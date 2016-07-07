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

/**********************
* COMMAND_UNITE       *
***********************/
#define		COMMAND_UNIT		17
#define		NORMAL_END			0
#define		ERROR_END			1

/**********************
* MESSAGE LINE       *
***********************/
#define		START_MESS_MON_LINE	2
#define		START_MESS_MEM_LINE	2
#define		ALL_HELP_MESS_LINE	20

/**********************
* TABLE PARAMETER     *
***********************/
#define		TBL_END				0
#define		MESSAGE_END			0
#define		DISABLE				0x00
#define		ENABLE				0x01

#ifdef AArch32
#define			ARM_CPSR		0
#define			ARM_R0			1
#define			ARM_R1			2
#define			ARM_R2			3
#define			ARM_R3			4
#define			ARM_R4			5
#define			ARM_R5			6
#define			ARM_R6			7
#define			ARM_R7			8
#define			ARM_R8			9
#define			ARM_R9			10
#define			ARM_R10			11
#define			ARM_R11			12
#define			ARM_R12			13
//#define			ARM_R13(SP)		13
//#define			ARM_R14(LR)		14
//#define			ARM_R15(PC)		15
#define			ARM_R14(LR)		14
#define			ARM_R15(PC)		15
#define			ARM_R13(SP)		16
#endif

/****************************************************************/
/*                                                              */
/*   Command Table Struct                                       */
/*                                                              */
/****************************************************************/
typedef struct protect_add {
	long		startAdd;
	long		endAdd;
} protect_add;

typedef struct com_menu {
	char		*comStr;
	void		(*comProg)();	 /* Program Pointer	*/
	protect_add *protectAdd;
} com_menu;

