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
#include "dmaspi.h"
#include "bit.h"
#include "spiflash1drv.h"
#include "reg_rcarh3.h"

void InitDma01_Data(uint32_t prgStartAd, uint32_t sector_Ad, uint32_t accessCount)
{
	//DMA Setting
	*((volatile uint32_t*)SYSDMAC_DMASAR_0)    =  sector_Ad;		//	RPC area
	*((volatile uint32_t*)SYSDMAC_DMADAR_0)    =  prgStartAd;		//	
	*((volatile uint32_t*)SYSDMAC_DMATCR_0)    =  accessCount;		//
	*((volatile uint32_t*)SYSDMAC_DMACHCR_0)   =  0x00105409;		//64Byte/AutoRequest mode
}

void DisableDma01(void)
{
	*((volatile uint32_t*)SYSDMAC_DMACHCR_0)   &=  0x00105410;		//64Byte/AutoRequest mode
}

void ClearDmaCh01(void)
{
	*((volatile uint32_t*)SYSDMAC_DMACHCLR_0) |= BIT0;
}

void StartDma01(void)
{
	*((volatile uint16_t*)SYSDMAC_DMAOR_0)  =  0x0001;				//Start DMA	  ( Priority Mode:Fixed )
}

uint32_t WaitDma01(void)
{
	uint32_t dataL=0;

	////////////////////////////////
	// DMA transfer complite check
	////////////////////////////////
	while(1){
		dataL = *((volatile uint32_t*)SYSDMAC_DMACHCR_0);
		if(dataL & BIT1){
			*((volatile uint32_t*)SYSDMAC_DMACHCR_0) &= ~BIT1;		// TE Clear
			break;
		}
		if(dataL & BIT31){
			*((volatile uint32_t*)SYSDMAC_DMACHCR_0) &= ~BIT31;	// CAE Clear
			return(1);
		}
	}
	*((volatile uint16_t*)SYSDMAC_DMAOR_0) = 0x0000;				//0: Disables DMA transfers on all channels
	return(0);
}
