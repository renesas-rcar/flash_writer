/*
 * Copyright (c) 2015-2017, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include	"emmc_config.h"
#include	"emmc_hal.h"
#include	"emmc_std.h"
#include	"emmc_def.h"
#include	"emmc_registers.h"

#include	"dgemmc.h"
#include	"common.h"
#include	"types.h"

#include	"reg_rcarh3.h"
#include	"ramckmdl.h"
#include	"dgmodul1.h"
#include	"devdrv.h"
#include	"b_boarddrv.h"
#include	"usb_lib.h"

#define		SIZE2SECTOR(x)				( (x) >> 9 )	/* 512Byte		*/

#define		EMMC_MAX_SIZE				8				/* 8 Gbyte		*/
#define		EMMC_MAX_SECTOR				((SIZE2SECTOR( EMMC_MAX_SIZE * 1024 )) * 1024 * 1024 ) /* MAX SECTOR (8Gbyte) */
#define		MULTI_PARTITION_SIZE		(128 * 1024)	/* 128 Kbyte	*/

#define		EMMC_WORK_DRAM_SADD			0x50000000U
#define		EMMC_WORK_DRAM_EADD_2M		0x501FFFFFU
#define		EMMC_WORK_DRAM_EADD_4M		0x503FFFFFU
#define		EMMC_WORK_DRAM_EADD_16M		0x50FFFFFFU
#define		EMMC_WORK_DRAM_EADD_64M		0x53FFFFFFU
#define		EMMC_WORK_DRAM_EADD_512M	0x6FFFFFFFU
#define		EMMC_WORK_DRAM_SECTOR_MAX	((EMMC_WORK_DRAM_EADD_512M - EMMC_WORK_DRAM_SADD + 1)>>9)

#define		EMMC_SECURERAM_SADD			0xE6300000U
#define		EMMC_SECURERAM_EADD			0xE635FFFFU

#define		DMA_TRANSFER_SIZE       (0x20)                /* DMA Transfer size =  32 Bytes*/
#define		DMA_ROUNDUP_VALUE       (0xFFFFFFE0)

 /* Product Register */
#define		PRR							(0xFFF00044U)
#define		PRR_PRODUCT_MASK			(0x00007F00U)
#define		PRR_PRODUCT_H3				(0x00004F00U)	/* R-Car H3 */
#define		PRR_PRODUCT_M3				(0x00005200U)	/* R-Car M3 */

typedef enum
{
	EMMC_PARTITION_USER_AREA = 0,
	EMMC_PARTITION_BOOT_1,
	EMMC_PARTITION_BOOT_2,
	EMMC_PARTITION_MAX
}EMMC_PARTITION;

typedef enum
{
	EMMC_INPUT_SECTOR_END = 0,
	EMMC_INPUT_SECTOR_SIZE,
	EMMC_INPUT_SECTOR_ADDRESS
}EMMC_INPUT_SECTOR;

typedef enum
{
	EMMC_INPUT_TYPE_READ = 0,
	EMMC_INPUT_TYPE_WRITE,
	EMMC_INPUT_TYPE_ERASE
}EMMC_INPUT_TYPE;

typedef struct
{
	uint32_t	maxSectorCount[EMMC_PARTITION_MAX];
}EMMC_SECTOR;

typedef enum
{
	EMMC_WRITE_MOT = 0,
	EMMC_WRITE_BINARY,
}EMMC_WRITE_COMMAND;

extern uint32_t	gTerminal;

static void dg_emmc_write_bin_serial(uint32_t* workStartAdd, uint32_t fileSize);
static EMMC_ERROR_CODE dg_emmc_init(void);
static uint32_t InputEmmcSector( EMMC_PARTITION partitionArea, uint32_t maxSectorCnt, uint32_t *startSector, uint32_t *sizeSector, EMMC_INPUT_TYPE type );
static uint32_t InputEmmcSectorArea( EMMC_PARTITION *partitionArea );
static uint32_t InputEmmcPrgStartAdd( uint32_t *prgStartAdd );
static uint32_t InputFileSize( uint32_t *fileSize );
static int32_t ChkSectorSize( uint32_t maxSectorCnt, uint32_t startSector, uint32_t sizeSector );
static void SetSectorData(EMMC_SECTOR *sectorData);
static void DispAreaData(EMMC_SECTOR sectorData);
static int8_t dg_emmc_mot_load(uint32_t *maxADD ,uint32_t *minADD, uint32_t gUserPrgStartAdd );
static void SwChgMmcVoltage(void);

static uint32_t emmcInit;		/* eMMC drv init */

/****************************************************************
	MODULE				: dg_init_emmc							*
	FUNCTION			: Init flag MMC drv Init				*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
void dg_init_emmc(void)
{
	emmcInit = FALSE;
}


/****************************************************************
	MODULE				: dg_emmc_check_init					*
	FUNCTION			: Check MMC drv Init					*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
unsigned long dg_emmc_check_init(void)
{
	EMMC_ERROR_CODE result;

	result = EMMC_SUCCESS;

	/* not init */
	if( FALSE == emmcInit )
	{
		result = dg_emmc_init();
		if( EMMC_SUCCESS == result )
		{
			emmcInit = TRUE;
		}
	}

	return (unsigned long)result;
}


/****************************************************************
	MODULE				: dg_emmc_init							*
	FUNCTION			: Init eMMC								*
	COMMAND				: EMMC_INIT								*
	INPUT PARAMETER		: 										*
*****************************************************************/
static EMMC_ERROR_CODE	dg_emmc_init(void)
{
    EMMC_ERROR_CODE result;

	/* eMMC driver initialize */
    result = emmc_init(FALSE);      /* Normal clock mode */
    if (result != EMMC_SUCCESS)
    {
        return result;
    }

    /* Card power on
     * MMC host cannot control Vcc&Vccq. RST_n asserted (high level).
     */
    result = emmc_memcard_power(TRUE);
    if (result != EMMC_SUCCESS)
    {
        return result;
    }

    /* Card mount (user area)
     * (1) Init card
     * (2) Hi-speed mode
     * (3) change Buswidth
     */
    result = emmc_mount();
    if (result != EMMC_SUCCESS)
    {
        return result;
    }

	return EMMC_SUCCESS;
}

/****************************************************************
	MODULE				: dg_emmc_write							*
	FUNCTION			: Write Memory to eMMC					*
	COMMAND				: EMMC_W								*
	INPUT PARAMETER		: EMMC_W								*
*****************************************************************/
void	dg_emmc_write(EMMC_WRITE_COMMAND wc)
{

	EMMC_ERROR_CODE result;
	EMMC_SECTOR		sectorData;
	EMMC_PARTITION	partitionArea;

	uint32_t	*Load_workStartAdd;
	uint32_t	*Load_workEndAdd;

	uint32_t	flags = 0x00000001;
	uint32_t	sectorStartAddress;
	uint32_t	sectorSize;
	uint32_t	prgStartAdd;
	uint32_t	chkInput;

	uint32_t	workAdd_Min;							//mot file Start address
	uint32_t	workAdd_Max;							//mot file end address
	uint32_t	mmcPrgStartAdd;							//program Start address
	uint32_t	mmcPrgEndAdd;							//program end address
	uint32_t	saveSize;

	uint32_t	SecStartAdd;
	uint32_t	SecEndAdd;
	uint32_t	SecCnt;

	uint32_t	totalDownloadSize;
	uint32_t	fileSize;

	int32_t chCnt;
	int8_t buf[16];
	int8_t motLoad = 1;
	int8_t oldPartitionConfig;

	const int8_t startMessage[][32] = {"EM_W Start --------------",
					   "EM_WB Start --------------"};

	const int8_t endMessage[][32] =	{"EM_W Complete!",
					 "EM_WB Complete!"};

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}

	PutStr(startMessage[wc], 1);

//sector data disp
	SetSectorData( &sectorData );
	DispAreaData( sectorData );

//Sw check
	SwChgMmcVoltage();

//Select Partition
	chkInput = InputEmmcSectorArea( &partitionArea );
	if( 1 != chkInput )
	{
		return;
	}

	Load_workStartAdd	= (uint32_t*)EMMC_WORK_DRAM_SADD;
	switch( partitionArea )
	{
	case EMMC_PARTITION_USER_AREA:			//User Partition Area Program
		Load_workEndAdd		= (uint32_t*)EMMC_WORK_DRAM_EADD_512M;
		PutStr("-- User Partition Area Program --------------------------",1);
		break;
	case EMMC_PARTITION_BOOT_1:				//Boot Partition 1 Program
		Load_workEndAdd		= (uint32_t*)EMMC_WORK_DRAM_EADD_16M;
		PutStr("-- Boot Partition 1 Program -----------------------------",1);
		break;
	case EMMC_PARTITION_BOOT_2:				//Boot Partition 2 Program
		Load_workEndAdd		= (uint32_t*)EMMC_WORK_DRAM_EADD_16M;
		PutStr("-- Boot Partition 2 Program -----------------------------",1);
		break;
	}

//Input address(mmc sector)
	chkInput = InputEmmcSector( partitionArea, sectorData.maxSectorCount[partitionArea], 
								&sectorStartAddress, &sectorSize, EMMC_INPUT_TYPE_WRITE );
	if( 1 != chkInput )
	{
		return;
	}

	mmcPrgStartAdd		= sectorStartAddress<<9;

//Input address( program start address)
	if (wc == EMMC_WRITE_MOT)
	{
		chkInput = InputEmmcPrgStartAdd( &prgStartAdd );
		if( 1 != chkInput )
		{
			return;
		}
	}

// WorkMemory CLEAR (Write H'00000000)
	switch( partitionArea )
	{
	case EMMC_PARTITION_USER_AREA:			//User Partition Area Program
		PutStr("Work RAM(H'50000000-H'6FFFFFFF) Clear....",1);
//		AsmWr(Load_workStartAdd, Load_workEndAdd, 0x00000000);
		FillData8Bit((uint8_t *)Load_workStartAdd,(uint8_t *)Load_workEndAdd,0x00);
		break;
	default:
		PutStr("Work RAM(H'50000000-H'50FFFFFF) Clear....",1);
//		AsmWr(Load_workStartAdd, Load_workEndAdd, 0x00000000);
		FillData8Bit((uint8_t *)Load_workStartAdd,(uint8_t *)Load_workEndAdd,0x00);
		break;
	}

// MOT file load
	if (wc == EMMC_WRITE_MOT)
	{
		motLoad = dg_emmc_mot_load(&workAdd_Max ,&workAdd_Min, prgStartAdd);
	}
	else
	{
		chkInput = InputFileSize( &fileSize );
		if( 1 != chkInput )
		{
			return;
		}
		PutStr("please send binary file!",1);

		if (gTerminal == 1)
		{
			totalDownloadSize = ((fileSize + (DMA_TRANSFER_SIZE - 1)) & DMA_ROUNDUP_VALUE);

			USB_ReadDataWithDMA((unsigned long)Load_workStartAdd, totalDownloadSize);
		}
		else
		{
			dg_emmc_write_bin_serial(Load_workStartAdd, fileSize);
		}

		workAdd_Min = (uintptr_t)Load_workStartAdd;
		workAdd_Max = workAdd_Min + fileSize - 1;
	}

#ifdef EMMC_DEBUG
	PutStr("workAdd_Min    = 0x",0);
	Hex2Ascii(workAdd_Min,buf,&chCnt);
	PutStr(buf,1);
	PutStr("workAdd_Max    = 0x",0);
	Hex2Ascii(workAdd_Max,buf,&chCnt);
	PutStr(buf,1);
#endif /* EMMC_DEBUG */

	if (wc == EMMC_WRITE_MOT)
	{
		if( 1 == motLoad )
		{
			PutStr("EM_W mot file read ERR",1);
			return;
		}
	}

//transfer data calc
	mmcPrgStartAdd = mmcPrgStartAdd + (workAdd_Min - (uintptr_t)Load_workStartAdd);
	mmcPrgEndAdd  = mmcPrgStartAdd + (workAdd_Max - workAdd_Min);
	saveSize = (mmcPrgEndAdd-mmcPrgStartAdd)+1;
	SecStartAdd = ( mmcPrgStartAdd >> 9 );		//sector top add
	SecEndAdd =  ( mmcPrgEndAdd >> 9 );			//sector bottom add
	SecCnt = ( SecEndAdd - SecStartAdd ) + 1;
#ifdef EMMC_DEBUG
	PutStr("mmcPrgStartAdd = 0x",0);
	Hex2Ascii(mmcPrgStartAdd,buf,&chCnt);
	PutStr(buf,1);
	PutStr("mmcPrgEndAdd   = 0x",0);
	Hex2Ascii(mmcPrgEndAdd,buf,&chCnt);
	PutStr(buf,1);
	PutStr("saveSize       = 0x",0);
	Hex2Ascii(saveSize,buf,&chCnt);
	PutStr(buf,1);
	PutStr("SecStartAdd    = 0x",0);
	Hex2Ascii(SecStartAdd,buf,&chCnt);
	PutStr(buf,1);
	PutStr("SecEndAdd      = 0x",0);
	Hex2Ascii(SecEndAdd,buf,&chCnt);
	PutStr(buf,1);
	PutStr("secCnt         = 0x",0);
	Hex2Ascii(SecCnt,buf,&chCnt);
	PutStr(buf,1);
#endif /* EMMC_DEBUG */

// Select Partition
	result = emmc_select_partition( partitionArea );
    if( result != EMMC_SUCCESS )
    {
        PutStr("EM_W Partition select FAIL",1);
        return;
    }

	SETR_32( SD_SIZE, EMMC_BLOCK_LENGTH );
// Write eMMC
	PutStr("SAVE -FLASH.......",1);
	//emmc_write_sector
	result = emmc_write_sector( Load_workStartAdd, sectorStartAddress, SecCnt, flags );
	if( result != EMMC_SUCCESS )
	{
        PutStr("EM_W ERR",1);
        return;
    }

// Change original EXT_CSD
	PutStr(endMessage[wc], 1);
}

/****************************************************************
	MODULE				: dg_emmc_write_bin							*
FUNCTION			: Write Memory to eMMC (Binary)					*
	COMMAND				: EMMC_WB								*
	INPUT PARAMETER		: EMMC_WB								*
*****************************************************************/
void	dg_emmc_write_bin(void)
{
	dg_emmc_write(EMMC_WRITE_BINARY);
}

/****************************************************************
	MODULE				: dg_emmc_write_mot							*
FUNCTION			: Write Memory to eMMC					*
	COMMAND				: EMMC_W								*
	INPUT PARAMETER		: EMMC_W								*
*****************************************************************/
void dg_emmc_write_mot(void)
{
	dg_emmc_write(EMMC_WRITE_MOT);
}

/****************************************************************
	MODULE				: dg_emmc_write_bin_serial							*
FUNCTION			: Write Memory to eMMC (Binary(Serial))					*
	COMMAND				: EMMC_WB								*
	INPUT PARAMETER		: EMMC_WB								*
*****************************************************************/
static void dg_emmc_write_bin_serial(uint32_t* workStartAdd, uint32_t fileSize)
{
	uint32_t i;
	int8_t byteData = 0;
	uintptr_t ptr;

	ptr = (uintptr_t)workStartAdd;
	for (i = 0; i < fileSize; i++)
	{
		GetChar(&byteData);
		*((uint8_t *)ptr) = byteData;
		ptr++;
	}
}

/****************************************************************
	MODULE				: dg_emmc_erase							*
	FUNCTION			: Erase Memory to eMMC					*
	COMMAND				: EMMC_E								*
	INPUT PARAMETER		: EMMC_E								*
*****************************************************************/
void	dg_emmc_erase(void)
{

	EMMC_ERROR_CODE result;
	EMMC_SECTOR		sectorData;
	EMMC_PARTITION	partitionArea;

	uint32_t	erase_start_address;
	uint32_t	erase_end_address;
	uint32_t	chkInput;

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}

	PutStr("EM_E Start --------------",1);

//sector data disp
	SetSectorData( &sectorData );
	DispAreaData( sectorData );

//Sw check
	SwChgMmcVoltage();

//Select Partition
	chkInput = InputEmmcSectorArea( &partitionArea );
	if( 1 != chkInput )
	{
		return;
	}

	switch( partitionArea )
	{
	case EMMC_PARTITION_USER_AREA:			//User Partition Area Program
		PutStr("-- User Partition Area Program --------------------------",1);
		break;
	case EMMC_PARTITION_BOOT_1:				//Boot Partition 1 Program
		PutStr("-- Boot Partition 1 Program -----------------------------",1);
		break;
	case EMMC_PARTITION_BOOT_2:				//Boot Partition 2 Program
		PutStr("-- Boot Partition 2 Program -----------------------------",1);
		break;
	}

// Select Partition
	result = emmc_select_partition( partitionArea );
	if( result != EMMC_SUCCESS )
	{
		PutStr("EM_E Partition select FAIL",1);
		return;
	}

//emmc_erase_sector
	erase_start_address = 0;
	erase_end_address = sectorData.maxSectorCount[partitionArea] - 1;

	result = emmc_erase_sector( erase_start_address, erase_end_address );
	if( result != EMMC_SUCCESS )
	{
		PutStr("EM_E ERR",1);
		return;
	}

// Change original EXT_CSD
	PutStr("EM_E Complete!",1);
}


/****************************************************************
	MODULE				: dg_emmc_mot_load						*
	FUNCTION			: load emmc mot file					*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static int8_t dg_emmc_mot_load(uint32_t *maxADD ,uint32_t *minADD, uint32_t gUserPrgStartAdd )
{
//MIN,MAX address calc
	int8_t 	str[12];			//max getByteCount=4 ->  4 * 2 +1 (NULL) = 9
	uint32_t data,getByteCount,byteCount;
	uint32_t loadGetCount,adByteCount,loadGetData,loadGetSum,loadGetCR;
	uintptr_t loadGetAddress;
	uint32_t loop,loop_S0,s0flag,errFlg,endFlg;
//**** Add dgLS_Load2 ********************************************************************
	uint32_t workAdd_Min,workAdd_Max;
//****************************************************************************************
//LAGER Add------------------------------------------------------------------------
	uint32_t WorkStartAdd,Calculation;
	uint32_t loadOffset;

	workAdd_Min = 0xFFFFFFFFU;
	workAdd_Max = 0x00000000U;

	WorkStartAdd = LS_WORK_DRAM_SADD;		//H'50000000

	if((0x40000000U <= gUserPrgStartAdd) && (gUserPrgStartAdd < WorkStartAdd)) {							//H'40000000 =< gUserPrgStartAdd < H'50000000
		loadOffset = WorkStartAdd - gUserPrgStartAdd ;
		Calculation = ADDITION;
		}
	else if((WorkStartAdd <= gUserPrgStartAdd) && (gUserPrgStartAdd < 0xC0000000U)) {					//H'50000000 =< gUserPrgStartAdd < H'C0000000
		loadOffset = gUserPrgStartAdd - WorkStartAdd ;
		Calculation = SUBTRACTION;
		}
	else if(( EMMC_SECURERAM_SADD <= gUserPrgStartAdd) && (gUserPrgStartAdd <= EMMC_SECURERAM_EADD)) {	//H'E6300000 =< gUserPrgStartAdd < H'E631FFFF  1st cut
		loadOffset = gUserPrgStartAdd - WorkStartAdd ;
		Calculation = SUBTRACTION;
		}
	else{
		PutStr("ERROR Load file.   <Download  file  DRAM(H'40000000-H'BFFFFFFF) , SecureRAM(H'E6300000-H'E631FFFF) ONLY > ",1);
		return(1);
	}

	loop	=1;
	loop_S0	=1;
	errFlg	=0;
	endFlg	=0;

	PutStr("please send ! ('.' & CR stop load)",1);
	while(loop){
		loop_S0=1;
		s0flag =0;
		while(1){
			GetChar(str);
			if(*str=='.'||*str=='s'||*str=='S')
				break;
		}
		if(*str =='.'){
			while(1){
				GetChar(str);
				if(*str==CR_CODE) 	return(1);
			}
		}
		else if(*str=='s'||*str=='S'){
			GetChar(str);
			switch(*str){
				case '0':				// S0:Title
					s0flag =1;
					while(loop_S0){		// loop CRorLR code
						GetChar(str);
						if((*str==CR_CODE)||(*str==LF_CODE)) 	loop_S0=0;
					}
					break;
				case '1':				// S1:2Byte Address
					adByteCount =2;
					break;
				case '2':				// S2:3Byte Address
					adByteCount =3;
					break;
				case '3':				// S3:4Byte Address
					adByteCount =4;
					break;
				case '7':				// S7,S8,S9:end code
				case '8':
				case '9':
					endFlg =1;
					break;
				default:
					errFlg =1;
					break;
			}
		}
		if(endFlg==1 || errFlg==1){		// end code etc.
			while(1){					// loop CRorLR code ,CRorLR Return
				GetChar(str);
				if((*str==CR_CODE)||(*str==LF_CODE)){

//**** Add dgLS_Load2 ********************************************************************
					*maxADD = workAdd_Max;
					*minADD = workAdd_Min;
//****************************************************************************************

//					return;
					return(0);		//KOELSCH_Area0_Ver0.07
				}
			}
		}
		if(s0flag == 0){
		//Get Byte count (addressByteCount + dataByteCount + sumCheckByteCount(=1) )
			getByteCount =1;
			GetStr_ByteCount(str,getByteCount);
			HexAscii2Data((uint8_t*)str,&data);
			loadGetCount = data;
		//Get Address
			getByteCount =adByteCount;
			GetStr_ByteCount(str,getByteCount);
			HexAscii2Data((uint8_t*)str,&data);
			loadGetAddress = data;

//LAGER Add------------------------------------------------------------------------
			if(Calculation == SUBTRACTION){
				loadGetAddress = loadGetAddress - loadOffset;
   			}
			else{
				loadGetAddress = loadGetAddress + loadOffset;
			}
//---------------------------------------------------------------------------------

			loadGetCount = loadGetCount - getByteCount;  // Get Address byte count -


//**** Add dgLS_Load2 ********************************************************************
		//Min Address Check
			if(loadGetAddress < workAdd_Min)
				workAdd_Min = loadGetAddress;
//****************************************************************************************

		//Get Data & Data write
			getByteCount =1;
			for(byteCount=loadGetCount;loadGetCount>1;loadGetCount=loadGetCount-1){
				GetStr_ByteCount(str,getByteCount);
				HexAscii2Data((uint8_t*)str,&data);
				loadGetData = data;
				*((uint8_t *)loadGetAddress) = loadGetData;
				loadGetAddress = loadGetAddress +1;
			}
//**** Add dgLS_Load2 ********************************************************************
		//Max Address Check
			if((loadGetAddress-1) > workAdd_Max)
				workAdd_Max = (loadGetAddress-1);
//****************************************************************************************

		//Get sum
			getByteCount =1;
			GetStr_ByteCount(str,getByteCount);
			HexAscii2Data((uint8_t*)str,&data);
			loadGetSum = data;
		//Get CR code
			GetChar(str);								//  char input
			loadGetCR = *str;
			if((loadGetCR==CR_CODE)||(loadGetCR==LF_CODE)){
				loop=1;
			}
		}
	}
}

/****************************************************************
	MODULE				: InputEmmcSector						*
	FUNCTION			: Input eMMC address and size in sector	*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t InputEmmcSector( EMMC_PARTITION partitionArea, uint32_t maxSectorCnt, uint32_t *startSector, uint32_t *sizeSector, EMMC_INPUT_TYPE type )
{
	uint32_t loop = EMMC_INPUT_SECTOR_ADDRESS;
	uint32_t wrData;
	int32_t chkInput;
	int8_t str[64];
	int8_t buf[16];
	int8_t chCnt = 0;
	int8_t chPtr;

	//Input Start Address and Size (sector)
	while(loop)
	{
		if(EMMC_INPUT_SECTOR_ADDRESS == loop)	
		{
			PutStr("Please Input Start Address in sector :",0);
		}
		else
		{
			PutStr("Please Input Size in sector :",0);
		}

		wrData = 0xFFFFFFFFU;
		GetStr(str,&chCnt);
		chPtr=0;
		if(!GetStrBlk(str,buf,&chPtr,0))
		{
			if(chPtr==1)
			{											/* Case Return */
				return(0);
			}
			else if(chPtr > (int8_t)((SIZE_32BIT<<1)+1) )	/* Case Data Size Over */
			{
				PutStr("Syntax Error",1);
			}
			else
			{
				if(HexAscii2Data((uint8_t*)buf,&wrData))
				{
					PutStr("Syntax Error",1);
				}
				else
				{
					/* Check Param */
					if(EMMC_INPUT_SECTOR_ADDRESS == loop)		/* case Address */
					{
						if(maxSectorCnt <= wrData)		/* Param Error */
						{
							PutStr("Param Error",1);
						}
						else
						{
							*startSector = wrData;
							if( EMMC_INPUT_TYPE_WRITE == type )		/* case Write */
							{
								loop = EMMC_INPUT_SECTOR_END;		/* Input End */
							}
							else
							{
								loop--;
							}
						}
					}
					else										/* case Size */
					{
						chkInput = ChkSectorSize(maxSectorCnt, *startSector, wrData);
						if(-1 == chkInput)		/* Size Over */
						{
							PutStr("Partition Size Over",1);
						}
						else if(0 == chkInput)	/* Param Error */
						{
							PutStr("Param Error",1);
						}
						else
						{
							*sizeSector = wrData;
							loop--;
						}
					}
				}
			}
		}
	}

	return(1);
}

/****************************************************************
	MODULE				: InputEmmcSectorArea					*
	FUNCTION			: Input eMMC Partition Area				*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t InputEmmcSectorArea( EMMC_PARTITION *partitionArea )
{
	uint32_t loop;
	uint32_t wrData;
	int8_t str[64];
	int8_t buf[16];
	int8_t chCnt = 0;
	int8_t chPtr;

	loop=1;
	while(loop)
	{
		PutStr("  Select area(0-2)>",0);
		GetStr(str,&chCnt);
		chPtr=0;
		if(!GetStrBlk(str,buf,&chPtr,0))
		{
			if(chPtr==1)
			{											/* Case Return */
				return(0);
			}
			else if(chPtr > (int8_t)((SIZE_32BIT<<1)+1) )	/* Case Data Size Over */
			{
				PutStr("Syntax Error",1);
			}
			else
			{
				if(HexAscii2Data((uint8_t*)buf,&wrData))
				{
					PutStr("Syntax Error",1);
				}
				else
				{
					switch(wrData)
					{
						case 0:			//User Partition Area Program
							*partitionArea	= EMMC_PARTITION_USER_AREA;
							loop=0;
							break;
						case 1:			//Boot Partition 1 Program
							*partitionArea	= EMMC_PARTITION_BOOT_1;
							loop=0;
							break;
						case 2:			//Boot Partition 2 Program
							*partitionArea	= EMMC_PARTITION_BOOT_2;
							loop=0;
							break;
						default:
							PutStr("Palam Error",1);
							break;
					}
				}
			}
		}
	}

	return(1);
}

/****************************************************************
	MODULE				: InputEmmcPrgStartAdd					*
	FUNCTION			: Input Program Start Add				*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t InputEmmcPrgStartAdd( uint32_t *prgStartAdd )
{
	uint32_t loop;
	uint32_t wrData;
	int8_t key[16];
	int8_t buf[16];
	int8_t chCnt = 0;
	int8_t chPtr;

	loop = 1;
	while(loop)
	{
		PutStr("Please Input Program Start Address : ",0);
		GetStr(key,&chCnt);
		chPtr=0;
		if(!GetStrBlk(key,buf,&chPtr,0))
		{
			if(chPtr==1)
			{									/* Case Return */
				return(0);
			}
			else if(chPtr > (int8_t)((SIZE_32BIT<<1)+1) )
			{	/* Case Data Size Over */
				PutStr("Syntax Error",1);
			}
			else
			{
				if(HexAscii2Data((uint8_t*)buf,&wrData))
				{
					PutStr("Syntax Error",1);
				}
				else
				{
					if(wrData & 0x000001FFU)
					{
						PutStr("Memory Boundary Error",1);
					}
					else
					{
						*prgStartAdd = wrData;
						loop =0;
					}
				}
			}
		}
	}

	return(1);
}

/****************************************************************
	MODULE				: InputFileSize					*
	FUNCTION			: Input Binary File Size				*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t InputFileSize( uint32_t *fileSize )
{
	uint32_t loop;
	uint32_t wrData;
	int8_t str[16];
	int8_t buf[16];
	int8_t chCnt = 0;
	int8_t chPtr;

	loop = 1;
	while(loop)
	{
		PutStr("Please Input File size(byte) : ",0);
		GetStr(str,&chCnt);
		chPtr=0;
		if(!GetStrBlk(str,buf,&chPtr,0))
		{
			if(chPtr==1)
			{									/* Case Return */
				return(0);
			}
			else
			{
				if(HexAscii2Data((uint8_t*)buf,&wrData))
				{
					PutStr("Syntax Error",1);
				}
				else
				{
					*fileSize = wrData;
					loop =0;
				}
			}
		}
	}

	return(1);
}


/****************************************************************
	MODULE				: ChkSectorSize							*
	FUNCTION			: check Sector Size						*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static int32_t ChkSectorSize( uint32_t maxSectorCnt, uint32_t startSector, uint32_t sizeSector )
{
	uint32_t sumSector;

	if( EMMC_WORK_DRAM_SECTOR_MAX < sizeSector )
	{
		return(-1);	/* Size Over */
	}

	if(( 1 <= sizeSector )
	&& ( maxSectorCnt >= sizeSector ) )
	{
		sumSector = startSector + sizeSector;

		if(sumSector <= maxSectorCnt)
		{
			return(1);	/* OK */
		}
		else
		{
			return(-1);	/* Size Over */
		}
	}
	else
	{
		return(0);	/* Param Error */
	}

}

/****************************************************************
	MODULE				: SetSectorData							*
	FUNCTION			: Set eMMC Sector Data					*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void SetSectorData(EMMC_SECTOR *sectorData)
{
	uint32_t multiSectorCount;
	uint32_t bootPartitionSector;
	uint32_t userDataAreaSector;

	multiSectorCount = mmc_drv_obj.ext_csd_data[EMMC_EXT_CSD_BOOT_SIZE_MULTI];
	bootPartitionSector = ( SIZE2SECTOR( MULTI_PARTITION_SIZE ) * multiSectorCount);

	userDataAreaSector  = mmc_drv_obj.ext_csd_data[EMMC_EXT_CSD_SEC_COUNT-0] << 24;
	userDataAreaSector |= mmc_drv_obj.ext_csd_data[EMMC_EXT_CSD_SEC_COUNT-1] << 16;
	userDataAreaSector |= mmc_drv_obj.ext_csd_data[EMMC_EXT_CSD_SEC_COUNT-2] << 8;
	userDataAreaSector |= mmc_drv_obj.ext_csd_data[EMMC_EXT_CSD_SEC_COUNT-3] << 0;

	sectorData->maxSectorCount[EMMC_PARTITION_BOOT_1] = bootPartitionSector;
	sectorData->maxSectorCount[EMMC_PARTITION_BOOT_2] = bootPartitionSector;
	sectorData->maxSectorCount[EMMC_PARTITION_USER_AREA] = userDataAreaSector;

	return;
}

/****************************************************************
	MODULE				: DispAreaData							*
	FUNCTION			: Display eMMC Sector Data				*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void DispAreaData(EMMC_SECTOR sectorData)
{
	uint32_t loop;
	int8_t str[64];
	int32_t chCnt;

	PutStr("---------------------------------------------------------",1);
	PutStr("Please select,eMMC Partition Area.",1);

	for(loop = EMMC_PARTITION_USER_AREA; loop < EMMC_PARTITION_MAX; loop++)
	{
		if(EMMC_PARTITION_USER_AREA == loop)
		{
			PutStr(" 0:User Partition Area   : ",0);
		}
		else if(EMMC_PARTITION_BOOT_1 == loop)
		{
			PutStr(" 1:Boot Partition 1      : ",0);
		}
		else
		{
			PutStr(" 2:Boot Partition 2      : ",0);
		}
		Hex2DecAscii(((sectorData.maxSectorCount[loop])>>1),str,&chCnt);
		PutStr(str,0);
		PutStr(" KBytes",1);
		PutStr("  eMMC Sector Cnt : H'0 - H'",0);
		Hex2Ascii((sectorData.maxSectorCount[loop] - 1),str,&chCnt);
		PutStr(str,1);
	}

	PutStr("---------------------------------------------------------",1);

}

/****************************************************************
	MODULE				: SwChgMmcVoltage						*
	FUNCTION			: Check SW								*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void SwChgMmcVoltage(void)
{
	uint32_t product;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;

	if (product == PRR_PRODUCT_M3) {
		if (SSI_WS6_OpenCheck()) {
			PutStr("SW32 All OFF! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(39);
			PutStr("SW33 All ON!  Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(39);
			PutStr("SW35 SW36 SW37 OFF! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(45);
			PutStr("SW39 SW40 SW41 ON!  Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(45);
		}
	}
}
