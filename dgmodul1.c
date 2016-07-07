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
extern uint32_t gUreg[17];
extern uint32_t gPrrData;


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
	uint16_t scscr;

	scscr = *((volatile uint16_t*)SCIF2_SCSCR);
	scscr &= 0x0003;

	if (scscr == 0x0002) {
		//external clock
		if (gPrrData == SoC_REV_RCARH3_ES10) {		//R-CarH3_ES1.0
			dgScifSpeedUp_460800();
		} else {
			dgScifSpeedUp_921600();
		}
	} else {
		//internal clock
		if (gPrrData == SoC_REV_RCARH3_ES10) {		//R-CarH3_ES1.0
			dgScifSpeedUp_115200();
		} else {
			dgScifSpeedUp_230400();
		}
	}

}

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 230.4kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
void	dgScifSpeedUp_115200(void)
{
	uint8_t setData;

	PutStr("Scif speed UP",1);
	setData =0x8;			// 115200bps@33MHz
	PutStr("Please change to 115.2Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_BRR(setData);
}

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 230.4kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
void	dgScifSpeedUp_230400(void)
{
	uint8_t setData;

	PutStr("Scif speed UP",1);
	setData =0x8;			// 230400bps@66MHz
	PutStr("Please change to 230.4Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_BRR(setData);
}

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 460.8kbps	*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
void	dgScifSpeedUp_460800(void)
{
	uint16_t setData;

	PutStr("Scif speed UP",1);
	setData =0x002;			//14.7456MHz/ (460800*16) =   2
	PutStr("Please change to 460.8Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_DL(setData);
}

/****************************************************************
	MODULE				: dgScifSpeedUp							*
	FUNCTION			: Scif speed UP		Change 921kbps		*
	COMMAND				: SUP									*
	INPUT PARAMETER		: SUP									*
*****************************************************************/
void	dgScifSpeedUp_921600(void)
{
	uint16_t setData;

	PutStr("Scif speed UP",1);
	setData =0x001;			//14.7456MHz/ (921600*16) =   1
	PutStr("Please change to 921.6Kbps baud rate setting of the terminal.",1);
	WaitPutCharSendEnd();
	SetScif2_DL(setData);
}

