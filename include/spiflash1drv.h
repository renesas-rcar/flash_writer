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

//==============================================
// SPANSION  S25FS128SAGMFV10
//==============================================

#define SPIREG_CR3V 0x00800004			//Volatile Status and Configuration Registers (CR3V)

void FastRdQspiFlashS25s128s(uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount);
void QuadIORdQspiFlashS25s128s(uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount);
void FastRdManuQspiFlashS25s128s(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount);
void SetSectorErase256kbQspiFlashS25s128s(void);
void SectorErase256kbQspiFlashS25s128s(uint32_t addr);
int32_t BulkEraseQspiFlashS25s128s(void);
void PageProgramQspiFlashS25s128s(uint32_t addr,uint32_t writeData);
void PageProgramQspiFlashS25s128s_CsCont(uint32_t addr, uint32_t *writeData,uint32_t byteCount);
void PageProgramWithBuffeQspiFlashS25s128s(uint32_t addr, uint32_t source_addr);
void SaveDataQspiFlashS25s128s(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void SaveDataQspiFlashS25s128s_CsCont_Byte(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void SaveDataQspiFlashS25s128s_CsCont(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void SaveDataWithBuffeQspiFlashS25s128s(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void SectorEraseQspiFlashS25s128s(uint32_t EraseStatAdd,uint32_t EraseEndAdd);
void ParameterSectorEraseQspiFlashS25s128s(uint32_t EraseStatAdd,uint32_t EraseEndAdd);
void SectorRdQspiFlashS25s128s(uint32_t spiStatAdd,uint32_t distRamAdd);

void FastRd3adQspiFlashS25s128s (uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount);

void SectorErase256kbQspiFlashS25s128s_D8(uint32_t addr);

void ParameterSectorErase4kbQspiFlashS25s128s(uint32_t addr);

