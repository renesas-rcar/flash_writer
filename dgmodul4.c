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

#include	"common.h"
#include	"dgtable.h"
#include	"dgmodul4.h"
#include	"rpcqspidrv.h"
#include	"rpchyperdrv.h"
#include	"hyperflashdrv.h"
#include	"spiflash0drv.h"
#include	"spiflash1drv.h"
#include	"reg_rcarh3.h"
#include	"ramckmdl.h"
#include	"dmaspi.h"
#include	"devdrv.h"
#include	"dgmodul1.h"
#include	"boardid.h"
#include	"switch.h"
#if USB_ENABLE == 1
#include	"usb_lib.h"
#endif /* USB_ENABLE == 1 */

uint32_t	gSpiFlashSvArea;
uint32_t	gUserPrgStartAdd;
uint32_t	gUserPrgSize;
uint32_t	gSelectQspiFlash;



/****************************************************************
	MODULE				: dgGen3LoadSpi/Hyperflash				*
	FUNCTION			: load Program to Spi/Hyperflash memory	*
	COMMAND				: XLS									*
	INPUT PARAMETER		: XLS				 					*
*****************************************************************/
void dgGen3LoadSpiflash0(void)
{
	char str[64];
	uint32_t OnBoradSpiSysSize;

	char		buf[16],key[16],chCnt,chPtr;
	uint32_t	readManuId,readDevId;
	uint32_t	loop;
	uint32_t	wrData;

	uintptr_t	Load_workStartAdd,Load_workEndAdd;
	uint32_t	workAdd_Min,workAdd_Max;

	uint32_t	Read_workStartAdd;
	uint32_t	ClrSpiStartSecTopAdd,ClrSpiSecEndAdd;
	uint32_t	clearSize;

	uint32_t	MaskSectorSize;
	uint32_t	WriteDataStatAdd;
	uint32_t	PrgSpiStatAdd,PrgSpiEndAdd;
	uint32_t	saveSize;

	uint32_t	InfoPrgStatAdd;
	uint32_t	rdBufstatAdd;
	uintptr_t	prgStAdd,prgSize;

	uint32_t	WrittenSize;
	uint32_t	RemainingSize;

	PutStr("===== Qspi/HyperFlash writing of Gen3 Board Command ========",1);
	PutStr("Load Program to Spiflash",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();
	if(CheckQspiFlashId())
		return;						//Error abortt

	PutStr("------------------------------------------------------------",1);
	PutStr("Please select,Qspi/HyperFlash Save Area. ",1);
	PutStr(" ",1);
	PutStr("== Loader Program : Program to execute on SystemRAM ========",1);
	PutStr("   1 : A-Side SPI_Address = H' 004_0000-H' 007_FFFF         ",1);
	PutStr("   2 : B-Side SPI_Address = H' 008_0000-H' 00B_FFFF         ",1);
	PutStr(" ",1);
	PutStr("== User Program : Program to execute on DRAM or SystemRAM ==",1);
	PutStr("   3 :        SPI_Address = H' 010_0000-H' 3FF_FFFF         ",1);
	PutStr("------------------------------------------------------------",1);

	loop=1;
	while(loop){
		PutStr("  Select area(1-3)>",0);
		GetStr(str,&chCnt);
		  switch(str[0]){
			case '1':				//LoaderProgram
				gSpiFlashSvArea		= 1;
				Load_workStartAdd	= LS_WORK_DRAM_SADD;
				Load_workEndAdd		= LS_WORK_DRAM_EADD_192K;
		  		PrgSpiStatAdd		= S25FL512_SA01_STARTAD;
				loop=0;
				break;
			case '2':				//LoaderProgram
				gSpiFlashSvArea		= 2;
				Load_workStartAdd	= LS_WORK_DRAM_SADD;
				Load_workEndAdd		= LS_WORK_DRAM_EADD_192K;
		  		PrgSpiStatAdd		= S25FL512_SA02_STARTAD;
				loop=0;
				break;
			case '3':				//UserProgram
				gSpiFlashSvArea		= 3;
				Load_workStartAdd	= LS_WORK_DRAM_SADD;
				Load_workEndAdd		= LS_WORK_DRAM_EADD_64M;
				PrgSpiStatAdd		= S25FL512_SA04_STARTAD;
				loop=0;
				break;
		  }
	}
	if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2){
		gUserPrgStartAdd = SYSTEMRAM_IPL_SADD;				//0xE6302000
		PutStr("-- Loader Program --------------------------",1);
	}
	else if(gSpiFlashSvArea==3){
		PutStr("-- User Program ----------------------------",1);
		loop=1;
		while(loop){
			PutStr("Please Input User Program Start Address : ",0);
			GetStr(key,&chCnt);
			chPtr=0;
			if(!GetStrBlk(key,buf,&chPtr,0)){
				if(chPtr==1){									/* Case Return */

				}else if((buf[0]=='.')){						/* Case End */
					gUserPrgStartAdd = 0x40000000;
					loop =0;
				}else if(chPtr > (char)((SIZE_32BIT<<1)+1) ){	/* Case Data Size Over */
					PutStr("Syntax Error",1);
				}else{
					if(HexAscii2Data((unsigned char*)buf,&wrData)){
						PutStr("Syntax Error",1);
					}else{
						if(wrData&0x00000003){
							PutStr("Memory Boundary Error",1);
						}
						else{
							gUserPrgStartAdd = wrData;
							loop =0;
						}
					}
				}
			}else{
				PutStr("Syntax Error",1);
			}
		}
	}

//=====================================================================================
//	InfoPrgStatAdd = S25FL512_SA03_STARTAD;
//	InfoPrgSizeAdd = S25FL512_SA03_STARTAD + 0x04;
//=====================================================================================

// WorkMemory CLEAR (Write H'FF)
   	if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2){						//Loader Area
		PutStr("Work RAM(H'50000000-H'5002FFFF) Clear....",1);			//Change
   	}
    else if(gSpiFlashSvArea==3) {
		PutStr("Work RAM(H'50000000-H'53FFFFFF) Clear....",1);
    }
	FillData32Bit((uint32_t *)Load_workStartAdd,(uint32_t *)Load_workEndAdd,0xFFFFFFFF);

	if(dgLS_Load_Offset2(&workAdd_Max ,&workAdd_Min))
		return;															//

	PrgSpiStatAdd = PrgSpiStatAdd + (workAdd_Min - Load_workStartAdd);
	PrgSpiEndAdd  = PrgSpiStatAdd + (workAdd_Max - workAdd_Min);
	saveSize = (PrgSpiEndAdd-PrgSpiStatAdd)+1;

	MaskSectorSize= 0xFFFC0000;

	WriteDataStatAdd     = workAdd_Min;
	ClrSpiStartSecTopAdd = PrgSpiStatAdd &   MaskSectorSize;
	ClrSpiSecEndAdd      = PrgSpiEndAdd  | ~(MaskSectorSize);

	clearSize = (ClrSpiSecEndAdd-ClrSpiStartSecTopAdd)+1;

	Read_workStartAdd    = 0x60000000;

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if( CkQspiFlash1ClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		if( CkQspiFlash0ClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		if( CkHyperFlashClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}

// SAVE QSPI-FLASH
	PutStr("SAVE SPI-FLASH.......",0);

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SaveDataWithBuffeQspiFlashS25s128s(WriteDataStatAdd,PrgSpiStatAdd,saveSize);			//Manual Mode Single WriteBuffe
		PutStr(" complete!",1);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		PutStr(" ",1);
		if(PrgSpiStatAdd <0x1000000){
			if(PrgSpiEndAdd>0x1000000){
				WrittenSize   = 0x1000000-PrgSpiStatAdd;
				RemainingSize = saveSize - WrittenSize;


				Data2HexAscii(WrittenSize,str,4);							//********************* DEBUG
				PutStr(" WrittenSize      :H' ",0);							//********************* DEBUG
				PutStr(str,1);												//********************* DEBUG

				Data2HexAscii(RemainingSize,str,4);							//********************* DEBUG
				PutStr(" RemainingSize    :H' ",0);							//********************* DEBUG
				PutStr(str,1);												//********************* DEBUG


				PutStr("SpiArea : H'00000000-H'00FFFFFF",0);
				SaveDataWithBuffeQspiFlashS25fl512s(WriteDataStatAdd,PrgSpiStatAdd,WrittenSize);	//Manual Mode Single WriteBuffe
				PutStr(" complete!",1);
				PutStr("SpiArea : H'01000000-H'03FFFFFF",0);
				SaveDataQspiFlashS25fl512s_CsCont((0x50000000+WrittenSize),0x1000000,RemainingSize);	//Manual Mode Single (512)
				PutStr(" complete!",1);
			}
			else{
				PutStr("SpiArea : H'00000000-H'00FFFFFF",0);
				SaveDataWithBuffeQspiFlashS25fl512s(WriteDataStatAdd,PrgSpiStatAdd,saveSize);		//Manual Mode Single WriteBuffe
				PutStr(" complete!",1);
			}
		}
		else{
			PutStr("SpiArea : H'01000000-H'03FFFFFF",0);
			SaveDataQspiFlashS25fl512s_CsCont(WriteDataStatAdd,PrgSpiStatAdd,saveSize);			//Manual Mode Single (512)
			PutStr(" complete!",1);
		}
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SetRPC_ClockMode(RPC_CLK_40M);															//Word Program 50MHz(max)
		SaveDataWithBuffeHyperFlash(WriteDataStatAdd,PrgSpiStatAdd,saveSize);					//Manual Mode WriteBuffe
		SetRPC_ClockMode(RPC_CLK_80M);
		PutStr(" complete!",1);
	}


	PutStr("-- Save (Program Start Address & Size ) -----",1);				//Message change
   	if(gSpiFlashSvArea==1){				//A-Side IPL
		InfoPrgStatAdd = S25FL512_SA00_STARTAD;								//0x0000000
		prgStAdd       = Read_workStartAdd + S25FL512_SA00_A_IPL_ADD;		//0x60000000 + 0x0000D54
		prgSize        = Read_workStartAdd + S25FL512_SA00_A_IPL_SIZE;		//0x60000000 + 0x0000E64
   	}
   	else if(gSpiFlashSvArea==2){		//B-Side IPL
		InfoPrgStatAdd = S25FL512_SA00_STARTAD;								//0x0000000
		prgStAdd       = Read_workStartAdd + S25FL512_SA00_B_IPL_ADD;		//0x60000000 + 0x0001154
		prgSize        = Read_workStartAdd + S25FL512_SA00_B_IPL_SIZE;		//0x60000000 + 0x0001264
   	}
   	else if(gSpiFlashSvArea==3){		//User Program Area
		InfoPrgStatAdd = S25FL512_SA03_STARTAD;								//0x00C0000
		prgStAdd       = Read_workStartAdd + S25FL512_SA03_PRG_ST_AD;		//0x60000000 + 0x00C0000
		prgSize        = Read_workStartAdd + S25FL512_SA03_PRG_SIZE;		//0x60000000 + 0x00C0004
   	}

	rdBufstatAdd    = Read_workStartAdd + InfoPrgStatAdd;	//0x60000000 + 0x00C0000 = 0x600C0000
	OnBoradSpiSysSize    = 0x2000;

	if(gSelectQspiFlash ==ONBOARD_QSPI){
//Change 2015.07.24
		if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2){
			FastRd3adQspiFlashS25s128s(InfoPrgStatAdd,rdBufstatAdd,OnBoradSpiSysSize);
		}
		else{
			SectorRdQspiFlashS25s128s(InfoPrgStatAdd,rdBufstatAdd);
		}
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorRdQspiFlashS25fl512s(InfoPrgStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorRdHyperFlash(InfoPrgStatAdd,rdBufstatAdd);
	}


	if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2)
		PutStr("SPI Data Clear(H'FF):H'000000-03FFFF Erasing.",0);
	else
		PutStr("SPI Data Clear(H'FF):H'0C0000-0FFFFF Erasing.",0);
	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2){
			ParameterSectorEraseQspiFlashS25s128s(InfoPrgStatAdd,((OnBoradSpiSysSize)-1));
		}
		else{
			SectorEraseQspiFlashS25s128s(InfoPrgStatAdd,((InfoPrgStatAdd+0x8)-1));
		}
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorEraseQspiFlashS25fl512s(InfoPrgStatAdd,((InfoPrgStatAdd+0x8)-1));
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorEraseHyperFlashRange(InfoPrgStatAdd,((InfoPrgStatAdd+0x8)-1));
	}

	*((uint32_t*)prgStAdd) = gUserPrgStartAdd;
	saveSize = (saveSize|0x3)>>2;
	*((uint32_t*)prgSize)  = saveSize;

	PutStr("SAVE SPI-FLASH.......",0);
	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if(gSpiFlashSvArea==1 || gSpiFlashSvArea==2){
			SaveDataWithBuffeQspiFlashS25s128s(rdBufstatAdd,InfoPrgStatAdd,OnBoradSpiSysSize);		//Manual Mode Single WriteBuffe //o
		}
		else{
			SaveDataWithBuffeQspiFlashS25s128s(rdBufstatAdd,InfoPrgStatAdd,S25FL512_SA_SIZE);		//Manual Mode Single WriteBuffe
		}
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SaveDataQspiFlashS25fl512s_CsCont(rdBufstatAdd,InfoPrgStatAdd,S25FL512_SA_SIZE);			//Manual Mode Single (512)			//OK
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SetRPC_ClockMode(RPC_CLK_40M);															//Word Program 50MHz(max)
		SaveDataWithBuffeHyperFlash(rdBufstatAdd,InfoPrgStatAdd,S25FL512_SA_SIZE);				//Manual Mode WriteBuffe
		SetRPC_ClockMode(RPC_CLK_80M);
	}
	PutStr(" complete!",1);

	PutStr("",1);
	PutStr("==========  Qspi/HyperFlash Save Information  =================",1);
	PutStr(" Program Start Address :  H'",0);
	Data2HexAscii(gUserPrgStartAdd,str,4);
	PutStr(str,1);
	Data2HexAscii(saveSize,str,4);
	PutStr(" Program Size (Byte/4) :  H'",0);
	PutStr(str,1);
	PutStr("===============================================================",1);
	PutStr("",1);
}




void SelQspiFlashSetSw(void)
{
	char str[64];
	char		chCnt;
	uint32_t	loop;

	gSelectQspiFlash =0;

	PutStr("Please select,FlashMemory. ",1);
	PutStr("   1 : QspiFlash       (U5 : S25FS128S)",1);
	if(gBoardFlag == BD_STARTERKIT){
		PutStr("   2 : QspiFlash Board (CN2: S25FL512S)",1);
	}else{
		PutStr("   2 : QspiFlash Board (CN3: S25FL512S)",1);
	}


	PutStr("   3 : HyperFlash      (SiP internal)",1);
	loop=1;
	while(loop){
		PutStr("  Select (1-3)>",0);
		GetStr(str,&chCnt);
		switch(str[0]){
		case '1':
			gSelectQspiFlash = ONBOARD_QSPI;
			loop=0;
			SwChgOnBoard_QSPI0[gBoardFlag].program();
			break;
		case '2':
			gSelectQspiFlash = QSPI_BOARD;
			loop=0;
			SwChgExSPI_QSPI0[gBoardFlag].program();
			break;
		case '3':
			gSelectQspiFlash = HYPER_FLASH;
			loop=0;
			SwChgHyperFlash[gBoardFlag].program();
			break;
		default:
			break;
		}
	}
}

void InitRPC_Mode(void)
{
	if(gSelectQspiFlash == ONBOARD_QSPI){
		InitRPC_QspiFlash();
	}
	else if(gSelectQspiFlash == QSPI_BOARD){
		InitRPC_QspiFlashBoard();
	}
	else if(gSelectQspiFlash == HYPER_FLASH){
		InitRPC_HyperFlash();
	}
}





uint32_t CheckQspiFlashId(void)
{
	char str[64];
	uint32_t	readDevId;

	if(gSelectQspiFlash == HYPER_FLASH){
		ReadHyperFlashID(&readDevId);
		ResetHyperFlash();
	}
	else{	//QSPI
		ReadQspiFlashID(&readDevId);
		readDevId = readDevId & 0x00FFFFFF;
	}

	if(readDevId != gSelectQspiFlash){
		PutStr(" DEVICE ID Error. Please check switch setting ",1);
		Data2HexAscii(readDevId,str,4);
		PutStr(" READ ID = 0x",0);
		PutStr(str,1);
		if(gSelectQspiFlash != HYPER_FLASH){
			PutStr(" Note: The lower 24-bit only is valid. (Upper 8 bits it is mask.)",1);
		}
		return(1);
	}
	else{
		PutStr(" READ ID OK.",1);
		return(0);
	}
}


int32_t CkQspiFlash0ClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize)
{
//	unsigned char *bufPtr;
	uint32_t flashStatus,flashEraseFlg;
	char str1Buf[10],str2Buf[10];



	char str[64];		//DEBUG

//	bufPtr = (unsigned char*)rdBufAdd;

	PutStr("SPI Data Clear(H'FF) Check :",0);
//	QuadRdQspiFlashS25fl512s(spiFlashStatAdd,bufPtr,checkSize,accessSize);
	QuadRdQspiFlashS25fl512s(spiFlashStatAdd,rdBufAdd,checkSize);

	flashEraseFlg = 0;

//	if( CkSpiFlashAllF(rdBufAdd,checkSize,spiFlashStatAdd) ){
	if( CkSpiFlashAllF(rdBufAdd,checkSize) ){

	    PutStr("H'",0);
		Data2HexAscii(spiFlashStatAdd,str1Buf,4);					PutStr(&str1Buf[0],0);
		PutStr("-",0);
		Data2HexAscii(((spiFlashStatAdd+checkSize)-1),str2Buf,4);	PutStr(&str2Buf[0],0);
		PutStr(",Clear OK?(y/n)",0);

		if( WaitKeyIn_YorN() ){
		    DelStr(34);
			PutStr(" Exit ",1);
			return(1);
		}
		DelStr(34);
		flashEraseFlg = 1;
	}
	else{
		PutStr(" OK ",1);
	}
    if(flashEraseFlg){		// FLASH: erase
    	//PutStr("SPI-FLASH:H'xxxxxxxx-xxxxxxxx Erasing.",0);
//		PutStr("H'",0);	PutStr(&str1Buf[2],0);	PutStr("-",0);
		PutStr("H'",0);	PutStr(&str1Buf[0],0);	PutStr("-",0);
//									PutStr(&str2Buf[2],0);	PutStr(" Erasing.",0);
									PutStr(&str2Buf[0],0);	PutStr(" Erasing.",0);

    	SectorEraseQspiFlashS25fl512s(spiFlashStatAdd,((spiFlashStatAdd+checkSize)-1));	//SPI-FLASH-Address H'0000-H'FFFF

//		//SPI Ver0.07
//    	DelStr(24);
//    	DelStr(28);
//		PutStr("SPI Data Clear(H'FF) Check :",0);
//		QuadRdQspiFlashS25fl512s(spiFlashStatAdd,bufPtr,checkSize,1);
//
//  	// All FF verify
//		if( CkSpiFlashAllF(rdBufAdd,checkSize,spiFlashStatAdd) ){
//			PutStr("HSPI-FLASH erase error.",1);
//			return(1);
//		}
//		PutStr(" OK ",1);
//
	}
	return(0);
}

int32_t CkQspiFlash1ClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize)
{
	uint32_t flashStatus,flashEraseFlg;
	char str1Buf[10],str2Buf[10];

	char str[64];		//DEBUG

	PutStr("SPI Data Clear(H'FF) Check :",0);
//	QuadIORdQspiFlashS25s128s(spiFlashStatAdd,rdBufAdd,checkSize);					//add 2016.01.19
	FastRd3adQspiFlashS25s128s (spiFlashStatAdd,rdBufAdd,checkSize);				//Change 2015.07.23

	flashEraseFlg = 0;

	if( CkSpiFlashAllF(rdBufAdd,checkSize) ){

	    PutStr("H'",0);
		Data2HexAscii(spiFlashStatAdd,str1Buf,4);					PutStr(&str1Buf[0],0);
		PutStr("-",0);
		Data2HexAscii(((spiFlashStatAdd+checkSize)-1),str2Buf,4);	PutStr(&str2Buf[0],0);
		PutStr(",Clear OK?(y/n)",0);

		if( WaitKeyIn_YorN() ){
		    DelStr(34);
			PutStr(" Exit ",1);
			return(1);
		}
		DelStr(34);
		flashEraseFlg = 1;
	}
	else{
		PutStr(" OK ",1);
	}
    if(flashEraseFlg){		// FLASH: erase
	   	if(spiFlashStatAdd<0x40000){		//Parameter Data Area Erase (H'0-H'7FFF)
			PutStr("H'00000000-H'00007FFF",0);	PutStr(" Erasing.",1);
			ParameterSectorEraseQspiFlashS25s128s(0x0,0x7FFF);
	   	}
		PutStr("H'",0);	PutStr(&str1Buf[0],0);	PutStr("-",0);	PutStr(&str2Buf[0],0);	PutStr(" Erasing.",0);
   		SectorEraseQspiFlashS25s128s(spiFlashStatAdd,((spiFlashStatAdd+checkSize)-1));	//SPI-FLASH-Address H'0000-H'FFFF
	}
	return(0);
}




int32_t CkHyperFlashClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize)
{
//	unsigned char *bufPtr;
	uint32_t flashStatus,flashEraseFlg;
	char str1Buf[10],str2Buf[10];
//	char str[64];		//DEBUG
//	bufPtr = (unsigned char*)rdBufAdd;

	PutStr("SPI Data Clear(H'FF) Check :",0);
//	RdManuHyperFlash(spiFlashStatAdd,rdBufAdd,checkSize);
	RdHyperFlash(spiFlashStatAdd,rdBufAdd,checkSize);

	flashEraseFlg = 0;
	if( CkSpiFlashAllF(rdBufAdd,checkSize) ){
	    PutStr("H'",0);
		Data2HexAscii(spiFlashStatAdd,str1Buf,4);					PutStr(&str1Buf[0],0);
		PutStr("-",0);
		Data2HexAscii(((spiFlashStatAdd+checkSize)-1),str2Buf,4);	PutStr(&str2Buf[0],0);
		PutStr(",Clear OK?(y/n)",0);
		if( WaitKeyIn_YorN() ){
		    DelStr(34);
			PutStr(" Exit ",1);
			return(1);
		}
		DelStr(34);
		flashEraseFlg = 1;
	}
	else{
		PutStr(" OK ",1);
	}
    if(flashEraseFlg){		// FLASH: erase
		PutStr("H'",0);	PutStr(&str1Buf[0],0);	PutStr("-",0);	PutStr(&str2Buf[0],0);	PutStr(" Erasing.",0);
	   	SectorEraseHyperFlashRange(spiFlashStatAdd,((spiFlashStatAdd+checkSize)-1));	//SPI-FLASH-Address H'0000-H'FFFF
	}
	return(0);
}



void mem_copy(uint32_t prgStartAd, uint32_t sector_Ad, uint32_t accessSize)
{

	uintptr_t readAdd,wrAdd;			//DEBUG
	uint32_t paddingOffset=0;
	uint32_t accessCount=0;

//DEBUG============
//	for(readAdd=(uintptr_t)sector_Ad,wrAdd=(uintptr_t)prgStartAd ; readAdd< (sector_Ad +accessSize ) ; readAdd=readAdd+1,wrAdd=wrAdd+1){
//		*(uint8_t*)wrAdd = *(uint8_t*)readAdd;
//	}
//DEBUG============

//#if 0

	paddingOffset = (accessSize + 0xFF ) & ~0xFF;

	//accessCount = accessSize/64;
	accessCount = paddingOffset >> 6;

//DMA Setting
	InitDma01_Data(prgStartAd, sector_Ad, accessCount);
	StartDma01();
	WaitDma01();
	DisableDma01();
	ClearDmaCh01();
//#endif
}

/****************************************************************
	MODULE			: dgGen3LoadSpiflash0_3		(S25fl512s)	*
	FUNCTION		: load Program to Spiflash memory		*
	COMMAND			: XLS3									*
	INPUT PARAMETER		: XLS3			 						*
*****************************************************************/
void dgGen3LoadSpiflash0_3(void)
{

	XLoadSpiflash0_2(1U);
}

/****************************************************************
	MODULE				: dgGen3LoadSpiflash0_2		(S25fl512s)	*
	FUNCTION			: load Program to Spiflash memory		*
	COMMAND				: XLS2									*
	INPUT PARAMETER		: XLS2			 						*
*****************************************************************/
void dgGen3LoadSpiflash0_2(void)
{
	XLoadSpiflash0_2(0U);
}

void XLoadSpiflash0_2(uint32_t mode)
{
	char str[64];
	uint32_t	readManuId,readDevId;

	uintptr_t	Load_workStartAdd,Load_workEndAdd;
	uint32_t	workAdd_Min,workAdd_Max;

	uint32_t	Read_workStartAdd;
	uint32_t	ClrSpiStartSecTopAdd,ClrSpiSecEndAdd;
	uint32_t	clearSize;

	uint32_t	MaskSectorSize;
	uint32_t	WriteDataStatAdd;
	uint32_t	PrgSpiStatAdd,PrgSpiEndAdd;
	uint32_t	saveSize;

	uint32_t	WrittenSize;
	uint32_t	RemainingSize;

	PutStr("===== Qspi/HyperFlash writing of Gen3 Board Command =============",1);
	PutStr("Load Program to Spiflash",1);
	PutStr("Writes to any of SPI address.",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();

	if(CheckQspiFlashId())
		return;						//Error abortt

	gUserPrgStartAdd = 0x0;
	PutStr((mode == 0U ? "Program Top Address & Qspi/HyperFlash Save Address " : "Program size & Qspi/HyperFlash Save Address "),1);

	gSpiFlashSvArea		= 3;
	Load_workStartAdd	= LS_WORK_DRAM_SADD;
	Load_workEndAdd		= LS_WORK_DRAM_EADD_64M;

	PrgSpiStatAdd		= 0x0;
	gUserPrgStartAdd	= 0x0;

	if (0U == mode) {
		PutStr("===== Please Input Program Top Address ============",1);
		SetAddInputKey(&gUserPrgStartAdd);
	} else {
		PutStr("===== Please Input Program size ============",1);
		SetSizeInputKey(&gUserPrgSize);
	}

	PutStr(" ",1);
	PutStr("===== Please Input Qspi/HyperFlash Save Address ===",1);
	SetAddInputKey(&PrgSpiStatAdd);
//	if(S25FL512_END_ADDRESS < PrgSpiStatAdd){
//		PutStr("Address Input Error",1);
//		PutStr("Range of H'000_0000 ~ H'3FF_FFFF",1);
//		return;
	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if(S25S128_END_ADDRESS < PrgSpiStatAdd){
			PutStr("Address Input Error",1);
//			PutStr("Range of H'000_0000 ~ H'0FF_FFFF",1);
			PutStr("Range of H'000_0000 ~ H'0FF_7FFF",1);			//Change 2015.07.27
			return;
		}
	}
	else if( (gSelectQspiFlash==QSPI_BOARD) || (gSelectQspiFlash==HYPER_FLASH) ){
		if(S25FL512_END_ADDRESS < PrgSpiStatAdd){
			PutStr("Address Input Error",1);
			PutStr("Range of H'000_0000 ~ H'3FF_FFFF",1);
			return;
		}
	}

// WorkMemory CLEAR (Write H'FF)
	PutStr("Work RAM(H'50000000-H'53FFFFFF) Clear....",1);		//
	FillData32Bit((uint32_t *)Load_workStartAdd,(uint32_t *)Load_workEndAdd,0xFFFFFFFF);

	if (0U == mode) {
		if (dgLS_Load_Offset2(&workAdd_Max, &workAdd_Min))
			return;											//
	} else {
		char bin_data;
		uint32_t image_offset = 0U;
		PutStr("please send ! (binary)",1);

#if USB_ENABLE == 1
		if (gTerminal == USB_TERMINAL) {
			image_offset = ((gUserPrgSize + (DMA_TRANSFER_SIZE-1)) & ~(DMA_TRANSFER_SIZE-1));
			USB_ReadDataWithDMA((unsigned long)Load_workStartAdd, image_offset);
		} else {
			while (image_offset < gUserPrgSize) {
				GetChar(&bin_data);
				*(uint8_t *)(Load_workStartAdd + image_offset) = bin_data;
				image_offset++;
			}
		}
#else  /* USB_ENABLE == 1 */
		while (image_offset < gUserPrgSize) {
			GetChar(&bin_data);
			*(uint8_t *)(Load_workStartAdd + image_offset) = bin_data;
			image_offset++;
		}
#endif /* USB_ENABLE == 1 */

		workAdd_Min = Load_workStartAdd;
		workAdd_Max = Load_workStartAdd + gUserPrgSize - 1;
	}

	PrgSpiStatAdd = PrgSpiStatAdd + (workAdd_Min - Load_workStartAdd);
	PrgSpiEndAdd  = PrgSpiStatAdd + (workAdd_Max - workAdd_Min);
	saveSize = (PrgSpiEndAdd-PrgSpiStatAdd)+1;
	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if(PrgSpiEndAdd>S25S128_END_ADDRESS){
			PutStr("Program over size Error",1);
			PutStr(" SpiFlashMemory Stat Address : H'",0);
			Data2HexAscii(PrgSpiStatAdd,str,4);
			PutStr(str,1);
			PutStr(" SpiFlashMemory End Address  : H'",0);
			Data2HexAscii(PrgSpiEndAdd,str,4);
			PutStr(str,1);
			return;
		}
	}
	else if( (gSelectQspiFlash==QSPI_BOARD) || (gSelectQspiFlash==HYPER_FLASH) ){
		if(PrgSpiEndAdd>S25FL512_END_ADDRESS){
			PutStr("Program over size Error",1);
			PutStr(" SpiFlashMemory Stat Address : H'",0);
			Data2HexAscii(PrgSpiStatAdd,str,4);
			PutStr(str,1);
			PutStr(" SpiFlashMemory End Address  : H'",0);
			Data2HexAscii(PrgSpiEndAdd,str,4);
			PutStr(str,1);
			return;
		}
	}


	MaskSectorSize= 0xFFFC0000;

	WriteDataStatAdd     = workAdd_Min;
	ClrSpiStartSecTopAdd = PrgSpiStatAdd &   MaskSectorSize;
	ClrSpiSecEndAdd      = PrgSpiEndAdd  | ~(MaskSectorSize);

	clearSize = (ClrSpiSecEndAdd-ClrSpiStartSecTopAdd)+1;

	Read_workStartAdd    = 0x60000000;

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		if( CkQspiFlash1ClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		if( CkQspiFlash0ClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		if( CkHyperFlashClearSectorSize(Read_workStartAdd,ClrSpiStartSecTopAdd,clearSize,1) )
			return;
	}

// SAVE QSPI-FLASH
	PutStr("SAVE SPI-FLASH.......",0);

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SaveDataWithBuffeQspiFlashS25s128s(WriteDataStatAdd,PrgSpiStatAdd,saveSize);		//Manual Mode Single WriteBuffe
		PutStr(" complete!",1);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		PutStr(" ",1);
		if(PrgSpiStatAdd <0x1000000){
			if(PrgSpiEndAdd>0x1000000){
				WrittenSize   = 0x1000000-PrgSpiStatAdd;
				RemainingSize = saveSize - WrittenSize;


				Data2HexAscii(WrittenSize,str,4);							//********************* DEBUG
				PutStr(" WrittenSize      :H' ",0);							//********************* DEBUG
				PutStr(str,1);												//********************* DEBUG

				Data2HexAscii(RemainingSize,str,4);							//********************* DEBUG
				PutStr(" RemainingSize    :H' ",0);							//********************* DEBUG
				PutStr(str,1);												//********************* DEBUG


				PutStr("SpiArea : H'00000000-H'00FFFFFF",0);
				SaveDataWithBuffeQspiFlashS25fl512s(WriteDataStatAdd,PrgSpiStatAdd,WrittenSize);	//Manual Mode Single WriteBuffe
				PutStr(" complete!",1);
				PutStr("SpiArea : H'01000000-H'03FFFFFF",0);
				SaveDataQspiFlashS25fl512s_CsCont((0x50000000+WrittenSize),0x1000000,RemainingSize);	//Manual Mode Single (512)
				PutStr(" complete!",1);
			}
			else{
				PutStr("SpiArea : H'00000000-H'00FFFFFF",0);
				SaveDataWithBuffeQspiFlashS25fl512s(WriteDataStatAdd,PrgSpiStatAdd,saveSize);		//Manual Mode Single WriteBuffe
				PutStr(" complete!",1);
			}
		}
		else{
			PutStr("SpiArea : H'01000000-H'03FFFFFF",0);
			SaveDataQspiFlashS25fl512s_CsCont(WriteDataStatAdd,PrgSpiStatAdd,saveSize);			//Manual Mode Single (512)
			PutStr(" complete!",1);
		}
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SetRPC_ClockMode(RPC_CLK_40M);														//Word Program 50MHz(max)
		SaveDataWithBuffeHyperFlash(WriteDataStatAdd,PrgSpiStatAdd,saveSize);				//Manual Mode WriteBuffe
		SetRPC_ClockMode(RPC_CLK_80M);
		PutStr(" complete!",1);
	}

	PutStr("",1);
	PutStr("======= Qspi/HyperFlash Save Information  =================",1);
	PutStr(" SpiFlashMemory Stat Address : H'",0);
	Data2HexAscii(PrgSpiStatAdd,str,4);
	PutStr(str,1);
	PutStr(" SpiFlashMemory End Address  : H'",0);
	Data2HexAscii(PrgSpiEndAdd,str,4);
	PutStr(str,1);
	PutStr("===========================================================",1);
	PutStr("",1);
}






void SetData(uint32_t *setAdd)
{
	char		buf[16],key[16],chCnt,chPtr;
	uint32_t	loop;
	uint32_t 	wrData;

	loop =1;

	while(loop){
		PutStr(" Set Data : ",0);
		GetStr(key,&chCnt);
		chPtr=0;
		if(!GetStrBlk(key,buf,&chPtr,0)){
			if(chPtr==1){									/* Case Return */

			}else if(chPtr > (char)((SIZE_32BIT<<1)+1) ){	/* Case Data Size Over */
				PutStr("Syntax Error",1);
			}else{
				if(HexAscii2Data((unsigned char*)buf,&wrData)){
					PutStr("Syntax Error",1);
				}else{
					*setAdd = wrData;
					loop =0;
				}
			}
		}else{
			PutStr("Syntax Error",1);
		}
	}
}

int32_t CkSpiFlashAllF(int32_t sAdd,int32_t cap)
{
//	int32_t			ckAdd;
	uintptr_t		ckAdd;
	unsigned char	rdData;

	for(ckAdd=sAdd;ckAdd<(sAdd+cap);ckAdd++){
		rdData = *((volatile unsigned char*)ckAdd);
	    if(rdData != 0xFF){
			return(1);
	    }
	}
	return(0);
}

void SetAddInputKey(uint32_t *Address)
{
	char		str[64];
	char		buf[16],key[16],chCnt,chPtr;
	uint32_t	loop;
	uint32_t	wrData;

	loop=1;
	while(loop){
		PutStr("  Please Input : H'",0);
		GetStr(key,&chCnt);
		chPtr=0;
		if(!GetStrBlk(key,buf,&chPtr,0)){
			if(chPtr==1){									/* Case Return */
				}else if((buf[0]=='.')){					/* Case End */
				gUserPrgStartAdd = 0x40000000;
				loop =0;
			}else if(chPtr > (char)((SIZE_32BIT<<1)+1) ){	/* Case Data Size Over */
				PutStr("Syntax Error",1);
			}else{
				if(HexAscii2Data((unsigned char*)buf,&wrData)){
					PutStr("Syntax Error",1);
				}else{
					if(wrData&0x00000003){
						PutStr("Memory Boundary Error",1);
					}
					else{
						*Address = wrData;
						loop =0;
					}
				}
			}
		}else{
			PutStr("Syntax Error",1);
		}
	}
}

void SetSizeInputKey(uint32_t *size)
{
	char		str[64];
	char		buf[16],key[16],chCnt,chPtr;
	uint32_t	loop;
	uint32_t	wrData;

	loop=1;
	while(loop){
		PutStr("  Please Input : H'",0);
		GetStr(key,&chCnt);
		chPtr=0;
		if(!GetStrBlk(key,buf,&chPtr,0)){
			if(chPtr==1){									/* Case Return */
				}else if((buf[0]=='.')){					/* Case End */
				loop =0;
			}else if(chPtr > (char)((SIZE_32BIT<<1)+1) ){	/* Case Data Size Over */
				PutStr("Syntax Error",1);
			}else{
				if(HexAscii2Data((unsigned char*)buf,&wrData)){
					PutStr("Syntax Error",1);
				}else{
					*size = wrData;
					loop =0;
				}
			}
		}else{
			PutStr("Syntax Error",1);
		}
	}
}


/****************************************************************
	MODULE				: dgGen3InfoSpiflash0_SA0	(S25fl512s)	*
	FUNCTION			: read SA0 spi Spiflash memory			*
	COMMAND				: XINFO_SA0								*
	INPUT PARAMETER		: XINFO_SA0			 					*
*****************************************************************/
void dgGen3InfoSpiflash0_SA0(void)
{
	char str[64];
	uint32_t bootRomPara;
	uint32_t prgStAdd,prgSize;
	uint32_t prgStAdd_B,prgSize_B;
	uint32_t readManuId,readDevId;
	uint32_t spiFlashStatAdd,workTopAdd,rdBufstatAdd;
	uintptr_t readAdd;

	PutStr("=== SPI SA0 System Area Information  ===",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();
	if(CheckQspiFlashId())
		return;						//Error abortt

//Setting  SPI_Add, workRAM_Add
	spiFlashStatAdd = S25FL512_SA00_STARTAD;

	workTopAdd      = 0x60000000;
	rdBufstatAdd    = workTopAdd + spiFlashStatAdd;			//0x60000000 + 0x0000000 = 0x60000000

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SectorRdQspiFlashS25s128s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorRdQspiFlashS25fl512s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorRdHyperFlash(spiFlashStatAdd,rdBufstatAdd);
	}

//Read Boot ROM Parameters Address
	readAdd  = workTopAdd + S25FL512_SA00_BTROM_PARA;
	bootRomPara = *(uint32_t *)readAdd;
//Read Program Start Address
	readAdd  = workTopAdd + S25FL512_SA00_A_IPL_ADD;
	prgStAdd = *(uint32_t *)readAdd;
//Read Program Size
	readAdd  = workTopAdd + S25FL512_SA00_A_IPL_SIZE;
	prgSize = *(uint32_t *)readAdd;
//Read Program Start Address
	readAdd  = workTopAdd + S25FL512_SA00_B_IPL_ADD;
	prgStAdd_B = *(uint32_t *)readAdd;
//Read Program Size
	readAdd  = workTopAdd + S25FL512_SA00_B_IPL_SIZE;
	prgSize_B = *(uint32_t *)readAdd;

	Data2HexAscii(bootRomPara,str,4);				
	PutStr(" Boot ROM Parameters                  : H'",0);	PutStr(str,1);
	Data2HexAscii(prgStAdd,str,4);
	PutStr(" A-side IPL Address   (Loader Address): H'",0);	PutStr(str,1);
	Data2HexAscii(prgSize,str,4);
	PutStr(" A-side IPL data size (Loader size)   : H'",0);	PutStr(str,1);
	Data2HexAscii(prgStAdd_B,str,4);
	PutStr(" B-side IPL Address   (Loader Address): H'",0);	PutStr(str,1);
	Data2HexAscii(prgSize_B,str,4);
	PutStr(" B-side IPL data size (Loader size)   : H'",0);	PutStr(str,1);
	PutStr("==================================================",1);
}



int32_t CheckDataChange(uintptr_t checkAdd)
{
	uint32_t data;
	uint32_t change;
	char str[64];
	char keyBuf[32],chCnt;

	change = CHANGE_OFF;

	data = *(uint32_t *)checkAdd;

	Data2HexAscii(data,str,4);	PutStr(str,1);
	while(1){
		PutStr(" Change ?(Y/N)",0);	GetStr(keyBuf,&chCnt);
		if(chCnt==1){
			if((keyBuf[0]=='Y')||(keyBuf[0]=='y')){
				PutStr(" Please Input New Data ",1);
				SetData(&data);
				*((uint32_t*)checkAdd) = data;
				change = CHANGE_ON;
				break;
			}
			if((keyBuf[0]=='N')||(keyBuf[0]=='n'))
				break;
		}
	}
	return(change);
}
/****************************************************************
	MODULE				: dgGen3InfoSpiflash0_SA0	(S25fl512s)	*
	FUNCTION			: set SA0 spi Spiflash memory			*
	COMMAND				: XINFO_SA0_S							*
	INPUT PARAMETER		: XINFO_SA0_S		 					*
*****************************************************************/
void dgGen3InfoSetSpiflash0_SA0(void)
{
	char str[64];
	uint32_t change;
	uint32_t spiFlashStatAdd,workTopAdd,rdBufstatAdd;
	uintptr_t readAdd;
	uint32_t readManuId,readDevId;
	uint32_t OnBoradSpiSysSize;

	change = CHANGE_OFF;

	PutStr("=== SPI SA0 System Area Information  ===",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();
	if(CheckQspiFlashId())
		return;						//Error abortt

//Setting  SPI_Add, workRAM_Add
	spiFlashStatAdd = S25FL512_SA00_STARTAD;

	workTopAdd      = 0x60000000;
	rdBufstatAdd    = workTopAdd + spiFlashStatAdd;			//0x60000000 + 0x0000000 = 0x60000000
	OnBoradSpiSysSize    = 0x2000;

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		FastRd3adQspiFlashS25s128s(spiFlashStatAdd,rdBufstatAdd,OnBoradSpiSysSize);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorRdQspiFlashS25fl512s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorRdHyperFlash(spiFlashStatAdd,rdBufstatAdd);
	}

//Boot ROM Parameters Address
	readAdd  = workTopAdd + S25FL512_SA00_BTROM_PARA;
	PutStr(" Boot ROM Parameters                  : H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))		change=CHANGE_ON;
//A-side IPL Address
	readAdd  = workTopAdd + S25FL512_SA00_A_IPL_ADD;
	PutStr(" A-side IPL Address   (Loader Address): H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))		change=CHANGE_ON;
//A-side IPL data size
	readAdd  = workTopAdd + S25FL512_SA00_A_IPL_SIZE;
	PutStr(" A-side IPL data size (Loader size)   : H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))		change=CHANGE_ON;
//B-side IPL Address
	readAdd  = workTopAdd + S25FL512_SA00_B_IPL_ADD;
	PutStr(" B-side IPL Address   (Loader Address): H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))		change=CHANGE_ON;
//B-side IPL data size
	readAdd  = workTopAdd + S25FL512_SA00_B_IPL_SIZE;
	PutStr(" B-side IPL data size (Loader size)   : H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))		change=CHANGE_ON;

	if(change == CHANGE_ON){
//		PutStr("SPI Data Clear(H'FF):H'000000-03FFFF Erasing.",0);
		if(gSelectQspiFlash ==ONBOARD_QSPI){
//			SectorEraseQspiFlashS25s128s(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
			PutStr("SPI Data Clear(H'FF):H'000000-001FFF Erasing.",0);
			ParameterSectorEraseQspiFlashS25s128s(spiFlashStatAdd,((OnBoradSpiSysSize)-1));
		}
		else if(gSelectQspiFlash ==QSPI_BOARD){
			PutStr("SPI Data Clear(H'FF):H'000000-03FFFF Erasing.",0);
			SectorEraseQspiFlashS25fl512s(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
		}
		else if(gSelectQspiFlash ==HYPER_FLASH){
			PutStr("SPI Data Clear(H'FF):H'000000-03FFFF Erasing.",0);
			SectorEraseHyperFlashRange(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
		}
//		SoftDelay(4000);			//Add 2015.07.21
		ResetHyperFlash();
		PutStr("SAVE SPI-FLASH.......",0);
		if(gSelectQspiFlash ==ONBOARD_QSPI){
			SaveDataWithBuffeQspiFlashS25s128s(rdBufstatAdd,spiFlashStatAdd,OnBoradSpiSysSize);		//Manual Mode Single WriteBuffe //o
		}
		else if(gSelectQspiFlash ==QSPI_BOARD){
			SaveDataQspiFlashS25fl512s_CsCont(rdBufstatAdd,spiFlashStatAdd,S25FL512_SA_SIZE);			//Manual Mode Single (512)
		}
		else if(gSelectQspiFlash ==HYPER_FLASH){
			SetRPC_ClockMode(RPC_CLK_40M);															//Word Program 50MHz(max)
			SaveDataWithBuffeHyperFlash(rdBufstatAdd,spiFlashStatAdd,S25FL512_SA_SIZE);				//Manual Mode WriteBuffe	//o
			SetRPC_ClockMode(RPC_CLK_80M);
		}
		PutStr(" complete!",1);
	}
}




/****************************************************************
	MODULE				: dgGen3InfoSpiflash0		(S25fl512s)	*
	FUNCTION			: read SA3 spi Spiflash memory			*
	COMMAND				: XINFO									*
	INPUT PARAMETER		: XINFO				 					*
*****************************************************************/
void dgGen3InfoSpiflash0(void)
{
	char str[64];
	uint32_t prgStAdd,prgSize;
	uint32_t readManuId,readDevId;
	uint32_t spiFlashStatAdd,workTopAdd,rdBufstatAdd;
	uintptr_t readAdd;

	PutStr("=== SPI SA3 System Area Information  ===",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();
	if(CheckQspiFlashId())
		return;						//Error abortt

//Setting  SPI_Add, workRAM_Add
	spiFlashStatAdd = S25FL512_SA03_STARTAD;

	workTopAdd      = 0x60000000;
	rdBufstatAdd    = workTopAdd + spiFlashStatAdd;			//0x60000000 + 0x00C0000 = 0x600C0000

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SectorRdQspiFlashS25s128s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorRdQspiFlashS25fl512s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorRdHyperFlash(spiFlashStatAdd,rdBufstatAdd);
	}
//Read Program Start Address
	readAdd  = workTopAdd + S25FL512_SA03_PRG_ST_AD;
	prgStAdd = *(uint32_t *)readAdd;
//Read Program Size
	readAdd  = workTopAdd + S25FL512_SA03_PRG_SIZE;
	prgSize = *(uint32_t *)readAdd;

	Data2HexAscii(prgStAdd,str,4);
	PutStr(" Program Start Address : H'",0);		PutStr(str,1);
	Data2HexAscii(prgSize,str,4);
	PutStr(" Program Size (Byte/4) : H'",0);		PutStr(str,1);
	PutStr("==================================================",1);
}



/****************************************************************
	MODULE				: dgGen3InfoSetSpiflash0	(S25fl512s)	*
	FUNCTION			: set SA3 spi Spiflash memory			*
	COMMAND				: XINFO_S								*
	INPUT PARAMETER		: XINFO_S			 					*
*****************************************************************/
void dgGen3InfoSetSpiflash0(void)
{
	char str[64];
	uint32_t change;
	uint32_t spiFlashStatAdd,workTopAdd,rdBufstatAdd,readAdd;
	uint32_t readManuId,readDevId;

	change = CHANGE_OFF;

	PutStr("=== SPI SA3 System Area Information  ===",1);
	SelQspiFlashSetSw();
	InitRPC_Mode();
	if(CheckQspiFlashId())
		return;						//Error abortt

//Setting  SPI_Add, workRAM_Add
	spiFlashStatAdd = S25FL512_SA03_STARTAD;
	workTopAdd      = 0x60000000;
	rdBufstatAdd    = workTopAdd + spiFlashStatAdd;			//0x60000000 + 0x00C0000 = 0x600C0000

	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SectorRdQspiFlashS25s128s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		SectorRdQspiFlashS25fl512s(spiFlashStatAdd,rdBufstatAdd);
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		SectorRdHyperFlash(spiFlashStatAdd,rdBufstatAdd);
	}

//Address
	readAdd  = workTopAdd + S25FL512_SA03_PRG_ST_AD;
	PutStr(" Program Start Address : H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))			change=CHANGE_ON;
//Size
	readAdd  = workTopAdd + S25FL512_SA03_PRG_SIZE;
	PutStr(" Program Size (Byte/4) : H'",0);
	if(CHANGE_ON==CheckDataChange(readAdd))			change=CHANGE_ON;

	if(change == CHANGE_ON){
		PutStr("SPI Data Clear(H'FF):H'0C0000-0FFFFF Erasing.",0);
		if(gSelectQspiFlash ==ONBOARD_QSPI){
			SectorEraseQspiFlashS25s128s(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
		}
		else if(gSelectQspiFlash ==QSPI_BOARD){
			SectorEraseQspiFlashS25fl512s(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
		}
		else if(gSelectQspiFlash ==HYPER_FLASH){
			SectorEraseHyperFlashRange(spiFlashStatAdd,((spiFlashStatAdd+0x4)-1));
		}

		PutStr("SAVE SPI-FLASH.......",0);
		if(gSelectQspiFlash ==ONBOARD_QSPI){
			SaveDataWithBuffeQspiFlashS25s128s(rdBufstatAdd,spiFlashStatAdd,S25FL512_SA_SIZE);		//Manual Mode Single WriteBuffe
		}
		else if(gSelectQspiFlash ==QSPI_BOARD){
			SaveDataQspiFlashS25fl512s_CsCont(rdBufstatAdd,spiFlashStatAdd,S25FL512_SA_SIZE);		//Manual Mode Single (512)
		}
		else if(gSelectQspiFlash ==HYPER_FLASH){
			SetRPC_ClockMode(RPC_CLK_40M);															//Word Program 50MHz(max)
			SaveDataWithBuffeHyperFlash(rdBufstatAdd,spiFlashStatAdd,S25FL512_SA_SIZE);				//Manual Mode WriteBuffe
			SetRPC_ClockMode(RPC_CLK_80M);
		}
		PutStr(" complete!",1);
	}
}









/****************************************************************
	MODULE				: dgClearSpiflash0	(S25fl512s)			*
	FUNCTION			: Clear Spiflash memory					*
	COMMAND				: CS									*
	INPUT PARAMETER		: CS					 				*
*****************************************************************/
void dgClearSpiflash0(void)
{
	char str[64];
	uint32_t	readManuId,readDevId;
	int32_t	Rtn;

	Rtn=NORMAL_END;

	PutStr("ALL ERASE SpiFlash or HyperFlash memory ",1);
	PutStr("Clear OK?(y/n)",0);
	if( WaitKeyIn_YorN() ){	// Return1=N
	    DelStr(14);
		return;
	}
	DelStr(14);
	SelQspiFlashSetSw();
	InitRPC_Mode();

	if(CheckQspiFlashId())
		return;						//Error abortt
	if(gSelectQspiFlash ==ONBOARD_QSPI){
		PutStr(" ERASE QSPI-FLASH (60sec[typ])....",0);
		Rtn=BulkEraseQspiFlashS25s128s();
	}
	else if(gSelectQspiFlash ==QSPI_BOARD){
		PutStr(" ERASE QSPI-FLASH (103sec[typ])....",0);
		Rtn=BulkEraseQspiFlashS25fl512s();
	}
	else if(gSelectQspiFlash ==HYPER_FLASH){
		PutStr(" ERASE HYPER-FLASH (96sec[typ])....",0);
		Rtn=ChipEraseHyperFlash();
	}
	if(Rtn==NORMAL_END)
		PutStr(" complete!",1);
	else
		PutStr(" Fail!",1);
}










char dgLS_Load_Offset2(uint32_t *maxADD ,uint32_t *minADD)
{
	char 	str[12];
//	unsigned long data,getByteCount,byteCount;
	uint32_t data;
	uint32_t getByteCount,byteCount;
//	uint32_t loadGetCount,adByteCount,loadGetAddress,loadGetData,loadGetSum,loadGetCR;
	uint32_t loadGetCount,adByteCount,loadGetData,loadGetSum,loadGetCR;
	uintptr_t loadGetAddress;
	uint32_t loop,loop_S0,s0flag,errFlg,checkData,endFlg;

//**** Add dgLS_Load2 ********************************************************************
	uint32_t workAdd_Min,workAdd_Max;
	workAdd_Min = 0xFFFFFFFF;
	workAdd_Max = 0x00000000;
//****************************************************************************************


	uint32_t WorkStartAdd,Calculation;
	uint32_t loadOffset;

	WorkStartAdd = LS_WORK_DRAM_SADD;		//H'50000000

	if(gSpiFlashSvArea==1||gSpiFlashSvArea==2){
//		loadOffset = 0;
		loadOffset  = gUserPrgStartAdd - WorkStartAdd ;		//Change
//		Calculation = ADDITION;
			Calculation = SUBTRACTION;						//Change
	}
	if(gSpiFlashSvArea==3){
		if((0x40000000 <= gUserPrgStartAdd) && (gUserPrgStartAdd < WorkStartAdd)) {				//H'40000000 =< gUserPrgStartAdd < H'50000000
			loadOffset = WorkStartAdd - gUserPrgStartAdd ;
			Calculation = ADDITION;
   		}
		else if((WorkStartAdd <= gUserPrgStartAdd) && (gUserPrgStartAdd < 0xC0000000)) {		//H'50000000 =< gUserPrgStartAdd < H'C0000000
			loadOffset = gUserPrgStartAdd - WorkStartAdd ;
			Calculation = SUBTRACTION;
   		}


//		else if(((SECURERAM_SADD + 0x4000 )<= gUserPrgStartAdd) && (gUserPrgStartAdd <= SECURERAM_EADD)) {	//H'E6300000 + H'4000 =< gUserPrgStartAdd < H'E633FFFF
		else if(( SYSTEMRAM_SADD<= gUserPrgStartAdd) && (gUserPrgStartAdd <= PUBLICRAM_EADD))            {	//H'E6300000 =< gUserPrgStartAdd < H'E635FFFF  	//Change 2015.06.19
			loadOffset = gUserPrgStartAdd - WorkStartAdd ;
			Calculation = SUBTRACTION;
   		}

		else{
			PutStr("ERROR Load file.   <Download  file  DRAM(H'40000000-H'BFFFFFFF) , RAM(H'E6300000-H'E635FFFF) ONLY > ",1);		//Change 2015.06.19
			return(1);
		}
	}//--------------------------------------------------------------------------------

	loop	=1;
	loop_S0	=1;
	errFlg	=0;
	endFlg	=0;
	checkData = 0xFF;

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
				case '0':
					s0flag =1;
					while(loop_S0){
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
				case '7':				// S7,S8,S9:
				case '8':
				case '9':
					endFlg =1;
					break;
				default:
					errFlg =1;
					break;
			}
		}
		if(endFlg==1 || errFlg==1){
			while(1){
				GetChar(str);
				if((*str==CR_CODE)||(*str==LF_CODE)){

//**** Add dgLS_Load2 ********************************************************************
					*maxADD = workAdd_Max;
					*minADD = workAdd_Min;
//****************************************************************************************

					return(0);
				}
			}
		}
		if(s0flag == 0){
		//Get Byte count (addressByteCount + dataByteCount + sumCheckByteCount(=1) )
			getByteCount =1;
			GetStr_ByteCount(str,getByteCount);
			HexAscii2Data((unsigned char*)str,&data);
			loadGetCount = data;
		//Get Address
			getByteCount =adByteCount;
			GetStr_ByteCount(str,getByteCount);
			HexAscii2Data((unsigned char*)str,&data);
			loadGetAddress = data;

//Add------------------------------------------------------------------------------
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
				HexAscii2Data((unsigned char*)str,&data);
				loadGetData = data;
				*((unsigned char *)loadGetAddress) = loadGetData;
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
			HexAscii2Data((unsigned char*)str,&data);
			loadGetSum = data;
		//Get CR code
			GetChar(str);
			loadGetCR = *str;
			if((loadGetCR==CR_CODE)||(loadGetCR==LF_CODE)){
				loop=1;
			}
		}
	}
}















