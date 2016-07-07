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

/* *********************** HEADER (INCLUDE) SECTION ************************ */
#include "timer_api.h"
#include "reg_rcarh3.h"
//#include "reg_rcare2x.h"
#include "bit.h"
#include "common.h"

/* ***************** MACROS, CONSTANTS, COMPILATION FLAGS ****************** */

/* ********************** STRUCTURES, TYPE DEFINITIONS ********************* */

/* ********************** DECLARATION OF EXTERNAL DATA ********************* */

/* ************************** FUNCTION PROTOTYPES ************************** */

/************************************************************************/
/*	TMU2 wait(10ms order)												*/
/************************************************************************/
void StartTMU2(uint32_t tenmSec)
{
	uint16_t dataW;
	uint32_t cnt;
	uint32_t timeOut;

	*((volatile uint16_t*)TMU_TCR6)	= 0x0000U;	// Input-Clock 1/4 count

	*((volatile uint32_t*)TMU_TCNT6)	= 333325U;	// [Gen3](133.33MHz/4)*333325=9.99025ms
	*((volatile uint32_t*)TMU_TCOR6)	= 333325U;	// Input-Clock=S3D2 Phy-Clock=133.33MHz

	*((volatile uint8_t*)TMU_TSTR2)	|= BIT0;	// TMU2 Start
	for(cnt=0;cnt<tenmSec;cnt++){
		timeOut=0;
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR6);
			if(dataW & BIT8){	// UNF(under-flow-flag) clear
				*((volatile uint16_t*)TMU_TCR6) &= ~BIT8;
				break;
			}
			if((timeOut++)>1000000){
				PutStr("===== TMU2 Time Out!! (count 1000000) =====",1);
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR2) &= ~BIT0;		// TMU2 Stop
}

/************************************************************************/
/*	TMU2 wait(10us order)												*/
/************************************************************************/
void StartTMU2usec(uint32_t uSec)
{
	uint16_t dataW;
	uint32_t cnt;
	uint32_t timeOut;

	*((volatile uint16_t*)TMU_TCR6)	= 0x0000U;	// Input-Clock 1/4 count

	*((volatile uint32_t*)TMU_TCNT6)	= 333U;		// [Gen3](133.33MHz/4)*333(.325)=9.99025us (def -0.0585s/60s)
	*((volatile uint32_t*)TMU_TCOR6)	= 333U;		// Input-Clock=S3D2 Phy-Clock=133.33MHz

	*((volatile uint8_t*)TMU_TSTR2)	|= BIT0;	// TMU2 Start
	for(cnt=0;cnt<uSec;cnt++){
		timeOut=0;
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR6);
			if(dataW & BIT8){	// UNF(under-flow-flag) clear
				*((volatile uint16_t*)TMU_TCR6) &= ~BIT8;
				break;
			}
			if((timeOut++)>1000000){
				PutStr("===== TMU2 Time Out!! (count 1000000) =====",1);
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR2) &= ~BIT0;		// TMU2 Stop
}

void PowerOnTmu2(void)
{
	uint32_t dataL;

	dataL = *((volatile uint32_t*)CPG_SMSTPCR1);
	if(dataL & BIT23){
		dataL &= ~(BIT23);
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR1) = dataL;
		while( (BIT23 & *((volatile uint32_t*)CPG_MSTPSR1)) );	// wait 0
	}

	*((volatile uint8_t*)TMU_TSTR2)	= 0x00U;
	*((volatile uint16_t*)TMU_TCR6)	= 0x0000U;
	*((volatile uint32_t*)TMU_TCNT6)	= 0x00000000U;
	*((volatile uint32_t*)TMU_TCOR6)	= 0x00000000U;
}

void PowerOffTmu2(void)
{
	uint32_t dataL;

	*((volatile uint8_t*)TMU_TSTR2)	= 0x00U;
	*((volatile uint16_t*)TMU_TCR6)	= 0x0000U;
	*((volatile uint32_t*)TMU_TCNT6)	= 0x00000000U;
	*((volatile uint32_t*)TMU_TCOR6)	= 0x00000000U;

	dataL = *((volatile uint32_t*)CPG_SMSTPCR1);
	if(!(dataL & BIT23)){
		dataL |= BIT23;
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR1) = dataL;
		while( !(BIT23 & *((volatile uint32_t*)CPG_MSTPSR1)) );	// wait 0
	}
}

