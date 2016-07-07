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

#include <stdint.h>


#ifdef AArch64
//typedef uint64_t    uintptr_t;
#define CPU_BYTE_SIZE			SIZE_64BIT
#endif

#ifdef AArch32
//typedef uint32_t    uintptr_t;
#define CPU_BYTE_SIZE			SIZE_32BIT
#endif


#define		DIS_RTN				0		/* Disable Return		*/
#define		ENB_RTN				1		/* Enable Return		*/
#define		OK				  0x1

#ifndef NULL
#define		NULL			  0x0
#endif

#define		INT_CODE		0x25		/* "%"					*/
#define		BS_CODE			0x08		/* "BS"					*/
#define		CR_CODE			0x0d		/* "CR"					*/
#define		SP_CODE			0x20		/* "LF"					*/
#define		LF_CODE			0x0a		/* "LF"					*/

#define		SIZE_8BIT		1			// Old name : BYTE_SIZE
#define		SIZE_16BIT		2			// Old name : WORD_SIZE
#define		SIZE_32BIT		4			// Old name : LONG_SIZE
#define		SIZE_64BIT		8			// New

/****************************
	Module Proto Type		*
****************************/
int32_t PutMess(const char *const mess[]);
int32_t	PutStr(const char *str,char rtn);
int32_t	GetStr(char *str,char *chCnt);
int32_t	GetStr_MemEd(char *str,char *chCnt);
uint32_t Hex2Ascii(int32_t hexdata,char *str,int32_t *chcnt);
uint32_t Hex2DecAscii(int32_t hexdata,char *str,int32_t *chcnt);
void DelStr(int32_t delCnt);
void ChgLtl2Lrg(char *str);
char HexAscii2Data(unsigned char *buf,uint32_t *data);
char HexAscii2Data_64(unsigned char *buf,uintptr_t *data);
char Data2HexAscii(uint32_t data,char *buf,char size);
char Data2HexAscii_64(uintptr_t data,char *buf,char size);
char GetStrBlk(char *inStr,char *outStr, char *chPtr,char method);
void SoftDelay(uint32_t roop);
void WaitKeyIn_Y(void);
char WaitKeyIn_YorN(void);
int32_t	GetStr_MemEd(char *str,char *chCnt);
