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
#include	"b_boarddrv.h"
#include	"cpudrv.h"
#include	"switch.h"


//===========================================================================
//#define BD_SALVATOR		0x00000000	/* R-Car H3_SIP/M3_SIP */
//#define BD_KRIEK		0x00000001	/* R-Car M3/M3N */
//#define BD_STARTERKIT		0x00000002	/* R-Car H3_SIP/M3_SIP */
//#define BD_EBISU		0x00000003	/* R-Car E3 */
//#define BD_DRAAK		0x00000004	/* R-Car D3 */
//===========================================================================

//== SPI / HYPER Interface Message ==========================================
// On Board SPI Flash Memory 128Mbit [S25FS128S]
const prg_tbl SwChgOnBoard_QSPI0[BOARD_COUNT] = {
	(void (*)())SwChgOnBoard_QSPI0_SALVATOR,
	(void (*)())SwChgOnBoard_QSPI0_KRIEK,
	(void (*)())SwChgOnBoard_QSPI0_SKIT,
	(void (*)())SwChgOnBoard_QSPI0_KRIEK,
	(void (*)())SwChgOnBoard_QSPI0_KRIEK,
	(void (*)())SwChgOnBoard_QSPI0_other,
};
void SwChgOnBoard_QSPI0_other(void){
	PutStr("Please set the switch to OnBoard-SPI0(128Mbit) side. Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(77);
}

// Ex Board SPI Flash Memory 128Mbit [S25FL512S]
const prg_tbl SwChgExSPI_QSPI0[BOARD_COUNT] = {
	(void (*)())SwChgExSPI_QSPI0_SALVATOR,
	(void (*)())SwChgExSPI_QSPI0_KRIEK,
	(void (*)())SwChgExSPI_QSPI0_SKIT,
	(void (*)())SwChgExSPI_QSPI0_KRIEK,
	(void (*)())SwChgExSPI_QSPI0_KRIEK,
	(void (*)())SwChgExSPI_QSPI0_other,
};
void SwChgExSPI_QSPI0_other(void){
	PutStr("Please set the switch to QspiBoard-SPI0 side. Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(70);
}

// Hyper Flash Memory
const prg_tbl SwChgHyperFlash[BOARD_COUNT] = {
	(void (*)())SwChgHyperFlash_SALVATOR,
	(void (*)())SwChgHyperFlash_KRIEK,
	(void (*)())SwChgHyperFlash_SKIT,
	(void (*)())SwChgHyperFlash_KRIEK,
	(void (*)())SwChgHyperFlash_KRIEK,
	(void (*)())SwChgHyperFlash_other,
};
void SwChgHyperFlash_other(void){
	PutStr("Please set the switch to HyperFlash side. Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(66);
}


// eMMC
const prg_tbl SwChgeMMC[BOARD_COUNT] = {
	(void (*)())SwChgeMMC_other,
	(void (*)())SwChgeMMC_KRIEK,
	(void (*)())SwChgeMMC_other,
	(void (*)())SwChgeMMC_other,
	(void (*)())SwChgeMMC_other,
	(void (*)())SwChgeMMC_other,
};
void SwChgeMMC_other(void){
	;
}


//-- SALBATOR ---------------------------------------------------------------
void SwChgOnBoard_QSPI0_SALVATOR(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0)
	PutStr("SW1 SW2 All ON!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 OFF!           Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW13 1pin-Side!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0) */
}
void SwChgExSPI_QSPI0_SALVATOR(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0)
	PutStr("SW1 SW2 All ON!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 OFF!           Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW13 3pin-Side!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("CN3 : QSPI Flash Board Set OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0) */
}
void SwChgHyperFlash_SALVATOR(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0)
	PutStr("SW1 SW2 All OFF!   Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 ON!            Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0) */
}

//-- KRIEK ------------------------------------------------------------------
void SwChgOnBoard_QSPI0_KRIEK(void){
	PutStr("SW1 SW2 All ON!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 OFF!           Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW31 OFF!          Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW13 1pin-Side!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
}
void SwChgExSPI_QSPI0_KRIEK(void){
	PutStr("SW1 SW2 All ON!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 OFF!           Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW31 OFF!          Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW13 3pin-Side!    Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("CN3 : QSPI Flash Board Set OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
}
void SwChgHyperFlash_KRIEK(void){
	PutStr("SW1 SW2 All OFF!   Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW3 ON!            Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
	PutStr("SW31 ON!           Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(43);
}
void SwChgeMMC_KRIEK(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0)
	PutStr("SW32 All OFF! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(39);
	PutStr("SW33 All ON!  Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(39);
	PutStr("SW35 SW36 SW37 OFF! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(45);
	PutStr("SW39 SW40 SW41 ON!  Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(45);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 0) */
}
//-- STARTER KIT ------------------------------------------------------------
void SwChgOnBoard_QSPI0_SKIT(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1)
	PutStr("SW1    OFF!               Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
	PutStr("SW6[3] OFF!               Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
	PutStr("JP1 1pin-2pin Connection! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1) */
}
void SwChgExSPI_QSPI0_SKIT(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1)
	PutStr("SW1    OFF!               Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
	PutStr("SW6[3] OFF!               Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
	PutStr("JP1 3pin-2pin Connection! Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1) */
}
void SwChgHyperFlash_SKIT(void){
#if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1)
	PutStr("SW1    ON!                Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
	PutStr("SW6[3] ON!                Setting OK? (Push Y key)",0);	WaitKeyIn_Y();	DelStr(50);
#endif /* if defined (RCAR_GEN3_SALVATOR) && (RCAR_GEN3_ULCB == 1) */
}
//===========================================================================


