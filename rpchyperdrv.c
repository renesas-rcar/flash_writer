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
#include "reg_rcarh3.h"
#include "bit.h"
#include "rpchyperdrv.h"


void InitRPC_HyperFlashExtMode(void)
{
		*((volatile uint32_t*)RPC_PHYCNT)     = 0x80070263;
		*((volatile uint32_t*)RPC_CMNCR)      = 0x01FFF301;
		*((volatile uint32_t*)RPC_DRCR)       = 0x001F0100;
		*((volatile uint32_t*)RPC_DRCMR)      = 0x00A00000;
		*((volatile uint32_t*)RPC_DRENR)      = 0xA222D400;
		*((volatile uint32_t*)RPC_DRDMCR)     = 0x0000000E;
		*((volatile uint32_t*)RPC_DRDRENR)    = 0x00005101;
		*((volatile uint32_t*)RPC_OFFSET1)= 0x21511144;
		*((volatile uint32_t*)RPC_PHYINT)    = 0x07070002;
			//bit18 RSTEN = 1 : RPC_RESET# pin is enabled
			//bit17 WPEN  = 1 : RPC_WP# pin is enabled
			//bit16 INTEN = 1 : RPC_INT# pin is enabled
			//bit2  RSTVAL= 0 : RPC_RESET# = H
			//bit1  WPVAL = 1 : RPC_WP# = L
			//bit0  INT   = 0 : Interrupt Status
}


void InitRPC_HyperFlash(void)
{
	PowerOnRPC();
	SetRPC_ClockMode(RPC_CLK_80M);
	ResetRPC();
	SetRPC_SSL_Delay();
}

uint32_t ReadHyperFlashData(uint32_t addr, uint32_t *readData, uint32_t byteCount)
{
	char str[64];		//DEBUG

	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030263;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash

	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF301;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 01 : QSPI Flash x 2 or HyperFlash

	*((volatile uint32_t*)RPC_SMCMR)      = 0x00800000;
		//bit23-21 CMD[7:5] = 100 : CA47-45 = 100 => Read/memory space/WrrapedBrst

	*((volatile uint32_t*)RPC_SMADR)      = (addr>>1);
		// ByteAddress(8bit) => WordAddress(16bit)

	*((volatile uint32_t*)RPC_SMOPR)      = 0x00000000;
		//                           CA15-3(Reserved) = all 0

	*((volatile uint32_t*)RPC_SMDMCR)     = 0x0000000E;
		//                           16 cycle dummy wait

	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00005101;
		//bit8 ADDRE  = 1 : Address DDR transfer
		//bit0 SPIDRE = 1 : DATA DDR transfer

	switch(byteCount){
		case 2:		// 2byte Read
			*((volatile uint32_t*)RPC_SMENR)      = 0xA222D408;
			//bit3-0   SPIDE[3:0] = 1000 : 16bit transfer
			break;
		case 4:		// 4byte Read
			*((volatile uint32_t*)RPC_SMENR)      = 0xA222D40C;
			//bit3-0   SPIDE[3:0] = 1100 : 32bit transfer
			break;
		case 8:		// 8byte Read
			*((volatile uint32_t*)RPC_SMENR)      = 0xA222D40F;
			//bit31-30 CDB[1:0]   =   10 : 4bit width command
			//bit25-24 ADB[1:0]   =   10 : 4bit width address
			//bit17-16 SPIDB[1:0] =   10 : 4bit width transfer data
			//bit15    DME        =    1 : dummy cycle enable
			//bit14    CDE        =    1 : Command enable
			//bit12    OCDE       =    1 : Option Command enable
			//bit11-8  ADE[3:0]   = 0100 : ADR[23:0] output (24 Bit Address)
			//bit7-4   OPDE[3:0]  = 0000 : Option data disable
			//bit3-0   SPIDE[3:0] = 1111 : 64bit transfer
			break;
	}

	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if(byteCount==8){
		readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	}

	readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]

/*
	Data2HexAscii(readData[0],str,4);
	PutStr(" RPC_SMRDR1 = 0x",0);
	PutStr(str,1);
	Data2HexAscii(readData[1],str,4);
	PutStr(" RPC_SMRDR0 = 0x",0);
	PutStr(str,1);
*/

	return(readData[0]);
}


void WriteCommandHyperFlash(uint32_t addr, uint32_t command)
{
	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030263;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash

	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF301;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 01 : QSPI Flash x 2 or HyperFlash

	*((volatile uint32_t*)RPC_SMCMR)      = 0x00000000;
		//bit23-21 CMD[7:5] = 000 : CA47-45 = 000 => Write/memory space/WrrapedBrst

	*((volatile uint32_t*)RPC_SMADR)      = addr;
	*((volatile uint32_t*)RPC_SMOPR)      = 0x00000000;
		//                           CA15-3(Reserved) = all 0
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x0000000E;
		//                           16 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00005101;
		//bit14-12 HYPE =101:Hyperflash mode
		//bit8 ADDRE  = 1 : Address DDR transfer
		//bit0 SPIDRE = 1 : DATA DDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0xA2225408;
		//bit31-30 CDB[1:0]   =   10 : 4bit width command
		//bit25-24 ADB[1:0]   =   10 : 4bit width address
		//bit17-16 SPIDB[1:0] =   10 : 4bit width transfer data
		//bit15    DME        =    0 : dummy cycle disable
		//bit14    CDE        =    1 : Command enable
		//bit12    OCDE       =    1 : Option Command enable
		//bit11-8  ADE[3:0]   = 0100 : ADR[23:0] output (24 Bit Address)
		//bit7-4   OPDE[3:0]  = 0000 : Option data disable
		//bit3-0   SPIDE[3:0] = 1000 : 16bit transfer

	*((volatile uint32_t*)RPC_SMWDR0)     = command;
		//
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();
}

void WriteDataHyperFlash(uint32_t addr, uint32_t writeData)
{
	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030263;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash

	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF301;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 01 : QSPI Flash x 2 or HyperFlash

	*((volatile uint32_t*)RPC_SMCMR)      = 0x00000000;
		//bit23-21 CMD[7:5] = 000 : CA47-45 = 000 => Write/memory space/WrrapedBrst
	*((volatile uint32_t*)RPC_SMADR)      = (addr>>1);
		// ByteAddress(8bit) => WordAddress(16bit)

	*((volatile uint32_t*)RPC_SMOPR)      = 0x00000000;
		//                           CA15-3(Reserved) = all 0
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x0000000E;
		//                           16 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00005101;
		//bit8 ADDRE  = 1 : Address DDR transfer
		//bit0 SPIDRE = 1 : DATA DDR transfer

	*((volatile uint32_t*)RPC_SMENR)      = 0xA222540C;
			//bit3-0   SPIDE[3:0] = 1100 : 32bit transfer

	*((volatile uint16_t*)RPC_SMWDR0)     = writeData;

	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start
	WaitRpcTxEnd();
}









void WriteProtectDisable(void)
{
	uint32_t dataL = 0;
	
	dataL = *((volatile uint32_t*)RPC_PHYINT);
	
	if(dataL & BIT1)
	{	//bit1:  WPVAL(0:RPC_WP#=H(Protect Disable), 1:RPC_WP#=L(Protect Enable))
		dataL &= ~BIT1;
		*((volatile uint32_t*)RPC_PHYINT) = dataL;
	}
}

//////////////////////////////////////////////////////////////////////////////////
//																				//
//	for HyperFlash																//
//																				//
//////////////////////////////////////////////////////////////////////////////////
uint32_t ReadHyperFlashData8Byte(uint32_t addr, uint32_t *readData)	//for HyperFlash
{
	char str[64];
	
	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030263;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF301;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 01 : QSPI Flash x 2 or HyperFlash
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00800000;
		//bit23-21 CMD[7:5] = 100 : CA47-45 = 100 => Read/memory space/WrrapedBrst
	*((volatile uint32_t*)RPC_SMADR)      = addr/2;
	*((volatile uint32_t*)RPC_SMOPR)      = 0x00000000;
		//                           CA15-3(Reserved) = all 0
	*((volatile uint32_t*)RPC_SMDMCR)     = 0x0000000E;
		//                           16 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00005101;
		//bit8 ADDRE  = 1 : Address DDR transfer
		//bit0 SPIDRE = 1 : DATA DDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0xA222D40F;
		//bit31-30 CDB[1:0]   =   10 : 4bit width command
		//bit25-24 ADB[1:0]   =   10 : 4bit width address
		//bit17-16 SPIDB[1:0] =   10 : 4bit width transfer data
		//bit15    DME        =    1 : dummy cycle enable
		//bit14    CDE        =    1 : Command enable
		//bit12    OCDE       =    1 : Option Command enable
		//bit11-8  ADE[3:0]   = 0100 : ADR[23:0] output (24 Bit Address)
		//bit7-4   OPDE[3:0]  = 0000 : Option data disable
		//bit3-0   SPIDE[3:0] = 1111 : 64bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start
	
//	WaitTxEnd();
	WaitRpcTxEnd();
	
	readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]

/*
	Data2HexAscii(readData[0],str,4);
	PutStr(" RPC_SMRDR1 = 0x",0);
	PutStr(str,1);
	Data2HexAscii(readData[1],str,4);
	PutStr(" RPC_SMRDR0 = 0x",0);
	PutStr(str,1);
*/
	
	return(readData[0]);
}


uint32_t ReadStatusHyperFlash(uint32_t *readData)	//for HyperFlash
{
	uint32_t addr = 0;
	uint32_t command = 0;
	uint32_t read_status = 0;
	uint32_t status = 0;
	
	//First Command
	addr = 0x00000555;
	command = 0x70000000;
	WriteCommandHyperFlash(addr, command);
	
	read_status = ReadHyperFlashData8Byte(0x0, readData);	// Status Register read
	
	status = ((read_status & 0xFF000000) >> 8 ) | ((read_status & 0x00FF0000) << 8 ) | ((read_status & 0x0000FF00) >> 8 ) | ((read_status & 0x000000FF) << 8 );
	
	status = (status & 0x0000FFFF);
	
	return(status);
}


void WriteDataWithBufferHyperFlash(uint32_t addr, uint32_t source_addr)	//for HyperFlash
{
	//uint32_t i=0;
	uintptr_t i=0;
	
	*((volatile uint32_t*)RPC_DRCR)       = 0x01FF0301;
		//bit9   RCF         =  1 : Read Cache Clear
	
	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030277;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	
	for(i=0;i<256;i=i+0x4)
	{
		(*(volatile uint32_t*)(0xEE208000+i)) = (*(volatile uint32_t*)(source_addr+i));
	}
//	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030277;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF301;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 01 : QSPI Flash x 2 or HyperFlash
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00000000;
		//bit23-21 CMD[7:5] = 000 : CA47-45 = 000 => Write/memory space/WrrapedBrst
	*((volatile uint32_t*)RPC_SMADR)      = addr;
	*((volatile uint32_t*)RPC_SMOPR)      = 0x00000000;
		//                           CA15-3(Reserved) = all 0
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000007;
		//                           16 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00005101;
		//bit8 ADDRE  = 1 : Address DDR transfer
		//bit0 SPIDRE = 1 : DATA DDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0xA222540F;
		//bit31-30 CDB[1:0]   =   10 : 4bit width command
		//bit25-24 ADB[1:0]   =   10 : 4bit width address
		//bit17-16 SPIDB[1:0] =   10 : 4bit width transfer data
		//bit15    DME        =    0 : dummy cycle disable
		//bit14    CDE        =    1 : Command enable
		//bit12    OCDE       =    1 : Option Command enable
		//bit11-8  ADE[3:0]   = 0100 : ADR[23:0] output (24 Bit Address)
		//bit7-4   OPDE[3:0]  = 0000 : Option data disable
		//bit3-0   SPIDE[3:0] = 1111 : 64bit transfer
	
//	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
		//
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start
	
	WaitRpcTxEnd();
	
	*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	*((volatile uint32_t*)RPC_DRCR)       = 0x01FF0301;
		//bit9   RCF         =  1 : Read Cache Clear
}


void WriteBufferOperationHyperFlash(uint32_t writeAddr, uint32_t source_addr)
{
	//Word Program
	uint32_t addr = 0;
	uint32_t command = 0;
	
	//First Command
	addr = 0x00000555;
	command = 0xAA000000;
	WriteCommandHyperFlash(addr, command);
	
	//Second Command
	addr = 0x000002AA;
	command = 0x55000000;
	WriteCommandHyperFlash(addr, command);
	
	//Third Command
	addr = 0x00000555;
	command = 0xA0000000;
	WriteCommandHyperFlash(addr, command);
	
	//Fourth Command
	addr = (writeAddr/2);
	WriteDataWithBufferHyperFlash(addr, source_addr);
}