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

/** 
 * @file  emmc_init.c
 * @brief eMMC boot initialize program.
 *
 */

/* ************************ HEADER (INCLUDE) SECTION *********************** */
#include "emmc_config.h"
#include "emmc_hal.h"
#include "emmc_std.h"
#include "emmc_registers.h"
#include "emmc_def.h"
//#include "reg_rcare2x.h"
#include "reg_rcarh3.h"
#include "common.h"
#include "bit.h"
#include "timer_api.h"

/* ***************** MACROS, CONSTANTS, COMPILATION FLAGS ****************** */

/* ********************** STRUCTURES, TYPE DEFINITIONS ********************* */

/* ********************** DECLARATION OF EXTERNAL DATA ********************* */

/* ************************** FUNCTION PROTOTYPES ************************** */
static void emmc_drv_init(void);
static EMMC_ERROR_CODE emmc_dev_init(void);
static EMMC_ERROR_CODE emmc_dev_finalize(void);
static void emmc_memset(uint8_t *buff, uint8_t data, uint32_t cnt);
static EMMC_ERROR_CODE emmc_reset_controller(void);
static void emmc_driver_config (void);
__inline static void emmc_set_retry_count(uint32_t retry);
__inline static void emmc_set_data_timeout(uint32_t data_timeout);

#ifdef EMMC_VOLTAGE_1_8
static void SetMmcPfcVoltage(uint32_t voltage);
static void SetMmcVoltage(uint32_t voltage);
static void InitMmcPinFunction(void);
#endif /* EMMC_VOLTAGE_1_8 */

/* ********************************* CODE ********************************** */

/** @brief eMMC initialize.
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * .
 * 
 * @param[in] low_clock_mode_enable TRUE = low clock mode(max26MHz), FALSE= Normal clock mode(Max52MHz)
 * @retval EMMC_SUCCESS successful.
 * @retval EMMC_ERR error from interrupt API.
 */
EMMC_ERROR_CODE emmc_init(uint8_t low_clock_mode_enable)
{
	EMMC_ERROR_CODE retult;

	/* TMU2 TIMER ON */
	PowerOnTmu2();

	/* initialize H/W */
    retult = emmc_reset_controller();
	if( EMMC_SUCCESS != retult )
	{
		return retult;
	}

    /* Configuration */
    emmc_driver_config();

    /* clock mode */
    mmc_drv_obj.low_clock_mode_enable = low_clock_mode_enable;

    return EMMC_SUCCESS;
}

/** @brief terminate emmc driver
 *
 * EMMC H/W and S/W resource is released.
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * .
 * 
 * @return None.
 */
EMMC_ERROR_CODE emmc_terminate (void)
{
    EMMC_ERROR_CODE result;

   /* H/W finalize */
    result = emmc_dev_finalize();
    if (result != EMMC_SUCCESS)
    {
        /* nothing to do. */
    }

    /* driver finalize */
    emmc_memset((uint8_t *)(&mmc_drv_obj), 0, sizeof(st_mmc_base));  /* clear global variable */

	/* TMU2 TIMER OFF */
	PowerOffTmu2();

    return result;
}

/** @brief Function executes full reset to MMC host controller without taking power out from the memory card.
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * Reset MMC host controller without taking power out from the memory card.
 * Memory card preserves its state.
 * 
 * @return None
 */
static EMMC_ERROR_CODE emmc_reset_controller(void)
{
	EMMC_ERROR_CODE retult;
	
    /* initialize mmc driver */
    emmc_drv_init();

    /* initialize H/W */
    retult = emmc_dev_init();
	if( EMMC_SUCCESS != retult )
	{
		return retult;
	}

    mmc_drv_obj.initialize = TRUE;

	return retult;

}

/** @brief Configuration eMMC driver
 * 
 * - Pre-conditions:<BR>
 * initialized eMMC driver.
 * - Post-conditions:<BR>
 * .
 * 
 * @return None
 */
static void emmc_driver_config (void)
{
    /* retry */
    emmc_set_retry_count(EMMC_RETRY_COUNT);

    /* Read/Write data timeout */
    emmc_set_data_timeout(EMMC_RW_DATA_TIMEOUT);
}


/** @brief  Registers configuration
 *
 * This function gives the configuration arguments to the driver.
 * It must be possible to call this function multiple times.
 * 
 * - Pre-conditions:<BR>
 * initialized eMMC driver.
 * 
 * - Post-conditions:<BR>
 * Driver is using configuration values.
 * 
 * @param[in] retry how many times to try after fail, for instance sending command.
 * @return None
 */
__inline static void emmc_set_retry_count (
    uint32_t  retry
    )
{
    mmc_drv_obj.retries_after_fail = retry;
}

/** @brief Sets data timeout
 *
 * Sets the data timeout value for read and write operations.
 * 
 * - Pre-conditions:<BR>
 * initialized eMMC driver.
 * 
 * - Post-conditions:<BR>
 * After this function is called, the timeout value is set according to argument. 
 * 
 * @param[in] time_out The desired timeout value in milliseconds.
 * @return None
 */
__inline static void emmc_set_data_timeout (
    uint32_t data_timeout
    )
{
    mmc_drv_obj.data_timeout = data_timeout;
}

/** @brief eMMC driver initialize. (software)
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * .
 * 
 * @return None.
 */
static void emmc_drv_init(void)
{
    /* initialize */
    emmc_memset((uint8_t *)(&mmc_drv_obj), 0, sizeof(st_mmc_base));
    
    mmc_drv_obj.card_present = HAL_MEMCARD_CARD_IS_IN;
    mmc_drv_obj.data_timeout = EMMC_RW_DATA_TIMEOUT;
    
    mmc_drv_obj.bus_width = HAL_MEMCARD_DATA_WIDTH_1_BIT;
}

/** @brief eMMC driver initialize. (H/W)
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * .
 * 
 * @return None.
 */
static EMMC_ERROR_CODE emmc_dev_init(void)
{
	uint32_t mmc_ch = USE_MMC_CH;
	uint32_t dataL;
	uint32_t tmp_val;
	volatile uint32_t* adr_cpg_sdxckcr;

	switch(mmc_ch) {
		case 0x0 :
			tmp_val	= BIT12;
			adr_cpg_sdxckcr	= (volatile uint32_t*)CPG_SD2CKCR;
			break;
		case 0x1 :
			tmp_val	= BIT11;
			adr_cpg_sdxckcr	= (volatile uint32_t*)CPG_SD3CKCR;
			break;
	}

	/* Power on eMMC */
	dataL = *((volatile uint32_t*)CPG_SMSTPCR3);
	if ((dataL) & (tmp_val)) {
		dataL &= ~(tmp_val);
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR3) = dataL;
	}

	dataL = *((volatile uint32_t*)CPG_MSTPSR3);
	while ( (dataL & (tmp_val)) != 0x0 ) {// wait tmp_val=0
		dataL = *((volatile uint32_t*)CPG_MSTPSR3);
	}
	
	/* Set SD clock */
	*((volatile uint32_t*)CPG_CPGWPR) = ~(BIT9|BIT0);	//SD phy 200MHz
	/* Stop SDnH clock & SDn=200MHz */
	*adr_cpg_sdxckcr = (BIT9|BIT0); 

#ifdef EMMC_VOLTAGE_1_8
	InitMmcPinFunction();
	SetMmcVoltage(1);	/* I/O Voltage=1.8V */
	StartTMU2(10);		/* wait 100ms		*/
#endif /* EMMC_VOLTAGE_1_8 */
	
	/* MMCIF initialize */
	SETR_32(SD_INFO1, 0x00000000U);			/* all interrupt clear */
	SETR_32(SD_INFO2, SD_INFO2_CLEAR );			/* all interrupt clear */
	SETR_32(SD_INFO1_MASK, 0x00000000U);		/* all interrupt disable */
	SETR_32(SD_INFO2_MASK, SD_INFO2_CLEAR );	/* all interrupt disable */

	SETR_32(HOST_MODE, 0x00000000U);			/* SD_BUF access width = 64-bit */
	SETR_32(SD_OPTION, 0x0000C0EEU);  		/* Bus width = 1bit, timeout=MAX */
	SETR_32(SD_CLK_CTRL, 0x00000000U);		/* Automatic Control=Disable, Clock Output=Disable */

    return EMMC_SUCCESS;
}

/** @brief EMMC H/W finalize 
 *
 * EMMC Host and Card hardware resource is released.
 *
 * - Pre-conditions:<BR>
 * .
 *
 * - Post-conditions:<BR>
 * .
 * @return None.
 */
static EMMC_ERROR_CODE emmc_dev_finalize(void)
{
    EMMC_ERROR_CODE result;
	uint32_t mmc_ch = USE_MMC_CH;
	uint32_t dataL;
	uint32_t tmp_val;

    /* MMC power off
     * the power supply of eMMC device is always turning on. 
     * RST_n : Hi --> Low level.
     */
    result = emmc_memcard_power(FALSE);
    if (result != EMMC_SUCCESS)
    {
        /* nothing to do. */
    }

    /* host controller reset */
//	SETR_32(SOFT_RST, ( GETR(SOFT_RST) & (~SOFT_RST_SDRST) ) );		/* Soft reset */
//	SETR_32(SOFT_RST, ( GETR(SOFT_RST) | SOFT_RST_SDRST ) );		/* Soft reset released */
	SETR_32(SD_INFO1, 0x00000000U);			/* all interrupt clear */
	SETR_32(SD_INFO2, SD_INFO2_CLEAR );		/* all interrupt clear */
	SETR_32(SD_INFO1_MASK, 0x00000000U);	/* all interrupt disable */
	SETR_32(SD_INFO2_MASK, SD_INFO2_CLEAR );	/* all interrupt disable */
	SETR_32(SD_CLK_CTRL, 0x00000000U);		/* MMC clock stop */

	switch (mmc_ch) {
		case 0x0 :
			tmp_val	= BIT12;
			break;
		case 0x1 :
			tmp_val	= BIT11;
			break;
	}

	
	dataL = *((volatile uint32_t*)CPG_SMSTPCR3);
	if ((dataL & tmp_val) == 0U) {
		dataL |= (tmp_val);
		*((volatile uint32_t*)CPG_CPGWPR)   = ~dataL;
		*((volatile uint32_t*)CPG_SMSTPCR3) = dataL;
	}

    return result;
}

/** @brief Set power to memory card IF.
 * This function control Vcc and Vccq and RST_n.
 *
 * @attention
 * CPU cannot control Vcc&Vccq.
 * The power supply of eMMC device is always turning on. 
 * 
 * @param[in] mode TRUE = power on, FALSE = power off
 * 
 * @retval EMMC_SUCCESS powering succeeded
 * @retval EMMC_ERR_CARD_POWER powering failed 
 */
EMMC_ERROR_CODE emmc_memcard_power
    (
    uint8_t mode
    )
{

    if (mode == TRUE)
    {
        /* power on (Vcc&Vccq is always power on) */
        mmc_drv_obj.card_power_enable = TRUE;
    }
    else
    {
        /* power off (Vcc&Vccq is always power on) */
        mmc_drv_obj.card_power_enable = FALSE;
        mmc_drv_obj.mount = FALSE;
        mmc_drv_obj.selected = FALSE;
    }

    return EMMC_SUCCESS;
}

/** @brief memset(). no use C standard library.
 * 
 * - Pre-conditions:<BR>
 * .
 * - Post-conditions:<BR>
 * .
 * 
 * @param[in,out] buff pointer to buffer (virtual)
 * @param[in] data fill data.
 * @param[in] cnt fill size (number of bytes)
 * @return None.
 */

static void emmc_memset(
    uint8_t *buff,
    uint8_t data,
    uint32_t cnt
    )
{
    if (buff == NULL)
    {
        return;
    }

    while (cnt > 0)
    {
        *buff++ = data;
        cnt--;
    }
}

#ifdef EMMC_VOLTAGE_1_8
// voltage=0: 1.8V
// voltage=1: 3.3V
static void SetMmcPfcVoltage(uint32_t voltage)
{
#ifdef EMMC_VOLTAGE_1_8
	uint32_t dataL;
#ifdef EMMC_DEBUG
	char str[16];
	int32_t chCnt;

	PutStr("PFC_IOCTRL6 Before  = 0x", 0);
	Hex2Ascii(GETR_32(PFC_IOCTRL6), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */

	dataL = *((volatile uint32_t*)PFC_IOCTRL6);
	if(voltage)	dataL |=  (BIT2);	// Case 3.3V
	else		dataL &= ~(BIT2);	// Case 1.8V
	*((volatile uint32_t*)PFC_PMMR)    = ~dataL;
	*((volatile uint32_t*)PFC_IOCTRL6) =  dataL;
	if(voltage)	while( !(BIT2 & *((volatile uint32_t*)PFC_IOCTRL6)) );	// wait 1
	else		while(  (BIT2 & *((volatile uint32_t*)PFC_IOCTRL6)) );	// wait 0

#ifdef EMMC_DEBUG
    PutStr("PFC_IOCTRL6 After   = 0x", 0);
	Hex2Ascii(GETR_32(PFC_IOCTRL6), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */
#endif /* EMMC_VOLTAGE_1_8 */
}

// voltage=0: 1.8V
// voltage=1: 3.3V
static void SetMmcVoltage(uint32_t voltage)
{
#ifdef EMMC_VOLTAGE_1_8
#ifdef EMMC_DEBUG
	char str[16];
	int32_t chCnt;

	PutStr("GPIO_OUTDT5 Before  = 0x", 0);
	Hex2Ascii(GETR_32(GPIO_OUTDT5), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */

	if(voltage){
		// IO=3.3V : 1.8V->3.3V before change IOsel voltage
		SetMmcPfcVoltage(1);											// set voltage 3.3V
		*((volatile uint32_t*)GPIO_OUTDT5) |=  BIT25;				// VCCQ_MMC : 3.3V
		while( !(BIT25 & *((volatile uint32_t*)GPIO_OUTDT5)) );	// wait 1
		StartTMU2(1);													// wait 10ms  (DVC: (3.3V-1.8V) / (10mV/4us) = 0.6ms)
	}else{
		// IO=1.8V : 3.3V->1.8V after change IOsel voltage
		*((volatile uint32_t*)GPIO_OUTDT5) &= ~BIT25;				// VCCQ_MMC : 1.8V
		while(  (BIT25 & *((volatile uint32_t*)GPIO_OUTDT5)) );	// wait 0
		StartTMU2(1);													// wait 10ms  (DVC: (3.3V-1.8V) / (10mV/4us) = 0.6ms)
		SetMmcPfcVoltage(0);											// set voltage 1.8V
	}

#ifdef EMMC_DEBUG
    PutStr("GPIO_OUTDT5 After   = 0x", 0);
	Hex2Ascii(GETR_32(GPIO_OUTDT5), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */
#endif /* EMMC_VOLTAGE_1_8 */
}

static void InitMmcPinFunction(void)
{
#ifdef EMMC_VOLTAGE_1_8
	uint32_t dataL;
#ifdef EMMC_DEBUG
	char str[16];
	int32_t chCnt;
#endif /* EMMC_DEBUG */

#ifdef EMMC_DEBUG
    PutStr("GPIO_INOUTSEL5 Before  = 0x", 0);
	Hex2Ascii(GETR_32(GPIO_INOUTSEL5), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */
	// GPSR5[25]    --> GPIO-Output (3.3V/1.8V select)
	// GP5[25] OUT-PORT-----
	dataL = *((volatile uint32_t*)GPIO_INOUTSEL5);
	dataL |= (BIT25);
	*((volatile uint32_t*)GPIO_INOUTSEL5) = dataL;
#ifdef EMMC_DEBUG
    PutStr("GPIO_INOUTSEL5 After   = 0x", 0);
	Hex2Ascii(GETR_32(GPIO_INOUTSEL5), str, &chCnt);
    PutStr(str, 1);
#endif /* EMMC_DEBUG */
#endif /* EMMC_VOLTAGE_1_8 */
}
#endif /* EMMC_VOLTAGE_1_8 */

/* ******************************** END ************************************ */

