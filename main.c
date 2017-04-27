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

#include	"common.h"
#include	"main.h"
#include	"dgtable.h"
#include	"bit.h"
#include	"cpudrv.h"
#include	"dgemmc.h"
#include	"dginit.h"
#include	"usb_lib.h"
#include	"scifdrv.h"
#include	"devdrv.h"

extern const char *const StartMessMonitor[START_MESS_MON_LINE];
extern const char *const StartMessWorkMem[START_MESS_MEM_LINE];
extern const com_menu MonCom[COMMAND_UNIT];
extern uint8_t	gCOMMAND_Area[COMMAND_BUFFER_SIZE];
extern uint32_t	gTerminal;

char gKeyBuf[64];
int32_t gComNo;


void Main(void)
{
	InitMain();
	StartMess();
	DecCom();
}

void InitMain(void)
{
	InitSysMon();
#ifdef Area0Boot
//	InitScif2_SCIFCLK();
#endif
	dg_init_emmc();
	SetgPrrData();
	USB_Init();
}

void StartMess( void )
{
	PutStr("  ",1);
	PutMess(StartMessMonitor);
	PutMess(StartMessWorkMem);
//	PutSocChipVersion();
}


void DecCom(void)
{
	char tmp[64], chCnt, chPtr;
	uint32_t rtn = 0;
	uint32_t res;
	chCnt = 1;

	PutStr(">", 0);

	while (rtn == 0) {
		rtn = USB_TerminalInputCheck(gCOMMAND_Area);
		if (rtn > 0) {
			gTerminal = USB_TERMINAL;
			gKeyBuf[0] = gCOMMAND_Area[0];

			PutMess(StartMessMonitor);
			PutMess(StartMessWorkMem);
			PutStr(">", 0);
			USB_IntCheck();
		}

		if (rtn == 0) {
			rtn = SCIF_TerminalInputCheck(gKeyBuf);
		}
		if (0 < rtn) {
			if (gKeyBuf[0] == CR_CODE) {
				PutChar(LF_CODE);
				PutChar(CR_CODE);
				PutStr(">", 0);
				chCnt = 0;

			} else if (gKeyBuf[0] != LF_CODE) {
				PutChar(gKeyBuf[0]);
			}
		}
	}

	while(1)
	{
		GetStr(gKeyBuf+chCnt,&chCnt);
		chPtr=0;
		GetStrBlk(gKeyBuf,tmp,&chPtr,0);
		if(chPtr!=1){
			ChgLtl2Lrg(tmp);
			if(!CmpCom(tmp)){
				(MonCom[gComNo].comProg)();
			}
			else PutStr("command not found",1);
		}
		PutStr(">",0);
		chCnt=0;
		USB_IntCheck();
	}
}

long CmpCom(char *str)
{
	char *cmpStr,*tmpStr,err;
	gComNo = 0;
	while(TBL_END!=MonCom[gComNo].comStr){
		err=0; tmpStr = str;
		cmpStr = MonCom[gComNo].comStr;
		while(*tmpStr!=0){
			if(*tmpStr == *cmpStr){
				tmpStr++; cmpStr++;
			}else{
				err=1; break;
			}
		}
		if((!err)&&(*cmpStr==0)){
			return(0);
		}
		gComNo++;
	}
	return(1);
}

