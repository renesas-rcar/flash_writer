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

#define		CHANGE_OFF		0
#define		CHANGE_ON		1

#define		ADDITION					0x00000000
#define		SUBTRACTION					0x00000001

#define		SYSTEMRAM_SADD				0xE6300000
#define		SYSTEMRAM_IPL_SADD			0xE6302000
#define		PUBLICRAM_EADD				0xE635FFFF

#define		LS_WORK_DRAM_SADD			0x50000000
#define		LS_WORK_DRAM_EADD_192K		0x5002FFFF
#define		LS_WORK_DRAM_EADD_16K		0x50003FFF
#define		LS_WORK_DRAM_EADD_64M		0x53FFFFFF




#define		LS_WORK_SRAMBD_SADD			0x04000000
#define		LS_WORK_SRAMBD_EADD_192K	0x0402FFFF
#define		LS_WORK_SRAMBD_EADD_16M		0x04FFFFFF



//----------------------------------------------------------------------
//                            Memory Size / Sector Size
//QspiFlash Board  (S25FL512):  64MByte   / 256KByte
//OnBoard QspiFlash(S25FS128):  16MByte   / 256KByte
//HyperFlash (on R-CarH3-SiP):  64MByte   / 256KByte
//----------------------------------------------------------------------

//Serial Flash ROM
//Hyper Flash / QSPI Flash(S25FL512)
#define		S25FL512_SA_SIZE			0x0040000
#define		S25FL512_SA00_STARTAD		0x0000000
#define		S25FL512_SA01_STARTAD		0x0040000
#define		S25FL512_SA02_STARTAD		0x0080000
#define		S25FL512_SA03_STARTAD		0x00C0000		//User Add,Size
#define		S25FL512_SA04_STARTAD		0x0100000		//User Image
#define		S25FL512_END_ADDRESS		0x3FFFFFF

#define		S25S128_END_ADDRESS			0x0FF7FFF

#define		S25FL512_SA03_PRG_ST_AD		0x00C0000
#define		S25FL512_SA03_PRG_SIZE		0x00C0004

#define		S25FL512_SA00_BTROM_PARA	0x0000000		//Boot ROM Parameters (4Byte)
#define		S25FL512_SA00_A_IPL_ADD		0x0000D54		//A-side IPL address  (4Byte)
#define		S25FL512_SA00_A_IPL_SIZE	0x0000E64		//A-side IPL data size(4Byte)
#define		S25FL512_SA00_B_IPL_ADD		0x0001154		//B-side IPL address  (4Byte)
#define		S25FL512_SA00_B_IPL_SIZE	0x0001264		//B-side IPL data size(4Byte)

#define		ONBOARD_QSPI				0x00182001		//ID	S25FS128S
#define		QSPI_BOARD					0x00200201		//ID	S25FL512S 03h:xxh
#define		HYPER_FLASH					0x007E0001		//ID  S26KS512S


void dgGen3LoadSpiflash0(void);
void SelQspiFlashSetSw(void);
void InitRPC_Mode(void);
uint32_t CheckQspiFlashId(void);
int32_t CkQspiFlash0ClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize);
int32_t CkQspiFlash1ClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize);
int32_t CkHyperFlashClearSectorSize(uint32_t rdBufAdd,uint32_t spiFlashStatAdd,uint32_t checkSize,uint32_t accessSize);
void mem_copy(uint32_t prgStartAd, uint32_t sector_Ad, uint32_t accessSize);
void dgGen3LoadSpiflash0_2(void);
void dgGen3LoadSpiflash0_3(void);
void XLoadSpiflash0_2(uint32_t mode);

void SetData(uint32_t *setAdd);
int32_t CkSpiFlashAllF(int32_t sAdd,int32_t cap);
void SetAddInputKey(uint32_t *Address);
void SetSizeInputKey(uint32_t *size);
void dgGen3InfoSpiflash0_SA0(void);
int32_t CheckDataChange(uintptr_t checkAdd);
void dgGen3InfoSetSpiflash0_SA0(void);
void dgGen3InfoSpiflash0(void);
void dgGen3InfoSetSpiflash0(void);
void dgClearSpiflash0(void);
char dgLS_Load_Offset2(uint32_t *maxADD ,uint32_t *minADD);

