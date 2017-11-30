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
#include	"devdrv.h"
#include	"scifdrv.h"

#if USB_ENABLE == 1
uint32_t	gTerminal = SCIF2_TERMINAL;
#endif /* USB_ENABLE == 1 */

/************************
	PutChar				*
*************************/

int32_t PutChar(char outChar)
{
#if USB_ENABLE == 1
	if (gTerminal == USB_TERMINAL)
	{
		PutCharUSB(outChar);
	}
	else
	{
		PutCharSCIF2(outChar);
	}
#else  /* USB_ENABLE == 1 */
	PutCharSCIF2(outChar);
#endif /* USB_ENABLE == 1 */
	return(0);
}

/************************
	GetChar				*
*************************/

int32_t GetChar(char *inChar)
{
#if USB_ENABLE == 1
	if (gTerminal == USB_TERMINAL)
	{
		GetCharUSB(inChar);
	}
	else
	{
		GetCharSCIF2(inChar);
	}
#else  /* USB_ENABLE == 1 */
	GetCharSCIF2(inChar);
#endif /* USB_ENABLE == 1 */
	return(0);
}

int32_t WaitPutCharSendEnd(void)
{
	WaitPutScif2SendEnd();
}
