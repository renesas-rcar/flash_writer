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


//CPG
#define	CPG_CPGWPCR						0xE6150904	// R/W	32	CPG Write Protect Control Register
#define	CPG_CPGWPR						0xE6150900	// R/W	32	CPG Write Protect Register
#define	CPG_FRQCRB						0xE6150004	// R/W	32	Frequency control register B
#define	CPG_FRQCRC						0xE61500E0	// R/W	32	Frequency control register C
#define	CPG_PLLECR						0xE61500D0	// R/W	32	PLL Enable Control Register
#define	CPG_PLL0CR						0xE61500D8	// R/W	32	PLL0 control register
#define	CPG_PLL2CR						0xE615002C	// R/W	32	PLL2 control register
#define	CPG_PLL3CR						0xE61500DC	// R/W	32	PLL2 control register
#define	CPG_PLL0STPCR					0xE61500F0	// R/W	32	PLL0 Stop Condition Register
#define	CPG_PLL2STPCR					0xE61500F8	// R/W	32	PLL2 Stop Condition Register
#define	CPG_PLL3STPCR					0xE61500FC	// R/W	32	PLL3 Stop Condition Register
#define	CPG_PLL4STPCR					0xE61501F8	// R/W	32	PLL4 Stop Condition Register
#define	CPG_SD0CKCR						0xE6150074	// R/W	32	SD-IF0 clock frequency control register
#define	CPG_SD1CKCR						0xE6150078	// R/W	32	SD-IF1 clock frequency control register
#define	CPG_SD2CKCR						0xE6150268	// R/W	32	SD-IF2 clock frequency control register
#define	CPG_SD3CKCR						0xE615026C	// R/W	32	SD-IF3 clock frequency control register
#define	CPG_RPCCKCR						0xE6150238	// R/W	32	RPC clock frequency control register
#define	CPG_SSPSRCCKCR					0xE6150248	// R/W	32	SSPSRC clock frequency control register
#define	CPG_SSPRSCKCR					0xE615024C	// R/W	32	SSPRS clock frequency control register
#define	CPG_CANFDCKCR					0xE6150244	// R/W	32	CAN-FD clock frequency control register
#define	CPG_MSOCKCR						0xE6150014	// R/W	32	MSIOF clock frequency control register
#define	CPG_HDMICKCR					0xE6150250	// R/W	32	HDMI-IF clock frequency control register
#define	CPG_CSI0CKCR					0xE615000C	// R/W	32	CSI0 clock frequency control register
#define	CPG_CSIREFCKCR					0xE6150034	// R/W	32	CSIREF clock frequency control register
#define	CPG_RCKCR						0xE6150240	// R/W	32	RCLK frequency control register
#define	CPG_DVFSCR0						0xE6150058	// R/W	32	DVFS control register 0
#define	CPG_DVFSCR1						0xE615005C	// R/W	32	DVFS control register 1 
#define	CPG_FSAPBR						0xE6150700	// R/W	32	Functional safety of APB bus interface register
#define	CPG_FSCLKCSR					0xE6150704	// R/W	32	Functional safety of clocks control/status register
#define	CPG_FSCNTCHKH0					0xE6150710	// R/W	32	Functional safety of clocks counter check H register 0
#define	CPG_FSCNTCHKH1					0xE6150714	// R/W	32	Functional safety of clocks counter check H register 1
#define	CPG_FSCNTCHKH2					0xE6150718	// R/W	32	Functional safety of clocks counter check H register 2
#define	CPG_FSCNTCHKH3					0xE615071C	// R/W	32	Functional safety of clocks counter check H register 3
#define	CPG_FSCNTCHKH4					0xE6150720	// R/W	32	Functional safety of clocks counter check H register 4
#define	CPG_FSCNTCHKH5					0xE6150724	// R/W	32	Functional safety of clocks counter check H register 5
#define	CPG_FSCNTCHKH6					0xE6150728	// R/W	32	Functional safety of clocks counter check H register 6
#define	CPG_FSCNTCHKL0					0xE6150730	// R/W	32	Functional safety of clocks counter check L register 0
#define	CPG_FSCNTCHKL1					0xE6150734	// R/W	32	Functional safety of clocks counter check L register 1
#define	CPG_FSCNTCHKL2					0xE6150738	// R/W	32	Functional safety of clocks counter check L register 2
#define	CPG_FSCNTCHKL3					0xE615073C	// R/W	32	Functional safety of clocks counter check L register 3
#define	CPG_FSCNTCHKL4					0xE6150740	// R/W	32	Functional safety of clocks counter check L register 4
#define	CPG_FSCNTCHKL5					0xE6150744	// R/W	32	Functional safety of clocks counter check L register 5
#define	CPG_FSCNTCHKL6					0xE6150748	// R/W	32	Functional safety of clocks counter check L register 6
#define	CPG_FSCNTMON0					0xE6150750	// R	32	Functional safety of clocks monitor register 0
#define	CPG_FSCNTMON1					0xE6150754	// R	32	Functional safety of clocks monitor register 1
#define	CPG_FSCNTMON2					0xE6150758	// R	32	Functional safety of clocks monitor register 2
#define	CPG_FSCNTMON3					0xE615075C	// R	32	Functional safety of clocks monitor register 3
#define	CPG_FSCNTMON4					0xE6150760	// R	32	Functional safety of clocks monitor register 4
#define	CPG_FSCNTMON5					0xE6150764	// R	32	Functional safety of clocks monitor register 5
#define	CPG_FSCNTMON6					0xE6150768	// R	32	Functional safety of clocks monitor register 6
#define	CPG_FSRCHKRA0					0xE6150A00	// R	32	Functional safety reset check register A 0
#define	CPG_FSRCHKRA1					0xE6150A04	// R	32	Functional safety reset check register A 1
#define	CPG_FSRCHKRA2					0xE6150A08	// R	32	Functional safety reset check register A 2
#define	CPG_FSRCHKRA3					0xE6150A0C	// R	32	Functional safety reset check register A 3
#define	CPG_FSRCHKRA4					0xE6150A10	// R	32	Functional safety reset check register A 4
#define	CPG_FSRCHKRA5					0xE6150A14	// R	32	Functional safety reset check register A 5
#define	CPG_FSRCHKRA6					0xE6150A18	// R	32	Functional safety reset check register A 6
#define	CPG_FSRCHKRA7					0xE6150A1C	// R	32	Functional safety reset check register A 7
#define	CPG_FSRCHKRA8					0xE6150A20	// R	32	Functional safety reset check register A 8
#define	CPG_FSRCHKRA9					0xE6150A24	// R	32	Functional safety reset check register A 9
#define	CPG_FSRCHKRA10					0xE6150A28	// R	32	Functional safety reset check register A 10
#define	CPG_FSRCHKRA11					0xE6150A2C	// R	32	Functional safety reset check register A 11
#define	CPG_FSRCHKRA12					0xE6150A30	// R	32	Functional safety reset check register A 12
#define	CPG_FSRCHKRA13					0xE6150A34	// R	32	Functional safety reset check register A 13
#define	CPG_FSRCHKRA14					0xE6150A38	// R	32	Functional safety reset check register A 14
#define	CPG_FSRCHKRA15					0xE6150A3C	// R	32	Functional safety reset check register A 15
#define	CPG_FSRCHKRA16					0xE6150B50	// R	32	Functional safety reset check register A 16
#define	CPG_FSRCHKRA17					0xE6150B54	// R	32	Functional safety reset check register A 17
#define	CPG_FSRCHKRA18					0xE6150B58	// R	32	Functional safety reset check register A 18
#define	CPG_FSRCHKRB0					0xE6150A30	// R	32	Functional safety reset check register B 0
#define	CPG_FSRCHKRB1					0xE6150A34	// R	32	Functional safety reset check register B 1
#define	CPG_FSRCHKRB2					0xE6150A38	// R	32	Functional safety reset check register B 2
#define	CPG_FSRCHKRB3					0xE6150A3C	// R	32	Functional safety reset check register B 3
#define	CPG_FSRCHKRB4					0xE6150A40	// R	32	Functional safety reset check register B 4
#define	CPG_FSRCHKRB5					0xE6150A44	// R	32	Functional safety reset check register B 5
#define	CPG_FSRCHKRB6					0xE6150A48	// R	32	Functional safety reset check register B 6
#define	CPG_FSRCHKRB7					0xE6150A4C	// R	32	Functional safety reset check register B 7
#define	CPG_FSRCHKRB8					0xE6150A50	// R	32	Functional safety reset check register B 8
#define	CPG_FSRCHKRB9					0xE6150A54	// R	32	Functional safety reset check register B 9
#define	CPG_FSRCHKRB10					0xE6150A58	// R	32	Functional safety reset check register B 10
#define	CPG_FSRCHKRB11					0xE6150A5C	// R	32	Functional safety reset check register B 11
#define	CPG_FSRCHKRB13					0xE6150A74	// R	32	Functional safety reset check register B 13
#define	CPG_FSRCHKSETR0					0xE6150A60	// W	32	Functional safety reset check set register 0
#define	CPG_FSRCHKSETR1					0xE6150A64	// W	32	Functional safety reset check set register 1
#define	CPG_FSRCHKSETR2					0xE6150A68	// W	32	Functional safety reset check set register 2
#define	CPG_FSRCHKSETR3					0xE6150A6C	// W	32	Functional safety reset check set register 3
#define	CPG_FSRCHKSETR4					0xE6150A70	// W	32	Functional safety reset check set register 4
#define	CPG_FSRCHKSETR5					0xE6150A74	// W	32	Functional safety reset check set register 5
#define	CPG_FSRCHKSETR6					0xE6150A78	// W	32	Functional safety reset check set register 6
#define	CPG_FSRCHKSETR7					0xE6150A7C	// W	32	Functional safety reset check set register 7
#define	CPG_FSRCHKSETR8					0xE6150A80	// W	32	Functional safety reset check set register 8
#define	CPG_FSRCHKSETR9					0xE6150A84	// W	32	Functional safety reset check set register 9
#define	CPG_FSRCHKSETR10				0xE6150A88	// W	32	Functional safety reset check set register 10
#define	CPG_FSRCHKSETR11				0xE6150A8C	// W	32	Functional safety reset check set register 11
#define	CPG_FSRCHKSETR12				0xE6150AB0	// W	32	Functional safety reset check set register 12
#define	CPG_FSRCHKSETR13				0xE6150AB4	// W	32	Functional safety reset check set register 13
#define	CPG_FSRCHKSETR14				0xE6150AB8	// W	32	Functional safety reset check set register 14
#define	CPG_FSRCHKSETR15				0xE6150ABC	// W	32	Functional safety reset check set register 15
#define	CPG_FSRCHKSETR16				0xE6150B60	// W	32	Functional safety reset check set register 16
#define	CPG_FSRCHKSETR17				0xE6150B64	// W	32	Functional safety reset check set register 17
#define	CPG_FSRCHKSETR18				0xE6150B68	// W	32	Functional safety reset check set register 18
#define	CPG_FSRCHKCLRR0					0xE6150A90	// W	32	Functional safety reset check clear register 0
#define	CPG_FSRCHKCLRR1					0xE6150A94	// W	32	Functional safety reset check clear register 1
#define	CPG_FSRCHKCLRR2					0xE6150A98	// W	32	Functional safety reset check clear register 2
#define	CPG_FSRCHKCLRR3					0xE6150A9C	// W	32	Functional safety reset check clear register 3
#define	CPG_FSRCHKCLRR4					0xE6150AA0	// W	32	Functional safety reset check clear register 4
#define	CPG_FSRCHKCLRR5					0xE6150AA4	// W	32	Functional safety reset check clear register 5
#define	CPG_FSRCHKCLRR6					0xE6150AA8	// W	32	Functional safety reset check clear register 6
#define	CPG_FSRCHKCLRR7					0xE6150AAC	// W	32	Functional safety reset check clear register 7
#define	CPG_FSRCHKCLRR8					0xE6150AB0	// W	32	Functional safety reset check clear register 8
#define	CPG_FSRCHKCLRR9					0xE6150AB4	// W	32	Functional safety reset check clear register 9
#define	CPG_FSRCHKCLRR10				0xE6150AB8	// W	32	Functional safety reset check clear register 10
#define	CPG_FSRCHKCLRR11				0xE6150ABC	// W	32	Functional safety reset check clear register 11
#define	CPG_FSRCHKCLRR12				0xE6150AF0	// W	32	Functional safety reset check clear register 12
#define	CPG_FSRCHKCLRR13				0xE6150AF4	// W	32	Functional safety reset check clear register 13
#define	CPG_FSRCHKCLRR14				0xE6150AF8	// W	32	Functional safety reset check clear register 14
#define	CPG_FSRCHKCLRR15				0xE6150AFC	// W	32	Functional safety reset check clear register 15
#define	CPG_FSRCHKCLRR16				0xE6150B70	// W	32	Functional safety reset check clear register 16
#define	CPG_FSRCHKCLRR17				0xE6150B74	// W	32	Functional safety reset check clear register 17
#define	CPG_FSRCHKCLRR18				0xE6150B78	// W	32	Functional safety reset check clear register 18
#define	CPG_FSSEQCHKR					0xE6150AF0	// R	32	Functional safety Power on sequence Check Register
#define	CPG_FSSEQCHKCSR					0xE6150AF4	// R/W	32	Functional safety Power on sequence Check Control/Status Register


//GPIO
#define	GPIO_IOINTSEL0					0xE6050000	// R/W	32	General IO/interrupt switching register 0
#define	GPIO_INOUTSEL0					0xE6050004	// R/W	32	General input/output switching register 0
#define	GPIO_OUTDT0						0xE6050008	// R/W	32	General output register 0
#define	GPIO_INDT0						0xE605000C	// R	32	General input register 0
#define	GPIO_INTDT0						0xE6050010	// R	32	Interrupt display register 0
#define	GPIO_INTCLR0					0xE6050014	// R/W	32	Interrupt clear register 0
#define	GPIO_INTMSK0					0xE6050018	// R/W	32	Interrupt mask register 0
#define	GPIO_MSKCLR0					0xE605001C	// R/W	32	Interrupt mask clear register 0
#define	GPIO_POSNEG0					0xE6050020	// R/W	32	Positive/negative logic select register 0
#define	GPIO_EDGLEVEL0					0xE6050024	// R/W	32	Edge/level select register 0
#define	GPIO_FILONOFF0					0xE6050028	// R/W	32	Chattering prevention on/off register 0
#define	GPIO_INTMSKS0					0xE6050038	// R/W	32	Interrupt sub mask register 0
#define	GPIO_MSKCLRS0					0xE605003C	// R/W	32	Interrupt sub mask clear register 0
#define	GPIO_OUTDTSEL0					0xE6050040	// R/W	32	Output data select register 0
#define	GPIO_OUTDTH0					0xE6050044	// R/W	32	Output data high register 0
#define	GPIO_OUTDTL0					0xE6050048	// R/W	32	Output data low register 0
#define	GPIO_BOTHEDGE0					0xE605004C	// R/W	32	One edge/both edge select register 0
#define	GPIO_IOINTSEL1					0xE6051000	// R/W	32	General IO/interrupt switching register 1
#define	GPIO_INOUTSEL1					0xE6051004	// R/W	32	General input/output switching register 1
#define	GPIO_OUTDT1						0xE6051008	// R/W	32	General output register 1
#define	GPIO_INDT1						0xE605100C	// R	32	General input register 1
#define	GPIO_INTDT1						0xE6051010	// R	32	Interrupt display register 1
#define	GPIO_INTCLR1					0xE6051014	// R/W	32	Interrupt clear register 1
#define	GPIO_INTMSK1					0xE6051018	// R/W	32	Interrupt mask register 1
#define	GPIO_MSKCLR1					0xE605101C	// R/W	32	Interrupt mask clear register 1
#define	GPIO_POSNEG1					0xE6051020	// R/W	32	Positive/negative logic select register 1
#define	GPIO_EDGLEVEL1					0xE6051024	// R/W	32	Edge/level select register 1
#define	GPIO_FILONOFF1					0xE6051028	// R/W	32	Chattering prevention on/off register 1
#define	GPIO_INTMSKS1					0xE6051038	// R/W	32	Interrupt sub mask register 1
#define	GPIO_MSKCLRS1					0xE605103C	// R/W	32	Interrupt sub mask clear register 1
#define	GPIO_OUTDTSEL1					0xE6051040	// R/W	32	Output data select register 1
#define	GPIO_OUTDTH1					0xE6051044	// R/W	32	Output data high register 1
#define	GPIO_OUTDTL1					0xE6051048	// R/W	32	Output data low register 1
#define	GPIO_BOTHEDGE1					0xE605104C	// R/W	32	One edge/both edge select register 1
#define	GPIO_IOINTSEL2					0xE6052000	// R/W	32	General IO/interrupt switching register 2
#define	GPIO_INOUTSEL2					0xE6052004	// R/W	32	General input/output switching register 2
#define	GPIO_OUTDT2						0xE6052008	// R/W	32	General output register 2
#define	GPIO_INDT2						0xE605200C	// R	32	General input register 2
#define	GPIO_INTDT2						0xE6052010	// R	32	Interrupt display register 2
#define	GPIO_INTCLR2					0xE6052014	// R/W	32	Interrupt clear register 2
#define	GPIO_INTMSK2					0xE6052018	// R/W	32	Interrupt mask register 2
#define	GPIO_MSKCLR2					0xE605201C	// R/W	32	Interrupt mask clear register 2
#define	GPIO_POSNEG2					0xE6052020	// R/W	32	Positive/negative logic select register 2
#define	GPIO_EDGLEVEL2					0xE6052024	// R/W	32	Edge/level select register 2
#define	GPIO_FILONOFF2					0xE6052028	// R/W	32	Chattering prevention on/off register 2
#define	GPIO_INTMSKS2					0xE6052038	// R/W	32	Interrupt sub mask register 2
#define	GPIO_MSKCLRS2					0xE605203C	// R/W	32	Interrupt sub mask clear register 2
#define	GPIO_OUTDTSEL2					0xE6052040	// R/W	32	Output data select register 2
#define	GPIO_OUTDTH2					0xE6052044	// R/W	32	Output data high register 2
#define	GPIO_OUTDTL2					0xE6052048	// R/W	32	Output data low register 2
#define	GPIO_BOTHEDGE2					0xE605204C	// R/W	32	One edge/both edge select register 2
#define	GPIO_IOINTSEL3					0xE6053000	// R/W	32	General IO/interrupt switching register 3
#define	GPIO_INOUTSEL3					0xE6053004	// R/W	32	General input/output switching register 3
#define	GPIO_OUTDT3						0xE6053008	// R/W	32	General output register 3
#define	GPIO_INDT3						0xE605300C	// R	32	General input register 3
#define	GPIO_INTDT3						0xE6053010	// R	32	Interrupt display register 3
#define	GPIO_INTCLR3					0xE6053014	// R/W	32	Interrupt clear register 3
#define	GPIO_INTMSK3					0xE6053018	// R/W	32	Interrupt mask register 3
#define	GPIO_MSKCLR3					0xE605301C	// R/W	32	Interrupt mask clear register 3
#define	GPIO_POSNEG3					0xE6053020	// R/W	32	Positive/negative logic select register 3
#define	GPIO_EDGLEVEL3					0xE6053024	// R/W	32	Edge/level select register 3
#define	GPIO_FILONOFF3					0xE6053028	// R/W	32	Chattering prevention on/off register 3
#define	GPIO_INTMSKS3					0xE6053038	// R/W	32	Interrupt sub mask register 3
#define	GPIO_MSKCLRS3					0xE605303C	// R/W	32	Interrupt sub mask clear register 3
#define	GPIO_OUTDTSEL3					0xE6053040	// R/W	32	Output data select register 3
#define	GPIO_OUTDTH3					0xE6053044	// R/W	32	Output data high register 3
#define	GPIO_OUTDTL3					0xE6053048	// R/W	32	Output data low register 3
#define	GPIO_BOTHEDGE3					0xE605304C	// R/W	32	One edge/both edge select register 3
#define	GPIO_IOINTSEL4					0xE6054000	// R/W	32	General IO/interrupt switching register 4
#define	GPIO_INOUTSEL4					0xE6054004	// R/W	32	General input/output switching register 4
#define	GPIO_OUTDT4						0xE6054008	// R/W	32	General output register 4
#define	GPIO_INDT4						0xE605400C	// R	32	General input register 4
#define	GPIO_INTDT4						0xE6054010	// R	32	Interrupt display register 4
#define	GPIO_INTCLR4					0xE6054014	// R/W	32	Interrupt clear register 4
#define	GPIO_INTMSK4					0xE6054018	// R/W	32	Interrupt mask register 4
#define	GPIO_MSKCLR4					0xE605401C	// R/W	32	Interrupt mask clear register 4
#define	GPIO_POSNEG4					0xE6054020	// R/W	32	Positive/negative logic select register 4
#define	GPIO_EDGLEVEL4					0xE6054024	// R/W	32	Edge/level select register 4
#define	GPIO_FILONOFF4					0xE6054028	// R/W	32	Chattering prevention on/off register 4
#define	GPIO_INTMSKS4					0xE6054038	// R/W	32	Interrupt sub mask register 4
#define	GPIO_MSKCLRS4					0xE605403C	// R/W	32	Interrupt sub mask clear register 4
#define	GPIO_OUTDTSEL4					0xE6054040	// R/W	32	Output data select register 4
#define	GPIO_OUTDTH4					0xE6054044	// R/W	32	Output data high register 4
#define	GPIO_OUTDTL4					0xE6054048	// R/W	32	Output data low register 4
#define	GPIO_BOTHEDGE4					0xE605404C	// R/W	32	One edge/both edge select register 4
#define	GPIO_IOINTSEL5					0xE6055000	// R/W	32	General IO/interrupt switching register 5
#define	GPIO_INOUTSEL5					0xE6055004	// R/W	32	General input/output switching register 5
#define	GPIO_OUTDT5						0xE6055008	// R/W	32	General output register 5
#define	GPIO_INDT5						0xE605500C	// R	32	General input register 5
#define	GPIO_INTDT5						0xE6055010	// R	32	Interrupt display register 5
#define	GPIO_INTCLR5					0xE6055014	// R/W	32	Interrupt clear register 5
#define	GPIO_INTMSK5					0xE6055018	// R/W	32	Interrupt mask register 5
#define	GPIO_MSKCLR5					0xE605501C	// R/W	32	Interrupt mask clear register 5
#define	GPIO_POSNEG5					0xE6055020	// R/W	32	Positive/negative logic select register 5
#define	GPIO_EDGLEVEL5					0xE6055024	// R/W	32	Edge/level select register 5
#define	GPIO_FILONOFF5					0xE6055028	// R/W	32	Chattering prevention on/off register 5
#define	GPIO_INTMSKS5					0xE6055038	// R/W	32	Interrupt sub mask register 5
#define	GPIO_MSKCLRS5					0xE605503C	// R/W	32	Interrupt sub mask clear register 5
#define	GPIO_OUTDTSEL5					0xE6055040	// R/W	32	Output data select register 5
#define	GPIO_OUTDTH5					0xE6055044	// R/W	32	Output data high register 5
#define	GPIO_OUTDTL5					0xE6055048	// R/W	32	Output data low register 5
#define	GPIO_BOTHEDGE5					0xE605504C	// R/W	32	One edge/both edge select register 5
#define	GPIO_IOINTSEL6					0xE6055400	// R/W	32	General IO/interrupt switching register 6
#define	GPIO_INOUTSEL6					0xE6055404	// R/W	32	General input/output switching register 6
#define	GPIO_OUTDT6						0xE6055408	// R/W	32	General output register 6
#define	GPIO_INDT6						0xE605540C	// R	32	General input register 6
#define	GPIO_INTDT6						0xE6055410	// R	32	Interrupt display register 6
#define	GPIO_INTCLR6					0xE6055414	// R/W	32	Interrupt clear register 6
#define	GPIO_INTMSK6					0xE6055418	// R/W	32	Interrupt mask register 6
#define	GPIO_MSKCLR6					0xE605541C	// R/W	32	Interrupt mask clear register 6
#define	GPIO_POSNEG6					0xE6055420	// R/W	32	Positive/negative logic select register 6
#define	GPIO_EDGLEVEL6					0xE6055424	// R/W	32	Edge/level select register 6
#define	GPIO_FILONOFF6					0xE6055428	// R/W	32	Chattering prevention on/off register 6
#define	GPIO_INTMSKS6					0xE6055438	// R/W	32	Interrupt sub mask register 6
#define	GPIO_MSKCLRS6					0xE605543C	// R/W	32	Interrupt sub mask clear register 6
#define	GPIO_OUTDTSEL6					0xE6055440	// R/W	32	Output data select register 6
#define	GPIO_OUTDTH6					0xE6055444	// R/W	32	Output data high register 6
#define	GPIO_OUTDTL6					0xE6055448	// R/W	32	Output data low register 6
#define	GPIO_BOTHEDGE6					0xE605544C	// R/W	32	One edge/both edge select register 6
#define	GPIO_IOINTSEL7					0xE6055800	// R/W	32	General IO/interrupt switching register 7
#define	GPIO_INOUTSEL7					0xE6055804	// R/W	32	General input/output switching register 7
#define	GPIO_OUTDT7						0xE6055808	// R/W	32	General output register 7
#define	GPIO_INDT7						0xE605580C	// R	32	General input register 7
#define	GPIO_INTDT7						0xE6055810	// R	32	Interrupt display register 7
#define	GPIO_INTCLR7					0xE6055814	// R/W	32	Interrupt clear register 7
#define	GPIO_INTMSK7					0xE6055818	// R/W	32	Interrupt mask register 7
#define	GPIO_MSKCLR7					0xE605581C	// R/W	32	Interrupt mask clear register 7
#define	GPIO_POSNEG7					0xE6055820	// R/W	32	Positive/negative logic select register 7
#define	GPIO_EDGLEVEL7					0xE6055824	// R/W	32	Edge/level select register 7
#define	GPIO_FILONOFF7					0xE6055828	// R/W	32	Chattering prevention on/off register 7
#define	GPIO_INTMSKS7					0xE6055838	// R/W	32	Interrupt sub mask register 7
#define	GPIO_MSKCLRS7					0xE605583C	// R/W	32	Interrupt sub mask clear register 7
#define	GPIO_OUTDTSEL7					0xE6055840	// R/W	32	Output data select register 7
#define	GPIO_OUTDTH7					0xE6055844	// R/W	32	Output data high register 7
#define	GPIO_OUTDTL7					0xE6055848	// R/W	32	Output data low register 7
#define	GPIO_BOTHEDGE7					0xE605584C	// R/W	32	One edge/both edge select register 7


//LBSC.h
#define	LBSC_CS0CTRL					0xEE220200	// R/W	32	Area 0 control register
#define	LBSC_CS1CTRL					0xEE220204	// R/W	32	Area 1 control register
#define	LBSC_CSWCR0						0xEE220230	// R/W	32	Area 0 RD/WE pulse control register
#define	LBSC_CSWCR1						0xEE220234	// R/W	32	Area 1 RD/WE pulse control register
#define	LBSC_CSPWCR0					0xEE220280	// R/W	32	Area 0 external wait control register
#define	LBSC_CSPWCR1					0xEE220284	// R/W	32	Area 1 external wait control register
#define	LBSC_EXWTSYNC					0xEE2202A0	// R/W	32	External wait input control register
#define	LBSC_CS0BSTCTL					0xEE2202B0	// R/W	32	Area 0 burst control register
#define	LBSC_CS0BTPH					0xEE2202B4	// R/W	32	Area 0 burst pitch set register
#define	LBSC_CS1GDST					0xEE2202C0	// R/W	32	Area 1 guard setting register
#define	LBSC_BCINTSR					0xEE220330	// R	32	BSC interrupt source status register
#define	LBSC_BCINTCR					0xEE220334	// -/WC1	32	BSC interrupt source clear register
#define	LBSC_BCINTMR					0xEE220338	// R/W	32	BSC interrupt enable register
#define	LBSC_EXWTSTS					0xEE220344	// R	32	External wait status register
#define	LBSC_EXBCT						0xEE2203C0	// R/W	32	EX-BUS wait timeout detection base counter register
#define	LBSC_EXTCT						0xEE2203C4	// R/W	32	EX-BUS wait timeout detection counter register
#define	LBSC_EXTSR						0xEE220010	// R/WC1	32	EX-BUS wait timeout detection access source indication register
#define	LBSC_EXTADR						0xEE220014	// R/W	32	EX-BUS wait timeout detection address indication register


//MSTPRST
#define	CPG_MSTPSR0						0xE6150030	// R	32	Module stop status register 0
#define	CPG_MSTPSR1						0xE6150038	// R	32	Module stop status register 1
#define	CPG_MSTPSR2						0xE6150040	// R	32	Module stop status register 2
#define	CPG_MSTPSR3						0xE6150048	// R	32	Module stop status register 3
#define	CPG_MSTPSR4						0xE615004C	// R	32	Module stop status register 4
#define	CPG_MSTPSR5						0xE615003C	// R	32	Module stop status register 5
#define	CPG_MSTPSR6						0xE61501C0	// R	32	Module stop status register 6
#define	CPG_MSTPSR7						0xE61501C4	// R	32	Module stop status register 7
#define	CPG_MSTPSR8						0xE61509A0	// R	32	Module stop status register 8
#define	CPG_MSTPSR9						0xE61509A4	// R	32	Module stop status register 9
#define	CPG_MSTPSR10					0xE61509A8	// R	32	Module stop status register 10
#define	CPG_MSTPSR11					0xE61509AC	// R	32	Module stop status register 11
#define	CPG_RMSTPCR0					0xE6150110	// R/W	32	Realtime module stop control register 0
#define	CPG_RMSTPCR1					0xE6150114	// R/W	32	Realtime module stop control register 1
#define	CPG_RMSTPCR2					0xE6150118	// R/W	32	Realtime module stop control register 2
#define	CPG_RMSTPCR3					0xE615011C	// R/W	32	Realtime module stop control register 3
#define	CPG_RMSTPCR4					0xE6150120	// R/W	32	Realtime module stop control register 4
#define	CPG_RMSTPCR5					0xE6150124	// R/W	32	Realtime module stop control register 5
#define	CPG_RMSTPCR6					0xE6150128	// R/W	32	Realtime module stop control register 6
#define	CPG_RMSTPCR7					0xE615012C	// R/W	32	Realtime module stop control register 7
#define	CPG_RMSTPCR8					0xE6150980	// R/W	32	Realtime module stop control register 8
#define	CPG_RMSTPCR9					0xE6150984	// R/W	32	Realtime module stop control register 9
#define	CPG_RMSTPCR10					0xE6150988	// R/W	32	Realtime module stop control register 10
#define	CPG_RMSTPCR11					0xE615098C	// R/W	32	Realtime module stop control register 11
#define	CPG_SMSTPCR0					0xE6150130	// R/W	32	System module stop control register 0
#define	CPG_SMSTPCR1					0xE6150134	// R/W	32	System module stop control register 1
#define	CPG_SMSTPCR2					0xE6150138	// R/W	32	System module stop control register 2
#define	CPG_SMSTPCR3					0xE615013C	// R/W	32	System module stop control register 3
#define	CPG_SMSTPCR4					0xE6150140	// R/W	32	System module stop control register 4
#define	CPG_SMSTPCR5					0xE6150144	// R/W	32	System module stop control register 5
#define	CPG_SMSTPCR6					0xE6150148	// R/W	32	System module stop control register 6
#define	CPG_SMSTPCR7					0xE615014C	// R/W	32	System module stop control register 7
#define	CPG_SMSTPCR8					0xE6150990	// R/W	32	System module stop control register 8
#define	CPG_SMSTPCR9					0xE6150994	// R/W	32	System module stop control register 9
#define	CPG_SMSTPCR10					0xE6150998	// R/W	32	System module stop control register 10
#define	CPG_SMSTPCR11					0xE615099C	// R/W	32	System module stop control register 11
#define	CPG_SRCR0						0xE61500A0	// R/W	32	Software reset register 0 
#define	CPG_SRCR1						0xE61500A8	// R/W	32	Software reset register 1 
#define	CPG_SRCR2						0xE61500B0	// R/W	32	Software reset register 2 
#define	CPG_SRCR3						0xE61500B8	// R/W	32	Software reset register 3 
#define	CPG_SRCR4						0xE61500BC	// R/W	32	Software reset register 4 
#define	CPG_SRCR5						0xE61500C4	// R/W	32	Software reset register 5 
#define	CPG_SRCR6						0xE61501C8	// R/W	32	Software reset register 6 
#define	CPG_SRCR7						0xE61501CC	// R/W	32	Software reset register 7 
#define	CPG_SRCR8						0xE6150920	// R/W	32	Software reset register 8 
#define	CPG_SRCR9						0xE6150924	// R/W	32	Software reset register 9 
#define	CPG_SRCR10						0xE6150928	// R/W	32	Software reset register 10 
#define	CPG_SRCR11						0xE615092C	// R/W	32	Software reset register 11 
#define	CPG_SRSTCLR0					0xE6150940	// W	32	Software reset clearing register 0
#define	CPG_SRSTCLR1					0xE6150944	// W	32	Software reset clearing register 1
#define	CPG_SRSTCLR2					0xE6150948	// W	32	Software reset clearing register 2
#define	CPG_SRSTCLR3					0xE615094C	// W	32	Software reset clearing register 3
#define	CPG_SRSTCLR4					0xE6150950	// W	32	Software reset clearing register 4
#define	CPG_SRSTCLR5					0xE6150954	// W	32	Software reset clearing register 5
#define	CPG_SRSTCLR6					0xE6150958	// W	32	Software reset clearing register 6
#define	CPG_SRSTCLR7					0xE615095C	// W	32	Software reset clearing register 7
#define	CPG_SRSTCLR8					0xE6150960	// W	32	Software reset clearing register 8
#define	CPG_SRSTCLR9					0xE6150964	// W	32	Software reset clearing register 9
#define	CPG_SRSTCLR10					0xE6150968	// W	32	Software reset clearing register 10
#define	CPG_SRSTCLR11					0xE615096C	// W	32	Software reset clearing register 11
#define	CPG_SAMSTPCR0					0xE6150C20	// R/W	32	Safety Module Stop Control Register 0
#define	CPG_SAMSTPCR1					0xE6150C24	// R/W	32	Safety Module Stop Control Register 1
#define	CPG_SAMSTPCR2					0xE6150C28	// R/W	32	Safety Module Stop Control Register 2
#define	CPG_SAMSTPCR3					0xE6150C2C	// R/W	32	Safety Module Stop Control Register 3
#define	CPG_SAMSTPCR4					0xE6150C30	// R/W	32	Safety Module Stop Control Register 4
#define	CPG_SAMSTPCR5					0xE6150C34	// R/W	32	Safety Module Stop Control Register 5
#define	CPG_SAMSTPCR6					0xE6150C38	// R/W	32	Safety Module Stop Control Register 6
#define	CPG_SAMSTPCR7					0xE6150C3C	// R/W	32	Safety Module Stop Control Register 7
#define	CPG_SAMSTPCR8					0xE6150C40	// R/W	32	Safety Module Stop Control Register 8
#define	CPG_SAMSTPCR9					0xE6150C44	// R/W	32	Safety Module Stop Control Register 9
#define	CPG_SAMSTPCR10					0xE6150C48	// R/W	32	Safety Module Stop Control Register 10
#define	CPG_SAMSTPCR11					0xE6150C4C	// R/W	32	Safety Module Stop Control Register 11
#define	CPG_SASRSTECR0					0xE6150C80	// R/W	32	Safety Software Reset Access Enable Control Register 0
#define	CPG_SASRSTECR1					0xE6150C84	// R/W	32	Safety Software Reset Access Enable Control Register 1
#define	CPG_SASRSTECR2					0xE6150C88	// R/W	32	Safety Software Reset Access Enable Control Register 2
#define	CPG_SASRSTECR3					0xE6150C8C	// R/W	32	Safety Software Reset Access Enable Control Register 3
#define	CPG_SASRSTECR4					0xE6150C90	// R/W	32	Safety Software Reset Access Enable Control Register 4
#define	CPG_SASRSTECR5					0xE6150C94	// R/W	32	Safety Software Reset Access Enable Control Register 5
#define	CPG_SASRSTECR6					0xE6150C98	// R/W	32	Safety Software Reset Access Enable Control Register 6
#define	CPG_SASRSTECR7					0xE6150C9C	// R/W	32	Safety Software Reset Access Enable Control Register 7
#define	CPG_SASRSTECR8					0xE6150CA0	// R/W	32	Safety Software Reset Access Enable Control Register 8
#define	CPG_SASRSTECR9					0xE6150CA4	// R/W	32	Safety Software Reset Access Enable Control Register 9
#define	CPG_SASRSTECR10					0xE6150CA8	// R/W	32	Safety Software Reset Access Enable Control Register 10
#define	CPG_SASRSTECR11					0xE6150CAC	// R/W	32	Safety Software Reset Access Enable Control Register 11
#define	CPG_SAPTCSR						0xE6150C00	// R/W	32	Safety Protect Control/Status Register
#define	CPG_SAERMIDR					0xE6150C04	// R	32	Safety Error Master ID Register
#define	CPG_SAERADR						0xE6150C08	// R	32	Safety Error Address Regsiter



//PFC
#define	PFC_PMMR						0xE6060000	// R/W	32	LSI Multiplexed Pin Setting Mask Register
#define	PFC_GPSR0						0xE6060100	// R/W	32	GPIO/Peripheral Function Select register 0
#define	PFC_GPSR1						0xE6060104	// R/W	32	GPIO/Peripheral Function Select register 1
#define	PFC_GPSR2						0xE6060108	// R/W	32	GPIO/Peripheral_Function Select register 2
#define	PFC_GPSR3						0xE606010C	// R/W	32	GPIO/Peripheral Function Select register 3
#define	PFC_GPSR4						0xE6060110	// R/W	32	GPIO/Peripheral Function Select register 4
#define	PFC_GPSR5						0xE6060114	// R/W	32	GPIO/Peripheral Function Select register 5
#define	PFC_GPSR6						0xE6060118	// R/W	32	GPIO/Peripheral Function Select register 6
#define	PFC_GPSR7						0xE606011C	// R/W	32	GPIO/Peripheral Function Select register 7
#define	PFC_IPSR0						0xE6060200	// R/W	32	Peripheral Function Select register 0
#define	PFC_IPSR1						0xE6060204	// R/W	32	Peripheral Function Select register 1
#define	PFC_IPSR2						0xE6060208	// R/W	32	Peripheral Function Select register 2
#define	PFC_IPSR3						0xE606020C	// R/W	32	Peripheral Function Select register 3
#define	PFC_IPSR4						0xE6060210	// R/W	32	Peripheral Function Select register 4
#define	PFC_IPSR5						0xE6060214	// R/W	32	Peripheral Function Select register 5
#define	PFC_IPSR6						0xE6060218	// R/W	32	Peripheral Function Select register 6
#define	PFC_IPSR7						0xE606021C	// R/W	32	Peripheral Function Select register 7
#define	PFC_IPSR8						0xE6060220	// R/W	32	Peripheral Function Select register 8
#define	PFC_IPSR9						0xE6060224	// R/W	32	Peripheral Function Select register 9
#define	PFC_IPSR10						0xE6060228	// R/W	32	Peripheral Function Select register 10
#define	PFC_IPSR11						0xE606022C	// R/W	32	Peripheral Function Select register 11
#define	PFC_IPSR12						0xE6060230	// R/W	32	Peripheral Function Select register 12
#define	PFC_IPSR13						0xE6060234	// R/W	32	Peripheral Function Select register 13
#define	PFC_IPSR14						0xE6060238	// R/W	32	Peripheral Function Select register 14
#define	PFC_IPSR15						0xE606023C	// R/W	32	Peripheral Function Select register 15
#define	PFC_IPSR16						0xE6060240	// R/W	32	Peripheral Function Select register 16
#define	PFC_IPSR17						0xE6060244	// R/W	32	Peripheral Function Select register 17
#define	PFC_IPSR18						0xE6060248	// R/W	32	Peripheral Function Select register 18
#define	PFC_DRVCTRL0					0xE6060300	// R/W	32	DRV control register0
#define	PFC_DRVCTRL1					0xE6060304	// R/W	32	DRV control register1
#define	PFC_DRVCTRL2					0xE6060308	// R/W	32	DRV control register2
#define	PFC_DRVCTRL3					0xE606030C	// R/W	32	DRV control register3
#define	PFC_DRVCTRL4					0xE6060310	// R/W	32	DRV control register4
#define	PFC_DRVCTRL5					0xE6060314	// R/W	32	DRV control register5
#define	PFC_DRVCTRL6					0xE6060318	// R/W	32	DRV control register6
#define	PFC_DRVCTRL7					0xE606031C	// R/W	32	DRV control register7
#define	PFC_DRVCTRL8					0xE6060320	// R/W	32	DRV control register8
#define	PFC_DRVCTRL9					0xE6060324	// R/W	32	DRV control register9
#define	PFC_DRVCTRL10					0xE6060328	// R/W	32	DRV control register10
#define	PFC_DRVCTRL11					0xE606032C	// R/W	32	DRV control register11
#define	PFC_DRVCTRL12					0xE6060330	// R/W	32	DRV control register12
#define	PFC_DRVCTRL13					0xE6060334	// R/W	32	DRV control register13
#define	PFC_DRVCTRL14					0xE6060338	// R/W	32	DRV control register14
#define	PFC_DRVCTRL15					0xE606033C	// R/W	32	DRV control register15
#define	PFC_DRVCTRL16					0xE6060340	// R/W	32	DRV control register16
#define	PFC_DRVCTRL17					0xE6060344	// R/W	32	DRV control register17
#define	PFC_DRVCTRL18					0xE6060348	// R/W	32	DRV control register18
#define	PFC_DRVCTRL19					0xE606034C	// R/W	32	DRV control register19
#define	PFC_DRVCTRL20					0xE6060350	// R/W	32	DRV control register20
#define	PFC_DRVCTRL21					0xE6060354	// R/W	32	DRV control register21
#define	PFC_DRVCTRL22					0xE6060358	// R/W	32	DRV control register22
#define	PFC_DRVCTRL23					0xE606035C	// R/W	32	DRV control register23
#define	PFC_DRVCTRL24					0xE6060360	// R/W	32	DRV control register24
#define	PFC_POCCTRL0					0xE6060380	// R/W	32	POC control register0
#define	PFC_TDSELCTRL0					0xE60603C0	// R/W	32	TDSEL control register0
#define	PFC_IOCTRL						0xE60603E0	// R/W	32	IO cell control for IICDVFS
#define	PFC_FUSEMON						0xE60603E4	// R	32	Fuse Monitor register0
#define	PFC_PUEN0						0xE6060400	// R/W	32	LSI pin pull-enable register 0
#define	PFC_PUEN1						0xE6060404	// R/W	32	LSI pin pull-enable register 1
#define	PFC_PUEN2						0xE6060408	// R/W	32	LSI pin pull-enable register 2
#define	PFC_PUEN3						0xE606040C	// R/W	32	LSI pin pull-enable register 3
#define	PFC_PUEN4						0xE6060410	// R/W	32	LSI pin pull-enable register 4
#define	PFC_PUEN5						0xE6060414	// R/W	32	LSI pin pull-enable register 5
#define	PFC_PUEN6						0xE6060418	// R/W	32	LSI pin pull-enable register 6
#define	PFC_PUD0						0xE6060440	// R/W	32	LSI pin pull-up/down control register 0
#define	PFC_PUD1						0xE6060444	// R/W	32	LSI pin pull-up/down control register 1
#define	PFC_PUD2						0xE6060448	// R/W	32	LSI pin pull-up/down control register 2
#define	PFC_PUD3						0xE606044C	// R/W	32	LSI pin pull-up/down control register 3
#define	PFC_PUD4						0xE6060450	// R/W	32	LSI pin pull-up/down control register 4
#define	PFC_PUD5						0xE6060454	// R/W	32	LSI pin pull-up/down control register 5
#define	PFC_PUD6						0xE6060458	// R/W	32	LSI pin pull-up/down control register 6
#define	PFC_MOD_SEL0					0xE6060500	// R/W	32	Module select register 0
#define	PFC_MOD_SEL1					0xE6060504	// R/W	32	Module select register 1
#define	PFC_MOD_SEL2					0xE6060508	// R/W	32	Module select register 2


//RPC
#define	RPC_CMNCR						0xEE200000	// R/W
#define	RPC_SSLDR						0xEE200004	// R/W
#define	RPC_DRCR						0xEE20000C	// R/W
#define	RPC_DRCMR						0xEE200010	// R/W
#define	RPC_DREAR						0xEE200014	// R/W
#define	RPC_DROPR						0xEE200018	// R/W
#define	RPC_DRENR						0xEE20001C	// R/W
#define	RPC_SMCR						0xEE200020	// R/W
#define	RPC_SMCMR						0xEE200024	// R/W
#define	RPC_SMADR						0xEE200028	// R/W
#define	RPC_SMOPR						0xEE20002C	// R/W
#define	RPC_SMENR						0xEE200030	// R/W
#define	RPC_SMRDR0						0xEE200038	// R
#define	RPC_SMRDR1						0xEE20003C	// R
#define	RPC_SMWDR0						0xEE200040	// R/W
#define	RPC_SMWDR1						0xEE200044	// R/W
#define	RPC_CMNSR						0xEE200048	// R
#define	RPC_DRDMCR						0xEE200058	// R/W
#define	RPC_DRDRENR						0xEE20005C	// R/W
#define	RPC_SMDMCR						0xEE200060	// R/W
#define	RPC_SMDRENR						0xEE200064	// R/W
#define	RPC_PHYCNT						0xEE20007C	// R/W
#define	RPC_OFFSET1						0xEE200080	// 
#define	RPC_PHYINT						0xEE200088	// R/W
#define	RPC_WRBUF						0xEE208000	// W	RPC Write buffer (Access size=4/8/16/32/64Byte)


//RST
#define	RST_MODEMR						0xE6160060	// R	32	Mode Monitor Register
#define	RST_CA57RESCNT					0xE6160040	// R/W	32	CA57 Reset Control Register
#define	RST_CA53RESCNT					0xE6160044	// R/W	32	CA53 Reset Control Register
#define	RST_WDTRSTCR					0xE6160054	// R/W	32	Watchdog Timer Reset Control Register
#define	RST_RSTOUTCR					0xE6160058	// R/W	32	PRESETOUT# Control Register
#define	RST_SBAR						0xE6160010	// R/W	32	SYS Boot Address Register
#define	RST_SBAR2						0xE6160014	// R/W	32	SYS Boot Address Register2
#define	RST_CA53BAR						0xE6160030	// R/W	32	CA53 Boot Address Register
#define	RST_CA53BAR2					0xE6160034	// R/W	32	CA53 Boot Address Register2
#define	RST_CA57BAR						0xE6160020	// R/W	32	CA57 Boot Address Register
#define	RST_CA57BAR2					0xE6160024	// R/W	32	CA57 Boot Address Register2
#define	RST_CR7BAR						0xE6160070	// R/W	32	CR7 Boot Address Register
#define	RST_CR7BAR2						0xE6160074	// R/W	32	CR7 Boot Address Register2
#define	RST_CA57CPU0BARH				0xE61600C0	// R/W	32	CA57 CPU0 Boot Address Register for 64-bit mode H
#define	RST_CA57CPU0BARL				0xE61600C4	// R/W	32	CA57 CPU0 Boot Address Register for 64-bit mode L
#define	RST_CA57CPU1BARH				0xE61600D0	// R/W	32	CA57 CPU1 Boot Address Register for 64-bit mode H
#define	RST_CA57CPU1BARL				0xE61600D4	// R/W	32	CA57 CPU1 Boot Address Register for 64-bit mode L
#define	RST_CA57CPU2BARH				0xE61600E0	// R/W	32	CA57 CPU2 Boot Address Register for 64-bit mode H
#define	RST_CA57CPU2BARL				0xE61600E4	// R/W	32	CA57 CPU2 Boot Address Register for 64-bit mode L
#define	RST_CA57CPU3BARH				0xE61600F0	// R/W	32	CA57 CPU3 Boot Address Register for 64-bit mode H
#define	RST_CA57CPU3BARL				0xE61600F4	// R/W	32	CA57 CPU3 Boot Address Register for 64-bit mode L
#define	RST_CA53CPU0BARH				0xE6160080	// R/W	32	CA53 CPU0 Boot Address Register for 64-bit mode H
#define	RST_CA53CPU0BARL				0xE6160084	// R/W	32	CA53 CPU0 Boot Address Register for 64-bit mode L
#define	RST_CA53CPU1BARH				0xE6160090	// R/W	32	CA53 CPU1 Boot Address Register for 64-bit mode H
#define	RST_CA53CPU1BARL				0xE6160094	// R/W	32	CA53 CPU1 Boot Address Register for 64-bit mode L
#define	RST_CA53CPU2BARH				0xE61600A0	// R/W	32	CA53 CPU2 Boot Address Register for 64-bit mode H
#define	RST_CA53CPU2BARL				0xE61600A4	// R/W	32	CA53 CPU2 Boot Address Register for 64-bit mode L
#define	RST_CA53CPU3BARH				0xE61600B0	// R/W	32	CA53 CPU3 Boot Address Register for 64-bit mode H
#define	RST_CA53CPU3BARL				0xE61600B4	// R/W	32	CA53 CPU3 Boot Address Register for 64-bit mode L
#define	RST_APBSFTYCHKR					0xE616005C	// R/W	32	APB bus Safety Check Register
#define	RST_STBCHR0						0xE6160100	// R/W	32	Standby Flag Register 0
#define	RST_STBCHR1						0xE6160104	// R/W	32	Standby Flag Register 1
#define	RST_STBCHR2						0xE6160108	// R/W	32	Standby Flag Register 2
#define	RST_STBCHR3						0xE616010C	// R/W	32	Standby Flag Register 3
#define	RST_STBCHR4						0xE6160120	// R/W	32	Standby Flag Register 4
#define	RST_STBCHR5						0xE6160124	// R/W	32	Standby Flag Register 5
#define	RST_STBCHR6						0xE6160128	// R/W	32	Standby Flag Register 6
#define	RST_STBCHR7						0xE616012C	// R/W	32	Standby Flag Register 7
#define	RST_SRESCR						0xE6160110	// R/W	32	Soft Power On Reset Control Register
#define	RST_RRSTFR						0xE6160114	// R/W	32	RT Reset Flag Register
#define	RST_SRSTFR						0xE6160118	// R/W	32	SYS Reset Flag Register
#define	RST_SCPTCSR						0xE6160180	// R/W	32	Secure Protect Control/Status Register
#define	RST_SCERMIDR					0xE6160184	// R	32	Secure Error Master ID Register
#define	RST_SCERADR						0xE6160188	// R	32	Secure Error Address Register
#define	RST_SAPTCSR						0xE6160190	// R/W	32	Safety Protect Control/Status Register
#define	RST_SAERMIDR					0xE6160194	// R	32	Safety Error Master ID Register
#define	RST_SAERADR						0xE6160198	// R	32	Safety Error Address Register


//RWDT
#define	RWDT_RWTCNT						0xE6020000	// R/W	16/32*	RCLK watchdog timer counter
#define	RWDT_RWTCSRA					0xE6020004	// R/W	8/32*	RCLK watchdog timer control/status register A
#define	RWDT_RWTCSRB					0xE6020008	// R/W	8/32*	RCLK watchdog timer control/status register B




//SCIF2
#define	SCIF2_SCSMR						0xE6E88000	// R/W	16	Serial mode register
#define	SCIF2_SCBRR						0xE6E88004	// R/W	8	Bit rate register
#define	SCIF2_SCSCR						0xE6E88008	// R/W	16	Serial control register
#define	SCIF2_SCFTDR					0xE6E8800C	// W	8	Transmit FIFO data register
#define	SCIF2_SCFSR						0xE6E88010	// R/W	16	Serial status register
#define	SCIF2_SCFRDR					0xE6E88014	// R	8	Receive FIFO data register
#define	SCIF2_SCFCR						0xE6E88018	// R/W	16	FIFO control register
#define	SCIF2_SCFDR						0xE6E8801C	// R	16	FIFO data count register
#define	SCIF2_SCSPTR					0xE6E88020	// R/W	16	Serial port register
#define	SCIF2_SCLSR						0xE6E88024	// R/W	16	Line status register
#define	SCIF2_DL						0xE6E88030	// R/W	16	Frequency division register 
#define	SCIF2_CKS						0xE6E88034	// R/W	16	Clock Select register 


//SYSDMAC
#define	SYSDMAC_DMAISTA_0				0xE6700020	// R	32	DMA interrupt status register (for channels 0 to 15)
#define	SYSDMAC_DMASEC_0				0xE6700030	// R/W	32	DMA secure control register (for channels 0 to 15)
#define	SYSDMAC_DMAOR_0					0xE6700060	// R/W	16	DMA operation register (for channels 0 to 15)
#define	SYSDMAC_DMACHCLR_0				0xE6700080	// W	32	DMA channel clear register (for channels 0 to 15)
#define	SYSDMAC_DMADPSEC_0				0xE67000A0	// R/W	32	DPRAM secure control register (for channels 0 to 15)
#define	SYSDMAC_DMASAR_0				0xE6708000	// R/W	32	DMA source address register_0
#define	SYSDMAC_DMADAR_0				0xE6708004	// R/W	32	DMA destination address register_0
#define	SYSDMAC_DMATCR_0				0xE6708008	// R/W	32	DMA transfer count register_0
#define	SYSDMAC_DMATSR_0				0xE6708028	// R/W	32	DMA transfer size register_0
#define	SYSDMAC_DMACHCR_0				0xE670800C	// R/W	32	DMA channel control register_0
#define	SYSDMAC_DMATCRB_0				0xE6708018	// R/W	32	DMA transfer count register B_0
#define	SYSDMAC_DMATSRB_0				0xE6708038	// R/W	32	DMA transfer size register B_0
#define	SYSDMAC_DMACHCRB_0				0xE670801C	// R/W	32	DMA channel control register B_0
#define	SYSDMAC_DMARS_0					0xE6708040	// R/W	16	DMA extended resource selector_0
#define	SYSDMAC_DMABUFCR_0				0xE6708048	// R/W	32	DMA buffer control register_0
#define	SYSDMAC_DMADPBASE_0				0xE6708050	// R/W	32	DMA descriptor base address register_0
#define	SYSDMAC_DMADPCR_0				0xE6708054	// R/W	32	DMA descriptor control register_0
#define	SYSDMAC_DMAFIXSAR_0				0xE6708010	// R/W	32	DMA fixed source address register_0
#define	SYSDMAC_DMAFIXDAR_0				0xE6708014	// R/W	32	DMA fixed destination address register_0
#define	SYSDMAC_DMAFIXDPBASE_0			0xE6708060	// R/W	32	DMA fixed descriptor base address register_0
#define	SYSDMAC_DMASAR_1				0xE6708080	// R/W	32	DMA source address register_1
#define	SYSDMAC_DMADAR_1				0xE6708084	// R/W	32	DMA destination address register_1
#define	SYSDMAC_DMATCR_1				0xE6708088	// R/W	32	DMA transfer count register_1
#define	SYSDMAC_DMATSR_1				0xE67080A8	// R/W	32	DMA transfer size register_1
#define	SYSDMAC_DMACHCR_1				0xE670808C	// R/W	32	DMA channel control register_1
#define	SYSDMAC_DMATCRB_1				0xE6708098	// R/W	32	DMA transfer count register B_1
#define	SYSDMAC_DMATSRB_1				0xE67080B8	// R/W	32	DMA transfer size register B_1
#define	SYSDMAC_DMACHCRB_1				0xE670809C	// R/W	32	DMA channel control register B_1
#define	SYSDMAC_DMARS_1					0xE67080C0	// R/W	16	DMA extended resource selector_1
#define	SYSDMAC_DMABUFCR_1				0xE67080C8	// R/W	32	DMA buffer control register_1
#define	SYSDMAC_DMADPBASE_1				0xE67080D0	// R/W	32	DMA descriptor base address register_1
#define	SYSDMAC_DMADPCR_1				0xE67080D4	// R/W	32	DMA descriptor control register_1
#define	SYSDMAC_DMAFIXDPBASE_1			0xE67080E0	// R/W	32	DMA fixed descriptor base address register_1
#define	SYSDMAC_DMAFIXSAR_1				0xE6708090	// R/W	32	DMA fixed source address register_1
#define	SYSDMAC_DMAFIXDAR_1				0xE6708094	// R/W	32	DMA fixed destination address register_1
#define	SYSDMAC_DMASAR_2				0xE6708100	// R/W	32	DMA source address register_2
#define	SYSDMAC_DMADAR_2				0xE6708104	// R/W	32	DMA destination address register_2
#define	SYSDMAC_DMATCR_2				0xE6708108	// R/W	32	DMA transfer count register_2
#define	SYSDMAC_DMATSR_2				0xE6708128	// R/W	32	DMA transfer size register_2
#define	SYSDMAC_DMACHCR_2				0xE670810C	// R/W	32	DMA channel control register_2
#define	SYSDMAC_DMATCRB_2				0xE6708118	// R/W	32	DMA transfer count register B_2
#define	SYSDMAC_DMATSRB_2				0xE6708138	// R/W	32	DMA transfer size register B_2
#define	SYSDMAC_DMACHCRB_2				0xE670811C	// R/W	32	DMA channel control register B_2
#define	SYSDMAC_DMARS_2					0xE6708140	// R/W	16	DMA extended resource selector_2
#define	SYSDMAC_DMABUFCR_2				0xE6708148	// R/W	32	DMA buffer control register_2
#define	SYSDMAC_DMADPBASE_2				0xE6708150	// R/W	32	DMA descriptor base address register_2
#define	SYSDMAC_DMADPCR_2				0xE6708154	// R/W	32	DMA descriptor control register_2
#define	SYSDMAC_DMAFIXSAR_2				0xE6708110	// R/W	32	DMA fixed source address register_2
#define	SYSDMAC_DMAFIXDAR_2				0xE6708114	// R/W	32	DMA fixed destination address register_2
#define	SYSDMAC_DMAFIXDPBASE_2			0xE6708160	// R/W	32	DMA fixed descriptor base address register_2
#define	SYSDMAC_DMASAR_3				0xE6708180	// R/W	32	DMA source address register_3
#define	SYSDMAC_DMADAR_3				0xE6708184	// R/W	32	DMA destination address register_3
#define	SYSDMAC_DMATCR_3				0xE6708188	// R/W	32	DMA transfer count register_3
#define	SYSDMAC_DMATSR_3				0xE67081A8	// R/W	32	DMA transfer size register_3
#define	SYSDMAC_DMACHCR_3				0xE670818C	// R/W	32	DMA channel control register_3
#define	SYSDMAC_DMATCRB_3				0xE6708198	// R/W	32	DMA transfer count register B_3
#define	SYSDMAC_DMATSRB_3				0xE67081B8	// R/W	32	DMA transfer size register B_3
#define	SYSDMAC_DMACHCRB_3				0xE670819C	// R/W	32	DMA channel control register B_3
#define	SYSDMAC_DMARS_3					0xE67081C0	// R/W	16	DMA extended resource selector_3
#define	SYSDMAC_DMABUFCR_3				0xE67081C8	// R/W	32	DMA buffer control register_3
#define	SYSDMAC_DMADPBASE_3				0xE67081D0	// R/W	32	DMA descriptor base address register_3
#define	SYSDMAC_DMADPCR_3				0xE67081D4	// R/W	32	DMA descriptor control register_3
#define	SYSDMAC_DMAFIXSAR_3				0xE6708190	// R/W	32	DMA fixed source address register_3
#define	SYSDMAC_DMAFIXDAR_3				0xE6708194	// R/W	32	DMA fixed destination address register_3
#define	SYSDMAC_DMAFIXDPBASE_3			0xE67081E0	// R/W	32	DMA fixed descriptor base address register_3
#define	SYSDMAC_DMASAR_4				0xE6708200	// R/W	32	DMA source address register_4
#define	SYSDMAC_DMADAR_4				0xE6708204	// R/W	32	DMA destination address register_4
#define	SYSDMAC_DMATCR_4				0xE6708208	// R/W	32	DMA transfer count register_4
#define	SYSDMAC_DMATSR_4				0xE6708228	// R/W	32	DMA transfer size register_4
#define	SYSDMAC_DMACHCR_4				0xE670820C	// R/W	32	DMA channel control register_4
#define	SYSDMAC_DMATCRB_4				0xE6708218	// R/W	32	DMA transfer count register B_4
#define	SYSDMAC_DMATSRB_4				0xE6708238	// R/W	32	DMA transfer size register B_4
#define	SYSDMAC_DMACHCRB_4				0xE670821C	// R/W	32	DMA channel control register B_4
#define	SYSDMAC_DMARS_4					0xE6708240	// R/W	16	DMA extended resource selector_4
#define	SYSDMAC_DMABUFCR_4				0xE6708248	// R/W	32	DMA buffer control register_4
#define	SYSDMAC_DMADPBASE_4				0xE6708250	// R/W	32	DMA descriptor base address register_4
#define	SYSDMAC_DMADPCR_4				0xE6708254	// R/W	32	DMA descriptor control register_4
#define	SYSDMAC_DMAFIXSAR_4				0xE6708210	// R/W	32	DMA fixed source address register_4
#define	SYSDMAC_DMAFIXDAR_4				0xE6708214	// R/W	32	DMA fixed destination address register_4
#define	SYSDMAC_DMAFIXDPBASE_4			0xE6708260	// R/W	32	DMA fixed descriptor base address register_4
#define	SYSDMAC_DMASAR_5				0xE6708280	// R/W	32	DMA source address register_5
#define	SYSDMAC_DMADAR_5				0xE6708284	// R/W	32	DMA destination address register_5
#define	SYSDMAC_DMATCR_5				0xE6708288	// R/W	32	DMA transfer count register_5
#define	SYSDMAC_DMATSR_5				0xE67082A8	// R/W	32	DMA transfer size register_5
#define	SYSDMAC_DMACHCR_5				0xE670828C	// R/W	32	DMA channel control register_5
#define	SYSDMAC_DMATCRB_5				0xE6708298	// R/W	32	DMA transfer count register B_5
#define	SYSDMAC_DMATSRB_5				0xE67082B8	// R/W	32	DMA transfer size register B_5
#define	SYSDMAC_DMACHCRB_5				0xE670829C	// R/W	32	DMA channel control register B_5
#define	SYSDMAC_DMARS_5					0xE67082C0	// R/W	16	DMA extended resource selector_5
#define	SYSDMAC_DMABUFCR_5				0xE67082C8	// R/W	32	DMA buffer control register_5
#define	SYSDMAC_DMADPBASE_5				0xE67082D0	// R/W	32	DMA descriptor base address register_5
#define	SYSDMAC_DMADPCR_5				0xE67082D4	// R/W	32	DMA descriptor control register_5
#define	SYSDMAC_DMAFIXSAR_5				0xE6708290	// R/W	32	DMA fixed source address register_5
#define	SYSDMAC_DMAFIXDAR_5				0xE6708294	// R/W	32	DMA fixed destination address register_5
#define	SYSDMAC_DMAFIXDPBASE_5			0xE67082E0	// R/W	32	DMA fixed descriptor base address register_5
#define	SYSDMAC_DMASAR_6				0xE6708300	// R/W	32	DMA source address register_6
#define	SYSDMAC_DMADAR_6				0xE6708304	// R/W	32	DMA destination address register_6
#define	SYSDMAC_DMATCR_6				0xE6708308	// R/W	32	DMA transfer count register_6
#define	SYSDMAC_DMATSR_6				0xE6708328	// R/W	32	DMA transfer size register_6
#define	SYSDMAC_DMACHCR_6				0xE670830C	// R/W	32	DMA channel control register_6
#define	SYSDMAC_DMATCRB_6				0xE6708318	// R/W	32	DMA transfer count register B_6
#define	SYSDMAC_DMATSRB_6				0xE6708338	// R/W	32	DMA transfer size register B_6
#define	SYSDMAC_DMACHCRB_6				0xE670831C	// R/W	32	DMA channel control register B_6
#define	SYSDMAC_DMARS_6					0xE6708340	// R/W	16	DMA extended resource selector_6
#define	SYSDMAC_DMABUFCR_6				0xE6708348	// R/W	32	DMA buffer control register_6
#define	SYSDMAC_DMADPBASE_6				0xE6708350	// R/W	32	DMA descriptor base address register_6
#define	SYSDMAC_DMADPCR_6				0xE6708354	// R/W	32	DMA descriptor control register_6
#define	SYSDMAC_DMAFIXSAR_6				0xE6708310	// R/W	32	DMA fixed source address register_6
#define	SYSDMAC_DMAFIXDAR_6				0xE6708314	// R/W	32	DMA fixed destination address register_6
#define	SYSDMAC_DMAFIXDPBASE_6			0xE6708360	// R/W	32	DMA fixed descriptor base address register_6
#define	SYSDMAC_DMASAR_7				0xE6708380	// R/W	32	DMA source address register_7
#define	SYSDMAC_DMADAR_7				0xE6708384	// R/W	32	DMA destination address register_7
#define	SYSDMAC_DMATCR_7				0xE6708388	// R/W	32	DMA transfer count register_7
#define	SYSDMAC_DMATSR_7				0xE67083A8	// R/W	32	DMA transfer size register_7
#define	SYSDMAC_DMACHCR_7				0xE670838C	// R/W	32	DMA channel control register_7
#define	SYSDMAC_DMATCRB_7				0xE6708398	// R/W	32	DMA transfer count register B_7
#define	SYSDMAC_DMATSRB_7				0xE67083B8	// R/W	32	DMA transfer size register B_7
#define	SYSDMAC_DMACHCRB_7				0xE670839C	// R/W	32	DMA channel control register B_7
#define	SYSDMAC_DMARS_7					0xE67083C0	// R/W	16	DMA extended resource selector_7
#define	SYSDMAC_DMABUFCR_7				0xE67083C8	// R/W	32	DMA buffer control register_7
#define	SYSDMAC_DMADPBASE_7				0xE67083D0	// R/W	32	DMA descriptor base address register_7
#define	SYSDMAC_DMADPCR_7				0xE67083D4	// R/W	32	DMA descriptor control register_7
#define	SYSDMAC_DMAFIXSAR_7				0xE6708390	// R/W	32	DMA fixed source address register_7
#define	SYSDMAC_DMAFIXDAR_7				0xE6708394	// R/W	32	DMA fixed destination address register_7
#define	SYSDMAC_DMAFIXDPBASE_7			0xE67083E0	// R/W	32	DMA fixed descriptor base address register_7
#define	SYSDMAC_DMASAR_8				0xE6708400	// R/W	32	DMA source address register_8
#define	SYSDMAC_DMADAR_8				0xE6708404	// R/W	32	DMA destination address register_8
#define	SYSDMAC_DMATCR_8				0xE6708408	// R/W	32	DMA transfer count register_8
#define	SYSDMAC_DMATSR_8				0xE6708428	// R/W	32	DMA transfer size register_8
#define	SYSDMAC_DMACHCR_8				0xE670840C	// R/W	32	DMA channel control register_8
#define	SYSDMAC_DMATCRB_8				0xE6708418	// R/W	32	DMA transfer count register B_8
#define	SYSDMAC_DMATSRB_8				0xE6708438	// R/W	32	DMA transfer size register B_8
#define	SYSDMAC_DMACHCRB_8				0xE670841C	// R/W	32	DMA channel control register B_8
#define	SYSDMAC_DMARS_8					0xE6708440	// R/W	16	DMA extended resource selector_8
#define	SYSDMAC_DMABUFCR_8				0xE6708448	// R/W	32	DMA buffer control register_8
#define	SYSDMAC_DMADPBASE_8				0xE6708450	// R/W	32	DMA descriptor base address register_8
#define	SYSDMAC_DMADPCR_8				0xE6708454	// R/W	32	DMA descriptor control register_8
#define	SYSDMAC_DMAFIXSAR_8				0xE6708410	// R/W	32	DMA fixed source address register_8
#define	SYSDMAC_DMAFIXDAR_8				0xE6708414	// R/W	32	DMA fixed destination address register_8
#define	SYSDMAC_DMAFIXDPBASE_8			0xE6708460	// R/W	32	DMA fixed descriptor base address register_8
#define	SYSDMAC_DMASAR_9				0xE6708480	// R/W	32	DMA source address register_9
#define	SYSDMAC_DMADAR_9				0xE6708484	// R/W	32	DMA destination address register_9
#define	SYSDMAC_DMATCR_9				0xE6708488	// R/W	32	DMA transfer count register_9
#define	SYSDMAC_DMATSR_9				0xE67084A8	// R/W	32	DMA transfer size register_9
#define	SYSDMAC_DMACHCR_9				0xE670848C	// R/W	32	DMA channel control register_9
#define	SYSDMAC_DMATCRB_9				0xE6708498	// R/W	32	DMA transfer count register B_9
#define	SYSDMAC_DMATSRB_9				0xE67084B8	// R/W	32	DMA transfer size register B_9
#define	SYSDMAC_DMACHCRB_9				0xE670849C	// R/W	32	DMA channel control register B_9
#define	SYSDMAC_DMARS_9					0xE67084C0	// R/W	16	DMA extended resource selector_9
#define	SYSDMAC_DMABUFCR_9				0xE67084C8	// R/W	32	DMA buffer control register_9
#define	SYSDMAC_DMADPBASE_9				0xE67084D0	// R/W	32	DMA descriptor base address register_9
#define	SYSDMAC_DMADPCR_9				0xE67084D4	// R/W	32	DMA descriptor control register_9
#define	SYSDMAC_DMAFIXSAR_9				0xE6708490	// R/W	32	DMA fixed source address register_9
#define	SYSDMAC_DMAFIXDAR_9				0xE6708494	// R/W	32	DMA fixed destination address register_9
#define	SYSDMAC_DMAFIXDPBASE_9			0xE67084E0	// R/W	32	DMA fixed descriptor base address register_9
#define	SYSDMAC_DMASAR_10				0xE6708500	// R/W	32	DMA source address register_10
#define	SYSDMAC_DMADAR_10				0xE6708504	// R/W	32	DMA destination address register_10
#define	SYSDMAC_DMATCR_10				0xE6708508	// R/W	32	DMA transfer count register_10
#define	SYSDMAC_DMATSR_10				0xE6708528	// R/W	32	DMA transfer size register_10
#define	SYSDMAC_DMACHCR_10				0xE670850C	// R/W	32	DMA channel control register_10
#define	SYSDMAC_DMATCRB_10				0xE6708518	// R/W	32	DMA transfer count register B_10
#define	SYSDMAC_DMATSRB_10				0xE6708538	// R/W	32	DMA transfer size register B_10
#define	SYSDMAC_DMACHCRB_10				0xE670851C	// R/W	32	DMA channel control register B_10
#define	SYSDMAC_DMARS_10				0xE6708540	// R/W	16	DMA extended resource selector_10
#define	SYSDMAC_DMABUFCR_10				0xE6708548	// R/W	32	DMA buffer control register_10
#define	SYSDMAC_DMADPBASE_10			0xE6708550	// R/W	32	DMA descriptor base address register_10
#define	SYSDMAC_DMADPCR_10				0xE6708554	// R/W	32	DMA descriptor control register_10
#define	SYSDMAC_DMAFIXSAR_10			0xE6708510	// R/W	32	DMA fixed source address register_10
#define	SYSDMAC_DMAFIXDAR_10			0xE6708514	// R/W	32	DMA fixed destination address register_10
#define	SYSDMAC_DMAFIXDPBASE_10			0xE6708560	// R/W	32	DMA fixed descriptor base address register_10
#define	SYSDMAC_DMASAR_11				0xE6708580	// R/W	32	DMA source address register_11
#define	SYSDMAC_DMADAR_11				0xE6708584	// R/W	32	DMA destination address register_11
#define	SYSDMAC_DMATCR_11				0xE6708588	// R/W	32	DMA transfer count register_11
#define	SYSDMAC_DMATSR_11				0xE67085A8	// R/W	32	DMA transfer size register_11
#define	SYSDMAC_DMACHCR_11				0xE670858C	// R/W	32	DMA channel control register_11
#define	SYSDMAC_DMATCRB_11				0xE6708598	// R/W	32	DMA transfer count register B_11
#define	SYSDMAC_DMATSRB_11				0xE67085B8	// R/W	32	DMA transfer size register B_11
#define	SYSDMAC_DMACHCRB_11				0xE670859C	// R/W	32	DMA channel control register B_11
#define	SYSDMAC_DMARS_11				0xE67085C0	// R/W	16	DMA extended resource selector_11
#define	SYSDMAC_DMABUFCR_11				0xE67085C8	// R/W	32	DMA buffer control register_11
#define	SYSDMAC_DMADPBASE_11			0xE67085D0	// R/W	32	DMA descriptor base address register_11
#define	SYSDMAC_DMADPCR_11				0xE67085D4	// R/W	32	DMA descriptor control register_11
#define	SYSDMAC_DMAFIXSAR_11			0xE6708590	// R/W	32	DMA fixed source address register_11
#define	SYSDMAC_DMAFIXDAR_11			0xE6708594	// R/W	32	DMA fixed destination address register_11
#define	SYSDMAC_DMAFIXDPBASE_11			0xE67085E0	// R/W	32	DMA fixed descriptor base address register_11
#define	SYSDMAC_DMASAR_12				0xE6708600	// R/W	32	DMA source address register_12
#define	SYSDMAC_DMADAR_12				0xE6708604	// R/W	32	DMA destination address register_12
#define	SYSDMAC_DMATCR_12				0xE6708608	// R/W	32	DMA transfer count register_12
#define	SYSDMAC_DMATSR_12				0xE6708628	// R/W	32	DMA transfer size register_12
#define	SYSDMAC_DMACHCR_12				0xE670860C	// R/W	32	DMA channel control register_12
#define	SYSDMAC_DMATCRB_12				0xE6708618	// R/W	32	DMA transfer count register B_12
#define	SYSDMAC_DMATSRB_12				0xE6708638	// R/W	32	DMA transfer size register B_12
#define	SYSDMAC_DMACHCRB_12				0xE670861C	// R/W	32	DMA channel control register B_12
#define	SYSDMAC_DMARS_12				0xE6708640	// R/W	16	DMA extended resource selector_12
#define	SYSDMAC_DMABUFCR_12				0xE6708648	// R/W	32	DMA buffer control register_12
#define	SYSDMAC_DMADPBASE_12			0xE6708650	// R/W	32	DMA descriptor base address register_12
#define	SYSDMAC_DMADPCR_12				0xE6708654	// R/W	32	DMA descriptor control register_12
#define	SYSDMAC_DMAFIXSAR_12			0xE6708610	// R/W	32	DMA fixed source address register_12
#define	SYSDMAC_DMAFIXDAR_12			0xE6708614	// R/W	32	DMA fixed destination address register_12
#define	SYSDMAC_DMAFIXDPBASE_12			0xE6708660	// R/W	32	DMA fixed descriptor base address register_12
#define	SYSDMAC_DMASAR_13				0xE6708680	// R/W	32	DMA source address register_13
#define	SYSDMAC_DMADAR_13				0xE6708684	// R/W	32	DMA destination address register_13
#define	SYSDMAC_DMATCR_13				0xE6708688	// R/W	32	DMA transfer count register_13
#define	SYSDMAC_DMATSR_13				0xE67086A8	// R/W	32	DMA transfer size register_13
#define	SYSDMAC_DMACHCR_13				0xE670868C	// R/W	32	DMA channel control register_13
#define	SYSDMAC_DMATCRB_13				0xE6708698	// R/W	32	DMA transfer count register B_13
#define	SYSDMAC_DMATSRB_13				0xE67086B8	// R/W	32	DMA transfer size register B_13
#define	SYSDMAC_DMACHCRB_13				0xE670869C	// R/W	32	DMA channel control register B_13
#define	SYSDMAC_DMARS_13				0xE67086C0	// R/W	16	DMA extended resource selector_13
#define	SYSDMAC_DMABUFCR_13				0xE67086C8	// R/W	32	DMA buffer control register_13
#define	SYSDMAC_DMADPBASE_13			0xE67086D0	// R/W	32	DMA descriptor base address register_13
#define	SYSDMAC_DMADPCR_13				0xE67086D4	// R/W	32	DMA descriptor control register_13
#define	SYSDMAC_DMAFIXSAR_13			0xE6708690	// R/W	32	DMA fixed source address register_13
#define	SYSDMAC_DMAFIXDAR_13			0xE6708694	// R/W	32	DMA fixed destination address register_13
#define	SYSDMAC_DMAFIXDPBASE_13			0xE67086E0	// R/W	32	DMA fixed descriptor base address register_13
#define	SYSDMAC_DMASAR_14				0xE6708700	// R/W	32	DMA source address register_14
#define	SYSDMAC_DMADAR_14				0xE6708704	// R/W	32	DMA destination address register_14
#define	SYSDMAC_DMATCR_14				0xE6708708	// R/W	32	DMA transfer count register_14
#define	SYSDMAC_DMATSR_14				0xE6708728	// R/W	32	DMA transfer size register_14
#define	SYSDMAC_DMACHCR_14				0xE670870C	// R/W	32	DMA channel control register_14
#define	SYSDMAC_DMATCRB_14				0xE6708718	// R/W	32	DMA transfer count register B_14
#define	SYSDMAC_DMATSRB_14				0xE6708738	// R/W	32	DMA transfer size register B_14
#define	SYSDMAC_DMACHCRB_14				0xE670871C	// R/W	32	DMA channel control register B_14
#define	SYSDMAC_DMARS_14				0xE6708740	// R/W	16	DMA extended resource selector_14
#define	SYSDMAC_DMABUFCR_14				0xE6708748	// R/W	32	DMA buffer control register_14
#define	SYSDMAC_DMADPBASE_14			0xE6708750	// R/W	32	DMA descriptor base address register_14
#define	SYSDMAC_DMADPCR_14				0xE6708754	// R/W	32	DMA descriptor control register_14
#define	SYSDMAC_DMAFIXSAR_14			0xE6708710	// R/W	32	DMA fixed source address register_14
#define	SYSDMAC_DMAFIXDAR_14			0xE6708714	// R/W	32	DMA fixed destination address register_14
#define	SYSDMAC_DMAFIXDPBASE_14			0xE6708760	// R/W	32	DMA fixed descriptor base address register_14
#define	SYSDMAC_DMASAR_15				0xE6708780	// R/W	32	DMA source address register_15
#define	SYSDMAC_DMADAR_15				0xE6708784	// R/W	32	DMA destination address register_15
#define	SYSDMAC_DMATCR_15				0xE6708788	// R/W	32	DMA transfer count register_15
#define	SYSDMAC_DMATSR_15				0xE67087A8	// R/W	32	DMA transfer size register_15
#define	SYSDMAC_DMACHCR_15				0xE670878C	// R/W	32	DMA channel control register_15
#define	SYSDMAC_DMATCRB_15				0xE6708798	// R/W	32	DMA transfer count register B_15
#define	SYSDMAC_DMATSRB_15				0xE67087B8	// R/W	32	DMA transfer size register B_15
#define	SYSDMAC_DMACHCRB_15				0xE670879C	// R/W	32	DMA channel control register B_15
#define	SYSDMAC_DMARS_15				0xE67087C0	// R/W	16	DMA extended resource selector_15
#define	SYSDMAC_DMABUFCR_15				0xE67087C8	// R/W	32	DMA buffer control register_15
#define	SYSDMAC_DMADPBASE_15			0xE67087D0	// R/W	32	DMA descriptor base address register_15
#define	SYSDMAC_DMADPCR_15				0xE67087D4	// R/W	32	DMA descriptor control register_15
#define	SYSDMAC_DMAFIXSAR_15			0xE6708790	// R/W	32	DMA fixed source address register_15
#define	SYSDMAC_DMAFIXDAR_15			0xE6708794	// R/W	32	DMA fixed destination address register_15
#define	SYSDMAC_DMAFIXDPBASE_15			0xE67087E0	// R/W	32	DMA fixed descriptor base address register_15
#define	SYSDMAC_DescriptorMEM_0_15		0xE670A000	// R/W	32	Descriptor memory (for channels 0 to 15)
#define	SYSDMAC_DMASES_0				0xE67000C0	// R/W	32	Secure function Secure Status register (for channels 0 to 15)
#define	SYSDMAC_DMASEA_0				0xE67000C4	// R/W	32	Secure function Slave Error Address register (for channels 0 to 15)
#define	SYSDMAC_DMAEMID_0				0xE67000C8	// R/W	32	Secure function Error Master ID register (for channels 0 to 15)
#define	SYSDMAC_DMAISTA_1				0xE7300020	// R	32	DMA interrupt status register (for channels 16 to 31)
#define	SYSDMAC_DMASEC_1				0xE7300030	// R/W	32	DMA secure control register (for channels 16 to 31)
#define	SYSDMAC_DMAOR_1					0xE7300060	// R/W	16	DMA operation register (for channels 16 to 31)
#define	SYSDMAC_DMACHCLR_1				0xE7300080	// W	32	DMA channel clear register (for channels 16 to 31)
#define	SYSDMAC_DMADPSEC_1				0xE73000A0	// R/W	32	DPRAM secure control register (for channels 16 to 31)
#define	SYSDMAC_DMASAR_16				0xE7308000	// R/W	32	DMA source address register_16
#define	SYSDMAC_DMADAR_16				0xE7308004	// R/W	32	DMA destination address register_16
#define	SYSDMAC_DMATCR_16				0xE7308008	// R/W	32	DMA transfer count register_16
#define	SYSDMAC_DMATSR_16				0xE7308028	// R/W	32	DMA transfer size register_16
#define	SYSDMAC_DMACHCR_16				0xE730800C	// R/W	32	DMA channel control register_16
#define	SYSDMAC_DMATCRB_16				0xE7308018	// R/W	32	DMA transfer count register B_16
#define	SYSDMAC_DMATSRB_16				0xE7308038	// R/W	32	DMA transfer size register B_16
#define	SYSDMAC_DMACHCRB_16				0xE730801C	// R/W	32	DMA channel control register B_16
#define	SYSDMAC_DMARS_16				0xE7308040	// R/W	16	DMA extended resource selector_16
#define	SYSDMAC_DMABUFCR_16				0xE7308048	// R/W	32	DMA buffer control register_16
#define	SYSDMAC_DMADPBASE_16			0xE7308050	// R/W	32	DMA descriptor base address register_16
#define	SYSDMAC_DMADPCR_16				0xE7308054	// R/W	32	DMA descriptor control register_16
#define	SYSDMAC_DMAFIXSAR_16			0xE7308010	// R/W	32	DMA fixed source address register_16
#define	SYSDMAC_DMAFIXDAR_16			0xE7308014	// R/W	32	DMA fixed destination address register_16
#define	SYSDMAC_DMAFIXDPBASE_16			0xE7308060	// R/W	32	DMA fixed descriptor base address register_16
#define	SYSDMAC_DMASAR_17				0xE7308080	// R/W	32	DMA source address register_17
#define	SYSDMAC_DMADAR_17				0xE7308084	// R/W	32	DMA destination address register_17
#define	SYSDMAC_DMATCR_17				0xE7308088	// R/W	32	DMA transfer count register_17
#define	SYSDMAC_DMATSR_17				0xE73080A8	// R/W	32	DMA transfer size register_17
#define	SYSDMAC_DMACHCR_17				0xE730808C	// R/W	32	DMA channel control register_17
#define	SYSDMAC_DMATCRB_17				0xE7308098	// R/W	32	DMA transfer count register B_17
#define	SYSDMAC_DMATSRB_17				0xE73080B8	// R/W	32	DMA transfer size register B_17
#define	SYSDMAC_DMACHCRB_17				0xE730809C	// R/W	32	DMA channel control register B_17
#define	SYSDMAC_DMARS_17				0xE73080C0	// R/W	16	DMA extended resource selector_17
#define	SYSDMAC_DMABUFCR_17				0xE73080C8	// R/W	32	DMA buffer control register_17
#define	SYSDMAC_DMADPBASE_17			0xE73080D0	// R/W	32	DMA descriptor base address register_17
#define	SYSDMAC_DMADPCR_17				0xE73080D4	// R/W	32	DMA descriptor control register_17
#define	SYSDMAC_DMAFIXDPBASE_17			0xE73080E0	// R/W	32	DMA fixed descriptor base address register_17
#define	SYSDMAC_DMAFIXSAR_17			0xE7308090	// R/W	32	DMA fixed source address register_17
#define	SYSDMAC_DMAFIXDAR_17			0xE7308094	// R/W	32	DMA fixed destination address register_17
#define	SYSDMAC_DMASAR_18				0xE7308100	// R/W	32	DMA source address register_18
#define	SYSDMAC_DMADAR_18				0xE7308104	// R/W	32	DMA destination address register_18
#define	SYSDMAC_DMATCR_18				0xE7308108	// R/W	32	DMA transfer count register_18
#define	SYSDMAC_DMATSR_18				0xE7308128	// R/W	32	DMA transfer size register_18
#define	SYSDMAC_DMACHCR_18				0xE730810C	// R/W	32	DMA channel control register_18
#define	SYSDMAC_DMATCRB_18				0xE7308118	// R/W	32	DMA transfer count register B_18
#define	SYSDMAC_DMATSRB_18				0xE7308138	// R/W	32	DMA transfer size register B_18
#define	SYSDMAC_DMACHCRB_18				0xE730811C	// R/W	32	DMA channel control register B_18
#define	SYSDMAC_DMARS_18				0xE7308140	// R/W	16	DMA extended resource selector_18
#define	SYSDMAC_DMABUFCR_18				0xE7308148	// R/W	32	DMA buffer control register_18
#define	SYSDMAC_DMADPBASE_18			0xE7308150	// R/W	32	DMA descriptor base address register_18
#define	SYSDMAC_DMADPCR_18				0xE7308154	// R/W	32	DMA descriptor control register_18
#define	SYSDMAC_DMAFIXSAR_18			0xE7308110	// R/W	32	DMA fixed source address register_18
#define	SYSDMAC_DMAFIXDAR_18			0xE7308114	// R/W	32	DMA fixed destination address register_18
#define	SYSDMAC_DMAFIXDPBASE_18			0xE7308160	// R/W	32	DMA fixed descriptor base address register_18
#define	SYSDMAC_DMASAR_19				0xE7308180	// R/W	32	DMA source address register_19
#define	SYSDMAC_DMADAR_19				0xE7308184	// R/W	32	DMA destination address register_19
#define	SYSDMAC_DMATCR_19				0xE7308188	// R/W	32	DMA transfer count register_19
#define	SYSDMAC_DMATSR_19				0xE73081A8	// R/W	32	DMA transfer size register_19
#define	SYSDMAC_DMACHCR_19				0xE730818C	// R/W	32	DMA channel control register_19
#define	SYSDMAC_DMATCRB_19				0xE7308198	// R/W	32	DMA transfer count register B_19
#define	SYSDMAC_DMATSRB_19				0xE73081B8	// R/W	32	DMA transfer size register B_19
#define	SYSDMAC_DMACHCRB_19				0xE730819C	// R/W	32	DMA channel control register B_19
#define	SYSDMAC_DMARS_19				0xE73081C0	// R/W	16	DMA extended resource selector_19
#define	SYSDMAC_DMABUFCR_19				0xE73081C8	// R/W	32	DMA buffer control register_19
#define	SYSDMAC_DMADPBASE_19			0xE73081D0	// R/W	32	DMA descriptor base address register_19
#define	SYSDMAC_DMADPCR_19				0xE73081D4	// R/W	32	DMA descriptor control register_19
#define	SYSDMAC_DMAFIXSAR_19			0xE7308190	// R/W	32	DMA fixed source address register_19
#define	SYSDMAC_DMAFIXDAR_19			0xE7308194	// R/W	32	DMA fixed destination address register_19
#define	SYSDMAC_DMAFIXDPBASE_19			0xE73081E0	// R/W	32	DMA fixed descriptor base address register_19
#define	SYSDMAC_DMASAR_20				0xE7308200	// R/W	32	DMA source address register_20
#define	SYSDMAC_DMADAR_20				0xE7308204	// R/W	32	DMA destination address register_20
#define	SYSDMAC_DMATCR_20				0xE7308208	// R/W	32	DMA transfer count register_20
#define	SYSDMAC_DMATSR_20				0xE7308228	// R/W	32	DMA transfer size register_20
#define	SYSDMAC_DMACHCR_20				0xE730820C	// R/W	32	DMA channel control register_20
#define	SYSDMAC_DMATCRB_20				0xE7308218	// R/W	32	DMA transfer count register B_20
#define	SYSDMAC_DMATSRB_20				0xE7308238	// R/W	32	DMA transfer size register B_20
#define	SYSDMAC_DMACHCRB_20				0xE730821C	// R/W	32	DMA channel control register B_20
#define	SYSDMAC_DMARS_20				0xE7308240	// R/W	16	DMA extended resource selector_20
#define	SYSDMAC_DMABUFCR_20				0xE7308248	// R/W	32	DMA buffer control register_20
#define	SYSDMAC_DMADPBASE_20			0xE7308250	// R/W	32	DMA descriptor base address register_20
#define	SYSDMAC_DMADPCR_20				0xE7308254	// R/W	32	DMA descriptor control register_20
#define	SYSDMAC_DMAFIXSAR_20			0xE7308210	// R/W	32	DMA fixed source address register_20
#define	SYSDMAC_DMAFIXDAR_20			0xE7308214	// R/W	32	DMA fixed destination address register_20
#define	SYSDMAC_DMAFIXDPBASE_20			0xE7308260	// R/W	32	DMA fixed descriptor base address register_20
#define	SYSDMAC_DMASAR_21				0xE7308280	// R/W	32	DMA source address register_21
#define	SYSDMAC_DMADAR_21				0xE7308284	// R/W	32	DMA destination address register_21
#define	SYSDMAC_DMATCR_21				0xE7308288	// R/W	32	DMA transfer count register_21
#define	SYSDMAC_DMATSR_21				0xE73082A8	// R/W	32	DMA transfer size register_21
#define	SYSDMAC_DMACHCR_21				0xE730828C	// R/W	32	DMA channel control register_21
#define	SYSDMAC_DMATCRB_21				0xE7308298	// R/W	32	DMA transfer count register B_21
#define	SYSDMAC_DMATSRB_21				0xE73082B8	// R/W	32	DMA transfer size register B_21
#define	SYSDMAC_DMACHCRB_21				0xE730829C	// R/W	32	DMA channel control register B_21
#define	SYSDMAC_DMARS_21				0xE73082C0	// R/W	16	DMA extended resource selector_21
#define	SYSDMAC_DMABUFCR_21				0xE73082C8	// R/W	32	DMA buffer control register_21
#define	SYSDMAC_DMADPBASE_21			0xE73082D0	// R/W	32	DMA descriptor base address register_21
#define	SYSDMAC_DMADPCR_21				0xE73082D4	// R/W	32	DMA descriptor control register_21
#define	SYSDMAC_DMAFIXSAR_21			0xE7308290	// R/W	32	DMA fixed source address register_21
#define	SYSDMAC_DMAFIXDAR_21			0xE7308294	// R/W	32	DMA fixed destination address register_21
#define	SYSDMAC_DMAFIXDPBASE_21			0xE73082E0	// R/W	32	DMA fixed descriptor base address register_21
#define	SYSDMAC_DMASAR_22				0xE7308300	// R/W	32	DMA source address register_22
#define	SYSDMAC_DMADAR_22				0xE7308304	// R/W	32	DMA destination address register_22
#define	SYSDMAC_DMATCR_22				0xE7308308	// R/W	32	DMA transfer count register_22
#define	SYSDMAC_DMATSR_22				0xE7308328	// R/W	32	DMA transfer size register_22
#define	SYSDMAC_DMACHCR_22				0xE730830C	// R/W	32	DMA channel control register_22
#define	SYSDMAC_DMATCRB_22				0xE7308318	// R/W	32	DMA transfer count register B_22
#define	SYSDMAC_DMATSRB_22				0xE7308338	// R/W	32	DMA transfer size register B_22
#define	SYSDMAC_DMACHCRB_22				0xE730831C	// R/W	32	DMA channel control register B_22
#define	SYSDMAC_DMARS_22				0xE7308340	// R/W	16	DMA extended resource selector_22
#define	SYSDMAC_DMABUFCR_22				0xE7308348	// R/W	32	DMA buffer control register_22
#define	SYSDMAC_DMADPBASE_22			0xE7308350	// R/W	32	DMA descriptor base address register_22
#define	SYSDMAC_DMADPCR_22				0xE7308354	// R/W	32	DMA descriptor control register_22
#define	SYSDMAC_DMAFIXSAR_22			0xE7308310	// R/W	32	DMA fixed source address register_22
#define	SYSDMAC_DMAFIXDAR_22			0xE7308314	// R/W	32	DMA fixed destination address register_22
#define	SYSDMAC_DMAFIXDPBASE_22			0xE7308360	// R/W	32	DMA fixed descriptor base address register_22
#define	SYSDMAC_DMASAR_23				0xE7308380	// R/W	32	DMA source address register_23
#define	SYSDMAC_DMADAR_23				0xE7308384	// R/W	32	DMA destination address register_23
#define	SYSDMAC_DMATCR_23				0xE7308388	// R/W	32	DMA transfer count register_23
#define	SYSDMAC_DMATSR_23				0xE73083A8	// R/W	32	DMA transfer size register_23
#define	SYSDMAC_DMACHCR_23				0xE730838C	// R/W	32	DMA channel control register_23
#define	SYSDMAC_DMATCRB_23				0xE7308398	// R/W	32	DMA transfer count register B_23
#define	SYSDMAC_DMATSRB_23				0xE73083B8	// R/W	32	DMA transfer size register B_23
#define	SYSDMAC_DMACHCRB_23				0xE730839C	// R/W	32	DMA channel control register B_23
#define	SYSDMAC_DMARS_23				0xE73083C0	// R/W	16	DMA extended resource selector_23
#define	SYSDMAC_DMABUFCR_23				0xE73083C8	// R/W	32	DMA buffer control register_23
#define	SYSDMAC_DMADPBASE_23			0xE73083D0	// R/W	32	DMA descriptor base address register_23
#define	SYSDMAC_DMADPCR_23				0xE73083D4	// R/W	32	DMA descriptor control register_23
#define	SYSDMAC_DMAFIXSAR_23			0xE7308390	// R/W	32	DMA fixed source address register_23
#define	SYSDMAC_DMAFIXDAR_23			0xE7308394	// R/W	32	DMA fixed destination address register_23
#define	SYSDMAC_DMAFIXDPBASE_23			0xE73083E0	// R/W	32	DMA fixed descriptor base address register_23
#define	SYSDMAC_DMASAR_24				0xE7308400	// R/W	32	DMA source address register_24
#define	SYSDMAC_DMADAR_24				0xE7308404	// R/W	32	DMA destination address register_24
#define	SYSDMAC_DMATCR_24				0xE7308408	// R/W	32	DMA transfer count register_24
#define	SYSDMAC_DMATSR_24				0xE7308428	// R/W	32	DMA transfer size register_24
#define	SYSDMAC_DMACHCR_24				0xE730840C	// R/W	32	DMA channel control register_24
#define	SYSDMAC_DMATCRB_24				0xE7308418	// R/W	32	DMA transfer count register B_24
#define	SYSDMAC_DMATSRB_24				0xE7308438	// R/W	32	DMA transfer size register B_24
#define	SYSDMAC_DMACHCRB_24				0xE730841C	// R/W	32	DMA channel control register B_24
#define	SYSDMAC_DMARS_24				0xE7308440	// R/W	16	DMA extended resource selector_24
#define	SYSDMAC_DMABUFCR_24				0xE7308448	// R/W	32	DMA buffer control register_24
#define	SYSDMAC_DMADPBASE_24			0xE7308450	// R/W	32	DMA descriptor base address register_24
#define	SYSDMAC_DMADPCR_24				0xE7308454	// R/W	32	DMA descriptor control register_24
#define	SYSDMAC_DMAFIXSAR_24			0xE7308410	// R/W	32	DMA fixed source address register_24
#define	SYSDMAC_DMAFIXDAR_24			0xE7308414	// R/W	32	DMA fixed destination address register_24
#define	SYSDMAC_DMAFIXDPBASE_24			0xE7308460	// R/W	32	DMA fixed descriptor base address register_24
#define	SYSDMAC_DMASAR_25				0xE7308480	// R/W	32	DMA source address register_25
#define	SYSDMAC_DMADAR_25				0xE7308484	// R/W	32	DMA destination address register_25
#define	SYSDMAC_DMATCR_25				0xE7308488	// R/W	32	DMA transfer count register_25
#define	SYSDMAC_DMATSR_25				0xE73084A8	// R/W	32	DMA transfer size register_25
#define	SYSDMAC_DMACHCR_25				0xE730848C	// R/W	32	DMA channel control register_25
#define	SYSDMAC_DMATCRB_25				0xE7308498	// R/W	32	DMA transfer count register B_25
#define	SYSDMAC_DMATSRB_25				0xE73084B8	// R/W	32	DMA transfer size register B_25
#define	SYSDMAC_DMACHCRB_25				0xE730849C	// R/W	32	DMA channel control register B_25
#define	SYSDMAC_DMARS_25				0xE73084C0	// R/W	16	DMA extended resource selector_25
#define	SYSDMAC_DMABUFCR_25				0xE73084C8	// R/W	32	DMA buffer control register_25
#define	SYSDMAC_DMADPBASE_25			0xE73084D0	// R/W	32	DMA descriptor base address register_25
#define	SYSDMAC_DMADPCR_25				0xE73084D4	// R/W	32	DMA descriptor control register_25
#define	SYSDMAC_DMAFIXSAR_25			0xE7308490	// R/W	32	DMA fixed source address register_25
#define	SYSDMAC_DMAFIXDAR_25			0xE7308494	// R/W	32	DMA fixed destination address register_25
#define	SYSDMAC_DMAFIXDPBASE_25			0xE73084E0	// R/W	32	DMA fixed descriptor base address register_25
#define	SYSDMAC_DMASAR_26				0xE7308500	// R/W	32	DMA source address register_26
#define	SYSDMAC_DMADAR_26				0xE7308504	// R/W	32	DMA destination address register_26
#define	SYSDMAC_DMATCR_26				0xE7308508	// R/W	32	DMA transfer count register_26
#define	SYSDMAC_DMATSR_26				0xE7308528	// R/W	32	DMA transfer size register_26
#define	SYSDMAC_DMACHCR_26				0xE730850C	// R/W	32	DMA channel control register_26
#define	SYSDMAC_DMATCRB_26				0xE7308518	// R/W	32	DMA transfer count register B_26
#define	SYSDMAC_DMATSRB_26				0xE7308538	// R/W	32	DMA transfer size register B_26
#define	SYSDMAC_DMACHCRB_26				0xE730851C	// R/W	32	DMA channel control register B_26
#define	SYSDMAC_DMARS_26				0xE7308540	// R/W	16	DMA extended resource selector_26
#define	SYSDMAC_DMABUFCR_26				0xE7308548	// R/W	32	DMA buffer control register_26
#define	SYSDMAC_DMADPBASE_26			0xE7308550	// R/W	32	DMA descriptor base address register_26
#define	SYSDMAC_DMADPCR_26				0xE7308554	// R/W	32	DMA descriptor control register_26
#define	SYSDMAC_DMAFIXSAR_26			0xE7308510	// R/W	32	DMA fixed source address register_26
#define	SYSDMAC_DMAFIXDAR_26			0xE7308514	// R/W	32	DMA fixed destination address register_26
#define	SYSDMAC_DMAFIXDPBASE_26			0xE7308560	// R/W	32	DMA fixed descriptor base address register_26
#define	SYSDMAC_DMASAR_27				0xE7308580	// R/W	32	DMA source address register_27
#define	SYSDMAC_DMADAR_27				0xE7308584	// R/W	32	DMA destination address register_27
#define	SYSDMAC_DMATCR_27				0xE7308588	// R/W	32	DMA transfer count register_27
#define	SYSDMAC_DMATSR_27				0xE73085A8	// R/W	32	DMA transfer size register_27
#define	SYSDMAC_DMACHCR_27				0xE730858C	// R/W	32	DMA channel control register_27
#define	SYSDMAC_DMATCRB_27				0xE7308598	// R/W	32	DMA transfer count register B_27
#define	SYSDMAC_DMATSRB_27				0xE73085B8	// R/W	32	DMA transfer size register B_27
#define	SYSDMAC_DMACHCRB_27				0xE730859C	// R/W	32	DMA channel control register B_27
#define	SYSDMAC_DMARS_27				0xE73085C0	// R/W	16	DMA extended resource selector_27
#define	SYSDMAC_DMABUFCR_27				0xE73085C8	// R/W	32	DMA buffer control register_27
#define	SYSDMAC_DMADPBASE_27			0xE73085D0	// R/W	32	DMA descriptor base address register_27
#define	SYSDMAC_DMADPCR_27				0xE73085D4	// R/W	32	DMA descriptor control register_27
#define	SYSDMAC_DMAFIXSAR_27			0xE7308590	// R/W	32	DMA fixed source address register_27
#define	SYSDMAC_DMAFIXDAR_27			0xE7308594	// R/W	32	DMA fixed destination address register_27
#define	SYSDMAC_DMAFIXDPBASE_27			0xE73085E0	// R/W	32	DMA fixed descriptor base address register_27
#define	SYSDMAC_DMASAR_28				0xE7308600	// R/W	32	DMA source address register_28
#define	SYSDMAC_DMADAR_28				0xE7308604	// R/W	32	DMA destination address register_28
#define	SYSDMAC_DMATCR_28				0xE7308608	// R/W	32	DMA transfer count register_28
#define	SYSDMAC_DMATSR_28				0xE7308628	// R/W	32	DMA transfer size register_28
#define	SYSDMAC_DMACHCR_28				0xE730860C	// R/W	32	DMA channel control register_28
#define	SYSDMAC_DMATCRB_28				0xE7308618	// R/W	32	DMA transfer count register B_28
#define	SYSDMAC_DMATSRB_28				0xE7308638	// R/W	32	DMA transfer size register B_28
#define	SYSDMAC_DMACHCRB_28				0xE730861C	// R/W	32	DMA channel control register B_28
#define	SYSDMAC_DMARS_28				0xE7308640	// R/W	16	DMA extended resource selector_28
#define	SYSDMAC_DMABUFCR_28				0xE7308648	// R/W	32	DMA buffer control register_28
#define	SYSDMAC_DMADPBASE_28			0xE7308650	// R/W	32	DMA descriptor base address register_28
#define	SYSDMAC_DMADPCR_28				0xE7308654	// R/W	32	DMA descriptor control register_28
#define	SYSDMAC_DMAFIXSAR_28			0xE7308610	// R/W	32	DMA fixed source address register_28
#define	SYSDMAC_DMAFIXDAR_28			0xE7308614	// R/W	32	DMA fixed destination address register_28
#define	SYSDMAC_DMAFIXDPBASE_28			0xE7308660	// R/W	32	DMA fixed descriptor base address register_28
#define	SYSDMAC_DMASAR_29				0xE7308680	// R/W	32	DMA source address register_29
#define	SYSDMAC_DMADAR_29				0xE7308684	// R/W	32	DMA destination address register_29
#define	SYSDMAC_DMATCR_29				0xE7308688	// R/W	32	DMA transfer count register_29
#define	SYSDMAC_DMATSR_29				0xE73086A8	// R/W	32	DMA transfer size register_29
#define	SYSDMAC_DMACHCR_29				0xE730868C	// R/W	32	DMA channel control register_29
#define	SYSDMAC_DMATCRB_29				0xE7308698	// R/W	32	DMA transfer count register B_29
#define	SYSDMAC_DMATSRB_29				0xE73086B8	// R/W	32	DMA transfer size register B_29
#define	SYSDMAC_DMACHCRB_29				0xE730869C	// R/W	32	DMA channel control register B_29
#define	SYSDMAC_DMARS_29				0xE73086C0	// R/W	16	DMA extended resource selector_29
#define	SYSDMAC_DMABUFCR_29				0xE73086C8	// R/W	32	DMA buffer control register_29
#define	SYSDMAC_DMADPBASE_29			0xE73086D0	// R/W	32	DMA descriptor base address register_29
#define	SYSDMAC_DMADPCR_29				0xE73086D4	// R/W	32	DMA descriptor control register_29
#define	SYSDMAC_DMAFIXSAR_29			0xE7308690	// R/W	32	DMA fixed source address register_29
#define	SYSDMAC_DMAFIXDAR_29			0xE7308694	// R/W	32	DMA fixed destination address register_29
#define	SYSDMAC_DMAFIXDPBASE_29			0xE73086E0	// R/W	32	DMA fixed descriptor base address register_29
#define	SYSDMAC_DMASAR_30				0xE7308700	// R/W	32	DMA source address register_30
#define	SYSDMAC_DMADAR_30				0xE7308704	// R/W	32	DMA destination address register_30
#define	SYSDMAC_DMATCR_30				0xE7308708	// R/W	32	DMA transfer count register_30
#define	SYSDMAC_DMATSR_30				0xE7308728	// R/W	32	DMA transfer size register_30
#define	SYSDMAC_DMACHCR_30				0xE730870C	// R/W	32	DMA channel control register_30
#define	SYSDMAC_DMATCRB_30				0xE7308718	// R/W	32	DMA transfer count register B_30
#define	SYSDMAC_DMATSRB_30				0xE7308738	// R/W	32	DMA transfer size register B_30
#define	SYSDMAC_DMACHCRB_30				0xE730871C	// R/W	32	DMA channel control register B_30
#define	SYSDMAC_DMARS_30				0xE7308740	// R/W	16	DMA extended resource selector_30
#define	SYSDMAC_DMABUFCR_30				0xE7308748	// R/W	32	DMA buffer control register_30
#define	SYSDMAC_DMADPBASE_30			0xE7308750	// R/W	32	DMA descriptor base address register_30
#define	SYSDMAC_DMADPCR_30				0xE7308754	// R/W	32	DMA descriptor control register_30
#define	SYSDMAC_DMAFIXSAR_30			0xE7308710	// R/W	32	DMA fixed source address register_30
#define	SYSDMAC_DMAFIXDAR_30			0xE7308714	// R/W	32	DMA fixed destination address register_30
#define	SYSDMAC_DMAFIXDPBASE_30			0xE7308760	// R/W	32	DMA fixed descriptor base address register_30
#define	SYSDMAC_DMASAR_31				0xE7308780	// R/W	32	DMA source address register_31
#define	SYSDMAC_DMADAR_31				0xE7308784	// R/W	32	DMA destination address register_31
#define	SYSDMAC_DMATCR_31				0xE7308788	// R/W	32	DMA transfer count register_31
#define	SYSDMAC_DMATSR_31				0xE73087A8	// R/W	32	DMA transfer size register_31
#define	SYSDMAC_DMACHCR_31				0xE730878C	// R/W	32	DMA channel control register_31
#define	SYSDMAC_DMATCRB_31				0xE7308798	// R/W	32	DMA transfer count register B_31
#define	SYSDMAC_DMATSRB_31				0xE73087B8	// R/W	32	DMA transfer size register B_31
#define	SYSDMAC_DMACHCRB_31				0xE730879C	// R/W	32	DMA channel control register B_31
#define	SYSDMAC_DMARS_31				0xE73087C0	// R/W	16	DMA extended resource selector_31
#define	SYSDMAC_DMABUFCR_31				0xE73087C8	// R/W	32	DMA buffer control register_31
#define	SYSDMAC_DMADPBASE_31			0xE73087D0	// R/W	32	DMA descriptor base address register_31
#define	SYSDMAC_DMADPCR_31				0xE73087D4	// R/W	32	DMA descriptor control register_31
#define	SYSDMAC_DMAFIXSAR_31			0xE7308790	// R/W	32	DMA fixed source address register_31
#define	SYSDMAC_DMAFIXDAR_31			0xE7308794	// R/W	32	DMA fixed destination address register_31
#define	SYSDMAC_DMAFIXDPBASE_31			0xE73087E0	// R/W	32	DMA fixed descriptor base address register_31
#define	SYSDMAC_DescriptorMEM_16_31		0xE730A000	// R/W	32	Descriptor memory (for channels 16 to 31)
#define	SYSDMAC_DMASES_1				0xE73000C0	// R/W	32	Secure function Secure Status register (for channels 16 to 31)
#define	SYSDMAC_DMASEA_1				0xE73000C4	// R/W	32	Secure function Slave Error Address register (for channels 16 to 31)
#define	SYSDMAC_DMAEMID_1				0xE73000C8	// R/W	32	Secure function Error Master ID register (for channels 16 to 31)
#define	SYSDMAC_DMAISTA_2				0xE7310020	// R	32	DMA interrupt status register (for channels 32 to 47)
#define	SYSDMAC_DMASEC_2				0xE7310030	// R/W	32	DMA secure control register (for channels 32 to 47)
#define	SYSDMAC_DMAOR_2					0xE7310060	// R/W	16	DMA operation register (for channels 32 to 47)
#define	SYSDMAC_DMACHCLR_2				0xE7310080	// W	32	DMA channel clear register (for channels 32 to 47)
#define	SYSDMAC_DMADPSEC_2				0xE73100A0	// R/W	32	DPRAM secure control register (for channels 32 to 47)
#define	SYSDMAC_DMASAR_32				0xE7318000	// R/W	32	DMA source address register_32
#define	SYSDMAC_DMADAR_32				0xE7318004	// R/W	32	DMA destination address register_32
#define	SYSDMAC_DMATCR_32				0xE7318008	// R/W	32	DMA transfer count register_32
#define	SYSDMAC_DMATSR_32				0xE7318028	// R/W	32	DMA transfer size register_32
#define	SYSDMAC_DMACHCR_32				0xE731800C	// R/W	32	DMA channel control register_32
#define	SYSDMAC_DMATCRB_32				0xE7318018	// R/W	32	DMA transfer count register B_32
#define	SYSDMAC_DMATSRB_32				0xE7318038	// R/W	32	DMA transfer size register B_32
#define	SYSDMAC_DMACHCRB_32				0xE731801C	// R/W	32	DMA channel control register B_32
#define	SYSDMAC_DMARS_32				0xE7318040	// R/W	16	DMA extended resource selector_32
#define	SYSDMAC_DMABUFCR_32				0xE7318048	// R/W	32	DMA buffer control register_32
#define	SYSDMAC_DMADPBASE_32			0xE7318050	// R/W	32	DMA descriptor base address register_32
#define	SYSDMAC_DMADPCR_32				0xE7318054	// R/W	32	DMA descriptor control register_32
#define	SYSDMAC_DMAFIXSAR_32			0xE7318010	// R/W	32	DMA fixed source address register_32
#define	SYSDMAC_DMAFIXDAR_32			0xE7318014	// R/W	32	DMA fixed destination address register_32
#define	SYSDMAC_DMAFIXDPBASE_32			0xE7318060	// R/W	32	DMA fixed descriptor base address register_32
#define	SYSDMAC_DMASAR_33				0xE7318080	// R/W	32	DMA source address register_33
#define	SYSDMAC_DMADAR_33				0xE7318084	// R/W	32	DMA destination address register_33
#define	SYSDMAC_DMATCR_33				0xE7318088	// R/W	32	DMA transfer count register_33
#define	SYSDMAC_DMATSR_33				0xE73180A8	// R/W	32	DMA transfer size register_33
#define	SYSDMAC_DMACHCR_33				0xE731808C	// R/W	32	DMA channel control register_33
#define	SYSDMAC_DMATCRB_33				0xE7318098	// R/W	32	DMA transfer count register B_33
#define	SYSDMAC_DMATSRB_33				0xE73180B8	// R/W	32	DMA transfer size register B_33
#define	SYSDMAC_DMACHCRB_33				0xE731809C	// R/W	32	DMA channel control register B_33
#define	SYSDMAC_DMARS_33				0xE73180C0	// R/W	16	DMA extended resource selector_33
#define	SYSDMAC_DMABUFCR_33				0xE73180C8	// R/W	32	DMA buffer control register_33
#define	SYSDMAC_DMADPBASE_33			0xE73180D0	// R/W	32	DMA descriptor base address register_33
#define	SYSDMAC_DMADPCR_33				0xE73180D4	// R/W	32	DMA descriptor control register_33
#define	SYSDMAC_DMAFIXDPBASE_33			0xE73180E0	// R/W	32	DMA fixed descriptor base address register_33
#define	SYSDMAC_DMAFIXSAR_33			0xE7318090	// R/W	32	DMA fixed source address register_33
#define	SYSDMAC_DMAFIXDAR_33			0xE7318094	// R/W	32	DMA fixed destination address register_33
#define	SYSDMAC_DMASAR_34				0xE7318100	// R/W	32	DMA source address register_34
#define	SYSDMAC_DMADAR_34				0xE7318104	// R/W	32	DMA destination address register_34
#define	SYSDMAC_DMATCR_34				0xE7318108	// R/W	32	DMA transfer count register_34
#define	SYSDMAC_DMATSR_34				0xE7318128	// R/W	32	DMA transfer size register_34
#define	SYSDMAC_DMACHCR_34				0xE731810C	// R/W	32	DMA channel control register_34
#define	SYSDMAC_DMATCRB_34				0xE7318118	// R/W	32	DMA transfer count register B_34
#define	SYSDMAC_DMATSRB_34				0xE7318138	// R/W	32	DMA transfer size register B_34
#define	SYSDMAC_DMACHCRB_34				0xE731811C	// R/W	32	DMA channel control register B_34
#define	SYSDMAC_DMARS_34				0xE7318140	// R/W	16	DMA extended resource selector_34
#define	SYSDMAC_DMABUFCR_34				0xE7318148	// R/W	32	DMA buffer control register_34
#define	SYSDMAC_DMADPBASE_34			0xE7318150	// R/W	32	DMA descriptor base address register_34
#define	SYSDMAC_DMADPCR_34				0xE7318154	// R/W	32	DMA descriptor control register_34
#define	SYSDMAC_DMAFIXSAR_34			0xE7318110	// R/W	32	DMA fixed source address register_34
#define	SYSDMAC_DMAFIXDAR_34			0xE7318114	// R/W	32	DMA fixed destination address register_34
#define	SYSDMAC_DMAFIXDPBASE_34			0xE7318160	// R/W	32	DMA fixed descriptor base address register_34
#define	SYSDMAC_DMASAR_35				0xE7318180	// R/W	32	DMA source address register_35
#define	SYSDMAC_DMADAR_35				0xE7318184	// R/W	32	DMA destination address register_35
#define	SYSDMAC_DMATCR_35				0xE7318188	// R/W	32	DMA transfer count register_35
#define	SYSDMAC_DMATSR_35				0xE73181A8	// R/W	32	DMA transfer size register_35
#define	SYSDMAC_DMACHCR_35				0xE731818C	// R/W	32	DMA channel control register_35
#define	SYSDMAC_DMATCRB_35				0xE7318198	// R/W	32	DMA transfer count register B_35
#define	SYSDMAC_DMATSRB_35				0xE73181B8	// R/W	32	DMA transfer size register B_35
#define	SYSDMAC_DMACHCRB_35				0xE731819C	// R/W	32	DMA channel control register B_35
#define	SYSDMAC_DMARS_35				0xE73181C0	// R/W	16	DMA extended resource selector_35
#define	SYSDMAC_DMABUFCR_35				0xE73181C8	// R/W	32	DMA buffer control register_35
#define	SYSDMAC_DMADPBASE_35			0xE73181D0	// R/W	32	DMA descriptor base address register_35
#define	SYSDMAC_DMADPCR_35				0xE73181D4	// R/W	32	DMA descriptor control register_35
#define	SYSDMAC_DMAFIXSAR_35			0xE7318190	// R/W	32	DMA fixed source address register_35
#define	SYSDMAC_DMAFIXDAR_35			0xE7318194	// R/W	32	DMA fixed destination address register_35
#define	SYSDMAC_DMAFIXDPBASE_35			0xE73181E0	// R/W	32	DMA fixed descriptor base address register_35
#define	SYSDMAC_DMASAR_36				0xE7318200	// R/W	32	DMA source address register_36
#define	SYSDMAC_DMADAR_36				0xE7318204	// R/W	32	DMA destination address register_36
#define	SYSDMAC_DMATCR_36				0xE7318208	// R/W	32	DMA transfer count register_36
#define	SYSDMAC_DMATSR_36				0xE7318228	// R/W	32	DMA transfer size register_36
#define	SYSDMAC_DMACHCR_36				0xE731820C	// R/W	32	DMA channel control register_36
#define	SYSDMAC_DMATCRB_36				0xE7318218	// R/W	32	DMA transfer count register B_36
#define	SYSDMAC_DMATSRB_36				0xE7318238	// R/W	32	DMA transfer size register B_36
#define	SYSDMAC_DMACHCRB_36				0xE731821C	// R/W	32	DMA channel control register B_36
#define	SYSDMAC_DMARS_36				0xE7318240	// R/W	16	DMA extended resource selector_36
#define	SYSDMAC_DMABUFCR_36				0xE7318248	// R/W	32	DMA buffer control register_36
#define	SYSDMAC_DMADPBASE_36			0xE7318250	// R/W	32	DMA descriptor base address register_36
#define	SYSDMAC_DMADPCR_36				0xE7318254	// R/W	32	DMA descriptor control register_36
#define	SYSDMAC_DMAFIXSAR_36			0xE7318210	// R/W	32	DMA fixed source address register_36
#define	SYSDMAC_DMAFIXDAR_36			0xE7318214	// R/W	32	DMA fixed destination address register_36
#define	SYSDMAC_DMAFIXDPBASE_36			0xE7318260	// R/W	32	DMA fixed descriptor base address register_36
#define	SYSDMAC_DMASAR_37				0xE7318280	// R/W	32	DMA source address register_37
#define	SYSDMAC_DMADAR_37				0xE7318284	// R/W	32	DMA destination address register_37
#define	SYSDMAC_DMATCR_37				0xE7318288	// R/W	32	DMA transfer count register_37
#define	SYSDMAC_DMATSR_37				0xE73182A8	// R/W	32	DMA transfer size register_37
#define	SYSDMAC_DMACHCR_37				0xE731828C	// R/W	32	DMA channel control register_37
#define	SYSDMAC_DMATCRB_37				0xE7318298	// R/W	32	DMA transfer count register B_37
#define	SYSDMAC_DMATSRB_37				0xE73182B8	// R/W	32	DMA transfer size register B_37
#define	SYSDMAC_DMACHCRB_37				0xE731829C	// R/W	32	DMA channel control register B_37
#define	SYSDMAC_DMARS_37				0xE73182C0	// R/W	16	DMA extended resource selector_37
#define	SYSDMAC_DMABUFCR_37				0xE73182C8	// R/W	32	DMA buffer control register_37
#define	SYSDMAC_DMADPBASE_37			0xE73182D0	// R/W	32	DMA descriptor base address register_37
#define	SYSDMAC_DMADPCR_37				0xE73182D4	// R/W	32	DMA descriptor control register_37
#define	SYSDMAC_DMAFIXSAR_37			0xE7318290	// R/W	32	DMA fixed source address register_37
#define	SYSDMAC_DMAFIXDAR_37			0xE7318294	// R/W	32	DMA fixed destination address register_37
#define	SYSDMAC_DMAFIXDPBASE_37			0xE73182E0	// R/W	32	DMA fixed descriptor base address register_37
#define	SYSDMAC_DMASAR_38				0xE7318300	// R/W	32	DMA source address register_38
#define	SYSDMAC_DMADAR_38				0xE7318304	// R/W	32	DMA destination address register_38
#define	SYSDMAC_DMATCR_38				0xE7318308	// R/W	32	DMA transfer count register_38
#define	SYSDMAC_DMATSR_38				0xE7318328	// R/W	32	DMA transfer size register_38
#define	SYSDMAC_DMACHCR_38				0xE731830C	// R/W	32	DMA channel control register_38
#define	SYSDMAC_DMATCRB_38				0xE7318318	// R/W	32	DMA transfer count register B_38
#define	SYSDMAC_DMATSRB_38				0xE7318338	// R/W	32	DMA transfer size register B_38
#define	SYSDMAC_DMACHCRB_38				0xE731831C	// R/W	32	DMA channel control register B_38
#define	SYSDMAC_DMARS_38				0xE7318340	// R/W	16	DMA extended resource selector_38
#define	SYSDMAC_DMABUFCR_38				0xE7318348	// R/W	32	DMA buffer control register_38
#define	SYSDMAC_DMADPBASE_38			0xE7318350	// R/W	32	DMA descriptor base address register_38
#define	SYSDMAC_DMADPCR_38				0xE7318354	// R/W	32	DMA descriptor control register_38
#define	SYSDMAC_DMAFIXSAR_38			0xE7318310	// R/W	32	DMA fixed source address register_38
#define	SYSDMAC_DMAFIXDAR_38			0xE7318314	// R/W	32	DMA fixed destination address register_38
#define	SYSDMAC_DMAFIXDPBASE_38			0xE7318360	// R/W	32	DMA fixed descriptor base address register_38
#define	SYSDMAC_DMASAR_39				0xE7318380	// R/W	32	DMA source address register_39
#define	SYSDMAC_DMADAR_39				0xE7318384	// R/W	32	DMA destination address register_39
#define	SYSDMAC_DMATCR_39				0xE7318388	// R/W	32	DMA transfer count register_39
#define	SYSDMAC_DMATSR_39				0xE73183A8	// R/W	32	DMA transfer size register_39
#define	SYSDMAC_DMACHCR_39				0xE731838C	// R/W	32	DMA channel control register_39
#define	SYSDMAC_DMATCRB_39				0xE7318398	// R/W	32	DMA transfer count register B_39
#define	SYSDMAC_DMATSRB_39				0xE73183B8	// R/W	32	DMA transfer size register B_39
#define	SYSDMAC_DMACHCRB_39				0xE731839C	// R/W	32	DMA channel control register B_39
#define	SYSDMAC_DMARS_39				0xE73183C0	// R/W	16	DMA extended resource selector_39
#define	SYSDMAC_DMABUFCR_39				0xE73183C8	// R/W	32	DMA buffer control register_39
#define	SYSDMAC_DMADPBASE_39			0xE73183D0	// R/W	32	DMA descriptor base address register_39
#define	SYSDMAC_DMADPCR_39				0xE73183D4	// R/W	32	DMA descriptor control register_39
#define	SYSDMAC_DMAFIXSAR_39			0xE7318390	// R/W	32	DMA fixed source address register_39
#define	SYSDMAC_DMAFIXDAR_39			0xE7318394	// R/W	32	DMA fixed destination address register_39
#define	SYSDMAC_DMAFIXDPBASE_39			0xE73183E0	// R/W	32	DMA fixed descriptor base address register_39
#define	SYSDMAC_DMASAR_40				0xE7318400	// R/W	32	DMA source address register_40
#define	SYSDMAC_DMADAR_40				0xE7318404	// R/W	32	DMA destination address register_40
#define	SYSDMAC_DMATCR_40				0xE7318408	// R/W	32	DMA transfer count register_40
#define	SYSDMAC_DMATSR_40				0xE7318428	// R/W	32	DMA transfer size register_40
#define	SYSDMAC_DMACHCR_40				0xE731840C	// R/W	32	DMA channel control register_40
#define	SYSDMAC_DMATCRB_40				0xE7318418	// R/W	32	DMA transfer count register B_40
#define	SYSDMAC_DMATSRB_40				0xE7318438	// R/W	32	DMA transfer size register B_40
#define	SYSDMAC_DMACHCRB_40				0xE731841C	// R/W	32	DMA channel control register B_40
#define	SYSDMAC_DMARS_40				0xE7318440	// R/W	16	DMA extended resource selector_40
#define	SYSDMAC_DMABUFCR_40				0xE7318448	// R/W	32	DMA buffer control register_40
#define	SYSDMAC_DMADPBASE_40			0xE7318450	// R/W	32	DMA descriptor base address register_40
#define	SYSDMAC_DMADPCR_40				0xE7318454	// R/W	32	DMA descriptor control register_40
#define	SYSDMAC_DMAFIXSAR_40			0xE7318410	// R/W	32	DMA fixed source address register_40
#define	SYSDMAC_DMAFIXDAR_40			0xE7318414	// R/W	32	DMA fixed destination address register_40
#define	SYSDMAC_DMAFIXDPBASE_40			0xE7318460	// R/W	32	DMA fixed descriptor base address register_40
#define	SYSDMAC_DMASAR_41				0xE7318480	// R/W	32	DMA source address register_41
#define	SYSDMAC_DMADAR_41				0xE7318484	// R/W	32	DMA destination address register_41
#define	SYSDMAC_DMATCR_41				0xE7318488	// R/W	32	DMA transfer count register_41
#define	SYSDMAC_DMATSR_41				0xE73184A8	// R/W	32	DMA transfer size register_41
#define	SYSDMAC_DMACHCR_41				0xE731848C	// R/W	32	DMA channel control register_41
#define	SYSDMAC_DMATCRB_41				0xE7318498	// R/W	32	DMA transfer count register B_41
#define	SYSDMAC_DMATSRB_41				0xE73184B8	// R/W	32	DMA transfer size register B_41
#define	SYSDMAC_DMACHCRB_41				0xE731849C	// R/W	32	DMA channel control register B_41
#define	SYSDMAC_DMARS_41				0xE73184C0	// R/W	16	DMA extended resource selector_41
#define	SYSDMAC_DMABUFCR_41				0xE73184C8	// R/W	32	DMA buffer control register_41
#define	SYSDMAC_DMADPBASE_41			0xE73184D0	// R/W	32	DMA descriptor base address register_41
#define	SYSDMAC_DMADPCR_41				0xE73184D4	// R/W	32	DMA descriptor control register_41
#define	SYSDMAC_DMAFIXSAR_41			0xE7318490	// R/W	32	DMA fixed source address register_41
#define	SYSDMAC_DMAFIXDAR_41			0xE7318494	// R/W	32	DMA fixed destination address register_41
#define	SYSDMAC_DMAFIXDPBASE_41			0xE73184E0	// R/W	32	DMA fixed descriptor base address register_41
#define	SYSDMAC_DMASAR_42				0xE7318500	// R/W	32	DMA source address register_42
#define	SYSDMAC_DMADAR_42				0xE7318504	// R/W	32	DMA destination address register_42
#define	SYSDMAC_DMATCR_42				0xE7318508	// R/W	32	DMA transfer count register_42
#define	SYSDMAC_DMATSR_42				0xE7318528	// R/W	32	DMA transfer size register_42
#define	SYSDMAC_DMACHCR_42				0xE731850C	// R/W	32	DMA channel control register_42
#define	SYSDMAC_DMATCRB_42				0xE7318518	// R/W	32	DMA transfer count register B_42
#define	SYSDMAC_DMATSRB_42				0xE7318538	// R/W	32	DMA transfer size register B_42
#define	SYSDMAC_DMACHCRB_42				0xE731851C	// R/W	32	DMA channel control register B_42
#define	SYSDMAC_DMARS_42				0xE7318540	// R/W	16	DMA extended resource selector_42
#define	SYSDMAC_DMABUFCR_42				0xE7318548	// R/W	32	DMA buffer control register_42
#define	SYSDMAC_DMADPBASE_42			0xE7318550	// R/W	32	DMA descriptor base address register_42
#define	SYSDMAC_DMADPCR_42				0xE7318554	// R/W	32	DMA descriptor control register_42
#define	SYSDMAC_DMAFIXSAR_42			0xE7318510	// R/W	32	DMA fixed source address register_42
#define	SYSDMAC_DMAFIXDAR_42			0xE7318514	// R/W	32	DMA fixed destination address register_42
#define	SYSDMAC_DMAFIXDPBASE_42			0xE7318560	// R/W	32	DMA fixed descriptor base address register_42
#define	SYSDMAC_DMASAR_43				0xE7318580	// R/W	32	DMA source address register_43
#define	SYSDMAC_DMADAR_43				0xE7318584	// R/W	32	DMA destination address register_43
#define	SYSDMAC_DMATCR_43				0xE7318588	// R/W	32	DMA transfer count register_43
#define	SYSDMAC_DMATSR_43				0xE73185A8	// R/W	32	DMA transfer size register_43
#define	SYSDMAC_DMACHCR_43				0xE731858C	// R/W	32	DMA channel control register_43
#define	SYSDMAC_DMATCRB_43				0xE7318598	// R/W	32	DMA transfer count register B_43
#define	SYSDMAC_DMATSRB_43				0xE73185B8	// R/W	32	DMA transfer size register B_43
#define	SYSDMAC_DMACHCRB_43				0xE731859C	// R/W	32	DMA channel control register B_43
#define	SYSDMAC_DMARS_43				0xE73185C0	// R/W	16	DMA extended resource selector_43
#define	SYSDMAC_DMABUFCR_43				0xE73185C8	// R/W	32	DMA buffer control register_43
#define	SYSDMAC_DMADPBASE_43			0xE73185D0	// R/W	32	DMA descriptor base address register_43
#define	SYSDMAC_DMADPCR_43				0xE73185D4	// R/W	32	DMA descriptor control register_43
#define	SYSDMAC_DMAFIXSAR_43			0xE7318590	// R/W	32	DMA fixed source address register_43
#define	SYSDMAC_DMAFIXDAR_43			0xE7318594	// R/W	32	DMA fixed destination address register_43
#define	SYSDMAC_DMAFIXDPBASE_43			0xE73185E0	// R/W	32	DMA fixed descriptor base address register_43
#define	SYSDMAC_DMASAR_44				0xE7318600	// R/W	32	DMA source address register_44
#define	SYSDMAC_DMADAR_44				0xE7318604	// R/W	32	DMA destination address register_44
#define	SYSDMAC_DMATCR_44				0xE7318608	// R/W	32	DMA transfer count register_44
#define	SYSDMAC_DMATSR_44				0xE7318628	// R/W	32	DMA transfer size register_44
#define	SYSDMAC_DMACHCR_44				0xE731860C	// R/W	32	DMA channel control register_44
#define	SYSDMAC_DMATCRB_44				0xE7318618	// R/W	32	DMA transfer count register B_44
#define	SYSDMAC_DMATSRB_44				0xE7318638	// R/W	32	DMA transfer size register B_44
#define	SYSDMAC_DMACHCRB_44				0xE731861C	// R/W	32	DMA channel control register B_44
#define	SYSDMAC_DMARS_44				0xE7318640	// R/W	16	DMA extended resource selector_44
#define	SYSDMAC_DMABUFCR_44				0xE7318648	// R/W	32	DMA buffer control register_44
#define	SYSDMAC_DMADPBASE_44			0xE7318650	// R/W	32	DMA descriptor base address register_44
#define	SYSDMAC_DMADPCR_44				0xE7318654	// R/W	32	DMA descriptor control register_44
#define	SYSDMAC_DMAFIXSAR_44			0xE7318610	// R/W	32	DMA fixed source address register_44
#define	SYSDMAC_DMAFIXDAR_44			0xE7318614	// R/W	32	DMA fixed destination address register_44
#define	SYSDMAC_DMAFIXDPBASE_44			0xE7318660	// R/W	32	DMA fixed descriptor base address register_44
#define	SYSDMAC_DMASAR_45				0xE7318680	// R/W	32	DMA source address register_45
#define	SYSDMAC_DMADAR_45				0xE7318684	// R/W	32	DMA destination address register_45
#define	SYSDMAC_DMATCR_45				0xE7318688	// R/W	32	DMA transfer count register_45
#define	SYSDMAC_DMATSR_45				0xE73186A8	// R/W	32	DMA transfer size register_45
#define	SYSDMAC_DMACHCR_45				0xE731868C	// R/W	32	DMA channel control register_45
#define	SYSDMAC_DMATCRB_45				0xE7318698	// R/W	32	DMA transfer count register B_45
#define	SYSDMAC_DMATSRB_45				0xE73186B8	// R/W	32	DMA transfer size register B_45
#define	SYSDMAC_DMACHCRB_45				0xE731869C	// R/W	32	DMA channel control register B_45
#define	SYSDMAC_DMARS_45				0xE73186C0	// R/W	16	DMA extended resource selector_45
#define	SYSDMAC_DMABUFCR_45				0xE73186C8	// R/W	32	DMA buffer control register_45
#define	SYSDMAC_DMADPBASE_45			0xE73186D0	// R/W	32	DMA descriptor base address register_45
#define	SYSDMAC_DMADPCR_45				0xE73186D4	// R/W	32	DMA descriptor control register_45
#define	SYSDMAC_DMAFIXSAR_45			0xE7318690	// R/W	32	DMA fixed source address register_45
#define	SYSDMAC_DMAFIXDAR_45			0xE7318694	// R/W	32	DMA fixed destination address register_45
#define	SYSDMAC_DMAFIXDPBASE_45			0xE73186E0	// R/W	32	DMA fixed descriptor base address register_45
#define	SYSDMAC_DMASAR_46				0xE7318700	// R/W	32	DMA source address register_46
#define	SYSDMAC_DMADAR_46				0xE7318704	// R/W	32	DMA destination address register_46
#define	SYSDMAC_DMATCR_46				0xE7318708	// R/W	32	DMA transfer count register_46
#define	SYSDMAC_DMATSR_46				0xE7318728	// R/W	32	DMA transfer size register_46
#define	SYSDMAC_DMACHCR_46				0xE731870C	// R/W	32	DMA channel control register_46
#define	SYSDMAC_DMATCRB_46				0xE7318718	// R/W	32	DMA transfer count register B_46
#define	SYSDMAC_DMATSRB_46				0xE7318738	// R/W	32	DMA transfer size register B_46
#define	SYSDMAC_DMACHCRB_46				0xE731871C	// R/W	32	DMA channel control register B_46
#define	SYSDMAC_DMARS_46				0xE7318740	// R/W	16	DMA extended resource selector_46
#define	SYSDMAC_DMABUFCR_46				0xE7318748	// R/W	32	DMA buffer control register_46
#define	SYSDMAC_DMADPBASE_46			0xE7318750	// R/W	32	DMA descriptor base address register_46
#define	SYSDMAC_DMADPCR_46				0xE7318754	// R/W	32	DMA descriptor control register_46
#define	SYSDMAC_DMAFIXSAR_46			0xE7318710	// R/W	32	DMA fixed source address register_46
#define	SYSDMAC_DMAFIXDAR_46			0xE7318714	// R/W	32	DMA fixed destination address register_46
#define	SYSDMAC_DMAFIXDPBASE_46			0xE7318760	// R/W	32	DMA fixed descriptor base address register_46
#define	SYSDMAC_DMASAR_47				0xE7318780	// R/W	32	DMA source address register_47
#define	SYSDMAC_DMADAR_47				0xE7318784	// R/W	32	DMA destination address register_47
#define	SYSDMAC_DMATCR_47				0xE7318788	// R/W	32	DMA transfer count register_47
#define	SYSDMAC_DMATSR_47				0xE73187A8	// R/W	32	DMA transfer size register_47
#define	SYSDMAC_DMACHCR_47				0xE731878C	// R/W	32	DMA channel control register_47
#define	SYSDMAC_DMATCRB_47				0xE7318798	// R/W	32	DMA transfer count register B_47
#define	SYSDMAC_DMATSRB_47				0xE73187B8	// R/W	32	DMA transfer size register B_47
#define	SYSDMAC_DMACHCRB_47				0xE731879C	// R/W	32	DMA channel control register B_47
#define	SYSDMAC_DMARS_47				0xE73187C0	// R/W	16	DMA extended resource selector_47
#define	SYSDMAC_DMABUFCR_47				0xE73187C8	// R/W	32	DMA buffer control register_47
#define	SYSDMAC_DMADPBASE_47			0xE73187D0	// R/W	32	DMA descriptor base address register_47
#define	SYSDMAC_DMADPCR_47				0xE73187D4	// R/W	32	DMA descriptor control register_47
#define	SYSDMAC_DMAFIXSAR_47			0xE7318790	// R/W	32	DMA fixed source address register_47
#define	SYSDMAC_DMAFIXDAR_47			0xE7318794	// R/W	32	DMA fixed destination address register_47
#define	SYSDMAC_DMAFIXDPBASE_47			0xE73187E0	// R/W	32	DMA fixed descriptor base address register_47
#define	SYSDMAC_DescriptorMEM_32_47		0xE731A000	// R/W	32	Descriptor memory (for channels 32 to 47)
#define	SYSDMAC_DMASES_2				0xE73100C0	// R/W	32	Secure function Secure Status register (for channels 32 to 47)
#define	SYSDMAC_DMASEA_2				0xE73100C4	// R/W	32	Secure function Slave Error Address register (for channels 32 to 47)
#define	SYSDMAC_DMAEMID_2				0xE73100C8	// R/W	32	Secure function Error Master ID register (for channels 32 to 47)
#define	SYSDMAC_FDSDM_ENABLE			0xE73000D0	// R/W	32	Failure detection function enable register
#define	SYSDMAC_FDSDM_STATUS			0xE73000D4	// R/W	32	Failure detection error status register


//TMU
#define	TMU_TSTR0						0xE61E0004	// R/W	8	Timer start register 0
#define	TMU_TCOR0						0xE61E0008	// R/W	32	Timer constant register 0
#define	TMU_TCNT0						0xE61E000C	// R/W	32	Timer counter 0
#define	TMU_TCR0						0xE61E0010	// R/W	16	Timer control register 0
#define	TMU_TCOR1						0xE61E0014	// R/W	32	Timer constant register 1
#define	TMU_TCNT1						0xE61E0018	// R/W	32	Timer counter 1
#define	TMU_TCR1						0xE61E001C	// R/W	16	Timer control register 1
#define	TMU_TCOR2						0xE61E0020	// R/W	32	Timer constant register 2
#define	TMU_TCNT2						0xE61E0024	// R/W	32	Timer counter 2
#define	TMU_TCR2						0xE61E0028	// R/W	16	Timer control register 2
#define	TMU_TSTR1						0xE6FC0004	// R/W	8	Timer start register 1
#define	TMU_TCOR3						0xE6FC0008	// R/W	32	Timer constant register 3
#define	TMU_TCNT3						0xE6FC000C	// R/W	32	Timer counter 3
#define	TMU_TCR3						0xE6FC0010	// R/W	16	Timer control register 3
#define	TMU_TCOR4						0xE6FC0014	// R/W	32	Timer constant register 4
#define	TMU_TCNT4						0xE6FC0018	// R/W	32	Timer counter 4
#define	TMU_TCR4						0xE6FC001C	// R/W	16	Timer control register 4
#define	TMU_TCOR5						0xE6FC0020	// R/W	32	Timer constant register 5
#define	TMU_TCNT5						0xE6FC0024	// R/W	32	Timer counter 5
#define	TMU_TCR5						0xE6FC0028	// R/W	16	Timer control register 5
#define	TMU_TCPR5						0xE6FC002C	// R	32	Input capture register 5
#define	TMU_TSTR2						0xE6FD0004	// R/W	8	Timer start register 2
#define	TMU_TCOR6						0xE6FD0008	// R/W	32	Timer constant register 6
#define	TMU_TCNT6						0xE6FD000C	// R/W	32	Timer counter 6
#define	TMU_TCR6						0xE6FD0010	// R/W	16	Timer control register 6
#define	TMU_TCOR7						0xE6FD0014	// R/W	32	Timer constant register 7
#define	TMU_TCNT7						0xE6FD0018	// R/W	32	Timer counter 7
#define	TMU_TCR7						0xE6FD001C	// R/W	16	Timer control register 7
#define	TMU_TCOR8						0xE6FD0020	// R/W	32	Timer constant register 8
#define	TMU_TCNT8						0xE6FD0024	// R/W	32	Timer counter 8
#define	TMU_TCR8						0xE6FD0028	// R/W	16	Timer control register 8
#define	TMU_TCPR8						0xE6FD002C	// R	32	Input capture register 8
#define	TMU_TSTR3						0xE6FE0004	// R/W	8	Timer start register 3
#define	TMU_TCOR9						0xE6FE0008	// R/W	32	Timer constant register 9
#define	TMU_TCNT9						0xE6FE000C	// R/W	32	Timer counter 9
#define	TMU_TCR9						0xE6FE0010	// R/W	16	Timer control register 9
#define	TMU_TCOR10						0xE6FE0014	// R/W	32	Timer constant register 10
#define	TMU_TCNT10						0xE6FE0018	// R/W	32	Timer counter 10
#define	TMU_TCR10						0xE6FE001C	// R/W	16	Timer control register 10
#define	TMU_TCOR11						0xE6FE0020	// R/W	32	Timer constant register 11
#define	TMU_TCNT11						0xE6FE0024	// R/W	32	Timer counter 11
#define	TMU_TCR11						0xE6FE0028	// R/W	16	Timer control register 11
#define	TMU_TCPR11						0xE6FE002C	// R	32	Input capture register 11
#define	TMU_TSTR4						0xFFC00004	// R/W	8	Timer start register 12
#define	TMU_TCOR12						0xFFC00008	// R/W	32	Timer constant register 12
#define	TMU_TCNT12						0xFFC0000C	// R/W	32	Timer counter 12
#define	TMU_TCR12						0xFFC00010	// R/W	16	Timer control register 12
#define	TMU_TCOR13						0xFFC00014	// R/W	32	Timer constant register 13
#define	TMU_TCNT13						0xFFC00018	// R/W	32	Timer counter 13
#define	TMU_TCR13						0xFFC0001C	// R/W	16	Timer control register 13
#define	TMU_TCOR14						0xFFC00020	// R/W	32	Timer constant register 14
#define	TMU_TCNT14						0xFFC00024	// R/W	32	Timer counter 14
#define	TMU_TCR14						0xFFC00028	// R/W	16	Timer control register 14







// Appendix A.
#define	PRR								0xFFF00044	// R	32	Product Register
#define PRR_PRODUCT_MASK	(0x00007F00U)
#define PRR_CUT_MASK		(0x000000FFU)
#define PRR_PRODUCT_H3		(0x00004F00U)           /* R-Car H3 */
#define PRR_PRODUCT_M3		(0x00005200U)           /* R-Car M3 */
#define PRR_CUT_10		(0x00U)
#define PRR_CUT_11		(0x01U)
#define PRR_CUT_20		(0x10U)
