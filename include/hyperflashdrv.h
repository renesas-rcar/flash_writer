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

#define	HYPER_FL_UNLOCK1_ADD		0x555
#define	HYPER_FL_UNLOCK1_DATA		(0xAA << 24)
#define	HYPER_FL_UNLOCK2_ADD		0x2AA
#define	HYPER_FL_UNLOCK2_DATA		(0x55 << 24)
#define	HYPER_FL_UNLOCK3_ADD		0x555

#define	HYPER_FL_RESET_COM			(0xF0 << 24)
#define	HYPER_FL_RD_STATUS_COM		(0x70 << 24)
#define	HYPER_FL_ID_ENTRY_COM		(0x90 << 24)
#define	HYPER_FL_WORD_PROGRAM_COM	(0xA0 << 24)
#define	HYPER_FL_ERASE_1ST_COM		(0x80 << 24)
#define	HYPER_FL_SECTOR_ERASE_COM	(0x30 << 24)
#define	HYPER_FL_CHIP_ERASE_COM		(0x10 << 24)

void ResetHyperFlash(void);
uint32_t ReadHyperFlashID(uint32_t *readData);
void WordProgramHyperFlash(uint32_t writeAddr, uint32_t writeData);
void SectorEraseHyperFlash(uint32_t sector_addr);
int32_t ChipEraseHyperFlash(void);
void RdHyperFlash (uint32_t sourceSpiAdd,uint32_t destinationAdd,uint32_t byteCount);
void RdManuHyperFlash(uint32_t sourceSpiAdd,uintptr_t destinationAdd,uint32_t byteCount);
void SaveDataWithBuffeHyperFlash(uint32_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void SaveDataHyperFlash(uintptr_t srcAdd,uint32_t svFlashAdd,uint32_t svSize);
void WordProgramWithBuffeHyperFlash(uint32_t addr, uint32_t source_addr);
void SectorEraseHyperFlashRange(uint32_t EraseStatAdd,uint32_t EraseEndAdd);
void SectorRdHyperFlash(uint32_t spiStatAdd,uint32_t distRamAdd);
