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

#define SPI_IOADDRESS_TOP		0x08000000		//RPC memory space 0x08000000-0x0BFFFFFF = 64MBytes
#define RPC_CLK_40M				0x01
#define RPC_CLK_80M				0x02
#define RPC_CLK_160M			0x03


void InitRPC_QspiFlashQuadExtMode(void);
void InitRPC_QspiFlash4FastReadExtMode(void);
void InitRPC_QspiFlash(void);
void InitRPC_QspiFlashBoard(void);
void ReadConfigRegQspiFlash(uint32_t *cnfigReg);
void WriteRegisterQspiFlash(uint32_t statusReg, uint32_t configReg);
void WriteRegisterQspiFlash_Byte2(uint32_t statusReg, uint32_t configReg);
void SectorErase4QspiFlash(uint32_t sector_addr);
void WriteData4ppWithBufferQspiFlash(uint32_t addr, uint32_t source_addr);
void WriteData4qppWithBufferQspiFlash(uint32_t addr, uint32_t source_addr);
void WriteData4ppQspiFlash(uint32_t addr, uint32_t writeData);
void WriteData4ppQspiFlash_CsCont(uint32_t addr, uint32_t *writeData,uint32_t cnt);
void WriteData4qppQspiFlash(uint32_t addr, uint32_t writeData);
uint32_t SingleFastReadQspiFlashData4Byte(uint32_t addr, uint32_t *readData);	//for QSPIx1ch
uint32_t SingleFastReadQspiFlashData1Byte(uint32_t addr, uint32_t *readData);	//for QSPIx1ch
uint32_t QuadFastReadQspiFlashData4Byte(uint32_t addr, uint32_t *readData);	//for QSPIx1ch
uint32_t ReadAnyRegisterQspiFlash(uint32_t addr, unsigned char *readData);		// Add24bit,Data8bit
void WriteAnyRegisterQspiFlash(uint32_t addr, unsigned char writeData);			// Add24bit,Data8bit
uint32_t QuadIOReadQspiFlashData4Byte(uint32_t addr, uint32_t *readData);
void SetRPC_ClockMode(uint32_t mode);
void WaitRpcTxEnd(void);

void InitRPC_QspiFlashFastReadExtMode(void);
void WriteDataPpWithBufferQspiFlash(uint32_t addr, uint32_t source_addr);

void ParameterSectorErase4QspiFlash(uint32_t sector_addr);
void ResetRPC(void);
//void SetResetRPC(void);
//void ClearResetRPC(void);
void SetRPC_SSL_Delay(void);

void PowerOnRPC(void);
uint32_t ReadQspiFlashID(uint32_t *readData);	//for QSPIx1ch
uint32_t ReadStatusQspiFlash(uint32_t *readData);	//for QSPIx1ch
void WriteCommandQspiFlash(uint32_t command);	//for QSPIx1ch
void WriteDataWithBufferQspiFlash(uint32_t addr, uint32_t source_addr);	//for QSPIx1ch
void SectorEraseQspiFlash(uint32_t sector_addr);	//for QSPIx1ch
void InitRPC_ExtMode_QuadIORead(void);	//for QSPIx1ch
void EnableQuadModeQspiFlashS25fs128s(void);
