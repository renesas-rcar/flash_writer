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

#include "common.h"
#include "bit.h"
#include "reg_rcarh3.h"
#include "cpudrv.h"


/* TMU ch0-2   : CP-Clock        */
/* TMU ch3-11  : S3D2_PERE-Clock */
/* TMU ch12-14 : S3D2_RT-Clock   */
void StartTMU0(uint32_t tenmSec)
{
	uint16_t dataW;
	uint32_t cnt,dataL;

	PowerOnTmu0();

	*((volatile uint16_t*)TMU_TCR0)  = 0x0000U;	/* TCNT_count_clock=(Input-Clock)/4 */


#ifdef RCAR_GEN3_SALVATOR
	*((volatile uint32_t*)TMU_TCNT0) = 20833U;	/* [H3/M3/M3N](8.3333MHz/4)*20833=9.999880ms (-0.000012s/100s) */
	*((volatile uint32_t*)TMU_TCOR0) = 20833U;	/* Input-Clock=CP-Clock=16.6666/2=8.3333MHz */
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
	*((volatile uint32_t*)TMU_TCNT0) = 60000U;	/* [E3](24.0000MHz/4)*60000=10.00ms */
	*((volatile uint32_t*)TMU_TCOR0) = 60000U;	/* Input-Clock=CP-Clock=48.0000/2=24.0000MHz */
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	*((volatile uint32_t*)TMU_TCNT0) = 60000U;	/* [D3](24.0000MHz/4)*60000=10.00ms */
	*((volatile uint32_t*)TMU_TCOR0) = 60000U;	/* Input-Clock=CP-Clock=48.0000/2=24.0000MHz */
#endif /* RCAR_GEN3_DRAAK */

	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	/* TMU0 Start */
	for(cnt=0;cnt<tenmSec;cnt++){
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR0);
			if(dataW & BIT8){		/* UNF(under-flow-flag) clear */
				*((volatile uint16_t*)TMU_TCR0) &= ~BIT8;
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR0) &= ~BIT0;	/* TMU0 Stop */
}

void StartTMU0usec(uint32_t tenuSec)
{
	uint16_t dataW;
	uint32_t cnt,dataL;

	PowerOnTmu0();

	*((volatile uint16_t*)TMU_TCR0)  = 0x0000U;	/* TCNT_count_clock=(Input-Clock)/4 */

#ifdef RCAR_GEN3_SALVATOR
	*((volatile uint32_t*)TMU_TCNT0) = 21U;		/* [H3/M3/M3N](8.3333MHz/4)*21=10.08004us (+0.8004s/100s) */
	*((volatile uint32_t*)TMU_TCOR0) = 21U;		/* Input-Clock=CP-Clock=16.6666/2=8.3333MHz */
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
	*((volatile uint32_t*)TMU_TCNT0) = 60U;		/* [E3](24.0000MHz/4)*60=10.00us */
	*((volatile uint32_t*)TMU_TCOR0) = 60U;		/* Input-Clock=CP-Clock=48.0000/2=24.0000MHz */
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	*((volatile uint32_t*)TMU_TCNT0) = 60U;		/* [D3](24.0000MHz/4)*60=10.00us */
	*((volatile uint32_t*)TMU_TCOR0) = 60U;		/* Input-Clock=CP-Clock=48.0000/2=24.0000MHz */
#endif /* RCAR_GEN3_DRAAK */

	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	/* TMU0 Start */
	for(cnt=0;cnt<tenuSec;cnt++){
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR0);
			if(dataW & BIT8){		/* UNF(under-flow-flag) clear */
				*((volatile uint16_t*)TMU_TCR0) &= ~BIT8;
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR0) &= ~BIT0;	/* TMU0 Stop */
}


void PowerOnTmu0(void)
{
	uint32_t dataL;

	dataL = *((volatile uint32_t*)CPG_MSTPSR1);
	if(dataL & BIT25){
		dataL &= ~BIT25;
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR1) =  dataL;
		while( (BIT25) & *((volatile uint32_t*)CPG_MSTPSR1) );  /* wait bit=0 */
	}
}


const void* const GPIO_INDT[8]={
	(void*)GPIO_INDT0,
	(void*)GPIO_INDT1,
	(void*)GPIO_INDT2,
	(void*)GPIO_INDT3,
	(void*)GPIO_INDT4,
	(void*)GPIO_INDT5,
	(void*)GPIO_INDT6,
	(void*)GPIO_INDT7,
};


uint32_t GetGpioInputLevel( uint32_t gp, uint32_t bit )
{
	uint32_t dataL;
	dataL = *((volatile uint32_t*)GPIO_INDT[gp]);
	if(dataL & (1<<bit))	return 1;
	else			return 0;
}
