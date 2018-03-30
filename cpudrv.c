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

#include "common.h"
#include "bit.h"
#include "reg_rcarh3.h"
#include "cpudrv.h"


#define PFC_WR(m,n)   *((volatile uint32_t*)PFC_PMMR)=~(n);*((volatile uint32_t*)(m))=(n);

uint32_t gPrrData;

extern uint32_t GetProductIdAndCutNum(void);


// TMU ch0-2   : CP-Clock
// TMU ch3-11  : S3D2_PERE-Clock
// TMU ch12-14 : S3D2_RT-Clock
void StartTMU0(uint32_t tenmSec)
{
	uint16_t dataW;
	uint32_t cnt,dataL;

	PowerOnTmu0();

	*((volatile uint16_t*)TMU_TCR0)  = 0x0000;	// TCNT_count_clock=(Input-Clock)/4

	*((volatile uint32_t*)TMU_TCNT0) = 20833;	// [Gen3](8.3333MHz/4)*20833=9.999880ms (-0.000012s/100s)
	*((volatile uint32_t*)TMU_TCOR0) = 20833;	// Input-Clock=CP-Clock=16.6666/2=8.3333MHz


	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	// TMU0 Start
	for(cnt=0;cnt<tenmSec;cnt++){
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR0);
			if(dataW & BIT8){	// UNF(under-flow-flag) clear
				*((volatile uint16_t*)TMU_TCR0) &= ~BIT8;
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR0) &= ~BIT0;		// TMU0 Stop
}

void StartTMU0usec(uint32_t tenuSec)
{
	uint16_t dataW;
	uint32_t cnt,dataL;

	PowerOnTmu0();

	*((volatile uint16_t*)TMU_TCR0)  = 0x0000;	// TCNT_count_clock=(Input-Clock)/4

	*((volatile uint32_t*)TMU_TCNT0) = 21;	// [Gen3](8.3333MHz/4)*21=10.08004us (+0.8004s/100s)
	*((volatile uint32_t*)TMU_TCOR0) = 21;	// Input-Clock=CP-Clock=16.6666/2=8.3333MHz

	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	// TMU0 Start
	for(cnt=0;cnt<tenuSec;cnt++){
		while(1){
			dataW = *((volatile uint16_t*)TMU_TCR0);
			if(dataW & BIT8){	// UNF(under-flow-flag) clear
				*((volatile uint16_t*)TMU_TCR0) &= ~BIT8;
				break;
			}
		}
	}
	*((volatile uint8_t*)TMU_TSTR0) &= ~BIT0;		// TMU0 Stop
}


void PowerOnTmu0(void)
{
	uint32_t dataL;

	dataL = *((volatile uint32_t*)CPG_MSTPSR1);
	if(dataL & BIT25){
		dataL &= ~BIT25;
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR1) =  dataL;
		while( (BIT25) & *((volatile uint32_t*)CPG_MSTPSR1) );  // wait bit=0
	}
}

void InitStopWatchTmu0(void)
{
	uint32_t dataL;

	PowerOnTmu0();

//Case @16.66MHz
	*((volatile uint16_t*)TMU_TCR0)  = 0x0000;	// TCNT_count_clock=(Input-Clock)/4
	*((volatile uint32_t*)TMU_TCNT0) = 0xFFFFFFFF;	// MAX     ( Ex 41667 = [Gen3](16.66665MHz/4)*41667=10.00009ms (+0.0009s/100s))
	*((volatile uint32_t*)TMU_TCOR0) = 0xFFFFFFFF;	//         (   Input-Clock=CP-Clock=33.3333/2=16.66665MHz)

//	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	// TMU0 Start

	//  16.66665MHz/4=4.16666MHz
	//  1/4.16666MHz = 240ns
	
	//  1/4.16666MHz = 41667=10.00009ms
	//  1/4.16666MHz = 4167 =1.00008ms
}

void StartCountStopWatchTmu0( void )
{
	*((volatile uint8_t*)TMU_TSTR0) |= BIT0;	// TMU0 Start
}

void StopCountStopWatchTmu0( void )
{
	*((volatile uint8_t*)TMU_TSTR0) &= ~BIT0;	// TMU0 Stop
}


uint32_t GetTimeStopWatchTmu0( void )
{
	unsigned long dataL, usec;
	char str[64];

	if( *((volatile uint16_t*)(TMU_TCR0)) & BIT8 ) return 0;

	dataL = 0xFFFFFFFF - *((volatile uint32_t *)(TMU_TCNT0));


	Data2HexAscii(dataL,str,4);
//	PutStr(" TMU Count (1Count=240ns) = 0x",0);
	PutStr(" TMU Count = 0x",0);
	PutStr(str,1);

//	dataL /= 1625;		// 0.1ms = 100us
//	usec   = dataL * 100;

//	dataL /= 41667;		// 10ms = 10000us
//	usec   = dataL * 10000;


//Case @16.66MHz
//	dataL /= 4167;		// 1ms = 1000us
//	usec   = dataL * 1000;

//Case @16.00MHz (Board No.0007) &BUG CPG 1/2 -> 8MHz/4=2MHz
//	dataL /= 2000;		// 1ms = 1000us
//	usec   = dataL * 1000;

//Case @16.6666MHz (Board No.0243) &BUG CPG 1/2 -> 8.3333MHz/4=2.0833MHz
	dataL /= 2083;		// 1ms = 1000us

//	usec   = dataL * 1000;
//	return usec;
	return dataL;		//msec
}


void SetgPrrData(void)
{
	gPrrData = GetProductIdAndCutNum();
}

void PutgPrrData(void)
{	
	char str[64];

	Data2HexAscii(gPrrData,str,4);
	PutStr(" PRR : H'",0);
	PutStr(str,1);
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
	else					return 0;
}


	