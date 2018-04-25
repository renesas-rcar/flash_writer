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

#include	"dgtable.h"
/**********************
*  TITLE              *
***********************/

const char *const StartMessMonitor[START_MESS_MON_LINE] = {
#ifdef RCAR_GEN3_SALVATOR
				"Flash writer for R-Car H3/M3/M3N Series V1.06 Apr.25,2018",
#endif /* RCAR_GEN3_SALVATOR */
#ifdef RCAR_GEN3_EBISU
				"Flash writer for R-Car E3 Series V1.06 Apr.25,2018",
#endif /* RCAR_GEN3_EBISU */
#ifdef RCAR_GEN3_DRAAK
				"Flash writer for R-Car D3 Series V1.06 Apr.25,2018",
#endif /* RCAR_GEN3_DRAAK */
				MESSAGE_END,
};


const char *const AllHelpMess[ALL_HELP_MESS_LINE] = {
#if SERIAL_FLASH == 1
				"        HyperFlash/SPI Flash write command",
				" XCS            erase program to HyperFlash/SPI Flash",
				" XLS2           write program to HyperFlash/SPI Flash",
				" XLS3           write program to HyperFlash/SPI Flash(Binary)",
				"",
#endif /* SERIAL_FLASH == 1 */
#if EMMC == 1
				"        eMMC write command",
				" EM_DCID        display register CID",
				" EM_DCSD        display register CSD",
				" EM_DECSD       display register EXT_CSD",
				" EM_SECSD       change register EXT_CSD byte",
				" EM_W           write program to eMMC",
				" EM_WB          write program to eMMC (Binary)",
				" EM_E           erase program to eMMC",
#endif /* EMMC == 1 */
				" SUP            Scif speed UP (Change to speed up baud rate setting)",
				" H              help",
				MESSAGE_END,
};
