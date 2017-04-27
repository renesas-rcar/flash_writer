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
#include "scifdrv.h"
#include "bit.h"
#include "reg_rcarh3.h"
#include "devdrv.h"


 /* Product Register */
#define PRR					(0xFFF00044U)
#define PRR_PRODUCT_MASK	(0x00007F00U)
#define PRR_CUT_MASK		(0x000000FFU)
#define PRR_PRODUCT_H3		(0x00004F00U)           /* R-Car H3 */
#define PRR_PRODUCT_M3		(0x00005200U)           /* R-Car M3 */
#define RCAR_PRODUCT_H3_CUT10	(PRR_PRODUCT_H3 | 0x00U) /* H3 WS1.0 */

//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//	Debug Seirial(SCIF2)														//
//																				//
//////////////////////////////////////////////////////////////////////////////////
int32_t PutCharSCIF2(char outChar)
{
	while(!(0x60 & *((volatile uint16_t*)SCIF2_SCFSR) ));
	*((volatile unsigned char*)SCIF2_SCFTDR) = outChar;
	*((volatile uint16_t*)SCIF2_SCFSR) &= ~0x60;	/* TEND,TDFE clear */
	return(0);
}

int32_t GetCharSCIF2(char *inChar)
{
	do{
		if(0x91 & *((volatile uint16_t *)SCIF2_SCFSR))
			*((volatile uint16_t *)SCIF2_SCFSR) &= ~0x91;
		if(0x01 & *((volatile uint16_t *)SCIF2_SCLSR))
		{
			PutStr("ORER",1);
			*((volatile uint16_t *)SCIF2_SCLSR) &= ~0x01;
		}
	}while( !(0x02 & *((volatile uint16_t *)SCIF2_SCFSR)) );
		*inChar = *((volatile unsigned char*)SCIF2_SCFRDR);
		*((volatile uint16_t*)SCIF2_SCFSR) &= ~0x02;
	return(0);
}

void PowerOnScif2(void)
{
	uint32_t dataL;

	dataL = *((volatile uint32_t*)CPG_MSTPSR3);
	if(dataL & BIT10){	// case SCIF2(IrDA) Standby
		dataL &= ~BIT10;
		*((volatile uint32_t*)CPG_CPGWPR)    = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR3)  =  dataL;
		while( BIT10 & *((volatile uint32_t*)CPG_MSTPSR3) );  // wait bit=0
	}
}

void WaitPutScif2SendEnd(void)
{
	uint16_t dataW;
    uint32_t loop;

	loop=1;
    while(loop){
		dataW = *((volatile uint16_t*)SCIF2_SCFSR);
		if(dataW & BIT6)	loop = 0;
	}
}

void InitScif2_SCIFCLK(void)
{
	uint16_t dataW;
	uint32_t prr;

	PowerOnScif2();

	dataW = *((volatile uint16_t*)SCIF2_SCLSR);	/* dummy read     		*/
	*((volatile uint16_t*)SCIF2_SCLSR) = 0x0000;	/* clear ORER bit 		*/
	*((volatile uint16_t*)SCIF2_SCFSR) = 0x0000;	/* clear all error bit	*/

	*((volatile uint16_t*)SCIF2_SCSCR) = 0x0000;	/* clear SCR.TE & SCR.RE*/
	*((volatile uint16_t*)SCIF2_SCFCR) = 0x0006;	/* reset tx-fifo, reset rx-fifo. */

#ifdef SCIF_CLK_EXTERNAL
	*((volatile uint16_t*)SCIF2_SCSCR) = 0x0002;	/* external clock, SC_CLK pin used for input pin */
	*((volatile uint16_t*)SCIF2_SCSMR) = 0x0000;	/* 8bit data, no-parity, 1 stop, Po/1 */
	SoftDelay(100);

#ifdef Writer
	prr = *((volatile uint32_t*)PRR);
	prr &= (PRR_PRODUCT_MASK | PRR_CUT_MASK);

	if (prr == RCAR_PRODUCT_H3_CUT10) {
		*((volatile uint16_t*)SCIF2_DL)    = 0x0010;	/* 14.7456MHz/ (57600*16) =  16 */
	} else {
		*((volatile uint16_t*)SCIF2_DL)    = 0x0008;	/* 14.7456MHz/ (115200*16) =  8 */
	}
#else  /* Writer */
	*((volatile uint16_t*)SCIF2_DL)    = 0x0008;	/* 14.7456MHz/ (115200*16) =  8 */
#endif /* Writer */

	*((volatile uint16_t*)SCIF2_CKS)   = 0x0000;	/*  select scif_clk	 */
	SoftDelay(100);
	*((volatile uint16_t*)SCIF2_SCFCR) = 0x0000;	/* reset-off tx-fifo, rx-fifo. */
	*((volatile uint16_t*)SCIF2_SCSCR) = 0x0032;	/* enable TE, RE; SC_CLK=input */
#endif /* SCIF_CLK_EXTERNAL */

#ifdef SCIF_CLK_INTERNAL
	*((volatile uint16_t*)SCIF2_SCSCR) = 0x0000;	/* internal clock, SC_CLK pin used for input pin */
	*((volatile uint16_t*)SCIF2_SCSMR) = 0x0000;	/* 8bit data, no-parity, 1 stop, Po/1 */
	SoftDelay(100);

#ifdef Writer
	*((volatile uint8_t*)SCIF2_SCBRR)  = 0x11;	/* 115200bps@66MHz */
#else  /* Writer */
	prr = *((volatile uint32_t*)PRR);
	prr &= (PRR_PRODUCT_MASK | PRR_CUT_MASK);

	if (prr == RCAR_PRODUCT_H3_CUT10) {
		*((volatile uint8_t*)SCIF2_SCBRR)  = 0x08;	/* 115200bps@33MHz */
	} else {
		*((volatile uint8_t*)SCIF2_SCBRR)  = 0x11;	/* 115200bps@66MHz */
	}
#endif /* Writer */

	SoftDelay(100);
	*((volatile uint16_t*)SCIF2_SCFCR) = 0x0000;	/* reset-off tx-fifo, rx-fifo. */
	*((volatile uint16_t*)SCIF2_SCSCR) = 0x0030;	/* enable TE, RE; SC_CLK=input */
#endif /* SCIF_CLK_INTERNAL */

	SoftDelay(100);
}

void InitScif2PinFunction(void)
{
	uint32_t dataL;

//SCIF2
	dataL = *((volatile uint32_t*)PFC_MOD_SEL1);
	dataL &= ~BIT12;
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_MOD_SEL1) = dataL;
	
	dataL = *((volatile uint32_t*)PFC_IPSR12);
	dataL &= ~0x000000FF;	//IP12[7:4]=4'b0000, IP12[3:0]=4'b0000
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_IPSR12) = dataL;
	
	dataL = *((volatile uint32_t*)PFC_GPSR5);
//	dataL &= 0xFFFFF3FF;	//GP5[11],GP5[10]
	dataL |= 0x00000C00;	//GP5[11],GP5[10]
	*((volatile uint32_t*)PFC_PMMR) = ~dataL;
	*((volatile uint32_t*)PFC_GPSR5) = dataL;
}

void SetScif2_DL(uint16_t setData)
{
	*((volatile uint16_t*)SCIF2_DL)    = setData;
}

void SetScif2_BRR(uint8_t setData)
{
	*((volatile uint8_t*)SCIF2_SCBRR)  = setData;
}


uint32_t SCIF_TerminalInputCheck(char* str)
{
	char result = 0;
	
	if(0x91 & *((volatile uint16_t *)SCIF2_SCFSR))
		*((volatile uint16_t *)SCIF2_SCFSR) &= ~0x91;
	if(0x01 & *((volatile uint16_t *)SCIF2_SCLSR))
	{
		PutStr("ORER",1);
		*((volatile uint16_t *)SCIF2_SCLSR) &= ~0x01;
	}
	if(0x02 & *((volatile uint16_t *)SCIF2_SCFSR))
	{
		*str = *((volatile unsigned char*)SCIF2_SCFRDR);
		*((volatile uint16_t*)SCIF2_SCFSR) &= ~0x02;
		result = 1;
	}
	return result;
}
