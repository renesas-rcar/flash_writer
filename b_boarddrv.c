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

#include "common.h"
#include "reg_rcarh3.h"
#include "bit.h"
#include "b_boarddrv.h"
#include "cpudrv.h"



// Connect = return 0
// Open    = return 1
uint32_t SSI_WS6_OpenCheck(void)
{
	uint32_t dataL, down, up;

	// Pull-Up/Down Enable (PUEN5[22]=1)
	dataL = *((volatile uint32_t*)PFC_PUEN5);
	dataL |= (BIT22);
	*((volatile uint32_t*)PFC_PMMR)  = ~dataL;
	*((volatile uint32_t*)PFC_PUEN5) =  dataL;
	while( 0 == (BIT22 & *((volatile uint32_t*)PFC_PUEN5)) );  // wait 1

	// Pull-Down-Enable (PUD5[22]=0, PUEN5[22]=1)
	dataL = *((volatile uint32_t*)PFC_PUD5);
	dataL &= ~(BIT22);
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_PUD5) =  dataL;
	while( 0 != (BIT22 & *((volatile uint32_t*)PFC_PUD5)) );  // wait 0
	StartTMU0usec(1);										  // wait 10us
	down = GetGpioInputLevel(6,15);	// GPSR6[15]=SSI_WS6

	// Pull-Up-Enable (PUD5[22]=1, PUEN5[22]=1)
	dataL = *((volatile uint32_t*)PFC_PUD5);
	dataL |= (BIT22);
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_PUD5) =  dataL;
	while( 0 == (BIT22 & *((volatile uint32_t*)PFC_PUD5)) );  // wait 1
	StartTMU0usec(1);										  // wait 10us
	up = GetGpioInputLevel(6,15);	// GPSR6[15]=SSI_WS6

	// Pull-Up/Down Disable (PUEN5[22]=0)
	dataL = *((volatile uint32_t*)PFC_PUEN5);
	dataL &= ~(BIT22);
	*((volatile uint32_t*)PFC_PMMR)  = ~dataL;
	*((volatile uint32_t*)PFC_PUEN5) =  dataL;
	while( 0 != (BIT22 & *((volatile uint32_t*)PFC_PUEN5)) );  // wait 0

	// Compare
	if( down == up ){
		// Same = Connect
		return 0;
	}else{
		// Diff = Open
		return 1;
	}
}


// Connect = return 0
// Open    = return 1
uint32_t USB0_OVC_OpenCheck(void)
{
	uint32_t dataL, down, up;

	// Pull-Up/Down Enable (PUD6[0]=1)
	dataL = *((volatile uint32_t*)PFC_PUEN6);
	dataL |= (BIT0);
	*((volatile uint32_t*)PFC_PMMR)  = ~dataL;
	*((volatile uint32_t*)PFC_PUEN6) =  dataL;
	while( 0 == (BIT0 & *((volatile uint32_t*)PFC_PUEN6)) );  // wait 1

	// Pull-Down-Enable (PUD6[0]=0, PUEN6[0]=1)
	dataL = *((volatile uint32_t*)PFC_PUD6);
	dataL &= ~(BIT0);
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_PUD6) =  dataL;
	while( 0 != (BIT0 & *((volatile uint32_t*)PFC_PUD6)) );  // wait 0
	StartTMU0usec(1);										 // wait 10us
	down = GetGpioInputLevel(6,25);	// GPSR6[25]=USB0_OVC

	// Pull-Up-Enable (PUD6[0]=1, PUEN6[22]=1)
	dataL = *((volatile uint32_t*)PFC_PUD6);
	dataL |= (BIT0);
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_PUD6) =  dataL;
	while( 0 == (BIT0 & *((volatile uint32_t*)PFC_PUD6)) );  // wait 1
	StartTMU0usec(1);										 // wait 10us
	up = GetGpioInputLevel(6,25);	// GPSR6[25]=USB0_OVC

	// Pull-Up/Down Disable (PUEN6[22]=0)
	dataL = *((volatile uint32_t*)PFC_PUEN6);
	dataL &= ~(BIT0);
	*((volatile uint32_t*)PFC_PMMR)  = ~dataL;
	*((volatile uint32_t*)PFC_PUEN6) =  dataL;
	while( 0 != (BIT0 & *((volatile uint32_t*)PFC_PUEN6)) );  // wait 0

	// Compare
	if( down == up ){
		// Same = Connect
		return 0;
	}else{
		// Diff = Open
		return 1;
	}
}


