/*
 * Copyright (c) 2018, Renesas Electronics Corporation
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
#include "reg_rcarh3.h"
#include "boot_init_dram.h"
#ifdef RCAR_GEN3_EBISU
#include "ddr_init_e3.h"
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
#include "ddr_init_d3.h"
#endif /* RCAR_GEN3_DRAAK */

#define MD19	(0x00080000)	/* bit19 */


int32_t InitDram(void)
{
	uint32_t product;
	uint32_t modemr;

	modemr  = *(volatile uint32_t*)RST_MODEMR;
	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	switch (product) {
#ifdef RCAR_GEN3_EBISU
	case PRR_PRODUCT_E3:
		if ((modemr & MD19) == 0U) {
			(void)init_ddr_e31600();
		} else {
			(void)init_ddr_e31866();
		}
		break;
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	case PRR_PRODUCT_D3:
		if ((modemr & MD19) == 0U) {
			(void)init_ddr_d31600();
		} else {
			(void)init_ddr_d31866();
		}
		break;
#endif /* RCAR_GEN3_DRAAK */
	default:
		break;
	}

	return INITDRAM_OK;
}
