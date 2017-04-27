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

#include	"types.h"
#include	"common.h"
#include	"devdrv.h"
#include	"usb_lib.h"

__attribute__((aligned(32))) uint8_t		gCOMMAND_Area[COMMAND_BUFFER_SIZE];
extern uint32_t	gTerminal;

/************************************************************************/
/*NAME		: PutMes													*/
/************************************************************************/
int32_t PutMess(const char *const mess[])
{
	int32_t i=0;
	while(mess[i]){
		PutStr(mess[i],ENB_RTN);
		i++;
	}
	return(0);
}

/************************************************************************/
/*NAME		: PutStr													*/
/************************************************************************/
int32_t	PutStr(const char *str,char rtn)
{
	while(*str){
		PutChar(*str);
		str++;
	}
	if(rtn == 1){
		PutChar(CR_CODE);
		PutChar(LF_CODE);
	}
	return(0);

}

int32_t PutCharUSB(char outChar)
{
	char outCh;
	outCh = outChar;
	
	(void)USB_WriteData(&outCh, 1);
	USB_IntCheck();
	return(0);
}

int32_t GetCharUSB(char *inChar)
{
	static int32_t numOfChar = 0;
	static int32_t index = 0;
	int32_t length = 0;
	
	while(numOfChar == 0)
	{
		numOfChar = USB_ReadCount();
		length = USB_ReadData(gCOMMAND_Area, numOfChar);
		USB_IntCheck();
	}
	*inChar = *((char*)(gCOMMAND_Area + index));
	index++;
	if (numOfChar == index)
	{
		index = 0;
		numOfChar = 0;
	}
	return(0);
}


/************************************************************************/
/*NAME		: GetStr													*/
/************************************************************************/
int32_t	GetStr(char *str,char *chCnt)
{
	char	*intstr;
	int32_t	i;

	intstr = str;

	while(1)
	{
		i=1;
		while(i==1)
		{
			i=GetChar(str);
		}
		if(*str==CR_CODE) break;
		switch(*str)
		{
			case BS_CODE: if(*chCnt==0) break;
						  else
						  {
							 PutChar(BS_CODE);
							 PutChar(SP_CODE);
							 PutChar(BS_CODE);
							 *chCnt = *chCnt - 1;
							 str--;
						  }
						  break;
			case LF_CODE: break;
			default: PutChar(*str);
				     str++;
					 *chCnt = *chCnt+1;
		}
	}
	*str = 0;
	PutChar(LF_CODE);
	PutChar(CR_CODE);
	return(0);

}


/************************************************************************/
/*NAME		: GetStr_MemEd												*/
/************************************************************************/
int32_t	GetStr_MemEd(char *str,char *chCnt)
{
	char	*intstr;
	int32_t	i;

	intstr = str;
	*chCnt=0;

	while(1)
	{
		i=1;
		while(i==1)
		{
			i=GetChar(str);
		}
		if(*str==CR_CODE) break;
		switch(*str)
		{
			case BS_CODE: if(*chCnt==0) break;
						  else
						  {
							 PutChar(BS_CODE);
							 PutChar(SP_CODE);
							 PutChar(BS_CODE);
							 *chCnt = *chCnt - 1;
							 str--;
						  }
						  break;
			case LF_CODE: break;
			default: PutChar(*str);
				     str++;
					 *chCnt = *chCnt+1;
		}
		if(*intstr =='.'){
			break;
		}
		else if(*intstr =='^'){
			break;
		}
	}
	*str = 0;
	PutChar(LF_CODE);
	PutChar(CR_CODE);
	return(0);
}

/************************************************************************/
/*NAME		: Hex2Ascii													*/
/************************************************************************/
uint32_t Hex2Ascii(int32_t hexdata,char *str,int32_t *chcnt)
{

    long    i;
    char    ch;

    for( i = 7; i >= 0; i-- ) {
        ch = (char)(hexdata & 0x0F);
        if( ch > 9 )
            ch += 7;
        ch += 0x30;
        hexdata >>= 4;

        *(str + i) = ch;
    }
    *(str + 8) = '\0';
	*chcnt = 8;

	return 0U;
}


uint32_t Hex2DecAscii(int32_t hexdata,char *str,int32_t *chcnt)
{
	char Count;
	char countstart;
	uint32_t Compdata;

	unsigned char dataB;
	uint32_t dataL;
	uint32_t i;

	Count			= 0;
	countstart		= 0x0;
	dataB = 0;
	dataL = 10;
	while( dataL > 0 ){
		Compdata = 1;
		i = 1;
		while( i < dataL ){
			Compdata *= 10;
			i++;
		}
		while( hexdata >= Compdata ){
			hexdata -= Compdata;
			dataB++;
			countstart = 1;
		}
		if( countstart == 1 ){
			*(str++) = dataB + '0';
			Count++;
		}
		dataB = 0;
		dataL--;
	}

	if(Count==0){
		*str = '0';	str++;	Count++;
	}
	*str = '\0';
	*chcnt = Count;
	return(0);

}


/************************************************************************/

void	DelStr(int32_t delCnt)
{
	int32_t i,j;
	for(i=0;i<delCnt;i++){	PutChar(BS_CODE);for(j=0;j<100;j++); }
	for(i=0;i<delCnt;i++){	PutChar(' ');for(j=0;j<100;j++); }
	for(i=0;i<delCnt;i++){	PutChar(BS_CODE);for(j=0;j<100;j++); }
}

void ChgLtl2Lrg(char *str)
{
	while(*str!=0){
		if(('a' <= *str)&&(*str<='z'))
			*str -= 0x20;
		str++;
	}
}
char HexAscii2Data(unsigned char *buf,uint32_t *data)
{
	char chCnt;
	uint32_t tmpData;
	*data = 0;	chCnt = 0;

	ChgLtl2Lrg(buf);

	if(*buf=='@') return(3);
	while(*buf){
		if(('0'<= *buf)&&(*buf<='9')){
			tmpData = (uint32_t)(*buf - '0');
			*data <<= 4;
			*data |= tmpData;
		}else if(('A'<= *buf)&&(*buf<='F')){
			tmpData = (uint32_t)(*buf - 55);
			*data <<= 4;
			*data |= tmpData;
		}else{
			return(1);
		}
		buf++; chCnt++;
		if(chCnt>(SIZE_32BIT*2))	return(1);
	}
	return(0);
}

char HexAscii2Data_64(unsigned char *buf,uintptr_t *data)
{
	char chCnt;
	uintptr_t tmpData;
	*data = 0;	chCnt = 0;

	ChgLtl2Lrg(buf);

	if(*buf=='@') return(3);
	while(*buf){
		if(('0'<= *buf)&&(*buf<='9')){
			tmpData = (uintptr_t)(*buf - '0');
			*data <<= 4;
			*data |= tmpData;
		}else if(('A'<= *buf)&&(*buf<='F')){
			tmpData = (uintptr_t)(*buf - 55);
			*data <<= 4;
			*data |= tmpData;
		}else{
			return(1);
		}
		buf++; chCnt++;
		if(chCnt>(CPU_BYTE_SIZE*2))	return(1);
	}
	return(0);
}



char Data2HexAscii(uint32_t data,char *buf,char size)
{
	char loopCnt,i;
	uint32_t tmpData;
	switch(size){
	case SIZE_8BIT:
		data <<= (SIZE_32BIT*8-8); loopCnt=2;
		break;
	case SIZE_16BIT:
		data <<= (SIZE_32BIT*8-16); loopCnt=4;
		break;
	case SIZE_32BIT:
		data <<= (SIZE_32BIT*8-32); loopCnt=8;
		break;
	}
	for(i=0;i<loopCnt;i++,buf++){
		tmpData = (data >> (SIZE_32BIT*8-4));
		if(tmpData < 0x0a){ /* case 1 to 9 */
			*buf = (char)(tmpData + '0');
		}else{	/* case A to F */
			*buf = (char)(tmpData + 55);
		}
		data <<= 4;
	}
	*buf = 0;
	return(0);
}

char Data2HexAscii_64(uintptr_t data,char *buf,char size)
{
	char loopCnt,i;
	uintptr_t tmpData;
	switch(size){
	case SIZE_8BIT:
		data <<= (CPU_BYTE_SIZE*8-8); loopCnt=2;
		break;
	case SIZE_16BIT:
		data <<= (CPU_BYTE_SIZE*8-16); loopCnt=4;
		break;
	case SIZE_32BIT:
		data <<= (CPU_BYTE_SIZE*8-32); loopCnt=8;
		break;
#ifdef AArch64
	case SIZE_64BIT:
		data <<= (CPU_BYTE_SIZE*8-64); loopCnt=16;
		break;
#endif
	}
	for(i=0;i<loopCnt;i++,buf++){
		tmpData = (data >> (CPU_BYTE_SIZE*8-4));
		if(tmpData < 0x0a){ /* case 1 to 9 */
			*buf = (char)(tmpData + '0');
		}else{	/* case A to F */
			*buf = (char)(tmpData + 55);
		}
		data <<= 4;
	}
	*buf = 0;
	return(0);
}



char GetStrBlk(char *inStr,char *outStr,
			   char *chPtr,char method)
{
	char serchEnd,frstSpace,endCh;
	inStr = inStr + *chPtr;
	serchEnd = 0;	frstSpace = 0;
	while(!serchEnd){
		switch(*inStr){
			case ' ':   /* space Code */
				if(frstSpace)
					if((method==0)||(method==' ')){
						serchEnd = 1; *outStr = 0;
						endCh = ' ';
				}
				break;
			case 0:
				serchEnd = 1;	*outStr = 0;
				inStr++;
				endCh = 0;
				break;
			default:
				frstSpace=1;
				*outStr = *inStr;
				outStr++;
				break;
		}
		*chPtr += 1; inStr++;
	}
	return(endCh);
}





void SoftDelay(uint32_t loop)
{
	uint32_t i;
	for(i=0;i<loop;i++);
}

void WaitKeyIn_Y(void)
{
	uint32_t loop;
	char tmp;

	loop=1;
	while(loop){
		GetChar(&tmp);
		if((tmp=='y')||(tmp=='Y'))	loop=0;
	}
}

char WaitKeyIn_YorN(void)
{
	char tmp;

	while(1){
		GetChar(&tmp);
		if((tmp=='y')||(tmp=='Y')){			return(0);	}
		else if((tmp=='n')||(tmp=='N')){	return(1);	}
	}
}

void *memset(void *dst, int val, unsigned long count)
{
	char *ptr = dst;

	while (count--)
		*ptr++ = val;

	return dst;
}
