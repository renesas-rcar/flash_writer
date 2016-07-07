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


//ADG
#define	ADG_BRRA						0xEC5A0000	// R/W	32	BRGA baud rate setting register
#define	ADG_BRRB						0xEC5A0004	// R/W	32	BRGB baud rate setting register
#define	ADG_BRGCKR						0xEC5A0008	// R/W	32	BRG Clock Select Register
#define	ADG_AUDIO_CLK_SEL0				0xEC5A000C	// R/W	32	Audio clock select register 0
#define	ADG_AUDIO_CLK_SEL1				0xEC5A0010	// R/W	32	Audio clock select register 1
#define	ADG_AUDIO_CLK_SEL2				0xEC5A0014	// R/W	32	Audio clock select register 2
#define	ADG_DIV_EN						0xEC5A0030	// R/W	32	Audio clock frequency division enable register
#define	ADG_SRCIN_TIMSEL0				0xEC5A0034	// R/W	32	SRC input timing select register 0
#define	ADG_SRCIN_TIMSEL1				0xEC5A0038	// R/W	32	SRC input timing select register 1
#define	ADG_SRCIN_TIMSEL2				0xEC5A003C	// R/W	32	SRC input timing select register 2
#define	ADG_SRCIN_TIMSEL3				0xEC5A0040	// R/W	32	SRC input timing select register 3
#define	ADG_SRCIN_TIMSEL4				0xEC5A0044	// R/W	32	SRC input timing select register 4
#define	ADG_SRCOUT_TIMSEL0				0xEC5A0048	// R/W	32	SRC output timing select register 0
#define	ADG_SRCOUT_TIMSEL1				0xEC5A004C	// R/W	32	SRC output timing select register 1
#define	ADG_SRCOUT_TIMSEL2				0xEC5A0050	// R/W	32	SRC output timing select register 2
#define	ADG_SRCOUT_TIMSEL3				0xEC5A0054	// R/W	32	SRC output timing select register 3
#define	ADG_SRCOUT_TIMSEL4				0xEC5A0058	// R/W	32	SRC output timing select register 4
#define	ADG_CMDOUT_TIMSEL				0xEC5A005C	// R/W	32	CMD output timing select register
#define	ADG_ADSP_TIMSEL					0xEC5A0060	// R/W	32	ADSP outputtiming select register
#define	ADG_DTCP_TIMSEL					0xEC5A0064	// R/W	32	DTCP timing select register
#define	ADG_ADSP_TIMSEL1				0xEC5A0080	// R/W	32	ADSP outputtiming select register1
#define	ADG_ADSP_TIMSEL2				0xEC5A0084	// R/W	32	ADSP outputtiming select register2
#define	ADG_ADSP_TIMSEL3				0xEC5A0088	// R/W	32	ADSP outputtiming select register3
#define	ADG_SSICKR1						0xEC5A0100	// R/W	32	Clock select register1
#define	ADG_AVB_SYNC_SEL0				0xEC5A0104	// R/W	32	AVB sync Select register0
#define	ADG_AVB_SYNC_SEL1				0xEC5A010C	// R/W	32	AVB sync Select register1
#define	ADG_AVB_SYNC_SEL2				0xEC5A0110	// R/W	32	AVB sync Select register2
#define	ADG_AVB_SYNC_DIV0				0xEC5A0114	// R/W	32	AVB sync divide register0
#define	ADG_AVB_SYNC_DIV1				0xEC5A0118	// R/W	32	AVB sync divide  register1
#define	ADG_AVB_CLK_DIV0				0xEC5A011C	// R/W	32	AVB clock divider comparison value register0
#define	ADG_AVB_CLK_DIV1				0xEC5A0120	// R/W	32	AVB clock divider comparison value register1
#define	ADG_AVB_CLK_DIV2				0xEC5A0124	// R/W	32	AVB clock divider comparison value register2
#define	ADG_AVB_CLK_DIV3				0xEC5A0128	// R/W	32	AVB clock divider comparison value register3
#define	ADG_AVB_CLK_DIV4				0xEC5A012C	// R/W	32	AVB clock divider comparison value register4
#define	ADG_AVB_CLK_DIV5				0xEC5A0130	// R/W	32	AVB clock divider comparison value register5
#define	ADG_AVB_CLK_DIV6				0xEC5A0134	// R/W	32	AVB clock divider comparison value register6
#define	ADG_AVB_CLK_DIV7				0xEC5A0138	// R/W	32	AVB clock divider comparison value register7
#define	ADG_AVB_CLK_CONFIG				0xEC5A013C	// R/W	32	AVB clock divider configuration register
#define	ADG_AVB_CLK_STATUS				0xEC5A0140	// R/WC1	32	AVB clock divider status register



//ADMA
#define	ADMA_DMAISTA_L					0xEC700020	// R	32	DMA interrupt status register (for lower-numbered channels)
#define	ADMA_DMASEC_L					0xEC700030	// R/W	32	DMA secure control register (for lower-numbered channels)
#define	ADMA_DMAOR_L					0xEC700060	// R/W	16	DMA operation register (for lower-numbered channels)
#define	ADMA_DMACHCLR_L					0xEC700080	// W	32	DMA channel clear register (for lower-numbered channels)
#define	ADMA_DMADPSEC_L					0xEC7000A0	// R/W	32	DPRAM secure control register (for lower-numbered channels)
#define	ADMA_DMASAR_0					0xEC708000	// R/W	32	DMA source address register_0
#define	ADMA_DMASAR_0_TSR				0xEC708020	// R/W	32	DMA source address register_0
#define	ADMA_DMADAR_0					0xEC708004	// R/W	32	DMA destination address register_0
#define	ADMA_DMADAR_0_TSR				0xEC708024	// R/W	32	DMA destination address register_0
#define	ADMA_DMATCR_0					0xEC708008	// R/W	32	DMA transfer count register_0
#define	ADMA_DMATSR_0					0xEC708028	// R/W	32	DMA transfer size register_0
#define	ADMA_DMACHCR_0					0xEC70800C	// R/W	32	DMA channel control register_0
#define	ADMA_DMACHCR_0_TSR				0xEC70802C	// R/W	32	DMA channel control register_0
#define	ADMA_DMATCRB_0					0xEC708018	// R/W	32	DMA transfer count register B_0
#define	ADMA_DMATSRB_0					0xEC708038	// R/W	32	DMA transfer size register B_0
#define	ADMA_DMACHCRB_0					0xEC70801C	// R/W	32	DMA channel control register B_0
#define	ADMA_DMARS_0					0xEC708040	// R/W	16	DMA extended resource selector_0
#define	ADMA_DMABUFCR_0					0xEC708048	// R/W	32	DMA buffer control register_0
#define	ADMA_DMADPBASE_0				0xEC708050	// R/W	32	DMA descriptor base address register_0
#define	ADMA_DMADPCR_0					0xEC708054	// R/W	32	DMA descriptor control register_0
#define	ADMA_DMAFIXSAR_0				0xEC708010	// R/W	32	DMA fixed source address register_0
#define	ADMA_DMAFIXDAR_0				0xEC708014	// R/W	32	DMA fixed destination address register_0
#define	ADMA_DMAFIXDPBASE_0				0xEC708060	// R/W	32	DMA fixed descriptor base address register_0
#define	ADMA_DMASAR_1					0xEC708080	// R/W	32	DMA source address register_1
#define	ADMA_DMASAR_1_TSR				0xEC7080A0	// R/W	32	DMA source address register_1
#define	ADMA_DMADAR_1					0xEC708084	// R/W	32	DMA destination address register_1
#define	ADMA_DMADAR_1_TSR				0xEC7080A4	// R/W	32	DMA destination address register_1
#define	ADMA_DMATCR_1					0xEC708088	// R/W	32	DMA transfer count register_1
#define	ADMA_DMATSR_1					0xEC7080A8	// R/W	32	DMA transfer size register_1
#define	ADMA_DMACHCR_1					0xEC70808C	// R/W	32	DMA channel control register_1
#define	ADMA_DMACHCR_1_TSR				0xEC7080AC	// R/W	32	DMA channel control register_1
#define	ADMA_DMATCRB_1					0xEC708098	// R/W	32	DMA transfer count register B_1
#define	ADMA_DMATSRB_1					0xEC7080B8	// R/W	32	DMA transfer size register B_1
#define	ADMA_DMACHCRB_1					0xEC70809C	// R/W	32	DMA channel control register B_1
#define	ADMA_DMARS_1					0xEC7080C0	// R/W	16	DMA extended resource selector_1
#define	ADMA_DMABUFCR_1					0xEC7080C8	// R/W	32	DMA buffer control register_1
#define	ADMA_DMADPBASE_1				0xEC7080D0	// R/W	32	DMA descriptor base address register_1
#define	ADMA_DMADPCR_1					0xEC7080D4	// R/W	32	DMA descriptor control register_1
#define	ADMA_DMAFIXDPBASE_1				0xEC7080E0	// R/W	32	DMA fixed descriptor base address register_1
#define	ADMA_DMAFIXSAR_1				0xEC708090	// R/W	32	DMA fixed source address register_1
#define	ADMA_DMAFIXDAR_1				0xEC708094	// R/W	32	DMA fixed destination address register_1
#define	ADMA_DMASAR_2					0xEC708100	// R/W	32	DMA source address register_2
#define	ADMA_DMASAR_2_TSR				0xEC708120	// R/W	32	DMA source address register_2
#define	ADMA_DMADAR_2					0xEC708104	// R/W	32	DMA destination address register_2
#define	ADMA_DMADAR_2_TSR				0xEC708124	// R/W	32	DMA destination address register_2
#define	ADMA_DMATCR_2					0xEC708108	// R/W	32	DMA transfer count register_2
#define	ADMA_DMATSR_2					0xEC708128	// R/W	32	DMA transfer size register_2
#define	ADMA_DMACHCR_2					0xEC70810C	// R/W	32	DMA channel control register_2
#define	ADMA_DMACHCR_2_TSR				0xEC70812C	// R/W	32	DMA channel control register_2
#define	ADMA_DMATCRB_2					0xEC708118	// R/W	32	DMA transfer count register B_2
#define	ADMA_DMATSRB_2					0xEC708138	// R/W	32	DMA transfer size register B_2
#define	ADMA_DMACHCRB_2					0xEC70811C	// R/W	32	DMA channel control register B_2
#define	ADMA_DMARS_2					0xEC708140	// R/W	16	DMA extended resource selector_2
#define	ADMA_DMABUFCR_2					0xEC708148	// R/W	32	DMA buffer control register_2
#define	ADMA_DMADPBASE_2				0xEC708150	// R/W	32	DMA descriptor base address register_2
#define	ADMA_DMADPCR_2					0xEC708154	// R/W	32	DMA descriptor control register_2
#define	ADMA_DMAFIXSAR_2				0xEC708110	// R/W	32	DMA fixed source address register_2
#define	ADMA_DMAFIXDAR_2				0xEC708114	// R/W	32	DMA fixed destination address register_2
#define	ADMA_DMAFIXDPBASE_2				0xEC708160	// R/W	32	DMA fixed descriptor base address register_2
#define	ADMA_DMASAR_3					0xEC708180	// R/W	32	DMA source address register_3
#define	ADMA_DMASAR_3_TSR				0xEC7081A0	// R/W	32	DMA source address register_3
#define	ADMA_DMADAR_3					0xEC708184	// R/W	32	DMA destination address register_3
#define	ADMA_DMADAR_3_TSR				0xEC7081A4	// R/W	32	DMA destination address register_3
#define	ADMA_DMATCR_3					0xEC708188	// R/W	32	DMA transfer count register_3
#define	ADMA_DMATSR_3					0xEC7081A8	// R/W	32	DMA transfer size register_3
#define	ADMA_DMACHCR_3					0xEC70818C	// R/W	32	DMA channel control register_3
#define	ADMA_DMACHCR_3_TSR				0xEC7081AC	// R/W	32	DMA channel control register_3
#define	ADMA_DMATCRB_3					0xEC708198	// R/W	32	DMA transfer count register B_3
#define	ADMA_DMATSRB_3					0xEC7081B8	// R/W	32	DMA transfer size register B_3
#define	ADMA_DMACHCRB_3					0xEC70819C	// R/W	32	DMA channel control register B_3
#define	ADMA_DMARS_3					0xEC7081C0	// R/W	16	DMA extended resource selector_3
#define	ADMA_DMABUFCR_3					0xEC7081C8	// R/W	32	DMA buffer control register_3
#define	ADMA_DMADPBASE_3				0xEC7081D0	// R/W	32	DMA descriptor base address register_3
#define	ADMA_DMADPCR_3					0xEC7081D4	// R/W	32	DMA descriptor control register_3
#define	ADMA_DMAFIXSAR_3				0xEC708190	// R/W	32	DMA fixed source address register_3
#define	ADMA_DMAFIXDAR_3				0xEC708194	// R/W	32	DMA fixed destination address register_3
#define	ADMA_DMAFIXDPBASE_3				0xEC7081E0	// R/W	32	DMA fixed descriptor base address register_3
#define	ADMA_DMASAR_4					0xEC708200	// R/W	32	DMA source address register_4
#define	ADMA_DMASAR_4_TSR				0xEC708220	// R/W	32	DMA source address register_4
#define	ADMA_DMADAR_4					0xEC708204	// R/W	32	DMA destination address register_4
#define	ADMA_DMADAR_4_TSR				0xEC708224	// R/W	32	DMA destination address register_4
#define	ADMA_DMATCR_4					0xEC708208	// R/W	32	DMA transfer count register_4
#define	ADMA_DMATSR_4					0xEC708228	// R/W	32	DMA transfer size register_4
#define	ADMA_DMACHCR_4					0xEC70820C	// R/W	32	DMA channel control register_4
#define	ADMA_DMACHCR_4_TSR				0xEC70822C	// R/W	32	DMA channel control register_4
#define	ADMA_DMATCRB_4					0xEC708218	// R/W	32	DMA transfer count register B_4
#define	ADMA_DMATSRB_4					0xEC708238	// R/W	32	DMA transfer size register B_4
#define	ADMA_DMACHCRB_4					0xEC70821C	// R/W	32	DMA channel control register B_4
#define	ADMA_DMARS_4					0xEC708240	// R/W	16	DMA extended resource selector_4
#define	ADMA_DMABUFCR_4					0xEC708248	// R/W	32	DMA buffer control register_4
#define	ADMA_DMADPBASE_4				0xEC708250	// R/W	32	DMA descriptor base address register_4
#define	ADMA_DMADPCR_4					0xEC708254	// R/W	32	DMA descriptor control register_4
#define	ADMA_DMAFIXSAR_4				0xEC708210	// R/W	32	DMA fixed source address register_4
#define	ADMA_DMAFIXDAR_4				0xEC708214	// R/W	32	DMA fixed destination address register_4
#define	ADMA_DMAFIXDPBASE_4				0xEC708260	// R/W	32	DMA fixed descriptor base address register_4
#define	ADMA_DMASAR_5					0xEC708280	// R/W	32	DMA source address register_5
#define	ADMA_DMASAR_5_TSR				0xEC7082A0	// R/W	32	DMA source address register_5
#define	ADMA_DMADAR_5					0xEC708284	// R/W	32	DMA destination address register_5
#define	ADMA_DMADAR_5_TSR				0xEC7082A4	// R/W	32	DMA destination address register_5
#define	ADMA_DMATCR_5					0xEC708288	// R/W	32	DMA transfer count register_5
#define	ADMA_DMATSR_5					0xEC7082A8	// R/W	32	DMA transfer size register_5
#define	ADMA_DMACHCR_5					0xEC70828C	// R/W	32	DMA channel control register_5
#define	ADMA_DMACHCR_5_TSR				0xEC7082AC	// R/W	32	DMA channel control register_5
#define	ADMA_DMATCRB_5					0xEC708298	// R/W	32	DMA transfer count register B_5
#define	ADMA_DMATSRB_5					0xEC7082B8	// R/W	32	DMA transfer size register B_5
#define	ADMA_DMACHCRB_5					0xEC70829C	// R/W	32	DMA channel control register B_5
#define	ADMA_DMARS_5					0xEC7082C0	// R/W	16	DMA extended resource selector_5
#define	ADMA_DMABUFCR_5					0xEC7082C8	// R/W	32	DMA buffer control register_5
#define	ADMA_DMADPBASE_5				0xEC7082D0	// R/W	32	DMA descriptor base address register_5
#define	ADMA_DMADPCR_5					0xEC7082D4	// R/W	32	DMA descriptor control register_5
#define	ADMA_DMAFIXSAR_5				0xEC708290	// R/W	32	DMA fixed source address register_5
#define	ADMA_DMAFIXDAR_5				0xEC708294	// R/W	32	DMA fixed destination address register_5
#define	ADMA_DMAFIXDPBASE_5				0xEC7082E0	// R/W	32	DMA fixed descriptor base address register_5
#define	ADMA_DMASAR_6					0xEC708300	// R/W	32	DMA source address register_6
#define	ADMA_DMASAR_6_TSR				0xEC708320	// R/W	32	DMA source address register_6
#define	ADMA_DMADAR_6					0xEC708304	// R/W	32	DMA destination address register_6
#define	ADMA_DMADAR_6_TSR				0xEC708324	// R/W	32	DMA destination address register_6
#define	ADMA_DMATCR_6					0xEC708308	// R/W	32	DMA transfer count register_6
#define	ADMA_DMATSR_6					0xEC708328	// R/W	32	DMA transfer size register_6
#define	ADMA_DMACHCR_6					0xEC70830C	// R/W	32	DMA channel control register_6
#define	ADMA_DMACHCR_6_TSR				0xEC70832C	// R/W	32	DMA channel control register_6
#define	ADMA_DMATCRB_6					0xEC708318	// R/W	32	DMA transfer count register B_6
#define	ADMA_DMATSRB_6					0xEC708338	// R/W	32	DMA transfer size register B_6
#define	ADMA_DMACHCRB_6					0xEC70831C	// R/W	32	DMA channel control register B_6
#define	ADMA_DMARS_6					0xEC708340	// R/W	16	DMA extended resource selector_6
#define	ADMA_DMABUFCR_6					0xEC708348	// R/W	32	DMA buffer control register_6
#define	ADMA_DMADPBASE_6				0xEC708350	// R/W	32	DMA descriptor base address register_6
#define	ADMA_DMADPCR_6					0xEC708354	// R/W	32	DMA descriptor control register_6
#define	ADMA_DMAFIXSAR_6				0xEC708310	// R/W	32	DMA fixed source address register_6
#define	ADMA_DMAFIXDAR_6				0xEC708314	// R/W	32	DMA fixed destination address register_6
#define	ADMA_DMAFIXDPBASE_6				0xEC708360	// R/W	32	DMA fixed descriptor base address register_6
#define	ADMA_DMASAR_7					0xEC708380	// R/W	32	DMA source address register_7
#define	ADMA_DMASAR_7_TSR				0xEC7083A0	// R/W	32	DMA source address register_7
#define	ADMA_DMADAR_7					0xEC708384	// R/W	32	DMA destination address register_7
#define	ADMA_DMADAR_7_TSR				0xEC7083A4	// R/W	32	DMA destination address register_7
#define	ADMA_DMATCR_7					0xEC708388	// R/W	32	DMA transfer count register_7
#define	ADMA_DMATSR_7					0xEC7083A8	// R/W	32	DMA transfer size register_7
#define	ADMA_DMACHCR_7					0xEC70838C	// R/W	32	DMA channel control register_7
#define	ADMA_DMACHCR_7_TSR				0xEC7083AC	// R/W	32	DMA channel control register_7
#define	ADMA_DMATCRB_7					0xEC708398	// R/W	32	DMA transfer count register B_7
#define	ADMA_DMATSRB_7					0xEC7083B8	// R/W	32	DMA transfer size register B_7
#define	ADMA_DMACHCRB_7					0xEC70839C	// R/W	32	DMA channel control register B_7
#define	ADMA_DMARS_7					0xEC7083C0	// R/W	16	DMA extended resource selector_7
#define	ADMA_DMABUFCR_7					0xEC7083C8	// R/W	32	DMA buffer control register_7
#define	ADMA_DMADPBASE_7				0xEC7083D0	// R/W	32	DMA descriptor base address register_7
#define	ADMA_DMADPCR_7					0xEC7083D4	// R/W	32	DMA descriptor control register_7
#define	ADMA_DMAFIXSAR_7				0xEC708390	// R/W	32	DMA fixed source address register_7
#define	ADMA_DMAFIXDAR_7				0xEC708394	// R/W	32	DMA fixed destination address register_7
#define	ADMA_DMAFIXDPBASE_7				0xEC7083E0	// R/W	32	DMA fixed descriptor base address register_7
#define	ADMA_DMASAR_8					0xEC708400	// R/W	32	DMA source address register_8
#define	ADMA_DMASAR_8_TSR				0xEC708420	// R/W	32	DMA source address register_8
#define	ADMA_DMADAR_8					0xEC708404	// R/W	32	DMA destination address register_8
#define	ADMA_DMADAR_8_TSR				0xEC708424	// R/W	32	DMA destination address register_8
#define	ADMA_DMATCR_8					0xEC708408	// R/W	32	DMA transfer count register_8
#define	ADMA_DMATSR_8					0xEC708428	// R/W	32	DMA transfer size register_8
#define	ADMA_DMACHCR_8					0xEC70840C	// R/W	32	DMA channel control register_8
#define	ADMA_DMACHCR_8_TSR				0xEC70842C	// R/W	32	DMA channel control register_8
#define	ADMA_DMATCRB_8					0xEC708418	// R/W	32	DMA transfer count register B_8
#define	ADMA_DMATSRB_8					0xEC708438	// R/W	32	DMA transfer size register B_8
#define	ADMA_DMACHCRB_8					0xEC70841C	// R/W	32	DMA channel control register B_8
#define	ADMA_DMARS_8					0xEC708440	// R/W	16	DMA extended resource selector_8
#define	ADMA_DMABUFCR_8					0xEC708448	// R/W	32	DMA buffer control register_8
#define	ADMA_DMADPBASE_8				0xEC708450	// R/W	32	DMA descriptor base address register_8
#define	ADMA_DMADPCR_8					0xEC708454	// R/W	32	DMA descriptor control register_8
#define	ADMA_DMAFIXSAR_8				0xEC708410	// R/W	32	DMA fixed source address register_8
#define	ADMA_DMAFIXDAR_8				0xEC708414	// R/W	32	DMA fixed destination address register_8
#define	ADMA_DMAFIXDPBASE_8				0xEC708460	// R/W	32	DMA fixed descriptor base address register_8
#define	ADMA_DMASAR_9					0xEC708480	// R/W	32	DMA source address register_9
#define	ADMA_DMASAR_9_TSR				0xEC7084A0	// R/W	32	DMA source address register_9
#define	ADMA_DMADAR_9					0xEC708484	// R/W	32	DMA destination address register_9
#define	ADMA_DMADAR_9_TSR				0xEC7084A4	// R/W	32	DMA destination address register_9
#define	ADMA_DMATCR_9					0xEC708488	// R/W	32	DMA transfer count register_9
#define	ADMA_DMATSR_9					0xEC7084A8	// R/W	32	DMA transfer size register_9
#define	ADMA_DMACHCR_9					0xEC70848C	// R/W	32	DMA channel control register_9
#define	ADMA_DMACHCR_9_TSR				0xEC7084AC	// R/W	32	DMA channel control register_9
#define	ADMA_DMATCRB_9					0xEC708498	// R/W	32	DMA transfer count register B_9
#define	ADMA_DMATSRB_9					0xEC7084B8	// R/W	32	DMA transfer size register B_9
#define	ADMA_DMACHCRB_9					0xEC70849C	// R/W	32	DMA channel control register B_9
#define	ADMA_DMARS_9					0xEC7084C0	// R/W	16	DMA extended resource selector_9
#define	ADMA_DMABUFCR_9					0xEC7084C8	// R/W	32	DMA buffer control register_9
#define	ADMA_DMADPBASE_9				0xEC7084D0	// R/W	32	DMA descriptor base address register_9
#define	ADMA_DMADPCR_9					0xEC7084D4	// R/W	32	DMA descriptor control register_9
#define	ADMA_DMAFIXSAR_9				0xEC708490	// R/W	32	DMA fixed source address register_9
#define	ADMA_DMAFIXDAR_9				0xEC708494	// R/W	32	DMA fixed destination address register_9
#define	ADMA_DMAFIXDPBASE_9				0xEC7084E0	// R/W	32	DMA fixed descriptor base address register_9
#define	ADMA_DMASAR_10					0xEC708500	// R/W	32	DMA source address register_10
#define	ADMA_DMASAR_10_TSR				0xEC708520	// R/W	32	DMA source address register_10
#define	ADMA_DMADAR_10					0xEC708504	// R/W	32	DMA destination address register_10
#define	ADMA_DMADAR_10_TSR				0xEC708524	// R/W	32	DMA destination address register_10
#define	ADMA_DMATCR_10					0xEC708508	// R/W	32	DMA transfer count register_10
#define	ADMA_DMATSR_10					0xEC708528	// R/W	32	DMA transfer size register_10
#define	ADMA_DMACHCR_10					0xEC70850C	// R/W	32	DMA channel control register_10
#define	ADMA_DMACHCR_10_TSR				0xEC70852C	// R/W	32	DMA channel control register_10
#define	ADMA_DMATCRB_10					0xEC708518	// R/W	32	DMA transfer count register B_10
#define	ADMA_DMATSRB_10					0xEC708538	// R/W	32	DMA transfer size register B_10
#define	ADMA_DMACHCRB_10				0xEC70851C	// R/W	32	DMA channel control register B_10
#define	ADMA_DMARS_10					0xEC708540	// R/W	16	DMA extended resource selector_10
#define	ADMA_DMABUFCR_10				0xEC708548	// R/W	32	DMA buffer control register_10
#define	ADMA_DMADPBASE_10				0xEC708550	// R/W	32	DMA descriptor base address register_10
#define	ADMA_DMADPCR_10					0xEC708554	// R/W	32	DMA descriptor control register_10
#define	ADMA_DMAFIXSAR_10				0xEC708510	// R/W	32	DMA fixed source address register_10
#define	ADMA_DMAFIXDAR_10				0xEC708514	// R/W	32	DMA fixed destination address register_10
#define	ADMA_DMAFIXDPBASE_10			0xEC708560	// R/W	32	DMA fixed descriptor base address register_10
#define	ADMA_DMASAR_11					0xEC708580	// R/W	32	DMA source address register_11
#define	ADMA_DMASAR_11_TSR				0xEC7085A0	// R/W	32	DMA source address register_11
#define	ADMA_DMADAR_11					0xEC708584	// R/W	32	DMA destination address register_11
#define	ADMA_DMADAR_11_TSR				0xEC7085A4	// R/W	32	DMA destination address register_11
#define	ADMA_DMATCR_11					0xEC708588	// R/W	32	DMA transfer count register_11
#define	ADMA_DMATSR_11					0xEC7085A8	// R/W	32	DMA transfer size register_11
#define	ADMA_DMACHCR_11					0xEC70858C	// R/W	32	DMA channel control register_11
#define	ADMA_DMACHCR_11_TSR				0xEC7085AC	// R/W	32	DMA channel control register_11
#define	ADMA_DMATCRB_11					0xEC708598	// R/W	32	DMA transfer count register B_11
#define	ADMA_DMATSRB_11					0xEC7085B8	// R/W	32	DMA transfer size register B_11
#define	ADMA_DMACHCRB_11				0xEC70859C	// R/W	32	DMA channel control register B_11
#define	ADMA_DMARS_11					0xEC7085C0	// R/W	16	DMA extended resource selector_11
#define	ADMA_DMABUFCR_11				0xEC7085C8	// R/W	32	DMA buffer control register_11
#define	ADMA_DMADPBASE_11				0xEC7085D0	// R/W	32	DMA descriptor base address register_11
#define	ADMA_DMADPCR_11					0xEC7085D4	// R/W	32	DMA descriptor control register_11
#define	ADMA_DMAFIXSAR_11				0xEC708590	// R/W	32	DMA fixed source address register_11
#define	ADMA_DMAFIXDAR_11				0xEC708594	// R/W	32	DMA fixed destination address register_11
#define	ADMA_DMAFIXDPBASE_11			0xEC7085E0	// R/W	32	DMA fixed descriptor base address register_11
#define	ADMA_DMASAR_12					0xEC708600	// R/W	32	DMA source address register_12
#define	ADMA_DMASAR_12_TSR				0xEC708620	// R/W	32	DMA source address register_12
#define	ADMA_DMADAR_12					0xEC708604	// R/W	32	DMA destination address register_12
#define	ADMA_DMADAR_12_TSR				0xEC708624	// R/W	32	DMA destination address register_12
#define	ADMA_DMATCR_12					0xEC708608	// R/W	32	DMA transfer count register_12
#define	ADMA_DMATSR_12					0xEC708628	// R/W	32	DMA transfer size register_12
#define	ADMA_DMACHCR_12					0xEC70860C	// R/W	32	DMA channel control register_12
#define	ADMA_DMACHCR_12_TSR				0xEC70862C	// R/W	32	DMA channel control register_12
#define	ADMA_DMATCRB_12					0xEC708618	// R/W	32	DMA transfer count register B_12
#define	ADMA_DMATSRB_12					0xEC708638	// R/W	32	DMA transfer size register B_12
#define	ADMA_DMACHCRB_12				0xEC70861C	// R/W	32	DMA channel control register B_12
#define	ADMA_DMARS_12					0xEC708640	// R/W	16	DMA extended resource selector_12
#define	ADMA_DMABUFCR_12				0xEC708648	// R/W	32	DMA buffer control register_12
#define	ADMA_DMADPBASE_12				0xEC708650	// R/W	32	DMA descriptor base address register_12
#define	ADMA_DMADPCR_12					0xEC708654	// R/W	32	DMA descriptor control register_12
#define	ADMA_DMAFIXSAR_12				0xEC708610	// R/W	32	DMA fixed source address register_12
#define	ADMA_DMAFIXDAR_12				0xEC708614	// R/W	32	DMA fixed destination address register_12
#define	ADMA_DMAFIXDPBASE_12			0xEC708660	// R/W	32	DMA fixed descriptor base address register_12
#define	ADMA_DMASAR_13					0xEC708680	// R/W	32	DMA source address register_13
#define	ADMA_DMASAR_13_TSR				0xEC7086A0	// R/W	32	DMA source address register_13
#define	ADMA_DMADAR_13					0xEC708684	// R/W	32	DMA destination address register_13
#define	ADMA_DMADAR_13_TSR				0xEC7086A4	// R/W	32	DMA destination address register_13
#define	ADMA_DMATCR_13					0xEC708688	// R/W	32	DMA transfer count register_13
#define	ADMA_DMATSR_13					0xEC7086A8	// R/W	32	DMA transfer size register_13
#define	ADMA_DMACHCR_13					0xEC70868C	// R/W	32	DMA channel control register_13
#define	ADMA_DMACHCR_13_TSR				0xEC7086AC	// R/W	32	DMA channel control register_13
#define	ADMA_DMATCRB_13					0xEC708698	// R/W	32	DMA transfer count register B_13
#define	ADMA_DMATSRB_13					0xEC7086B8	// R/W	32	DMA transfer size register B_13
#define	ADMA_DMACHCRB_13				0xEC70869C	// R/W	32	DMA channel control register B_13
#define	ADMA_DMARS_13					0xEC7086C0	// R/W	16	DMA extended resource selector_13
#define	ADMA_DMABUFCR_13				0xEC7086C8	// R/W	32	DMA buffer control register_13
#define	ADMA_DMADPBASE_13				0xEC7086D0	// R/W	32	DMA descriptor base address register_13
#define	ADMA_DMADPCR_13					0xEC7086D4	// R/W	32	DMA descriptor control register_13
#define	ADMA_DMAFIXSAR_13				0xEC708690	// R/W	32	DMA fixed source address register_13
#define	ADMA_DMAFIXDAR_13				0xEC708694	// R/W	32	DMA fixed destination address register_13
#define	ADMA_DMAFIXDPBASE_13			0xEC7086E0	// R/W	32	DMA fixed descriptor base address register_13
#define	ADMA_DMASAR_14					0xEC708700	// R/W	32	DMA source address register_14
#define	ADMA_DMASAR_14_TSR				0xEC708720	// R/W	32	DMA source address register_14
#define	ADMA_DMADAR_14					0xEC708704	// R/W	32	DMA destination address register_14
#define	ADMA_DMADAR_14_TSR				0xEC708724	// R/W	32	DMA destination address register_14
#define	ADMA_DMATCR_14					0xEC708708	// R/W	32	DMA transfer count register_14
#define	ADMA_DMATSR_14					0xEC708728	// R/W	32	DMA transfer size register_14
#define	ADMA_DMACHCR_14					0xEC70870C	// R/W	32	DMA channel control register_14
#define	ADMA_DMACHCR_14_TSR				0xEC70872C	// R/W	32	DMA channel control register_14
#define	ADMA_DMATCRB_14					0xEC708718	// R/W	32	DMA transfer count register B_14
#define	ADMA_DMATSRB_14					0xEC708738	// R/W	32	DMA transfer size register B_14
#define	ADMA_DMACHCRB_14				0xEC70871C	// R/W	32	DMA channel control register B_14
#define	ADMA_DMARS_14					0xEC708740	// R/W	16	DMA extended resource selector_14
#define	ADMA_DMABUFCR_14				0xEC708748	// R/W	32	DMA buffer control register_14
#define	ADMA_DMADPBASE_14				0xEC708750	// R/W	32	DMA descriptor base address register_14
#define	ADMA_DMADPCR_14					0xEC708754	// R/W	32	DMA descriptor control register_14
#define	ADMA_DMAFIXSAR_14				0xEC708710	// R/W	32	DMA fixed source address register_14
#define	ADMA_DMAFIXDAR_14				0xEC708714	// R/W	32	DMA fixed destination address register_14
#define	ADMA_DMAFIXDPBASE_14			0xEC708760	// R/W	32	DMA fixed descriptor base address register_14
#define	ADMA_DMASAR_15					0xEC708780	// R/W	32	DMA source address register_15
#define	ADMA_DMASAR_15_TSR				0xEC7087A0	// R/W	32	DMA source address register_15
#define	ADMA_DMADAR_15					0xEC708784	// R/W	32	DMA destination address register_15
#define	ADMA_DMADAR_15_TSR				0xEC7087A4	// R/W	32	DMA destination address register_15
#define	ADMA_DMATCR_15					0xEC708788	// R/W	32	DMA transfer count register_15
#define	ADMA_DMATSR_15					0xEC7087A8	// R/W	32	DMA transfer size register_15
#define	ADMA_DMACHCR_15					0xEC70878C	// R/W	32	DMA channel control register_15
#define	ADMA_DMACHCR_15_TSR				0xEC7087AC	// R/W	32	DMA channel control register_15
#define	ADMA_DMATCRB_15					0xEC708798	// R/W	32	DMA transfer count register B_15
#define	ADMA_DMATSRB_15					0xEC7087B8	// R/W	32	DMA transfer size register B_15
#define	ADMA_DMACHCRB_15				0xEC70879C	// R/W	32	DMA channel control register B_15
#define	ADMA_DMARS_15					0xEC7087C0	// R/W	16	DMA extended resource selector_15
#define	ADMA_DMABUFCR_15				0xEC7087C8	// R/W	32	DMA buffer control register_15
#define	ADMA_DMADPBASE_15				0xEC7087D0	// R/W	32	DMA descriptor base address register_15
#define	ADMA_DMADPCR_15					0xEC7087D4	// R/W	32	DMA descriptor control register_15
#define	ADMA_DMAFIXSAR_15				0xEC708790	// R/W	32	DMA fixed source address register_15
#define	ADMA_DMAFIXDAR_15				0xEC708794	// R/W	32	DMA fixed destination address register_15
#define	ADMA_DMAFIXDPBASE_15			0xEC7087E0	// R/W	32	DMA fixed descriptor base address register_15
#define	ADMA_DescriptorMEM				0xEC70A000	// R/W	32	Descriptor memory (for lower-numbered channels)
#define	ADMA_DMAISTA_U					0xEC720020	// R	32	DMA interrupt status register (for higher-numbered channels)
#define	ADMA_DMASEC_U					0xEC720030	// R/W	32	DMA secure control register (for higher-numbered channels)
#define	ADMA_DMAOR_U					0xEC720060	// R/W	16	DMA operation register (for higher-numbered channels)
#define	ADMA_DMACHCLR_U					0xEC720080	// W	32	DMA channel clear register (for higher-numbered channels)
#define	ADMA_DMADPSEC_U					0xEC7200A0	// R/W	32	DPRAM secure control register (for higher-numbered channels)
#define	ADMA_DMASAR_16					0xEC728000	// R/W	32	DMA source address register_16
#define	ADMA_DMASAR_16_TSR				0xEC728020	// R/W	32	DMA source address register_16
#define	ADMA_DMADAR_16					0xEC728004	// R/W	32	DMA destination address register_16
#define	ADMA_DMADAR_16_TSR				0xEC728024	// R/W	32	DMA destination address register_16
#define	ADMA_DMATCR_16					0xEC728008	// R/W	32	DMA transfer count register_16
#define	ADMA_DMATSR_16					0xEC728028	// R/W	32	DMA transfer size register_16
#define	ADMA_DMACHCR_16					0xEC72800C	// R/W	32	DMA channel control register_16
#define	ADMA_DMACHCR_16_TSR				0xEC72802C	// R/W	32	DMA channel control register_16
#define	ADMA_DMATCRB_16					0xEC728018	// R/W	32	DMA transfer count register B_16
#define	ADMA_DMATSRB_16					0xEC728038	// R/W	32	DMA transfer size register B_16
#define	ADMA_DMACHCRB_16				0xEC72801C	// R/W	32	DMA channel control register B_16
#define	ADMA_DMARS_16					0xEC728040	// R/W	16	DMA extended resource selector_16
#define	ADMA_DMABUFCR_16				0xEC728048	// R/W	32	DMA buffer control register_16
#define	ADMA_DMADPBASE_16				0xEC728050	// R/W	32	DMA descriptor base address register_16
#define	ADMA_DMADPCR_16					0xEC728054	// R/W	32	DMA descriptor control register_16
#define	ADMA_DMAFIXSAR_16				0xEC728010	// R/W	32	DMA fixed source address register_16
#define	ADMA_DMAFIXDAR_16				0xEC728014	// R/W	32	DMA fixed destination address register_16
#define	ADMA_DMAFIXDPBASE_16			0xEC728060	// R/W	32	DMA fixed descriptor base address register_16
#define	ADMA_DMASAR_17					0xEC728080	// R/W	32	DMA source address register_17
#define	ADMA_DMASAR_17_TSR				0xEC7280A0	// R/W	32	DMA source address register_17
#define	ADMA_DMADAR_17					0xEC728084	// R/W	32	DMA destination address register_17
#define	ADMA_DMADAR_17_TSR				0xEC7280A4	// R/W	32	DMA destination address register_17
#define	ADMA_DMATCR_17					0xEC728088	// R/W	32	DMA transfer count register_17
#define	ADMA_DMATSR_17					0xEC7280A8	// R/W	32	DMA transfer size register_17
#define	ADMA_DMACHCR_17					0xEC72808C	// R/W	32	DMA channel control register_17
#define	ADMA_DMACHCR_17_TSR				0xEC7280AC	// R/W	32	DMA channel control register_17
#define	ADMA_DMATCRB_17					0xEC728098	// R/W	32	DMA transfer count register B_17
#define	ADMA_DMATSRB_17					0xEC7280B8	// R/W	32	DMA transfer size register B_17
#define	ADMA_DMACHCRB_17				0xEC72809C	// R/W	32	DMA channel control register B_17
#define	ADMA_DMARS_17					0xEC7280C0	// R/W	16	DMA extended resource selector_17
#define	ADMA_DMABUFCR_17				0xEC7280C8	// R/W	32	DMA buffer control register_17
#define	ADMA_DMADPBASE_17				0xEC7280D0	// R/W	32	DMA descriptor base address register_17
#define	ADMA_DMADPCR_17					0xEC7280D4	// R/W	32	DMA descriptor control register_17
#define	ADMA_DMAFIXSAR_17				0xEC7280E0	// R/W	32	DMA fixed source address register_17
#define	ADMA_DMAFIXDAR_17				0xEC728090	// R/W	32	DMA fixed destination address register_17
#define	ADMA_DMAFIXDPBASE_17			0xEC728094	// R/W	32	DMA fixed descriptor base address register_17
#define	ADMA_DMASAR_18					0xEC728100	// R/W	32	DMA source address register_18
#define	ADMA_DMASAR_18_TSR				0xEC728120	// R/W	32	DMA source address register_18
#define	ADMA_DMADAR_18					0xEC728104	// R/W	32	DMA destination address register_18
#define	ADMA_DMADAR_18_TSR				0xEC728124	// R/W	32	DMA destination address register_18
#define	ADMA_DMATCR_18					0xEC728108	// R/W	32	DMA transfer count register_18
#define	ADMA_DMATSR_18					0xEC728128	// R/W	32	DMA transfer size register_18
#define	ADMA_DMACHCR_18					0xEC72810C	// R/W	32	DMA channel control register_18
#define	ADMA_DMACHCR_18_TSR				0xEC72812C	// R/W	32	DMA channel control register_18
#define	ADMA_DMATCRB_18					0xEC728118	// R/W	32	DMA transfer count register B_18
#define	ADMA_DMATSRB_18					0xEC728138	// R/W	32	DMA transfer size register B_18
#define	ADMA_DMACHCRB_18				0xEC72811C	// R/W	32	DMA channel control register B_18
#define	ADMA_DMARS_18					0xEC728140	// R/W	16	DMA extended resource selector_18
#define	ADMA_DMABUFCR_18				0xEC728148	// R/W	32	DMA buffer control register_18
#define	ADMA_DMADPBASE_18				0xEC728150	// R/W	32	DMA descriptor base address register_18
#define	ADMA_DMADPCR_18					0xEC728154	// R/W	32	DMA descriptor control register_18
#define	ADMA_DMAFIXSAR_18				0xEC728110	// R/W	32	DMA fixed source address register_18
#define	ADMA_DMAFIXDAR_18				0xEC728114	// R/W	32	DMA fixed destination address register_18
#define	ADMA_DMAFIXDPBASE_18			0xEC728160	// R/W	32	DMA fixed descriptor base address register_18
#define	ADMA_DMASAR_19					0xEC728180	// R/W	32	DMA source address register_19
#define	ADMA_DMASAR_19_TSR				0xEC7281A0	// R/W	32	DMA source address register_19
#define	ADMA_DMADAR_19					0xEC728184	// R/W	32	DMA destination address register_19
#define	ADMA_DMADAR_19_TSR				0xEC7281A4	// R/W	32	DMA destination address register_19
#define	ADMA_DMATCR_19					0xEC728188	// R/W	32	DMA transfer count register_19
#define	ADMA_DMATSR_19					0xEC7281A8	// R/W	32	DMA transfer size register_19
#define	ADMA_DMACHCR_19					0xEC72818C	// R/W	32	DMA channel control register_19
#define	ADMA_DMACHCR_19_TSR				0xEC7281AC	// R/W	32	DMA channel control register_19
#define	ADMA_DMATCRB_19					0xEC728198	// R/W	32	DMA transfer count register B_19
#define	ADMA_DMATSRB_19					0xEC7281B8	// R/W	32	DMA transfer size register B_19
#define	ADMA_DMACHCRB_19				0xEC72819C	// R/W	32	DMA channel control register B_19
#define	ADMA_DMARS_19					0xEC7281C0	// R/W	16	DMA extended resource selector_19
#define	ADMA_DMABUFCR_19				0xEC7281C8	// R/W	32	DMA buffer control register_19
#define	ADMA_DMADPBASE_19				0xEC7281D0	// R/W	32	DMA descriptor base address register_19
#define	ADMA_DMADPCR_19					0xEC7281D4	// R/W	32	DMA descriptor control register_19
#define	ADMA_DMAFIXSAR_19				0xEC728190	// R/W	32	DMA fixed source address register_19
#define	ADMA_DMAFIXDAR_19				0xEC728194	// R/W	32	DMA fixed destination address register_19
#define	ADMA_DMAFIXDPBASE_19			0xEC7281E0	// R/W	32	DMA fixed descriptor base address register_19
#define	ADMA_DMASAR_20					0xEC728200	// R/W	32	DMA source address register_20
#define	ADMA_DMASAR_20_TSR				0xEC728220	// R/W	32	DMA source address register_20
#define	ADMA_DMADAR_20					0xEC728204	// R/W	32	DMA destination address register_20
#define	ADMA_DMADAR_20_TSR				0xEC728224	// R/W	32	DMA destination address register_20
#define	ADMA_DMATCR_20					0xEC728208	// R/W	32	DMA transfer count register_20
#define	ADMA_DMATSR_20					0xEC728228	// R/W	32	DMA transfer size register_20
#define	ADMA_DMACHCR_20					0xEC72820C	// R/W	32	DMA channel control register_20
#define	ADMA_DMACHCR_20_TSR				0xEC72822C	// R/W	32	DMA channel control register_20
#define	ADMA_DMATCRB_20					0xEC728218	// R/W	32	DMA transfer count register B_20
#define	ADMA_DMATSRB_20					0xEC728238	// R/W	32	DMA transfer size register B_20
#define	ADMA_DMACHCRB_20				0xEC72821C	// R/W	32	DMA channel control register B_20
#define	ADMA_DMARS_20					0xEC728240	// R/W	16	DMA extended resource selector_20
#define	ADMA_DMABUFCR_20				0xEC728248	// R/W	32	DMA buffer control register_20
#define	ADMA_DMADPBASE_20				0xEC728250	// R/W	32	DMA descriptor base address register_20
#define	ADMA_DMADPCR_20					0xEC728254	// R/W	32	DMA descriptor control register_20
#define	ADMA_DMAFIXSAR_20				0xEC728210	// R/W	32	DMA fixed source address register_20
#define	ADMA_DMAFIXDAR_20				0xEC728214	// R/W	32	DMA fixed destination address register_20
#define	ADMA_DMAFIXDPBASE_20			0xEC728260	// R/W	32	DMA fixed descriptor base address register_20
#define	ADMA_DMASAR_21					0xEC728280	// R/W	32	DMA source address register_21
#define	ADMA_DMASAR_21_TSR				0xEC7282A0	// R/W	32	DMA source address register_21
#define	ADMA_DMADAR_21					0xEC728284	// R/W	32	DMA destination address register_21
#define	ADMA_DMADAR_21_TSR				0xEC7282A4	// R/W	32	DMA destination address register_21
#define	ADMA_DMATCR_21					0xEC728288	// R/W	32	DMA transfer count register_21
#define	ADMA_DMATSR_21					0xEC7282A8	// R/W	32	DMA transfer size register_21
#define	ADMA_DMACHCR_21					0xEC72828C	// R/W	32	DMA channel control register_21
#define	ADMA_DMACHCR_21_TSR				0xEC7282AC	// R/W	32	DMA channel control register_21
#define	ADMA_DMATCRB_21					0xEC728298	// R/W	32	DMA transfer count register B_21
#define	ADMA_DMATSRB_21					0xEC7282B8	// R/W	32	DMA transfer size register B_21
#define	ADMA_DMACHCRB_21				0xEC72829C	// R/W	32	DMA channel control register B_21
#define	ADMA_DMARS_21					0xEC7282C0	// R/W	16	DMA extended resource selector_21
#define	ADMA_DMABUFCR_21				0xEC7282C8	// R/W	32	DMA buffer control register_21
#define	ADMA_DMADPBASE_21				0xEC7282D0	// R/W	32	DMA descriptor base address register_21
#define	ADMA_DMADPCR_21					0xEC7282D4	// R/W	32	DMA descriptor control register_21
#define	ADMA_DMAFIXSAR_21				0xEC728290	// R/W	32	DMA fixed source address register_21
#define	ADMA_DMAFIXDAR_21				0xEC728294	// R/W	32	DMA fixed destination address register_21
#define	ADMA_DMAFIXDPBASE_21			0xEC7282E0	// R/W	32	DMA fixed descriptor base address register_21
#define	ADMA_DMASAR_22					0xEC728300	// R/W	32	DMA source address register_22
#define	ADMA_DMASAR_22_TSR				0xEC728320	// R/W	32	DMA source address register_22
#define	ADMA_DMADAR_22					0xEC728304	// R/W	32	DMA destination address register_22
#define	ADMA_DMADAR_22_TSR				0xEC728324	// R/W	32	DMA destination address register_22
#define	ADMA_DMATCR_22					0xEC728308	// R/W	32	DMA transfer count register_22
#define	ADMA_DMATSR_22					0xEC728328	// R/W	32	DMA transfer size register_22
#define	ADMA_DMACHCR_22					0xEC72830C	// R/W	32	DMA channel control register_22
#define	ADMA_DMACHCR_22_TSR				0xEC72832C	// R/W	32	DMA channel control register_22
#define	ADMA_DMATCRB_22					0xEC728318	// R/W	32	DMA transfer count register B_22
#define	ADMA_DMATSRB_22					0xEC728338	// R/W	32	DMA transfer size register B_22
#define	ADMA_DMACHCRB_22				0xEC72831C	// R/W	32	DMA channel control register B_22
#define	ADMA_DMARS_22					0xEC728340	// R/W	16	DMA extended resource selector_22
#define	ADMA_DMABUFCR_22				0xEC728348	// R/W	32	DMA buffer control register_22
#define	ADMA_DMADPBASE_22				0xEC728350	// R/W	32	DMA descriptor base address register_22
#define	ADMA_DMADPCR_22					0xEC728354	// R/W	32	DMA descriptor control register_22
#define	ADMA_DMAFIXSAR_22				0xEC728310	// R/W	32	DMA fixed source address register_22
#define	ADMA_DMAFIXDAR_22				0xEC728314	// R/W	32	DMA fixed destination address register_22
#define	ADMA_DMAFIXDPBASE_22			0xEC728360	// R/W	32	DMA fixed descriptor base address register_22
#define	ADMA_DMASAR_23					0xEC728380	// R/W	32	DMA source address register_23
#define	ADMA_DMASAR_23_TSR				0xEC7283A0	// R/W	32	DMA source address register_23
#define	ADMA_DMADAR_23					0xEC728384	// R/W	32	DMA destination address register_23
#define	ADMA_DMADAR_23_TSR				0xEC7283A4	// R/W	32	DMA destination address register_23
#define	ADMA_DMATCR_23					0xEC728388	// R/W	32	DMA transfer count register_23
#define	ADMA_DMATSR_23					0xEC7283A8	// R/W	32	DMA transfer size register_23
#define	ADMA_DMACHCR_23					0xEC72838C	// R/W	32	DMA channel control register_23
#define	ADMA_DMACHCR_23_TSR				0xEC7283AC	// R/W	32	DMA channel control register_23
#define	ADMA_DMATCRB_23					0xEC728398	// R/W	32	DMA transfer count register B_23
#define	ADMA_DMATSRB_23					0xEC7283B8	// R/W	32	DMA transfer size register B_23
#define	ADMA_DMACHCRB_23				0xEC72839C	// R/W	32	DMA channel control register B_23
#define	ADMA_DMARS_23					0xEC7283C0	// R/W	16	DMA extended resource selector_23
#define	ADMA_DMABUFCR_23				0xEC7283C8	// R/W	32	DMA buffer control register_23
#define	ADMA_DMADPBASE_23				0xEC7283D0	// R/W	32	DMA descriptor base address register_23
#define	ADMA_DMADPCR_23					0xEC7283D4	// R/W	32	DMA descriptor control register_23
#define	ADMA_DMAFIXSAR_23				0xEC728390	// R/W	32	DMA fixed source address register_23
#define	ADMA_DMAFIXDAR_23				0xEC728394	// R/W	32	DMA fixed destination address register_23
#define	ADMA_DMAFIXDPBASE_23			0xEC7283E0	// R/W	32	DMA fixed descriptor base address register_23
#define	ADMA_DMASAR_24					0xEC728400	// R/W	32	DMA source address register_24
#define	ADMA_DMASAR_24_TSR				0xEC728420	// R/W	32	DMA source address register_24
#define	ADMA_DMADAR_24					0xEC728404	// R/W	32	DMA destination address register_24
#define	ADMA_DMADAR_24_TSR				0xEC728424	// R/W	32	DMA destination address register_24
#define	ADMA_DMATCR_24					0xEC728408	// R/W	32	DMA transfer count register_24
#define	ADMA_DMATSR_24					0xEC728428	// R/W	32	DMA transfer size register_24
#define	ADMA_DMACHCR_24					0xEC72840C	// R/W	32	DMA channel control register_24
#define	ADMA_DMACHCR_24_TSR				0xEC72842C	// R/W	32	DMA channel control register_24
#define	ADMA_DMATCRB_24					0xEC728418	// R/W	32	DMA transfer count register B_24
#define	ADMA_DMATSRB_24					0xEC728438	// R/W	32	DMA transfer size register B_24
#define	ADMA_DMACHCRB_24				0xEC72841C	// R/W	32	DMA channel control register B_24
#define	ADMA_DMARS_24					0xEC728440	// R/W	16	DMA extended resource selector_24
#define	ADMA_DMABUFCR_24				0xEC728448	// R/W	32	DMA buffer control register_24
#define	ADMA_DMADPBASE_24				0xEC728450	// R/W	32	DMA descriptor base address register_24
#define	ADMA_DMADPCR_24					0xEC728454	// R/W	32	DMA descriptor control register_24
#define	ADMA_DMAFIXSAR_24				0xEC728410	// R/W	32	DMA fixed source address register_24
#define	ADMA_DMAFIXDAR_24				0xEC728414	// R/W	32	DMA fixed destination address register_24
#define	ADMA_DMAFIXDPBASE_24			0xEC728460	// R/W	32	DMA fixed descriptor base address register_24
#define	ADMA_DMASAR_25					0xEC728480	// R/W	32	DMA source address register_25
#define	ADMA_DMASAR_25_TSR				0xEC7284A0	// R/W	32	DMA source address register_25
#define	ADMA_DMADAR_25					0xEC728484	// R/W	32	DMA destination address register_25
#define	ADMA_DMADAR_25_TSR				0xEC7284A4	// R/W	32	DMA destination address register_25
#define	ADMA_DMATCR_25					0xEC728488	// R/W	32	DMA transfer count register_25
#define	ADMA_DMATSR_25					0xEC7284A8	// R/W	32	DMA transfer size register_25
#define	ADMA_DMACHCR_25					0xEC72848C	// R/W	32	DMA channel control register_25
#define	ADMA_DMACHCR_25_TSR				0xEC7284AC	// R/W	32	DMA channel control register_25
#define	ADMA_DMATCRB_25					0xEC728498	// R/W	32	DMA transfer count register B_25
#define	ADMA_DMATSRB_25					0xEC7284B8	// R/W	32	DMA transfer size register B_25
#define	ADMA_DMACHCRB_25				0xEC72849C	// R/W	32	DMA channel control register B_25
#define	ADMA_DMARS_25					0xEC7284C0	// R/W	16	DMA extended resource selector_25
#define	ADMA_DMABUFCR_25				0xEC7284C8	// R/W	32	DMA buffer control register_25
#define	ADMA_DMADPBASE_25				0xEC7284D0	// R/W	32	DMA descriptor base address register_25
#define	ADMA_DMADPCR_25					0xEC7284D4	// R/W	32	DMA descriptor control register_25
#define	ADMA_DMAFIXSAR_25				0xEC728490	// R/W	32	DMA fixed source address register_25
#define	ADMA_DMAFIXDAR_25				0xEC728494	// R/W	32	DMA fixed destination address register_25
#define	ADMA_DMAFIXDPBASE_25			0xEC7284E0	// R/W	32	DMA fixed descriptor base address register_25
#define	ADMA_DMASAR_26					0xEC728500	// R/W	32	DMA source address register_26
#define	ADMA_DMASAR_26_TSR				0xEC728520	// R/W	32	DMA source address register_26
#define	ADMA_DMADAR_26					0xEC728504	// R/W	32	DMA destination address register_26
#define	ADMA_DMADAR_26_TSR				0xEC728524	// R/W	32	DMA destination address register_26
#define	ADMA_DMATCR_26					0xEC728508	// R/W	32	DMA transfer count register_26
#define	ADMA_DMATSR_26					0xEC728528	// R/W	32	DMA transfer size register_26
#define	ADMA_DMACHCR_26					0xEC72850C	// R/W	32	DMA channel control register_26
#define	ADMA_DMACHCR_26_TSR				0xEC72852C	// R/W	32	DMA channel control register_26
#define	ADMA_DMATCRB_26					0xEC728518	// R/W	32	DMA transfer count register B_26
#define	ADMA_DMATSRB_26					0xEC728538	// R/W	32	DMA transfer size register B_26
#define	ADMA_DMACHCRB_26				0xEC72851C	// R/W	32	DMA channel control register B_26
#define	ADMA_DMARS_26					0xEC728540	// R/W	16	DMA extended resource selector_26
#define	ADMA_DMABUFCR_26				0xEC728548	// R/W	32	DMA buffer control register_26
#define	ADMA_DMADPBASE_26				0xEC728550	// R/W	32	DMA descriptor base address register_26
#define	ADMA_DMADPCR_26					0xEC728554	// R/W	32	DMA descriptor control register_26
#define	ADMA_DMAFIXSAR_26				0xEC728510	// R/W	32	DMA fixed source address register_26
#define	ADMA_DMAFIXDAR_26				0xEC728514	// R/W	32	DMA fixed destination address register_26
#define	ADMA_DMAFIXDPBASE_26			0xEC728560	// R/W	32	DMA fixed descriptor base address register_26
#define	ADMA_DMASAR_27					0xEC728580	// R/W	32	DMA source address register_27
#define	ADMA_DMASAR_27_TSR				0xEC7285A0	// R/W	32	DMA source address register_27
#define	ADMA_DMADAR_27					0xEC728584	// R/W	32	DMA destination address register_27
#define	ADMA_DMADAR_27_TSR				0xEC7285A4	// R/W	32	DMA destination address register_27
#define	ADMA_DMATCR_27					0xEC728588	// R/W	32	DMA transfer count register_27
#define	ADMA_DMATSR_27					0xEC7285A8	// R/W	32	DMA transfer size register_27
#define	ADMA_DMACHCR_27					0xEC72858C	// R/W	32	DMA channel control register_27
#define	ADMA_DMACHCR_27_TSR				0xEC7285AC	// R/W	32	DMA channel control register_27
#define	ADMA_DMATCRB_27					0xEC728598	// R/W	32	DMA transfer count register B_27
#define	ADMA_DMATSRB_27					0xEC7285B8	// R/W	32	DMA transfer size register B_27
#define	ADMA_DMACHCRB_27				0xEC72859C	// R/W	32	DMA channel control register B_27
#define	ADMA_DMARS_27					0xEC7285C0	// R/W	16	DMA extended resource selector_27
#define	ADMA_DMABUFCR_27				0xEC7285C8	// R/W	32	DMA buffer control register_27
#define	ADMA_DMADPBASE_27				0xEC7285D0	// R/W	32	DMA descriptor base address register_27
#define	ADMA_DMADPCR_27					0xEC7285D4	// R/W	32	DMA descriptor control register_27
#define	ADMA_DMAFIXSAR_27				0xEC728590	// R/W	32	DMA fixed source address register_27
#define	ADMA_DMAFIXDAR_27				0xEC728594	// R/W	32	DMA fixed destination address register_27
#define	ADMA_DMAFIXDPBASE_27			0xEC7285E0	// R/W	32	DMA fixed descriptor base address register_27
#define	ADMA_DMASAR_28					0xEC728600	// R/W	32	DMA source address register_28
#define	ADMA_DMASAR_28_TSR				0xEC728620	// R/W	32	DMA source address register_28
#define	ADMA_DMADAR_28					0xEC728604	// R/W	32	DMA destination address register_28
#define	ADMA_DMADAR_28_TSR				0xEC728624	// R/W	32	DMA destination address register_28
#define	ADMA_DMATCR_28					0xEC728608	// R/W	32	DMA transfer count register_28
#define	ADMA_DMATSR_28					0xEC728628	// R/W	32	DMA transfer size register_28
#define	ADMA_DMACHCR_28					0xEC72860C	// R/W	32	DMA channel control register_28
#define	ADMA_DMACHCR_28_TSR				0xEC72862C	// R/W	32	DMA channel control register_28
#define	ADMA_DMATCRB_28					0xEC728618	// R/W	32	DMA transfer count register B_28
#define	ADMA_DMATSRB_28					0xEC728638	// R/W	32	DMA transfer size register B_28
#define	ADMA_DMACHCRB_28				0xEC72861C	// R/W	32	DMA channel control register B_28
#define	ADMA_DMARS_28					0xEC728640	// R/W	16	DMA extended resource selector_28
#define	ADMA_DMABUFCR_28				0xEC728648	// R/W	32	DMA buffer control register_28
#define	ADMA_DMADPBASE_28				0xEC728650	// R/W	32	DMA descriptor base address register_28
#define	ADMA_DMADPCR_28					0xEC728654	// R/W	32	DMA descriptor control register_28
#define	ADMA_DMAFIXSAR_28				0xEC728610	// R/W	32	DMA fixed source address register_28
#define	ADMA_DMAFIXDAR_28				0xEC728614	// R/W	32	DMA fixed destination address register_28
#define	ADMA_DMAFIXDPBASE_28			0xEC728660	// R/W	32	DMA fixed descriptor base address register_28
#define	ADMA_DMASAR_29					0xEC728680	// R/W	32	DMA source address register_29
#define	ADMA_DMASAR_29_TSR				0xEC7286A0	// R/W	32	DMA source address register_29
#define	ADMA_DMADAR_29					0xEC728684	// R/W	32	DMA destination address register_29
#define	ADMA_DMADAR_29_TSR				0xEC7286A4	// R/W	32	DMA destination address register_29
#define	ADMA_DMATCR_29					0xEC728688	// R/W	32	DMA transfer count register_29
#define	ADMA_DMATSR_29					0xEC7286A8	// R/W	32	DMA transfer size register_29
#define	ADMA_DMACHCR_29					0xEC72868C	// R/W	32	DMA channel control register_29
#define	ADMA_DMACHCR_29_TSR				0xEC7286AC	// R/W	32	DMA channel control register_29
#define	ADMA_DMATCRB_29					0xEC728698	// R/W	32	DMA transfer count register B_29
#define	ADMA_DMATSRB_29					0xEC7286B8	// R/W	32	DMA transfer size register B_29
#define	ADMA_DMACHCRB_29				0xEC72869C	// R/W	32	DMA channel control register B_29
#define	ADMA_DMARS_29					0xEC7286C0	// R/W	16	DMA extended resource selector_29
#define	ADMA_DMABUFCR_29				0xEC7286C8	// R/W	32	DMA buffer control register_29
#define	ADMA_DMADPBASE_29				0xEC7286D0	// R/W	32	DMA descriptor base address register_29
#define	ADMA_DMADPCR_29					0xEC7286D4	// R/W	32	DMA descriptor control register_29
#define	ADMA_DMAFIXSAR_29				0xEC728690	// R/W	32	DMA fixed source address register_29
#define	ADMA_DMAFIXDAR_29				0xEC728694	// R/W	32	DMA fixed destination address register_29
#define	ADMA_DMAFIXDPBASE_29			0xEC7286E0	// R/W	32	DMA fixed descriptor base address register_29
#define	ADMA_DMASAR_30					0xEC728700	// R/W	32	DMA source address register_30
#define	ADMA_DMASAR_30_TSR				0xEC728720	// R/W	32	DMA source address register_30
#define	ADMA_DMADAR_30					0xEC728704	// R/W	32	DMA destination address register_30
#define	ADMA_DMADAR_30_TSR				0xEC728724	// R/W	32	DMA destination address register_30
#define	ADMA_DMATCR_30					0xEC728708	// R/W	32	DMA transfer count register_30
#define	ADMA_DMATSR_30					0xEC728728	// R/W	32	DMA transfer size register_30
#define	ADMA_DMACHCR_30					0xEC72870C	// R/W	32	DMA channel control register_30
#define	ADMA_DMACHCR_30_TSR				0xEC72872C	// R/W	32	DMA channel control register_30
#define	ADMA_DMATCRB_30					0xEC728718	// R/W	32	DMA transfer count register B_30
#define	ADMA_DMATSRB_30					0xEC728738	// R/W	32	DMA transfer size register B_30
#define	ADMA_DMACHCRB_30				0xEC72871C	// R/W	32	DMA channel control register B_30
#define	ADMA_DMARS_30					0xEC728740	// R/W	16	DMA extended resource selector_30
#define	ADMA_DMABUFCR_30				0xEC728748	// R/W	32	DMA buffer control register_30
#define	ADMA_DMADPBASE_30				0xEC728750	// R/W	32	DMA descriptor base address register_30
#define	ADMA_DMADPCR_30					0xEC728754	// R/W	32	DMA descriptor control register_30
#define	ADMA_DMAFIXSAR_30				0xEC728710	// R/W	32	DMA fixed source address register_30
#define	ADMA_DMAFIXDAR_30				0xEC728714	// R/W	32	DMA fixed destination address register_30
#define	ADMA_DMAFIXDPBASE_30			0xEC728760	// R/W	32	DMA fixed descriptor base address register_30
#define	ADMA_DMASAR_31					0xEC728780	// R/W	32	DMA source address register_31
#define	ADMA_DMASAR_31_TSR				0xEC7287A0	// R/W	32	DMA source address register_31
#define	ADMA_DMADAR_31					0xEC728784	// R/W	32	DMA destination address register_31
#define	ADMA_DMADAR_31_TSR				0xEC7287A4	// R/W	32	DMA destination address register_31
#define	ADMA_DMATCR_31					0xEC728788	// R/W	32	DMA transfer count register_31
#define	ADMA_DMATSR_31					0xEC7287A8	// R/W	32	DMA transfer size register_31
#define	ADMA_DMACHCR_31					0xEC72878C	// R/W	32	DMA channel control register_31
#define	ADMA_DMACHCR_31_TSR				0xEC7287AC	// R/W	32	DMA channel control register_31
#define	ADMA_DMATCRB_31					0xEC728798	// R/W	32	DMA transfer count register B_31
#define	ADMA_DMATSRB_31					0xEC7287B8	// R/W	32	DMA transfer size register B_31
#define	ADMA_DMACHCRB_31				0xEC72879C	// R/W	32	DMA channel control register B_31
#define	ADMA_DMARS_31					0xEC7287C0	// R/W	16	DMA extended resource selector_31
#define	ADMA_DMABUFCR_31				0xEC7287C8	// R/W	32	DMA buffer control register_31
#define	ADMA_DMADPBASE_31				0xEC7287D0	// R/W	32	DMA descriptor base address register_31
#define	ADMA_DMADPCR_31					0xEC7287D4	// R/W	32	DMA descriptor control register_31
#define	ADMA_DMAFIXSAR_31				0xEC728790	// R/W	32	DMA fixed source address register_31
#define	ADMA_DMAFIXDAR_31				0xEC728794	// R/W	32	DMA fixed destination address register_31
#define	ADMA_DMAFIXDPBASE_31			0xEC7287E0	// R/W	32	DMA fixed descriptor base address register_31


//AUDIO
#define	SSI0_0_BUSIF					0xEC100000			
#define	SSI0_1_BUSIF					0xEC100400			
#define	SSI0_2_BUSIF					0xEC100800			
#define	SSI0_3_BUSIF					0xEC100C00			
#define	SSI1_0_BUSIF					0xEC101000			
#define	SSI1_1_BUSIF					0xEC101400			
#define	SSI1_2_BUSIF					0xEC101800			
#define	SSI1_3_BUSIF					0xEC101C00			
#define	SSI2_0_BUSIF					0xEC102000			
#define	SSI2_1_BUSIF					0xEC102400			
#define	SSI2_2_BUSIF					0xEC102800			
#define	SSI2_3_BUSIF					0xEC102C00			
#define	SSI3_0_BUSIF					0xEC103000			
#define	SSI3_1_BUSIF					0xEC103400			
#define	SSI3_2_BUSIF					0xEC103800			
#define	SSI3_3_BUSIF					0xEC103C00			
#define	SSI4_0_BUSIF					0xEC104000			
#define	SSI4_1_BUSIF					0xEC104400			
#define	SSI4_2_BUSIF					0xEC104800			
#define	SSI4_3_BUSIF					0xEC104C00			
#define	SSI5_BUSIF						0xEC105000			
#define	SSI6_BUSIF						0xEC106000			
#define	SSI7_BUSIF						0xEC107000			
#define	SSI8_BUSIF						0xEC108000			
#define	SSI9_0_BUSIF					0xEC109000			
#define	SSI9_1_BUSIF					0xEC109400			
#define	SSI9_2_BUSIF					0xEC109800			
#define	SSI9_3_BUSIF					0xEC109C00			
#define	SSI0_4_BUSIF					0xEC10A000			
#define	SSI0_5_BUSIF					0xEC10A400			
#define	SSI0_6_BUSIF					0xEC10A800			
#define	SSI0_7_BUSIF					0xEC10AC00			
#define	SSI1_4_BUSIF					0xEC10B000			
#define	SSI1_5_BUSIF					0xEC10B400			
#define	SSI1_6_BUSIF					0xEC10B800			
#define	SSI1_7_BUSIF					0xEC10BC00			
#define	SSI2_4_BUSIF					0xEC10C000			
#define	SSI2_5_BUSIF					0xEC10C400			
#define	SSI2_6_BUSIF					0xEC10C800			
#define	SSI2_7_BUSIF					0xEC10CC00			
#define	SSI3_4_BUSIF					0xEC10D000			
#define	SSI3_5_BUSIF					0xEC10D400			
#define	SSI3_6_BUSIF					0xEC10D800			
#define	SSI3_7_BUSIF					0xEC10DC00			
#define	SSI4_4_BUSIF					0xEC10E000			
#define	SSI4_5_BUSIF					0xEC10E400			
#define	SSI4_6_BUSIF					0xEC10E800			
#define	SSI4_7_BUSIF					0xEC10EC00			
#define	SSI9_4_BUSIF					0xEC10F000			
#define	SSI9_5_BUSIF					0xEC10F400			
#define	SSI9_6_BUSIF					0xEC10F800			
#define	SSI9_7_BUSIF					0xEC10FC00			
#define	DTCP0_PT_BUSIF					0xEC120000			
#define	DTCP1_PT_BUSIF					0xEC120400			
#define	DTCP0_CT_BUSIF					0xEC124000			
#define	DTCP1_CT_BUSIF					0xEC124400			
#define	SSITDR0							0xEC241008			
#define	SSIRDR0							0xEC24100C			
#define	SSITDR1							0xEC241048			
#define	SSIRDR1							0xEC24104C			
#define	SSITDR2							0xEC241088			
#define	SSIRDR2							0xEC24108C			
#define	SSITDR3							0xEC2410C8			
#define	SSIRDR3							0xEC2410CC			
#define	SSITDR4							0xEC241108			
#define	SSIRDR4							0xEC24110C			
#define	SSITDR5							0xEC241148			
#define	SSIRDR5							0xEC24114C			
#define	SSITDR6							0xEC241188			
#define	SSIRDR6							0xEC24118C			
#define	SSITDR7							0xEC2411C8			
#define	SSIRDR7							0xEC2411CC			
#define	SSITDR8							0xEC241208			
#define	SSIRDR8							0xEC24120C			
#define	SSITDR9							0xEC241248			
#define	SSIRDR9							0xEC24124C			
#define	MLM_BUSIF0						0xEC020000			
#define	MLM_BUSIF1						0xEC020400			
#define	MLM_BUSIF2						0xEC020800			
#define	MLM_BUSIF3						0xEC020C00			
#define	MLM_BUSIF4						0xEC021000			
#define	MLM_BUSIF5						0xEC021400			
#define	MLM_BUSIF6						0xEC021800			
#define	MLM_BUSIF7						0xEC021C00			
#define	SRC0in_BUSIF					0xEC000000			
#define	SRC1in_BUSIF					0xEC000400			
#define	SRC2in_BUSIF					0xEC000800			
#define	SRC3in_BUSIF					0xEC000C00			
#define	SRC4in_BUSIF					0xEC001000			
#define	SRC5in_BUSIF					0xEC001400			
#define	SRC6in_BUSIF					0xEC001800			
#define	SRC7in_BUSIF					0xEC001C00			
#define	SRC8in_BUSIF					0xEC002000			
#define	SRC9in_BUSIF					0xEC002400			
#define	SRC0out_BUSIF					0xEC004000			
#define	SRC1out_BUSIF					0xEC004400			
#define	SRC2out_BUSIF					0xEC004800			
#define	SRC3out_BUSIF					0xEC004C00			
#define	SRC4out_BUSIF					0xEC005000			
#define	SRC5out_BUSIF					0xEC005400			
#define	SRC6out_BUSIF					0xEC005800			
#define	SRC7out_BUSIF					0xEC005C00			
#define	SRC8out_BUSIF					0xEC006000			
#define	SRC9out_BUSIF					0xEC006400			
#define	CMD0out_BUSIF					0xEC008000			
#define	CMD1out_BUSIF					0xEC008400			



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



//CSI2LNK0
#define	CSI2LNK0_TREF					0xFEA80000	// R/W	32
#define	CSI2LNK0_SRST					0xFEA80004	// R/W	32
#define	CSI2LNK0_PHYCNT					0xFEA80008	// R/W	32
#define	CSI2LNK0_CHKSUM					0xFEA8000C	// R/W	32
#define	CSI2LNK0_VCDT					0xFEA80010	// R/W	32
#define	CSI2LNK0_VCDT2					0xFEA80014	// R/W	32
#define	CSI2LNK0_FRDT					0xFEA80018	// R/W	32
#define	CSI2LNK0_FLD					0xFEA8001C	// R/W	32
#define	CSI2LNK0_ASTBY					0xFEA80020	// R/W	32
#define	CSI2LNK0_LNGDT0					0xFEA80028	// R/W	32
#define	CSI2LNK0_LNGDT1					0xFEA8002C	// R/W	32
#define	CSI2LNK0_INTEN					0xFEA80030	// R/W	32
#define	CSI2LNK0_INTCLOSE				0xFEA80034	// R/W	32
#define	CSI2LNK0_INTSTATE				0xFEA80038	// R/(W)1
#define	CSI2LNK0_INTERRSTATE			0xFEA8003C	// R/(W)2
#define	CSI2LNK0_SHPDAT					0xFEA80040	// R	32
#define	CSI2LNK0_SHPCNT					0xFEA80044	// R	32
#define	CSI2LNK0_LINKCNT				0xFEA80048	// R/W	32
#define	CSI2LNK0_LSWAP					0xFEA8004C	// R/W	32
#define	CSI2LNK0_PHTC					0xFEA80058	// R/W	32
#define	CSI2LNK0_PHYPLL					0xFEA80068	// R/W	32
#define	CSI2LNK0_PHEERM					0xFEA80074	// R	32
#define	CSI2LNK0_PHCLM					0xFEA80078	// R	32
#define	CSI2LNK0_PHDLM					0xFEA8007C	// R	32
#define	CSI2LNK0_PH0M0					0xFEA800F0	// R	32
#define	CSI2LNK0_PH0M1					0xFEA800F4	// R	32
#define	CSI2LNK0_PH1M0					0xFEA800F8	// R	32
#define	CSI2LNK0_PH1M1					0xFEA800FC	// R	32
#define	CSI2LNK0_PH2M0					0xFEA80100	// R	32
#define	CSI2LNK0_PH2M1					0xFEA80104	// R	32
#define	CSI2LNK0_PH3M0					0xFEA80108	// R	32
#define	CSI2LNK0_PH3M1					0xFEA8010C	// R	32
#define	CSI2LNK0_PHRM0					0xFEA80110	// R	32
#define	CSI2LNK0_PHRM1					0xFEA80114	// R	32
#define	CSI2LNK0_PHRM2					0xFEA80118	// R	32
#define	CSI2LNK0_PHCM0					0xFEA80120	// R	32
#define	CSI2LNK0_PHCM1					0xFEA80124	// R	32
#define	CSI2LNK0_CRCM0					0xFEA80128	// R	32
#define	CSI2LNK0_CRCM1					0xFEA8012C	// R	32
#define	CSI2LNK0_SERRCNT				0xFEA80140	// R	32
#define	CSI2LNK0_SSERRCNT				0xFEA80144	// R	32
#define	CSI2LNK0_ECCCM					0xFEA80148	// R	32
#define	CSI2LNK0_ECECM					0xFEA8014C	// R	32
#define	CSI2LNK0_CRCECM					0xFEA80150	// R	32
#define	CSI2LNK0_LCNT					0xFEA80160	// R	32
#define	CSI2LNK0_LCNT2					0xFEA80164	// R	32
#define	CSI2LNK0_LCNTM					0xFEA80168	// R	32
#define	CSI2LNK0_LCNTM2					0xFEA8016C	// R	32
#define	CSI2LNK0_FCNTM					0xFEA80170	// R	32
#define	CSI2LNK0_PHYDIM					0xFEA80180	// R	32
#define	CSI2LNK0_PHYIM					0xFEA80184	// R	32
#define	CSI2LNK0_RCUDM					0xFEA8018C	// R	32
#define	CSI2LNK0_RCUSM1					0xFEA80190	// R	32
#define	CSI2LNK0_RCUSM2					0xFEA80194	// R	32
#define	CSI2LNK0_RCUSM3					0xFEA80198	// R	32
#define	CSI2LNK0_PHYOM					0xFEA8019C	// R	32
#define	CSI2LNK0_PHM1					0xFEA801C0	// R	32
#define	CSI2LNK0_PHM2					0xFEA801C4	// R	32
#define	CSI2LNK0_PHM3					0xFEA801C8	// R	32
#define	CSI2LNK0_PHM4					0xFEA801CC	// R	32
#define	CSI2LNK0_PHM5					0xFEA801D0	// R	32
#define	CSI2LNK0_PHM6					0xFEA801D4	// R	32
#define	CSI2LNK0_PHM7					0xFEA801D8	// R	32
#define	CSI2LNK0_PHM8					0xFEA801DC	// R	32
#define	CSI2LNK0_PPM1					0xFEA801E0	// R	32
#define	CSI2LNK0_PPM2					0xFEA801E4	// R	32
#define	CSI2LNK0_PPM3					0xFEA801E8	// R	32
#define	CSI2LNK0_PPM4					0xFEA801EC	// R	32
#define	CSI2LNK0_PPM5					0xFEA801F0	// R	32
#define	CSI2LNK0_PPM6					0xFEA801F4	// R	32
#define	CSI2LNK0_PPM7					0xFEA801F8	// R	32
#define	CSI2LNK0_PPM8					0xFEA801FC	// R	32


//CSI4LNK0
#define	CSI4LNK0_TREF					0xFEAA0000	// R/W	32
#define	CSI4LNK0_SRST					0xFEAA0004	// R/W	32
#define	CSI4LNK0_PHYCNT					0xFEAA0008	// R/W	32
#define	CSI4LNK0_CHKSUM					0xFEAA000C	// R/W	32
#define	CSI4LNK0_VCDT					0xFEAA0010	// R/W	32
#define	CSI4LNK0_VCDT2					0xFEAA0014	// R/W	32
#define	CSI4LNK0_FRDT					0xFEAA0018	// R/W	32
#define	CSI4LNK0_FLD					0xFEAA001C	// R/W	32
#define	CSI4LNK0_ASTBY					0xFEAA0020	// R/W	32
#define	CSI4LNK0_LNGDT0					0xFEAA0028	// R/W	32
#define	CSI4LNK0_LNGDT1					0xFEAA002C	// R/W	32
#define	CSI4LNK0_INTEN					0xFEAA0030	// R/W	32
#define	CSI4LNK0_INTCLOSE				0xFEAA0034	// R/W	32
#define	CSI4LNK0_INTSTATE				0xFEAA0038	// R/(W)1
#define	CSI4LNK0_INTERRSTATE			0xFEAA003C	// R/(W)2
#define	CSI4LNK0_SHPDAT					0xFEAA0040	// R	32
#define	CSI4LNK0_SHPCNT					0xFEAA0044	// R	32
#define	CSI4LNK0_LINKCNT				0xFEAA0048	// R/W	32
#define	CSI4LNK0_LSWAP					0xFEAA004C	// R/W	32
#define	CSI4LNK0_PHTC					0xFEAA0058	// R/W	32
#define	CSI4LNK0_PHYPLL					0xFEAA0068	// R/W	32
#define	CSI4LNK0_PHEERM					0xFEAA0074	// R	32
#define	CSI4LNK0_PHCLM					0xFEAA0078	// R	32
#define	CSI4LNK0_PHDLM					0xFEAA007C	// R	32
#define	CSI4LNK0_PH0M0					0xFEAA00F0	// R	32
#define	CSI4LNK0_PH0M1					0xFEAA00F4	// R	32
#define	CSI4LNK0_PH1M0					0xFEAA00F8	// R	32
#define	CSI4LNK0_PH1M1					0xFEAA00FC	// R	32
#define	CSI4LNK0_PH2M0					0xFEAA0100	// R	32
#define	CSI4LNK0_PH2M1					0xFEAA0104	// R	32
#define	CSI4LNK0_PH3M0					0xFEAA0108	// R	32
#define	CSI4LNK0_PH3M1					0xFEAA010C	// R	32
#define	CSI4LNK0_PHRM0					0xFEAA0110	// R	32
#define	CSI4LNK0_PHRM1					0xFEAA0114	// R	32
#define	CSI4LNK0_PHRM2					0xFEAA0118	// R	32
#define	CSI4LNK0_PHCM0					0xFEAA0120	// R	32
#define	CSI4LNK0_PHCM1					0xFEAA0124	// R	32
#define	CSI4LNK0_CRCM0					0xFEAA0128	// R	32
#define	CSI4LNK0_CRCM1					0xFEAA012C	// R	32
#define	CSI4LNK0_SERRCNT				0xFEAA0140	// R	32
#define	CSI4LNK0_SSERRCNT				0xFEAA0144	// R	32
#define	CSI4LNK0_ECCCM					0xFEAA0148	// R	32
#define	CSI4LNK0_ECECM					0xFEAA014C	// R	32
#define	CSI4LNK0_CRCECM					0xFEAA0150	// R	32
#define	CSI4LNK0_LCNT					0xFEAA0160	// R	32
#define	CSI4LNK0_LCNT2					0xFEAA0164	// R	32
#define	CSI4LNK0_LCNTM					0xFEAA0168	// R	32
#define	CSI4LNK0_LCNTM2					0xFEAA016C	// R	32
#define	CSI4LNK0_FCNTM					0xFEAA0170	// R	32
#define	CSI4LNK0_PHYDIM					0xFEAA0180	// R	32
#define	CSI4LNK0_PHYIM					0xFEAA0184	// R	32
#define	CSI4LNK0_RCUDM					0xFEAA018C	// R	32
#define	CSI4LNK0_RCUSM1					0xFEAA0190	// R	32
#define	CSI4LNK0_RCUSM2					0xFEAA0194	// R	32
#define	CSI4LNK0_RCUSM3					0xFEAA0198	// R	32
#define	CSI4LNK0_PHYOM					0xFEAA019C	// R	32
#define	CSI4LNK0_PHM1					0xFEAA01C0	// R	32
#define	CSI4LNK0_PHM2					0xFEAA01C4	// R	32
#define	CSI4LNK0_PHM3					0xFEAA01C8	// R	32
#define	CSI4LNK0_PHM4					0xFEAA01CC	// R	32
#define	CSI4LNK0_PHM5					0xFEAA01D0	// R	32
#define	CSI4LNK0_PHM6					0xFEAA01D4	// R	32
#define	CSI4LNK0_PHM7					0xFEAA01D8	// R	32
#define	CSI4LNK0_PHM8					0xFEAA01DC	// R	32
#define	CSI4LNK0_PPM1					0xFEAA01E0	// R	32
#define	CSI4LNK0_PPM2					0xFEAA01E4	// R	32
#define	CSI4LNK0_PPM3					0xFEAA01E8	// R	32
#define	CSI4LNK0_PPM4					0xFEAA01EC	// R	32
#define	CSI4LNK0_PPM5					0xFEAA01F0	// R	32
#define	CSI4LNK0_PPM6					0xFEAA01F4	// R	32
#define	CSI4LNK0_PPM7					0xFEAA01F8	// R	32
#define	CSI4LNK0_PPM8					0xFEAA01FC	// R	32


//DU
#define	DU0_DSYSR						0xFEB00000	// R/W	32	Display unit system control register n
#define	DU0_DSMR						0xFEB00004	// R/W	32	Display unit mode register n
#define	DU0_DSSR						0xFEB00008	// R	32	Display unit status register n
#define	DU0_DSRCR						0xFEB0000C	// W	32	Display unit status register clear register n
#define	DU0_DIER						0xFEB00010	// R/W	32	Display unit interrupt enable register n
#define	DU0_DPPR						0xFEB00018	// R/W	32	Display plane priority register m
#define	DU0_DEFR						0xFEB00020	// R/W	32	Display unit extensional function control register n
#define	DU0_DEF5R						0xFEB000E0	// R/W	32	Display unit extensional function control 5 register m
#define	DU0_DDLTR 						0xFEB000E4	// R/W	32	Display unit data latency adjustment register 
#define	DU0_DEF6R						0xFEB000E8	// R/W	32	Display unit extensional function control 6 register m
#define	DU0_DEF7R						0xFEB000EC	// R/W	32	Display unit extensional function control 7 register m
#define	DU1_DSYSR						0xFEB30000	// R/W	32	Display unit system control register n
#define	DU1_DSMR						0xFEB30004	// R/W	32	Display unit mode register n
#define	DU1_DSSR						0xFEB30008	// R	32	Display unit status register n
#define	DU1_DSRCR						0xFEB3000C	// W	32	Display unit status register clear register n
#define	DU1_DIER						0xFEB30010	// R/W	32	Display unit interrupt enable register n
#define	DU1_DEFR						0xFEB30020	// R/W	32	Display unit extensional function control register n
#define	DU2_DSYSR						0xFEB40000	// R/W	32	Display unit system control register n
#define	DU2_DSMR						0xFEB40004	// R/W	32	Display unit mode register n
#define	DU2_DSSR						0xFEB40008	// R	32	Display unit status register n
#define	DU2_DSRCR						0xFEB4000C	// W	32	Display unit status register clear register n
#define	DU2_DIER						0xFEB40010	// R/W	32	Display unit interrupt enable register n
#define	DU2_DPPR						0xFEB40018	// R/W	32	Display plane priority register m
#define	DU2_DEFR						0xFEB40020	// R/W	32	Display unit extensional function control register n
#define	DU2_DEF5R						0xFEB400E0	// R/W	32	Display unit extensional function control 5 register m
#define	DU2_DEF6R						0xFEB400E8	// R/W	32	Display unit extensional function control 6 register m
#define	DU2_DEF7R						0xFEB400EC	// R/W	32	Display unit extensional function control 7 register m
#define	DU3_DSYSR						0xFEB70000	// R/W	32	Display unit system control register n
#define	DU3_DSMR						0xFEB70004	// R/W	32	Display unit mode register n
#define	DU3_DSSR						0xFEB70008	// R	32	Display unit status register n
#define	DU3_DSRCR						0xFEB7000C	// W	32	Display unit status register clear register n
#define	DU3_DIER						0xFEB70010	// R/W	32	Display unit interrupt enable register n
#define	DU3_DEFR						0xFEB70020	// R/W	32	Display unit extensional function control register n
#define	DU0_DD1SSR0						0xFEB20008	// R	32	Display unit domain 1 status register n
#define	DU0_DD1SRCR0					0xFEB2000C	// W	32	Display unit domain 1 status register clear register n
#define	DU0_DD1IER0						0xFEB20010	// R/W	32	Display unit domain 1 interrupt enable register n
#define	DU0_DEF8R						0xFEB20020	// R/W	32	Display unit extensional function control 8 register m
#define	DU0_DIDSR						0xFEB20028	// R/W	32	Display unit input dot clock select register m
#define	DU0_DEF10R						0xFEB20038	// R/W	32	Display unit extensional function control 10 register m
#define	DU0_DDTHCR						0xFEB2003C	// R/W	32	Display unit dither control  register m
#define	DU0_DPLLCR						0xFEB20044	// R/W	32	Display unit PLL control  register m
#define	DU0_DPLLC2R						0xFEB20048	// R/W	32	Display unit PLL control 2 register m
#define	DU1_DD1SSR1						0xFEB28008	// R	32	Display unit domain 1 status register n
#define	DU1_DD1SRCR1					0xFEB2800C	// W	32	Display unit domain 1 status register clear register n
#define	DU1_DD1IER1						0xFEB28010	// R/W	32	Display unit domain 1 interrupt enable register n
#define	DU2_DD1SSR2						0xFEB60008	// R	32	Display unit domain 1 status register n
#define	DU2_DD1SRCR2					0xFEB6000C	// W	32	Display unit domain 1 status register clear register n
#define	DU2_DD1IER2						0xFEB60010	// R/W	32	Display unit domain 1 interrupt enable register n
#define	DU2_DEF8R						0xFEB60020	// R/W	32	Display unit extensional function control 8 register m
#define	DU2_DOFLR2						0xFEB60024	// R/W	32	Display unit output signal fix register 2
#define	DU2_DIDSR						0xFEB60028	// R/W	32	Display unit input dot clock select register m
#define	DU2_DEF10R						0xFEB60038	// R/W	32	Display unit extensional function control 10 register m
#define	DU2_DDTHCR						0xFEB6003C	// R/W	32	Display unit dither control  register m
#define	DU2_DPLLCR						0xFEB60044	// R/W	32	Display unit PLL control  register m
#define	DU2_DPLLC2R						0xFEB60048	// R/W	32	Display unit PLL control 2 register m
#define	DU3_DD1SSR3						0xFEB68008	// R	32	Display unit domain 1 status register n
#define	DU3_DD1SRCR3					0xFEB6800C	// W	32	Display unit domain 1 status register clear register n
#define	DU3_DD1IER3						0xFEB68010	// R/W	32	Display unit domain 1 interrupt enable register n
#define	DU0_HDSR 						0xFEB00040	// R/W	32	Horizontal display start register n
#define	DU0_HDER						0xFEB00044	// R/W	32	Horizontal display end register n
#define	DU0_VDSR						0xFEB00048	// R/W	32	Vertical display start register n
#define	DU0_VDER 						0xFEB0004C	// R/W	32	Vertical display end register n
#define	DU0_HCR 						0xFEB00050	// R/W	32	Horizontal cycle register n
#define	DU0_HSWR 						0xFEB00054	// R/W	32	Horizontal sync width register n
#define	DU0_VCR							0xFEB00058	// R/W	32	Vertical cycle register n
#define	DU0_VSPR						0xFEB0005C	// R/W	32	Vertical sync point register n
#define	DU0_EQWR 						0xFEB00060	// R/W	32	Equal pulse width register n
#define	DU0_SPWR						0xFEB00064	// R/W	32	Serration width register n
#define	DU0_CLAMPSR						0xFEB00070	// R/W	32	CLAMP signal start register n
#define	DU0_CLAMPWR						0xFEB00074	// R/W	32	CLAMP signal width register n
#define	DU0_DESR						0xFEB00078	// R/W	32	DE signal start register n
#define	DU0_DEWR						0xFEB0007C	// R/W	32	DE signal width register n
#define	DU1_HDSR 						0xFEB30040	// R/W	32	Horizontal display start register n
#define	DU1_HDER						0xFEB30044	// R/W	32	Horizontal display end register n
#define	DU1_VDSR						0xFEB30048	// R/W	32	Vertical display start register n
#define	DU1_VDER 						0xFEB3004C	// R/W	32	Vertical display end register n
#define	DU1_HCR 						0xFEB30050	// R/W	32	Horizontal cycle register n
#define	DU1_HSWR 						0xFEB30054	// R/W	32	Horizontal sync width register n
#define	DU1_VCR							0xFEB30058	// R/W	32	Vertical cycle register n
#define	DU1_VSPR						0xFEB3005C	// R/W	32	Vertical sync point register n
#define	DU1_EQWR 						0xFEB30060	// R/W	32	Equal pulse width register n
#define	DU1_SPWR						0xFEB30064	// R/W	32	Serration width register n
#define	DU1_CLAMPSR						0xFEB30070	// R/W	32	CLAMP signal start register n
#define	DU1_CLAMPWR						0xFEB30074	// R/W	32	CLAMP signal width register n
#define	DU1_DESR						0xFEB30078	// R/W	32	DE signal start register n
#define	DU1_DEWR						0xFEB3007C	// R/W	32	DE signal width register n
#define	DU2_HDSR 						0xFEB40040	// R/W	32	Horizontal display start register n
#define	DU2_HDER						0xFEB40044	// R/W	32	Horizontal display end register n
#define	DU2_VDSR						0xFEB40048	// R/W	32	Vertical display start register n
#define	DU2_VDER 						0xFEB4004C	// R/W	32	Vertical display end register n
#define	DU2_HCR 						0xFEB40050	// R/W	32	Horizontal cycle register n
#define	DU2_HSWR 						0xFEB40054	// R/W	32	Horizontal sync width register n
#define	DU2_VCR							0xFEB40058	// R/W	32	Vertical cycle register n
#define	DU2_VSPR						0xFEB4005C	// R/W	32	Vertical sync point register n
#define	DU2_EQWR 						0xFEB40060	// R/W	32	Equal pulse width register n
#define	DU2_SPWR						0xFEB40064	// R/W	32	Serration width register n
#define	DU2_CLAMPSR						0xFEB40070	// R/W	32	CLAMP signal start register n
#define	DU2_CLAMPWR						0xFEB40074	// R/W	32	CLAMP signal width register n
#define	DU2_DESR						0xFEB40078	// R/W	32	DE signal start register n
#define	DU2_DEWR						0xFEB4007C	// R/W	32	DE signal width register n
#define	DU3_HDSR 						0xFEB70040	// R/W	32	Horizontal display start register n
#define	DU3_HDER						0xFEB70044	// R/W	32	Horizontal display end register n
#define	DU3_VDSR						0xFEB70048	// R/W	32	Vertical display start register n
#define	DU3_VDER 						0xFEB7004C	// R/W	32	Vertical display end register n
#define	DU3_HCR 						0xFEB70050	// R/W	32	Horizontal cycle register n
#define	DU3_HSWR 						0xFEB70054	// R/W	32	Horizontal sync width register n
#define	DU3_VCR							0xFEB70058	// R/W	32	Vertical cycle register n
#define	DU3_VSPR						0xFEB7005C	// R/W	32	Vertical sync point register n
#define	DU3_EQWR 						0xFEB70060	// R/W	32	Equal pulse width register n
#define	DU3_SPWR						0xFEB70064	// R/W	32	Serration width register n
#define	DU3_CLAMPSR						0xFEB70070	// R/W	32	CLAMP signal start register n
#define	DU3_CLAMPWR						0xFEB70074	// R/W	32	CLAMP signal width register n
#define	DU3_DESR						0xFEB70078	// R/W	32	DE signal start register n
#define	DU3_DEWR						0xFEB7007C	// R/W	32	DE signal width register n
#define	DU0_DOOR						0xFEB00090	// R/W	32	Display off mode output register n
#define	DU0_CDER						0xFEB00094	// R/W	32	Color detection register n
#define	DU0_BPOR						0xFEB00098	// R/W	32	Background plane output register n
#define	DU0_RINTOFSR					0xFEB0009C	// R/W	32	Raster interrupt offset register n
#define	DU1_DOOR						0xFEB30090	// R/W	32	Display off mode output register n
#define	DU1_CDER						0xFEB30094	// R/W	32	Color detection register n
#define	DU1_BPOR						0xFEB30098	// R/W	32	Background plane output register n
#define	DU1_RINTOFSR					0xFEB3009C	// R/W	32	Raster interrupt offset register n
#define	DU2_DOOR						0xFEB40090	// R/W	32	Display off mode output register n
#define	DU2_CDER						0xFEB40094	// R/W	32	Color detection register n
#define	DU2_BPOR						0xFEB40098	// R/W	32	Background plane output register n
#define	DU2_RINTOFSR					0xFEB4009C	// R/W	32	Raster interrupt offset register n
#define	DU3_DOOR						0xFEB70090	// R/W	32	Display off mode output register n
#define	DU3_CDER						0xFEB70094	// R/W	32	Color detection register n
#define	DU3_BPOR						0xFEB70098	// R/W	32	Background plane output register n
#define	DU3_RINTOFSR					0xFEB7009C	// R/W	32	Raster interrupt offset register n
#define	DU0_P1MR						0xFEB00100	// R/W	32	Plane 1 mode register m
#define	DU0_P1DSXR						0xFEB00110	// R/W	32	Plane 1 display size X register m
#define	DU0_P1DSYR						0xFEB00114	// R/W	32	Plane 1 display size Y register m
#define	DU0_P1DPXR						0xFEB00118	// R/W	32	Plane 1 display position X register m
#define	DU0_P1DPYR						0xFEB0011C	// R/W	32	Plane 1 display position Y register m
#define	DU0_P1DDC4R						0xFEB00190	// R/W	32	Plane 1 display data control 4 register m
#define	DU0_P3MR						0xFEB00300	// R/W	32	Plane 3 mode register m
#define	DU0_P3DSXR						0xFEB00310	// R/W	32	Plane 3 display size X register m
#define	DU0_P3DSYR						0xFEB00314	// R/W	32	Plane 3 display size Y register m
#define	DU0_P3DPXR						0xFEB00318	// R/W	32	Plane 3 display position X register m
#define	DU0_P3DPYR						0xFEB0031C	// R/W	32	Plane 3 display position Y register m
#define	DU0_P3DDC4R						0xFEB00390	// R/W	32	Plane 3 display data control 4 register m
#define	DU2_P1MR						0xFEB40100	// R/W	32	Plane 1 mode register m
#define	DU2_P1DSXR						0xFEB40110	// R/W	32	Plane 1 display size X register m
#define	DU2_P1DSYR						0xFEB40114	// R/W	32	Plane 1 display size Y register m
#define	DU2_P1DPXR						0xFEB40118	// R/W	32	Plane 1 display position X register m
#define	DU2_P1DPYR						0xFEB4011C	// R/W	32	Plane 1 display position Y register m
#define	DU2_P1DDC4R						0xFEB40190	// R/W	32	Plane 1 display data control 4 register m
#define	DU2_P3MR						0xFEB40300	// R/W	32	Plane 3 mode register m
#define	DU2_P3DSXR						0xFEB40310	// R/W	32	Plane 3 display size X register m
#define	DU2_P3DSYR						0xFEB40314	// R/W	32	Plane 3 display size Y register m
#define	DU2_P3DPXR						0xFEB40318	// R/W	32	Plane 3 display position X register m
#define	DU2_P3DPYR						0xFEB4031C	// R/W	32	Plane 3 display position Y register m
#define	DU2_P3DDC4R						0xFEB40390	// R/W	32	Plane 3 display data control 4 register m
#define	DU0_ESCR						0xFEB10000	// R/W	32	External synchronization control register n
#define	DU1_ESCR						0xFEB31000	// R/W	32	External synchronization control register n
#define	DU2_ESCR						0xFEB50000	// R/W	32	External synchronization control register n
#define	DU3_ESCR						0xFEB71000	// R/W	32	External synchronization control register n
#define	DU2_OTAR						0xFEB50004	// R/W	32	Output signal timing adjustment register 2
#define	DU3_OTAR						0xFEB71004	// R/W	32	Output signal timing adjustment register 3
#define	DU0_DORCR						0xFEB11000	// R/W	32	Display unit output route control register m
#define	DU0_DPTSR						0xFEB11004	// R/W	32	Display plane timing select register m
#define	DU0_DS0PR						0xFEB11020	// R/W	32	Display superimpose 0 priority register m
#define	DU0_DS1PR						0xFEB11024	// R/W	32	Display superimpose 1 priority register
#define	DU2_DORCR						0xFEB51000	// R/W	32	Display unit output route control register m
#define	DU2_DPTSR						0xFEB51004	// R/W	32	Display plane timing select register m
#define	DU2_DS0PR						0xFEB51020	// R/W	32	Display superimpose 0 priority register m
#define	DU2_DS1PR						0xFEB51024	// R/W	32	Display superimpose 1 priority register
#define	DU0_YNCR						0xFEB14080	// R/W	32	Y normalization coefficient register m
#define	DU0_YNOR						0xFEB14084	// R/W	32	Y normalization offset register m
#define	DU0_CRNOR						0xFEB14088	// R/W	32	Cr normalization offset register m
#define	DU0_CBNOR						0xFEB1408C	// R/W	32	Cb normalization offset register m
#define	DU0_RCRCR						0xFEB14090	// R/W	32	Red Cr coefficient register m
#define	DU0_GCRCR						0xFEB14094	// R/W	32	Green Cr coefficient register m
#define	DU0_GCBCR						0xFEB14098	// R/W	32	Green Cb coefficient register m
#define	DU0_BCBCR						0xFEB1409C	// R/W	32	Blue Cb coefficient register m
#define	DU2_YNCR						0xFEB54080	// R/W	32	Y normalization coefficient register m
#define	DU2_YNOR						0xFEB54084	// R/W	32	Y normalization offset register m
#define	DU2_CRNOR						0xFEB54088	// R/W	32	Cr normalization offset register m
#define	DU2_CBNOR						0xFEB5408C	// R/W	32	Cb normalization offset register m
#define	DU2_RCRCR						0xFEB54090	// R/W	32	Red Cr coefficient register m
#define	DU2_GCRCR						0xFEB54094	// R/W	32	Green Cr coefficient register m
#define	DU2_GCBCR						0xFEB54098	// R/W	32	Green Cb coefficient register m
#define	DU2_BCBCR						0xFEB5409C	// R/W	32	Blue Cb coefficient register m


//EAVB
#define	EAVB_CCC						0xE6800000	// R/W	32	AVB-DMAC mode register
#define	EAVB_DBAT						0xE6800004	// R/W	32	Descriptor base address table register
#define	EAVB_DLR						0xE6800008	// R/W	32	Descriptor base address load request register
#define	EAVB_CSR						0xE680000C	// R	32	AVB-DMAC status register
#define	EAVB_CDAR0						0xE6800010	// R	32	Current descriptor address register 0
#define	EAVB_CDAR1						0xE6800014	// R	32	Current descriptor address register 1
#define	EAVB_CDAR2						0xE6800018	// R	32	Current descriptor address register 2
#define	EAVB_CDAR3						0xE680001C	// R	32	Current descriptor address register 3
#define	EAVB_CDAR4						0xE6800020	// R	32	Current descriptor address register 4
#define	EAVB_CDAR5						0xE6800024	// R	32	Current descriptor address register 5
#define	EAVB_CDAR6						0xE6800028	// R	32	Current descriptor address register 6
#define	EAVB_CDAR7						0xE680002C	// R	32	Current descriptor address register 7
#define	EAVB_CDAR8						0xE6800030	// R	32	Current descriptor address register 8
#define	EAVB_CDAR9						0xE6800034	// R	32	Current descriptor address register 9
#define	EAVB_CDAR10						0xE6800038	// R	32	Current descriptor address register 10
#define	EAVB_CDAR11						0xE680003C	// R	32	Current descriptor address register 11
#define	EAVB_CDAR12						0xE6800040	// R	32	Current descriptor address register 12
#define	EAVB_CDAR13						0xE6800044	// R	32	Current descriptor address register 13
#define	EAVB_CDAR14						0xE6800048	// R	32	Current descriptor address register 14
#define	EAVB_CDAR15						0xE680004C	// R	32	Current descriptor address register 15
#define	EAVB_CDAR16						0xE6800050	// R	32	Current descriptor address register 16
#define	EAVB_CDAR17						0xE6800054	// R	32	Current descriptor address register 17
#define	EAVB_CDAR18						0xE6800058	// R	32	Current descriptor address register 18
#define	EAVB_CDAR19						0xE680005C	// R	32	Current descriptor address register 19
#define	EAVB_CDAR20						0xE6800060	// R	32	Current descriptor address register 20
#define	EAVB_CDAR21						0xE6800064	// R	32	Current descriptor address register 21
#define	EAVB_ESR						0xE6800088	// R	32	Error status register
#define	EAVB_APSR						0xE680008C	// R/W	32	AVB-DMAC Product Specific Register
#define	EAVB_RCR						0xE6800090	// R/W	32	Receive configuration register
#define	EAVB_RQC0						0xE6800094	// R/W	32	Receive queue configuration register 0
#define	EAVB_RQC1						0xE6800098	// R/W	32	Receive queue configuration register 1
#define	EAVB_RQC2						0xE680009C	// R/W	32	Receive queue configuration register 2
#define	EAVB_RQC3						0xE68000A0	// R/W	32	Receive queue configuration register 3
#define	EAVB_RQC4						0xE68000A4	// R/W	32	Receive queue configuration register 4
#define	EAVB_RPC						0xE68000B0	// R/W	32	Receive padding configuration register
#define	EAVB_RTC						0xE68000B4	// R/W	32	Reception Truncation Configuration register
#define	EAVB_UFCW						0xE68000BC	// R/W	32	Unread frame counter warning level register
#define	EAVB_UFCS						0xE68000C0	// R/W	32	Unread frame counter stop level register
#define	EAVB_UFCV0						0xE68000C4	// R	32	Unread frame counter register 0
#define	EAVB_UFCV1						0xE68000C8	// R	32	Unread frame counter register 1
#define	EAVB_UFCV2						0xE68000CC	// R	32	Unread frame counter register 2
#define	EAVB_UFCV3						0xE68000D0	// R	32	Unread frame counter register 3
#define	EAVB_UFCV4						0xE68000D4	// R	32	Unread frame counter register 4
#define	EAVB_UFCD0						0xE68000E0	// R/W	32	Unread frame counter decrement register 0
#define	EAVB_UFCD1						0xE68000E4	// R/W	32	Unread frame counter decrement register 1
#define	EAVB_UFCD2						0xE68000E8	// R/W	32	Unread frame counter decrement register 2
#define	EAVB_UFCD3						0xE68000EC	// R/W	32	Unread frame counter decrement register 3
#define	EAVB_UFCD4						0xE68000F0	// R/W	32	Unread frame counter decrement register 4
#define	EAVB_SFO						0xE68000FC	// R/W	32	Separation filter offset register
#define	EAVB_SFP0						0xE6800100	// R/W	32	Separation filter pattern register 0
#define	EAVB_SFP1						0xE6800104	// R/W	32	Separation filter pattern register 1
#define	EAVB_SFP2						0xE6800108	// R/W	32	Separation filter pattern register 2
#define	EAVB_SFP3						0xE680010C	// R/W	32	Separation filter pattern register 3
#define	EAVB_SFP4						0xE6800110	// R/W	32	Separation filter pattern register 4
#define	EAVB_SFP5						0xE6800114	// R/W	32	Separation filter pattern register 5
#define	EAVB_SFP6						0xE6800118	// R/W	32	Separation filter pattern register 6
#define	EAVB_SFP7						0xE680011C	// R/W	32	Separation filter pattern register 7
#define	EAVB_SFP8						0xE6800120	// R/W	32	Separation filter pattern register 8
#define	EAVB_SFP9						0xE6800124	// R/W	32	Separation filter pattern register 9
#define	EAVB_SFP10						0xE6800128	// R/W	32	Separation filter pattern register 10
#define	EAVB_SFP11						0xE680012C	// R/W	32	Separation filter pattern register 11
#define	EAVB_SFP12						0xE6800130	// R/W	32	Separation filter pattern register 12
#define	EAVB_SFP13						0xE6800134	// R/W	32	Separation filter pattern register 13
#define	EAVB_SFP14						0xE6800138	// R/W	32	Separation filter pattern register 14
#define	EAVB_SFP15						0xE680013C	// R/W	32	Separation filter pattern register 15
#define	EAVB_SFP16						0xE6800140	// R/W	32	Separation filter pattern register 16
#define	EAVB_SFP17						0xE6800144	// R/W	32	Separation filter pattern register 17
#define	EAVB_SFP18						0xE6800148	// R/W	32	Separation filter pattern register 18
#define	EAVB_SFP19						0xE680014C	// R/W	32	Separation filter pattern register 19
#define	EAVB_SFP20						0xE6800150	// R/W	32	Separation filter pattern register 20
#define	EAVB_SFP21						0xE6800154	// R/W	32	Separation filter pattern register 21
#define	EAVB_SFP22						0xE6800158	// R/W	32	Separation filter pattern register 22
#define	EAVB_SFP23						0xE680015C	// R/W	32	Separation filter pattern register 23
#define	EAVB_SFP24						0xE6800160	// R/W	32	Separation filter pattern register 24
#define	EAVB_SFP25						0xE6800164	// R/W	32	Separation filter pattern register 25
#define	EAVB_SFP26						0xE6800168	// R/W	32	Separation filter pattern register 26
#define	EAVB_SFP27						0xE680016C	// R/W	32	Separation filter pattern register 27
#define	EAVB_SFP28						0xE6800170	// R/W	32	Separation filter pattern register 28
#define	EAVB_SFP29						0xE6800174	// R/W	32	Separation filter pattern register 29
#define	EAVB_SFP30						0xE6800178	// R/W	32	Separation filter pattern register 30
#define	EAVB_SFP31						0xE680017C	// R/W	32	Separation filter pattern register 31
#define	EAVB_SFV0						0xE68001B8	// R/W	32	Separation Filter Value register 0
#define	EAVB_SFV1						0xE68001BC	// R/W	32	Separation Filter Value register 1
#define	EAVB_SFM0						0xE68001C0	// R/W	32	Separation filter mask register 0
#define	EAVB_SFM1						0xE68001C4	// R/W	32	Separation filter mask register 1
#define	EAVB_SFL						0xE68001C8	// R/W	32	Separation Filter Load register
#define	EAVB_PCRC						0xE68001CC	// R/W	32	Payload CRC register
#define	EAVB_CIAR0						0xE6800200	// R	32	Current Incremental Address Register 0
#define	EAVB_CIAR1						0xE6800204	// R	32	Current Incremental Address Register 1
#define	EAVB_CIAR2						0xE6800208	// R	32	Current Incremental Address Register 2
#define	EAVB_CIAR3						0xE680020C	// R	32	Current Incremental Address Register 3
#define	EAVB_CIAR4						0xE6800210	// R	32	Current Incremental Address Register 4
#define	EAVB_CIAR5						0xE6800214	// R	32	Current Incremental Address Register 5
#define	EAVB_CIAR6						0xE6800218	// R	32	Current Incremental Address Register 6
#define	EAVB_CIAR7						0xE680021C	// R	32	Current Incremental Address Register 7
#define	EAVB_CIAR8						0xE6800220	// R	32	Current Incremental Address Register 8
#define	EAVB_CIAR9						0xE6800224	// R	32	Current Incremental Address Register 9
#define	EAVB_CIAR10						0xE6800228	// R	32	Current Incremental Address Register 10
#define	EAVB_CIAR11						0xE680022C	// R	32	Current Incremental Address Register 11
#define	EAVB_CIAR12						0xE6800230	// R	32	Current Incremental Address Register 12
#define	EAVB_CIAR13						0xE6800234	// R	32	Current Incremental Address Register 13
#define	EAVB_CIAR14						0xE6800238	// R	32	Current Incremental Address Register 14
#define	EAVB_CIAR15						0xE680023C	// R	32	Current Incremental Address Register 15
#define	EAVB_CIAR16						0xE6800240	// R	32	Current Incremental Address Register 16
#define	EAVB_CIAR17						0xE6800244	// R	32	Current Incremental Address Register 17
#define	EAVB_LIAR0						0xE6800280	// R	32	Last Incremental Address Register 0
#define	EAVB_LIAR1						0xE6800284	// R	32	Last Incremental Address Register 1
#define	EAVB_LIAR2						0xE6800288	// R	32	Last Incremental Address Register 2
#define	EAVB_LIAR3						0xE680028C	// R	32	Last Incremental Address Register 3
#define	EAVB_LIAR4						0xE6800290	// R	32	Last Incremental Address Register 4
#define	EAVB_LIAR5						0xE6800294	// R	32	Last Incremental Address Register 5
#define	EAVB_LIAR6						0xE6800298	// R	32	Last Incremental Address Register 6
#define	EAVB_LIAR7						0xE680029C	// R	32	Last Incremental Address Register 7
#define	EAVB_LIAR8						0xE68002A0	// R	32	Last Incremental Address Register 8
#define	EAVB_LIAR9						0xE68002A4	// R	32	Last Incremental Address Register 9
#define	EAVB_LIAR10						0xE68002A8	// R	32	Last Incremental Address Register 10
#define	EAVB_LIAR11						0xE68002AC	// R	32	Last Incremental Address Register 11
#define	EAVB_LIAR12						0xE68002B0	// R	32	Last Incremental Address Register 12
#define	EAVB_LIAR13						0xE68002B4	// R	32	Last Incremental Address Register 13
#define	EAVB_LIAR14						0xE68002B8	// R	32	Last Incremental Address Register 14
#define	EAVB_LIAR15						0xE68002BC	// R	32	Last Incremental Address Register 15
#define	EAVB_LIAR16						0xE68002C0	// R	32	Last Incremental Address Register 16
#define	EAVB_LIAR17						0xE68002C4	// R	32	Last Incremental Address Register 17
#define	EAVB_TGC						0xE6800300	// R/W	32	Transmit configuration register
#define	EAVB_TCCR						0xE6800304	// R/W	32	Transmit configuration control register
#define	EAVB_TSR						0xE6800308	// R	32	Transmit status register
#define	EAVB_MFA						0xE680030C	// R	32	E-MAC status FIFO Access register
#define	EAVB_TFA0						0xE6800310	// R	32	Time stamp FIFO access register 0
#define	EAVB_TFA1						0xE6800314	// R	32	Time stamp FIFO access register 1
#define	EAVB_TFA2						0xE6800318	// R	32	Time stamp FIFO access register 2
#define	EAVB_CIVR0						0xE6800320	// R/W	32	CBS increment value register 0
#define	EAVB_CIVR1						0xE6800324	// R/W	32	CBS increment value register 1
#define	EAVB_CDVR0						0xE6800328	// R/W	32	CBS decrement value register 0
#define	EAVB_CDVR1						0xE680032C	// R/W	32	CBS decrement value register 1
#define	EAVB_CUL0						0xE6800330	// R/W	32	CBS upper limit register 0
#define	EAVB_CUL1						0xE6800334	// R/W	32	CBS upper limit register 1
#define	EAVB_CLL0						0xE6800338	// R/W	32	CBS lower limit register 0
#define	EAVB_CLL1						0xE680033C	// R/W	32	CBS lower limit register 1
#define	EAVB_DIC						0xE6800350	// R/W	32	Descriptor interrupt control register
#define	EAVB_DIS						0xE6800354	// R/W	32	Descriptor interrupt status register
#define	EAVB_EIC						0xE6800358	// R/W	32	Error interrupt control register
#define	EAVB_EIS						0xE680035C	// R/W	32	Error interrupt status register
#define	EAVB_RIC0						0xE6800360	// R/W	32	Receive interrupt control register 0
#define	EAVB_RIS0						0xE6800364	// R/W	32	Receive interrupt status register 0
#define	EAVB_RIC1						0xE6800368	// R/W	32	Receive interrupt control register 1
#define	EAVB_RIS1						0xE680036C	// R/W	32	Receive interrupt status register 1
#define	EAVB_RIC2						0xE6800370	// R/W	32	Receive interrupt control register 2
#define	EAVB_RIS2						0xE6800374	// R/W	32	Receive interrupt status register 2
#define	EAVB_TIC						0xE6800378	// R/W	32	Transmit interrupt control register
#define	EAVB_TIS						0xE680037C	// R/W	32	Transmit interrupt status register
#define	EAVB_ISS						0xE6800380	// R	32	Interrupt summary status register
#define	EAVB_CIE						0xE6800384	// R/W	32	Common Interrupt Enable register
#define	EAVB_RIC3						0xE6800388	// R/W	32	Reception Interrupt Control register 3
#define	EAVB_RIS3						0xE680038C	// R/W	32	Reception Interrupt Status register 3
#define	EAVB_GCCR						0xE6800390	// R/W	32	gPTP configuration control register
#define	EAVB_GMTT						0xE6800394	// R/W	32	gPTP maximum transit time register
#define	EAVB_GPTC						0xE6800398	// R/W	32	gPTP presentation time comparison register
#define	EAVB_GTI						0xE680039C	// R/W	32	gPTP timer increment register
#define	EAVB_GTO0						0xE68003A0	// R/W	32	gPTP timer offset register 0
#define	EAVB_GTO1						0xE68003A4	// R/W	32	gPTP timer offset register 1
#define	EAVB_GTO2						0xE68003A8	// R/W	32	gPTP timer offset register 2
#define	EAVB_GIC						0xE68003AC	// R/W	32	gPTP interrupt control register
#define	EAVB_GIS						0xE68003B0	// R/W	32	gPTP interrupt status register
#define	EAVB_GCPT						0xE68003B4	// R	32	Gptp Captured Presentation Time register
#define	EAVB_GCT0						0xE68003B8	// R/W	32	gPTP timer capture register 0
#define	EAVB_GCT1						0xE68003BC	// R/W	32	gPTP timer capture register 1
#define	EAVB_GCT2						0xE68003C0	// R/W	32	gPTP timer capture register 2
#define	EAVB_GSR						0xE68003C4	// R	32	Gptp Status Register
#define	EAVB_GIE						0xE68003CC	// R/W	32	Gptp Interrupt Enable register
#define	EAVB_GID						0xE68003D0	// R/W	32	Gptp Interrupt Disable register
#define	EAVB_GIL						0xE68003D4	// R/W	32	Gptp Interrupt Line selection register
#define	EAVB_GACP						0xE68003DC	// R/W	32	Gptp Avtp Capture Prescaler register
#define	EAVB_GCAT0						0xE6800400	// R	32	Gptp Captured Avtp Time register 0
#define	EAVB_GCAT1						0xE6800404	// R	32	Gptp Captured Avtp Time register 1
#define	EAVB_GCAT2						0xE6800408	// R	32	Gptp Captured Avtp Time register 2
#define	EAVB_DIL						0xE6800440	// R/W	32	Descriptor Interrupt Line selection register
#define	EAVB_EIL						0xE6800444	// R/W	32	Error Interrupt Line selection register
#define	EAVB_TIL						0xE6800448	// R/W	32	Transmission Interrupt Line selection register
#define	EAVB_DIE						0xE6800450	// R/W	32	Descriptor Interrupt Enable register
#define	EAVB_DID						0xE6800454	// R/W	32	Descriptor Interrupt Disable register
#define	EAVB_EIE						0xE6800458	// R/W	32	Error Interrupt Enable register
#define	EAVB_EID						0xE680045C	// R/W	32	Error Interrupt Disable Register
#define	EAVB_RIE0						0xE6800460	// R/W	32	Reception Interrupt Enable register 0
#define	EAVB_RID0						0xE6800464	// R/W	32	Reception Interrupt Disable register 0
#define	EAVB_RIE1						0xE6800468	// R/W	32	Reception Interrupt Enable register 1
#define	EAVB_RID1						0xE680046C	// R/W	32	Reception Interrupt Disable register 1
#define	EAVB_RIE2						0xE6800470	// R/W	32	Reception Interrupt Enable register 2
#define	EAVB_RID2						0xE6800474	// R/W	32	Reception Interrupt Disable register 2
#define	EAVB_TIE						0xE6800478	// R/W	32	Transmission Interrupt Enable register
#define	EAVB_TID						0xE680047C	// R/W	32	Transmission Interrupt Disable register
#define	EAVB_RIE3						0xE6800488	// R/W	32	Reception Interrupt Enable register 3
#define	EAVB_RID3						0xE680048C	// R/W	32	Reception Interrupt Disable register 3
#define	EAVB_ECMR						0xE6800500	// R/W	32	E-MAC mode register
#define	EAVB_RFLR						0xE6800508	// R/W	32	Receive frame length register
#define	EAVB_ECSR						0xE6800510	// R/W	32	E-MAC status register
#define	EAVB_ECSIPR						0xE6800518	// R/W	32	E-MAC interrupt permission register
#define	EAVB_PIR						0xE6800520	// R/W	32	PHY interface register
#define	EAVB_PSR						0xE6800528	// R	32	PHY Status Register
#define	EAVB_PIPR						0xE680052C	// R/W	32	PHY_INT Polarity Register
#define	EAVB_APR						0xE6800554	// R/W	32	Auto PAUSE frame register
#define	EAVB_MPR						0xE6800558	// R/W	32	Manual PAUSE frame register
#define	EAVB_PFTCR						0xE680055C	// R	32	PAUSE frame transmit counter
#define	EAVB_PFRCR						0xE6800560	// R	32	PAUSE frame receive counter
#define	EAVB_PFTTLR						0xE6800564	// R/W	32	PAUSE frame transmit times limit
#define	EAVB_PFTTCR						0xE6800568	// R	32	PAUSE frame transmit times counter
#define	EAVB_GECMR						0xE68005B0	// R/W	32	EthernetAVB Mode Register
#define	EAVB_MAHR						0xE68005C0	// R/W	32	E-MAC address high register
#define	EAVB_MALR						0xE68005C8	// R/W	32	E-MAC address low register
#define	EAVB_FTTOCR						0xE6800700	// R/W	32	Frame transmit time-out counter
#define	EAVB_CEFCR						0xE6800740	// R/W	32	CRC error frame receive counter register
#define	EAVB_FRECR						0xE6800748	// R/W	32	Frame receive error counter register
#define	EAVB_TSFRCR						0xE6800750	// R/W	32	Too-short frame receive counter register
#define	EAVB_TLFRCR						0xE6800758	// R/W	32	Too-long frame receive counter register
#define	EAVB_RFCR						0xE6800760	// R/W	32	Residual-bit frame receive counter register
#define	EAVB_MAFCR						0xE6800778	// R/W	32	Multicast address frame receive counter register



//EHCI0
#define	EHCI0_HcRevision				0xEE080000	// R/W	32	HcRevision
#define	EHCI0_HcControl					0xEE080004	// R/W	32	HcControl
#define	EHCI0_HcCommandStatus			0xEE080008	// R/W	32	HcCommandStatus
#define	EHCI0_HcInterruptStatus			0xEE08000C	// R/W	32	HcInterruptStatus
#define	EHCI0_HcInterruptEnable			0xEE080010	// R/W	32	HcInterruptEnable
#define	EHCI0_HcInterruptDisable		0xEE080014	// R/W	32	HcInterruptDisable
#define	EHCI0_HcHCCA					0xEE080018	// R/W	32	HcHCCA
#define	EHCI0_HcPeriodCurrentED			0xEE08001C	// R/W	32	HcPeriodCurrentED
#define	EHCI0_HcControlHeadED			0xEE080020	// R/W	32	HcControlHeadED
#define	EHCI0_HcControlCurrentED		0xEE080024	// R/W	32	HcControlCurrentED
#define	EHCI0_HcBulkHeadED				0xEE080028	// R/W	32	HcBulkHeadED
#define	EHCI0_HcBulkCurrentED			0xEE08002C	// R/W	32	HcBulkCurrentED
#define	EHCI0_HcDoneHead				0xEE080030	// R/W	32	HcDoneHead
#define	EHCI0_HcFmInterval				0xEE080034	// R/W	32	HcFmInterval
#define	EHCI0_HcFmRemaining				0xEE080038	// R/W	32	HcFmRemaining
#define	EHCI0_HcFmNumber				0xEE08003C	// R/W	32	HcFmNumber
#define	EHCI0_HcPeriodicStart			0xEE080040	// R/W	32	HcPeriodicStart
#define	EHCI0_HcLSThreshold				0xEE080044	// R/W	32	HcLSThreshold
#define	EHCI0_HcRhDescriptorA			0xEE080048	// R/W	32	HcRhDescriptorA
#define	EHCI0_HcRhDescriptorB			0xEE08004C	// R/W	32	HcRhDescriptorB
#define	EHCI0_HcRhStatus				0xEE080050	// R/W	32	HcRhStatus
#define	EHCI0_HcRhPortStatus1			0xEE080054	// R/W	32	HcRhPortStatus1
#define	EHCI0_CAPL_VERSION				0xEE080100	// R/W	32	HCIVERSION / CAPLENGTH
#define	EHCI0_HCSPARAMS					0xEE080104	// R/W	32	HCSPARAMS
#define	EHCI0_HCCPARAMS					0xEE080108	// R/W	32	HCCPARAMS
#define	EHCI0_HCSP_PORTROUTE			0xEE08010C	// R/W	32	HCSP_PORTROUTE
#define	EHCI0_USBCMD					0xEE080120	// R/W	32	USBCMD
#define	EHCI0_USBSTS					0xEE080124	// R/W	32	USBSTS
#define	EHCI0_USBINTR					0xEE080128	// R/W	32	USBINTR
#define	EHCI0_FRINDEX					0xEE08012C	// R/W	32	FRINDEX
#define	EHCI0_CTRLDSSEGMENT				0xEE080130	// R/W	32	CTRLDSSEGMENT
#define	EHCI0_PERIODICLISTBASE			0xEE080134	// R/W	32	PERIODICLISTBASE
#define	EHCI0_ASYNCLISTADDR				0xEE080138	// R/W	32	ASYNCLISTADDR
#define	EHCI0_CONFIGFLAG				0xEE080160	// R/W	32	CONFIGFLAG
#define	EHCI0_PORTSC1					0xEE080164	// R/W	32	PORTSC1
#define	EHCI0_INT_ENABLE				0xEE080200	// R/W	32	INT_ENABLE
#define	EHCI0_INT_STATUS				0xEE080204	// R/W	32	INT_STATUS
#define	EHCI0_AHB_BUS_CTR				0xEE080208	// R/W	32	AHB_BUS_CTR
#define	EHCI0_USBCTR					0xEE08020C	// R/W	32	USBCTR
#define	EHCI0_REVID						0xEE080300	// R/W	32	REVID
#define	EHCI0_REGEN_CG_CTRL				0xEE080304	// R/W	32	Register Enable/Clock Gating Control
#define	EHCI0_SPD_CTRL					0xEE080308	// R/W	32	Suspend Control
#define	EHCI0_SPD_RSM_TIMSET			0xEE08030C	// R/W	32	Suspend/Resume Timer Setting
#define	EHCI0_OC_TIMSET					0xEE080310	// R/W	32	Overcurrent Detection Timer Setting
#define	EHCI0_SBRN_FLADJ_PW 			0xEE080314	// R/W	32	SBRN, FLADJ, PORTWAKECAP
#define	EHCI0_COMMCTRL					0xEE080800	// R/W	32	Common Control
#define	EHCI0_OBINTSTA					0xEE080804	// R/W	32	OTG-BC Interrupt Status
#define	EHCI0_OBINTEN					0xEE080808	// R/W	32	OTG-BC Interrupt Enable
#define	EHCI0_VBCTRL					0xEE08080C	// R/W	32	VBUS Control
#define	EHCI0_LINECTRL1					0xEE080810	// R/W	32	Line Control Port1
#define	EHCI0_BCCTRL1					0xEE080820	// R/W	32	BC Control Port1
#define	EHCI0_ADPCTRL					0xEE080830	// R/W	32	ADP Control



//EHCI1
#define	EHCI1_HcRevision				0xEE0A0000	// R/W	32	HcRevision
#define	EHCI1_HcControl					0xEE0A0004	// R/W	32	HcControl
#define	EHCI1_HcCommandStatus			0xEE0A0008	// R/W	32	HcCommandStatus
#define	EHCI1_HcInterruptStatus			0xEE0A000C	// R/W	32	HcInterruptStatus
#define	EHCI1_HcInterruptEnable			0xEE0A0010	// R/W	32	HcInterruptEnable
#define	EHCI1_HcInterruptDisable		0xEE0A0014	// R/W	32	HcInterruptDisable
#define	EHCI1_HcHCCA					0xEE0A0018	// R/W	32	HcHCCA
#define	EHCI1_HcPeriodCurrentED			0xEE0A001C	// R/W	32	HcPeriodCurrentED
#define	EHCI1_HcControlHeadED			0xEE0A0020	// R/W	32	HcControlHeadED
#define	EHCI1_HcControlCurrentED		0xEE0A0024	// R/W	32	HcControlCurrentED
#define	EHCI1_HcBulkHeadED				0xEE0A0028	// R/W	32	HcBulkHeadED
#define	EHCI1_HcBulkCurrentED			0xEE0A002C	// R/W	32	HcBulkCurrentED
#define	EHCI1_HcDoneHead				0xEE0A0030	// R/W	32	HcDoneHead
#define	EHCI1_HcFmInterval				0xEE0A0034	// R/W	32	HcFmInterval
#define	EHCI1_HcFmRemaining				0xEE0A0038	// R/W	32	HcFmRemaining
#define	EHCI1_HcFmNumber				0xEE0A003C	// R/W	32	HcFmNumber
#define	EHCI1_HcPeriodicStart			0xEE0A0040	// R/W	32	HcPeriodicStart
#define	EHCI1_HcLSThreshold				0xEE0A0044	// R/W	32	HcLSThreshold
#define	EHCI1_HcRhDescriptorA			0xEE0A0048	// R/W	32	HcRhDescriptorA
#define	EHCI1_HcRhDescriptorB			0xEE0A004C	// R/W	32	HcRhDescriptorB
#define	EHCI1_HcRhStatus				0xEE0A0050	// R/W	32	HcRhStatus
#define	EHCI1_HcRhPortStatus1			0xEE0A0054	// R/W	32	HcRhPortStatus1
#define	EHCI1_CAPL_VERSION				0xEE0A0100	// R/W	32	HCIVERSION / CAPLENGTH
#define	EHCI1_HCSPARAMS					0xEE0A0104	// R/W	32	HCSPARAMS
#define	EHCI1_HCCPARAMS					0xEE0A0108	// R/W	32	HCCPARAMS
#define	EHCI1_HCSP_PORTROUTE			0xEE0A010C	// R/W	32	HCSP_PORTROUTE
#define	EHCI1_USBCMD					0xEE0A0120	// R/W	32	USBCMD
#define	EHCI1_USBSTS					0xEE0A0124	// R/W	32	USBSTS
#define	EHCI1_USBINTR					0xEE0A0128	// R/W	32	USBINTR
#define	EHCI1_FRINDEX					0xEE0A012C	// R/W	32	FRINDEX
#define	EHCI1_CTRLDSSEGMENT				0xEE0A0130	// R/W	32	CTRLDSSEGMENT
#define	EHCI1_PERIODICLISTBASE			0xEE0A0134	// R/W	32	PERIODICLISTBASE
#define	EHCI1_ASYNCLISTADDR				0xEE0A0138	// R/W	32	ASYNCLISTADDR
#define	EHCI1_CONFIGFLAG				0xEE0A0160	// R/W	32	CONFIGFLAG
#define	EHCI1_PORTSC1					0xEE0A0164	// R/W	32	PORTSC1
#define	EHCI1_INT_ENABLE				0xEE0A0200	// R/W	32	INT_ENABLE
#define	EHCI1_INT_STATUS				0xEE0A0204	// R/W	32	INT_STATUS
#define	EHCI1_AHB_BUS_CTR				0xEE0A0208	// R/W	32	AHB_BUS_CTR
#define	EHCI1_USBCTR					0xEE0A020C	// R/W	32	USBCTR
#define	EHCI1_REVID						0xEE0A0300	// R/W	32	REVID
#define	EHCI1_REGEN_CG_CTRL				0xEE0A0304	// R/W	32	Register Enable/Clock Gating Control
#define	EHCI1_SPD_CTRL					0xEE0A0308	// R/W	32	Suspend Control
#define	EHCI1_SPD_RSM_TIMSET			0xEE0A030C	// R/W	32	Suspend/Resume Timer Setting
#define	EHCI1_OC_TIMSET					0xEE0A0310	// R/W	32	Overcurrent Detection Timer Setting
#define	EHCI1_SBRN_FLADJ_PW 			0xEE0A0314	// R/W	32	SBRN, FLADJ, PORTWAKECAP
#define	EHCI1_COMMCTRL					0xEE0A0800	// R/W	32	Common Control
#define	EHCI1_OBINTSTA					0xEE0A0804	// R/W	32	OTG-BC Interrupt Status
#define	EHCI1_OBINTEN					0xEE0A0808	// R/W	32	OTG-BC Interrupt Enable
#define	EHCI1_VBCTRL					0xEE0A080C	// R/W	32	VBUS Control
#define	EHCI1_LINECTRL1					0xEE0A0810	// R/W	32	Line Control Port1
#define	EHCI1_BCCTRL1					0xEE0A0820	// R/W	32	BC Control Port1
#define	EHCI1_ADPCTRL					0xEE0A0830	// R/W	32	ADP Control



//EHCI2
#define	EHCI2_HcRevision				0xEE0C0000	// R/W	32	HcRevision
#define	EHCI2_HcControl					0xEE0C0004	// R/W	32	HcControl
#define	EHCI2_HcCommandStatus			0xEE0C0008	// R/W	32	HcCommandStatus
#define	EHCI2_HcInterruptStatus			0xEE0C000C	// R/W	32	HcInterruptStatus
#define	EHCI2_HcInterruptEnable			0xEE0C0010	// R/W	32	HcInterruptEnable
#define	EHCI2_HcInterruptDisable		0xEE0C0014	// R/W	32	HcInterruptDisable
#define	EHCI2_HcHCCA					0xEE0C0018	// R/W	32	HcHCCA
#define	EHCI2_HcPeriodCurrentED			0xEE0C001C	// R/W	32	HcPeriodCurrentED
#define	EHCI2_HcControlHeadED			0xEE0C0020	// R/W	32	HcControlHeadED
#define	EHCI2_HcControlCurrentED		0xEE0C0024	// R/W	32	HcControlCurrentED
#define	EHCI2_HcBulkHeadED				0xEE0C0028	// R/W	32	HcBulkHeadED
#define	EHCI2_HcBulkCurrentED			0xEE0C002C	// R/W	32	HcBulkCurrentED
#define	EHCI2_HcDoneHead				0xEE0C0030	// R/W	32	HcDoneHead
#define	EHCI2_HcFmInterval				0xEE0C0034	// R/W	32	HcFmInterval
#define	EHCI2_HcFmRemaining				0xEE0C0038	// R/W	32	HcFmRemaining
#define	EHCI2_HcFmNumber				0xEE0C003C	// R/W	32	HcFmNumber
#define	EHCI2_HcPeriodicStart			0xEE0C0040	// R/W	32	HcPeriodicStart
#define	EHCI2_HcLSThreshold				0xEE0C0044	// R/W	32	HcLSThreshold
#define	EHCI2_HcRhDescriptorA			0xEE0C0048	// R/W	32	HcRhDescriptorA
#define	EHCI2_HcRhDescriptorB			0xEE0C004C	// R/W	32	HcRhDescriptorB
#define	EHCI2_HcRhStatus				0xEE0C0050	// R/W	32	HcRhStatus
#define	EHCI2_HcRhPortStatus1			0xEE0C0054	// R/W	32	HcRhPortStatus1
#define	EHCI2_CAPL_VERSION				0xEE0C0100	// R/W	32	HCIVERSION / CAPLENGTH
#define	EHCI2_HCSPARAMS					0xEE0C0104	// R/W	32	HCSPARAMS
#define	EHCI2_HCCPARAMS					0xEE0C0108	// R/W	32	HCCPARAMS
#define	EHCI2_HCSP_PORTROUTE			0xEE0C010C	// R/W	32	HCSP_PORTROUTE
#define	EHCI2_USBCMD					0xEE0C0120	// R/W	32	USBCMD
#define	EHCI2_USBSTS					0xEE0C0124	// R/W	32	USBSTS
#define	EHCI2_USBINTR					0xEE0C0128	// R/W	32	USBINTR
#define	EHCI2_FRINDEX					0xEE0C012C	// R/W	32	FRINDEX
#define	EHCI2_CTRLDSSEGMENT				0xEE0C0130	// R/W	32	CTRLDSSEGMENT
#define	EHCI2_PERIODICLISTBASE			0xEE0C0134	// R/W	32	PERIODICLISTBASE
#define	EHCI2_ASYNCLISTADDR				0xEE0C0138	// R/W	32	ASYNCLISTADDR
#define	EHCI2_CONFIGFLAG				0xEE0C0160	// R/W	32	CONFIGFLAG
#define	EHCI2_PORTSC1					0xEE0C0164	// R/W	32	PORTSC1
#define	EHCI2_INT_ENABLE				0xEE0C0200	// R/W	32	INT_ENABLE
#define	EHCI2_INT_STATUS				0xEE0C0204	// R/W	32	INT_STATUS
#define	EHCI2_AHB_BUS_CTR				0xEE0C0208	// R/W	32	AHB_BUS_CTR
#define	EHCI2_USBCTR					0xEE0C020C	// R/W	32	USBCTR
#define	EHCI2_REVID						0xEE0C0300	// R/W	32	REVID
#define	EHCI2_REGEN_CG_CTRL				0xEE0C0304	// R/W	32	Register Enable/Clock Gating Control
#define	EHCI2_SPD_CTRL					0xEE0C0308	// R/W	32	Suspend Control
#define	EHCI2_SPD_RSM_TIMSET			0xEE0C030C	// R/W	32	Suspend/Resume Timer Setting
#define	EHCI2_OC_TIMSET					0xEE0C0310	// R/W	32	Overcurrent Detection Timer Setting
#define	EHCI2_SBRN_FLADJ_PW 			0xEE0C0314	// R/W	32	SBRN, FLADJ, PORTWAKECAP
#define	EHCI2_COMMCTRL					0xEE0C0800	// R/W	32	Common Control
#define	EHCI2_OBINTSTA					0xEE0C0804	// R/W	32	OTG-BC Interrupt Status
#define	EHCI2_OBINTEN					0xEE0C0808	// R/W	32	OTG-BC Interrupt Enable
#define	EHCI2_VBCTRL					0xEE0C080C	// R/W	32	VBUS Control
#define	EHCI2_LINECTRL1					0xEE0C0810	// R/W	32	Line Control Port1
#define	EHCI2_BCCTRL1					0xEE0C0820	// R/W	32	BC Control Port1
#define	EHCI2_ADPCTRL					0xEE0C0830	// R/W	32	ADP Control



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


//HDMI0
#define	HDMI0_DESIGN_ID					0xFEAD0000	// R	8	Design Identification Register
#define	HDMI0_REVISION_ID 				0xFEAD0001	// R	8	Revision Identification Register
#define	HDMI0_PRODUCT_ID0 				0xFEAD0002	// R	8	Product Identification Register 0
#define	HDMI0_PRODUCT_ID1 				0xFEAD0003	// R	8	Product Identification Register 1
#define	HDMI0_CONFIG0_ID 				0xFEAD0004	// R	8	Configuration Identification Register 0
#define	HDMI0_CONFIG1_ID 				0xFEAD0005	// R	8	Configuration Identification Register 1
#define	HDMI0_CONFIG2_ID 				0xFEAD0006	// R	8	Configuration Identification Register 2
#define	HDMI0_CONFIG3_ID 				0xFEAD0007	// R	8	Configuration Identification Register 3
#define	HDMI0_IH_FC_STAT0 				0xFEAD0100	// R/W1C	8	Frame Composer Interrupt Status Register 0
#define	HDMI0_IH_FC_STAT1 				0xFEAD0101	// R/W1C	8	Frame Composer Interrupt Status Register 1
#define	HDMI0_IH_FC_STAT2 				0xFEAD0102	// R/W1C	8	Frame Composer Interrupt Status Register 2
#define	HDMI0_IH_AS_STAT0 				0xFEAD0103	// R/W1C	8	Audio Sampler Interrupt Status Register
#define	HDMI0_IH_PHY_STAT0 				0xFEAD0104	// R/W1C	8	PHY Interface Interrupt Status Register
#define	HDMI0_IH_I2CM_STAT0 			0xFEAD0105	// R/W1C	8	E-DDC I2C Master Interrupt Status Register
#define	HDMI0_IH_CEC_STAT0 				0xFEAD0106	// R/W1C	8	CEC Interrupt Status Register
#define	HDMI0_IH_VP_STAT0 				0xFEAD0107	// R/W1C	8	Video Packetizer Interrupt Status Register
#define	HDMI0_IH_I2CMPHY_STAT0 			0xFEAD0108	// R/W1C	8	PHY GEN2 I2C Master Interrupt Status Register
#define	HDMI0_IH_AHBDMAAUD_STAT0 		0xFEAD0109	// R	8	AHB Audio DMA Interrupt Status Register
#define	HDMI0_IH_DECODE 				0xFEAD0170	// R	8	Interruption Handler Decode Assist Register
#define	HDMI0_IH_MUTE_FC_STAT0 			0xFEAD0180	// R/W	8	Frame Composer Interrupt Mute Control Register 0
#define	HDMI0_IH_MUTE_FC_STAT1 			0xFEAD0181	// R/W	8	Frame Composer Interrupt Mute Control Register 1
#define	HDMI0_IH_MUTE_FC_STAT2 			0xFEAD0182	// R/W	8	Frame Composer Interrupt Mute Control Register 2
#define	HDMI0_IH_MUTE_AS_STAT0 			0xFEAD0183	// R/W	8	Audio Sampler Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_PHY_STAT0 		0xFEAD0184	// R/W	8	PHY Interface Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_I2CM_STAT0 		0xFEAD0185	// R/W	8	E-DDC I2C Master Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_CEC_STAT0 		0xFEAD0186	// R/W	8	CEC Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_VP_STAT0 			0xFEAD0187	// R/W	8	Video Packetizer Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_I2CMPHY_STAT0 	0xFEAD0188	// R/W	8	PHY GEN2 I2C Master Interrupt Mute Control Register
#define	HDMI0_IH_MUTE_AHBDMAAUD_STAT0 	0xFEAD0189	// R	8	AHB Audio DMA Interrupt Mute Control Register
#define	HDMI0_IH_MUTE 					0xFEAD01FF	// R/W	8	Global Interrupt Mute Control Register
#define	HDMI0_TX_INVID0 				0xFEAD0200	// R/W	8	Video Input Mapping and Internal Data Enable Configuration Register
#define	HDMI0_TX_INSTUFFING 			0xFEAD0201	// R/W	8	Video Input Stuffing Enable Register
#define	HDMI0_TX_GYDATA0 				0xFEAD0202	// R/W	8	Video Input gy Data Channel Stuffing Register 0
#define	HDMI0_TX_GYDATA1 				0xFEAD0203	// R/W	8	Video Input gy Data Channel Stuffing Register 1
#define	HDMI0_TX_RCRDATA0 				0xFEAD0204	// R/W	8	Video Input rcr Data Channel Stuffing Register 0
#define	HDMI0_TX_RCRDATA1 				0xFEAD0205	// R/W	8	Video Input rcr Data Channel Stuffing Register 1
#define	HDMI0_TX_BCBDATA0 				0xFEAD0206	// R/W	8	Video Input bcb Data Channel Stuffing Register 0
#define	HDMI0_TX_BCBDATA1 				0xFEAD0207	// R/W	8	Video Input bcb Data Channel Stuffing Register 1
#define	HDMI0_VP_STATUS 				0xFEAD0800	// R	8	Video Packetizer Packing Phase Status Register
#define	HDMI0_VP_PR_CD 					0xFEAD0801	// R/W	8	Video Packetizer Pixel Repetition and Color Depth Register
#define	HDMI0_VP_STUFF 					0xFEAD0802	// R/W	8	Video Packetizer Stuffing and Default Packing Phase Register
#define	HDMI0_VP_REMAP 					0xFEAD0803	// R/W	8	Video Packetizer YCC422 Remapping Register
#define	HDMI0_VP_CONF 					0xFEAD0804	// R/W	8	Video Packetizer Output, Bypass and Enable Configuration Register
#define	HDMI0_VP_MASK 					0xFEAD0807	// R/W	8	Video Packetizer Interrupt Mask Register
#define	HDMI0_FC_INVIDCONF 				0xFEAD1000	// R/W	8	Frame Composer Input Video Configuration and HDCP Keepout Register
#define	HDMI0_FC_INHACTIV0 				0xFEAD1001	// R/W	8	Frame Composer Input Video HActive Pixels Register 0
#define	HDMI0_FC_INHACTIV1 				0xFEAD1002	// R/W	8	Frame Composer Input Video HActive Pixels Register 1
#define	HDMI0_FC_INHBLANK0 				0xFEAD1003	// R/W	8	Frame Composer Input Video HBlank Pixels Register 0
#define	HDMI0_FC_INHBLANK1 				0xFEAD1004	// R/W	8	Frame Composer Input Video HBlank Pixels Register 1
#define	HDMI0_FC_INVACTIV0 				0xFEAD1005	// R/W	8	Frame Composer Input Video VActive Pixels Register 0
#define	HDMI0_FC_INVACTIV1 				0xFEAD1006	// R/W	8	Frame Composer Input Video VActive Pixels Register 1
#define	HDMI0_FC_INVBLANK 				0xFEAD1007	// R/W	8	Frame Composer Input Video VBlank Pixels Register
#define	HDMI0_FC_HSYNCINDELAY0 			0xFEAD1008	// R/W	8	Frame Composer Input Video HSync Front Porch Register 0
#define	HDMI0_FC_HSYNCINDELAY1 			0xFEAD1009	// R/W	8	Frame Composer Input Video HSync Front Porch Register 1
#define	HDMI0_FC_HSYNCINWIDTH0 			0xFEAD100A	// R/W	8	Frame Composer Input Video HSync Width Register 0
#define	HDMI0_FC_HSYNCINWIDTH1 			0xFEAD100B	// R/W	8	Frame Composer Input Video HSync Width Register 1
#define	HDMI0_FC_VSYNCINDELAY 			0xFEAD100C	// R/W	8	Frame Composer Input Video VSync Front Porch Register
#define	HDMI0_FC_VSYNCINWIDTH 			0xFEAD100D	// R/W	8	Frame Composer Input Video VSync Width Register
#define	HDMI0_FC_INFREQ0 				0xFEAD100E	// R/W	8	Frame Composer Input Video Refresh Rate Register 0
#define	HDMI0_FC_INFREQ1 				0xFEAD100F	// R/W	8	Frame Composer Input Video Refresh Rate Register 1
#define	HDMI0_FC_INFREQ2 				0xFEAD1010	// R/W	8	Frame Composer Input Video Refresh Rate Register 2
#define	HDMI0_FC_CTRLDUR 				0xFEAD1011	// R/W	8	Frame Composer Control Period Duration Register
#define	HDMI0_FC_EXCTRLDUR 				0xFEAD1012	// R/W	8	Frame Composer Extended Control Period Duration Register
#define	HDMI0_FC_EXCTRLSPAC 			0xFEAD1013	// R/W	8	Frame Composer Extended Control Period Maximum Spacing Register
#define	HDMI0_FC_CH0PREAM 				0xFEAD1014	// R/W	8	Frame Composer Channel 0 Non-Preamble Data Register
#define	HDMI0_FC_CH1PREAM 				0xFEAD1015	// R/W	8	Frame Composer Channel 1 Non-Preamble Data Register
#define	HDMI0_FC_CH2PREAM 				0xFEAD1016	// R/W	8	Frame Composer Channel 2 Non-Preamble Data Register
#define	HDMI0_FC_AVICONF3 				0xFEAD1017	// R/W	8	Frame Composer AVI Packet Configuration Register 3
#define	HDMI0_FC_GCP 					0xFEAD1018	// R/W	8	Frame Composer GCP Packet Configuration Register
#define	HDMI0_FC_AVICONF0 				0xFEAD1019	// R/W	8	Frame Composer AVI Packet Configuration Register 0
#define	HDMI0_FC_AVICONF1 				0xFEAD101A	// R/W	8	Frame Composer AVI Packet Configuration Register 1
#define	HDMI0_FC_AVICONF2 				0xFEAD101B	// R/W	8	Frame Composer AVI Packet Configuration Register 2
#define	HDMI0_FC_AVIVID 				0xFEAD101C	// R/W	8	Frame Composer AVI Packet VIC Register
#define	HDMI0_FC_AVIETB0				0xFEAD101D	// R/W	8	Frame Composer AVI Packet End of Top Bar Register Array
#define	HDMI0_FC_AVIETB1				0xFEAD101E	// R/W	8	
#define	HDMI0_FC_AVISBB0				0xFEAD101F	// R/W	8	Frame Composer AVI Packet Start of Bottom Bar Register Array
#define	HDMI0_FC_AVISBB1				0xFEAD1020	// R/W	8	
#define	HDMI0_FC_AVIELB0				0xFEAD1021	// R/W	8	Frame Composer AVI Packet End of Left Bar Register Array
#define	HDMI0_FC_AVIELB1				0xFEAD1022	// R/W	8	
#define	HDMI0_FC_AVISRB0				0xFEAD1023	// R/W	8	Frame Composer AVI Packet Start of Right Bar Register Array
#define	HDMI0_FC_AVISRB1				0xFEAD1024	// R/W	8	
#define	HDMI0_FC_AUDICONF0 				0xFEAD1025	// R/W	8	Frame Composer AUD Packet Configuration Register 0
#define	HDMI0_FC_AUDICONF1 				0xFEAD1026	// R/W	8	Frame Composer AUD Packet Configuration Register 1
#define	HDMI0_FC_AUDICONF2 				0xFEAD1027	// R/W	8	Frame Composer AUD Packet Configuration Register 2
#define	HDMI0_FC_AUDICONF3 				0xFEAD1028	// R/W	8	Frame Composer AUD Packet Configuration Register 0
#define	HDMI0_FC_VSDIEEEID2 			0xFEAD1029	// R/W	8	Frame Composer VSI Packet Data IEEE Register 2
#define	HDMI0_FC_VSDSIZE 				0xFEAD102A	// R/W	8	Frame Composer VSI Packet Data Size Register
#define	HDMI0_FC_VSDIEEEID1 			0xFEAD1030	// R/W	8	Frame Composer VSI Packet Data IEEE Register 1
#define	HDMI0_FC_VSDIEEEID0 			0xFEAD1031	// R/W	8	Frame Composer VSI Packet Data IEEE Register 0
#define	HDMI0_FC_VSDPAYLOAD0			0xFEAD1032	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD1			0xFEAD1033	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD2			0xFEAD1034	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD3			0xFEAD1035	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD4			0xFEAD1036	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD5			0xFEAD1037	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD6			0xFEAD1038	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD7			0xFEAD1039	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD8			0xFEAD103A	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD9			0xFEAD103B	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD10			0xFEAD103C	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD11			0xFEAD103D	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD12			0xFEAD103E	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD13			0xFEAD103F	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD14			0xFEAD1040	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD15			0xFEAD1041	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD16			0xFEAD1042	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD17			0xFEAD1043	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD18			0xFEAD1044	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD19			0xFEAD1045	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD20			0xFEAD1046	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD21			0xFEAD1047	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD22			0xFEAD1048	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_VSDPAYLOAD23			0xFEAD1049	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI0_FC_SPDVENDORNAME0			0xFEAD104A	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME1			0xFEAD104B	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME2			0xFEAD104C	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME3			0xFEAD104D	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME4			0xFEAD104E	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME5			0xFEAD104F	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME6			0xFEAD1050	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDVENDORNAME7			0xFEAD1051	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME0		0xFEAD1052	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME1		0xFEAD1053	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME2		0xFEAD1054	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME3		0xFEAD1055	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME4		0xFEAD1056	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME5		0xFEAD1057	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME6		0xFEAD1058	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME7		0xFEAD1059	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME8		0xFEAD105A	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME9		0xFEAD105B	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME10		0xFEAD105C	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME11		0xFEAD105D	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME12		0xFEAD105E	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME13		0xFEAD105F	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME14		0xFEAD1060	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDPRODUCTNAME15		0xFEAD1061	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI0_FC_SPDDEVICEINF 			0xFEAD1062	// R/W	8	Frame Composer SPD Packet Data Source Product Descriptor Register
#define	HDMI0_FC_AUDSCONF 				0xFEAD1063	// R/W	8	Frame Composer Audio Sample Flat and Layout Configuration Register
#define	HDMI0_FC_AUDSSTAT 				0xFEAD1064	// R/W	8	Frame Composer Audio Sample Flat and Layout Configuration Register
#define	HDMI0_FC_AUDSV 					0xFEAD1065	// R	8	Frame Composer Audio Sample Validity Flag Register
#define	HDMI0_FC_AUDSU 					0xFEAD1066	// R/W	8	Frame Composer Audio Sample User Flag Register
#define	HDMI0_FC_AUDSCHNL0 				0xFEAD1067	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 0
#define	HDMI0_FC_AUDSCHNL1 				0xFEAD1068	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 1
#define	HDMI0_FC_AUDSCHNL2 				0xFEAD1069	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 2
#define	HDMI0_FC_AUDSCHNL3 				0xFEAD106A	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 3
#define	HDMI0_FC_AUDSCHNL4 				0xFEAD106B	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 4
#define	HDMI0_FC_AUDSCHNL5 				0xFEAD106C	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 5
#define	HDMI0_FC_AUDSCHNL6 				0xFEAD106D	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 6
#define	HDMI0_FC_AUDSCHNL7 				0xFEAD106E	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 7
#define	HDMI0_FC_AUDSCHNL8 				0xFEAD106F	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 8
#define	HDMI0_FC_CTRLQHIGH 				0xFEAD1073	// R/W	8	Frame Composer Number of High Priority Packets Attended Configuration Register
#define	HDMI0_FC_CTRLQLOW 				0xFEAD1074	// R/W	8	Frame Composer Number of Low Priority Packets Attended Configuration Register
#define	HDMI0_FC_ACP0 					0xFEAD1075	// R/W	8	Frame Composer ACP Packet Type Configuration Register 0
#define	HDMI0_FC_ACP16 					0xFEAD1082	// R/W	8	Frame Composer ACP Packet Body Configuration Register 16
#define	HDMI0_FC_ACP15 					0xFEAD1083	// R/W	8	Frame Composer ACP Packet Body Configuration Register 15
#define	HDMI0_FC_ACP14 					0xFEAD1084	// R/W	8	Frame Composer ACP Packet Body Configuration Register 14
#define	HDMI0_FC_ACP13 					0xFEAD1085	// R/W	8	Frame Composer ACP Packet Body Configuration Register 13
#define	HDMI0_FC_ACP12 					0xFEAD1086	// R/W	8	Frame Composer ACP Packet Body Configuration Register 12
#define	HDMI0_FC_ACP11 					0xFEAD1087	// R/W	8	Frame Composer ACP Packet Body Configuration Register 11
#define	HDMI0_FC_ACP10 					0xFEAD1088	// R/W	8	Frame Composer ACP Packet Body Configuration Register 10
#define	HDMI0_FC_ACP9 					0xFEAD1089	// R/W	8	Frame Composer ACP Packet Body Configuration Register 9
#define	HDMI0_FC_ACP8 					0xFEAD108A	// R/W	8	Frame Composer ACP Packet Body Configuration Register 8
#define	HDMI0_FC_ACP7 					0xFEAD108B	// R/W	8	Frame Composer ACP Packet Body Configuration Register 7
#define	HDMI0_FC_ACP6 					0xFEAD108C	// R/W	8	Frame Composer ACP Packet Body Configuration Register 6
#define	HDMI0_FC_ACP5 					0xFEAD108D	// R/W	8	Frame Composer ACP Packet Body Configuration Register 5
#define	HDMI0_FC_ACP4 					0xFEAD108E	// R/W	8	Frame Composer ACP Packet Body Configuration Register 4
#define	HDMI0_FC_ACP3 					0xFEAD108F	// R/W	8	Frame Composer ACP Packet Body Configuration Register 3
#define	HDMI0_FC_ACP2 					0xFEAD1090	// R/W	8	Frame Composer ACP Packet Body Configuration Register 2
#define	HDMI0_FC_ACP1 					0xFEAD1091	// R/W	8	Frame Composer ACP Packet Body Configuration Register 1
#define	HDMI0_FC_ISCR1_0 				0xFEAD1092	// R/W	8	Frame Composer ISRC1 Packet Status, Valid, and Continue Configuration Register
#define	HDMI0_FC_ISCR1_16 				0xFEAD1093	// R/W	8	Frame Composer ISRC1 Packet Body Register 16
#define	HDMI0_FC_ISCR1_15 				0xFEAD1094	// R/W	8	Frame Composer ISRC1 Packet Body Register 15
#define	HDMI0_FC_ISCR1_14 				0xFEAD1095	// R/W	8	Frame Composer ISRC1 Packet Body Register 14
#define	HDMI0_FC_ISCR1_13 				0xFEAD1096	// R/W	8	Frame Composer ISRC1 Packet Body Register 13
#define	HDMI0_FC_ISCR1_12 				0xFEAD1097	// R/W	8	Frame Composer ISRC1 Packet Body Register 12
#define	HDMI0_FC_ISCR1_11 				0xFEAD1098	// R/W	8	Frame Composer ISRC1 Packet Body Register 11
#define	HDMI0_FC_ISCR1_10 				0xFEAD1099	// R/W	8	Frame Composer ISRC1 Packet Body Register 10
#define	HDMI0_FC_ISCR1_9 				0xFEAD109A	// R/W	8	Frame Composer ISRC1 Packet Body Register 9
#define	HDMI0_FC_ISCR1_8 				0xFEAD109B	// R/W	8	Frame Composer ISRC1 Packet Body Register 8
#define	HDMI0_FC_ISCR1_7 				0xFEAD109C	// R/W	8	Frame Composer ISRC1 Packet Body Register 7
#define	HDMI0_FC_ISCR1_6 				0xFEAD109D	// R/W	8	Frame Composer ISRC1 Packet Body Register 6
#define	HDMI0_FC_ISCR1_5 				0xFEAD109E	// R/W	8	Frame Composer ISRC1 Packet Body Register 5
#define	HDMI0_FC_ISCR1_4 				0xFEAD109F	// R/W	8	Frame Composer ISRC1 Packet Body Register 4
#define	HDMI0_FC_ISCR1_3 				0xFEAD10A0	// R/W	8	Frame Composer ISRC1 Packet Body Register 3
#define	HDMI0_FC_ISCR1_2 				0xFEAD10A1	// R/W	8	Frame Composer ISRC1 Packet Body Register 2
#define	HDMI0_FC_ISCR1_1 				0xFEAD10A2	// R/W	8	Frame Composer ISRC1 Packet Body Register 1
#define	HDMI0_FC_ISCR2_15 				0xFEAD10A3	// R/W	8	Frame Composer ISRC2 Packet Body Register 15
#define	HDMI0_FC_ISCR2_14 				0xFEAD10A4	// R/W	8	Frame Composer ISRC2 Packet Body Register 14
#define	HDMI0_FC_ISCR2_13 				0xFEAD10A5	// R/W	8	Frame Composer ISRC2 Packet Body Register 13
#define	HDMI0_FC_ISCR2_12 				0xFEAD10A6	// R/W	8	Frame Composer ISRC2 Packet Body Register 12
#define	HDMI0_FC_ISCR2_11 				0xFEAD10A7	// R/W	8	Frame Composer ISRC2 Packet Body Register 11
#define	HDMI0_FC_ISCR2_10 				0xFEAD10A8	// R/W	8	Frame Composer ISRC2 Packet Body Register 10
#define	HDMI0_FC_ISCR2_9 				0xFEAD10A9	// R/W	8	Frame Composer ISRC2 Packet Body Register 9
#define	HDMI0_FC_ISCR2_8 				0xFEAD10AA	// R/W	8	Frame Composer ISRC2 Packet Body Register 8
#define	HDMI0_FC_ISCR2_7 				0xFEAD10AB	// R/W	8	Frame Composer ISRC2 Packet Body Register 7
#define	HDMI0_FC_ISCR2_6 				0xFEAD10AC	// R/W	8	Frame Composer ISRC2 Packet Body Register 6
#define	HDMI0_FC_ISCR2_5 				0xFEAD10AD	// R/W	8	Frame Composer ISRC2 Packet Body Register 5
#define	HDMI0_FC_ISCR2_4 				0xFEAD10AE	// R/W	8	Frame Composer ISRC2 Packet Body Register 4
#define	HDMI0_FC_ISCR2_3 				0xFEAD10AF	// R/W	8	Frame Composer ISRC2 Packet Body Register 3
#define	HDMI0_FC_ISCR2_2 				0xFEAD10B0	// R/W	8	Frame Composer ISRC2 Packet Body Register 2
#define	HDMI0_FC_ISCR2_1 				0xFEAD10B1	// R/W	8	Frame Composer ISRC2 Packet Body Register 1
#define	HDMI0_FC_ISCR2_0 				0xFEAD10B2	// R/W	8	Frame Composer ISRC2 Packet Body Register 0
#define	HDMI0_FC_DATAUTO0 				0xFEAD10B3	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 0 Configures the Frame Composer RDRB(1)/Manual(0)...
#define	HDMI0_FC_DATAUTO1 				0xFEAD10B4	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 1 Configures the Frame Composer (FC)...
#define	HDMI0_FC_DATAUTO2 				0xFEAD10B5	// R/W	8	Frame Composer Data Island Auto packet scheduling Register 2 Configures the Frame Composer (FC)...
#define	HDMI0_FC_DATMAN 				0xFEAD10B6	// R/W	8	Frame Composer Data Island Manual Packet Request Register Requests to the Frame Composer the data...
#define	HDMI0_FC_DATAUTO3 				0xFEAD10B7	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 3 Configures the Frame Composer Automatic(1)/RDRB(0)...
#define	HDMI0_FC_RDRB0 					0xFEAD10B8	// R/W	8	Frame Composer Round Robin ACR Packet Insertion Register 0 ...
#define	HDMI0_FC_RDRB1 					0xFEAD10B9	// R/W	8	Frame Composer Round Robin ACR Packet Insertion Register 1 ...
#define	HDMI0_FC_RDRB2 					0xFEAD10BA	// R/W	8	Frame Composer Round Robin AUDI Packet Insertion Register 2 ...
#define	HDMI0_FC_RDRB3 					0xFEAD10BB	// R/W	8	Frame Composer Round Robin AUDI Packet Insertion Register 3 ...
#define	HDMI0_FC_RDRB4 					0xFEAD10BC	// R/W	8	Frame Composer Round Robin GCP Packet Insertion Register 4 ...
#define	HDMI0_FC_RDRB5 					0xFEAD10BD	// R/W	8	Frame Composer Round Robin GCP Packet Insertion Register 5 ...
#define	HDMI0_FC_RDRB6 					0xFEAD10BE	// R/W	8	Frame Composer Round Robin AVI Packet Insertion Register 6 ...
#define	HDMI0_FC_RDRB7 					0xFEAD10BF	// R/W	8	Frame Composer Round Robin AVI Packet Insertion Register 7 Configures
#define	HDMI0_FC_RDRB8 					0xFEAD10C0	// R/W	8	Frame Composer Round Robin AMP Packet Insertion Register 8
#define	HDMI0_FC_RDRB9 					0xFEAD10C1	// R/W	8	Frame Composer Round Robin AMP Packet Insertion Register 9
#define	HDMI0_FC_RDRB10 				0xFEAD10C2	// R/W	8	Frame Composer Round Robin NTSC VBI Packet Insertion Register 10
#define	HDMI0_FC_RDRB11 				0xFEAD10C3	// R/W	8	Frame Composer Round Robin NTSC VBI Packet Insertion Register 11
#define	HDMI0_FC_MASK0 					0xFEAD10D2	// R/W	8	Frame Composer Packet Interrupt Mask Register 0
#define	HDMI0_FC_MASK1 					0xFEAD10D6	// R/W	8	Frame Composer Packet Interrupt Mask Register 1
#define	HDMI0_FC_MASK2 					0xFEAD10DA	// R/W	8	Frame Composer High/Low Priority Overflow Interrupt Mask Register 2
#define	HDMI0_FC_PRCONF 				0xFEAD10E0	// R/W	8	Frame Composer Pixel Repetition Configuration Register
#define	HDMI0_FC_SCRAMBLER_CTRL 		0xFEAD10E1	// R/W	8	Frame Composer Scrambler Control
#define	HDMI0_FC_MULTISTREAM_CTRL 		0xFEAD10E2	// R/W	8	Frame Composer Multi-Stream Audio Control
#define	HDMI0_FC_PACKET_TX_EN 			0xFEAD10E3	// R/W	8	Frame Composer Packet Transmission Control
#define	HDMI0_FC_ACTSPC_HDLR_CFG 		0xFEAD10E8	// R/W	8	Frame Composer Active Space Control
#define	HDMI0_FC_INVACT_2D_0 			0xFEAD10E9	// R/W	8	Frame Composer Input Video 2D VActive Pixels Register 0
#define	HDMI0_FC_INVACT_2D_1 			0xFEAD10EA	// R/W	8	Frame Composer Input Video VActive pixels Register 1
#define	HDMI0_PHY_CONF0 				0xFEAD3000	// R/W	8	PHY Configuration Register This register holds the power down, data enable ...
#define	HDMI0_PHY_TST0 					0xFEAD3001	// R/W	8	PHY Test Interface Register 0 PHY TX mapped test interface (control). For more information, refer...
#define	HDMI0_PHY_TST1 					0xFEAD3002	// R/W	8	PHY Test Interface Register 1 PHY TX mapped text interface (data in). For more information, refer...
#define	HDMI0_PHY_TST2 					0xFEAD3003	// R/W	8	PHY Test Interface Register 2 PHY TX mapped text interface (data out). For more information, refer...
#define	HDMI0_PHY_STAT0 				0xFEAD3004	// R	8	PHY RXSENSE, PLL Lock, and HPD Status Register This register contains the following active high...
#define	HDMI0_PHY_INT0 					0xFEAD3005	// R	8	PHY RXSENSE, PLL Lock, and HPD Interrupt Register This register contains the interrupt indication...
#define	HDMI0_PHY_MASK0 				0xFEAD3006	// R/W	8	PHY RXSENSE, PLL Lock, and HPD Mask Register Mask register for generation of PHY_INT0...
#define	HDMI0_PHY_POL0 					0xFEAD3007	// R/W	8	PHY RXSENSE, PLL Lock, and HPD Polarity Register Polarity register for generation of PHY_INT0...
#define	HDMI0_PHY_PCLFREQ0 				0xFEAD3008	// R	8	PHY Test Interface Register 0
#define	HDMI0_PHY_PCLFREQ1 				0xFEAD3009	// R	8	PHY Test Interface Register 1
#define	HDMI0_PHY_PLLCFGFREQ0 			0xFEAD300A	// R	8	PHY Test Interface Register 0
#define	HDMI0_PHY_PLLCFGFREQ1 			0xFEAD300B	// R	8	PHY Test Interface Register 1
#define	HDMI0_PHY_PLLCFGFREQ2 			0xFEAD300C	// R	8	PHY Test Interface Register 2
#define	HDMI0_PHY_I2CM_SLAVE 			0xFEAD3020	// R/W	8	PHY I2C Slave Address Configuration Register
#define	HDMI0_PHY_I2CM_ADDRESS 			0xFEAD3021	// R/W	8	PHY I2C Address Configuration Register This register writes the address for read and write...
#define	HDMI0_PHY_I2CM_DATAO_1 			0xFEAD3022	// R/W	8	PHY I2C Data Write Register
#define	HDMI0_PHY_I2CM_DATAO_0 			0xFEAD3023	// R/W	8	PHY I2C Data Write Register
#define	HDMI0_PHY_I2CM_DATAI_1 			0xFEAD3024	// R	8	PHY I2C Data Read Register...
#define	HDMI0_PHY_I2CM_DATAI_0 			0xFEAD3025	// R	8	PHY I2C Data Read Register
#define	HDMI0_PHY_I2CM_OPERATION 		0xFEAD3026	// W	8	PHY I2C RD/RD_EXT/WR Operation Register This register requests read and write operations from the...
#define	HDMI0_PHY_I2CM_INT 				0xFEAD3027	// R/W	8	PHY I2C Done Interrupt Register This register contains and configures I2C master PHY done...
#define	HDMI0_PHY_I2CM_CTLINT 			0xFEAD3028	// R/W	8	PHY I2C error Interrupt Register This register contains and configures I2C master PHY error...
#define	HDMI0_PHY_I2CM_DIV 				0xFEAD3029	// R/W	8	PHY I2C Speed control Register This register wets the I2C Master PHY to work in either Fast or...
#define	HDMI0_PHY_I2CM_SOFTRSTZ 		0xFEAD302A	// R/W	8	PHY I2C SW reset control register This register sets the I2C Master PHY software reset.
#define	HDMI0_PHY_I2CM_SDA_HOLD 		0xFEAD3033	// R/W	8	PHY I2C Fast Speed SCL Low Level Control Register 0
#define	HDMI0_AUD_CONF0 				0xFEAD3100	// R/W	8	Audio I2S Software FIFO Reset, Select, and Enable Control Register 0 This register configures the...
#define	HDMI0_AUD_CONF1 				0xFEAD3101	// R/W	8	Audio I2S Width and Mode Configuration Register 1 This register configures the I2S mode and data...
#define	HDMI0_AUD_INT 					0xFEAD3102	// R/W	8	I2S FIFO status and interrupts. This register configures the I2S FIFO status and interrupts.
#define	HDMI0_AUD_CONF2 				0xFEAD3103	// R/W	8	Audio I2S NLPCM and HBR configuration Register 2 This register configures the I2S Audio Data mapping...
#define	HDMI0_AUD_INT1 					0xFEAD3104	// R/W	8	I2S Mask Interrupt Register This register masks the interrupts present in the I2S module.
#define	HDMI0_AUD_N1 					0xFEAD3200	// R/W	8	Audio Clock Regenerator N Value Register 1 For N expected values, refer to the HDMI0 1.4b...
#define	HDMI0_AUD_N2 					0xFEAD3201	// R/W	8	Audio Clock Regenerator N Value Register 2 For N expected values, refer to the HDMI0 1.4b...
#define	HDMI0_AUD_N3 					0xFEAD3202	// R/W	8	Audio Clock Regenerator N Value Register 3 For N expected values, refer to the HDMI0 1.4b...
#define	HDMI0_AUD_CTS1 					0xFEAD3203	// R/W	8	Audio Clock Regenerator CTS Value Register 1 For CTS expected values, to the HDMI0 1.4b...
#define	HDMI0_AUD_CTS2 					0xFEAD3204	// R/W	8	Audio Clock Regenerator CTS Register 2. For CTS expected values, refer to the HDMI0 1.4b...
#define	HDMI0_AUD_CTS3 					0xFEAD3205	// R/W	8	Audio Clock Regenerator CTS value Register 3. For CTS expected values, to the HDMI0 1.4b...
#define	HDMI0_AUD_INPUTCLKFS 			0xFEAD3206	// R/W	8	Audio Input Clock FS Factor Register
#define	HDMI0_MC_CLKDIS 				0xFEAD4001	// R/W	8	Main Controller Synchronous Clock Domain Disable Register
#define	HDMI0_MC_SWRSTZREQ 				0xFEAD4002	// R/W	8	Main Controller Software Reset Register Main controller software reset request per clock domain...
#define	HDMI0_MC_OPCTRL 				0xFEAD4003	// R/W	8	Main Controller HDCP Bypass Control Register
#define	HDMI0_MC_FLOWCTRL 				0xFEAD4004	// R/W	8	Main Controller Feed Through Control Register
#define	HDMI0_MC_PHYRSTZ 				0xFEAD4005	// R/W	8	Main Controller PHY Reset Register
#define	HDMI0_MC_LOCKONCLOCK 			0xFEAD4006	// R/W1C	8	Main Controller Clock Present Register
#define	HDMI0_MC_HEACPHY_RST 			0xFEAD4007	// R/W	8	Main Controller HEAC PHY Reset Register
#define	HDMI0_MC_LOCKONCLOCK_2 			0xFEAD4009	// R/W1C	8	Main Controller Clock Present Register 2
#define	HDMI0_MC_SWRSTZREQ_2 			0xFEAD400A	// R	8	Main Controller Software Reset Register 2 Main controller software reset request per clock domain...
#define	HDMI0_I2CM_SLAVE 				0xFEAD7E00	// R/W	8	I2C DDC Slave address Configuration Register
#define	HDMI0_I2CM_ADDRESS 				0xFEAD7E01	// R/W	8	I2C DDC Address Configuration Register
#define	HDMI0_I2CM_DATAO 				0xFEAD7E02	// R/W	8	I2C DDC Data Write Register
#define	HDMI0_I2CM_DATAI 				0xFEAD7E03	// R	8	I2C DDC Data read Register
#define	HDMI0_I2CM_OPERATION 			0xFEAD7E04	// W	8	I2C DDC RD/RD_EXT/WR Operation Register Read and write operation request. This register can only...
#define	HDMI0_I2CM_INT 					0xFEAD7E05	// R/W	8	I2C DDC Done Interrupt Register This register configures the I2C master interrupts.
#define	HDMI0_I2CM_CTLINT 				0xFEAD7E06	// R/W	8	I2C DDC error Interrupt Register This register configures the I2C master arbitration lost and not...
#define	HDMI0_I2CM_DIV 					0xFEAD7E07	// R/W	8	I2C DDC Speed Control Register This register configures the division relation between master and...
#define	HDMI0_I2CM_SEGADDR 				0xFEAD7E08	// R/W	8	I2C DDC Segment Address Configuration Register This register configures the segment address for...
#define	HDMI0_I2CM_SOFTRSTZ 			0xFEAD7E09	// R/W	8	I2C DDC Software Reset Control Register This register resets the I2C master...
#define	HDMI0_I2CM_SEGPTR 				0xFEAD7E0A	// R/W	8	I2C DDC Segment Pointer Register This register configures the segment pointer for extended RD/WR...


//HDMI1
#define	HDMI1_DESIGN_ID					0xFEAE0000	// R	8	Design Identification Register
#define	HDMI1_REVISION_ID 				0xFEAE0001	// R	8	Revision Identification Register
#define	HDMI1_PRODUCT_ID0 				0xFEAE0002	// R	8	Product Identification Register 0
#define	HDMI1_PRODUCT_ID1 				0xFEAE0003	// R	8	Product Identification Register 1
#define	HDMI1_CONFIG0_ID 				0xFEAE0004	// R	8	Configuration Identification Register 0
#define	HDMI1_CONFIG1_ID 				0xFEAE0005	// R	8	Configuration Identification Register 1
#define	HDMI1_CONFIG2_ID 				0xFEAE0006	// R	8	Configuration Identification Register 2
#define	HDMI1_CONFIG3_ID 				0xFEAE0007	// R	8	Configuration Identification Register 3
#define	HDMI1_IH_FC_STAT0 				0xFEAE0100	// R/W1C	8	Frame Composer Interrupt Status Register 0
#define	HDMI1_IH_FC_STAT1 				0xFEAE0101	// R/W1C	8	Frame Composer Interrupt Status Register 1
#define	HDMI1_IH_FC_STAT2 				0xFEAE0102	// R/W1C	8	Frame Composer Interrupt Status Register 2
#define	HDMI1_IH_AS_STAT0 				0xFEAE0103	// R/W1C	8	Audio Sampler Interrupt Status Register
#define	HDMI1_IH_PHY_STAT0 				0xFEAE0104	// R/W1C	8	PHY Interface Interrupt Status Register
#define	HDMI1_IH_I2CM_STAT0 			0xFEAE0105	// R/W1C	8	E-DDC I2C Master Interrupt Status Register
#define	HDMI1_IH_CEC_STAT0 				0xFEAE0106	// R/W1C	8	CEC Interrupt Status Register
#define	HDMI1_IH_VP_STAT0 				0xFEAE0107	// R/W1C	8	Video Packetizer Interrupt Status Register
#define	HDMI1_IH_I2CMPHY_STAT0 			0xFEAE0108	// R/W1C	8	PHY GEN2 I2C Master Interrupt Status Register
#define	HDMI1_IH_AHBDMAAUD_STAT0 		0xFEAE0109	// R	8	AHB Audio DMA Interrupt Status Register
#define	HDMI1_IH_DECODE 				0xFEAE0170	// R	8	Interruption Handler Decode Assist Register
#define	HDMI1_IH_MUTE_FC_STAT0 			0xFEAE0180	// R/W	8	Frame Composer Interrupt Mute Control Register 0
#define	HDMI1_IH_MUTE_FC_STAT1 			0xFEAE0181	// R/W	8	Frame Composer Interrupt Mute Control Register 1
#define	HDMI1_IH_MUTE_FC_STAT2 			0xFEAE0182	// R/W	8	Frame Composer Interrupt Mute Control Register 2
#define	HDMI1_IH_MUTE_AS_STAT0 			0xFEAE0183	// R/W	8	Audio Sampler Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_PHY_STAT0 		0xFEAE0184	// R/W	8	PHY Interface Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_I2CM_STAT0 		0xFEAE0185	// R/W	8	E-DDC I2C Master Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_CEC_STAT0 		0xFEAE0186	// R/W	8	CEC Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_VP_STAT0 			0xFEAE0187	// R/W	8	Video Packetizer Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_I2CMPHY_STAT0 	0xFEAE0188	// R/W	8	PHY GEN2 I2C Master Interrupt Mute Control Register
#define	HDMI1_IH_MUTE_AHBDMAAUD_STAT0 	0xFEAE0189	// R	8	AHB Audio DMA Interrupt Mute Control Register
#define	HDMI1_IH_MUTE 					0xFEAE01FF	// R/W	8	Global Interrupt Mute Control Register
#define	HDMI1_TX_INVID0 				0xFEAE0200	// R/W	8	Video Input Mapping and Internal Data Enable Configuration Register
#define	HDMI1_TX_INSTUFFING 			0xFEAE0201	// R/W	8	Video Input Stuffing Enable Register
#define	HDMI1_TX_GYDATA0 				0xFEAE0202	// R/W	8	Video Input gy Data Channel Stuffing Register 0
#define	HDMI1_TX_GYDATA1 				0xFEAE0203	// R/W	8	Video Input gy Data Channel Stuffing Register 1
#define	HDMI1_TX_RCRDATA0 				0xFEAE0204	// R/W	8	Video Input rcr Data Channel Stuffing Register 0
#define	HDMI1_TX_RCRDATA1 				0xFEAE0205	// R/W	8	Video Input rcr Data Channel Stuffing Register 1
#define	HDMI1_TX_BCBDATA0 				0xFEAE0206	// R/W	8	Video Input bcb Data Channel Stuffing Register 0
#define	HDMI1_TX_BCBDATA1 				0xFEAE0207	// R/W	8	Video Input bcb Data Channel Stuffing Register 1
#define	HDMI1_VP_STATUS 				0xFEAE0800	// R	8	Video Packetizer Packing Phase Status Register
#define	HDMI1_VP_PR_CD 					0xFEAE0801	// R/W	8	Video Packetizer Pixel Repetition and Color Depth Register
#define	HDMI1_VP_STUFF 					0xFEAE0802	// R/W	8	Video Packetizer Stuffing and Default Packing Phase Register
#define	HDMI1_VP_REMAP 					0xFEAE0803	// R/W	8	Video Packetizer YCC422 Remapping Register
#define	HDMI1_VP_CONF 					0xFEAE0804	// R/W	8	Video Packetizer Output, Bypass and Enable Configuration Register
#define	HDMI1_VP_MASK 					0xFEAE0807	// R/W	8	Video Packetizer Interrupt Mask Register
#define	HDMI1_FC_INVIDCONF 				0xFEAE1000	// R/W	8	Frame Composer Input Video Configuration and HDCP Keepout Register
#define	HDMI1_FC_INHACTIV0 				0xFEAE1001	// R/W	8	Frame Composer Input Video HActive Pixels Register 0
#define	HDMI1_FC_INHACTIV1 				0xFEAE1002	// R/W	8	Frame Composer Input Video HActive Pixels Register 1
#define	HDMI1_FC_INHBLANK0 				0xFEAE1003	// R/W	8	Frame Composer Input Video HBlank Pixels Register 0
#define	HDMI1_FC_INHBLANK1 				0xFEAE1004	// R/W	8	Frame Composer Input Video HBlank Pixels Register 1
#define	HDMI1_FC_INVACTIV0 				0xFEAE1005	// R/W	8	Frame Composer Input Video VActive Pixels Register 0
#define	HDMI1_FC_INVACTIV1 				0xFEAE1006	// R/W	8	Frame Composer Input Video VActive Pixels Register 1
#define	HDMI1_FC_INVBLANK 				0xFEAE1007	// R/W	8	Frame Composer Input Video VBlank Pixels Register
#define	HDMI1_FC_HSYNCINDELAY0 			0xFEAE1008	// R/W	8	Frame Composer Input Video HSync Front Porch Register 0
#define	HDMI1_FC_HSYNCINDELAY1 			0xFEAE1009	// R/W	8	Frame Composer Input Video HSync Front Porch Register 1
#define	HDMI1_FC_HSYNCINWIDTH0 			0xFEAE100A	// R/W	8	Frame Composer Input Video HSync Width Register 0
#define	HDMI1_FC_HSYNCINWIDTH1 			0xFEAE100B	// R/W	8	Frame Composer Input Video HSync Width Register 1
#define	HDMI1_FC_VSYNCINDELAY 			0xFEAE100C	// R/W	8	Frame Composer Input Video VSync Front Porch Register
#define	HDMI1_FC_VSYNCINWIDTH 			0xFEAE100D	// R/W	8	Frame Composer Input Video VSync Width Register
#define	HDMI1_FC_INFREQ0 				0xFEAE100E	// R/W	8	Frame Composer Input Video Refresh Rate Register 0
#define	HDMI1_FC_INFREQ1 				0xFEAE100F	// R/W	8	Frame Composer Input Video Refresh Rate Register 1
#define	HDMI1_FC_INFREQ2 				0xFEAE1010	// R/W	8	Frame Composer Input Video Refresh Rate Register 2
#define	HDMI1_FC_CTRLDUR 				0xFEAE1011	// R/W	8	Frame Composer Control Period Duration Register
#define	HDMI1_FC_EXCTRLDUR 				0xFEAE1012	// R/W	8	Frame Composer Extended Control Period Duration Register
#define	HDMI1_FC_EXCTRLSPAC 			0xFEAE1013	// R/W	8	Frame Composer Extended Control Period Maximum Spacing Register
#define	HDMI1_FC_CH0PREAM 				0xFEAE1014	// R/W	8	Frame Composer Channel 0 Non-Preamble Data Register
#define	HDMI1_FC_CH1PREAM 				0xFEAE1015	// R/W	8	Frame Composer Channel 1 Non-Preamble Data Register
#define	HDMI1_FC_CH2PREAM 				0xFEAE1016	// R/W	8	Frame Composer Channel 2 Non-Preamble Data Register
#define	HDMI1_FC_AVICONF3 				0xFEAE1017	// R/W	8	Frame Composer AVI Packet Configuration Register 3
#define	HDMI1_FC_GCP 					0xFEAE1018	// R/W	8	Frame Composer GCP Packet Configuration Register
#define	HDMI1_FC_AVICONF0 				0xFEAE1019	// R/W	8	Frame Composer AVI Packet Configuration Register 0
#define	HDMI1_FC_AVICONF1 				0xFEAE101A	// R/W	8	Frame Composer AVI Packet Configuration Register 1
#define	HDMI1_FC_AVICONF2 				0xFEAE101B	// R/W	8	Frame Composer AVI Packet Configuration Register 2
#define	HDMI1_FC_AVIVID 				0xFEAE101C	// R/W	8	Frame Composer AVI Packet VIC Register
#define	HDMI1_FC_AVIETB0				0xFEAE101D	// R/W	8	Frame Composer AVI Packet End of Top Bar Register Array
#define	HDMI1_FC_AVIETB1				0xFEAE101E	// R/W	8	
#define	HDMI1_FC_AVISBB0				0xFEAE101F	// R/W	8	Frame Composer AVI Packet Start of Bottom Bar Register Array
#define	HDMI1_FC_AVISBB1				0xFEAE1020	// R/W	8	
#define	HDMI1_FC_AVIELB0				0xFEAE1021	// R/W	8	Frame Composer AVI Packet End of Left Bar Register Array
#define	HDMI1_FC_AVIELB1				0xFEAE1022	// R/W	8	
#define	HDMI1_FC_AVISRB0				0xFEAE1023	// R/W	8	Frame Composer AVI Packet Start of Right Bar Register Array
#define	HDMI1_FC_AVISRB1				0xFEAE1024	// R/W	8	
#define	HDMI1_FC_AUDICONF0 				0xFEAE1025	// R/W	8	Frame Composer AUD Packet Configuration Register 0
#define	HDMI1_FC_AUDICONF1 				0xFEAE1026	// R/W	8	Frame Composer AUD Packet Configuration Register 1
#define	HDMI1_FC_AUDICONF2 				0xFEAE1027	// R/W	8	Frame Composer AUD Packet Configuration Register 2
#define	HDMI1_FC_AUDICONF3 				0xFEAE1028	// R/W	8	Frame Composer AUD Packet Configuration Register 0
#define	HDMI1_FC_VSDIEEEID2 			0xFEAE1029	// R/W	8	Frame Composer VSI Packet Data IEEE Register 2
#define	HDMI1_FC_VSDSIZE 				0xFEAE102A	// R/W	8	Frame Composer VSI Packet Data Size Register
#define	HDMI1_FC_VSDIEEEID1 			0xFEAE1030	// R/W	8	Frame Composer VSI Packet Data IEEE Register 1
#define	HDMI1_FC_VSDIEEEID0 			0xFEAE1031	// R/W	8	Frame Composer VSI Packet Data IEEE Register 0
#define	HDMI1_FC_VSDPAYLOAD0			0xFEAE1032	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD1			0xFEAE1033	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD2			0xFEAE1034	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD3			0xFEAE1035	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD4			0xFEAE1036	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD5			0xFEAE1037	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD6			0xFEAE1038	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD7			0xFEAE1039	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD8			0xFEAE103A	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD9			0xFEAE103B	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD10			0xFEAE103C	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD11			0xFEAE103D	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD12			0xFEAE103E	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD13			0xFEAE103F	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD14			0xFEAE1040	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD15			0xFEAE1041	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD16			0xFEAE1042	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD17			0xFEAE1043	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD18			0xFEAE1044	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD19			0xFEAE1045	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD20			0xFEAE1046	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD21			0xFEAE1047	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD22			0xFEAE1048	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_VSDPAYLOAD23			0xFEAE1049	// R/W	8	Frame Composer VSI Packet Data Payload Register Array
#define	HDMI1_FC_SPDVENDORNAME0			0xFEAE104A	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME1			0xFEAE104B	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME2			0xFEAE104C	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME3			0xFEAE104D	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME4			0xFEAE104E	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME5			0xFEAE104F	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME6			0xFEAE1050	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDVENDORNAME7			0xFEAE1051	// R/W	8	Frame Composer SPD Packet Data Vendor Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME0		0xFEAE1052	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME1		0xFEAE1053	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME2		0xFEAE1054	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME3		0xFEAE1055	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME4		0xFEAE1056	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME5		0xFEAE1057	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME6		0xFEAE1058	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME7		0xFEAE1059	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME8		0xFEAE105A	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME9		0xFEAE105B	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME10		0xFEAE105C	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME11		0xFEAE105D	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME12		0xFEAE105E	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME13		0xFEAE105F	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME14		0xFEAE1060	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDPRODUCTNAME15		0xFEAE1061	// R/W	8	Frame Composer SPD packet Data Product Name Register Array
#define	HDMI1_FC_SPDDEVICEINF 			0xFEAE1062	// R/W	8	Frame Composer SPD Packet Data Source Product Descriptor Register
#define	HDMI1_FC_AUDSCONF 				0xFEAE1063	// R/W	8	Frame Composer Audio Sample Flat and Layout Configuration Register
#define	HDMI1_FC_AUDSSTAT 				0xFEAE1064	// R/W	8	Frame Composer Audio Sample Flat and Layout Configuration Register
#define	HDMI1_FC_AUDSV 					0xFEAE1065	// R	8	Frame Composer Audio Sample Validity Flag Register
#define	HDMI1_FC_AUDSU 					0xFEAE1066	// R/W	8	Frame Composer Audio Sample User Flag Register
#define	HDMI1_FC_AUDSCHNL0 				0xFEAE1067	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 0
#define	HDMI1_FC_AUDSCHNL1 				0xFEAE1068	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 1
#define	HDMI1_FC_AUDSCHNL2 				0xFEAE1069	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 2
#define	HDMI1_FC_AUDSCHNL3 				0xFEAE106A	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 3
#define	HDMI1_FC_AUDSCHNL4 				0xFEAE106B	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 4
#define	HDMI1_FC_AUDSCHNL5 				0xFEAE106C	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 5
#define	HDMI1_FC_AUDSCHNL6 				0xFEAE106D	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 6
#define	HDMI1_FC_AUDSCHNL7 				0xFEAE106E	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 7
#define	HDMI1_FC_AUDSCHNL8 				0xFEAE106F	// R/W	8	Frame Composer Audio Sample Channel Status Configuration Register 8
#define	HDMI1_FC_CTRLQHIGH 				0xFEAE1073	// R/W	8	Frame Composer Number of High Priority Packets Attended Configuration Register
#define	HDMI1_FC_CTRLQLOW 				0xFEAE1074	// R/W	8	Frame Composer Number of Low Priority Packets Attended Configuration Register
#define	HDMI1_FC_ACP0 					0xFEAE1075	// R/W	8	Frame Composer ACP Packet Type Configuration Register 0
#define	HDMI1_FC_ACP16 					0xFEAE1082	// R/W	8	Frame Composer ACP Packet Body Configuration Register 16
#define	HDMI1_FC_ACP15 					0xFEAE1083	// R/W	8	Frame Composer ACP Packet Body Configuration Register 15
#define	HDMI1_FC_ACP14 					0xFEAE1084	// R/W	8	Frame Composer ACP Packet Body Configuration Register 14
#define	HDMI1_FC_ACP13 					0xFEAE1085	// R/W	8	Frame Composer ACP Packet Body Configuration Register 13
#define	HDMI1_FC_ACP12 					0xFEAE1086	// R/W	8	Frame Composer ACP Packet Body Configuration Register 12
#define	HDMI1_FC_ACP11 					0xFEAE1087	// R/W	8	Frame Composer ACP Packet Body Configuration Register 11
#define	HDMI1_FC_ACP10 					0xFEAE1088	// R/W	8	Frame Composer ACP Packet Body Configuration Register 10
#define	HDMI1_FC_ACP9 					0xFEAE1089	// R/W	8	Frame Composer ACP Packet Body Configuration Register 9
#define	HDMI1_FC_ACP8 					0xFEAE108A	// R/W	8	Frame Composer ACP Packet Body Configuration Register 8
#define	HDMI1_FC_ACP7 					0xFEAE108B	// R/W	8	Frame Composer ACP Packet Body Configuration Register 7
#define	HDMI1_FC_ACP6 					0xFEAE108C	// R/W	8	Frame Composer ACP Packet Body Configuration Register 6
#define	HDMI1_FC_ACP5 					0xFEAE108D	// R/W	8	Frame Composer ACP Packet Body Configuration Register 5
#define	HDMI1_FC_ACP4 					0xFEAE108E	// R/W	8	Frame Composer ACP Packet Body Configuration Register 4
#define	HDMI1_FC_ACP3 					0xFEAE108F	// R/W	8	Frame Composer ACP Packet Body Configuration Register 3
#define	HDMI1_FC_ACP2 					0xFEAE1090	// R/W	8	Frame Composer ACP Packet Body Configuration Register 2
#define	HDMI1_FC_ACP1 					0xFEAE1091	// R/W	8	Frame Composer ACP Packet Body Configuration Register 1
#define	HDMI1_FC_ISCR1_0 				0xFEAE1092	// R/W	8	Frame Composer ISRC1 Packet Status, Valid, and Continue Configuration Register
#define	HDMI1_FC_ISCR1_16 				0xFEAE1093	// R/W	8	Frame Composer ISRC1 Packet Body Register 16
#define	HDMI1_FC_ISCR1_15 				0xFEAE1094	// R/W	8	Frame Composer ISRC1 Packet Body Register 15
#define	HDMI1_FC_ISCR1_14 				0xFEAE1095	// R/W	8	Frame Composer ISRC1 Packet Body Register 14
#define	HDMI1_FC_ISCR1_13 				0xFEAE1096	// R/W	8	Frame Composer ISRC1 Packet Body Register 13
#define	HDMI1_FC_ISCR1_12 				0xFEAE1097	// R/W	8	Frame Composer ISRC1 Packet Body Register 12
#define	HDMI1_FC_ISCR1_11 				0xFEAE1098	// R/W	8	Frame Composer ISRC1 Packet Body Register 11
#define	HDMI1_FC_ISCR1_10 				0xFEAE1099	// R/W	8	Frame Composer ISRC1 Packet Body Register 10
#define	HDMI1_FC_ISCR1_9 				0xFEAE109A	// R/W	8	Frame Composer ISRC1 Packet Body Register 9
#define	HDMI1_FC_ISCR1_8 				0xFEAE109B	// R/W	8	Frame Composer ISRC1 Packet Body Register 8
#define	HDMI1_FC_ISCR1_7 				0xFEAE109C	// R/W	8	Frame Composer ISRC1 Packet Body Register 7
#define	HDMI1_FC_ISCR1_6 				0xFEAE109D	// R/W	8	Frame Composer ISRC1 Packet Body Register 6
#define	HDMI1_FC_ISCR1_5 				0xFEAE109E	// R/W	8	Frame Composer ISRC1 Packet Body Register 5
#define	HDMI1_FC_ISCR1_4 				0xFEAE109F	// R/W	8	Frame Composer ISRC1 Packet Body Register 4
#define	HDMI1_FC_ISCR1_3 				0xFEAE10A0	// R/W	8	Frame Composer ISRC1 Packet Body Register 3
#define	HDMI1_FC_ISCR1_2 				0xFEAE10A1	// R/W	8	Frame Composer ISRC1 Packet Body Register 2
#define	HDMI1_FC_ISCR1_1 				0xFEAE10A2	// R/W	8	Frame Composer ISRC1 Packet Body Register 1
#define	HDMI1_FC_ISCR2_15 				0xFEAE10A3	// R/W	8	Frame Composer ISRC2 Packet Body Register 15
#define	HDMI1_FC_ISCR2_14 				0xFEAE10A4	// R/W	8	Frame Composer ISRC2 Packet Body Register 14
#define	HDMI1_FC_ISCR2_13 				0xFEAE10A5	// R/W	8	Frame Composer ISRC2 Packet Body Register 13
#define	HDMI1_FC_ISCR2_12 				0xFEAE10A6	// R/W	8	Frame Composer ISRC2 Packet Body Register 12
#define	HDMI1_FC_ISCR2_11 				0xFEAE10A7	// R/W	8	Frame Composer ISRC2 Packet Body Register 11
#define	HDMI1_FC_ISCR2_10 				0xFEAE10A8	// R/W	8	Frame Composer ISRC2 Packet Body Register 10
#define	HDMI1_FC_ISCR2_9 				0xFEAE10A9	// R/W	8	Frame Composer ISRC2 Packet Body Register 9
#define	HDMI1_FC_ISCR2_8 				0xFEAE10AA	// R/W	8	Frame Composer ISRC2 Packet Body Register 8
#define	HDMI1_FC_ISCR2_7 				0xFEAE10AB	// R/W	8	Frame Composer ISRC2 Packet Body Register 7
#define	HDMI1_FC_ISCR2_6 				0xFEAE10AC	// R/W	8	Frame Composer ISRC2 Packet Body Register 6
#define	HDMI1_FC_ISCR2_5 				0xFEAE10AD	// R/W	8	Frame Composer ISRC2 Packet Body Register 5
#define	HDMI1_FC_ISCR2_4 				0xFEAE10AE	// R/W	8	Frame Composer ISRC2 Packet Body Register 4
#define	HDMI1_FC_ISCR2_3 				0xFEAE10AF	// R/W	8	Frame Composer ISRC2 Packet Body Register 3
#define	HDMI1_FC_ISCR2_2 				0xFEAE10B0	// R/W	8	Frame Composer ISRC2 Packet Body Register 2
#define	HDMI1_FC_ISCR2_1 				0xFEAE10B1	// R/W	8	Frame Composer ISRC2 Packet Body Register 1
#define	HDMI1_FC_ISCR2_0 				0xFEAE10B2	// R/W	8	Frame Composer ISRC2 Packet Body Register 0
#define	HDMI1_FC_DATAUTO0 				0xFEAE10B3	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 0 Configures the Frame Composer RDRB(1)/Manual(0)...
#define	HDMI1_FC_DATAUTO1 				0xFEAE10B4	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 1 Configures the Frame Composer (FC)...
#define	HDMI1_FC_DATAUTO2 				0xFEAE10B5	// R/W	8	Frame Composer Data Island Auto packet scheduling Register 2 Configures the Frame Composer (FC)...
#define	HDMI1_FC_DATMAN 				0xFEAE10B6	// R/W	8	Frame Composer Data Island Manual Packet Request Register Requests to the Frame Composer the data...
#define	HDMI1_FC_DATAUTO3 				0xFEAE10B7	// R/W	8	Frame Composer Data Island Auto Packet Scheduling Register 3 Configures the Frame Composer Automatic(1)/RDRB(0)...
#define	HDMI1_FC_RDRB0 					0xFEAE10B8	// R/W	8	Frame Composer Round Robin ACR Packet Insertion Register 0 ...
#define	HDMI1_FC_RDRB1 					0xFEAE10B9	// R/W	8	Frame Composer Round Robin ACR Packet Insertion Register 1 ...
#define	HDMI1_FC_RDRB2 					0xFEAE10BA	// R/W	8	Frame Composer Round Robin AUDI Packet Insertion Register 2 ...
#define	HDMI1_FC_RDRB3 					0xFEAE10BB	// R/W	8	Frame Composer Round Robin AUDI Packet Insertion Register 3 ...
#define	HDMI1_FC_RDRB4 					0xFEAE10BC	// R/W	8	Frame Composer Round Robin GCP Packet Insertion Register 4 ...
#define	HDMI1_FC_RDRB5 					0xFEAE10BD	// R/W	8	Frame Composer Round Robin GCP Packet Insertion Register 5 ...
#define	HDMI1_FC_RDRB6 					0xFEAE10BE	// R/W	8	Frame Composer Round Robin AVI Packet Insertion Register 6 ...
#define	HDMI1_FC_RDRB7 					0xFEAE10BF	// R/W	8	Frame Composer Round Robin AVI Packet Insertion Register 7 Configures
#define	HDMI1_FC_RDRB8 					0xFEAE10C0	// R/W	8	Frame Composer Round Robin AMP Packet Insertion Register 8
#define	HDMI1_FC_RDRB9 					0xFEAE10C1	// R/W	8	Frame Composer Round Robin AMP Packet Insertion Register 9
#define	HDMI1_FC_RDRB10 				0xFEAE10C2	// R/W	8	Frame Composer Round Robin NTSC VBI Packet Insertion Register 10
#define	HDMI1_FC_RDRB11 				0xFEAE10C3	// R/W	8	Frame Composer Round Robin NTSC VBI Packet Insertion Register 11
#define	HDMI1_FC_MASK0 					0xFEAE10D2	// R/W	8	Frame Composer Packet Interrupt Mask Register 0
#define	HDMI1_FC_MASK1 					0xFEAE10D6	// R/W	8	Frame Composer Packet Interrupt Mask Register 1
#define	HDMI1_FC_MASK2 					0xFEAE10DA	// R/W	8	Frame Composer High/Low Priority Overflow Interrupt Mask Register 2
#define	HDMI1_FC_PRCONF 				0xFEAE10E0	// R/W	8	Frame Composer Pixel Repetition Configuration Register
#define	HDMI1_FC_SCRAMBLER_CTRL 		0xFEAE10E1	// R/W	8	Frame Composer Scrambler Control
#define	HDMI1_FC_MULTISTREAM_CTRL 		0xFEAE10E2	// R/W	8	Frame Composer Multi-Stream Audio Control
#define	HDMI1_FC_PACKET_TX_EN 			0xFEAE10E3	// R/W	8	Frame Composer Packet Transmission Control
#define	HDMI1_FC_ACTSPC_HDLR_CFG 		0xFEAE10E8	// R/W	8	Frame Composer Active Space Control
#define	HDMI1_FC_INVACT_2D_0 			0xFEAE10E9	// R/W	8	Frame Composer Input Video 2D VActive Pixels Register 0
#define	HDMI1_FC_INVACT_2D_1 			0xFEAE10EA	// R/W	8	Frame Composer Input Video VActive pixels Register 1
#define	HDMI1_PHY_CONF0 				0xFEAE3000	// R/W	8	PHY Configuration Register This register holds the power down, data enable ...
#define	HDMI1_PHY_TST0 					0xFEAE3001	// R/W	8	PHY Test Interface Register 0 PHY TX mapped test interface (control). For more information, refer...
#define	HDMI1_PHY_TST1 					0xFEAE3002	// R/W	8	PHY Test Interface Register 1 PHY TX mapped text interface (data in). For more information, refer...
#define	HDMI1_PHY_TST2 					0xFEAE3003	// R/W	8	PHY Test Interface Register 2 PHY TX mapped text interface (data out). For more information, refer...
#define	HDMI1_PHY_STAT0 				0xFEAE3004	// R	8	PHY RXSENSE, PLL Lock, and HPD Status Register This register contains the following active high...
#define	HDMI1_PHY_INT0 					0xFEAE3005	// R	8	PHY RXSENSE, PLL Lock, and HPD Interrupt Register This register contains the interrupt indication...
#define	HDMI1_PHY_MASK0 				0xFEAE3006	// R/W	8	PHY RXSENSE, PLL Lock, and HPD Mask Register Mask register for generation of PHY_INT0...
#define	HDMI1_PHY_POL0 					0xFEAE3007	// R/W	8	PHY RXSENSE, PLL Lock, and HPD Polarity Register Polarity register for generation of PHY_INT0...
#define	HDMI1_PHY_PCLFREQ0 				0xFEAE3008	// R	8	PHY Test Interface Register 0
#define	HDMI1_PHY_PCLFREQ1 				0xFEAE3009	// R	8	PHY Test Interface Register 1
#define	HDMI1_PHY_PLLCFGFREQ0 			0xFEAE300A	// R	8	PHY Test Interface Register 0
#define	HDMI1_PHY_PLLCFGFREQ1 			0xFEAE300B	// R	8	PHY Test Interface Register 1
#define	HDMI1_PHY_PLLCFGFREQ2 			0xFEAE300C	// R	8	PHY Test Interface Register 2
#define	HDMI1_PHY_I2CM_SLAVE 			0xFEAE3020	// R/W	8	PHY I2C Slave Address Configuration Register
#define	HDMI1_PHY_I2CM_ADDRESS 			0xFEAE3021	// R/W	8	PHY I2C Address Configuration Register This register writes the address for read and write...
#define	HDMI1_PHY_I2CM_DATAO_1 			0xFEAE3022	// R/W	8	PHY I2C Data Write Register
#define	HDMI1_PHY_I2CM_DATAO_0 			0xFEAE3023	// R/W	8	PHY I2C Data Write Register
#define	HDMI1_PHY_I2CM_DATAI_1 			0xFEAE3024	// R	8	PHY I2C Data Read Register...
#define	HDMI1_PHY_I2CM_DATAI_0 			0xFEAE3025	// R	8	PHY I2C Data Read Register
#define	HDMI1_PHY_I2CM_OPERATION 		0xFEAE3026	// W	8	PHY I2C RD/RD_EXT/WR Operation Register This register requests read and write operations from the...
#define	HDMI1_PHY_I2CM_INT 				0xFEAE3027	// R/W	8	PHY I2C Done Interrupt Register This register contains and configures I2C master PHY done...
#define	HDMI1_PHY_I2CM_CTLINT 			0xFEAE3028	// R/W	8	PHY I2C error Interrupt Register This register contains and configures I2C master PHY error...
#define	HDMI1_PHY_I2CM_DIV 				0xFEAE3029	// R/W	8	PHY I2C Speed control Register This register wets the I2C Master PHY to work in either Fast or...
#define	HDMI1_PHY_I2CM_SOFTRSTZ 		0xFEAE302A	// R/W	8	PHY I2C SW reset control register This register sets the I2C Master PHY software reset.
#define	HDMI1_PHY_I2CM_SDA_HOLD 		0xFEAE3033	// R/W	8	PHY I2C Fast Speed SCL Low Level Control Register 0
#define	HDMI1_AUD_CONF0 				0xFEAE3100	// R/W	8	Audio I2S Software FIFO Reset, Select, and Enable Control Register 0 This register configures the...
#define	HDMI1_AUD_CONF1 				0xFEAE3101	// R/W	8	Audio I2S Width and Mode Configuration Register 1 This register configures the I2S mode and data...
#define	HDMI1_AUD_INT 					0xFEAE3102	// R/W	8	I2S FIFO status and interrupts. This register configures the I2S FIFO status and interrupts.
#define	HDMI1_AUD_CONF2 				0xFEAE3103	// R/W	8	Audio I2S NLPCM and HBR configuration Register 2 This register configures the I2S Audio Data mapping...
#define	HDMI1_AUD_INT1 					0xFEAE3104	// R/W	8	I2S Mask Interrupt Register This register masks the interrupts present in the I2S module.
#define	HDMI1_AUD_N1 					0xFEAE3200	// R/W	8	Audio Clock Regenerator N Value Register 1 For N expected values, refer to the HDMI1 1.4b...
#define	HDMI1_AUD_N2 					0xFEAE3201	// R/W	8	Audio Clock Regenerator N Value Register 2 For N expected values, refer to the HDMI1 1.4b...
#define	HDMI1_AUD_N3 					0xFEAE3202	// R/W	8	Audio Clock Regenerator N Value Register 3 For N expected values, refer to the HDMI1 1.4b...
#define	HDMI1_AUD_CTS1 					0xFEAE3203	// R/W	8	Audio Clock Regenerator CTS Value Register 1 For CTS expected values, to the HDMI1 1.4b...
#define	HDMI1_AUD_CTS2 					0xFEAE3204	// R/W	8	Audio Clock Regenerator CTS Register 2. For CTS expected values, refer to the HDMI1 1.4b...
#define	HDMI1_AUD_CTS3 					0xFEAE3205	// R/W	8	Audio Clock Regenerator CTS value Register 3. For CTS expected values, to the HDMI1 1.4b...
#define	HDMI1_AUD_INPUTCLKFS 			0xFEAE3206	// R/W	8	Audio Input Clock FS Factor Register
#define	HDMI1_MC_CLKDIS 				0xFEAE4001	// R/W	8	Main Controller Synchronous Clock Domain Disable Register
#define	HDMI1_MC_SWRSTZREQ 				0xFEAE4002	// R/W	8	Main Controller Software Reset Register Main controller software reset request per clock domain...
#define	HDMI1_MC_OPCTRL 				0xFEAE4003	// R/W	8	Main Controller HDCP Bypass Control Register
#define	HDMI1_MC_FLOWCTRL 				0xFEAE4004	// R/W	8	Main Controller Feed Through Control Register
#define	HDMI1_MC_PHYRSTZ 				0xFEAE4005	// R/W	8	Main Controller PHY Reset Register
#define	HDMI1_MC_LOCKONCLOCK 			0xFEAE4006	// R/W1C	8	Main Controller Clock Present Register
#define	HDMI1_MC_HEACPHY_RST 			0xFEAE4007	// R/W	8	Main Controller HEAC PHY Reset Register
#define	HDMI1_MC_LOCKONCLOCK_2 			0xFEAE4009	// R/W1C	8	Main Controller Clock Present Register 2
#define	HDMI1_MC_SWRSTZREQ_2 			0xFEAE400A	// R	8	Main Controller Software Reset Register 2 Main controller software reset request per clock domain...
#define	HDMI1_I2CM_SLAVE 				0xFEAE7E00	// R/W	8	I2C DDC Slave address Configuration Register
#define	HDMI1_I2CM_ADDRESS 				0xFEAE7E01	// R/W	8	I2C DDC Address Configuration Register
#define	HDMI1_I2CM_DATAO 				0xFEAE7E02	// R/W	8	I2C DDC Data Write Register
#define	HDMI1_I2CM_DATAI 				0xFEAE7E03	// R	8	I2C DDC Data read Register
#define	HDMI1_I2CM_OPERATION 			0xFEAE7E04	// W	8	I2C DDC RD/RD_EXT/WR Operation Register Read and write operation request. This register can only...
#define	HDMI1_I2CM_INT 					0xFEAE7E05	// R/W	8	I2C DDC Done Interrupt Register This register configures the I2C master interrupts.
#define	HDMI1_I2CM_CTLINT 				0xFEAE7E06	// R/W	8	I2C DDC error Interrupt Register This register configures the I2C master arbitration lost and not...
#define	HDMI1_I2CM_DIV 					0xFEAE7E07	// R/W	8	I2C DDC Speed Control Register This register configures the division relation between master and...
#define	HDMI1_I2CM_SEGADDR 				0xFEAE7E08	// R/W	8	I2C DDC Segment Address Configuration Register This register configures the segment address for...
#define	HDMI1_I2CM_SOFTRSTZ 			0xFEAE7E09	// R/W	8	I2C DDC Software Reset Control Register This register resets the I2C master...
#define	HDMI1_I2CM_SEGPTR 				0xFEAE7E0A	// R/W	8	I2C DDC Segment Pointer Register This register configures the segment pointer for extended RD/WR...


//HSUSB
#define	HSUSB_SYSCFG					0xE6590000	// R/W	16	System configuration control register
#define	HSUSB_BUSWAIT					0xE6590002	// R/W	16	CPU bus wait register
#define	HSUSB_SYSSTS					0xE6590004	// R	16	System configuration status register
#define	HSUSB_DVSTCTR					0xE6590008	// R/W	16	Device state control register
#define	HSUSB_TESTMODE					0xE659000C	// R/W	16	Test mode register
#define	HSUSB_CFIFO						0xE6590014	// R/W	32	CFIFO port register
#define	HSUSB_CFIFOSEL					0xE6590020	// R/W	16	CFIFO port select register
#define	HSUSB_CFIFOCTR					0xE6590022	// R/W	16	CFIFO port control register
#define	HSUSB_D0FIFOSEL					0xE6590028	// R/W	16	D0FIFO port select register
#define	HSUSB_D0FIFOCTR					0xE659002A	// R/W	16	D0FIFO port control register
#define	HSUSB_D1FIFOSEL					0xE659002C	// R/W	16	D1FIFO port select register
#define	HSUSB_D1FIFOCTR					0xE659002E	// R/W	16	D1FIFO port control register
#define	HSUSB_INTENB0					0xE6590030	// R/W	16	Interrupt enable register 0
#define	HSUSB_BRDYENB					0xE6590036	// R/W	16	BRDY interrupt enable register
#define	HSUSB_NRDYENB					0xE6590038	// R/W	16	NRDY interrupt enable register
#define	HSUSB_BEMPENB					0xE659003A	// R/W	16	BEMP interrupt enable register
#define	HSUSB_SOFCFG					0xE659003C	// R/W	16	SOF output configuration register
#define	HSUSB_INTSTS0					0xE6590040	// R/W	16	Interrupt status register 0
#define	HSUSB_BRDYSTS					0xE6590046	// R/W	16	BRDY interrupt status register
#define	HSUSB_NRDYSTS					0xE6590048	// R/W	16	NRDY interrupt status register
#define	HSUSB_BEMPSTS					0xE659004A	// R/W	16	BEMP interrupt status register
#define	HSUSB_FRMNUM					0xE659004C	// R/W	16	Frame number register
#define	HSUSB_UFRMNUM					0xE659004E	// R/W	16	u frame number register
#define	HSUSB_USBADDR					0xE6590050	// R	16	USB address register
#define	HSUSB_USBREQ					0xE6590054	// R	16	USB request type register
#define	HSUSB_USBVAL					0xE6590056	// R	16	USB request value register
#define	HSUSB_USBINDX					0xE6590058	// R	16	USB request index register
#define	HSUSB_USBLENG					0xE659005A	// R	16	USB request length register
#define	HSUSB_DCPMAXP					0xE659005E	// R/W	16	DCP maximum packet size register
#define	HSUSB_DCPCTR					0xE6590060	// R/W	16	DCP control register
#define	HSUSB_PIPESEL					0xE6590064	// R/W	16	Pipe window select register
#define	HSUSB_PIPECFG					0xE6590068	// R/W	16	Pipe configuration register
#define	HSUSB_PIPEBUF					0xE659006A	// R/W	16	Pipe buffer register
#define	HSUSB_PIPEMAXP					0xE659006C	// R/W	16	Pipe maximum packet size register
#define	HSUSB_PIPEPERI					0xE659006E	// R/W	16	Pipe cycle control register
#define	HSUSB_PIPE1CTR					0xE6590070	// R/W	16	Pipe 1 control register
#define	HSUSB_PIPE2CTR					0xE6590072	// R/W	16	Pipe 2 control register
#define	HSUSB_PIPE3CTR					0xE6590074	// R/W	16	Pipe 3 control register
#define	HSUSB_PIPE4CTR					0xE6590076	// R/W	16	Pipe 4 control register
#define	HSUSB_PIPE5CTR					0xE6590078	// R/W	16	Pipe 5 control register
#define	HSUSB_PIPE6CTR					0xE659007A	// R/W	16	Pipe 6 control register
#define	HSUSB_PIPE7CTR					0xE659007C	// R/W	16	Pipe 7 control register
#define	HSUSB_PIPE8CTR					0xE659007E	// R/W	16	Pipe 8 control register
#define	HSUSB_PIPE9CTR					0xE6590080	// R/W	16	Pipe 9 control register
#define	HSUSB_PIPEACTR					0xE6590082	// R/W	16	Pipe A control register
#define	HSUSB_PIPEBCTR					0xE6590084	// R/W	16	Pipe B control register
#define	HSUSB_PIPECCTR					0xE6590086	// R/W	16	Pipe C control register
#define	HSUSB_PIPEDCTR					0xE6590088	// R/W	16	Pipe D control register
#define	HSUSB_PIPEECTR					0xE659008A	// R/W	16	Pipe E control register
#define	HSUSB_PIPEFCTR					0xE659008C	// R/W	16	Pipe F control register
#define	HSUSB_PIPE1TRE					0xE6590090	// R/W	16	Pipe 1 transaction counter enable register
#define	HSUSB_PIPE1TRN					0xE6590092	// R/W	16	Pipe 1 transaction counter register
#define	HSUSB_PIPE2TRE					0xE6590094	// R/W	16	Pipe 2 transaction counter enable register
#define	HSUSB_PIPE2TRN					0xE6590096	// R/W	16	Pipe 2 transaction counter register
#define	HSUSB_PIPE3TRE					0xE6590098	// R/W	16	Pipe 3 transaction counter enable register
#define	HSUSB_PIPE3TRN					0xE659009A	// R/W	16	Pipe 3 transaction counter register
#define	HSUSB_PIPE4TRE					0xE659009C	// R/W	16	Pipe 4 transaction counter enable register
#define	HSUSB_PIPE4TRN					0xE659009E	// R/W	16	Pipe 4 transaction counter register
#define	HSUSB_PIPE5TRE					0xE65900A0	// R/W	16	Pipe 5 transaction counter enable register
#define	HSUSB_PIPE5TRN					0xE65900A2	// R/W	16	Pipe 5 transaction counter register
#define	HSUSB_PIPEBTRE					0xE65900A4	// R/W	16	Pipe B transaction counter enable register
#define	HSUSB_PIPEBTRN					0xE65900A6	// R/W	16	Pipe B transaction counter register
#define	HSUSB_PIPECTRE					0xE65900A8	// R/W	16	Pipe C transaction counter enable register
#define	HSUSB_PIPECTRN					0xE65900AA	// R/W	16	Pipe C transaction counter register
#define	HSUSB_PIPEDTRE					0xE65900AC	// R/W	16	Pipe D transaction counter enable register
#define	HSUSB_PIPEDTRN					0xE65900AE	// R/W	16	Pipe D transaction counter register
#define	HSUSB_PIPEETRE					0xE65900B0	// R/W	16	Pipe E transaction counter enable register
#define	HSUSB_PIPEETRN					0xE65900B2	// R/W	16	Pipe E transaction counter register
#define	HSUSB_PIPEFTRE					0xE65900B4	// R/W	16	Pipe F transaction counter enable register
#define	HSUSB_PIPEFTRN					0xE65900B6	// R/W	16	Pipe F transaction counter register
#define	HSUSB_PIPE9TRE					0xE65900B8	// R/W	16	Pipe 9 transaction counter enable register
#define	HSUSB_PIPE9TRN					0xE65900BA	// R/W	16	Pipe 9 transaction counter register
#define	HSUSB_PIPEATRE					0xE65900BC	// R/W	16	Pipe A transaction counter enable register
#define	HSUSB_PIPEATRN					0xE65900BE	// R/W	16	Pipe A transaction counter register
#define	HSUSB_D2FIFOSEL					0xE65900F0	// R/W	16	D2FIFO port select register
#define	HSUSB_D2FIFOCTR					0xE65900F2	// R/W	16	D2FIFO port control register
#define	HSUSB_D3FIFOSEL					0xE65900F4	// R/W	16	D3FIFO port select register
#define	HSUSB_D3FIFOCTR					0xE65900F6	// R/W	16	D3FIFO port control register
#define	HSUSB_LPSTS						0xE6590102	// R/W	16	Low power status register
#define	HSUSB_BCCTRL					0xE6590140	// R/W	16	Battery charging control register
#define	HSUSB_UGCTRL2					0xE6590184	// R/W	32	USB general control register 2


//I2C2
#define	I2C2_ICSCR						0xE6510000	// R/W	32	Slave control register
#define	I2C2_ICMCR						0xE6510004	// R/W	32	Master control register
#define	I2C2_ICSSR						0xE6510008	// R/(W)*1	32	Slave status register
#define	I2C2_ICMSR						0xE651000C	// R/(W)*2	32	Master status register
#define	I2C2_ICSIER						0xE6510010	// R/W	32	Slave interrupt enable register
#define	I2C2_ICMIER						0xE6510014	// R/W	32	Master interrupt enable register
#define	I2C2_ICCCR						0xE6510018	// R/W	32	Clock control register
#define	I2C2_ICSAR						0xE651001C	// R/W	32	Slave address register
#define	I2C2_ICMAR						0xE6510020	// R/W	32	Master address register
#define	I2C2_ICRXD						0xE6510024	// R	32	Receive data register
#define	I2C2_ICTXD						0xE6510024	// W	32	Transmit data register
#define	I2C2_ICCCR2						0xE6510028	// R/W	32	Clock control register 2
#define	I2C2_ICMPR						0xE651002C	// R/W	32	SCL mask control register
#define	I2C2_ICHPR						0xE6510030	// R/W	32	SCL high control register
#define	I2C2_ICLPR						0xE6510034	// R/W	32	SCL low control register
#define	I2C2_ICDMAER					0xE651003C	// R/W	32	DMA enable register
#define	I2C2_ICFBSCR					0xE6510038	// R/W	32	First bit setup cycle register


//I2C4
#define	I2C4_ICSCR						0xE66D8000	// R/W	32	Slave control register
#define	I2C4_ICMCR						0xE66D8004	// R/W	32	Master control register
#define	I2C4_ICSSR						0xE66D8008	// R/(W)*1	32	Slave status register
#define	I2C4_ICMSR						0xE66D800C	// R/(W)*2	32	Master status register
#define	I2C4_ICSIER						0xE66D8010	// R/W	32	Slave interrupt enable register
#define	I2C4_ICMIER						0xE66D8014	// R/W	32	Master interrupt enable register
#define	I2C4_ICCCR						0xE66D8018	// R/W	32	Clock control register
#define	I2C4_ICSAR						0xE66D801C	// R/W	32	Slave address register
#define	I2C4_ICMAR						0xE66D8020	// R/W	32	Master address register
#define	I2C4_ICRXD						0xE66D8024	// R	32	Receive data register
#define	I2C4_ICTXD						0xE66D8024	// W	32	Transmit data register
#define	I2C4_ICCCR2						0xE66D8028	// R/W	32	Clock control register 2
#define	I2C4_ICMPR						0xE66D802C	// R/W	32	SCL mask control register
#define	I2C4_ICHPR						0xE66D8030	// R/W	32	SCL high control register
#define	I2C4_ICLPR						0xE66D8034	// R/W	32	SCL low control register
#define	I2C4_ICDMAER					0xE66D803C	// R/W	32	DMA enable register
#define	I2C4_ICFBSCR					0xE66D8038	// R/W	32	First bit setup cycle register


//IICDVFS
#define	IICDVFS_ICDR					0xE60B0000	// R/W	8	IIC bus data register
#define	IICDVFS_ICCR					0xE60B0004	// R/W	8	IIC bus control register
#define	IICDVFS_ICSR					0xE60B0008	// R/W	8	IIC bus status register
#define	IICDVFS_ICIC					0xE60B000C	// R/W	8	IIC interruption control register
#define	IICDVFS_ICCL					0xE60B0010	// R/W	8	IIC clock control register low
#define	IICDVFS_ICCH					0xE60B0014	// R/W	8	IIC clock control register high
#define	IICDVFS_ICTR					0xE60B0018	// R	8	IIC transmit register
#define	IICDVFS_ICRR					0xE60B001C	// R	8	IIC receive register
#define	IICDVFS_ICTA					0xE60B0020	// R	8	IIC transmit monitor register
#define	IICDVFS_ICTB					0xE60B0024	// R	8	IIC transmit buffer monitor register
#define	IICDVFS_ICTC					0xE60B0028	// R/W	8	IIC transmit control register
#define	IICDVFS_ICTD					0xE60B002C	// R	8	IIC transmit control status monitor register
#define	IICDVFS_ICSF					0xE60B0030	// R	8	IIC shift register
#define	IICDVFS_ICVCON					0xE60B006C	// R/W	8	IIC option enabling register
#define	IICDVFS_ICIMSK					0xE60B0050	// R/W	8	IIC automatic transmission interrupt mask register
#define	IICDVFS_ICINT					0xE60B0054	// R	8	IIC automatic transmission interrupt flag register
#define	IICDVFS_ICACE					0xE60B0058	// R/W	8	IIC automatic transmission processing enabling register
#define	IICDVFS_ICTMC1					0xE60B0060	// R/W	8	IIC automatic transmission timer control register 1
#define	IICDVFS_ICTMC2					0xE60B0064	// R/W	8	IIC automatic transmission timer control register 2
#define	IICDVFS_ICTMCW					0xE60B0068	// R/W	8	IIC automatic transmission wait control register
#define	IICDVFS_ICSTART					0xE60B0070	// R/W	8	IIC automatic transmission transmit start register
#define	IICDVFS_ICATFR					0xE60B0080	// R/W	8	IIC automatic transmission transmit control register
#define	IICDVFS_ICATSET1				0xE60B0084	// R/W	8	IIC automatic transmission transmit time register 1
#define	IICDVFS_ICATSET2				0xE60B0088	// R/W	8	IIC automatic transmission transmit time register 2
#define	IICDVFS_ICARSET1				0xE60B008C	// R/W	8	IIC automatic transmission reception time register 1
#define	IICDVFS_ICARSET2				0xE60B0090	// R/W	8	IIC automatic transmission reception time register 2
#define	IICDVFS_ICATD00					0xE60B0100	// R/W	8	IIC automatic transmission transmit data 00
#define	IICDVFS_ICATD01					0xE60B0104	// R/W	8	IIC automatic transmission transmit data 01
#define	IICDVFS_ICATD02					0xE60B0108	// R/W	8	IIC automatic transmission transmit data 02
#define	IICDVFS_ICATD03					0xE60B010C	// R/W	8	IIC automatic transmission transmit data 03
#define	IICDVFS_ICATD04					0xE60B0110	// R/W	8	IIC automatic transmission transmit data 04
#define	IICDVFS_ICATD05					0xE60B0114	// R/W	8	IIC automatic transmission transmit data 05
#define	IICDVFS_ICATD06					0xE60B0118	// R/W	8	IIC automatic transmission transmit data 06
#define	IICDVFS_ICATD07					0xE60B011C	// R/W	8	IIC automatic transmission transmit data 07
#define	IICDVFS_ICATD08					0xE60B0120	// R/W	8	IIC automatic transmission transmit data 08
#define	IICDVFS_ICATD09					0xE60B0124	// R/W	8	IIC automatic transmission transmit data 09
#define	IICDVFS_ICATD10					0xE60B0200	// R/W	8	IIC automatic transmission transmit data 10
#define	IICDVFS_ICATD11					0xE60B0204	// R/W	8	IIC automatic transmission transmit data 11
#define	IICDVFS_ICATD12					0xE60B0208	// R/W	8	IIC automatic transmission transmit data 12
#define	IICDVFS_ICATD13					0xE60B020C	// R/W	8	IIC automatic transmission transmit data 13
#define	IICDVFS_ICATD14					0xE60B0210	// R/W	8	IIC automatic transmission transmit data 14
#define	IICDVFS_ICATD15					0xE60B0214	// R/W	8	IIC automatic transmission transmit data 15
#define	IICDVFS_ICATD16					0xE60B0218	// R/W	8	IIC automatic transmission transmit data 16
#define	IICDVFS_ICATD17					0xE60B021C	// R/W	8	IIC automatic transmission transmit data 17
#define	IICDVFS_ICATD18					0xE60B0220	// R/W	8	IIC automatic transmission transmit data 18
#define	IICDVFS_ICATD19					0xE60B0224	// R/W	8	IIC automatic transmission transmit data 19
#define	IICDVFS_ICARD00					0xE60B0300	// R	8	IIC automatic transmission receipt data 00
#define	IICDVFS_ICARD01					0xE60B0304	// R	8	IIC automatic transmission receipt data 01
#define	IICDVFS_ICARD02					0xE60B0308	// R	8	IIC automatic transmission receipt data 02
#define	IICDVFS_ICARD03					0xE60B030C	// R	8	IIC automatic transmission receipt data 03
#define	IICDVFS_ICARD04					0xE60B0310	// R	8	IIC automatic transmission receipt data 04
#define	IICDVFS_ICARD05					0xE60B0314	// R	8	IIC automatic transmission receipt data 05
#define	IICDVFS_ICARD06					0xE60B0318	// R	8	IIC automatic transmission receipt data 06
#define	IICDVFS_ICARD07					0xE60B031C	// R	8	IIC automatic transmission receipt data 07
#define	IICDVFS_ICARD08					0xE60B0320	// R	8	IIC automatic transmission receipt data 08
#define	IICDVFS_ICARD09					0xE60B0324	// R	8	IIC automatic transmission receipt data 09
#define	IICDVFS_ICARD10					0xE60B0400	// R	8	IIC automatic transmission receipt data 10
#define	IICDVFS_ICARD11					0xE60B0404	// R	8	IIC automatic transmission receipt data 11
#define	IICDVFS_ICARD12					0xE60B0408	// R	8	IIC automatic transmission receipt data 12
#define	IICDVFS_ICARD13					0xE60B040C	// R	8	IIC automatic transmission receipt data 13
#define	IICDVFS_ICARD14					0xE60B0410	// R	8	IIC automatic transmission receipt data 14
#define	IICDVFS_ICARD15					0xE60B0414	// R	8	IIC automatic transmission receipt data 15
#define	IICDVFS_ICARD16					0xE60B0418	// R	8	IIC automatic transmission receipt data 16
#define	IICDVFS_ICARD17					0xE60B041C	// R	8	IIC automatic transmission receipt data 17
#define	IICDVFS_ICARD18					0xE60B0420	// R	8	IIC automatic transmission receipt data 18
#define	IICDVFS_ICARD19					0xE60B0424	// R	8	IIC automatic transmission receipt data 19


//LVDS
#define	LVDS_LVDCR0						0xFEB90000	// R/W	32	LVDS control register 0
#define	LVDS_LVDCR1						0xFEB90004	// R/W	32	LVDS control register 1
#define	LVDS_LVDPLLCR					0xFEB90008	// R/W	32	PLL control register
#define	LVDS_LVDCTRCR					0xFEB9000C	// R/W	32	CTR control register
#define	LVDS_LVDCHCR					0xFEB90010	// R/W	32	CH control register


//MMC_CH0
#define	MMC_CH0_SD_CMD					0xEE140000	// 	16/32/64
#define	MMC_CH0_SD_PORTSEL				0xEE140008	// 	16/32/64
#define	MMC_CH0_SD_ARG					0xEE140010	// 	16/32/64
#define	MMC_CH0_SD_ARG1					0xEE140018	// 	16/32/64
#define	MMC_CH0_SD_STOP					0xEE140020	// 	16/32/64
#define	MMC_CH0_SD_SECCNT				0xEE140028	// 	16/32/64
#define	MMC_CH0_SD_RSP10				0xEE140030	// 	16/32/64
#define	MMC_CH0_SD_RSP1					0xEE140038	// 	16/32/64
#define	MMC_CH0_SD_RSP32				0xEE140040	// 	16/32/64
#define	MMC_CH0_SD_RSP3					0xEE140048	// 	16/32/64
#define	MMC_CH0_SD_RSP54				0xEE140050	// 	16/32/64
#define	MMC_CH0_SD_RSP5					0xEE140058	// 	16/32/64
#define	MMC_CH0_SD_RSP76				0xEE140060	// 	16/32/64
#define	MMC_CH0_SD_RSP7					0xEE140068	// 	16/32/64
#define	MMC_CH0_SD_INFO1				0xEE140070	// 	16/32/64
#define	MMC_CH0_SD_INFO2				0xEE140078	// 	16/32/64
#define	MMC_CH0_SD_INFO1_MASK			0xEE140080	// 	16/32/64
#define	MMC_CH0_SD_INFO2_MASK			0xEE140088	// 	16/32/64
#define	MMC_CH0_SD_CLK_CTRL				0xEE140090	// 	16/32/64
#define	MMC_CH0_SD_SIZE					0xEE140098	// 	16/32/64
#define	MMC_CH0_SD_OPTION				0xEE1400A0	// 	16/32/64
#define	MMC_CH0_SD_ERR_STS1				0xEE1400B0	// 	16/32/64
#define	MMC_CH0_SD_ERR_STS2				0xEE1400B8	// 	16/32/64
#define	MMC_CH0_SD_BUF0					0xEE1400C0	// 	16/32/64
#define	MMC_CH0_SDIO_MODE				0xEE1400D0	// 	16/32/64
#define	MMC_CH0_SDIO_INFO1				0xEE1400D8	// 	16/32/64
#define	MMC_CH0_SDIO_INFO1_MASK			0xEE1400E0	// 	16/32/64
#define	MMC_CH0_CC_EXT_MODE				0xEE140360	// 	16/32/64
#define	MMC_CH0_SOFT_RST				0xEE140380	// 	16/32/64
#define	MMC_CH0_VERSION					0xEE140388	// 	16/32/64
#define	MMC_CH0_HOST_MODE				0xEE140390	// 	16/32/64
#define	MMC_CH0_SDIF_MODE				0xEE140398	// 	16/32/64
#define	MMC_CH0_DM_CM_SEQ_MODE			0xEE140808	// 	16/32/64
#define	MMC_CH0_DM_CM_DTRAN_MODE		0xEE140820	// 	16/32/64
#define	MMC_CH0_DM_CM_DTRAN_CTRL		0xEE140828	// 	16/32/64
#define	MMC_CH0_DM_CM_RST				0xEE140830	// 	16/32/64
#define	MMC_CH0_DM_CM_INFO1				0xEE140840	// 	16/32/64
#define	MMC_CH0_DM_CM_INFO1_MASK		0xEE140848	// 	16/32/64
#define	MMC_CH0_DM_CM_INFO2				0xEE140850	// 	16/32/64
#define	MMC_CH0_DM_CM_INFO2_MASK		0xEE140858	// 	16/32/64
#define	MMC_CH0_DM_DTRAN_ADDR			0xEE140880	// 	16/32/64
#define	MMC_CH0_SCC_DTCNTL				0xEE141000	// 	32	Initial setting register
#define	MMC_CH0_SCC_TAPSET				0xEE141008	// 	32	Sampling clock position setting register
#define	MMC_CH0_SCC_DT2FF				0xEE141010	// 	32	Hardware adjustment register 1
#define	MMC_CH0_SCC_CKSEL				0xEE141018	// 	32	Sampling clock selection register
#define	MMC_CH0_SCC_RVSCNTL				0xEE141020	// 	32	Sampling clock position correction register
#define	MMC_CH0_SCC_RVSREQ				0xEE141028	// 	32	Sampling clock position correction request register
#define	MMC_CH0_SCC_TMPPORT2			0xEE141038	// 	32	Hardware adjustment register 2
#define	MMC_CH0_SCC_TMPPORT3			0xEE141048	// 	32	Hardware adjustment register 3


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


//PCIE0
#define	PCIE0_PCIECAR					0xFE000010	// R/W	32	Configuration transmission address register 
#define	PCIE0_PCIECCTLR					0xFE000018	// R/W	32	Configuration transmission control register
#define	PCIE0_PCIECDR					0xFE000020	// R/W	32	Configuration transmission data register
#define	PCIE0_PCIEMSR					0xFE000028	// R/W	32	Mode setting register
#define	PCIE0_PCIEUNLOCKCR				0xFE000048	// R	32	Unlock transmission control register
#define	PCIE0_PCIEINTXR					0xFE000400	// R/W	32	INTx register
#define	PCIE0_PCIERMSGR					0xFE000410	// R/W	32	Message reception status register
#define	PCIE0_PCIERMSGIER				0xFE000440	// R/W	32	Message reception interrupt enable register
#define	PCIE0_PCIEPMMSGCR				0xFE000500	// R/W	32	Power management message transmission control register
#define	PCIE0_PCIEPHYSR					0xFE0007F0	// R/W	32	PHY layer status register
#define	PCIE0_PCIEMSITXR				0xFE000840	// R/W	32	MSI transmission register
#define	PCIE0_PCIETCTLR					0xFE002000	// R/W	32	Transfer control register
#define	PCIE0_PCIETSTR					0xFE002004	// R/W	32	Transfer status register
#define	PCIE0_PCIEINTR					0xFE002008	// R/W	32	Interrupt register
#define	PCIE0_PCIEINTER					0xFE00200C	// R/W	32	Interrupt enable register
#define	PCIE0_PCIEERRFR					0xFE002020	// R/W	32	Error factor register
#define	PCIE0_PCIEERRFER				0xFE002024	// R/W	32	Error interrupt enable register
#define	PCIE0_PCIEERRFR2				0xFE002028	// R/W	32	Error factor register 2
#define	PCIE0_PCIETIER					0xFE002030	// R/W	32	Transfer interrupt enable register
#define	PCIE0_PCIEPMSR					0xFE002034	// R/W	32	Power management state status register
#define	PCIE0_PCIEPMSCIER				0xFE002038	// R/W	32	Power management state interrupt enable register
#define	PCIE0_PCIEMSIFR					0xFE002044	// R/W	32	MSIF register
#define	PCIE0_PCIEMSIALR				0xFE002048	// R/W	32	MSI address lower register
#define	PCIE0_PCIEMSIAUR				0xFE00204C	// R/W	32	MSI address upper register
#define	PCIE0_PCIEMSIIER				0xFE002050	// R/W	32	MSI interrupt enable register
#define	PCIE0_PCIEPRAR0					0xFE002080	// R/W	32	PCIEC Root Port address register 0
#define	PCIE0_PCIEPRAR1					0xFE002084	// R/W	32	PCIEC Root Port address register 1
#define	PCIE0_PCIEPRAR2					0xFE002088	// R/W	32	PCIEC Root Port address register 2
#define	PCIE0_PCIEPRAR3					0xFE00208C	// R/W	32	PCIEC Root Port address register 3
#define	PCIE0_PCIEPRAR4					0xFE002090	// R/W	32	PCIEC Root Port address register 4
#define	PCIE0_PCIEPRAR5					0xFE002094	// R/W	32	PCIEC Root Port address register 5
#define	PCIE0_PCIELAR0					0xFE002200	// R/W	32	Local address register 0
#define	PCIE0_PCIELAMR0					0xFE002208	// R/W	32	Local address mask register 0
#define	PCIE0_PCIELAR1					0xFE002220	// R/W	32	Local address register 1
#define	PCIE0_PCIELAMR1					0xFE002228	// R/W	32	Local address mask register 1
#define	PCIE0_PCIELAR2					0xFE002240	// R/W	32	Local address register 2
#define	PCIE0_PCIELAMR2					0xFE002248	// R/W	32	Local address mask register 2
#define	PCIE0_PCIELAR3					0xFE002260	// R/W	32	Local address register 3
#define	PCIE0_PCIELAMR3					0xFE002268	// R/W	32	Local address mask register 3
#define	PCIE0_PCIELAR4					0xFE002280	// R/W	32	Local address register 4
#define	PCIE0_PCIELAMR4					0xFE002288	// R/W	32	Local address mask register 4
#define	PCIE0_PCIELAR5					0xFE0022A0	// R/W	32	Local address register 5
#define	PCIE0_PCIELAMR5					0xFE0022A8	// R/W	32	Local address mask register 5
#define	PCIE0_PCIEPALR0					0xFE003400	// R/W	32	PCIEC address lower register 0
#define	PCIE0_PCIEPAUR0					0xFE003404	// R/W	32	PCIEC address upper register 0
#define	PCIE0_PCIEPAMR0					0xFE003408	// R/W	32	PCIEC address mask register 0
#define	PCIE0_PCIEPTCTLR0				0xFE00340C	// R/W	32	PCIEC conversion control register 0
#define	PCIE0_PCIEPALR1					0xFE003420	// R/W	32	PCIEC address lower register 1
#define	PCIE0_PCIEPAUR1					0xFE003424	// R/W	32	PCIEC address upper register 1
#define	PCIE0_PCIEPAMR1					0xFE003428	// R/W	32	PCIEC address mask register 1
#define	PCIE0_PCIEPTCTLR1				0xFE00342C	// R/W	32	PCIEC conversion control register 1
#define	PCIE0_PCIEPALR2					0xFE003440	// R/W	32	PCIEC address lower register 2
#define	PCIE0_PCIEPAUR2					0xFE003444	// R/W	32	PCIEC address upper register 2
#define	PCIE0_PCIEPAMR2					0xFE003448	// R/W	32	PCIEC address mask register 2
#define	PCIE0_PCIEPTCTLR2				0xFE00344C	// R/W	32	PCIEC conversion control register 2
#define	PCIE0_PCIEPALR3					0xFE003460	// R/W	32	PCIEC address lower register 3
#define	PCIE0_PCIEPAUR3					0xFE003464	// R/W	32	PCIEC address upper register 3
#define	PCIE0_PCIEPAMR3					0xFE003468	// R/W	32	PCIEC address mask register 3
#define	PCIE0_PCIEPTCTLR3				0xFE00346C	// R/W	32	PCIEC conversion control register 3
#define	PCIE0_PCIEDMAOR					0xFE004000	// R/W	32	PCIEC DMAC DMA operation register
#define	PCIE0_PCIEDMPALR0				0xFE004100	// R/W	32	PCIEC DMAC PCI Express address lower register 0
#define	PCIE0_PCIEDMPAUR0				0xFE004104	// R/W	32	PCIEC DMAC PCI Express address upper register 0
#define	PCIE0_PCIEDMIAR0				0xFE004108	// R/W	32	PCIEC DMAC internal bus address register 0
#define	PCIE0_PCIEDMBCNTR0				0xFE004110	// R/W	32	PCIEC DMAC byte count register 0
#define	PCIE0_PCIEDMCCAR0				0xFE004120	// R/W	32	PCIEC DMAC command chain address register 0
#define	PCIE0_PCIEDMCHCR0				0xFE004128	// R/W	32	PCIEC DMAC channel control register 0
#define	PCIE0_PCIEDMCHSR0				0xFE00412C	// R/W	32	PCIEC DMAC channel status register 0
#define	PCIE0_PCIEDMCHC2R0				0xFE004130	// R/W	32	PCIEC DMAC channel control 2 register 0
#define	PCIE0_PCIEDMPALR1				0xFE004140	// R/W	32	PCIEC DMAC PCI Express address lower register 1
#define	PCIE0_PCIEDMPAUR1				0xFE004144	// R/W	32	PCIEC DMAC PCI Express address upper register 1
#define	PCIE0_PCIEDMIAR1				0xFE004148	// R/W	32	PCIEC DMAC internal bus address register 1
#define	PCIE0_PCIEDMBCNTR1				0xFE004150	// R/W	32	PCIEC DMAC byte count register 1
#define	PCIE0_PCIEDMCCAR1				0xFE004160	// R/W	32	PCIEC DMAC command chain address register 1
#define	PCIE0_PCIEDMCHCR1				0xFE004168	// R/W	32	PCIEC DMAC channel control register 1
#define	PCIE0_PCIEDMCHSR1				0xFE00416C	// R/W	32	PCIEC DMAC channel status register 1
#define	PCIE0_PCIEDMCHC2R1				0xFE004170	// R/W	32	PCIEC DMAC channel control 2 register 1
#define	PCIE0_PCIEDMPALR2				0xFE004180	// R/W	32	PCIEC DMAC PCI Express address lower register 2
#define	PCIE0_PCIEDMPAUR2				0xFE004184	// R/W	32	PCIEC DMAC PCI Express address upper register 2
#define	PCIE0_PCIEDMIAR2				0xFE004188	// R/W	32	PCIEC DMAC internal bus address register 2
#define	PCIE0_PCIEDMBCNTR2				0xFE004190	// R/W	32	PCIEC DMAC byte count register 2
#define	PCIE0_PCIEDMCCAR2				0xFE0041A0	// R/W	32	PCIEC DMAC command chain address register 2
#define	PCIE0_PCIEDMCHCR2				0xFE0041A8	// R/W	32	PCIEC DMAC channel control register 2
#define	PCIE0_PCIEDMCHSR2				0xFE0041AC	// R/W	32	PCIEC DMAC channel status register 2
#define	PCIE0_PCIEDMCHC2R2				0xFE0041B0	// R/W	32	PCIEC DMAC channel control 2 register 2
#define	PCIE0_PCIEDMPALR3				0xFE0041C0	// R/W	32	PCIEC DMAC PCI Express address lower register 3
#define	PCIE0_PCIEDMPAUR3				0xFE0041C4	// R/W	32	PCIEC DMAC PCI Express address upper register 3
#define	PCIE0_PCIEDMIAR3				0xFE0041C8	// R/W	32	PCIEC DMAC internal bus address register 3
#define	PCIE0_PCIEDMBCNTR3				0xFE0041D0	// R/W	32	PCIEC DMAC byte count register 3
#define	PCIE0_PCIEDMCCAR3				0xFE0041E0	// R/W	32	PCIEC DMAC command chain address register 3
#define	PCIE0_PCIEDMCHCR3				0xFE0041E8	// R/W	32	PCIEC DMAC channel control register 3
#define	PCIE0_PCIEDMCHSR3				0xFE0041EC	// R/W	32	PCIEC DMAC channel status register 3
#define	PCIE0_PCIEDMCHC2R3				0xFE0041F0	// R/W	32	PCIEC DMAC channel control 2 register 3
#define	PCIE0_PCIEDMPALR4				0xFE004200	// R/W	32	PCIEC DMAC PCI Express address lower register 4
#define	PCIE0_PCIEDMPAUR4				0xFE004204	// R/W	32	PCIEC DMAC PCI Express address upper register 4
#define	PCIE0_PCIEDMIAR4				0xFE004208	// R/W	32	PCIEC DMAC internal bus address register 4
#define	PCIE0_PCIEDMBCNTR4				0xFE004210	// R/W	32	PCIEC DMAC byte count register 4
#define	PCIE0_PCIEDMCCAR4				0xFE004220	// R/W	32	PCIEC DMAC command chain address register 4
#define	PCIE0_PCIEDMCHCR4				0xFE004228	// R/W	32	PCIEC DMAC channel control register 4
#define	PCIE0_PCIEDMCHSR4				0xFE00422C	// R/W	32	PCIEC DMAC channel status register 4
#define	PCIE0_PCIEDMCHC2R4				0xFE004230	// R/W	32	PCIEC DMAC channel control 2 register 4
#define	PCIE0_PCIEDMPALR5				0xFE004240	// R/W	32	PCIEC DMAC PCI Express address lower register 5
#define	PCIE0_PCIEDMPAUR5				0xFE004244	// R/W	32	PCIEC DMAC PCI Express address upper register 5
#define	PCIE0_PCIEDMIAR5				0xFE004248	// R/W	32	PCIEC DMAC internal bus address register 5
#define	PCIE0_PCIEDMBCNTR5				0xFE004250	// R/W	32	PCIEC DMAC byte count register 5
#define	PCIE0_PCIEDMCCAR5				0xFE004260	// R/W	32	PCIEC DMAC command chain address register 5
#define	PCIE0_PCIEDMCHCR5				0xFE004268	// R/W	32	PCIEC DMAC channel control register 5
#define	PCIE0_PCIEDMCHSR5				0xFE00426C	// R/W	32	PCIEC DMAC channel status register 5
#define	PCIE0_PCIEDMCHC2R5				0xFE004270	// R/W	32	PCIEC DMAC channel control 2 register 5
#define	PCIE0_PCIEDMPALR6				0xFE004280	// R/W	32	PCIEC DMAC PCI Express address lower register 6
#define	PCIE0_PCIEDMPAUR6				0xFE004284	// R/W	32	PCIEC DMAC PCI Express address upper register 6
#define	PCIE0_PCIEDMIAR6				0xFE004288	// R/W	32	PCIEC DMAC internal bus address register 6
#define	PCIE0_PCIEDMBCNTR6				0xFE004290	// R/W	32	PCIEC DMAC byte count register 6
#define	PCIE0_PCIEDMCCAR6				0xFE0042A0	// R/W	32	PCIEC DMAC command chain address register 6
#define	PCIE0_PCIEDMCHCR6				0xFE0042A8	// R/W	32	PCIEC DMAC channel control register 6
#define	PCIE0_PCIEDMCHSR6				0xFE0042AC	// R/W	32	PCIEC DMAC channel status register 6
#define	PCIE0_PCIEDMCHC2R6				0xFE0042B0	// R/W	32	PCIEC DMAC channel control 2 register 6
#define	PCIE0_PCIEDMPALR7				0xFE0042C0	// R/W	32	PCIEC DMAC PCI Express address lower register 7
#define	PCIE0_PCIEDMPAUR7				0xFE0042C4	// R/W	32	PCIEC DMAC PCI Express address upper register 7
#define	PCIE0_PCIEDMIAR7				0xFE0042C8	// R/W	32	PCIEC DMAC internal bus address register 7
#define	PCIE0_PCIEDMBCNTR7				0xFE0042D0	// R/W	32	PCIEC DMAC byte count register 7
#define	PCIE0_PCIEDMCCAR7				0xFE0042E0	// R/W	32	PCIEC DMAC command chain address register 7
#define	PCIE0_PCIEDMCHCR7				0xFE0042E8	// R/W	32	PCIEC DMAC channel control register 7
#define	PCIE0_PCIEDMCHSR7				0xFE0042EC	// R/W	32	PCIEC DMAC channel status register 7
#define	PCIE0_PCIEDMCHC2R7				0xFE0042F0	// R/W	32	PCIEC DMAC channel control 2 register 7
#define	PCIE0_PCICONF0					0xFE010000	// R	32	PCI configuration register 0
#define	PCIE0_PCICONF1					0xFE010004	// R/W	32	PCI configuration register 1
#define	PCIE0_PCICONF2					0xFE010008	// R	32	PCI configuration register 2
#define	PCIE0_PCICONF3					0xFE01000C	// R/W	32	PCI configuration register 3
#define	PCIE0_PCICONF4					0xFE010010	// 	32	PCI configuration register 4
#define	PCIE0_PCICONF5					0xFE010014	// 	32	PCI configuration register 5
#define	PCIE0_PCICONF6					0xFE010018	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 6
#define	PCIE0_PCICONF7					0xFE01001C	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 7
#define	PCIE0_PCICONF8					0xFE010020	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 8
#define	PCIE0_PCICONF9					0xFE010024	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 9
#define	PCIE0_PCICONF10					0xFE010028	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 10
#define	PCIE0_PCICONF11					0xFE01002C	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 11
#define	PCIE0_PCICONF12					0xFE010030	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 12
#define	PCIE0_PCICONF13					0xFE010034	// R/W	32	PCI configuration register 13
#define	PCIE0_PCICONF14					0xFE010038	// Header TYPE00: R/Header TYPE01: R	32	PCI configuration register 14
#define	PCIE0_PCICONF15					0xFE01003C	// Header TYPE00: R/W/Header TYPE01: R/W	32	PCI configuration register 15
#define	PCIE0_PMCAP0					0xFE010040	// R/W	32	PCI power management capability register 0
#define	PCIE0_PMCAP1					0xFE010044	// R/W	32	PCI power management capability register 1
#define	PCIE0_MSICAP0					0xFE010050	// R/W	32	MSI capability register 0
#define	PCIE0_MSICAP1					0xFE010054	// R/W	32	MSI capability register 1
#define	PCIE0_MSICAP2					0xFE010058	// R/W	32	MSI capability register 2
#define	PCIE0_MSICAP3					0xFE01005C	// R/W	32	MSI capability register 3
#define	PCIE0_MSICAP4					0xFE010060	// R/W	32	MSI capability register 4
#define	PCIE0_MSICAP5					0xFE010064	// R	32	MSI capability register 5
#define	PCIE0_EXPCAP0					0xFE010070	// R/W	32	PCI Express capability register 0/PCI Express capability list register/PCI Express capabilities register
#define	PCIE0_EXPCAP1					0xFE010074	// R/W	32	PCI Express capability register 1/Device capabilities register
#define	PCIE0_EXPCAP2					0xFE010078	// R/W	32	CI Express capability register 2/Device control register/Device status register
#define	PCIE0_EXPCAP3					0xFE01007C	// R/W	32	PCI Express capability register 3/Link capabilities register
#define	PCIE0_EXPCAP4					0xFE010080	// R/W	32	PCI Express capability register 4/Link control register/Link status register
#define	PCIE0_EXPCAP5					0xFE010084	// Header TYPE00: R/Header TYPE01: R	32	PCI Express capability register 5/Slot capabilities register
#define	PCIE0_EXPCAP6					0xFE010088	// Header TYPE00: R/Header TYPE01: R	32	PCI Express capability register 6/Slot control register/Slot status register
#define	PCIE0_EXPCAP7					0xFE01008C	// Header TYPE00: R/Header TYPE01: R/W	32	PCI Express capability register 7/Root control register/Root capabilities register
#define	PCIE0_EXPCAP8					0xFE010090	// Header TYPE00: R/Header TYPE01: R/W	32	PCI Express capability register 8/Root status register
#define	PCIE0_EXPCAP9					0xFE010094	// R/W	32	PCI Express capability register 9/Device capabilities 2 register
#define	PCIE0_EXPCAP10					0xFE010098	// R/W	32	PCI Express capability register 10/Device control 2 register/Device status 2 register
#define	PCIE0_EXPCAP11					0xFE01009C	// R	32	PCI Express capability register 11/Link capabilities 2 register
#define	PCIE0_EXPCAP12					0xFE0100A0	// R/W	32	PCI Express capability register 12/Link control 2 register/Link status 2 register
#define	PCIE0_EXPCAP13					0xFE0100A4	// R	32	PCI Express capability register 13/Slot capabilities 2 register
#define	PCIE0_EXPCAP14					0xFE0100A8	// R	32	PCI Express capability register 14/Slot control 2 register/Slot status 2 register
#define	PCIE0_VCCAP0					0xFE010100	// R/W	32	VC capability register 0/Virtual channel enhanced capability header
#define	PCIE0_VCCAP1					0xFE010104	// R/W	32	VC capability register 1/Port VC capability register 1
#define	PCIE0_VCCAP2					0xFE010108	// R	32	VC capability register 2/Port VC capability register 2
#define	PCIE0_VCCAP3					0xFE01010C	// R	32	VC capability register 3/Port VC status register/Port VC control register
#define	PCIE0_VCCAP4					0xFE010110	// R/W	32	VC capability register 4/VC0 resource capability register
#define	PCIE0_VCCAP5					0xFE010114	// R/W	32	VC capability register 5/VC0 resource control register
#define	PCIE0_VCCAP6					0xFE010118	// R	32	VC capability register 6/VC0 resource status register
#define	PCIE0_SERNUMCAP0				0xFE0101B0	// R/W	32	Device serial number capability register 0
#define	PCIE0_SERNUMCAP1				0xFE0101B4	// R	32	Device serial number capability register 1
#define	PCIE0_SERNUMCAP2				0xFE0101B8	// R	32	Device serial number capability register 2
#define	PCIE0_IDSETR0					0xFE011000	// R/W	32	ID setting register 0 
#define	PCIE0_IDSETR1					0xFE011004	// R/W	32	ID setting register 1
#define	PCIE0_SUBIDSETR					0xFE011024	// R/W	32	SUBID setting register
#define	PCIE0_DSERSETR0					0xFE01102C	// R/W	32	Device serial number setting register 0
#define	PCIE0_DSERSETR1					0xFE011030	// R/W	32	Device serial number setting register 1
#define	PCIE0_TLCTLR					0xFE011048	// R/W	32	TL control register
#define	PCIE0_MACSR						0xFE011054	// R/W	32	MAC status register
#define	PCIE0_MACCTLR					0xFE011058	// R/W	32	MAC control register
#define	PCIE0_PMSR						0xFE01105C	// R/W	32	PM status register
#define	PCIE0_PMCTLR					0xFE011060	// R/W	32	PM control register
#define	PCIE0_MACINTENR					0xFE01106C	// R/W	32	MAC interrupt enable register 
#define	PCIE0_PMINTENR					0xFE011070	// R/W	32	PM interrupt enable register
#define	PCIE0_MACS2R					0xFE011078	// R	32	MAC status register 2
#define	PCIE0_MACCTL2R					0xFE01107C	// R/W	32	MAC control register 2
#define	PCIE0_MACCGSPSETR				0xFE011084	// R/W	32	MAC speed change setting register 

#define	PCIE0_MEMORY0					0xFE100000	// PCIE0 memory 0 : 1Mbyte
#define	PCIE0_MEMORY1					0xFE200000	// PCIE0 memory 1 : 2Mbyte
#define	PCIE0_MEMORY2					0x30000000	// PCIE0 memory 2 : 128Mbyte
#define	PCIE0_MEMORY3					0x38000000	// PCIE0 memory 3 : 128Mbyte



//PCIE1
#define	PCIE1_PCIECAR					0xEE800010	// R/W	32	Configuration transmission address register 
#define	PCIE1_PCIECCTLR					0xEE800018	// R/W	32	Configuration transmission control register
#define	PCIE1_PCIECDR					0xEE800020	// R/W	32	Configuration transmission data register
#define	PCIE1_PCIEMSR					0xEE800028	// R/W	32	Mode setting register
#define	PCIE1_PCIEUNLOCKCR				0xEE800048	// R	32	Unlock transmission control register
#define	PCIE1_PCIEINTXR					0xEE800400	// R/W	32	INTx register
#define	PCIE1_PCIERMSGR					0xEE800410	// R/W	32	Message reception status register
#define	PCIE1_PCIERMSGIER				0xEE800440	// R/W	32	Message reception interrupt enable register
#define	PCIE1_PCIEPMMSGCR				0xEE800500	// R/W	32	Power management message transmission control register
#define	PCIE1_PCIEPHYSR					0xEE8007F0	// R/W	32	PHY layer status register
#define	PCIE1_PCIEMSITXR				0xEE800840	// R/W	32	MSI transmission register
#define	PCIE1_PCIETCTLR					0xEE802000	// R/W	32	Transfer control register
#define	PCIE1_PCIETSTR					0xEE802004	// R/W	32	Transfer status register
#define	PCIE1_PCIEINTR					0xEE802008	// R/W	32	Interrupt register
#define	PCIE1_PCIEINTER					0xEE80200C	// R/W	32	Interrupt enable register
#define	PCIE1_PCIEERRFR					0xEE802020	// R/W	32	Error factor register
#define	PCIE1_PCIEERRFER				0xEE802024	// R/W	32	Error interrupt enable register
#define	PCIE1_PCIEERRFR2				0xEE802028	// R/W	32	Error factor register 2
#define	PCIE1_PCIETIER					0xEE802030	// R/W	32	Transfer interrupt enable register
#define	PCIE1_PCIEPMSR					0xEE802034	// R/W	32	Power management state status register
#define	PCIE1_PCIEPMSCIER				0xEE802038	// R/W	32	Power management state interrupt enable register
#define	PCIE1_PCIEMSIFR					0xEE802044	// R/W	32	MSIF register
#define	PCIE1_PCIEMSIALR				0xEE802048	// R/W	32	MSI address lower register
#define	PCIE1_PCIEMSIAUR				0xEE80204C	// R/W	32	MSI address upper register
#define	PCIE1_PCIEMSIIER				0xEE802050	// R/W	32	MSI interrupt enable register
#define	PCIE1_PCIEPRAR0					0xEE802080	// R/W	32	PCIEC Root Port address register 0
#define	PCIE1_PCIEPRAR1					0xEE802084	// R/W	32	PCIEC Root Port address register 1
#define	PCIE1_PCIEPRAR2					0xEE802088	// R/W	32	PCIEC Root Port address register 2
#define	PCIE1_PCIEPRAR3					0xEE80208C	// R/W	32	PCIEC Root Port address register 3
#define	PCIE1_PCIEPRAR4					0xEE802090	// R/W	32	PCIEC Root Port address register 4
#define	PCIE1_PCIEPRAR5					0xEE802094	// R/W	32	PCIEC Root Port address register 5
#define	PCIE1_PCIELAR0					0xEE802200	// R/W	32	Local address register 0
#define	PCIE1_PCIELAMR0					0xEE802208	// R/W	32	Local address mask register 0
#define	PCIE1_PCIELAR1					0xEE802220	// R/W	32	Local address register 1
#define	PCIE1_PCIELAMR1					0xEE802228	// R/W	32	Local address mask register 1
#define	PCIE1_PCIELAR2					0xEE802240	// R/W	32	Local address register 2
#define	PCIE1_PCIELAMR2					0xEE802248	// R/W	32	Local address mask register 2
#define	PCIE1_PCIELAR3					0xEE802260	// R/W	32	Local address register 3
#define	PCIE1_PCIELAMR3					0xEE802268	// R/W	32	Local address mask register 3
#define	PCIE1_PCIELAR4					0xEE802280	// R/W	32	Local address register 4
#define	PCIE1_PCIELAMR4					0xEE802288	// R/W	32	Local address mask register 4
#define	PCIE1_PCIELAR5					0xEE8022A0	// R/W	32	Local address register 5
#define	PCIE1_PCIELAMR5					0xEE8022A8	// R/W	32	Local address mask register 5
#define	PCIE1_PCIEPALR0					0xEE803400	// R/W	32	PCIEC address lower register 0
#define	PCIE1_PCIEPAUR0					0xEE803404	// R/W	32	PCIEC address upper register 0
#define	PCIE1_PCIEPAMR0					0xEE803408	// R/W	32	PCIEC address mask register 0
#define	PCIE1_PCIEPTCTLR0				0xEE80340C	// R/W	32	PCIEC conversion control register 0
#define	PCIE1_PCIEPALR1					0xEE803420	// R/W	32	PCIEC address lower register 1
#define	PCIE1_PCIEPAUR1					0xEE803424	// R/W	32	PCIEC address upper register 1
#define	PCIE1_PCIEPAMR1					0xEE803428	// R/W	32	PCIEC address mask register 1
#define	PCIE1_PCIEPTCTLR1				0xEE80342C	// R/W	32	PCIEC conversion control register 1
#define	PCIE1_PCIEPALR2					0xEE803440	// R/W	32	PCIEC address lower register 2
#define	PCIE1_PCIEPAUR2					0xEE803444	// R/W	32	PCIEC address upper register 2
#define	PCIE1_PCIEPAMR2					0xEE803448	// R/W	32	PCIEC address mask register 2
#define	PCIE1_PCIEPTCTLR2				0xEE80344C	// R/W	32	PCIEC conversion control register 2
#define	PCIE1_PCIEPALR3					0xEE803460	// R/W	32	PCIEC address lower register 3
#define	PCIE1_PCIEPAUR3					0xEE803464	// R/W	32	PCIEC address upper register 3
#define	PCIE1_PCIEPAMR3					0xEE803468	// R/W	32	PCIEC address mask register 3
#define	PCIE1_PCIEPTCTLR3				0xEE80346C	// R/W	32	PCIEC conversion control register 3
#define	PCIE1_PCIEDMAOR					0xEE804000	// R/W	32	PCIEC DMAC DMA operation register
#define	PCIE1_PCIEDMPALR0				0xEE804100	// R/W	32	PCIEC DMAC PCI Express address lower register 0
#define	PCIE1_PCIEDMPAUR0				0xEE804104	// R/W	32	PCIEC DMAC PCI Express address upper register 0
#define	PCIE1_PCIEDMIAR0				0xEE804108	// R/W	32	PCIEC DMAC internal bus address register 0
#define	PCIE1_PCIEDMBCNTR0				0xEE804110	// R/W	32	PCIEC DMAC byte count register 0
#define	PCIE1_PCIEDMCCAR0				0xEE804120	// R/W	32	PCIEC DMAC command chain address register 0
#define	PCIE1_PCIEDMCHCR0				0xEE804128	// R/W	32	PCIEC DMAC channel control register 0
#define	PCIE1_PCIEDMCHSR0				0xEE80412C	// R/W	32	PCIEC DMAC channel status register 0
#define	PCIE1_PCIEDMCHC2R0				0xEE804130	// R/W	32	PCIEC DMAC channel control 2 register 0
#define	PCIE1_PCIEDMPALR1				0xEE804140	// R/W	32	PCIEC DMAC PCI Express address lower register 1
#define	PCIE1_PCIEDMPAUR1				0xEE804144	// R/W	32	PCIEC DMAC PCI Express address upper register 1
#define	PCIE1_PCIEDMIAR1				0xEE804148	// R/W	32	PCIEC DMAC internal bus address register 1
#define	PCIE1_PCIEDMBCNTR1				0xEE804150	// R/W	32	PCIEC DMAC byte count register 1
#define	PCIE1_PCIEDMCCAR1				0xEE804160	// R/W	32	PCIEC DMAC command chain address register 1
#define	PCIE1_PCIEDMCHCR1				0xEE804168	// R/W	32	PCIEC DMAC channel control register 1
#define	PCIE1_PCIEDMCHSR1				0xEE80416C	// R/W	32	PCIEC DMAC channel status register 1
#define	PCIE1_PCIEDMCHC2R1				0xEE804170	// R/W	32	PCIEC DMAC channel control 2 register 1
#define	PCIE1_PCIEDMPALR2				0xEE804180	// R/W	32	PCIEC DMAC PCI Express address lower register 2
#define	PCIE1_PCIEDMPAUR2				0xEE804184	// R/W	32	PCIEC DMAC PCI Express address upper register 2
#define	PCIE1_PCIEDMIAR2				0xEE804188	// R/W	32	PCIEC DMAC internal bus address register 2
#define	PCIE1_PCIEDMBCNTR2				0xEE804190	// R/W	32	PCIEC DMAC byte count register 2
#define	PCIE1_PCIEDMCCAR2				0xEE8041A0	// R/W	32	PCIEC DMAC command chain address register 2
#define	PCIE1_PCIEDMCHCR2				0xEE8041A8	// R/W	32	PCIEC DMAC channel control register 2
#define	PCIE1_PCIEDMCHSR2				0xEE8041AC	// R/W	32	PCIEC DMAC channel status register 2
#define	PCIE1_PCIEDMCHC2R2				0xEE8041B0	// R/W	32	PCIEC DMAC channel control 2 register 2
#define	PCIE1_PCIEDMPALR3				0xEE8041C0	// R/W	32	PCIEC DMAC PCI Express address lower register 3
#define	PCIE1_PCIEDMPAUR3				0xEE8041C4	// R/W	32	PCIEC DMAC PCI Express address upper register 3
#define	PCIE1_PCIEDMIAR3				0xEE8041C8	// R/W	32	PCIEC DMAC internal bus address register 3
#define	PCIE1_PCIEDMBCNTR3				0xEE8041D0	// R/W	32	PCIEC DMAC byte count register 3
#define	PCIE1_PCIEDMCCAR3				0xEE8041E0	// R/W	32	PCIEC DMAC command chain address register 3
#define	PCIE1_PCIEDMCHCR3				0xEE8041E8	// R/W	32	PCIEC DMAC channel control register 3
#define	PCIE1_PCIEDMCHSR3				0xEE8041EC	// R/W	32	PCIEC DMAC channel status register 3
#define	PCIE1_PCIEDMCHC2R3				0xEE8041F0	// R/W	32	PCIEC DMAC channel control 2 register 3
#define	PCIE1_PCIEDMPALR4				0xEE804200	// R/W	32	PCIEC DMAC PCI Express address lower register 4
#define	PCIE1_PCIEDMPAUR4				0xEE804204	// R/W	32	PCIEC DMAC PCI Express address upper register 4
#define	PCIE1_PCIEDMIAR4				0xEE804208	// R/W	32	PCIEC DMAC internal bus address register 4
#define	PCIE1_PCIEDMBCNTR4				0xEE804210	// R/W	32	PCIEC DMAC byte count register 4
#define	PCIE1_PCIEDMCCAR4				0xEE804220	// R/W	32	PCIEC DMAC command chain address register 4
#define	PCIE1_PCIEDMCHCR4				0xEE804228	// R/W	32	PCIEC DMAC channel control register 4
#define	PCIE1_PCIEDMCHSR4				0xEE80422C	// R/W	32	PCIEC DMAC channel status register 4
#define	PCIE1_PCIEDMCHC2R4				0xEE804230	// R/W	32	PCIEC DMAC channel control 2 register 4
#define	PCIE1_PCIEDMPALR5				0xEE804240	// R/W	32	PCIEC DMAC PCI Express address lower register 5
#define	PCIE1_PCIEDMPAUR5				0xEE804244	// R/W	32	PCIEC DMAC PCI Express address upper register 5
#define	PCIE1_PCIEDMIAR5				0xEE804248	// R/W	32	PCIEC DMAC internal bus address register 5
#define	PCIE1_PCIEDMBCNTR5				0xEE804250	// R/W	32	PCIEC DMAC byte count register 5
#define	PCIE1_PCIEDMCCAR5				0xEE804260	// R/W	32	PCIEC DMAC command chain address register 5
#define	PCIE1_PCIEDMCHCR5				0xEE804268	// R/W	32	PCIEC DMAC channel control register 5
#define	PCIE1_PCIEDMCHSR5				0xEE80426C	// R/W	32	PCIEC DMAC channel status register 5
#define	PCIE1_PCIEDMCHC2R5				0xEE804270	// R/W	32	PCIEC DMAC channel control 2 register 5
#define	PCIE1_PCIEDMPALR6				0xEE804280	// R/W	32	PCIEC DMAC PCI Express address lower register 6
#define	PCIE1_PCIEDMPAUR6				0xEE804284	// R/W	32	PCIEC DMAC PCI Express address upper register 6
#define	PCIE1_PCIEDMIAR6				0xEE804288	// R/W	32	PCIEC DMAC internal bus address register 6
#define	PCIE1_PCIEDMBCNTR6				0xEE804290	// R/W	32	PCIEC DMAC byte count register 6
#define	PCIE1_PCIEDMCCAR6				0xEE8042A0	// R/W	32	PCIEC DMAC command chain address register 6
#define	PCIE1_PCIEDMCHCR6				0xEE8042A8	// R/W	32	PCIEC DMAC channel control register 6
#define	PCIE1_PCIEDMCHSR6				0xEE8042AC	// R/W	32	PCIEC DMAC channel status register 6
#define	PCIE1_PCIEDMCHC2R6				0xEE8042B0	// R/W	32	PCIEC DMAC channel control 2 register 6
#define	PCIE1_PCIEDMPALR7				0xEE8042C0	// R/W	32	PCIEC DMAC PCI Express address lower register 7
#define	PCIE1_PCIEDMPAUR7				0xEE8042C4	// R/W	32	PCIEC DMAC PCI Express address upper register 7
#define	PCIE1_PCIEDMIAR7				0xEE8042C8	// R/W	32	PCIEC DMAC internal bus address register 7
#define	PCIE1_PCIEDMBCNTR7				0xEE8042D0	// R/W	32	PCIEC DMAC byte count register 7
#define	PCIE1_PCIEDMCCAR7				0xEE8042E0	// R/W	32	PCIEC DMAC command chain address register 7
#define	PCIE1_PCIEDMCHCR7				0xEE8042E8	// R/W	32	PCIEC DMAC channel control register 7
#define	PCIE1_PCIEDMCHSR7				0xEE8042EC	// R/W	32	PCIEC DMAC channel status register 7
#define	PCIE1_PCIEDMCHC2R7				0xEE8042F0	// R/W	32	PCIEC DMAC channel control 2 register 7
#define	PCIE1_PCICONF0					0xEE810000	// R	32	PCI configuration register 0
#define	PCIE1_PCICONF1					0xEE810004	// R/W	32	PCI configuration register 1
#define	PCIE1_PCICONF2					0xEE810008	// R	32	PCI configuration register 2
#define	PCIE1_PCICONF3					0xEE81000C	// R/W	32	PCI configuration register 3
#define	PCIE1_PCICONF4					0xEE810010	// 	32	PCI configuration register 4
#define	PCIE1_PCICONF5					0xEE810014	// 	32	PCI configuration register 5
#define	PCIE1_PCICONF6					0xEE810018	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 6
#define	PCIE1_PCICONF7					0xEE81001C	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 7
#define	PCIE1_PCICONF8					0xEE810020	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 8
#define	PCIE1_PCICONF9					0xEE810024	// Header TYPE00:/Header TYPE01: R/W	32	PCI configuration register 9
#define	PCIE1_PCICONF10					0xEE810028	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 10
#define	PCIE1_PCICONF11					0xEE81002C	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 11
#define	PCIE1_PCICONF12					0xEE810030	// Header TYPE00: R/Header TYPE01: R/W	32	PCI configuration register 12
#define	PCIE1_PCICONF13					0xEE810034	// R/W	32	PCI configuration register 13
#define	PCIE1_PCICONF14					0xEE810038	// Header TYPE00: R/Header TYPE01: R	32	PCI configuration register 14
#define	PCIE1_PCICONF15					0xEE81003C	// Header TYPE00: R/W/Header TYPE01: R/W	32	PCI configuration register 15
#define	PCIE1_PMCAP0					0xEE810040	// R/W	32	PCI power management capability register 0
#define	PCIE1_PMCAP1					0xEE810044	// R/W	32	PCI power management capability register 1
#define	PCIE1_MSICAP0					0xEE810050	// R/W	32	MSI capability register 0
#define	PCIE1_MSICAP1					0xEE810054	// R/W	32	MSI capability register 1
#define	PCIE1_MSICAP2					0xEE810058	// R/W	32	MSI capability register 2
#define	PCIE1_MSICAP3					0xEE81005C	// R/W	32	MSI capability register 3
#define	PCIE1_MSICAP4					0xEE810060	// R/W	32	MSI capability register 4
#define	PCIE1_MSICAP5					0xEE810064	// R	32	MSI capability register 5
#define	PCIE1_EXPCAP0					0xEE810070	// R/W	32	PCI Express capability register 0/PCI Express capability list register/PCI Express capabilities register
#define	PCIE1_EXPCAP1					0xEE810074	// R/W	32	PCI Express capability register 1/Device capabilities register
#define	PCIE1_EXPCAP2					0xEE810078	// R/W	32	CI Express capability register 2/Device control register/Device status register
#define	PCIE1_EXPCAP3					0xEE81007C	// R/W	32	PCI Express capability register 3/Link capabilities register
#define	PCIE1_EXPCAP4					0xEE810080	// R/W	32	PCI Express capability register 4/Link control register/Link status register
#define	PCIE1_EXPCAP5					0xEE810084	// Header TYPE00: R/Header TYPE01: R	32	PCI Express capability register 5/Slot capabilities register
#define	PCIE1_EXPCAP6					0xEE810088	// Header TYPE00: R/Header TYPE01: R	32	PCI Express capability register 6/Slot control register/Slot status register
#define	PCIE1_EXPCAP7					0xEE81008C	// Header TYPE00: R/Header TYPE01: R/W	32	PCI Express capability register 7/Root control register/Root capabilities register
#define	PCIE1_EXPCAP8					0xEE810090	// Header TYPE00: R/Header TYPE01: R/W	32	PCI Express capability register 8/Root status register
#define	PCIE1_EXPCAP9					0xEE810094	// R/W	32	PCI Express capability register 9/Device capabilities 2 register
#define	PCIE1_EXPCAP10					0xEE810098	// R/W	32	PCI Express capability register 10/Device control 2 register/Device status 2 register
#define	PCIE1_EXPCAP11					0xEE81009C	// R	32	PCI Express capability register 11/Link capabilities 2 register
#define	PCIE1_EXPCAP12					0xEE8100A0	// R/W	32	PCI Express capability register 12/Link control 2 register/Link status 2 register
#define	PCIE1_EXPCAP13					0xEE8100A4	// R	32	PCI Express capability register 13/Slot capabilities 2 register
#define	PCIE1_EXPCAP14					0xEE8100A8	// R	32	PCI Express capability register 14/Slot control 2 register/Slot status 2 register
#define	PCIE1_VCCAP0					0xEE810100	// R/W	32	VC capability register 0/Virtual channel enhanced capability header
#define	PCIE1_VCCAP1					0xEE810104	// R/W	32	VC capability register 1/Port VC capability register 1
#define	PCIE1_VCCAP2					0xEE810108	// R	32	VC capability register 2/Port VC capability register 2
#define	PCIE1_VCCAP3					0xEE81010C	// R	32	VC capability register 3/Port VC status register/Port VC control register
#define	PCIE1_VCCAP4					0xEE810110	// R/W	32	VC capability register 4/VC0 resource capability register
#define	PCIE1_VCCAP5					0xEE810114	// R/W	32	VC capability register 5/VC0 resource control register
#define	PCIE1_VCCAP6					0xEE810118	// R	32	VC capability register 6/VC0 resource status register
#define	PCIE1_SERNUMCAP0				0xEE8101B0	// R/W	32	Device serial number capability register 0
#define	PCIE1_SERNUMCAP1				0xEE8101B4	// R	32	Device serial number capability register 1
#define	PCIE1_SERNUMCAP2				0xEE8101B8	// R	32	Device serial number capability register 2
#define	PCIE1_IDSETR0					0xEE811000	// R/W	32	ID setting register 0 
#define	PCIE1_IDSETR1					0xEE811004	// R/W	32	ID setting register 1
#define	PCIE1_SUBIDSETR					0xEE811024	// R/W	32	SUBID setting register
#define	PCIE1_DSERSETR0					0xEE81102C	// R/W	32	Device serial number setting register 0
#define	PCIE1_DSERSETR1					0xEE811030	// R/W	32	Device serial number setting register 1
#define	PCIE1_TLCTLR					0xEE811048	// R/W	32	TL control register
#define	PCIE1_MACSR						0xEE811054	// R/W	32	MAC status register
#define	PCIE1_MACCTLR					0xEE811058	// R/W	32	MAC control register
#define	PCIE1_PMSR						0xEE81105C	// R/W	32	PM status register
#define	PCIE1_PMCTLR					0xEE811060	// R/W	32	PM control register
#define	PCIE1_MACINTENR					0xEE81106C	// R/W	32	MAC interrupt enable register 
#define	PCIE1_PMINTENR					0xEE811070	// R/W	32	PM interrupt enable register
#define	PCIE1_MACS2R					0xEE811078	// R	32	MAC status register 2
#define	PCIE1_MACCTL2R					0xEE81107C	// R/W	32	MAC control register 2
#define	PCIE1_MACCGSPSETR				0xEE811084	// R/W	32	MAC speed change setting register 

#define	PCIE1_MEMORY0					0xEE900000	// PCIE1 memory 0 : 1Mbyte
#define	PCIE1_MEMORY1					0xEEA00000	// PCIE1 memory 1 : 2Mbyte
#define	PCIE1_MEMORY2					0xC0000000	// PCIE1 memory 2 : 128Mbyte
#define	PCIE1_MEMORY3					0xC8000000	// PCIE1 memory 3 : 128Mbyte



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


//PWM
#define	PWM_PWMCR0						0xE6E30000	// R/W	32	PWM control register
#define	PWM_PWMCNT0						0xE6E30004	// R/W	32	PWM count register
#define	PWM_PWMCR1						0xE6E31000	// R/W	32	PWM control register
#define	PWM_PWMCNT1						0xE6E31004	// R/W	32	PWM count register
#define	PWM_PWMCR2						0xE6E32000	// R/W	32	PWM control register
#define	PWM_PWMCNT2						0xE6E32004	// R/W	32	PWM count register
#define	PWM_PWMCR3						0xE6E33000	// R/W	32	PWM control register
#define	PWM_PWMCNT3						0xE6E33004	// R/W	32	PWM count register
#define	PWM_PWMCR4						0xE6E34000	// R/W	32	PWM control register
#define	PWM_PWMCNT4						0xE6E34004	// R/W	32	PWM count register
#define	PWM_PWMCR5						0xE6E35000	// R/W	32	PWM control register
#define	PWM_PWMCNT5						0xE6E35004	// R/W	32	PWM count register
#define	PWM_PWMCR6						0xE6E36000	// R/W	32	PWM control register
#define	PWM_PWMCNT6						0xE6E36004	// R/W	32	PWM count register


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


//SATA
#define	SATA_DATA						0xEE300100	// R/W	32 (16)1	Shadow data register
#define	SATA_SERR						0xEE300104	// R	32 (8)2	Shadow error register
#define	SATA_SFEATURES					0xEE300104	// W	32 (8)2	Shadow features register
#define	SATA_SECCNT						0xEE300108	// R/W	32 (8)2	Shadow sector CNT register
#define	SATA_LBALOW						0xEE30010C	// R/W	32 (8)2	Shadow LBA low register
#define	SATA_LBAMID						0xEE300110	// R/W	32 (8)2	Shadow LBA mid register
#define	SATA_LBAHIGH					0xEE300114	// R/W	32 (8)2	Shadow LBA high register
#define	SATA_DEVHEAD					0xEE300118	// R/W	32 (8)2	Shadow device/head register
#define	SATA_SSTATUS					0xEE30011C	// R	32 (8)2	Shadow status register
#define	SATA_SCOM						0xEE30011C	// W	32 (8)2	Shadow command register
#define	SATA_SALTSTS					0xEE300138	// R	32 (8)2	Shadow alternates status register
#define	SATA_SDEVCON					0xEE300138	// W	32 (8)2	Shadow device control register
#define	SATA_ATAPI_CONTROL1				0xEE300180	// R/W	32	ATAPI control register
#define	SATA_ATAPI_STATUS				0xEE300184	// R/WC0	32	ATAPI status register
#define	SATA_ATAPI_INT_ENABLE			0xEE300188	// R/W	32	Interrupt enable register
#define	SATA_ATAPI_DTB_ADR				0xEE300198	// R/W	32	Descriptor table base address register
#define	SATA_ATAPI_DMA_START_ADR		0xEE30019C	// R/W	32	DMA start address register
#define	SATA_ATAPI_DMA_TRANS_CNT		0xEE3001A0	// R/W	32	DMA transfer count register
#define	SATA_ATAPI_CONTROL2				0xEE3001A4	// R/W	32	ATAPI control 2 register
#define	SATA_ATAPI_SIG_ST				0xEE3001B0	// R	32	ATAPI signal status register
#define	SATA_ATAPI_BYTE_SWAP			0xEE3001BC	// R/W	32	Byte swap register
#define	SATA_BISTCONF					0xEE30102C	// R/W	32	BIST config register
#define	SATA_SDATA						0xEE301100	// R/W	32	Shadow data register
#define	SATA_SSERR						0xEE301104	// R	32	Shadow error register
#define	SATA_SSFEATURES					0xEE301104	// W	32	Shadow features register
#define	SATA_SSECCNT					0xEE301108	// R/W	32	Shadow sector CNT register
#define	SATA_SLBALOW					0xEE30110C	// R/W	32	Shadow LBA low register
#define	SATA_SLBAMID					0xEE301110	// R/W	32	Shadow LBA mid register
#define	SATA_SLBAHIGH					0xEE301114	// R/W	32	Shadow LBA high register
#define	SATA_SDEVHEAD					0xEE301118	// R/W	32	Shadow device/head register
#define	SATA_SSSTATUS					0xEE30111C	// R	32	Shadow status register
#define	SATA_SSCOM						0xEE30111C	// W	32	Shadow command register
#define	SATA_SSALTSTS					0xEE301204	// R	32	Shadow alternate status register
#define	SATA_SSDEVCON					0xEE301204	// W	32	Shadow device control register
#define	SATA_SATAEICCR					0xEE301220	// R/W	32	SATA extend ICC register
#define	SATA_SATAEAUXR					0xEE301224	// R/W	32	SATA extend Auxiliary register
#define	SATA_SATAEDEVSLPR				0xEE301228	// R/W	32	SATA extend DEVSLP register
#define	SATA_SCRSSTS					0xEE301400	// R	32	SCR Sstatus register
#define	SATA_SCRSERR					0xEE301404	// R/WC1	32	SCR Serror register
#define	SATA_SCRSCON					0xEE301408	// R/W	32	SCR Scontrol register
#define	SATA_SCRSACT					0xEE30140C	// R/W	32	SCR Sactive register
#define	SATA_SATAINTSTAT				0xEE301508	// RC	32	SATA INT status register
#define	SATA_SATAINTMASK				0xEE30150C	// R/W	32	SATA INT mask register
#define	SATA_DMADW0						0xEE301620	// R/W	32	Rx DMA setup FIS dword 0 register
#define	SATA_DMADW1						0xEE301624	// R/W	32	Rx DMA setup FIS dword 1 register
#define	SATA_DMADW2						0xEE301628	// R/W	32	Rx DMA setup FIS dword 2 register
#define	SATA_DMADW3						0xEE30162C	// R/W	32	Rx DMA setup FIS dword 3 register
#define	SATA_DMADW4						0xEE301630	// R/W	32	Rx DMA setup FIS dword 4 register
#define	SATA_DMADW5						0xEE301634	// R/W	32	Rx DMA setup FIS dword 5 register
#define	SATA_DMADW6						0xEE301638	// R/W	32	Rx DMA setup FIS dword 6 register


//SCIF1
#define	SCIF1_SCSMR						0xE6E68000	// R/W	16	Serial mode register
#define	SCIF1_SCBRR						0xE6E68004	// R/W	8	Bit rate register
#define	SCIF1_SCSCR						0xE6E68008	// R/W	16	Serial control register
#define	SCIF1_SCFTDR					0xE6E6800C	// W	8	Transmit FIFO data register
#define	SCIF1_SCFSR						0xE6E68010	// R/W	16	Serial status register
#define	SCIF1_SCFRDR					0xE6E68014	// R	8	Receive FIFO data register
#define	SCIF1_SCFCR						0xE6E68018	// R/W	16	FIFO control register
#define	SCIF1_SCFDR						0xE6E6801C	// R	16	FIFO data count register
#define	SCIF1_SCSPTR					0xE6E68020	// R/W	16	Serial port register
#define	SCIF1_SCLSR						0xE6E68024	// R/W	16	Line status register
#define	SCIF1_DL						0xE6E68030	// R/W	16	Frequency division register 
#define	SCIF1_CKS						0xE6E68034	// R/W	16	Clock Select register 


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


//SSI
#define	SSI_SSICR0						0xEC541000	// R/W	32	Control register 0
#define	SSI_SSISR0						0xEC541004	// R/W1	32	Status register 0
#define	SSI_SSITDR0						0xEC541008	// R/W	32	Transmit data register 0
#define	SSI_SSIRDR0						0xEC54100C	// R	32	Receive data register 0
#define	SSI_SSIWSR0						0xEC541020	// R/W	32	WS mode register 0
#define	SSI_SSIFMR0						0xEC541024	// R/W	32	FS mode register 0
#define	SSI_SSIFSR0						0xEC541028	// R/W2	32	FS status register 0
#define	SSI_SSICRE0						0xEC541030	// R/W	32	Control register extend 0
#define	SSI_SSICR1						0xEC541040	// R/W	32	Control register 1
#define	SSI_SSISR1						0xEC541044	// R/W1	32	Status register 1
#define	SSI_SSITDR1						0xEC541048	// R/W	32	Transmit data register 1
#define	SSI_SSIRDR1						0xEC54104C	// R	32	Receive data register 1
#define	SSI_SSIWSR1						0xEC541060	// R/W	32	WS mode register 1
#define	SSI_SSIFMR1						0xEC541064	// R/W	32	FS mode register 1
#define	SSI_SSIFSR1						0xEC541068	// R/W2	32	FS status register 1
#define	SSI_SSICRE1						0xEC541070	// R/W	32	Control register extend 1
#define	SSI_SSICR2						0xEC541080	// R/W	32	Control register 2
#define	SSI_SSISR2						0xEC541084	// R/W1	32	Status register 2
#define	SSI_SSITDR2						0xEC541088	// R/W	32	Transmit data register 2
#define	SSI_SSIRDR2						0xEC54108C	// R	32	Receive data register 2
#define	SSI_SSIWSR2						0xEC5410A0	// R/W	32	WS mode register 2
#define	SSI_SSIFMR2						0xEC5410A4	// R/W	32	FS mode register 2
#define	SSI_SSIFSR2						0xEC5410A8	// R/W2	32	FS status register 2
#define	SSI_SSICRE2						0xEC5410B0	// R/W	32	Control register extend 2
#define	SSI_SSICR3						0xEC5410C0	// R/W	32	Control register 3
#define	SSI_SSISR3						0xEC5410C4	// R/W1	32	Status register 3
#define	SSI_SSITDR3						0xEC5410C8	// R/W	32	Transmit data register 3
#define	SSI_SSIRDR3						0xEC5410CC	// R	32	Receive data register 3
#define	SSI_SSIWSR3						0xEC5410E0	// R/W	32	WS mode register 3
#define	SSI_SSIFMR3						0xEC5410E4	// R/W	32	FS mode register 3
#define	SSI_SSIFSR3						0xEC5410E8	// R/W2	32	FS status register 3
#define	SSI_SSICRE3						0xEC5410F0	// R/W	32	Control register extend 3
#define	SSI_SSICR4						0xEC541100	// R/W	32	Control register 4
#define	SSI_SSISR4						0xEC541104	// R/W1	32	Status register 4
#define	SSI_SSITDR4						0xEC541108	// R/W	32	Transmit data register 4
#define	SSI_SSIRDR4						0xEC54110C	// R	32	Receive data register 4
#define	SSI_SSIWSR4						0xEC541120	// R/W	32	WS mode register 4
#define	SSI_SSIFMR4						0xEC541124	// R/W	32	FS mode register 4
#define	SSI_SSIFSR4						0xEC541128	// R/W2	32	FS status register 4
#define	SSI_SSICRE4						0xEC541130	// R/W	32	Control register extend 4
#define	SSI_SSICR5						0xEC541140	// R/W	32	Control register 5
#define	SSI_SSISR5						0xEC541144	// R/W1	32	Status register 5
#define	SSI_SSITDR5						0xEC541148	// R/W	32	Transmit data register 5
#define	SSI_SSIRDR5						0xEC54114C	// R	32	Receive data register 5
#define	SSI_SSIWSR5						0xEC541160	// R/W	32	WS mode register 5
#define	SSI_SSIFMR5						0xEC541164	// R/W	32	FS mode register 5
#define	SSI_SSIFSR5						0xEC541168	// R/W2	32	FS status register 5
#define	SSI_SSICR6						0xEC541180	// R/W	32	Control register 6
#define	SSI_SSISR6						0xEC541184	// R/W1	32	Status register 6
#define	SSI_SSITDR6						0xEC541188	// R/W	32	Transmit data register 6
#define	SSI_SSIRDR6						0xEC54118C	// R	32	Receive data register 6
#define	SSI_SSIWSR6						0xEC5411A0	// R/W	32	WS mode register 6
#define	SSI_SSIFMR6						0xEC5411A4	// R/W	32	FS mode register 6
#define	SSI_SSIFSR6						0xEC5411A8	// R/W2	32	FS status register 6
#define	SSI_SSICR7						0xEC5411C0	// R/W	32	Control register 7
#define	SSI_SSISR7						0xEC5411C4	// R/W1	32	Status register 7
#define	SSI_SSITDR7						0xEC5411C8	// R/W	32	Transmit data register 7
#define	SSI_SSIRDR7						0xEC5411CC	// R	32	Receive data register 7
#define	SSI_SSIWSR7						0xEC5411E0	// R/W	32	WS mode register 7
#define	SSI_SSIFMR7						0xEC5411E4	// R/W	32	FS mode register 7
#define	SSI_SSIFSR7						0xEC5411E8	// R/W2	32	FS status register 7
#define	SSI_SSICR8						0xEC541200	// R/W	32	Control register 8
#define	SSI_SSISR8						0xEC541204	// R/W1	32	Status register 8
#define	SSI_SSITDR8						0xEC541208	// R/W	32	Transmit data register 8
#define	SSI_SSIRDR8						0xEC54120C	// R	32	Receive data register 8
#define	SSI_SSIWSR8						0xEC541220	// R/W	32	WS mode register 8
#define	SSI_SSIFMR8						0xEC541224	// R/W	32	FS mode register 8
#define	SSI_SSIFSR8						0xEC541228	// R/W2	32	FS status register 8
#define	SSI_SSICR9						0xEC541240	// R/W	32	Control register 9
#define	SSI_SSISR9						0xEC541244	// R/W1	32	Status register 9
#define	SSI_SSITDR9						0xEC541248	// R/W	32	Transmit data register 9
#define	SSI_SSIRDR9						0xEC54124C	// R	32	Receive data register 9
#define	SSI_SSIWSR9						0xEC541260	// R/W	32	WS mode register 9
#define	SSI_SSIFMR9						0xEC541264	// R/W	32	FS mode register 9
#define	SSI_SSIFSR9						0xEC541268	// R/W2	32	FS status register 9
#define	SSI_SSICRE9						0xEC541270	// R/W	32	Control register extend 9
#define	SSI_SSITDR0_DMA					0xEC241008	// R/W	32	Transmit data register 0
#define	SSI_SSIRDR0_DMA					0xEC24100C	// R	32	Receive data register 0
#define	SSI_SSITDR1_DMA					0xEC241048	// R/W	32	Transmit data register 1
#define	SSI_SSIRDR1_DMA					0xEC24104C	// R	32	Receive data register 1
#define	SSI_SSITDR2_DMA					0xEC241088	// R/W	32	Transmit data register 2
#define	SSI_SSITDR3_DMA					0xEC2410C8	// R/W	32	Transmit data register 3
#define	SSI_SSIRDR3_DMA					0xEC2410CC	// R	32	Receive data register 3
#define	SSI_SSITDR4_DMA					0xEC241108	// R/W	32	Transmit data register 4
#define	SSI_SSIRDR4_DMA					0xEC24110C	// R	32	Receive data register 4
#define	SSI_SSITDR5_DMA					0xEC241148	// R/W	32	Transmit data register 5
#define	SSI_SSIRDR5_DMA					0xEC24114C	// R	32	Receive data register 5
#define	SSI_SSITDR6_DMA					0xEC241188	// R/W	32	Transmit data register 6
#define	SSI_SSIRDR6_DMA					0xEC24118C	// R	32	Receive data register 6
#define	SSI_SSITDR7_DMA					0xEC2411C8	// R/W	32	Transmit data register 7
#define	SSI_SSIRDR7_DMA					0xEC2411CC	// R	32	Receive data register 7
#define	SSI_SSITDR8_DMA					0xEC241208	// R/W	32	Transmit data register 8
#define	SSI_SSIRDR8_DMA					0xEC24120C	// R	32	Receive data register 8
#define	SSI_SSITDR9_DMA					0xEC241248	// R/W	32	Transmit data register 9
#define	SSI_SSIRDR9_DMA					0xEC24124C	// R	32	Receive data register 9



//SSIU
#define	SSIU_SSI_MODE0					0xEC540800	// R/W	32	SSI mode register 0
#define	SSIU_SSI_MODE1					0xEC540804	// R/W	32	SSI mode register 1
#define	SSIU_SSI_MODE2					0xEC540808	// R/W	32	SSI mode register 2
#define	SSIU_SSI_MODE3					0xEC54080C	// R/W	32	SSI mode register 3
#define	SSIU_SSI_CONTROL				0xEC540810	// R/W	32	SSI control register
#define	SSIU_SSI_CONTROL2				0xEC540814	// R/W	32	SSI control register2


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


//VIN
#define	VIN_V0MC						0xE6EF0000	// R/W	32	Video 0 main control register
#define	VIN_V0MS						0xE6EF0004	// R	32	Video 0 module status register
#define	VIN_V0FC						0xE6EF0008	// R/W	32	Video 0 frame capture register
#define	VIN_V0SLPrC						0xE6EF000C	// R/W	32	Video 0 start line pre-clip register
#define	VIN_V0ELPrC						0xE6EF0010	// R/W	32	Video 0 end line pre-clip register
#define	VIN_V0SPPrC						0xE6EF0014	// R/W	32	Video 0 start pixel pre-clip register
#define	VIN_V0EPPrC						0xE6EF0018	// R/W	32	Video 0 end pixel pre-clip register
#define	VIN_V0CSI_IFMD					0xE6EF0020	// R/W	32	Video 0 CSI input control register 
#define	VIN_V0IS						0xE6EF002C	// R/W	32	Video 0 image stride register
#define	VIN_V0MB1						0xE6EF0030	// R/W	32	Video 0 memory base 1 register
#define	VIN_V0MB2						0xE6EF0034	// R/W	32	Video 0 memory base 2 register
#define	VIN_V0MB3						0xE6EF0038	// R/W	32	Video 0 memory base 3 register
#define	VIN_V0LC						0xE6EF003C	// R	32	Video 0 line count register
#define	VIN_V0IE						0xE6EF0040	// R/W	32	Video 0 interrupt enable register
#define	VIN_V0INTS						0xE6EF0044	// R/W	32	Video 0 interrupt status register
#define	VIN_V0SI						0xE6EF0048	// R/W	32	Video 0 scanline interrupt register
#define	VIN_V0DMR						0xE6EF0058	// R/W	32	Video 0 data mode register
#define	VIN_V0DMR2						0xE6EF005C	// R/W	32	Video 0 data mode register 2
#define	VIN_V0UVAOF						0xE6EF0060	// R/W	32	Video 0 UV address offset register
#define	VIN_V0CSCC1						0xE6EF0064	// R/W	32	Video 0 color space change coefficient 1 register
#define	VIN_V0CSCC2						0xE6EF0068	// R/W	32	Video 0 color space change coefficient 2 register
#define	VIN_V0CSCC3						0xE6EF006C	// R/W	32	Video 0 color space change coefficient 3 register
#define	VIN_V0UDS_CTRL					0xE6EF0080	// R/W	32	Video 0 scaling control register
#define	VIN_V0UDS_SCALE					0xE6EF0084	// R/W	32	Video 0 scaling factor register
#define	VIN_V0UDS_PASS_BWIDTH			0xE6EF0090	// R/W	32	Video 0 passband register
#define	VIN_V0UDS_IPC					0xE6EF0098	// R/W	32	Video 0 2D IPC setting register
#define	VIN_V0UDS_CLIP_SIZE				0xE6EF00A4	// R/W	32	Video 0 UDS output size clipping register
#define	VIN_V0LUTP						0xE6EF0100	// R/W	32	Video 0 lookup table pointer
#define	VIN_V0LUTD						0xE6EF0104	// R/W	32	Video 0 lookup table data register
#define	VIN_V0YCCR1						0xE6EF0228	// R/W	32	Video 0 RGB->Y calculation setting register 1
#define	VIN_V0YCCR2						0xE6EF022C	// R/W	32	Video 0 RGB->Y calculation setting register 2
#define	VIN_V0YCCR3						0xE6EF0230	// R/W	32	Video 0 RGB->Y calculation setting register 3
#define	VIN_V0CBCCR1					0xE6EF0234	// R/W	32	Video 0 RGB->Cb calculation setting register 1
#define	VIN_V0CBCCR2					0xE6EF0238	// R/W	32	Video 0 RGB->Cb calculation setting register 2
#define	VIN_V0CBCCR3					0xE6EF023C	// R/W	32	Video 0 RGB->Cb calculation setting register 3
#define	VIN_V0CRCCR1					0xE6EF0240	// R/W	32	Video 0 RGB->Cr calculation setting register 1
#define	VIN_V0CRCCR2					0xE6EF0244	// R/W	32	Video 0 RGB->Cr calculation setting register 2
#define	VIN_V0CRCCR3					0xE6EF0248	// R/W	32	Video 0 RGB->Cr calculation setting register 3
#define	VIN_V0CSCE1						0xE6EF0300	// R/W	32	Video 0 YC->RGB calculation setting register 1
#define	VIN_V0CSCE2						0xE6EF0304	// R/W	32	Video 0 YC->RGB calculation setting register 2
#define	VIN_V0CSCE3						0xE6EF0308	// R/W	32	Video 0 YC->RGB calculation setting register 3
#define	VIN_V0CSCE4						0xE6EF030C	// R/W	32	Video 0 YC->RGB calculation setting register 4
#define	VIN_V4MC						0xE6EF4000	// R/W	32	Video 4 main control register
#define	VIN_V4MS						0xE6EF4004	// R	32	Video 4 module status register
#define	VIN_V4FC						0xE6EF4008	// R/W	32	Video 4 frame capture register
#define	VIN_V4SLPrC						0xE6EF400C	// R/W	32	Video 4 start line pre-clip register
#define	VIN_V4ELPrC						0xE6EF4010	// R/W	32	Video 4 end line pre-clip register
#define	VIN_V4SPPrC						0xE6EF4014	// R/W	32	Video 4 start pixel pre-clip register
#define	VIN_V4EPPrC						0xE6EF4018	// R/W	32	Video 4 end pixel pre-clip register
#define	VIN_V4CSI_IFMD					0xE6EF4020	// R/W	32	Video 4 CSI input control register 
#define	VIN_V4IS						0xE6EF402C	// R/W	32	Video 4 image stride register
#define	VIN_V4MB1						0xE6EF4030	// R/W	32	Video 4 memory base 1 register
#define	VIN_V4MB2						0xE6EF4034	// R/W	32	Video 4 memory base 2 register
#define	VIN_V4MB3						0xE6EF4038	// R/W	32	Video 4 memory base 3 register
#define	VIN_V4LC						0xE6EF403C	// R	32	Video 4 line count register
#define	VIN_V4IE						0xE6EF4040	// R/W	32	Video 4 interrupt enable register
#define	VIN_V4INTS						0xE6EF4044	// R/W	32	Video 4 interrupt status register
#define	VIN_V4SI						0xE6EF4048	// R/W	32	Video 4 scanline interrupt register
#define	VIN_V4DMR						0xE6EF4058	// R/W	32	Video 4 data mode register
#define	VIN_V4DMR2						0xE6EF405C	// R/W	32	Video 4 data mode register 2
#define	VIN_V4UVAOF						0xE6EF4060	// R/W	32	Video 4 UV address offset register
#define	VIN_V4CSCC1						0xE6EF4064	// R/W	32	Video 4 color space change coefficient 1 register
#define	VIN_V4CSCC2						0xE6EF4068	// R/W	32	Video 4 color space change coefficient 2 register
#define	VIN_V4CSCC3						0xE6EF406C	// R/W	32	Video 4 color space change coefficient 3 register
#define	VIN_V4UDS_CTRL					0xE6EF4080	// R/W	32	Video 4 scaling control register
#define	VIN_V4UDS_SCALE					0xE6EF4084	// R/W	32	Video 4 scaling factor register
#define	VIN_V4UDS_PASS_BWIDTH			0xE6EF4090	// R/W	32	Video 4 passband register
#define	VIN_V4UDS_IPC					0xE6EF4098	// R/W	32	Video 4 2D IPC setting register
#define	VIN_V4UDS_CLIP_SIZE				0xE6EF40A4	// R/W	32	Video 4 UDS output size clipping register
#define	VIN_V4LUTP						0xE6EF4100	// R/W	32	Video 4 lookup table pointer
#define	VIN_V4LUTD						0xE6EF4104	// R/W	32	Video 4 lookup table data register
#define	VIN_V4YCCR1						0xE6EF4228	// R/W	32	Video 4 RGB->Y calculation setting register 1
#define	VIN_V4YCCR2						0xE6EF422C	// R/W	32	Video 4 RGB->Y calculation setting register 2
#define	VIN_V4YCCR3						0xE6EF4230	// R/W	32	Video 4 RGB->Y calculation setting register 3
#define	VIN_V4CBCCR1					0xE6EF4234	// R/W	32	Video 4 RGB->Cb calculation setting register 1
#define	VIN_V4CBCCR2					0xE6EF4238	// R/W	32	Video 4 RGB->Cb calculation setting register 2
#define	VIN_V4CBCCR3					0xE6EF423C	// R/W	32	Video 4 RGB->Cb calculation setting register 3
#define	VIN_V4CRCCR1					0xE6EF4240	// R/W	32	Video 4 RGB->Cr calculation setting register 1
#define	VIN_V4CRCCR2					0xE6EF4244	// R/W	32	Video 4 RGB->Cr calculation setting register 2
#define	VIN_V4CRCCR3					0xE6EF4248	// R/W	32	Video 4 RGB->Cr calculation setting register 3
#define	VIN_V4CSCE1						0xE6EF4300	// R/W	32	Video 4 YC->RGB calculation setting register 1
#define	VIN_V4CSCE2						0xE6EF4304	// R/W	32	Video 4 YC->RGB calculation setting register 2
#define	VIN_V4CSCE3						0xE6EF4308	// R/W	32	Video 4 YC->RGB calculation setting register 3
#define	VIN_V4CSCE4						0xE6EF430C	// R/W	32	Video 4 YC->RGB calculation setting register 4
#define	VIN_V1MC						0xE6EF1000	// R/W	32	Video 1 main control register
#define	VIN_V1MS						0xE6EF1004	// R	32	Video 1 module status register
#define	VIN_V1FC						0xE6EF1008	// R/W	32	Video 1 frame capture register
#define	VIN_V1SLPrC						0xE6EF100C	// R/W	32	Video 1 start line pre-clip register
#define	VIN_V1ELPrC						0xE6EF1010	// R/W	32	Video 1 end line pre-clip register
#define	VIN_V1SPPrC						0xE6EF1014	// R/W	32	Video 1 start pixel pre-clip register
#define	VIN_V1EPPrC						0xE6EF1018	// R/W	32	Video 1 end pixel pre-clip register
#define	VIN_V1IS						0xE6EF102C	// R/W	32	Video 1 image stride register
#define	VIN_V1MB1						0xE6EF1030	// R/W	32	Video 1 memory base 1 register
#define	VIN_V1MB2						0xE6EF1034	// R/W	32	Video 1 memory base 2 register
#define	VIN_V1MB3						0xE6EF1038	// R/W	32	Video 1 memory base 3 register
#define	VIN_V1LC						0xE6EF103C	// R	32	Video 1 line count register
#define	VIN_V1IE						0xE6EF1040	// R/W	32	Video 1 interrupt enable register
#define	VIN_V1INTS						0xE6EF1044	// R/W	32	Video 1 interrupt status register
#define	VIN_V1SI						0xE6EF1048	// R/W	32	Video 1 scanline interrupt register
#define	VIN_V1DMR						0xE6EF1058	// R/W	32	Video 1 data mode register
#define	VIN_V1DMR2						0xE6EF105C	// R/W	32	Video 1 data mode register 2
#define	VIN_V1UVAOF						0xE6EF1060	// R/W	32	Video 1 UV address offset register
#define	VIN_V1CSCC1						0xE6EF1064	// R/W	32	Video 1 color space change coefficient 1 register
#define	VIN_V1CSCC2						0xE6EF1068	// R/W	32	Video 1 color space change coefficient 2 register
#define	VIN_V1CSCC3						0xE6EF106C	// R/W	32	Video 1 color space change coefficient 3 register
#define	VIN_V1UDS_CTRL					0xE6EF1080	// R/W	32	Video 1 scaling control register
#define	VIN_V1UDS_SCALE					0xE6EF1084	// R/W	32	Video 1 scaling factor register
#define	VIN_V1UDS_ALPTH					0xE6EF1088	// R/W	32	Video 1 alpha data threshold setting register
#define	VIN_V1UDS_ALPVAL				0xE6EF108C	// R/W	32	Video 1 alpha data replacing value setting register
#define	VIN_V1UDS_PASS_BWIDTH			0xE6EF1090	// R/W	32	Video 1 passband register
#define	VIN_V1UDS_IPC					0xE6EF1098	// R/W	32	Video 1 2D IPC setting register
#define	VIN_V1UDS_CLIP_SIZE				0xE6EF10A4	// R/W	32	Video 1 UDS output size clipping register
#define	VIN_V1LUTP						0xE6EF1100	// R/W	32	Video 1 lookup table pointer
#define	VIN_V1LUTD						0xE6EF1104	// R/W	32	Video 1 lookup table data register
#define	VIN_V1YCCR1						0xE6EF1228	// R/W	32	Video 1 RGB->Y calculation setting register 1
#define	VIN_V1YCCR2						0xE6EF122C	// R/W	32	Video 1 RGB->Y calculation setting register 2
#define	VIN_V1YCCR3						0xE6EF1230	// R/W	32	Video 1 RGB->Y calculation setting register 3
#define	VIN_V1CBCCR1					0xE6EF1234	// R/W	32	Video 1 RGB->Cb calculation setting register 1
#define	VIN_V1CBCCR2					0xE6EF1238	// R/W	32	Video 1 RGB->Cb calculation setting register 2
#define	VIN_V1CBCCR3					0xE6EF123C	// R/W	32	Video 1 RGB->Cb calculation setting register 3
#define	VIN_V1CRCCR1					0xE6EF1240	// R/W	32	Video 1 RGB->Cr calculation setting register 1
#define	VIN_V1CRCCR2					0xE6EF1244	// R/W	32	Video 1 RGB->Cr calculation setting register 2
#define	VIN_V1CRCCR3					0xE6EF1248	// R/W	32	Video 1 RGB->Cr calculation setting register 3
#define	VIN_V1CSCE1						0xE6EF1300	// R/W	32	Video 1 YC->RGB calculation setting register 1
#define	VIN_V1CSCE2						0xE6EF1304	// R/W	32	Video 1 YC->RGB calculation setting register 2
#define	VIN_V1CSCE3						0xE6EF1308	// R/W	32	Video 1 YC->RGB calculation setting register 3
#define	VIN_V1CSCE4						0xE6EF130C	// R/W	32	Video 1 YC->RGB calculation setting register 4
#define	VIN_V5MC						0xE6EF5000	// R/W	32	Video 5 main control register
#define	VIN_V5MS						0xE6EF5004	// R	32	Video 5 module status register
#define	VIN_V5FC						0xE6EF5008	// R/W	32	Video 5 frame capture register
#define	VIN_V5SLPrC						0xE6EF500C	// R/W	32	Video 5 start line pre-clip register
#define	VIN_V5ELPrC						0xE6EF5010	// R/W	32	Video 5 end line pre-clip register
#define	VIN_V5SPPrC						0xE6EF5014	// R/W	32	Video 5 start pixel pre-clip register
#define	VIN_V5EPPrC						0xE6EF5018	// R/W	32	Video 5 end pixel pre-clip register
#define	VIN_V5IS						0xE6EF502C	// R/W	32	Video 5 image stride register
#define	VIN_V5MB1						0xE6EF5030	// R/W	32	Video 5 memory base 1 register
#define	VIN_V5MB2						0xE6EF5034	// R/W	32	Video 5 memory base 2 register
#define	VIN_V5MB3						0xE6EF5038	// R/W	32	Video 5 memory base 3 register
#define	VIN_V5LC						0xE6EF503C	// R	32	Video 5 line count register
#define	VIN_V5IE						0xE6EF5040	// R/W	32	Video 5 interrupt enable register
#define	VIN_V5INTS						0xE6EF5044	// R/W	32	Video 5 interrupt status register
#define	VIN_V5SI						0xE6EF5048	// R/W	32	Video 5 scanline interrupt register
#define	VIN_V5DMR						0xE6EF5058	// R/W	32	Video 5 data mode register
#define	VIN_V5DMR2						0xE6EF505C	// R/W	32	Video 5 data mode register 2
#define	VIN_V5UVAOF						0xE6EF5060	// R/W	32	Video 5 UV address offset register
#define	VIN_V5CSCC1						0xE6EF5064	// R/W	32	Video 5 color space change coefficient 1 register
#define	VIN_V5CSCC2						0xE6EF5068	// R/W	32	Video 5 color space change coefficient 2 register
#define	VIN_V5CSCC3						0xE6EF506C	// R/W	32	Video 5 color space change coefficient 3 register
#define	VIN_V5UDS_CTRL					0xE6EF5080	// R/W	32	Video 5 scaling control register
#define	VIN_V5UDS_SCALE					0xE6EF5084	// R/W	32	Video 5 scaling factor register
#define	VIN_V5UDS_ALPTH					0xE6EF5088	// R/W	32	Video 5 alpha data threshold setting register
#define	VIN_V5UDS_ALPVAL				0xE6EF508C	// R/W	32	Video 5 alpha data replacing value setting register
#define	VIN_V5UDS_PASS_BWIDTH			0xE6EF5090	// R/W	32	Video 5 passband register
#define	VIN_V5UDS_IPC					0xE6EF5098	// R/W	32	Video 5 2D IPC setting register
#define	VIN_V5UDS_CLIP_SIZE				0xE6EF50A4	// R/W	32	Video 5 UDS output size clipping register
#define	VIN_V5LUTP						0xE6EF5100	// R/W	32	Video 5 lookup table pointer
#define	VIN_V5LUTD						0xE6EF5104	// R/W	32	Video 5 lookup table data register
#define	VIN_V5YCCR1						0xE6EF5228	// R/W	32	Video 5 RGB->Y calculation setting register 1
#define	VIN_V5YCCR2						0xE6EF522C	// R/W	32	Video 5 RGB->Y calculation setting register 2
#define	VIN_V5YCCR3						0xE6EF5230	// R/W	32	Video 5 RGB->Y calculation setting register 3
#define	VIN_V5CBCCR1					0xE6EF5234	// R/W	32	Video 5 RGB->Cb calculation setting register 1
#define	VIN_V5CBCCR2					0xE6EF5238	// R/W	32	Video 5 RGB->Cb calculation setting register 2
#define	VIN_V5CBCCR3					0xE6EF523C	// R/W	32	Video 5 RGB->Cb calculation setting register 3
#define	VIN_V5CRCCR1					0xE6EF5240	// R/W	32	Video 5 RGB->Cr calculation setting register 1
#define	VIN_V5CRCCR2					0xE6EF5244	// R/W	32	Video 5 RGB->Cr calculation setting register 2
#define	VIN_V5CRCCR3					0xE6EF5248	// R/W	32	Video 5 RGB->Cr calculation setting register 3
#define	VIN_V5CSCE1						0xE6EF5300	// R/W	32	Video 5 YC->RGB calculation setting register 1
#define	VIN_V5CSCE2						0xE6EF5304	// R/W	32	Video 5 YC->RGB calculation setting register 2
#define	VIN_V5CSCE3						0xE6EF5308	// R/W	32	Video 5 YC->RGB calculation setting register 3
#define	VIN_V5CSCE4						0xE6EF530C	// R/W	32	Video 5 YC->RGB calculation setting register 4
#define	VIN_V2MC						0xE6EF2000	// R/W	32	Video 2 main control register
#define	VIN_V2MS						0xE6EF2004	// R	32	Video 2 module status register
#define	VIN_V2FC						0xE6EF2008	// R/W	32	Video 2 frame capture register
#define	VIN_V2SLPrC						0xE6EF200C	// R/W	32	Video 2 start line pre-clip register
#define	VIN_V2ELPrC						0xE6EF2010	// R/W	32	Video 2 end line pre-clip register
#define	VIN_V2SPPrC						0xE6EF2014	// R/W	32	Video 2 start pixel pre-clip register
#define	VIN_V2EPPrC						0xE6EF2018	// R/W	32	Video 2 end pixel pre-clip register
#define	VIN_V2IS						0xE6EF202C	// R/W	32	Video 2 image stride register
#define	VIN_V2MB1						0xE6EF2030	// R/W	32	Video 2 memory base 1 register
#define	VIN_V2MB2						0xE6EF2034	// R/W	32	Video 2 memory base 2 register
#define	VIN_V2MB3						0xE6EF2038	// R/W	32	Video 2 memory base 3 register
#define	VIN_V2LC						0xE6EF203C	// R	32	Video 2 line count register
#define	VIN_V2IE						0xE6EF2040	// R/W	32	Video 2 interrupt enable register
#define	VIN_V2INTS						0xE6EF2044	// R/W	32	Video 2 interrupt status register
#define	VIN_V2SI						0xE6EF2048	// R/W	32	Video 2 scanline interrupt register
#define	VIN_V2DMR						0xE6EF2058	// R/W	32	Video 2 data mode register
#define	VIN_V2DMR2						0xE6EF205C	// R/W	32	Video 2 data mode register 2
#define	VIN_V2UVAOF						0xE6EF2060	// R/W	32	Video 2 UV address offset register
#define	VIN_V2CSCC1						0xE6EF2064	// R/W	32	Video 2 color space change coefficient 1 register
#define	VIN_V2CSCC2						0xE6EF2068	// R/W	32	Video 2 color space change coefficient 2 register
#define	VIN_V2CSCC3						0xE6EF206C	// R/W	32	Video 2 color space change coefficient 3 register
#define	VIN_V2LUTP						0xE6EF2100	// R/W	32	Video 2 lookup table pointer
#define	VIN_V2LUTD						0xE6EF2104	// R/W	32	Video 2 lookup table data register
#define	VIN_V2YCCR1						0xE6EF2228	// R/W	32	Video 2 RGB->Y calculation setting register 1
#define	VIN_V2YCCR2						0xE6EF222C	// R/W	32	Video 2 RGB->Y calculation setting register 2
#define	VIN_V2YCCR3						0xE6EF2230	// R/W	32	Video 2 RGB->Y calculation setting register 3
#define	VIN_V2CBCCR1					0xE6EF2234	// R/W	32	Video 2 RGB->Cb calculation setting register 1
#define	VIN_V2CBCCR2					0xE6EF2238	// R/W	32	Video 2 RGB->Cb calculation setting register 2
#define	VIN_V2CBCCR3					0xE6EF223C	// R/W	32	Video 2 RGB->Cb calculation setting register 3
#define	VIN_V2CRCCR1					0xE6EF2240	// R/W	32	Video 2 RGB->Cr calculation setting register 1
#define	VIN_V2CRCCR2					0xE6EF2244	// R/W	32	Video 2 RGB->Cr calculation setting register 2
#define	VIN_V2CRCCR3					0xE6EF2248	// R/W	32	Video 2 RGB->Cr calculation setting register 3
#define	VIN_V6MC						0xE6EF6000	// R/W	32	Video 6 main control register
#define	VIN_V6MS						0xE6EF6004	// R	32	Video 6 module status register
#define	VIN_V6FC						0xE6EF6008	// R/W	32	Video 6 frame capture register
#define	VIN_V6SLPrC						0xE6EF600C	// R/W	32	Video 6 start line pre-clip register
#define	VIN_V6ELPrC						0xE6EF6010	// R/W	32	Video 6 end line pre-clip register
#define	VIN_V6SPPrC						0xE6EF6014	// R/W	32	Video 6 start pixel pre-clip register
#define	VIN_V6EPPrC						0xE6EF6018	// R/W	32	Video 6 end pixel pre-clip register
#define	VIN_V6IS						0xE6EF602C	// R/W	32	Video 6 image stride register
#define	VIN_V6MB1						0xE6EF6030	// R/W	32	Video 6 memory base 1 register
#define	VIN_V6MB2						0xE6EF6034	// R/W	32	Video 6 memory base 2 register
#define	VIN_V6MB3						0xE6EF6038	// R/W	32	Video 6 memory base 3 register
#define	VIN_V6LC						0xE6EF603C	// R	32	Video 6 line count register
#define	VIN_V6IE						0xE6EF6040	// R/W	32	Video 6 interrupt enable register
#define	VIN_V6INTS						0xE6EF6044	// R/W	32	Video 6 interrupt status register
#define	VIN_V6SI						0xE6EF6048	// R/W	32	Video 6 scanline interrupt register
#define	VIN_V6DMR						0xE6EF6058	// R/W	32	Video 6 data mode register
#define	VIN_V6DMR2						0xE6EF605C	// R/W	32	Video 6 data mode register 2
#define	VIN_V6UVAOF						0xE6EF6060	// R/W	32	Video 6 UV address offset register
#define	VIN_V6CSCC1						0xE6EF6064	// R/W	32	Video 6 color space change coefficient 1 register
#define	VIN_V6CSCC2						0xE6EF6068	// R/W	32	Video 6 color space change coefficient 2 register
#define	VIN_V6CSCC3						0xE6EF606C	// R/W	32	Video 6 color space change coefficient 3 register
#define	VIN_V6LUTP						0xE6EF6100	// R/W	32	Video 6 lookup table pointer
#define	VIN_V6LUTD						0xE6EF6104	// R/W	32	Video 6 lookup table data register
#define	VIN_V6YCCR1						0xE6EF6228	// R/W	32	Video 6 RGB->Y calculation setting register 1
#define	VIN_V6YCCR2						0xE6EF622C	// R/W	32	Video 6 RGB->Y calculation setting register 2
#define	VIN_V6YCCR3						0xE6EF6230	// R/W	32	Video 6 RGB->Y calculation setting register 3
#define	VIN_V6CBCCR1					0xE6EF6234	// R/W	32	Video 6 RGB->Cb calculation setting register 1
#define	VIN_V6CBCCR2					0xE6EF6238	// R/W	32	Video 6 RGB->Cb calculation setting register 2
#define	VIN_V6CBCCR3					0xE6EF623C	// R/W	32	Video 6 RGB->Cb calculation setting register 3
#define	VIN_V6CRCCR1					0xE6EF6240	// R/W	32	Video 6 RGB->Cr calculation setting register 1
#define	VIN_V6CRCCR2					0xE6EF6244	// R/W	32	Video 6 RGB->Cr calculation setting register 2
#define	VIN_V6CRCCR3					0xE6EF6248	// R/W	32	Video 6 RGB->Cr calculation setting register 3
#define	VIN_V3MC						0xE6EF3000	// R/W	32	Video 3 main control register
#define	VIN_V3MS						0xE6EF3004	// R	32	Video 3 module status register
#define	VIN_V3FC						0xE6EF3008	// R/W	32	Video 3 frame capture register
#define	VIN_V3SLPrC						0xE6EF300C	// R/W	32	Video 3 start line pre-clip register
#define	VIN_V3ELPrC						0xE6EF3010	// R/W	32	Video 3 end line pre-clip register
#define	VIN_V3SPPrC						0xE6EF3014	// R/W	32	Video 3 start pixel pre-clip register
#define	VIN_V3EPPrC						0xE6EF3018	// R/W	32	Video 3 end pixel pre-clip register
#define	VIN_V3IS						0xE6EF302C	// R/W	32	Video 3 image stride register
#define	VIN_V3MB1						0xE6EF3030	// R/W	32	Video 3 memory base 1 register
#define	VIN_V3MB2						0xE6EF3034	// R/W	32	Video 3 memory base 2 register
#define	VIN_V3MB3						0xE6EF3038	// R/W	32	Video 3 memory base 3 register
#define	VIN_V3LC						0xE6EF303C	// R	32	Video 3 line count register
#define	VIN_V3IE						0xE6EF3040	// R/W	32	Video 3 interrupt enable register
#define	VIN_V3INTS						0xE6EF3044	// R/W	32	Video 3 interrupt status register
#define	VIN_V3SI						0xE6EF3048	// R/W	32	Video 3 scanline interrupt register
#define	VIN_V3DMR						0xE6EF3058	// R/W	32	Video 3 data mode register
#define	VIN_V3DMR2						0xE6EF305C	// R/W	32	Video 3 data mode register 2
#define	VIN_V3UVAOF						0xE6EF3060	// R/W	32	Video 3 UV address offset register
#define	VIN_V3CSCC1						0xE6EF3064	// R/W	32	Video 3 color space change coefficient 1 register
#define	VIN_V3CSCC2						0xE6EF3068	// R/W	32	Video 3 color space change coefficient 2 register
#define	VIN_V3CSCC3						0xE6EF306C	// R/W	32	Video 3 color space change coefficient 3 register
#define	VIN_V7MC						0xE6EF7000	// R/W	32	Video 7 main control register
#define	VIN_V7MS						0xE6EF7004	// R	32	Video 7 module status register
#define	VIN_V7FC						0xE6EF7008	// R/W	32	Video 7 frame capture register
#define	VIN_V7SLPrC						0xE6EF700C	// R/W	32	Video 7 start line pre-clip register
#define	VIN_V7ELPrC						0xE6EF7010	// R/W	32	Video 7 end line pre-clip register
#define	VIN_V7SPPrC						0xE6EF7014	// R/W	32	Video 7 start pixel pre-clip register
#define	VIN_V7EPPrC						0xE6EF7018	// R/W	32	Video 7 end pixel pre-clip register
#define	VIN_V7IS						0xE6EF702C	// R/W	32	Video 7 image stride register
#define	VIN_V7MB1						0xE6EF7030	// R/W	32	Video 7 memory base 1 register
#define	VIN_V7MB2						0xE6EF7034	// R/W	32	Video 7 memory base 2 register
#define	VIN_V7MB3						0xE6EF7038	// R/W	32	Video 7 memory base 3 register
#define	VIN_V7LC						0xE6EF703C	// R	32	Video 7 line count register
#define	VIN_V7IE						0xE6EF7040	// R/W	32	Video 7 interrupt enable register
#define	VIN_V7INTS						0xE6EF7044	// R/W	32	Video 7 interrupt status register
#define	VIN_V7SI						0xE6EF7048	// R/W	32	Video 7 scanline interrupt register
#define	VIN_V7DMR						0xE6EF7058	// R/W	32	Video 7 data mode register
#define	VIN_V7DMR2						0xE6EF705C	// R/W	32	Video 7 data mode register 2
#define	VIN_V7UVAOF						0xE6EF7060	// R/W	32	Video 7 UV address offset register
#define	VIN_V7CSCC1						0xE6EF7064	// R/W	32	Video 7 color space change coefficient 1 register
#define	VIN_V7CSCC2						0xE6EF7068	// R/W	32	Video 7 color space change coefficient 2 register
#define	VIN_V7CSCC3						0xE6EF706C	// R/W	32	Video 7 color space change coefficient 3 register


//VSPD0
#define	VSPD0_VI6_CMD0					0xFEA20000	// R/W	32	General control registers
#define	VSPD0_VI6_CMD1					0xFEA20004	// R/W	32	General control registers
#define	VSPD0_VI6_CLK_DCSWT 			0xFEA20018	// R/W	32	General control registers
#define	VSPD0_VI6_SRESET				0xFEA20028	// R/W	32	General control registers
#define	VSPD0_VI6_STATUS				0xFEA20038	// R	32	General control registers
#define	VSPD0_VI6_WPF0_IRQ_ENB			0xFEA20048	// R/W	32	General control registers
#define	VSPD0_VI6_WPF0_IRQ_STA			0xFEA2004c	// R/W	32	General control registers
#define	VSPD0_VI6_WPF1_IRQ_ENB			0xFEA20054	// R/W	32	General control registers
#define	VSPD0_VI6_WPF1_IRQ_STA			0xFEA20058	// R/W	32	General control registers
#define	VSPD0_VI6_DISP_IRQ_ENB			0xFEA20078	// R/W	32	General control registers
#define	VSPD0_VI6_DISP_IRQ_STA			0xFEA2007c	// R/W	32	General control registers
#define	VSPD0_VI6_DL_CTRL				0xFEA20100	// R/W	32	Display list control registers
#define	VSPD0_VI6_DL_HDR_ADDR0			0xFEA20104	// R	32	Display list control registers
#define	VSPD0_VI6_DL_HDR_ADDR1			0xFEA20108	// R	32	Display list control registers
#define	VSPD0_VI6_DL_SWAP				0xFEA20114	// R/W	32	Display list control registers
#define	VSPD0_VI6_DL_EXT_CTRL 			0xFEA2011c	// R/W	32	Display list control registers
#define	VSPD0_VI6_DL_BODY_SIZE0 		0xFEA20120	// R/W	32	Display list control registers
#define	VSPD0_VI6_RPF0_SRC_BSIZE		0xFEA20300	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRC_BSIZE		0xFEA20400	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRC_BSIZE		0xFEA20500	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRC_BSIZE		0xFEA20600	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRC_BSIZE		0xFEA20700	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRC_ESIZE		0xFEA20304	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRC_ESIZE		0xFEA20404	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRC_ESIZE		0xFEA20504	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRC_ESIZE		0xFEA20604	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRC_ESIZE		0xFEA20704	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_INFMT			0xFEA20308	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_INFMT			0xFEA20408	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_INFMT			0xFEA20508	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_INFMT			0xFEA20608	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_INFMT			0xFEA20708	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_DSWAP			0xFEA2030C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_DSWAP			0xFEA2040C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_DSWAP			0xFEA2050C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_DSWAP			0xFEA2060C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_DSWAP			0xFEA2070C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_LOC				0xFEA20310	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_LOC				0xFEA20410	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_LOC				0xFEA20510	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_LOC				0xFEA20610	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_LOC				0xFEA20710	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_ALPH_SEL			0xFEA20314	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_ALPH_SEL			0xFEA20414	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_ALPH_SEL			0xFEA20514	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_ALPH_SEL			0xFEA20614	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_ALPH_SEL			0xFEA20714	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_VRTCOL_SET		0xFEA20318	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_VRTCOL_SET		0xFEA20418	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_VRTCOL_SET		0xFEA20518	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_VRTCOL_SET		0xFEA20618	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_VRTCOL_SET		0xFEA20718	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_MSKCTRL			0xFEA2031C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_MSKCTRL			0xFEA2041C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_MSKCTRL			0xFEA2051C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_MSKCTRL			0xFEA2061C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_MSKCTRL			0xFEA2071C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_MSKSET0			0xFEA20320	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_MSKSET0			0xFEA20420	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_MSKSET0			0xFEA20520	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_MSKSET0			0xFEA20620	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_MSKSET0			0xFEA20720	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_MSKSET1			0xFEA20324	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_MSKSET1			0xFEA20424	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_MSKSET1			0xFEA20524	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_MSKSET1			0xFEA20624	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_MSKSET1			0xFEA20724	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_CKEY_CTRL		0xFEA20328	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_CKEY_CTRL		0xFEA20428	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_CKEY_CTRL		0xFEA20528	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_CKEY_CTRL		0xFEA20628	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_CKEY_CTRL		0xFEA20728	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_CKEY_SET0		0xFEA2032C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_CKEY_SET0		0xFEA2042C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_CKEY_SET0		0xFEA2052C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_CKEY_SET0		0xFEA2062C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_CKEY_SET0		0xFEA2072C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_CKEY_SET1		0xFEA20330	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_CKEY_SET1		0xFEA20430	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_CKEY_SET1		0xFEA20530	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_CKEY_SET1		0xFEA20630	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_CKEY_SET1		0xFEA20730	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_PSTRIDE		0xFEA20334	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_PSTRIDE		0xFEA20434	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_PSTRIDE		0xFEA20534	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_PSTRIDE		0xFEA20634	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_PSTRIDE		0xFEA20734	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_ASTRIDE		0xFEA20338	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_ASTRIDE		0xFEA20438	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_ASTRIDE		0xFEA20538	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_ASTRIDE		0xFEA20638	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_ASTRIDE		0xFEA20738	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_ADDR_Y		0xFEA2033C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_ADDR_Y		0xFEA2043C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_ADDR_Y		0xFEA2053C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_ADDR_Y		0xFEA2063C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_ADDR_Y		0xFEA2073C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_ADDR_C0		0xFEA20340	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_ADDR_C0		0xFEA20440	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_ADDR_C0		0xFEA20540	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_ADDR_C0		0xFEA20640	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_ADDR_C0		0xFEA20740	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_ADDR_C1		0xFEA20344	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_ADDR_C1		0xFEA20444	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_ADDR_C1		0xFEA20544	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_ADDR_C1		0xFEA20644	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_ADDR_C1		0xFEA20744	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_SRCM_ADDR_AI		0xFEA20348	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_SRCM_ADDR_AI		0xFEA20448	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_SRCM_ADDR_AI		0xFEA20548	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_SRCM_ADDR_AI		0xFEA20648	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_SRCM_ADDR_AI		0xFEA20748	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF0_MULT_ALPHA		0xFEA2036C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF1_MULT_ALPHA		0xFEA2046C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF2_MULT_ALPHA		0xFEA2056C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF3_MULT_ALPHA		0xFEA2066C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_RPF4_MULT_ALPHA		0xFEA2076C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD0_VI6_WPF0_SRCRPF			0xFEA21000	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_SRCRPF			0xFEA21100	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_SRCRPF			0xFEA21200	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_SRCRPF			0xFEA21300	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_HSZCLIP			0xFEA21004	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_HSZCLIP			0xFEA21104	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_HSZCLIP			0xFEA21204	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_HSZCLIP			0xFEA21304	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_VSZCLIP			0xFEA21008	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_VSZCLIP			0xFEA21108	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_VSZCLIP			0xFEA21208	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_VSZCLIP			0xFEA21308	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_OUTFMT			0xFEA2100C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_OUTFMT			0xFEA2110C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_OUTFMT			0xFEA2120C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_OUTFMT			0xFEA2130C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSWAP			0xFEA21010	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSWAP			0xFEA21110	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSWAP			0xFEA21210	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSWAP			0xFEA21310	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_RNDCTRL			0xFEA21014	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_RNDCTRL			0xFEA21114	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_RNDCTRL			0xFEA21214	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_RNDCTRL			0xFEA21314	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_ROT_CTRL			0xFEA21018	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_ROT_CTRL			0xFEA21118	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_ROT_CTRL			0xFEA21218	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_ROT_CTRL			0xFEA21318	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSTM_STRIDE_Y	0xFEA2101C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSTM_STRIDE_Y	0xFEA2111C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSTM_STRIDE_Y	0xFEA2121C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSTM_STRIDE_Y	0xFEA2131C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSTM_STRIDE_C	0xFEA21020	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSTM_STRIDE_C	0xFEA21120	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSTM_STRIDE_C	0xFEA21220	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSTM_STRIDE_C	0xFEA21320	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSTM_ADDR_Y		0xFEA21024	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSTM_ADDR_Y		0xFEA21124	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSTM_ADDR_Y		0xFEA21224	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSTM_ADDR_Y		0xFEA21324	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSTM_ADDR_C0		0xFEA21028	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSTM_ADDR_C0		0xFEA21128	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSTM_ADDR_C0		0xFEA21228	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSTM_ADDR_C0		0xFEA21328	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_DSTM_ADDR_C1		0xFEA2102C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF1_DSTM_ADDR_C1		0xFEA2112C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF2_DSTM_ADDR_C1		0xFEA2122C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF3_DSTM_ADDR_C1		0xFEA2132C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD0_VI6_WPF0_WRBCK_CTRL 		0xFEA21034	// R/W	32	WPF0 control register
#define	VSPD0_UIF_REG_0					0xFEA21800	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD0_UIF_REG_1					0xFEA21900	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD0_UIF_REG_2					0xFEA21A00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD0_UIF_REG_3					0xFEA21B00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD0_UIF_REG_4					0xFEA21C00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD0_VI6_DPR_RPF0_ROUTE		0xFEA22000	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_RPF1_ROUTE		0xFEA22004	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_RPF2_ROUTE		0xFEA22008	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_RPF3_ROUTE		0xFEA2200c	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_RPF4_ROUTE		0xFEA22010	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_WPF0_FPORCH		0xFEA22014	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_WPF1_FPORCH		0xFEA22018	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_SRU_ROUTE			0xFEA22024	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_UDS_ROUTE			0xFEA22028	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_LUT_ROUTE			0xFEA2203c	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_CLU_ROUTE			0xFEA22040	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_HST_ROUTE			0xFEA22044	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_HSI_ROUTE			0xFEA22048	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_BRU_ROUTE			0xFEA2204c	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_HGO_SMPPT 		0xFEA22054	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_HGT_SMPPT 		0xFEA22058	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_SHP_ROUTE			0xFEA22060	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_UIF0_ROUTE 		0xFEA22064	// R/W	32	DPR control registers
#define	VSPD0_VI6_DPR_UIF4_ROUTE		0xFEA22074	// R/W	32	DPR control registers
#define	VSPD0_VI6_SRU_CTRL0				0xFEA22200	// R/W	32	SRU control registers
#define	VSPD0_VI6_SRU_CTRL1				0xFEA22204	// R/W	32	SRU control registers
#define	VSPD0_VI6_SRU_CTRL2				0xFEA22208	// R/W	32	SRU control registers
#define	VSPD0_VI6_UDS_CTRL				0xFEA22300	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_SCALE				0xFEA22304	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_ALPTH				0xFEA22308	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_ALPVAL			0xFEA2230c	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_PASS_BWIDTH		0xFEA22310	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_HPHASE			0xFEA22314	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_VPHASE			0xFEA22318	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_HSZCLIP			0xFEA2231c	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_CLIP_SIZE			0xFEA22324	// R/W	32	UDS control registers
#define	VSPD0_VI6_UDS_FILL_COLOR		0xFEA22328	// R/W	32	UDS control registers
#define	VSPD0_VI6_LUT_CTRL				0xFEA22800	// R/W	32	1D-LUT control register
#define	VSPD0_VI6_CLU_CTRL				0xFEA22900	// R/W	32	3D-LUT control register
#define	VSPD0_VI6_HST_CTRL				0xFEA22a00	// R/W	32	HST control register
#define	VSPD0_VI6_HSI_CTRL				0xFEA22b00	// R/W	32	HSI control register
#define	VSPD0_VI6_BRU_INCTRL			0xFEA22c00	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRU_VIRRPF_SIZE		0xFEA22c04	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRU_VIRRPF_LOC		0xFEA22c08	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRU_VIRRPF_COL		0xFEA22c0c	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUA_CTRL				0xFEA22c10	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUA_BLD				0xFEA22c14	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUB_CTRL				0xFEA22c18	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUB_BLD				0xFEA22c1c	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUC_CTRL				0xFEA22c20	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUC_BLD				0xFEA22c24	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUD_CTRL				0xFEA22c28	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUD_BLD				0xFEA22c2c	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRU_ROP				0xFEA22c30	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUE_CTRL				0xFEA22c34	// R/W	32	BRU control registers
#define	VSPD0_VI6_BRUE_BLD				0xFEA22c38	// R/W	32	BRU control registers
#define	VSPD0_VI6_HGO_OFFSET			0xFEA23000	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_SIZE				0xFEA23004	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_MODE				0xFEA23008	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB_TH				0xFEA2300c	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB0_H				0xFEA23010	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB0_V				0xFEA23014	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB1_H				0xFEA23018	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB1_V				0xFEA2301c	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB2_H				0xFEA23020	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB2_V				0xFEA23024	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB3_H				0xFEA23028	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_LB3_V				0xFEA2302c	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_R_HISTO_n			0xFEA23030	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_R_MAXMIN			0xFEA23130	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_R_SUM				0xFEA23134	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_R_LB_DET			0xFEA23138	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_G_HISTO_n			0xFEA23140	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_G_MAXMIN			0xFEA23240	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_G_SUM				0xFEA23244	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_G_LB_DET			0xFEA23248	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_B_HISTO_n			0xFEA23250	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_B_MAXMIN			0xFEA23350	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_B_SUM				0xFEA23354	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_B_LB_DET			0xFEA23358	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_EXT_HIST_ADDR		0xFEA2335c	// R/W	32	HGO control registers
#define	VSPD0_VI6_HGO_EXT_HIST_DATA		0xFEA23360	// R	32	HGO control registers
#define	VSPD0_VI6_HGO_REGRST			0xFEA233fc	// W	32	HGO control registers
#define	VSPD0_VI6_HGT_OFFSET			0xFEA23400	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_SIZE				0xFEA23404	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_MODE				0xFEA23408	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA0			0xFEA2340c	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA1			0xFEA23410	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA2			0xFEA23414	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA3			0xFEA23418	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA4			0xFEA2341c	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HUE_AREA5			0xFEA23420	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB_TH				0xFEA23424	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB0_H				0xFEA23428	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB0_V				0xFEA2342c	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB1_H				0xFEA23430	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB1_V				0xFEA23434	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB2_H				0xFEA23438	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB2_V				0xFEA2343c	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB3_H				0xFEA23440	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_LB3_V				0xFEA23444	// R/W	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_0			0xFEA23450	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_1			0xFEA234D0	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_2			0xFEA23550	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_3			0xFEA235D0	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_4			0xFEA23650	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_HISTO_5			0xFEA236D0	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_MAXMIN			0xFEA23750	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_SUM				0xFEA23754	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_LB_DET			0xFEA23758	// R	32	HGT control registers
#define	VSPD0_VI6_HGT_REGRST			0xFEA237fc	// W	32	HGT control registers
#define	VSPD0_VI6_LIF_CTRL				0xFEA23b00	// R/W	32	LIF control registers
#define	VSPD0_VI6_LIF_CSBTH				0xFEA23b04	// R/W	32	LIF control registers
#define	VSPD0_VI6_SECURE_CTRL0			0xFEA23d00	// R/W	32	Security control registers 
#define	VSPD0_VI6_SECURE_CTRL1			0xFEA23d04	// R/W	32	Security control registers 
#define	VSPD0_VI6_SHP_CTRL0				0xFEA23e00	// R/W	32	SHP control registers
#define	VSPD0_VI6_SHP_CTRL1				0xFEA23e04	// R/W	32	SHP control registers
#define	VSPD0_VI6_SHP_CTRL2				0xFEA23e08	// R/W	32	SHP control registers
#define	VSPD0_VI6_CLUT0_TBL0			0xFEA24000	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD0_VI6_CLUT1_TBL0			0xFEA24400	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD0_VI6_CLUT2_TBL0			0xFEA24800	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD0_VI6_CLUT3_TBL0			0xFEA24C00	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD0_VI6_CLUT4_TBL0			0xFEA25000	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD0_VI6_LUT_TBL_0				0xFEA27000	// R/W	32	1D-LUT
#define	VSPD0_VI6_CLU_ADDR				0xFEA27400	// R/W	32	3D-LUT
#define	VSPD0_VI6_CLU_DATA				0xFEA27404	// R/W	32	3D-LUT
#define	VSPD0_VI6_UIF4_DICOM_DOCMCR		0xFEA21C00	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMSTR	0xFEA21C04	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMCLSTR	0xFEA21C08	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMIENR	0xFEA21C0C	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMPMR	0xFEA21C14	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMECRCR	0xFEA21C18	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMCCRCR	0xFEA21C1C	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMSPXR	0xFEA21C20	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMSPYR	0xFEA21C24	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMSZXR	0xFEA21C28	// R/W	32	DISCOM control
#define	VSPD0_VI6_UIF4_DICOM_DOCMSZYR	0xFEA21C2C	// R/W	32	DISCOM control



//VSPD1
#define	VSPD1_VI6_CMD0					0xFEA28000	// R/W	32	 General control registers
#define	VSPD1_VI6_CMD1					0xFEA28004	// R/W	32	 General control registers
#define	VSPD1_VI6_CLK_DCSWT				0xFEA28018	// R/W	32	 General control registers
#define	VSPD1_VI6_SRESET				0xFEA28028	// R/W	32	 General control registers
#define	VSPD1_VI6_STATUS				0xFEA28038	// R	32	 General control registers
#define	VSPD1_VI6_WPF0_IRQ_ENB			0xFEA28048	// R/W	32	 General control registers
#define	VSPD1_VI6_WPF0_IRQ_STA			0xFEA2804C	// R/W	32	 General control registers
#define	VSPD1_VI6_WPF1_IRQ_ENB			0xFEA28054	// R/W	32	 General control registers
#define	VSPD1_VI6_WPF1_IRQ_STA			0xFEA28058	// R/W	32	 General control registers
#define	VSPD1_VI6_DISP_IRQ_ENB			0xFEA28078	// R/W	32	 General control registers
#define	VSPD1_VI6_DISP_IRQ_STA			0xFEA2807C	// R/W	32	 General control registers
#define	VSPD1_VI6_DL_CTRL				0xFEA28100	// R/W	32	 Display list control registers
#define	VSPD1_VI6_DL_HDR_ADDR0			0xFEA28104	// R	32	 Display list control registers
#define	VSPD1_VI6_DL_HDR_ADDR1			0xFEA28108	// R	32	 Display list control registers
#define	VSPD1_VI6_DL_SWAP				0xFEA28114	// R/W	32	 Display list control registers
#define	VSPD1_VI6_DL_EXT_CTRL			0xFEA2811C	// R/W	32	 Display list control registers
#define	VSPD1_VI6_DL_BODY_SIZE0			0xFEA28120	// R/W	32	 Display list control registers
#define	VSPD1_VI6_RPF0_SRC_BSIZE		0xFEA28300	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRC_BSIZE		0xFEA28400	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRC_BSIZE		0xFEA28500	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRC_BSIZE		0xFEA28600	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRC_BSIZE		0xFEA28700	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRC_ESIZE		0xFEA28304	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRC_ESIZE		0xFEA28404	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRC_ESIZE		0xFEA28504	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRC_ESIZE		0xFEA28604	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRC_ESIZE		0xFEA28704	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_INFMT			0xFEA28308	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_INFMT			0xFEA28408	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_INFMT			0xFEA28508	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_INFMT			0xFEA28608	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_INFMT			0xFEA28708	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_DSWAP			0xFEA2830C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_DSWAP			0xFEA2840C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_DSWAP			0xFEA2850C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_DSWAP			0xFEA2860C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_DSWAP			0xFEA2870C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_LOC				0xFEA28310	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_LOC				0xFEA28410	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_LOC				0xFEA28510	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_LOC				0xFEA28610	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_LOC				0xFEA28710	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_ALPH_SEL			0xFEA28314	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_ALPH_SEL			0xFEA28414	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_ALPH_SEL			0xFEA28514	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_ALPH_SEL			0xFEA28614	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_ALPH_SEL			0xFEA28714	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_VRTCOL_SET		0xFEA28318	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_VRTCOL_SET		0xFEA28418	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_VRTCOL_SET		0xFEA28518	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_VRTCOL_SET		0xFEA28618	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_VRTCOL_SET		0xFEA28718	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_MSKCTRL			0xFEA2831C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_MSKCTRL			0xFEA2841C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_MSKCTRL			0xFEA2851C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_MSKCTRL			0xFEA2861C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_MSKCTRL			0xFEA2871C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_MSKSET0			0xFEA28320	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_MSKSET0			0xFEA28420	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_MSKSET0			0xFEA28520	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_MSKSET0			0xFEA28620	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_MSKSET0			0xFEA28720	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_MSKSET1			0xFEA28324	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_MSKSET1			0xFEA28424	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_MSKSET1			0xFEA28524	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_MSKSET1			0xFEA28624	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_MSKSET1			0xFEA28724	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_CKEY_CTRL		0xFEA28328	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_CKEY_CTRL		0xFEA28428	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_CKEY_CTRL		0xFEA28528	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_CKEY_CTRL		0xFEA28628	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_CKEY_CTRL		0xFEA28728	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_CKEY_SET0		0xFEA2832C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_CKEY_SET0		0xFEA2842C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_CKEY_SET0		0xFEA2852C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_CKEY_SET0		0xFEA2862C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_CKEY_SET0		0xFEA2872C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_CKEY_SET1		0xFEA28330	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_CKEY_SET1		0xFEA28430	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_CKEY_SET1		0xFEA28530	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_CKEY_SET1		0xFEA28630	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_CKEY_SET1		0xFEA28730	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_PSTRIDE		0xFEA28334	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_PSTRIDE		0xFEA28434	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_PSTRIDE		0xFEA28534	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_PSTRIDE		0xFEA28634	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_PSTRIDE		0xFEA28734	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_ASTRIDE		0xFEA28338	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_ASTRIDE		0xFEA28438	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_ASTRIDE		0xFEA28538	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_ASTRIDE		0xFEA28638	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_ASTRIDE		0xFEA28738	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_ADDR_Y		0xFEA2833C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_ADDR_Y		0xFEA2843C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_ADDR_Y		0xFEA2853C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_ADDR_Y		0xFEA2863C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_ADDR_Y		0xFEA2873C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_ADDR_C0		0xFEA28340	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_ADDR_C0		0xFEA28440	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_ADDR_C0		0xFEA28540	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_ADDR_C0		0xFEA28640	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_ADDR_C0		0xFEA28740	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_ADDR_C1		0xFEA28344	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_ADDR_C1		0xFEA28444	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_ADDR_C1		0xFEA28544	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_ADDR_C1		0xFEA28644	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_ADDR_C1		0xFEA28744	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_SRCM_ADDR_AI		0xFEA28348	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_SRCM_ADDR_AI		0xFEA28448	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_SRCM_ADDR_AI		0xFEA28548	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_SRCM_ADDR_AI		0xFEA28648	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_SRCM_ADDR_AI		0xFEA28748	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF0_MULT_ALPHA		0xFEA2836C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF1_MULT_ALPHA		0xFEA2846C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF2_MULT_ALPHA		0xFEA2856C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF3_MULT_ALPHA		0xFEA2866C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_RPF4_MULT_ALPHA		0xFEA2876C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD1_VI6_WPF0_SRCRPF			0xFEA29000	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_SRCRPF			0xFEA29100	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_SRCRPF			0xFEA29200	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_SRCRPF			0xFEA29300	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_HSZCLIP			0xFEA29004	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_HSZCLIP			0xFEA29104	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_HSZCLIP			0xFEA29204	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_HSZCLIP			0xFEA29304	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_VSZCLIP			0xFEA29008	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_VSZCLIP			0xFEA29108	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_VSZCLIP			0xFEA29208	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_VSZCLIP			0xFEA29308	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_OUTFMT			0xFEA2900C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_OUTFMT			0xFEA2910C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_OUTFMT			0xFEA2920C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_OUTFMT			0xFEA2930C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSWAP			0xFEA29010	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSWAP			0xFEA29110	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSWAP			0xFEA29210	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSWAP			0xFEA29310	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_RNDCTRL			0xFEA29014	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_RNDCTRL			0xFEA29114	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_RNDCTRL			0xFEA29214	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_RNDCTRL			0xFEA29314	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_ROT_CTRL			0xFEA29018	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_ROT_CTRL			0xFEA29118	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_ROT_CTRL			0xFEA29218	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_ROT_CTRL			0xFEA29318	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSTM_STRIDE_Y	0xFEA2901C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSTM_STRIDE_Y	0xFEA2911C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSTM_STRIDE_Y	0xFEA2921C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSTM_STRIDE_Y	0xFEA2931C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSTM_STRIDE_C	0xFEA29020	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSTM_STRIDE_C	0xFEA29120	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSTM_STRIDE_C	0xFEA29220	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSTM_STRIDE_C	0xFEA29320	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSTM_ADDR_Y		0xFEA29024	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSTM_ADDR_Y		0xFEA29124	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSTM_ADDR_Y		0xFEA29224	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSTM_ADDR_Y		0xFEA29324	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSTM_ADDR_C0		0xFEA29028	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSTM_ADDR_C0		0xFEA29128	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSTM_ADDR_C0		0xFEA29228	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSTM_ADDR_C0		0xFEA29328	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_DSTM_ADDR_C1		0xFEA2902C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF1_DSTM_ADDR_C1		0xFEA2912C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF2_DSTM_ADDR_C1		0xFEA2922C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF3_DSTM_ADDR_C1		0xFEA2932C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD1_VI6_WPF0_WRBCK_CTRL		0xFEA29034	// R/W	32	 WPF0 control register
#define	VSPD1_UIF_REG_0					0xFEA29800	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD1_UIF_REG_1					0xFEA29900	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD1_UIF_REG_2					0xFEA29A00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD1_UIF_REG_3					0xFEA29B00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD1_UIF_REG_4					0xFEA29C00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD1_VI6_DPR_RPF0_ROUTE		0xFEA2A000	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_RPF1_ROUTE		0xFEA2A004	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_RPF2_ROUTE		0xFEA2A008	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_RPF3_ROUTE		0xFEA2A00C	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_RPF4_ROUTE		0xFEA2A010	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_WPF0_FPORCH		0xFEA2A014	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_WPF1_FPORCH		0xFEA2A018	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_SRU_ROUTE			0xFEA2A024	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_UDS_ROUTE			0xFEA2A028	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_LUT_ROUTE			0xFEA2A03C	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_CLU_ROUTE			0xFEA2A040	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_HST_ROUTE			0xFEA2A044	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_HSI_ROUTE			0xFEA2A048	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_BRU_ROUTE			0xFEA2A04C	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_HGO_SMPPT			0xFEA2A054	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_HGT_SMPPT			0xFEA2A058	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_SHP_ROUTE			0xFEA2A060	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_UIF0_ROUTE		0xFEA2A064	// R/W	32	 DPR control registers
#define	VSPD1_VI6_DPR_UIF4_ROUTE		0xFEA2A074	// R/W	32	 DPR control registers
#define	VSPD1_VI6_SRU_CTRL0				0xFEA2A200	// R/W	32	 SRU control registers
#define	VSPD1_VI6_SRU_CTRL1				0xFEA2A204	// R/W	32	 SRU control registers
#define	VSPD1_VI6_SRU_CTRL2				0xFEA2A208	// R/W	32	 SRU control registers
#define	VSPD1_VI6_UDS_CTRL				0xFEA2A300	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_SCALE				0xFEA2A304	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_ALPTH				0xFEA2A308	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_ALPVAL			0xFEA2A30C	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_PASS_BWIDTH		0xFEA2A310	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_HPHASE			0xFEA2A314	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_VPHASE			0xFEA2A318	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_HSZCLIP			0xFEA2A31C	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_CLIP_SIZE			0xFEA2A324	// R/W	32	 UDS control registers
#define	VSPD1_VI6_UDS_FILL_COLOR		0xFEA2A328	// R/W	32	 UDS control registers
#define	VSPD1_VI6_LUT_CTRL				0xFEA2A800	// R/W	32	 1D-LUT control register
#define	VSPD1_VI6_CLU_CTRL				0xFEA2A900	// R/W	32	 3D-LUT control register
#define	VSPD1_VI6_HST_CTRL				0xFEA2AA00	// R/W	32	 HST control register
#define	VSPD1_VI6_HSI_CTRL				0xFEA2AB00	// R/W	32	 HSI control register
#define	VSPD1_VI6_BRU_INCTRL			0xFEA2AC00	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRU_VIRRPF_SIZE		0xFEA2AC04	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRU_VIRRPF_LOC		0xFEA2AC08	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRU_VIRRPF_COL		0xFEA2AC0C	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUA_CTRL				0xFEA2AC10	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUA_BLD				0xFEA2AC14	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUB_CTRL				0xFEA2AC18	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUB_BLD				0xFEA2AC1C	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUC_CTRL				0xFEA2AC20	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUC_BLD				0xFEA2AC24	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUD_CTRL				0xFEA2AC28	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUD_BLD				0xFEA2AC2C	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRU_ROP				0xFEA2AC30	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUE_CTRL				0xFEA2AC34	// R/W	32	 BRU control registers
#define	VSPD1_VI6_BRUE_BLD				0xFEA2AC38	// R/W	32	 BRU control registers
#define	VSPD1_VI6_HGO_OFFSET			0xFEA2B000	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_SIZE				0xFEA2B004	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_MODE				0xFEA2B008	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB_TH				0xFEA2B00C	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB0_H				0xFEA2B010	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB0_V				0xFEA2B014	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB1_H				0xFEA2B018	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB1_V				0xFEA2B01C	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB2_H				0xFEA2B020	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB2_V				0xFEA2B024	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB3_H				0xFEA2B028	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_LB3_V				0xFEA2B02C	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_R_HISTO_n			0xFEA2B030	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_R_MAXMIN			0xFEA2B130	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_R_SUM				0xFEA2B134	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_R_LB_DET			0xFEA2B138	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_G_HISTO_n			0xFEA2B140	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_G_MAXMIN			0xFEA2B240	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_G_SUM				0xFEA2B244	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_G_LB_DET			0xFEA2B248	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_B_HISTO_n			0xFEA2B250	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_B_MAXMIN			0xFEA2B350	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_B_SUM				0xFEA2B354	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_B_LB_DET			0xFEA2B358	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_EXT_HIST_ADDR		0xFEA2B35C	// R/W	32	 HGO control registers
#define	VSPD1_VI6_HGO_EXT_HIST_DATA		0xFEA2B360	// R	32	 HGO control registers
#define	VSPD1_VI6_HGO_REGRST			0xFEA2B3FC	// W	32	 HGO control registers
#define	VSPD1_VI6_HGT_OFFSET			0xFEA2B400	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_SIZE				0xFEA2B404	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_MODE				0xFEA2B408	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA0			0xFEA2B40C	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA1			0xFEA2B410	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA2			0xFEA2B414	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA3			0xFEA2B418	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA4			0xFEA2B41C	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HUE_AREA5			0xFEA2B420	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB_TH				0xFEA2B424	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB0_H				0xFEA23428	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB0_V				0xFEA2B42C	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB1_H				0xFEA2B430	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB1_V				0xFEA2B434	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB2_H				0xFEA2B438	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB2_V				0xFEA2B43C	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB3_H				0xFEA2B440	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB3_V				0xFEA2B444	// R/W	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_0			0xFEA2B450	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_1			0xFEA2B4D0	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_2			0xFEA2B550	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_3			0xFEA2B5D0	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_4			0xFEA2B650	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_HISTO_5			0xFEA2B6D0	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_MAXMIN			0xFEA2B750	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_SUM				0xFEA2B754	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_LB_DET			0xFEA2B758	// R	32	 HGT control registers
#define	VSPD1_VI6_HGT_REGRST			0xFEA2B7FC	// W	32	 HGT control registers
#define	VSPD1_VI6_LIF_CTRL				0xFEA2BB00	// R/W	32	 LIF control registers
#define	VSPD1_VI6_LIF_CSBTH				0xFEA2BB04	// R/W	32	 LIF control registers
#define	VSPD1_VI6_SECURE_CTRL0			0xFEA2BD00	// R/W	32	 Security control registers
#define	VSPD1_VI6_SECURE_CTRL1			0xFEA2BD04	// R/W	32	 Security control registers
#define	VSPD1_VI6_SHP_CTRL0				0xFEA2BE00	// R/W	32	 SHP control registers
#define	VSPD1_VI6_SHP_CTRL1				0xFEA2BE04	// R/W	32	 SHP control registers
#define	VSPD1_VI6_SHP_CTRL2				0xFEA2BE08	// R/W	32	 SHP control registers
#define	VSPD1_VI6_CLUT0_TBL0			0xFEA2C000	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD1_VI6_CLUT1_TBL0			0xFEA2C400	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD1_VI6_CLUT2_TBL0			0xFEA2C800	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD1_VI6_CLUT3_TBL0			0xFEA2CC00	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD1_VI6_CLUT4_TBL0			0xFEA2D000	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD1_VI6_LUT_TBL_0				0xFEA2F000	// R/W	32	 1D-LUT
#define	VSPD1_VI6_CLU_ADDR				0xFEA2F400	// R/W	32	 3D-LUT
#define	VSPD1_VI6_CLU_DATA				0xFEA2F404	// R/W	32	 3D-LUT
#define	VSPD1_VI6_UIF4_DICOM_DOCMCR		0xFEA29C00	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMSTR	0xFEA29C04	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMCLSTR	0xFEA29C08	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMIENR	0xFEA29C0C	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMPMR	0xFEA29C14	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMECRCR	0xFEA29C18	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMCCRCR	0xFEA29C1C	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMSPXR	0xFEA29C20	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMSPYR	0xFEA29C24	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMSZXR	0xFEA29C28	// R/W	32	 DISCOM control
#define	VSPD1_VI6_UIF4_DICOM_DOCMSZYR	0xFEA29C2C	// R/W	32	 DISCOM control



//VSPD2
#define	VSPD2_VI6_CMD0					0xFEA30000	// R/W	32	General control registers
#define	VSPD2_VI6_CMD1					0xFEA30004	// R/W	32	General control registers
#define	VSPD2_VI6_CLK_DCSWT 			0xFEA30018	// R/W	32	General control registers
#define	VSPD2_VI6_SRESET				0xFEA30028	// R/W	32	General control registers
#define	VSPD2_VI6_STATUS				0xFEA30038	// R	32	General control registers
#define	VSPD2_VI6_WPF0_IRQ_ENB			0xFEA30048	// R/W	32	General control registers
#define	VSPD2_VI6_WPF0_IRQ_STA			0xFEA3004c	// R/W	32	General control registers
#define	VSPD2_VI6_WPF1_IRQ_ENB			0xFEA30054	// R/W	32	General control registers
#define	VSPD2_VI6_WPF1_IRQ_STA			0xFEA30058	// R/W	32	General control registers
#define	VSPD2_VI6_DISP_IRQ_ENB			0xFEA30078	// R/W	32	General control registers
#define	VSPD2_VI6_DISP_IRQ_STA			0xFEA3007c	// R/W	32	General control registers
#define	VSPD2_VI6_DL_CTRL				0xFEA30100	// R/W	32	Display list control registers
#define	VSPD2_VI6_DL_HDR_ADDR0			0xFEA30104	// R	32	Display list control registers
#define	VSPD2_VI6_DL_HDR_ADDR1			0xFEA30108	// R	32	Display list control registers
#define	VSPD2_VI6_DL_SWAP				0xFEA30114	// R/W	32	Display list control registers
#define	VSPD2_VI6_DL_EXT_CTRL 			0xFEA3011c	// R/W	32	Display list control registers
#define	VSPD2_VI6_DL_BODY_SIZE0 		0xFEA30120	// R/W	32	Display list control registers
#define	VSPD2_VI6_RPF0_SRC_BSIZE		0xFEA30300	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRC_BSIZE		0xFEA30400	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRC_BSIZE		0xFEA30500	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRC_BSIZE		0xFEA30600	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRC_BSIZE		0xFEA30700	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRC_ESIZE		0xFEA30304	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRC_ESIZE		0xFEA30404	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRC_ESIZE		0xFEA30504	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRC_ESIZE		0xFEA30604	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRC_ESIZE		0xFEA30704	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_INFMT			0xFEA30308	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_INFMT			0xFEA30408	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_INFMT			0xFEA30508	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_INFMT			0xFEA30608	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_INFMT			0xFEA30708	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_DSWAP			0xFEA3030C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_DSWAP			0xFEA3040C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_DSWAP			0xFEA3050C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_DSWAP			0xFEA3060C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_DSWAP			0xFEA3070C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_LOC				0xFEA30310	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_LOC				0xFEA30410	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_LOC				0xFEA30510	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_LOC				0xFEA30610	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_LOC				0xFEA30710	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_ALPH_SEL			0xFEA30314	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_ALPH_SEL			0xFEA30414	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_ALPH_SEL			0xFEA30514	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_ALPH_SEL			0xFEA30614	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_ALPH_SEL			0xFEA30714	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_VRTCOL_SET		0xFEA30318	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_VRTCOL_SET		0xFEA30418	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_VRTCOL_SET		0xFEA30518	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_VRTCOL_SET		0xFEA30618	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_VRTCOL_SET		0xFEA30718	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_MSKCTRL			0xFEA3031C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_MSKCTRL			0xFEA3041C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_MSKCTRL			0xFEA3051C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_MSKCTRL			0xFEA3061C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_MSKCTRL			0xFEA3071C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_MSKSET0			0xFEA30320	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_MSKSET0			0xFEA30420	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_MSKSET0			0xFEA30520	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_MSKSET0			0xFEA30620	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_MSKSET0			0xFEA30720	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_MSKSET1			0xFEA30324	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_MSKSET1			0xFEA30424	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_MSKSET1			0xFEA30524	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_MSKSET1			0xFEA30624	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_MSKSET1			0xFEA30724	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_CKEY_CTRL		0xFEA30328	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_CKEY_CTRL		0xFEA30428	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_CKEY_CTRL		0xFEA30528	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_CKEY_CTRL		0xFEA30628	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_CKEY_CTRL		0xFEA30728	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_CKEY_SET0		0xFEA3032C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_CKEY_SET0		0xFEA3042C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_CKEY_SET0		0xFEA3052C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_CKEY_SET0		0xFEA3062C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_CKEY_SET0		0xFEA3072C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_CKEY_SET1		0xFEA30330	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_CKEY_SET1		0xFEA30430	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_CKEY_SET1		0xFEA30530	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_CKEY_SET1		0xFEA30630	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_CKEY_SET1		0xFEA30730	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_PSTRIDE		0xFEA30334	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_PSTRIDE		0xFEA30434	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_PSTRIDE		0xFEA30534	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_PSTRIDE		0xFEA30634	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_PSTRIDE		0xFEA30734	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_ASTRIDE		0xFEA30338	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_ASTRIDE		0xFEA30438	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_ASTRIDE		0xFEA30538	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_ASTRIDE		0xFEA30638	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_ASTRIDE		0xFEA30738	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_ADDR_Y		0xFEA3033C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_ADDR_Y		0xFEA3043C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_ADDR_Y		0xFEA3053C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_ADDR_Y		0xFEA3063C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_ADDR_Y		0xFEA3073C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_ADDR_C0		0xFEA30340	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_ADDR_C0		0xFEA30440	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_ADDR_C0		0xFEA30540	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_ADDR_C0		0xFEA30640	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_ADDR_C0		0xFEA30740	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_ADDR_C1		0xFEA30344	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_ADDR_C1		0xFEA30444	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_ADDR_C1		0xFEA30544	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_ADDR_C1		0xFEA30644	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_ADDR_C1		0xFEA30744	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_SRCM_ADDR_AI		0xFEA30348	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_SRCM_ADDR_AI		0xFEA30448	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_SRCM_ADDR_AI		0xFEA30548	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_SRCM_ADDR_AI		0xFEA30648	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_SRCM_ADDR_AI		0xFEA30748	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF0_MULT_ALPHA		0xFEA3036C	// R/W	32	RPF0 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF1_MULT_ALPHA		0xFEA3046C	// R/W	32	RPF1 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF2_MULT_ALPHA		0xFEA3056C	// R/W	32	RPF2 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF3_MULT_ALPHA		0xFEA3066C	// R/W	32	RPF3 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_RPF4_MULT_ALPHA		0xFEA3076C	// R/W	32	RPF4 control registers (n=0,1,2,3,4)
#define	VSPD2_VI6_WPF0_SRCRPF			0xFEA31000	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_SRCRPF			0xFEA31100	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_SRCRPF			0xFEA31200	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_SRCRPF			0xFEA31300	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_HSZCLIP			0xFEA31004	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_HSZCLIP			0xFEA31104	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_HSZCLIP			0xFEA31204	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_HSZCLIP			0xFEA31304	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_VSZCLIP			0xFEA31008	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_VSZCLIP			0xFEA31108	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_VSZCLIP			0xFEA31208	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_VSZCLIP			0xFEA31308	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_OUTFMT			0xFEA3100C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_OUTFMT			0xFEA3110C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_OUTFMT			0xFEA3120C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_OUTFMT			0xFEA3130C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSWAP			0xFEA31010	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSWAP			0xFEA31110	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSWAP			0xFEA31210	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSWAP			0xFEA31310	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_RNDCTRL			0xFEA31014	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_RNDCTRL			0xFEA31114	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_RNDCTRL			0xFEA31214	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_RNDCTRL			0xFEA31314	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_ROT_CTRL			0xFEA31018	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_ROT_CTRL			0xFEA31118	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_ROT_CTRL			0xFEA31218	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_ROT_CTRL			0xFEA31318	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSTM_STRIDE_Y	0xFEA3101C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSTM_STRIDE_Y	0xFEA3111C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSTM_STRIDE_Y	0xFEA3121C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSTM_STRIDE_Y	0xFEA3131C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSTM_STRIDE_C	0xFEA31020	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSTM_STRIDE_C	0xFEA31120	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSTM_STRIDE_C	0xFEA31220	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSTM_STRIDE_C	0xFEA31320	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSTM_ADDR_Y		0xFEA31024	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSTM_ADDR_Y		0xFEA31124	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSTM_ADDR_Y		0xFEA31224	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSTM_ADDR_Y		0xFEA31324	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSTM_ADDR_C0		0xFEA31028	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSTM_ADDR_C0		0xFEA31128	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSTM_ADDR_C0		0xFEA31228	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSTM_ADDR_C0		0xFEA31328	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_DSTM_ADDR_C1		0xFEA3102C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF1_DSTM_ADDR_C1		0xFEA3112C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF2_DSTM_ADDR_C1		0xFEA3122C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF3_DSTM_ADDR_C1		0xFEA3132C	// R/W	32	WPFk control registers (k=0,1,2,3)
#define	VSPD2_VI6_WPF0_WRBCK_CTRL 		0xFEA31034	// R/W	32	WPF0 control register
#define	VSPD2_UIF_REG_0					0xFEA31800	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD2_UIF_REG_1					0xFEA31900	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD2_UIF_REG_2					0xFEA31A00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD2_UIF_REG_3					0xFEA31B00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD2_UIF_REG_4					0xFEA31C00	// R/W	32	UIF{n} control register (n=0,1,2,3,4)
#define	VSPD2_VI6_DPR_RPF0_ROUTE		0xFEA32000	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_RPF1_ROUTE		0xFEA32004	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_RPF2_ROUTE		0xFEA32008	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_RPF3_ROUTE		0xFEA3200c	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_RPF4_ROUTE		0xFEA32010	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_WPF0_FPORCH		0xFEA32014	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_WPF1_FPORCH		0xFEA32018	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_SRU_ROUTE			0xFEA32024	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_UDS_ROUTE			0xFEA32028	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_LUT_ROUTE			0xFEA3203c	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_CLU_ROUTE			0xFEA32040	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_HST_ROUTE			0xFEA32044	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_HSI_ROUTE			0xFEA32048	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_BRU_ROUTE			0xFEA3204c	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_HGO_SMPPT 		0xFEA32054	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_HGT_SMPPT 		0xFEA32058	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_SHP_ROUTE			0xFEA32060	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_UIF0_ROUTE 		0xFEA32064	// R/W	32	DPR control registers
#define	VSPD2_VI6_DPR_UIF4_ROUTE		0xFEA32074	// R/W	32	DPR control registers
#define	VSPD2_VI6_SRU_CTRL0				0xFEA32200	// R/W	32	SRU control registers
#define	VSPD2_VI6_SRU_CTRL1				0xFEA32204	// R/W	32	SRU control registers
#define	VSPD2_VI6_SRU_CTRL2				0xFEA32208	// R/W	32	SRU control registers
#define	VSPD2_VI6_UDS_CTRL				0xFEA32300	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_SCALE				0xFEA32304	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_ALPTH				0xFEA32308	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_ALPVAL			0xFEA3230c	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_PASS_BWIDTH		0xFEA32310	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_HPHASE			0xFEA32314	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_VPHASE			0xFEA32318	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_HSZCLIP			0xFEA3231c	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_CLIP_SIZE			0xFEA32324	// R/W	32	UDS control registers
#define	VSPD2_VI6_UDS_FILL_COLOR		0xFEA32328	// R/W	32	UDS control registers
#define	VSPD2_VI6_LUT_CTRL				0xFEA32800	// R/W	32	1D-LUT control register
#define	VSPD2_VI6_CLU_CTRL				0xFEA32900	// R/W	32	3D-LUT control register
#define	VSPD2_VI6_HST_CTRL				0xFEA32a00	// R/W	32	HST control register
#define	VSPD2_VI6_HSI_CTRL				0xFEA32b00	// R/W	32	HSI control register
#define	VSPD2_VI6_BRU_INCTRL			0xFEA32c00	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRU_VIRRPF_SIZE		0xFEA32c04	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRU_VIRRPF_LOC		0xFEA32c08	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRU_VIRRPF_COL		0xFEA32c0c	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUA_CTRL				0xFEA32c10	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUA_BLD				0xFEA32c14	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUB_CTRL				0xFEA32c18	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUB_BLD				0xFEA32c1c	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUC_CTRL				0xFEA32c20	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUC_BLD				0xFEA32c24	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUD_CTRL				0xFEA32c28	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUD_BLD				0xFEA32c2c	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRU_ROP				0xFEA32c30	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUE_CTRL				0xFEA32c34	// R/W	32	BRU control registers
#define	VSPD2_VI6_BRUE_BLD				0xFEA32c38	// R/W	32	BRU control registers
#define	VSPD2_VI6_HGO_OFFSET			0xFEA33000	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_SIZE				0xFEA33004	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_MODE				0xFEA33008	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB_TH				0xFEA3300c	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB0_H				0xFEA33010	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB0_V				0xFEA33014	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB1_H				0xFEA33018	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB1_V				0xFEA3301c	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB2_H				0xFEA33020	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB2_V				0xFEA33024	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB3_H				0xFEA33028	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_LB3_V				0xFEA3302c	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_R_HISTO_n			0xFEA33030	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_R_MAXMIN			0xFEA33130	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_R_SUM				0xFEA33134	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_R_LB_DET			0xFEA33138	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_G_HISTO_n			0xFEA33140	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_G_MAXMIN			0xFEA33240	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_G_SUM				0xFEA33244	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_G_LB_DET			0xFEA33248	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_B_HISTO_n			0xFEA33250	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_B_MAXMIN			0xFEA33350	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_B_SUM				0xFEA33354	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_B_LB_DET			0xFEA33358	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_EXT_HIST_ADDR		0xFEA3335c	// R/W	32	HGO control registers
#define	VSPD2_VI6_HGO_EXT_HIST_DATA		0xFEA33360	// R	32	HGO control registers
#define	VSPD2_VI6_HGO_REGRST			0xFEA333fc	// W	32	HGO control registers
#define	VSPD2_VI6_HGT_OFFSET			0xFEA33400	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_SIZE				0xFEA33404	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_MODE				0xFEA33408	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA0			0xFEA3340c	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA1			0xFEA33410	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA2			0xFEA33414	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA3			0xFEA33418	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA4			0xFEA3341c	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HUE_AREA5			0xFEA33420	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB_TH				0xFEA33424	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB0_H				0xFEA33428	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB0_V				0xFEA3342c	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB1_H				0xFEA33430	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB1_V				0xFEA33434	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB2_H				0xFEA33438	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB2_V				0xFEA3343c	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB3_H				0xFEA33440	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_LB3_V				0xFEA33444	// R/W	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_0			0xFEA33450	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_1			0xFEA334D0	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_2			0xFEA33550	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_3			0xFEA335D0	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_4			0xFEA33650	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_HISTO_5			0xFEA336D0	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_MAXMIN			0xFEA33750	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_SUM				0xFEA33754	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_LB_DET			0xFEA33758	// R	32	HGT control registers
#define	VSPD2_VI6_HGT_REGRST			0xFEA337fc	// W	32	HGT control registers
#define	VSPD2_VI6_LIF_CTRL				0xFEA33b00	// R/W	32	LIF control registers
#define	VSPD2_VI6_LIF_CSBTH				0xFEA33b04	// R/W	32	LIF control registers
#define	VSPD2_VI6_SECURE_CTRL0			0xFEA33d00	// R/W	32	Security control registers 
#define	VSPD2_VI6_SECURE_CTRL1			0xFEA33d04	// R/W	32	Security control registers 
#define	VSPD2_VI6_SHP_CTRL0				0xFEA33e00	// R/W	32	SHP control registers
#define	VSPD2_VI6_SHP_CTRL1				0xFEA33e04	// R/W	32	SHP control registers
#define	VSPD2_VI6_SHP_CTRL2				0xFEA33e08	// R/W	32	SHP control registers
#define	VSPD2_VI6_CLUT0_TBL0			0xFEA34000	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD2_VI6_CLUT1_TBL0			0xFEA34400	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD2_VI6_CLUT2_TBL0			0xFEA34800	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD2_VI6_CLUT3_TBL0			0xFEA34C00	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD2_VI6_CLUT4_TBL0			0xFEA35000	// R/W	32	RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD2_VI6_LUT_TBL_0				0xFEA37000	// R/W	32	1D-LUT
#define	VSPD2_VI6_CLU_ADDR				0xFEA37400	// R/W	32	3D-LUT
#define	VSPD2_VI6_CLU_DATA				0xFEA37404	// R/W	32	3D-LUT
#define	VSPD2_VI6_UIF4_DICOM_DOCMCR		0xFEA31C00	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMSTR	0xFEA31C04	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMCLSTR	0xFEA31C08	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMIENR	0xFEA31C0C	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMPMR	0xFEA31C14	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMECRCR	0xFEA31C18	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMCCRCR	0xFEA31C1C	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMSPXR	0xFEA31C20	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMSPYR	0xFEA31C24	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMSZXR	0xFEA31C28	// R/W	32	DISCOM control
#define	VSPD2_VI6_UIF4_DICOM_DOCMSZYR	0xFEA31C2C	// R/W	32	DISCOM control



//VSPD3
#define	VSPD3_VI6_CMD0					0xFEA38000	// R/W	32	 General control registers
#define	VSPD3_VI6_CMD1					0xFEA38004	// R/W	32	 General control registers
#define	VSPD3_VI6_CLK_DCSWT				0xFEA38018	// R/W	32	 General control registers
#define	VSPD3_VI6_SRESET				0xFEA38028	// R/W	32	 General control registers
#define	VSPD3_VI6_STATUS				0xFEA38038	// R	32	 General control registers
#define	VSPD3_VI6_WPF0_IRQ_ENB			0xFEA38048	// R/W	32	 General control registers
#define	VSPD3_VI6_WPF0_IRQ_STA			0xFEA3804C	// R/W	32	 General control registers
#define	VSPD3_VI6_WPF1_IRQ_ENB			0xFEA38054	// R/W	32	 General control registers
#define	VSPD3_VI6_WPF1_IRQ_STA			0xFEA38058	// R/W	32	 General control registers
#define	VSPD3_VI6_DISP_IRQ_ENB			0xFEA38078	// R/W	32	 General control registers
#define	VSPD3_VI6_DISP_IRQ_STA			0xFEA3807C	// R/W	32	 General control registers
#define	VSPD3_VI6_DL_CTRL				0xFEA38100	// R/W	32	 Display list control registers
#define	VSPD3_VI6_DL_HDR_ADDR0			0xFEA38104	// R	32	 Display list control registers
#define	VSPD3_VI6_DL_HDR_ADDR1			0xFEA38108	// R	32	 Display list control registers
#define	VSPD3_VI6_DL_SWAP				0xFEA38114	// R/W	32	 Display list control registers
#define	VSPD3_VI6_DL_EXT_CTRL			0xFEA3811C	// R/W	32	 Display list control registers
#define	VSPD3_VI6_DL_BODY_SIZE0			0xFEA38120	// R/W	32	 Display list control registers
#define	VSPD3_VI6_RPF0_SRC_BSIZE		0xFEA38300	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRC_BSIZE		0xFEA38400	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRC_BSIZE		0xFEA38500	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRC_BSIZE		0xFEA38600	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRC_BSIZE		0xFEA38700	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRC_ESIZE		0xFEA38304	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRC_ESIZE		0xFEA38404	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRC_ESIZE		0xFEA38504	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRC_ESIZE		0xFEA38604	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRC_ESIZE		0xFEA38704	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_INFMT			0xFEA38308	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_INFMT			0xFEA38408	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_INFMT			0xFEA38508	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_INFMT			0xFEA38608	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_INFMT			0xFEA38708	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_DSWAP			0xFEA3830C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_DSWAP			0xFEA3840C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_DSWAP			0xFEA3850C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_DSWAP			0xFEA3860C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_DSWAP			0xFEA3870C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_LOC				0xFEA38310	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_LOC				0xFEA38410	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_LOC				0xFEA38510	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_LOC				0xFEA38610	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_LOC				0xFEA38710	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_ALPH_SEL			0xFEA38314	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_ALPH_SEL			0xFEA38414	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_ALPH_SEL			0xFEA38514	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_ALPH_SEL			0xFEA38614	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_ALPH_SEL			0xFEA38714	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_VRTCOL_SET		0xFEA38318	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_VRTCOL_SET		0xFEA38418	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_VRTCOL_SET		0xFEA38518	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_VRTCOL_SET		0xFEA38618	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_VRTCOL_SET		0xFEA38718	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_MSKCTRL			0xFEA3831C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_MSKCTRL			0xFEA3841C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_MSKCTRL			0xFEA3851C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_MSKCTRL			0xFEA3861C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_MSKCTRL			0xFEA3871C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_MSKSET0			0xFEA38320	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_MSKSET0			0xFEA38420	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_MSKSET0			0xFEA38520	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_MSKSET0			0xFEA38620	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_MSKSET0			0xFEA38720	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_MSKSET1			0xFEA38324	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_MSKSET1			0xFEA38424	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_MSKSET1			0xFEA38524	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_MSKSET1			0xFEA38624	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_MSKSET1			0xFEA38724	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_CKEY_CTRL		0xFEA38328	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_CKEY_CTRL		0xFEA38428	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_CKEY_CTRL		0xFEA38528	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_CKEY_CTRL		0xFEA38628	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_CKEY_CTRL		0xFEA38728	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_CKEY_SET0		0xFEA3832C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_CKEY_SET0		0xFEA3842C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_CKEY_SET0		0xFEA3852C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_CKEY_SET0		0xFEA3862C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_CKEY_SET0		0xFEA3872C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_CKEY_SET1		0xFEA38330	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_CKEY_SET1		0xFEA38430	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_CKEY_SET1		0xFEA38530	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_CKEY_SET1		0xFEA38630	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_CKEY_SET1		0xFEA38730	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_PSTRIDE		0xFEA38334	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_PSTRIDE		0xFEA38434	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_PSTRIDE		0xFEA38534	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_PSTRIDE		0xFEA38634	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_PSTRIDE		0xFEA38734	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_ASTRIDE		0xFEA38338	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_ASTRIDE		0xFEA38438	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_ASTRIDE		0xFEA38538	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_ASTRIDE		0xFEA38638	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_ASTRIDE		0xFEA38738	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_ADDR_Y		0xFEA3833C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_ADDR_Y		0xFEA3843C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_ADDR_Y		0xFEA3853C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_ADDR_Y		0xFEA3863C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_ADDR_Y		0xFEA3873C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_ADDR_C0		0xFEA38340	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_ADDR_C0		0xFEA38440	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_ADDR_C0		0xFEA38540	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_ADDR_C0		0xFEA38640	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_ADDR_C0		0xFEA38740	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_ADDR_C1		0xFEA38344	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_ADDR_C1		0xFEA38444	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_ADDR_C1		0xFEA38544	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_ADDR_C1		0xFEA38644	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_ADDR_C1		0xFEA38744	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_SRCM_ADDR_AI		0xFEA38348	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_SRCM_ADDR_AI		0xFEA38448	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_SRCM_ADDR_AI		0xFEA38548	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_SRCM_ADDR_AI		0xFEA38648	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_SRCM_ADDR_AI		0xFEA38748	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF0_MULT_ALPHA		0xFEA3836C	// R/W	32	 RPF0 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF1_MULT_ALPHA		0xFEA3846C	// R/W	32	 RPF1 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF2_MULT_ALPHA		0xFEA3856C	// R/W	32	 RPF2 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF3_MULT_ALPHA		0xFEA3866C	// R/W	32	 RPF3 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_RPF4_MULT_ALPHA		0xFEA3876C	// R/W	32	 RPF4 control registers (n=0,1,2,3,4)
#define	VSPD3_VI6_WPF0_SRCRPF			0xFEA39000	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_SRCRPF			0xFEA39100	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_SRCRPF			0xFEA39200	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_SRCRPF			0xFEA39300	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_HSZCLIP			0xFEA39004	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_HSZCLIP			0xFEA39104	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_HSZCLIP			0xFEA39204	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_HSZCLIP			0xFEA39304	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_VSZCLIP			0xFEA39008	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_VSZCLIP			0xFEA39108	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_VSZCLIP			0xFEA39208	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_VSZCLIP			0xFEA39308	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_OUTFMT			0xFEA3900C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_OUTFMT			0xFEA3910C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_OUTFMT			0xFEA3920C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_OUTFMT			0xFEA3930C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSWAP			0xFEA39010	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSWAP			0xFEA39110	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSWAP			0xFEA39210	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSWAP			0xFEA39310	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_RNDCTRL			0xFEA39014	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_RNDCTRL			0xFEA39114	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_RNDCTRL			0xFEA39214	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_RNDCTRL			0xFEA39314	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_ROT_CTRL			0xFEA39018	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_ROT_CTRL			0xFEA39118	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_ROT_CTRL			0xFEA39218	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_ROT_CTRL			0xFEA39318	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSTM_STRIDE_Y	0xFEA3901C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSTM_STRIDE_Y	0xFEA3911C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSTM_STRIDE_Y	0xFEA3921C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSTM_STRIDE_Y	0xFEA3931C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSTM_STRIDE_C	0xFEA39020	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSTM_STRIDE_C	0xFEA39120	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSTM_STRIDE_C	0xFEA39220	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSTM_STRIDE_C	0xFEA39320	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSTM_ADDR_Y		0xFEA39024	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSTM_ADDR_Y		0xFEA39124	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSTM_ADDR_Y		0xFEA39224	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSTM_ADDR_Y		0xFEA39324	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSTM_ADDR_C0		0xFEA39028	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSTM_ADDR_C0		0xFEA39128	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSTM_ADDR_C0		0xFEA39228	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSTM_ADDR_C0		0xFEA39328	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_DSTM_ADDR_C1		0xFEA3902C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF1_DSTM_ADDR_C1		0xFEA3912C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF2_DSTM_ADDR_C1		0xFEA3922C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF3_DSTM_ADDR_C1		0xFEA3932C	// R/W	32	 WPFk control registers (k=0,1,2,3)
#define	VSPD3_VI6_WPF0_WRBCK_CTRL		0xFEA39034	// R/W	32	 WPF0 control register
#define	VSPD3_UIF_REG_0					0xFEA39800	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD3_UIF_REG_1					0xFEA39900	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD3_UIF_REG_2					0xFEA39A00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD3_UIF_REG_3					0xFEA39B00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD3_UIF_REG_4					0xFEA39C00	// R/W	32	 UIF{n} control register (n=0,1,2,3,4)
#define	VSPD3_VI6_DPR_RPF0_ROUTE		0xFEA3A000	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_RPF1_ROUTE		0xFEA3A004	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_RPF2_ROUTE		0xFEA3A008	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_RPF3_ROUTE		0xFEA3A00C	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_RPF4_ROUTE		0xFEA3A010	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_WPF0_FPORCH		0xFEA3A014	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_WPF1_FPORCH		0xFEA3A018	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_SRU_ROUTE			0xFEA3A024	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_UDS_ROUTE			0xFEA3A028	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_LUT_ROUTE			0xFEA3A03C	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_CLU_ROUTE			0xFEA3A040	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_HST_ROUTE			0xFEA3A044	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_HSI_ROUTE			0xFEA3A048	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_BRU_ROUTE			0xFEA3A04C	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_HGO_SMPPT			0xFEA3A054	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_HGT_SMPPT			0xFEA3A058	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_SHP_ROUTE			0xFEA3A060	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_UIF0_ROUTE		0xFEA3A064	// R/W	32	 DPR control registers
#define	VSPD3_VI6_DPR_UIF4_ROUTE		0xFEA3A074	// R/W	32	 DPR control registers
#define	VSPD3_VI6_SRU_CTRL0				0xFEA3A200	// R/W	32	 SRU control registers
#define	VSPD3_VI6_SRU_CTRL1				0xFEA3A204	// R/W	32	 SRU control registers
#define	VSPD3_VI6_SRU_CTRL2				0xFEA3A208	// R/W	32	 SRU control registers
#define	VSPD3_VI6_UDS_CTRL				0xFEA3A300	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_SCALE				0xFEA3A304	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_ALPTH				0xFEA3A308	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_ALPVAL			0xFEA3A30C	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_PASS_BWIDTH		0xFEA3A310	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_HPHASE			0xFEA3A314	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_VPHASE			0xFEA3A318	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_HSZCLIP			0xFEA3A31C	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_CLIP_SIZE			0xFEA3A324	// R/W	32	 UDS control registers
#define	VSPD3_VI6_UDS_FILL_COLOR		0xFEA3A328	// R/W	32	 UDS control registers
#define	VSPD3_VI6_LUT_CTRL				0xFEA3A800	// R/W	32	 1D-LUT control register
#define	VSPD3_VI6_CLU_CTRL				0xFEA3A900	// R/W	32	 3D-LUT control register
#define	VSPD3_VI6_HST_CTRL				0xFEA3AA00	// R/W	32	 HST control register
#define	VSPD3_VI6_HSI_CTRL				0xFEA3AB00	// R/W	32	 HSI control register
#define	VSPD3_VI6_BRU_INCTRL			0xFEA3AC00	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRU_VIRRPF_SIZE		0xFEA3AC04	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRU_VIRRPF_LOC		0xFEA3AC08	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRU_VIRRPF_COL		0xFEA3AC0C	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUA_CTRL				0xFEA3AC10	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUA_BLD				0xFEA3AC14	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUB_CTRL				0xFEA3AC18	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUB_BLD				0xFEA3AC1C	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUC_CTRL				0xFEA3AC20	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUC_BLD				0xFEA3AC24	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUD_CTRL				0xFEA3AC28	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUD_BLD				0xFEA3AC2C	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRU_ROP				0xFEA3AC30	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUE_CTRL				0xFEA3AC34	// R/W	32	 BRU control registers
#define	VSPD3_VI6_BRUE_BLD				0xFEA3AC38	// R/W	32	 BRU control registers
#define	VSPD3_VI6_HGO_OFFSET			0xFEA3B000	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_SIZE				0xFEA3B004	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_MODE				0xFEA3B008	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB_TH				0xFEA3B00C	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB0_H				0xFEA3B010	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB0_V				0xFEA3B014	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB1_H				0xFEA3B018	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB1_V				0xFEA3B01C	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB2_H				0xFEA3B020	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB2_V				0xFEA3B024	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB3_H				0xFEA3B028	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_LB3_V				0xFEA3B02C	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_R_HISTO_n			0xFEA3B030	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_R_MAXMIN			0xFEA3B130	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_R_SUM				0xFEA3B134	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_R_LB_DET			0xFEA3B138	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_G_HISTO_n			0xFEA3B140	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_G_MAXMIN			0xFEA3B240	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_G_SUM				0xFEA3B244	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_G_LB_DET			0xFEA3B248	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_B_HISTO_n			0xFEA3B250	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_B_MAXMIN			0xFEA3B350	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_B_SUM				0xFEA3B354	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_B_LB_DET			0xFEA3B358	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_EXT_HIST_ADDR		0xFEA3B35C	// R/W	32	 HGO control registers
#define	VSPD3_VI6_HGO_EXT_HIST_DATA		0xFEA3B360	// R	32	 HGO control registers
#define	VSPD3_VI6_HGO_REGRST			0xFEA3B3FC	// W	32	 HGO control registers
#define	VSPD3_VI6_HGT_OFFSET			0xFEA3B400	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_SIZE				0xFEA3B404	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_MODE				0xFEA3B408	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA0			0xFEA3B40C	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA1			0xFEA3B410	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA2			0xFEA3B414	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA3			0xFEA3B418	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA4			0xFEA3B41C	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HUE_AREA5			0xFEA3B420	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB_TH				0xFEA3B424	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB0_H				0xFEA33428	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB0_V				0xFEA3B42C	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB1_H				0xFEA3B430	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB1_V				0xFEA3B434	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB2_H				0xFEA3B438	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB2_V				0xFEA3B43C	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB3_H				0xFEA3B440	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB3_V				0xFEA3B444	// R/W	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_0			0xFEA3B450	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_1			0xFEA3B4D0	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_2			0xFEA3B550	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_3			0xFEA3B5D0	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_4			0xFEA3B650	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_HISTO_5			0xFEA3B6D0	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_MAXMIN			0xFEA3B750	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_SUM				0xFEA3B754	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_LB_DET			0xFEA3B758	// R	32	 HGT control registers
#define	VSPD3_VI6_HGT_REGRST			0xFEA3B7FC	// W	32	 HGT control registers
#define	VSPD3_VI6_LIF_CTRL				0xFEA3BB00	// R/W	32	 LIF control registers
#define	VSPD3_VI6_LIF_CSBTH				0xFEA3BB04	// R/W	32	 LIF control registers
#define	VSPD3_VI6_SECURE_CTRL0			0xFEA3BD00	// R/W	32	 Security control registers
#define	VSPD3_VI6_SECURE_CTRL1			0xFEA3BD04	// R/W	32	 Security control registers
#define	VSPD3_VI6_SHP_CTRL0				0xFEA3BE00	// R/W	32	 SHP control registers
#define	VSPD3_VI6_SHP_CTRL1				0xFEA3BE04	// R/W	32	 SHP control registers
#define	VSPD3_VI6_SHP_CTRL2				0xFEA3BE08	// R/W	32	 SHP control registers
#define	VSPD3_VI6_CLUT0_TBL0			0xFEA3C000	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD3_VI6_CLUT1_TBL0			0xFEA3C400	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD3_VI6_CLUT2_TBL0			0xFEA3C800	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD3_VI6_CLUT3_TBL0			0xFEA3CC00	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD3_VI6_CLUT4_TBL0			0xFEA3D000	// R/W	32	 RPFn-CLUT (n=0,1,2,3,4)
#define	VSPD3_VI6_LUT_TBL_0				0xFEA3F000	// R/W	32	 1D-LUT
#define	VSPD3_VI6_CLU_ADDR				0xFEA3F400	// R/W	32	 3D-LUT
#define	VSPD3_VI6_CLU_DATA				0xFEA3F404	// R/W	32	 3D-LUT
#define	VSPD3_VI6_UIF4_DICOM_DOCMCR		0xFEA39C00	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMSTR	0xFEA39C04	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMCLSTR	0xFEA39C08	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMIENR	0xFEA39C0C	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMPMR	0xFEA39C14	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMECRCR	0xFEA39C18	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMCCRCR	0xFEA39C1C	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMSPXR	0xFEA39C20	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMSPYR	0xFEA39C24	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMSZXR	0xFEA39C28	// R/W	32	 DISCOM control
#define	VSPD3_VI6_UIF4_DICOM_DOCMSZYR	0xFEA39C2C	// R/W	32	 DISCOM control




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
