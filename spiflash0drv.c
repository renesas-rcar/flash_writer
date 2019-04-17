/*
 * Copyright (c) 2015-2018, Renesas Electronics Corporation
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
#include "bit.h"
#include "rpcqspidrv.h"
#include "spiflash0drv.h"
#include "dgtable.h"
#include "dgmodul4.h"

//////////////////////////////////////////////////////////////////////////////////////
//
// QSPI SPI-FLASH  S25FL512S
//
//////////////////////////////////////////////////////////////////////////////////////
void FastRdQspiFlashS25fl512s(uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	InitRPC_QspiFlash4FastReadExtMode();
	sourceAdd = SPI_IOADDRESS_TOP + sourceSpiAdd;

//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}

//////////////////////////////////
// Qspi:Quad Read  (4QOR 6Ch)
//////////////////////////////////
void QuadRdQspiFlashS25fl512s (uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	EnableQuadModeQspiFlashS25fl512s();

	InitRPC_QspiFlashQuadExtMode();
	sourceAdd = SPI_IOADDRESS_TOP + sourceSpiAdd;

//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}


void FastRdManuQspiFlashS25fl512s(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount)
{
	uint32_t		readAdd;
	uint32_t		rdData;
	
	rdData=destinationAdd;

	for(readAdd=sourceSpiAdd ; readAdd<(sourceSpiAdd+byteCount) ; readAdd+=4){
		SingleFastReadQspiFlashData4Byte(readAdd, &rdData);
		*((uint32_t *) destinationAdd) = rdData;
		destinationAdd +=4;
	}
}






//////////////////////////////////////////
// Qspi:Enable QUAD mode (Config.bit1)
//////////////////////////////////////////
void EnableQuadModeQspiFlashS25fl512s(void)
{
	uint32_t statusReg,configReg;

	ReadConfigRegQspiFlash(&configReg);
	if(!(configReg & BIT1)){
		//PutStr("QUAD mode set!",1);
		WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
		ReadStatusQspiFlash(&statusReg);
		configReg |= BIT1;		// QUAD=1
//		WriteRegisterQspiFlash(statusReg,configReg);
		WriteRegisterQspiFlash_Byte2(statusReg,configReg);
		while(1){
			ReadStatusQspiFlash(&statusReg);
			if( !(statusReg & BIT0) )	break;
		}
	}}


//////////////////////////////////////////
// Qspi:Sector Erase (256kB)	
//////////////////////////////////////////
void SectorErase256kbQspiFlashS25fl512s(uint32_t addr)
{
	uint32_t	status;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	SectorErase4QspiFlash(addr);

	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}


//////////////////////////////////////////
// Qspi:Bulk Erase (All)
//////////////////////////////////////////
int32_t BulkEraseQspiFlashS25fl512s(void)
{
	uint32_t status;
	int32_t errFlag;

	errFlag = NORMAL_END;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteCommandQspiFlash(0x00600000);	//Bulk Erase (BE 60h)
	
	while(1){
		ReadStatusQspiFlash(&status);
		if( (status & BIT5) ){			//BIT5  1:Erase Error Occurred  0:No Error.
			errFlag=ERROR_END;
			break;
		}
		if( !(status & BIT0) )	break;	//BIT0  1:Device Busy  0:Ready Device is in Standby
	}
	return(errFlag);
}



void PageProgramQspiFlashS25fl512s(uint32_t addr,uint32_t writeData)
{
	uint32_t wrData,rdData,i,status,loopCount,dummyRd;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4ppQspiFlash(addr, writeData);
}

void PageProgramQspiFlashS25fl512s_CsCont(uint32_t addr, uint32_t *writeData,uint32_t byteCount)
{
	uint32_t loopCount;
	uint32_t status;

	loopCount = (byteCount>>2); 

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4ppQspiFlash_CsCont(addr, writeData,loopCount);
	
//Add 2015.07.19
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}

void PageProgramWithBuffeQspiFlashS25fl512s(uint32_t addr, uint32_t source_addr)
{
	uint32_t status;

//	EnableQuadModeQspiFlashS25fl512s();

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
//	WriteData4ppWithBufferQspiFlash(addr,source_addr);
	WriteDataPpWithBufferQspiFlash(addr,source_addr);

//Add
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}

}


void PageProgram4PPWithBuffeQspiFlashS25fl512s(uint32_t addr, uint32_t source_addr)
{
	uint32_t status;

//	EnableQuadModeQspiFlashS25fl512s();

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4ppWithBufferQspiFlash(addr,source_addr);

	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}


void PageProgram02hWithBuffeQspiFlashS25fl512s(uint32_t addr, uint32_t source_addr)
{
	uint32_t status;

	EnableQuadModeQspiFlashS25fl512s();

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
//	WriteData4ppWithBufferQspiFlash(addr,source_addr);
	WriteDataWithBufferQspiFlash(addr,source_addr);

	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}




//////////////////////////////////////////
// Qspi:Quad Page Program (4QPP:34h)
//////////////////////////////////////////
// wrCount:Max512
//void QuadPageProgramQspiFlashS25fl512s(unsigned long add,
//				 		   	   unsigned char *wrBuf,
//					   	   	   unsigned long byteCount,
//						   	   unsigned long accessSize)
void QuadPageProgramQspiFlashS25fl512s(uint32_t addr,uint32_t writeData)
{

	uint32_t status;

	EnableQuadModeQspiFlashS25fl512s();

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4qppQspiFlash(addr,writeData);

//Add 2015.07.19
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}





void SaveDataQspiFlashS25fl512s(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeData;

	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=4){
		writeData = *(volatile uint32_t*)srcAdd;
	    PageProgramQspiFlashS25fl512s(flashAdd,writeData);
		srcAdd = srcAdd + 4;
	}
//	bufPtr = (unsigned char*)srcAdd;
//	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=512){
//	    PageProgramQspiFlashS25fl512s(flashAdd,bufPtr,512,1);
//	    bufPtr = (unsigned char*)(bufPtr+512);
//	}
}

void SaveDataQspiFlashS25fl512s_CsCont_Byte(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	unsigned char *bufPtr;
	uint32_t flashAdd;

	bufPtr = (unsigned char*)srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=512){
//	    PageProgramQspiFlashS25fl512s     (flashAdd,bufPtr,512,1);
		PageProgramQspiFlashS25fl512s_CsCont(flashAdd,(uint32_t *)bufPtr,512);
	    bufPtr = (unsigned char*)(bufPtr+512);
	}
}
void SaveDataQspiFlashS25fl512s_CsCont(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
//	unsigned char *bufPtr;
	uint32_t *bufPtr;
	uint32_t flashAdd;

	bufPtr = (uint32_t*)srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=512){
//	    PageProgramQspiFlashS25fl512s     (flashAdd,bufPtr,512,1);
		PageProgramQspiFlashS25fl512s_CsCont(flashAdd,bufPtr,512);
	    bufPtr = (uint32_t*)(bufPtr+(512/4));
	}
}


void SaveDataWithBuffeQspiFlashS25fl512s(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeDataAdd;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE

	writeDataAdd = srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){	//256byte:RPC Write Buffer size
		PageProgramWithBuffeQspiFlashS25fl512s(flashAdd, writeDataAdd);
		writeDataAdd = writeDataAdd + 256;
	}
}

void SaveData4PPWithBuffeQspiFlashS25fl512s(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeDataAdd;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE

	writeDataAdd = srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){	//256byte:RPC Write Buffer size
		PageProgram4PPWithBuffeQspiFlashS25fl512s(flashAdd, writeDataAdd);
		writeDataAdd = writeDataAdd + 256;
	}
}

//////////////////////////////////////////
// Qspi:Quad Page Program (4QPP:34h)
//////////////////////////////////////////
void SaveDataQuadQspiFlashS25fl512s(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeData;

	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=4){
		writeData = *(volatile uint32_t*)srcAdd;
	    QuadPageProgramQspiFlashS25fl512s(flashAdd,writeData);
		srcAdd = srcAdd + 4;
	}
#if 0
	bufPtr = (unsigned char*)srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=512){
	    QuadPageProgramQspiFlashS25fl512s(flashAdd,bufPtr,512,1);
	    bufPtr = (unsigned char*)(bufPtr+512);
	}
#endif
}



void SectorEraseQspiFlashS25fl512s(uint32_t EraseStatAdd,uint32_t EraseEndAdd)
{
	uint32_t	sectorAd;
	uint32_t	SectorStatTopAdd,SectorEndTopAdd;

	char str[64];		//DEBUG

	SectorStatTopAdd = EraseStatAdd & 0xFFFC0000;
	SectorEndTopAdd  = EraseEndAdd  & 0xFFFC0000;

//MON Debug
//				PutStr(" -------- SectorEraseQspiFlashS25fl512s --------  : ",1);		//********************* DEBUG
//				Data2HexAscii(SectorStatTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorStatTopAdd        : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
//				Data2HexAscii(SectorEndTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorEndTopAdd         : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
///MON Debug




	for(sectorAd =SectorStatTopAdd;sectorAd<=SectorEndTopAdd;sectorAd=sectorAd+0x40000 ){
		SectorErase256kbQspiFlashS25fl512s(sectorAd);
		PutStr(".",0);
	}
	PutStr("Erase Completed ",1);
}


void SectorRdQspiFlashS25fl512s(uint32_t spiStatAdd,uint32_t distRamAdd)
{
	uint32_t	SectorStatTopAdd,readSize;
	unsigned char	*bufPtr;

//	char str[64];		//DEBUG

	SectorStatTopAdd = spiStatAdd & 0xFFFC0000;
	readSize  = 0x40000;
//	bufPtr    = (unsigned char*)distRamAdd;

//MON Debug
//				PutStr(" -------- SectorReadQspi1Flash --------  : ",1);	//********************* DEBUG
//				Data2HexAscii(spiStatAdd,str,4);							//********************* DEBUG
//				PutStr(" spiStatAdd        : ",0);							//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
//				Data2HexAscii(SectorStatTopAdd,str,4);						//********************* DEBUG
//				PutStr(" SectorStatTopAdd  : ",0);							//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
//				Data2HexAscii(distRamAdd,str,4);							//********************* DEBUG
//				PutStr(" distRamAdd            : ",0);						//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
///MON Debug

//	QuadRdQspiFlashS25fl512s(SectorStatTopAdd,bufPtr,readSize,1);
	FastRdQspiFlashS25fl512s(SectorStatTopAdd,distRamAdd,readSize);
//	QuadRdQspiFlashS25fl512s(SectorStatTopAdd,distRamAdd,readSize);
}
