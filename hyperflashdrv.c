/*
 * Copyright (c) 2015-2016, Renesas Electronics Corporation
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

#include "common.h"
#include "rpcqspidrv.h"
#include "bit.h"
#include "rpchyperdrv.h"
#include "hyperflashdrv.h"
#include "dgtable.h"
#include "dgmodul4.h"


uint16_t gHyperFlashIdCfi[0x100];


void ResetHyperFlash(void)
{
	//Reset / ASO Exit

	WriteCommandHyperFlash(0,HYPER_FL_RESET_COM);
		// Address=xxxx
}


uint32_t ReadHyperFlashID(uint32_t *readData)
{
	uint32_t rdFlashData[2];
	uint32_t addr,i;

	//1st
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//2nd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//3rd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK3_ADD, HYPER_FL_ID_ENTRY_COM);

	for(addr=0,i=0;addr<0x10;addr+=8){
		ReadHyperFlashData(addr,rdFlashData,8);
		gHyperFlashIdCfi[i] = (rdFlashData[0] >> 16); 			i++;
		gHyperFlashIdCfi[i] = (rdFlashData[0] &  0x0000FFFF); 	i++;
		gHyperFlashIdCfi[i] = (rdFlashData[1] >> 16); 			i++;
		gHyperFlashIdCfi[i] = (rdFlashData[1] &  0x0000FFFF); 	i++;
		if(addr==0)	*readData = ((rdFlashData[0]&0xFF000000)>>8 | ((rdFlashData[0]&0x00FF0000)<<8) | ((rdFlashData[0]&0x0000FF00)>>8) | ((rdFlashData[0]&0x000000FF)<<8)) ;
	}
	ResetHyperFlash();
	return(0);
}


void WordProgramHyperFlash(uint32_t writeAddr, uint32_t writeData)
{
	//Word Program
	uint32_t hyperFlashStatus;
	uint32_t loopf;
	uint32_t status=0;
	uint32_t readData[2];

	//1st
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//2nd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//3rd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK3_ADD, HYPER_FL_WORD_PROGRAM_COM);

	//4th
	WriteDataHyperFlash(writeAddr, writeData);

	while(1){
		status = ReadStatusHyperFlash(readData);
		if( status & BIT7 )	break;		//BIT7: Device Ready Bit (0=Busy, 1=Ready)
	}
}

void SectorEraseHyperFlash(uint32_t sector_addr)
{
	uint32_t hyperFlashStatus;
	uint32_t loopf;
	uint32_t readData[2];
	uint32_t status=0;

	//1st
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//2nd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//3rd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK3_ADD, HYPER_FL_ERASE_1ST_COM);

	//4th
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//5th
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//Sixth Command
	WriteCommandHyperFlash((sector_addr>>1), HYPER_FL_SECTOR_ERASE_COM);

	while(1){
		status = ReadStatusHyperFlash(readData);
		if( status & BIT7 )	break;		//BIT7: Device Ready Bit (0=Busy, 1=Ready)
	}

}

int32_t ChipEraseHyperFlash(void)
{
	uint32_t hyperFlashStatus;
	uint32_t loopf;
	uint32_t status=0;
	uint32_t readData[2];
	
	int32_t errFlag;

	errFlag = NORMAL_END;
	
	char str[10];

	//1st
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//2nd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//3rd
	WriteCommandHyperFlash(HYPER_FL_UNLOCK3_ADD, HYPER_FL_ERASE_1ST_COM);

	//4th
	WriteCommandHyperFlash(HYPER_FL_UNLOCK1_ADD, HYPER_FL_UNLOCK1_DATA);

	//5th
	WriteCommandHyperFlash(HYPER_FL_UNLOCK2_ADD, HYPER_FL_UNLOCK2_DATA);

	//Sixth Command
	WriteCommandHyperFlash(HYPER_FL_UNLOCK3_ADD, HYPER_FL_CHIP_ERASE_COM);

	while(1){
		status = ReadStatusHyperFlash(readData);

//Data2HexAscii(status,str,4);								//********************* DEBUG
//PutStr(" readData(status)      : ",0);					//********************* DEBUG
//PutStr(str,1);											//********************* DEBUG
		if( status & BIT5 ){						//BIT5: Erase Status Bit (0=Successful, 1=Fail)
//			PutStr("Erase Fail",0); 
			errFlag=ERROR_END;
			break;
		}
		if( status & BIT7 )	break;					//BIT7: Device Ready Bit (0=Busy, 1=Ready)
	}
	return(errFlag);
}

//////////////////////////////////
// Read (External Address Space Read Mode)
//////////////////////////////////
void RdHyperFlash (uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	InitRPC_HyperFlashExtMode();
	
	sourceAdd = (SPI_IOADDRESS_TOP + sourceSpiAdd);

//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}
void RdManuHyperFlash(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount)
{
	char str[10];
	uint32_t		readAdd;
	uint32_t		rdData;
	
	rdData=destinationAdd;

	for(readAdd=sourceSpiAdd ; readAdd<(sourceSpiAdd+byteCount) ; readAdd+=4){
//		ReadHyperFlashData4Byte(readAdd, &rdData);
		ReadHyperFlashData8Byte(readAdd, &rdData);
/*
	Data2HexAscii(readAdd,str,4);
	PutStr(" readAdd  = 0x",0);
	PutStr(str,1);
*/
		destinationAdd +=4;
	}
}


void SaveDataWithBuffeHyperFlash(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeDataAdd;
	char str[64];		//DEBUG

	writeDataAdd = srcAdd;

	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){	//256byte:RPC Write Buffer size

//Data2HexAscii(flashAdd,str,4);							//********************* DEBUG
//PutStr(" flashAdd      : ",0);							//********************* DEBUG
//PutStr(str,1);											//********************* DEBUG

//Data2HexAscii(writeDataAdd,str,4);						//********************* DEBUG
//PutStr(" writeDataAdd  : ",0);							//********************* DEBUG
//PutStr(str,1);											//********************* DEBUG

		WordProgramWithBuffeHyperFlash(flashAdd, writeDataAdd);
		writeDataAdd = writeDataAdd + 256;
	}
}
void SaveDataHyperFlash(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeData;
	char str[64];		//DEBUG

	WriteProtectDisable();

	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=4){
		writeData = *(volatile uint32_t*)srcAdd;

//Data2HexAscii(flashAdd,str,4);							//********************* DEBUG
//PutStr(" flashAdd      : ",0);							//********************* DEBUG
//PutStr(str,1);											//********************* DEBUG

		WordProgramHyperFlash(flashAdd,writeData);
		srcAdd = srcAdd + 4;
	}
}


void WordProgramWithBuffeHyperFlash(uint32_t addr, uint32_t source_addr)
{
	uint32_t loopf;
	uint32_t hyperFlashStatus;
	uint32_t status=0;
	uint32_t readData[2];

	WriteProtectDisable();
//	PutStr(" WriteProtectDisable",1);
	WriteBufferOperationHyperFlash(addr,source_addr);
	WaitRpcTxEnd();				//Add 2015.07.21
//SoftDelay(2000);				//Add 2015.07.21

#if 0
//Add 2015.07.22
	loopf=1;
	while(loopf){
		
	PutStr("hyperFlashStatus Check ",1);			//DEBUG=================================

		ReadStatusHyperFlash(&hyperFlashStatus);
		if(hyperFlashStatus & BIT7)	loopf=0;
	}
#endif
	while(1){
		status = ReadStatusHyperFlash(readData);
		if( status & BIT7 )	break;		//BIT7: Device Ready Bit (0=Busy, 1=Ready)
	}
}


void SectorEraseHyperFlashRange(uint32_t EraseStatAdd,uint32_t EraseEndAdd)
{
	uint32_t	sectorAd;
	uint32_t	SectorStatTopAdd,SectorEndTopAdd;

//	char str[64];		//DEBUG
	SectorStatTopAdd = EraseStatAdd & 0xFFFC0000;
	SectorEndTopAdd  = EraseEndAdd  & 0xFFFC0000;
//MON Debug
//				PutStr(" -------- SectorErase --------  : ",1);				//********************* DEBUG
//				Data2HexAscii(SectorStatTopAdd,str,4);						//********************* DEBUG
//				PutStr(" SectorStatTopAdd        : H' ",0);					//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
//				Data2HexAscii(SectorEndTopAdd,str,4);						//********************* DEBUG
//				PutStr(" SectorEndTopAdd         : H' ",0);					//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
///MON Debug
	for(sectorAd =SectorStatTopAdd;sectorAd<=SectorEndTopAdd;sectorAd=sectorAd+0x40000 ){
		SectorEraseHyperFlash(sectorAd);
		PutStr(".",0);
	}
	PutStr("Erase Completed ",1);
}

void SectorRdHyperFlash(uint32_t spiStatAdd,uint32_t distRamAdd)
{
	uint32_t	SectorStatTopAdd,readSize;
	unsigned char	*bufPtr;
	char str[64];		//DEBUG

	SectorStatTopAdd = spiStatAdd & 0xFFFC0000;
	readSize  = 0x40000;

//MON Debug
//				PutStr(" -------- SectorRead --------  : ",1);				//********************* DEBUG
//				Data2HexAscii(spiStatAdd,str,4);							//********************* DEBUG
//				PutStr(" spiStatAdd        : H'",0);						//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
//				Data2HexAscii(SectorStatTopAdd,str,4);						//********************* DEBUG
//				PutStr(" SectorStatTopAdd  : H'",0);						//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
//				Data2HexAscii(distRamAdd,str,4);							//********************* DEBUG
//				PutStr(" distRamAdd        : H'",0);						//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
///MON Debug
	RdHyperFlash(SectorStatTopAdd,distRamAdd,readSize);
}

