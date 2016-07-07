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

/**
 * @file  emmc_config.h
 * @brief Configuration file
 *
 */

#ifndef __EMMC_CONFIG_H__
#define __EMMC_CONFIG_H__

/* ************************ HEADER (INCLUDE) SECTION *********************** */

/* ***************** MACROS, CONSTANTS, COMPILATION FLAGS ****************** */

/** @brief eMMC address map
 */
#define SYS_RAM_BASE_ADD				0xE6300000UL									/* SYSTEM RAM BASE ADD							*/
#define EMMC_MULTI_BOOT_SADD			0x00004000UL									/* Multi Boot start add	(512byte order)			*/
#define EMMC_MULTI_BOOT_SIZE			0x0000A000UL									/* Multi Boot size		(512byte order)			*/
#define EMMC_MULTI_BOOT_DEST_ADD		(SYS_RAM_BASE_ADD + EMMC_MULTI_BOOT_SADD)		/* Multi Boot dest add							*/
#define EMMC_UBOOT_TRANS_DATA_SADD		0x0001EFF0UL									/* UBOOT trans data add							*/
#define EMMC_UBOOT_TRANS_DATA_DEST_ADD	(SYS_RAM_BASE_ADD + EMMC_UBOOT_TRANS_DATA_SADD)	/* UBOOT trans data dest add (512byte order)	*/

#define EMMC_UBOOT_TRANS_DEST_ADD_INDEX	((EMMC_UBOOT_TRANS_DATA_SADD & 0x1FF)>>2)		/* UBOOT trans dest add index					*/
#define EMMC_UBOOT_TRANS_SIZE_INDEX		(EMMC_UBOOT_TRANS_DEST_ADD_INDEX+1)				/* UBOOT trans size index						*/

/** @brief MMC driver config
 */
#define EMMC_RCA                1UL                       /* RCA  */
#define EMMC_RW_DATA_TIMEOUT    0x40UL                    /* 345ms (freq = 400KHz, timeout Counter = 0x04(SDCLK * 2^17)  */
#define EMMC_RETRY_COUNT        0                         /* how many times to try after fail. Don't change. */
#define EMMC_CMD_MAX            60UL                      /* Don't change. */

/** @brief etc
 */
#define LOADIMAGE_FLAGS_DMA_ENABLE              0x00000001UL


/* ********************** STRUCTURES, TYPE DEFINITIONS ********************* */
//#define EMMC_VOLTAGE_1_8		/* 			Voltage=1.8V driver spec 1/2		*/
								/* invalid: Voltage=3.3V driver spec 3/4		*/
//#define EMMC_DEBUG			/* eMMC drv debug log output					*/
								/* 1st Cut: No conditions						*/
								/* 2nd Cut: After the multi-boot was successful	*/
//#define EMMC_TOOL_DUMP		/* eMMC Tool dump log output					*/
/* ********************** DECLARATION OF EXTERNAL DATA ********************* */

/* ************************** FUNCTION PROTOTYPES ************************** */

/* ********************************* CODE ********************************** */

#endif  /* #ifndef __EMMC_CONFIG_H__ */
/* ******************************** END ************************************ */

