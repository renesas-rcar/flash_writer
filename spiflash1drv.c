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
#include "bit.h"
#include "spiflash1drv.h"
#include "rpcqspidrv.h"
#include "dgtable.h"
#include "dgmodul4.h"

extern uint32_t gSelectQspiFlash;

//////////////////////////////////////////////////////////////////////////////////////
//
// QSPI SPI-FLASH  S25FS128S
//
//////////////////////////////////////////////////////////////////////////////////////
void FastRdQspiFlashS25s128s(uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	InitRPC_QspiFlash4FastReadExtMode();

	sourceAdd = SPI_IOADDRESS_TOP + sourceSpiAdd;

//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}

//////////////////////////////////
// Qspi:Fast Read  (FAST_READ 0Bh)
//////////////////////////////////
void FastRd3adQspiFlashS25s128s (uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	InitRPC_QspiFlashFastReadExtMode();

	sourceAdd = SPI_IOADDRESS_TOP + sourceSpiAdd;
//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}



void FastRdManuQspiFlashS25s128s(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount)
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

void QuadIORdManuQspiFlashS25s128s(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount)
{
	uint32_t		readAdd;
	uint32_t		rdData;
	
	rdData=destinationAdd;

	for(readAdd=sourceSpiAdd ; readAdd<(sourceSpiAdd+byteCount) ; readAdd+=4){
//		QuadFastReadQspiFlashData4Byte(readAdd, &rdData);
		QuadIOReadQspiFlashData4Byte(readAdd, &rdData);
		*((uint32_t *) destinationAdd) = rdData;
		destinationAdd +=4;
	}
}

//add 2016.01.19
//////////////////////////////////
// Qspi:Quad I/O Read   (Quad I/O Read EBh)
//////////////////////////////////
void QuadIORdQspiFlashS25s128s(uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount)
{
	uint32_t sourceAdd;

	EnableQuadModeQspiFlashS25fs128s();		//WriteAnyRegister

	InitRPC_ExtMode_QuadIORead();

	sourceAdd = SPI_IOADDRESS_TOP + sourceSpiAdd;
//	copy : spi_ioaddress (H'08000000)-> destinationAdd (H'60000000)
	mem_copy(destinationAdd, sourceAdd, byteCount);
}






//////////////////////////////////////////
// Qspi:Set SectorErase256kb mode (CR3V[1]=1   0:64kb 1:256kb)
//////////////////////////////////////////
void SetSectorErase256kbQspiFlashS25s128s(void)
{
	unsigned char readData;
	uint32_t status;
	uint32_t addr;

	char str[64];		//DEBUG

	addr = (uint32_t) SPIREG_CR3V;

// Read Any Register CR3V[1]
//	PutStr("=== READ :Read Any Register (RDAR 65h) =====",1);	//********************* DEBUG
	ReadAnyRegisterQspiFlash(addr,&readData);
//	Data2HexAscii(addr,str,4);									//********************* DEBUG
//	PutStr("RDAR        :H' ",0);			PutStr(str,1);		//********************* DEBUG
//	Data2HexAscii(readData,str,4);								//********************* DEBUG
//	PutStr("RDAR[CR3V]  :H' ",0);			PutStr(str,1);		//********************* DEBUG

	if(!(readData & BIT1)){
//		PutStr("256KB Erase mode set!",1);			//DEBUG Message
		WriteCommandQspiFlash(0x00060000);			//WRITE ENABLE
		readData |= BIT1;							// Bit1=Block Erase Size  1:256KB , 0:64KB
//		readData |= (BIT1|BIT3);					// Bit1=Block Erase Size  1:256KB , 0:64KB  , Bit3=4KB Erase 1:Disable , 0:Enable //Change 2015.07.24
// Write Any Register CR3V[1]
//		PutStr("=== SET: Write Any Register (WRAR 71h) =====",1);	//********************* DEBUG
		WriteAnyRegisterQspiFlash(addr,readData);

//Data2HexAscii(addr,str,4);								//********************* DEBUG
//PutStr("WRAR        :H' ",0);		PutStr(str,1);		//********************* DEBUG
//Data2HexAscii(readData,str,4);							//********************* DEBUG
//PutStr("WRAR[CR3V]  :H' ",0);		PutStr(str,1);		//********************* DEBUG

		while(1){
			ReadStatusQspiFlash(&status);
			if( !(status & BIT0) )	break;
		}
	}
// Read Any Register CR3V[1]
//	PutStr("=== READ :Read Any Register (RDAR 65h) =====",1);	//********************* DEBUG
//	ReadAnyRegisterQspiFlash(addr,&readData);
//	Data2HexAscii(addr,str,4);									//********************* DEBUG
//	PutStr("RDAR        :H' ",0);			PutStr(str,1);		//********************* DEBUG
//	Data2HexAscii(readData,str,4);								//********************* DEBUG
//	PutStr("RDAR[CR3V]  :H' ",0);			PutStr(str,1);		//********************* DEBUG
}



//////////////////////////////////////////
// Qspi:Sector Erase (256kB)	
//////////////////////////////////////////
//4SE DCh
void SectorErase256kbQspiFlashS25s128s(uint32_t addr)
{
	uint32_t status;
	char str[64];		//DEBUG

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	SectorErase4QspiFlash(addr);

	while(1){
		ReadStatusQspiFlash(&status);
//Data2HexAscii(status,str,4);				//********************* DEBUG
//PutStr("Read[RDSR1 05h]  :H' ",0);		//********************* DEBUG
//PutStr(str,1);							//********************* DEBUG
		if( (status & BIT5) ){				//Add 2015.07.23  //DEBUG===
			PutStr("Erase Error",0);		//DEBUG===
			break;							//DEBUG===
		}									//DEBUG===
		if( !(status & BIT0) )	break;
	}
}

//Add 2015.07.18
//SE D8h    
void SectorErase256kbQspiFlashS25s128s_D8(uint32_t addr)
{
	uint32_t status;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	SectorEraseQspiFlash(addr);

	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}



void ParameterSectorErase4kbQspiFlashS25s128s(uint32_t addr)
{
	uint32_t status;
	char str[64];		//DEBUG

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	ParameterSectorErase4QspiFlash(addr);

	while(1){
		ReadStatusQspiFlash(&status);
//Data2HexAscii(status,str,4);				//********************* DEBUG
//PutStr("Read[RDSR1 05h]  :H' ",0);		//********************* DEBUG
//PutStr(str,1);							//********************* DEBUG
		if( (status & BIT5) ){				//Add 2015.07.23
			PutStr("Erase Error",0);
			break;
		}
		if( !(status & BIT0) )	break;
	}
}





//////////////////////////////////////////
// Qspi:Bulk Erase (All)
//////////////////////////////////////////
int32_t BulkEraseQspiFlashS25s128s(void)
{
	uint32_t status;
	int32_t errFlag;

	errFlag = NORMAL_END;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteCommandQspiFlash(0x00600000);	//Bulk Erase (BE 60h)

	while(1){
		ReadStatusQspiFlash(&status);
		if( (status & BIT5) ){				//Add 2015.07.23  //DEBUG===
//			PutStr("Erase Error",0);		//DEBUG===
			errFlag=ERROR_END;
			break;							//DEBUG===
		}									//DEBUG===
		if( !(status & BIT0) )	break;		//BIT0  1:Device Busy  0:Ready Device is in Standby
	}
	return(errFlag);
}




void PageProgramQspiFlashS25s128s(uint32_t addr,uint32_t writeData)
{
//	uint32_t wrData,rdData,i,status,loopCount,dummyRd;
	uint32_t status;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4ppQspiFlash(addr, writeData);

//Add 2015.07.21
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}

void PageProgramQspiFlashS25s128s_CsCont(uint32_t addr, uint32_t *writeData,uint32_t byteCount)
{
	uint32_t loopCount;
	uint32_t status;

	loopCount = (byteCount>>2);

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
	WriteData4ppQspiFlash_CsCont(addr, writeData,loopCount);
//Add 2015.07.21
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}
}


void PageProgramWithBuffeQspiFlashS25s128s(uint32_t addr, uint32_t source_addr)
{
	uint32_t status;


	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE
//	WriteData4ppWithBufferQspiFlash(addr,source_addr);			//4PP
	WriteDataPpWithBufferQspiFlash(addr,source_addr);			//PP

//Add
	while(1){
		ReadStatusQspiFlash(&status);
		if( !(status & BIT0) )	break;
	}

}













void SaveDataQspiFlashS25s128s(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeData;

	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=4){
		writeData = *(volatile uint32_t*)srcAdd;
	    PageProgramQspiFlashS25s128s(flashAdd,writeData);
		srcAdd = srcAdd + 4;
	}

//	unsigned char *bufPtr;
//	unsigned long flashAdd;
//	bufPtr = (unsigned char*)srcAdd;
//	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){
//	    PageProgramQspiFlash(flashAdd,bufPtr,256,1);
//	    bufPtr = (unsigned char*)(bufPtr+256);
//	}
}
void SaveDataQspiFlashS25s128s_CsCont_Byte(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	unsigned char *bufPtr;
	uint32_t flashAdd;

	bufPtr = (unsigned char*)srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){
//	    PageProgramQspiFlash(flashAdd,bufPtr,256,1);
		PageProgramQspiFlashS25s128s_CsCont(flashAdd,(uint32_t *)bufPtr,256);
	    bufPtr = (unsigned char*)(bufPtr+256);
	}
}
void SaveDataQspiFlashS25s128s_CsCont(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
//	unsigned char *bufPtr;
	uint32_t *bufPtr;
	uint32_t flashAdd;

	bufPtr = (uint32_t*)srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){
//	    PageProgramQspiFlash(flashAdd,bufPtr,256,1);
		PageProgramQspiFlashS25s128s_CsCont(flashAdd,bufPtr,256);
	    bufPtr = (uint32_t*)(bufPtr+(256/4));
	}
}


void SaveDataWithBuffeQspiFlashS25s128s(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize)
{
	uint32_t flashAdd;
	uint32_t writeDataAdd;

	WriteCommandQspiFlash(0x00060000);	//WRITE ENABLE

	writeDataAdd = srcAdd;
	for(flashAdd=svFlashAdd;flashAdd<(svFlashAdd+svSize);flashAdd+=256){	//256byte:RPC Write Buffer size
		PageProgramWithBuffeQspiFlashS25s128s(flashAdd, writeDataAdd);
		writeDataAdd = writeDataAdd + 256;
	}
}





void SectorEraseQspiFlashS25s128s(uint32_t EraseStatAdd,uint32_t EraseEndAdd)
{
	uint32_t	sectorAd;
	uint32_t	SectorStatTopAdd,SectorEndTopAdd;

//	char str[64];		//DEBUG

	SectorStatTopAdd = EraseStatAdd & 0xFFFC0000;
	SectorEndTopAdd  = EraseEndAdd  & 0xFFFC0000;

//MON Debug
//				Data2HexAscii(SectorStatTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorStatTopAdd        : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
//				Data2HexAscii(SectorEndTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorEndTopAdd         : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
///MON Debug




//	if(gSelectQspiFlash ==ONBOARD_QSPI){
		SetSectorErase256kbQspiFlashS25s128s();
//	}

	for(sectorAd =SectorStatTopAdd;sectorAd<=SectorEndTopAdd;sectorAd=sectorAd+0x40000 ){
		SectorErase256kbQspiFlashS25s128s(sectorAd);
		PutStr(".",0);
	}
	PutStr("Erase Completed ",1);
}

void ParameterSectorEraseQspiFlashS25s128s(uint32_t EraseStatAdd,uint32_t EraseEndAdd)
{
	uint32_t	sectorAd;
	uint32_t	SectorStatTopAdd,SectorEndTopAdd;

	char str[64];		//DEBUG

	SectorStatTopAdd = EraseStatAdd & 0xFFFFF000;
	SectorEndTopAdd  = EraseEndAdd  & 0xFFFFF000;

//MON Debug
//				Data2HexAscii(SectorStatTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorStatTopAdd        : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
//				Data2HexAscii(SectorEndTopAdd,str,4);							//********************* DEBUG
//				PutStr(" SectorEndTopAdd         : ",0);						//********************* DEBUG
//				PutStr(str,1);													//********************* DEBUG
///MON Debug

	for(sectorAd =SectorStatTopAdd;sectorAd<=SectorEndTopAdd;sectorAd=sectorAd+0x1000 ){
//		SectorErase256kbQspiFlashS25s128s(sectorAd);
		ParameterSectorErase4kbQspiFlashS25s128s(sectorAd);
		PutStr(".",0);
//				Data2HexAscii(sectorAd,str,4);							//********************* DEBUG
//				PutStr(" EraseAd         : ",0);						//********************* DEBUG
//				PutStr(str,1);											//********************* DEBUG
	}
	PutStr("Erase Completed ",1);
}


void SectorRdQspiFlashS25s128s(uint32_t spiStatAdd,uint32_t distRamAdd)
{

	uint32_t	SectorStatTopAdd,readSize;
	unsigned char	*bufPtr;

	char str[64];		//DEBUG

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
//				PutStr(" distRamAdd        : ",0);							//********************* DEBUG
//				PutStr(str,1);												//********************* DEBUG
///MON Debug

//	QuadIORdQspiFlashS25s128s(SectorStatTopAdd,distRamAdd,readSize);	//add 2016.01.19
//	FastRdManuQspiFlashS25s128s(SectorStatTopAdd,distRamAdd,readSize);
//	FastRdQspiFlashS25s128s(SectorStatTopAdd,distRamAdd,readSize);
	FastRd3adQspiFlashS25s128s(SectorStatTopAdd,distRamAdd,readSize);
}













