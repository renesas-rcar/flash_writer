/*
 * Copyright (c) 2015-2019, Renesas Electronics Corporation
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
#include "cpudrv.h"


void InitRPC_QspiFlashQuadExtMode(void)
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
		*((volatile uint32_t*)RPC_CMNCR)      = 0x01FFF300;
		*((volatile uint32_t*)RPC_DRCR)       = 0x001F0100;
			//bit20-16 RBURST[4:0] = 11111 : 32 continuous data unit
			//bit8     RBE         =     1 : Burst read
		*((volatile uint32_t*)RPC_DRCMR)      = 0x006C0000;
			//bit23-16 CMD[7:0] = 0x6C : Quad Output Read 4-byte address command

		*((volatile uint32_t*)RPC_DREAR)      = 0x00000001;
			//bit23-16 EAV[7:0]   = 0    : ADR[32:26] output set0
			//bit2-0   EAC[2:0]   = 001  : ADR[25:0 ] Enable

		*((volatile uint32_t*)RPC_DRENR)      = 0x0002CF00;
			//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
			//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
			//bit17-16 DRDB[1:0]  =   10 : 4bit width transfer data (QSPI0_IO0-3)
			//bit15    DME        =    1 : dummy cycle enable
			//bit14    CDE        =    1 : Command enable
			//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
		*((volatile uint32_t*)RPC_DRDMCR)     = 0x00000007;
			//bit2-0 DMCYC[2:0]   = 111 : 8 cycle dummy wait
		*((volatile uint32_t*)RPC_DRDRENR)    = 0x00000000;
			//bit8 ADDRE  = 0 : Address SDR transfer
			//bit0 DRDRE  = 0 : DATA SDR transfer
}
void InitRPC_QspiFlash4FastReadExtMode(void)
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
		*((volatile uint32_t*)RPC_CMNCR)      = 0x01FFF300;
		*((volatile uint32_t*)RPC_DRCR)       = 0x001F0100;
			//bit20-16 RBURST[4:0] = 11111 : 32 continuous data unit
			//bit8     RBE         =     1 : Burst read
		*((volatile uint32_t*)RPC_DRCMR)      = 0x000C0000;
			//bit23-16 CMD[7:0] = 0x0C : 4FAST_READ 0Ch Command 4-byte address command

		*((volatile uint32_t*)RPC_DREAR)      = 0x00000001;
			//bit23-16 EAV[7:0]   = 0    : ADR[32:26] output set0
			//bit2-0   EAC[2:0]   = 001  : ADR[25:0 ] Enable

		*((volatile uint32_t*)RPC_DRENR)      = 0x0000CF00;
			//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
			//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
			//bit17-16 DRDB[1:0]  =   00 : 1bit width transfer data (QSPI0_IO0)
			//bit15    DME        =    1 : dummy cycle enable
			//bit14    CDE        =    1 : Command enable
			//bit11-8  ADE[3:0]   = 1111 : ADR[23:0] output (24 Bit Address)
		*((volatile uint32_t*)RPC_DRDMCR)     = 0x00000007;
			//bit2-0 DMCYC[2:0]   = 111 : 8 cycle dummy wait
		*((volatile uint32_t*)RPC_DRDRENR)    = 0x00000000;
			//bit8 ADDRE  = 0 : Address SDR transfer
			//bit0 DRDRE  = 0 : DATA SDR transfer
}


void InitRPC_QspiFlash(void)
{
	PowerOnRPC();

	SetRPC_ClockMode(RPC_CLK_80M);
	ResetRPC();
	SetRPC_SSL_Delay();

	*((volatile uint32_t*)RPC_OFFSET1)= 0x31511144;
}

void InitRPC_QspiFlashBoard(void)
{
	PowerOnRPC();
	SetRPC_ClockMode(RPC_CLK_40M);
	ResetRPC();
	SetRPC_SSL_Delay();

	*((volatile uint32_t*)RPC_OFFSET1)= 0x31511144;
}


void ReadConfigRegQspiFlash(uint32_t *cnfigReg)
{
	uint8_t readData;
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

//  Manual mode / No dummy / On Command / No Address /  Data:8bit transfer

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00350000;
		//bit23-16 CMD[7:0] = 0x35 : Read Configuration Register (CFG)

	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004008;
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : Address output disable
		//bit3-0   SPIDE[3:0] = 1000 : 8bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	readData    = *((volatile uint8_t*)RPC_SMRDR0);	//read data[7:0]
	*cnfigReg  = readData;
}


void WriteRegisterQspiFlash(uint32_t statusReg, uint32_t configReg)
{
	uint16_t writeData;
	uint32_t product;
	uint32_t cut;

//	writeData  = ( (configReg<<8) | statusReg ) );
	writeData  = ( (configReg<<8) & 0x0000FF00 );
	writeData |= (  statusReg     & 0x000000FF );

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00010000;
		//bit23-16 CMD[7:0] = 0x01 : Write (Status & Configuration) Register
//	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000400C;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : ADR[23:0] is disable
		//bit3-0   SPIDE[3:0] = 1100 : 16bit transfer
	*((volatile uint16_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030270;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038270;
	}
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

}
void WriteRegisterQspiFlash_Byte2(uint32_t statusReg, uint32_t configReg)
{
	uint32_t loopf,dataL;
	unsigned char writeStatusData,writeConfigData;
	uint32_t product;
	uint32_t cut;

//	writeData  = ( (configReg<<8) & 0x0000FF00 );
//	writeData |= (  statusReg     & 0x000000FF );

	writeStatusData  = (volatile unsigned char)statusReg;
	writeConfigData  = (volatile unsigned char)configReg;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00010000;
		//bit23-16 CMD[7:0] = 0x01 : Write (Status & Configuration) Register
//	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004008;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : ADR[23:0] is disable
		//bit3-0   SPIDE[3:0] = 1000 : 8bit transfer

//First ByteData
	*((volatile unsigned char*)RPC_SMWDR0) = writeStatusData;
	*((volatile uint32_t*)RPC_SMCR)        = 0x00000103;
		//bit8     SSLKP      = 1 : SSL After the transfer assert continue
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start
	WaitRpcTxEnd();

//Second ByteData
	*((volatile uint32_t*)RPC_SMENR)       = 0x00000008;
	*((volatile unsigned char*)RPC_SMWDR0) = writeConfigData;
	*((volatile uint32_t*)RPC_SMCR)        = 0x00000003;
		//bit8     SSLKP      = 0 : SSL After the transfer negated
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start
	WaitRpcTxEnd();

	loopf=1;
	//*((volatile uint32_t*)RPC_SMCR) = 0x00000000;
	while(loopf){
		dataL = *((volatile uint32_t*)RPC_CMNSR);
		if( !(dataL & BIT1) )	loopf=0;
	}

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030270;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038270;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear
}


//4SE DCh 4-byte address
void SectorErase4QspiFlash(uint32_t sector_addr)
{
	char str[64];
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00DC0000;
		//bit23-16 CMD[7:0] = 0xDC : Sector Erase 4-byte address command
	*((volatile uint32_t*)RPC_SMADR)      = sector_addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004F00;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
		//bit3-0   SPIDE[3:0] = 0000 : No transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000001;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();
}

//4P4E 21h 4-byte address
void ParameterSectorErase4QspiFlash(uint32_t sector_addr)
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00210000;
		//bit23-16 CMD[7:0] = 0x21 : Parameter 4-kB Sector Erasecommand
	*((volatile uint32_t*)RPC_SMADR)      = sector_addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004F00;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
		//bit3-0   SPIDE[3:0] = 0000 : No transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000001;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();
}


//Page Program (4PP:12h)  4-byte address
void WriteData4ppWithBufferQspiFlash(uint32_t addr, uint32_t source_addr)
{
	uintptr_t i=0;
	uint32_t product;
	uint32_t cut;

	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}

	for(i=0;i<256;i=i+0x4)
	{
		(*(volatile uint32_t*)(0xEE208000+i)) = (*(volatile uint32_t*)(source_addr+i));
	}

//	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00120000;
		//bit23-16 CMD[7:0] = 0x12 : Page Program 4-byte address
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004F0F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[23:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
//	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear
}


//Page Program (PP:02h)  3-byte address
//Add 2015.07.23
void WriteDataPpWithBufferQspiFlash(uint32_t addr, uint32_t source_addr)
{
	//uint32_t i=0;
	uintptr_t i=0;
	uint32_t product;
	uint32_t cut;

	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}

	for(i=0;i<256;i=i+0x4)
	{
		(*(volatile uint32_t*)(0xEE208000+i)) = (*(volatile uint32_t*)(source_addr+i));
	}

//	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00020000;
		//bit23-16 CMD[7:0] = 0x02 : Page Program 3-byte address
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000470F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
//		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] is output
		//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
//	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear
}


//Page Program (4PP:12h)  4-byte address
void WriteData4ppQspiFlash(uint32_t addr, uint32_t writeData)
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00120000;
		//bit23-16 CMD[7:0] = 0x12 : Page Program 4-byte address 
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004F0F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

}

//void WriteData4ppQspiFlash    (uint32_t addr, uint32_t writeData)
void WriteData4ppQspiFlash_CsCont(uint32_t addr, uint32_t *writeData,uint32_t cnt)
{
	uint32_t i,loopf,dataL;
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00120000;
		//bit23-16 CMD[7:0] = 0x12 : Page Program 4-byte address 
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004F0F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
//	*((volatile uint32_t*)RPC_SMWDR0)     = *writeData;
	*((volatile uint32_t*)RPC_SMWDR0)     = *((volatile uint32_t*)writeData);
	if(cnt==1){
		*((volatile uint32_t*)RPC_SMCR)   = 0x00000003;
				//bit8     SSLKP      = 0 : SSL After the transfer negated
				//bit2     SPIRE      = 0 : Data read disable
				//bit1     SPIWE      = 1 : Data write disable
				//bit0     SPIE       = 1 : SPI transfer start
	}else{
		*((volatile uint32_t*)RPC_SMCR)   = 0x00000103;
				//bit8     SSLKP      = 1 : SSL After the transfer assert continue
				//bit2     SPIRE      = 0 : Data read disable
				//bit1     SPIWE      = 1 : Data write disable
				//bit0     SPIE       = 1 : SPI transfer start
	}
	WaitRpcTxEnd();
	writeData++;
//	writeData+=4;
	if(cnt!=1){
		*((volatile uint32_t*)RPC_SMENR)        = 0x0000000F;
		for(i=1;i<cnt;i++){
			*((volatile uint32_t*)RPC_SMWDR0)   = *writeData;
			if(i==(cnt-1)){
				*((volatile uint32_t*)RPC_SMCR) = 0x00000003;
			}else{
				*((volatile uint32_t*)RPC_SMCR) = 0x00000103;
			}
			WaitRpcTxEnd();
			writeData++;
//			writeData+=4;
		}
	}

	loopf=1;
	//*((volatile uint32_t*)RPC_SMCR) = 0x00000000;
	while(loopf){
		dataL = *((volatile uint32_t*)RPC_CMNSR);
		if( !(dataL & BIT1) )	loopf=0;
	}

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear
}

//Quad Page Program (4QPP:34h)  4-byte address
void WriteData4qppQspiFlash(uint32_t addr, uint32_t writeData)
{
//	char str[64];

	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00340000;
		//bit23-16 CMD[7:0] = 0x34 : Quad Page Program 4-byte address
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00024F0F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   10 : 4bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

}



uint32_t SingleFastReadQspiFlashData4Byte(uint32_t addr, uint32_t *readData)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x000C0000;
		//bit23-16 CMD[7:0] = 0x0C : Fast Read command (4FAST_READ 0Ch)
	*((volatile uint32_t*)RPC_SMADR)      = addr;
	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000007;
		//bit2-0 DMCYC[2:0] = 111 : 8 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000CF0F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    1 : dummy cycle enable
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	//readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	//readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]
	readData[0] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[31:0]

	return(readData[0]);
}

uint32_t SingleFastReadQspiFlashData1Byte(uint32_t addr, uint32_t *readData)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x000C0000;
		//bit23-16 CMD[7:0] = 0x0C : Fast Read command (4FAST_READ 0Ch)
	*((volatile uint32_t*)RPC_SMADR)      = addr;
	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000007;
		//bit2-0 DMCYC[2:0] = 111 : 8 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000CF08;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    1 : dummy cycle enable
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
		//bit3-0   SPIDE[3:0] = 1000 : 8bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	//readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	//readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]
	*readData   = *((volatile unsigned char*)RPC_SMRDR0);	//read data[7:0]

//	return(readData[0]);
}






//OnBoard QspiFlash(S25FS128S)
//65h Read Any Register command (RADR 65h)
uint32_t ReadAnyRegisterQspiFlash(uint32_t addr, unsigned char *readData)		// Add24bit,Data8bit
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00650000;
		//bit23-16 CMD[7:0] = 0x65 :        Read Any Register command (RADR 65h)
	*((volatile uint32_t*)RPC_SMADR)      = addr;
	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000007;
		//bit2-0 DMCYC[2:0] = 111 : 8 cycle dummy wait
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000C708;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    1 : dummy cycle enable
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] output (24 Bit Address)
		//bit3-0   SPIDE[3:0] = 1000 : 8bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

//	readData[0] = *((volatile unsigned char*)RPC_SMRDR0);	//read data[31:0]
	*readData   = *((volatile unsigned char*)RPC_SMRDR0);	//read data[7:0]

//	return(readData[0]);
}


//OnBoard QspiFlash(S25FS128S)
//71h Write Any Register command (WRAR 71h)
void WriteAnyRegisterQspiFlash(uint32_t addr, unsigned char writeData)			// Add24bit,Data8bit
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00710000;
		//bit23-16 CMD[7:0] = 0x71 : Write Any Register Command  (WRAR)
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004708;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0111 : ADR[24:0] is output
		//bit3-0   SPIDE[3:0] = 1000 : 8bit transfer
	*((volatile unsigned char*)RPC_SMWDR0)= writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

}




//Add 2015.07.23
//OnBoard QspiFlash(S25FS128S)		//FAST_READ 0Bh (CR2V[7]=0) is followed by a 3-byte address
void InitRPC_QspiFlashFastReadExtMode(void)
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
	}
		*((volatile uint32_t*)RPC_CMNCR)      = 0x01FFF300;
		*((volatile uint32_t*)RPC_DRCR)       = 0x001F0100;
			//bit20-16 RBURST[4:0] = 11111 : 32 continuous data unit
			//bit8     RBE         =     1 : Burst read
		*((volatile uint32_t*)RPC_DRCMR)      = 0x000B0000;
			//bit23-16 CMD[7:0] = 0x0B : FAST_READ 0Bh

		*((volatile uint32_t*)RPC_DREAR)      = 0x00000000;
			//bit23-16 EAV[7:0]   = 0    : ADR[32:25] output set0
			//bit2-0   EAC[2:0]   = 000  : ADR[24:0 ] Enable

		*((volatile uint32_t*)RPC_DROPR)      = 0x00000000;
			//bit31-24 OPD3[7:0]  = H'0  : Option Data 3 (Set Mode)

//		*((volatile uint32_t*)RPC_DRENR)      = 0x0202CF00;	//4bit width address,4bit width transfer data, ADR[31:0] output
		*((volatile uint32_t*)RPC_DRENR)      = 0x0000C700;	//
			//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
//			//bit25-24 ADB[1:0]   =   10 : 4bit width address (QSPI0_MOSI)
			//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
//			//bit17-16 DRDB[1:0]  =   10 : 4bit width transfer data (QSPI0_IO0-3)
			//bit17-16 DRDB[1:0]  =   00 : 1bit width transfer data (QSPI0_IO0-3)
			//bit15    DME        =    1 : dummy cycle enable
			//bit14    CDE        =    1 : Command enable
//			//bit11-8  ADE[3:0]   = 1111 : ADR[31:0] output (32 Bit Address)
			//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] output (24 Bit Address)
//		*((volatile uint32_t*)RPC_DRDMCR)     = 0x00020003;		//DMCYC[2:0] =4 bit, 4 cycle dummy
		*((volatile uint32_t*)RPC_DRDMCR)     = 0x00000007;		//8 cycle dummy
			//bit17-16 DMCYC[2:0] =  10 : 4 bit width
			//bit2-0 DMCYC[2:0]   = 111 : 8 cycle dummy wait
			//bit2-0 DMCYC[2:0]   = 011 : 4 cycle dummy wait
		*((volatile uint32_t*)RPC_DRDRENR)    = 0x00000000;
			//bit8 ADDRE  = 0 : Address SDR transfer
			//bit0 DRDRE  = 0 : DATA SDR transfer
}





void SetRPC_ClockMode(uint32_t mode)
{
	uint32_t dataL=0;

#ifdef RCAR_GEN3_SALVATOR
	if(mode == RPC_CLK_160M){
		dataL = 0x00000011;	/* RPC clock 160MHz */
	}else if(mode == RPC_CLK_80M){
		dataL = 0x00000013;	/* RPC clock 80MHz */
	}else{
		dataL = 0x00000017;	/* RPC clock 40MHz */
	}
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
	if(mode == RPC_CLK_160M){
		dataL = 0x00000011;	/* RPC clock 160MHz */
	}else if(mode == RPC_CLK_80M){
		dataL = 0x00000001;	/* RPC clock 80MHz */
	}else{
		dataL = 0x00000003;	/* RPC clock 40MHz */
	}
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	if(mode == RPC_CLK_160M){
		dataL = 0x00000011;	/* RPC clock 160MHz */
	}else if(mode == RPC_CLK_80M){
		dataL = 0x00000001;	/* RPC clock 80MHz */
	}else{
		dataL = 0x00000003;	/* RPC clock 40MHz */
	}
#endif /* RCAR_GEN3_DRAAK */

	*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
	*((volatile uint32_t*)CPG_RPCCKCR)  =  dataL;

	SoftDelay(50000);
}


//void WaitTxEnd(void)
void WaitRpcTxEnd(void)
{
	uint32_t dataL=0;

	while(1)
	{
		dataL = *((volatile uint32_t*)RPC_CMNSR);
		if(dataL & BIT0)	break;
		// Wait for TEND = 1
	}
}








void ResetRPC(void)
{
	*((volatile uint32_t*)CPG_CPGWPR) = ~BIT17;
	*((volatile uint32_t*)CPG_SRCR9)  =  BIT17;
	//wait: tRLRH Reset# low pulse width 10us
	StartTMU0usec(2);							// wait 20us

	*((volatile uint32_t*)CPG_CPGWPR)   = ~BIT17;
	*((volatile uint32_t*)CPG_SRSTCLR9) =  BIT17;
	//wait: tREADY1(35us) - tRHSL(10us) = 25us
	StartTMU0usec(4);							// wait 40us
}





//Add 2016.03.24
void SetRPC_SSL_Delay(void)
{
	*((volatile uint32_t*)RPC_SSLDR) = 0x00000400;
		//bit10-8  SLNDL[2:0] =  100 : 5.5 cycles of QSPIn_SPCLK 
}





void PowerOnRPC(void)
{
	uint32_t dataL=0;

	dataL = *((volatile uint32_t*)CPG_MSTPSR9);
	if(dataL & BIT17){	// case RPC(QSPI) Standby
		dataL &= ~BIT17;
		*((volatile uint32_t*)CPG_CPGWPR)    = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR9)  =  dataL;
		while( BIT17 & *((volatile uint32_t*)CPG_MSTPSR9) );  // wait bit=0
	}
}


uint32_t ReadQspiFlashID(uint32_t *readData)	//for QSPIx1ch
{
	char str[64];
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x009F0000;
		//bit23-16 CMD[7:0] = 0x9F : Read ID command (for Palladium QSPI model)
//	*((volatile uint32_t*)RPC_SMADR)      = 0x00000000;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000400F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : Address output disable
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	//readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	//readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]
	readData[0] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[31:0]
///*
//	PutStr("",1);
//	Data2HexAscii(readData[0],str,4);
//	PutStr(" RPC_SMRDR0 = 0x",0);
//	PutStr(str,1);
//	Data2HexAscii(readData[1],str,4);
//	PutStr(" RPC_SMRDR0 = 0x",0);
//	PutStr(str,1);
//*/
	return(readData[0]);
}

uint32_t ReadStatusQspiFlash(uint32_t *readData)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00050000;
		//bit23-16 CMD[7:0] = 0x05 : Status Read command (for Palladium QSPI model)
//	*((volatile uint32_t*)RPC_SMADR)      = 0x00000000;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000400F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : Address output disable
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000005;
		//bit2     SPIRE      = 1 : Data read enable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	//readData[1] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[63:32]
	//readData[0] = *((volatile uint32_t*)RPC_SMRDR1);	//read data[31:0]
	readData[0] = *((volatile uint32_t*)RPC_SMRDR0);	//read data[31:0]

	return(readData[0]);
}



void WriteCommandQspiFlash(uint32_t command)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = command;
		//bit23-16 CMD[7:0] : command
//	*((volatile uint32_t*)RPC_SMADR)      = 0x00000000;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004000;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0000 : Address output disable
		//bit3-0   SPIDE[3:0] = 0000 : No transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000001;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

}


void WriteDataWithBufferQspiFlash(uint32_t addr, uint32_t source_addr)	//for QSPIx1ch
{
	uintptr_t i=0;
	uint32_t product;
	uint32_t cut;

	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}

	for(i=0;i<256;i=i+0x4)
	{
		(*(volatile uint32_t*)(0xEE208000+i)) = (*(volatile uint32_t*)(source_addr+i));
	}

//	*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030274;
		//bit31  CAL         =  1 : PHY calibration
		//bit2   WBUF        =  1 : Write Buffer Enable
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00020000;
		//bit23-16 CMD[7:0] = 0x02 : Write command (for Palladium QSPI model)
	*((volatile uint32_t*)RPC_SMADR)      = addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x0000470F;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] is output
		//bit3-0   SPIDE[3:0] = 1111 : 32bit transfer
//	*((volatile uint32_t*)RPC_SMWDR0)     = writeData;
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000003;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 1 : Data write enable
		//bit0     SPIE       = 1 : SPI transfer start

	WaitRpcTxEnd();

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030273;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038273;
		//bit31  CAL         =  0 : No PHY calibration
		//bit2   WBUF        =  0 : Write Buffer Disable
		//bit1-0 PHYMEM[1:0] = 11 : HyperFlash
	}
	*((volatile uint32_t*)RPC_DRCR)       = 0x011F0301;
		//bit9   RCF         =  1 : Read Cache Clear
}

//SE D8h  3-byte address
void SectorEraseQspiFlash(uint32_t sector_addr)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x81FFF300;
		//bit31  MD       =  1 : Manual mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_SMCMR)      = 0x00D80000;
		//bit23-16 CMD[7:0] = 0xD8 : Sector Erase command (for Palladium QSPI model)
	*((volatile uint32_t*)RPC_SMADR)      = sector_addr;
//	*((volatile uint32_t*)RPC_SMDMCR)     = 0x00000006;
	*((volatile uint32_t*)RPC_SMDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 SPIDRE = 0 : DATA SDR transfer
	*((volatile uint32_t*)RPC_SMENR)      = 0x00004700;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   00 : 1bit width address (QSPI0_MOSI)
		//bit17-16 SPIDB[1:0] =   00 : 1bit width transfer data (QSPI0_MISO)
		//bit15    DME        =    0 : No dummy cycle
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] output (24 Bit Address)
		//bit3-0   SPIDE[3:0] = 0000 : No transfer
	*((volatile uint32_t*)RPC_SMCR)       = 0x00000001;
		//bit2     SPIRE      = 0 : Data read disable
		//bit1     SPIWE      = 0 : Data write disable
		//bit0     SPIE       = 1 : SPI transfer start

//	WaitTxEnd();
	WaitRpcTxEnd();
}



//Add 2015.09.30
void InitRPC_ExtMode_QuadIORead(void)	//for QSPIx1ch
{
	uint32_t product;
	uint32_t cut;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	cut = *((volatile uint32_t*)PRR) & PRR_CUT_MASK;

	if ((product ==  PRR_PRODUCT_M3) && (cut < PRR_CUT_30)) {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00030260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80030260;
	} else {
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x00038260;
		*((volatile uint32_t*)RPC_PHYCNT)    = 0x80038260;
		//bit31  CAL         =  1 : PHY calibration
		//bit1-0 PHYMEM[1:0] = 00 : QSPI-SDR
	}
	*((volatile uint32_t*)RPC_CMNCR)      = 0x01FFF300;
		//bit31  MD       =  0 : External address space read mode
		//bit1-0 BSZ[1:0] = 00 : QSPI Flash x 1
	*((volatile uint32_t*)RPC_DRCR)       = 0x001F0100;
		//bit20-16 RBURST[4:0] = 11111 : 32 continuous data unit
		//bit8     RBE         =     1 : Burst read
	*((volatile uint32_t*)RPC_DRCMR)      = 0x00EB0000;
		//bit23-16 CMD[7:0] = 0xEB : Quad I/O Read command
	*((volatile uint32_t*)RPC_DRENR)      = 0x0202C700;
		//bit31-30 CDB[1:0]   =   00 : 1bit width command (QSPI0_MOSI)
		//bit25-24 ADB[1:0]   =   10 : 4bit width address (QSPI0_IO0-3)
		//bit17-16 DRDB[1:0]  =   10 : 4bit width transfer data (QSPI0_IO0-3)
		//bit15    DME        =    1 : dummy cycle enable
		//bit14    CDE        =    1 : Command enable
		//bit11-8  ADE[3:0]   = 0111 : ADR[23:0] output (24 Bit Address)
//	*((volatile uint32_t*)RPC_DRDMCR)     = 0x00020005;
	*((volatile uint32_t*)RPC_DRDMCR)     = 0x00020009;
		//bit17-16 DMCYC[2:0] =   10 : 4 bit width
		//bit3-0 DMCYC[3:0]   = 0001 : 2 cycle dummy wait
		//bit3-0 DMCYC[3:0]   = 0011 : 4 cycle dummy wait
		//bit3-0 DMCYC[3:0]   = 0101 : 6 cycle dummy wait(mode bit:2 cycle + 4 cycle dummy)	<= S25FL512(on QSPI Board)
		//bit3-0 DMCYC[3:0]   = 0111 : 8 cycle dummy wait
		//bit3-0 DMCYC[3:0]   = 1001 :10 cycle dummy wait(mode bit:2 cycle + 8 cycle dummy)	<= S25FS128(on Salvator)
	*((volatile uint32_t*)RPC_DRDRENR)    = 0x00000000;
		//bit8 ADDRE  = 0 : Address SDR transfer
		//bit0 DRDRE  = 0 : DATA SDR transfer
}

//////////////////////////////////////////
// Qspi:Enable QUAD mode (CR1V bit1)
//////////////////////////////////////////
void EnableQuadModeQspiFlashS25fs128s(void)
{
	uint8_t readDataB[2];
	uint8_t configReg=0;
	uint32_t statusReg=0;

	char str[64];		//DEBUG

//	configReg = ReadAnyRegisterQspiFlash(0x00800002, readDataB); //CR1V
	ReadAnyRegisterQspiFlash(0x00800002, &configReg); //CR1V

	Data2HexAscii(configReg,str,4);									//********************* DEBUG
	PutStr("configReg(CR1V) :H' ",0);			PutStr(str,1);		//********************* DEBUG

	if(!(configReg & BIT1))
	{
		PutStr("QUAD mode set!",1);

		WriteCommandQspiFlash(0x00060000);			//WRITE ENABLE
		WriteAnyRegisterQspiFlash(0x00800002, (configReg | BIT1));	 //CR1V[1]=1 :0=Dual or Serial, 1=Quad

		while(1)
		{
			ReadStatusQspiFlash(&statusReg);
			if( !(statusReg & BIT0) )	break;
		}
	}
}
