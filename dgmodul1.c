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

#include	"common.h"
#include	"dgtable.h"
#include	"dgmodul1.h"
#include	"devdrv.h"
#include	"devdrv.h"
#include	"bit.h"
#include	"cpudrv.h"
#include	"scifdrv.h"

#include "reg_rcarh3.h"
#include "boot_init_lbsc.h"


extern const char *const AllHelpMess[ALL_HELP_MESS_LINE];
extern const com_menu MonCom[COMMAND_UNIT];
extern int32_t  gComNo;
extern char gKeyBuf[64];


uint32_t gFLASH_CS1_ID;



/****************************************************************
	MODULE				: dgHelp								*
	FUNCTION			: HELP	MESSAGE							*
	COMMAND				: H										*
	INPUT PARAMETER		: H										*
*****************************************************************/
void	dgHelp(void)
{
	char tmp[64],chPtr,helpNo;

	chPtr=0;
	if(!GetStrBlk(gKeyBuf,tmp,&chPtr,0)){
		PutMess(AllHelpMess);
	}
}



int32_t	GetStr_ByteCount(char *str,uint32_t getByteCount)
{
	uint32_t	byteCount;
	int32_t i;

	for(byteCount=1;byteCount<=getByteCount;byteCount=byteCount+1){
		i=1;
		while(i==1){
			i=GetChar(str);
		}
		str++;
		i=1;
		while(i==1){
			i=GetChar(str);
		}
		str++;
	}
	*str = 0;
}



void	dgScifSpeedUp(void)
{
#ifdef RCAR_GEN3_SALVATOR
	uint32_t product;

	product = *((volatile uint32_t*)PRR) & (PRR_PRODUCT_MASK | PRR_CUT_MASK);

#ifdef SCIF_CLK_EXTERNAL
	if (product == (PRR_PRODUCT_H3 | PRR_CUT_10)) {	/* R-CarH3_Ver.1.0 */
		dgScifSpeedUp_460800();
	} else {
		dgScifSpeedUp_921600();
	}
#endif /* SCIF_CLK_EXTERNAL */
#ifdef SCIF_CLK_INTERNAL
	if (product == (PRR_PRODUCT_H3 | PRR_CUT_10)) {	/* R-CarH3_Ver.1.0 */
		dgScifSpeedUp_115200();
	} else {
		dgScifSpeedUp_230400();
	}
#endif /* SCIF_CLK_INTERNAL */
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
	dgScifSpeedUp_921600();
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	dgScifSpeedUp_921600();
#endif /* RCAR_GEN3_DRAAK */
}

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 230.4kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
#ifdef RCAR_GEN3_SALVATOR
void	dgScifSpeedUp_115200(void)
{
	uint8_t setData;

	PutStr("Scif speed UP",1);
	setData =0x8;			/* 115200bps@33MHz */
	PutStr("Please change to 115.2Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_BRR(setData);
}
#endif /* RCAR_GEN3_SALVATOR */

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 230.4kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
#ifdef RCAR_GEN3_SALVATOR
void	dgScifSpeedUp_230400(void)
{
	uint8_t setData;

	PutStr("Scif speed UP",1);
	setData =0x8;			/* 230400bps@66MHz */
	PutStr("Please change to 230.4Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_BRR(setData);
}
#endif /* RCAR_GEN3_SALVATOR */

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 460.8kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
#ifdef RCAR_GEN3_SALVATOR
void	dgScifSpeedUp_460800(void)
{
	uint16_t setData;

	PutStr("Scif speed UP",1);
	setData =0x002;			//14.7456MHz/ (460800*16) =   2
	PutStr("Please change to 460.8Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_DL(setData);
}
#endif /* RCAR_GEN3_SALVATOR */

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 921kbps		*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
void	dgScifSpeedUp_921600(void)
{
	uint16_t setData;
#ifdef RCAR_GEN3_EBISU
	uint32_t sscg;
	uint32_t md;

	md = *((volatile uint32_t*)RST_MODEMR);
	sscg = (md & 0x00001000) >> 12;
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	uint32_t sscg;
	uint32_t md;

	md = *((volatile uint32_t*)RST_MODEMR);
	sscg = (md & 0x00001000) >> 12;
#endif /* RCAR_GEN3_DRAAK */

	PutStr("Scif speed UP",1);
	PutStr("Please change to 921.6Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();

#ifdef RCAR_GEN3_SALVATOR
	setData =0x001;			/* 14.7456MHz / (921600*16) = 1 */
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
	if(sscg == 0x0){		//MD12=0 (SSCG off) ： S3D1CΦ=266.6MHz
		setData =0x12;		//266.66MHz/ (921600*16) =   18.08     @S3D1
	}else{				//MD12=1 (SSCG on)  ： S3D1CΦ=240MHz
		setData =0x10;		//240MHz   / (921600*16) =   16.28     @S3D1
	}
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
	if(sscg == 0x0){		//MD12=0 (SSCG off) ： S3D1CΦ=266.6MHz
		setData =0x12;		//266.66MHz/ (921600*16) =   18.08     @S3D1
	}
	else{				//MD12=1 (SSCG on)  ： S3D1CΦ=250MHz
		setData =0x11;		//250MHz   / (921600*16) =   16.95     @S3D1
	}
#endif /* RCAR_GEN3_DRAAK */
	SetScif2_DL(setData);
}
