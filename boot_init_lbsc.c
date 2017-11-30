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
#include "reg_rcarh3.h"
#include "boot_init_lbsc.h"


void InitLBSC(void)
{
	InitCSCTRL();
	InitCSWCR();
	InitCSPWCR();
	InitEXWTSYNC();
}


void InitCSCTRL(void)
{
	*((volatile uint32_t*)LBSC_CS0CTRL)=0x00000020;
	*((volatile uint32_t*)LBSC_CS1CTRL)=0x00000020;
}

void InitCSWCR(void)
{
	uint32_t product;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	switch (product) {
	case PRR_PRODUCT_H3:
		*((volatile uint32_t*)LBSC_CSWCR0)=0xFF70FF70;			//Initial value
		*((volatile uint32_t*)LBSC_CSWCR1)=0xFF70FF70;			//Initial value
		break;
	case PRR_PRODUCT_M3:
	case PRR_PRODUCT_M3N:
		*((volatile uint32_t*)LBSC_CSWCR0)=0x2A103320;
		*((volatile uint32_t*)LBSC_CSWCR1)=0x2A103320;
		break;
	default:
		break;
	}
}

void InitCSPWCR(void)
{
	*((volatile uint32_t*)LBSC_CSPWCR0)=0x00000000;
	*((volatile uint32_t*)LBSC_CSPWCR1)=0x00000000;
}

void InitEXWTSYNC(void)
{
	*((volatile uint32_t*)LBSC_EXWTSYNC)=0x00000000;
	*((volatile uint32_t*)LBSC_CS1GDST) =0x00000000;
}

