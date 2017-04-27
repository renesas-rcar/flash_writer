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

#define __EMMC_GLOBAL_DEFINE__
#include "emmc_config.h"
#include "emmc_hal.h"
#include "emmc_std.h"
#include "emmc_registers.h"
#include "emmc_def.h"
#undef __EMMC_GLOBAL_DEFINE__

#include "dgemmc.h"
#include "common.h"
#include "bit.h"
#include "types.h"

#define SIZE_TEST

#define		EMMC_PRR		0xFF000044U			/* Product Register */

#define		EXT_CSD_INDEX_MAX			(511U)
#define		EXT_CSD_VALUE_MAX			(0xFF)

#ifdef EXTCSD_PROTECT
#define		EXT_CSD_WRITE_INDEX_NUM		(37U)
#define		EXT_CSD_PROTECT_INDEX_NUM	(5U)
#else /* EXTCSD_PROTECT */
#define		EXT_CSD_WRITE_INDEX_NUM		(32U)
#endif /* EXTCSD_PROTECT */

typedef enum{
	EMMC_EXT_CSD_INPUT_END = 0,
	EMMC_EXT_CSD_INPUT_VALUE,
	EMMC_EXT_CSD_INPUT_INDEX
}EMMC_EXT_CSD_INPUT;

typedef enum
{
	CID_FIELD_MID = 0,
	CID_FIELD_CBX,
	CID_FIELD_OID,
	CID_FIELD_PNM,
	CID_FIELD_PRV,
	CID_FIELD_PSN,
	CID_FIELD_MDT,
	CID_FIELD_CRC,
	CID_FIELD_MAX
}CID_FIELD;

typedef enum
{
	CSD_FIELD_CSD_STRUCTURE = 0,
	CSD_FIELD_SPEC_VERS,
	CSD_FIELD_TAAC,
	CSD_FIELD_NSAC,
	CSD_FIELD_TRAN_SPEED,
	CSD_FIELD_CCC,
	CSD_FIELD_READ_BL_LEN,
	CSD_FIELD_READ_BL_PARTIAL,
	CSD_FIELD_WRITE_BLK_MISALIGN,
	CSD_FIELD_READ_BLK_MISALIGN,
	CSD_FIELD_DSR_IMP,
	CSD_FIELD_C_SIZE,
	CSD_FIELD_VDD_R_CURR_MIN,
	CSD_FIELD_VDD_R_CURR_MAX,
	CSD_FIELD_VDD_W_CURR_MIN,
	CSD_FIELD_VDD_W_CURR_MAX,
	CSD_FIELD_C_SIZE_MULT,
	CSD_FIELD_ERASE_GRP_SIZE,
	CSD_FIELD_ERASE_GRP_MULT,
	CSD_FIELD_WP_GRP_SIZE,
	CSD_FIELD_WP_GRP_ENABLE,
	CSD_FIELD_DEFAULT_ECC,
	CSD_FIELD_R2W_FACTOR,
	CSD_FIELD_WRITE_BL_LEN,
	CSD_FIELD_WRITE_BL_PARTIAL,
	CSD_FIELD_CONTENT_PROT_APP,
	CSD_FIELD_FILE_FORMAT_GRP,
	CSD_FIELD_COPY,
	CSD_FIELD_PERM_WRITE_PROTECT,
	CSD_FIELD_TMP_WRITE_PROTECT,
	CSD_FIELD_FILE_FORMAT,
	CSD_FIELD_ECC,
	CSD_FIELD_CRC,
	CSD_FIELD_MAX
}CSD_FIELD;

typedef enum
{
	EXT_CSD_FIELD_EXT_SECURITY_ERR = 0,
	EXT_CSD_FIELD_S_CMD_SET,
	EXT_CSD_FIELD_HPI_FEATURES,
	EXT_CSD_FIELD_BKOPS_SUPPORT,
	EXT_CSD_FIELD_MAX_PACKED_READS,
	EXT_CSD_FIELD_MAX_PACKED_WRITES,
	EXT_CSD_FIELD_DATA_TAG_SUPPORT,
	EXT_CSD_FIELD_TAG_UNIT_SIZE,
	EXT_CSD_FIELD_TAG_RES_SIZE,
	EXT_CSD_FIELD_CONTEXT_CAPABILITIES,
	EXT_CSD_FIELD_LARGE_UNIT_SIZE_M1,
	EXT_CSD_FIELD_EXT_SUPPORT,
	EXT_CSD_FIELD_SUPPORTED_MODES,
	EXT_CSD_FIELD_FFU_FEATURES,
	EXT_CSD_FIELD_OPERATION_CODE_TIMEOUT,
	EXT_CSD_FIELD_FFU_ARG,
	EXT_CSD_FIELD_NUMBER_OF_FW_SECTORS_CORRECTLY_PROGRAMMED,
	EXT_CSD_FIELD_VENDOR_PROPRIETARY_HEALTH_REPORT,
	EXT_CSD_FIELD_DEVICE_LIFE_TIME_EST_TYP_B,
	EXT_CSD_FIELD_DEVICE_LIFE_TIME_EST_TYP_A,
	EXT_CSD_FIELD_PRE_EOL_INFO,
	EXT_CSD_FIELD_OPTIMAL_READ_SIZE,
	EXT_CSD_FIELD_OPTIMAL_WRITE_SIZE,
	EXT_CSD_FIELD_OPTIMAL_TRIM_UNIT_SIZE,
	EXT_CSD_FIELD_DEVICE_VERSION,
	EXT_CSD_FIELD_FIRMWARE_VERSION,
	EXT_CSD_FIELD_PWR_CL_DDR_200_360,
	EXT_CSD_FIELD_CACHE_SIZE,
	EXT_CSD_FIELD_GENERIC_CMD6_TIME,
	EXT_CSD_FIELD_POWER_OFF_LONG_TIME,
	EXT_CSD_FIELD_BKOPS_STATUS,
	EXT_CSD_FIELD_CORRECTLY_PRG_SECTORS_NUM,
	EXT_CSD_FIELD_INI_TIMEOUT_AP,
	EXT_CSD_FIELD_PWR_CL_DDR_52_360,
	EXT_CSD_FIELD_PWR_CL_DDR_52_195,
	EXT_CSD_FIELD_PWR_CL_200_195,
	EXT_CSD_FIELD_PWR_CL_200_130,
	EXT_CSD_FIELD_MIN_PERF_DDR_W_8_52,
	EXT_CSD_FIELD_MIN_PERF_DDR_R_8_52,
	EXT_CSD_FIELD_TRIM_MULT,
	EXT_CSD_FIELD_SEC_FEATURE_SUPPORT,
	EXT_CSD_FIELD_SEC_ERASE_MULT,
	EXT_CSD_FIELD_SEC_TRIM_MULT,
	EXT_CSD_FIELD_BOOT_INFO,
	EXT_CSD_FIELD_BOOT_SIZE_MULTI,
	EXT_CSD_FIELD_ACC_SIZE,
	EXT_CSD_FIELD_HC_ERASE_GRP_SIZE,
	EXT_CSD_FIELD_ERASE_TIMEOUT_MULT,
	EXT_CSD_FIELD_REL_WR_SEC_C,
	EXT_CSD_FIELD_HC_WP_GRP_SIZE,
	EXT_CSD_FIELD_S_C_VCC,
	EXT_CSD_FIELD_S_C_VCCQ,
	EXT_CSD_FIELD_PRODUCTION_STATE_AWARENESS_TIMEOUT,
	EXT_CSD_FIELD_S_A_TIMEOUT,
	EXT_CSD_FIELD_SLEEP_NOTIFICATION_TIME,
	EXT_CSD_FIELD_SEC_COUNT,
	EXT_CSD_FIELD_MIN_PERF_W_8_52,
	EXT_CSD_FIELD_MIN_PERF_R_8_52,
	EXT_CSD_FIELD_MIN_PERF_W_8_26_4_52,
	EXT_CSD_FIELD_MIN_PERF_R_8_26_4_52,
	EXT_CSD_FIELD_MIN_PERF_W_4_26,
	EXT_CSD_FIELD_MIN_PERF_R_4_26,
	EXT_CSD_FIELD_PWR_CL_26_360,
	EXT_CSD_FIELD_PWR_CL_52_360,
	EXT_CSD_FIELD_PWR_CL_26_195,
	EXT_CSD_FIELD_PWR_CL_52_195,
	EXT_CSD_FIELD_PARTITION_SWITCH_TIME,
	EXT_CSD_FIELD_OUT_OF_INTERRUPT_TIME,
	EXT_CSD_FIELD_DRIVER_STRENGTH,
	EXT_CSD_FIELD_CARD_TYPE,
	EXT_CSD_FIELD_CSD_STRUCTURE,
	EXT_CSD_FIELD_EXT_CSD_REV,
	EXT_CSD_FIELD_CMD_SET,
	EXT_CSD_FIELD_CMD_SET_REV,
	EXT_CSD_FIELD_POWER_CLASS,
	EXT_CSD_FIELD_HS_TIMING,
	EXT_CSD_FIELD_BUS_WIDTH,
	EXT_CSD_FIELD_ERASED_MEM_CONT,
	EXT_CSD_FIELD_PARTITION_CONFIG,
	EXT_CSD_FIELD_BOOT_CONFIG_PROT,
	EXT_CSD_FIELD_BOOT_BUS_WIDTH,
	EXT_CSD_FIELD_ERASE_GROUP_DEF,
	EXT_CSD_FIELD_BOOT_WP,
	EXT_CSD_FIELD_USER_WP,
	EXT_CSD_FIELD_FW_CONFIG,
	EXT_CSD_FIELD_RPMB_SIZE_MULT,
	EXT_CSD_FIELD_WR_REL_SET,
	EXT_CSD_FIELD_WR_REL_PARAM,
	EXT_CSD_FIELD_SANITIZE_START,
	EXT_CSD_FIELD_BKOPS_START,
	EXT_CSD_FIELD_BKOPS_EN,
	EXT_CSD_FIELD_RST_n_FUNCTION,
	EXT_CSD_FIELD_HPI_MGMT,
	EXT_CSD_FIELD_PARTITIONING_SUPPORT,
	EXT_CSD_FIELD_MAX_ENH_SIZE_MULT,
	EXT_CSD_FIELD_PARTITIONS_ATTRIBUTE,
	EXT_CSD_FIELD_PARTITION_SETTING_COMPLETED,
	EXT_CSD_FIELD_GP_SIZE_MULT,
	EXT_CSD_FIELD_ENH_SIZE_MULT,
	EXT_CSD_FIELD_ENH_START_ADDR,
	EXT_CSD_FIELD_SEC_BAD_BLK_MGMNT,
	EXT_CSD_FIELD_MAX
}EXT_CSD_FIELD;



typedef struct
{
	uint32_t top;
	uint32_t end;
	uint8_t name[48];
}EMMC_DISP_REGISTER_DATA;

const EMMC_DISP_REGISTER_DATA dg_cid_data[CID_FIELD_MAX] = {
	{	127,	120,	"MID  "},
	{	113,	112,	"CBX  "},
	{	111,	104,	"OID  "},
	{	103,	 56,	"PNM  "},
	{	 55,	 48,	"PRV  "},
	{	 47,	 16,	"PSN  "},
	{	 15,	  8,	"MDT  "},
	{	  7,	  1,	"CRC  "},
};

const EMMC_DISP_REGISTER_DATA dg_csd_data[CSD_FIELD_MAX] = {
	{	127,	126,	"CSD_STRUCTURE       "},
	{	125,	122,	"SPEC_VERS           "},
	{	119,	112,	"TAAC                "},
	{	111,	104,	"NSAC                "},
	{	103,	 96,	"TRAN_SPEED          "},
	{	 95,	 84,	"CCC                 "},
	{	 83,	 80,	"READ_BL_LEN         "},
	{	 79,	 79,	"READ_BL_PARTIAL     "},
	{	 78,	 78,	"WRITE_BLK_MISALIGN  "},
	{	 77,	 77,	"READ_BLK_MISALIGN   "},
	{	 76,	 76,	"DSR_IMP             "},
	{	 73,	 62,	"C_SIZE              "},
	{	 61,	 59,	"VDD_R_CURR_MIN      "},
	{	 58,	 56,	"VDD_R_CURR_MAX      "},
	{	 55,	 53,	"VDD_W_CURR_MIN      "},
	{	 52,	 50,	"VDD_W_CURR_MAX      "},
	{	 49,	 47,	"C_SIZE_MULT         "},
	{	 46,	 42,	"ERASE_GRP_SIZE      "},
	{	 41,	 37,	"ERASE_GRP_MULT      "},
	{	 36,	 32,	"WP_GRP_SIZE         "},
	{	 31,	 31,	"WP_GRP_ENABLE       "},
	{	 30,	 29,	"DEFAULT_ECC         "},
	{	 28,	 26,	"R2W_FACTOR          "},
	{	 25,	 22,	"WRITE_BL_LEN        "},
	{	 21,	 21,	"WRITE_BL_PARTIAL    "},
	{	 16,	 16,	"CONTENT_PROT_APP    "},
	{	 15,	 15,	"FILE_FORMAT_GRP     "},
	{	 14,	 14,	"COPY                "},
	{	 13,	 13,	"PERM_WRITE_PROTECT  "},
	{	 12,	 12,	"TMP_WRITE_PROTECT   "},
	{	 11,	 10,	"FILE_FORMAT         "},
	{	  9,	  8,	"ECC                 "},
	{	  7,	  1,	"CRC                 "},
};

const EMMC_DISP_REGISTER_DATA dg_ext_csd_data[EXT_CSD_FIELD_MAX] = {
	{	505,	505,	"EXT_SECURITY_ERR                           "},
	{	504,	504,	"S_CMD_SET                                  "},
	{	503,	503,	"HPI_FEATURES                               "},
	{	502,	502,	"BKOPS_SUPPORT                              "},
	{	501,	501,	"MAX_PACKED_READS                           "},
	{	500,	500,	"MAX_PACKED_WRITES                          "},
	{	499,	499,	"DATA_TAG_SUPPORT                           "},
	{	498,	498,	"TAG_UNIT_SIZE                              "},
	{	497,	497,	"TAG_RES_SIZE                               "},
	{	496,	496,	"CONTEXT_CAPABILITIES                       "},
	{	495,	495,	"LARGE_UNIT_SIZE_M1                         "},
	{	494,	494,	"EXT_SUPPORT                                "},
	{	493,	493,	"SUPPORTED_MODES                            "},
	{	492,	492,	"FFU_FEATURES                               "},
	{	491,	491,	"OPERATION_CODE_TIMEOUT                     "},
	{	490,	487,	"FFU_ARG                                    "},
	{	305,	302,	"NUMBER_OF_FW_SECTORS_CORRECTLY_PROGRAMMED  "},
	{	301,	270,	"VENDOR_PROPRIETARY_HEALTH_REPORT           "},
	{	269,	269,	"DEVICE_LIFE_TIME_EST_TYP_B                 "},
	{	268,	268,	"DEVICE_LIFE_TIME_EST_TYP_A                 "},
	{	267,	267,	"PRE_EOL_INFO                               "},
	{	266,	266,	"OPTIMAL_READ_SIZE                          "},
	{	265,	265,	"OPTIMAL_WRITE_SIZE                         "},
	{	264,	264,	"OPTIMAL_TRIM_UNIT_SIZE                     "},
	{	263,	262,	"DEVICE_VERSION                             "},
	{	261,	254,	"FIRMWARE_VERSION                           "},
	{	253,	253,	"PWR_CL_DDR_200_360                         "},
	{	252,	249,	"CACHE_SIZE                                 "},
	{	248,	248,	"GENERIC_CMD6_TIME                          "},
	{	247,	247,	"POWER_OFF_LONG_TIME                        "},
	{	246,	246,	"BKOPS_STATUS                               "},
	{	245,	242,	"CORRECTLY_PRG_SECTORS_NUM                  "},
	{	241,	241,	"INI_TIMEOUT_AP                             "},
	{	239,	239,	"PWR_CL_DDR_52_360                          "},
	{	238,	238,	"PWR_CL_DDR_52_195                          "},
	{	237,	237,	"PWR_CL_200_195                             "},
	{	236,	236,	"PWR_CL_200_130                             "},
	{	235,	235,	"MIN_PERF_DDR_W_8_52                        "},
	{	234,	234,	"MIN_PERF_DDR_R_8_52                        "},
	{	232,	232,	"TRIM_MULT                                  "},
	{	231,	231,	"SEC_FEATURE_SUPPORT                        "},
	{	230,	230,	"SEC_ERASE_MULT                             "},
	{	229,	229,	"SEC_TRIM_MULT                              "},
	{	228,	228,	"BOOT_INFO                                  "},
	{	226,	226,	"BOOT_SIZE_MULTI                            "},
	{	225,	225,	"ACC_SIZE                                   "},
	{	224,	224,	"HC_ERASE_GRP_SIZE                          "},
	{	223,	223,	"ERASE_TIMEOUT_MULT                         "},
	{	222,	222,	"REL_WR_SEC_C                               "},
	{	221,	221,	"HC_WP_GRP_SIZE                             "},
	{	220,	220,	"S_C_VCC                                    "},
	{	219,	219,	"S_C_VCCQ                                   "},
	{	218,	218,	"PRODUCTION_STATE_AWARENESS_TIMEOUT         "},
	{	217,	217,	"S_A_TIMEOUT                                "},
	{	216,	216,	"SLEEP_NOTIFICATION_TIME                    "},
	{	215,	212,	"SEC_COUNT                                  "},
	{	210,	210,	"MIN_PERF_W_8_52                            "},
	{	209,	209,	"MIN_PERF_R_8_52                            "},
	{	208,	208,	"MIN_PERF_W_8_26_4_52                       "},
	{	207,	207,	"MIN_PERF_R_8_26_4_52                       "},
	{	206,	206,	"MIN_PERF_W_4_26                            "},
	{	205,	205,	"MIN_PERF_R_4_26                            "},
	{	203,	203,	"PWR_CL_26_360                              "},
	{	202,	202,	"PWR_CL_52_360                              "},
	{	201,	201,	"PWR_CL_26_195                              "},
	{	200,	200,	"PWR_CL_52_195                              "},
	{	199,	199,	"PARTITION_SWITCH_TIME                      "},
	{	198,	198,	"OUT_OF_INTERRUPT_TIME                      "},
	{	197,	197,	"DRIVER_STRENGTH                            "},
	{	196,	196,	"CARD_TYPE                                  "},
	{	194,	194,	"CSD_STRUCTURE                              "},
	{	192,	192,	"EXT_CSD_REV                                "},
	{	191,	191,	"CMD_SET                                    "},
	{	189,	189,	"CMD_SET_REV                                "},
	{	187,	187,	"POWER_CLASS                                "},
	{	185,	185,	"HS_TIMING                                  "},
	{	183,	183,	"BUS_WIDTH                                  "},
	{	181,	181,	"ERASED_MEM_CONT                            "},
	{	179,	179,	"PARTITION_CONFIG                           "},
	{	178,	178,	"BOOT_CONFIG_PROT                           "},
	{	177,	177,	"BOOT_BUS_WIDTH                             "},
	{	175,	175,	"ERASE_GROUP_DEF                            "},
	{	173,	173,	"BOOT_WP                                    "},
	{	171,	171,	"USER_WP                                    "},
	{	169,	169,	"FW_CONFIG                                  "},
	{	168,	168,	"RPMB_SIZE_MULT                             "},
	{	167,	167,	"WR_REL_SET                                 "},
	{	166,	166,	"WR_REL_PARAM                               "},
	{	165,	165,	"SANITIZE_START                             "},
	{	164,	164,	"BKOPS_START                                "},
	{	163,	163,	"BKOPS_EN                                   "},
	{	162,	162,	"RST_n_FUNCTION                             "},
	{	161,	161,	"HPI_MGMT                                   "},
	{	160,	160,	"PARTITIONING_SUPPORT                       "},
	{	159,	157,	"MAX_ENH_SIZE_MULT                          "},
	{	156,	156,	"PARTITIONS_ATTRIBUTE                       "},
	{	155,	155,	"PARTITION_SETTING_COMPLETED                "},
	{	154,	143,	"GP_SIZE_MULT                               "},
	{	142,	140,	"ENH_SIZE_MULT                              "},
	{	139,	136,	"ENH_START_ADDR                             "},
	{	134,	134,	"SEC_BAD_BLK_MGMNT                          "},
};

#ifdef EXTCSD_PROTECT
const uint32_t extCsdWriteIndex[EXT_CSD_WRITE_INDEX_NUM] = {
	187,	185,	183,	179,	178,	177,	175,	173,	171,	169,
	167,	164,	163,	162,	161,	156,	155,	154,	153,	152,
	151,	150,	149,	148,	147,	146,	145,	144,	143,	142,
	141,	140,	139,	138,	137,	136,	134,
};

const uint32_t extCsdProtectIndex[EXT_CSD_PROTECT_INDEX_NUM] = {
	178,	173,	171,	169,	162,
};
#else /* EXTCSD_PROTECT */
const uint32_t extCsdWriteIndex[EXT_CSD_WRITE_INDEX_NUM] = {
	187,	185,	183,	179,	177,	175,	167,	164,	163,	161,
	156,	155,	154,	153,	152,	151,	150,	149,	148,	147,
	146,	145,	144,	143,	142,	141,	140,	139,	138,	137,
	136,	134,
};
#endif /* EXTCSD_PROTECT */

static void disp_cid(void);
static void disp_csd(void);
static void disp_ext_csd(void);
static uint32_t InputExtCsdParam( uint32_t *index, uint32_t *value );
static uint32_t emmcChkExtCsdWriteIndex(uint32_t index);
#ifdef EXTCSD_PROTECT
static uint32_t emmcChkExtCsdProtectIndex(uint32_t index);
static void warningChgProtectIndex(void);
#endif /* EXTCSD_PROTECT */
static void dispField( uint32_t start, uint32_t end );
static void dispOffset( int8_t cnt );


/****************************************************************
	MODULE				: dg_emmc_disp_cid 						*
	FUNCTION			: Display CID							*
	COMMAND				: EMMC_DCID								*
	INPUT PARAMETER		: EMMC_DCID								*
*****************************************************************/
void	dg_emmc_disp_cid(void)
{
	EMMC_ERROR_CODE result;

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}
	disp_cid();

	return;
}

/****************************************************************
	MODULE				: dg_emmc_disp_csd 						*
	FUNCTION			: Display CSD							*
	COMMAND				: EMMC_DCSD								*
	INPUT PARAMETER		: EMMC_DCSD								*
*****************************************************************/
void	dg_emmc_disp_csd(void)
{
	EMMC_ERROR_CODE result;

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}
	disp_csd();

	return;
}


/****************************************************************
	MODULE				: dg_emmc_disp_ext_csd 					*
	FUNCTION			: Display EXT_CID						*
	COMMAND				: EMMC_DECSD							*
	INPUT PARAMETER		: EMMC_DECSD							*
*****************************************************************/
void	dg_emmc_disp_ext_csd(void)
{
	EMMC_ERROR_CODE result;

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}

	/* CMD8 (EXT_CSD) */
    emmc_make_trans_cmd(CMD8_SEND_EXT_CSD, 0x00000000U, (uint32_t *)(&mmc_drv_obj.ext_csd_data[0]), EMMC_MAX_EXT_CSD_LENGTH, HAL_MEMCARD_READ, HAL_MEMCARD_NOT_DMA);
    result = emmc_exec_cmd(EMMC_R1_ERROR_MASK, mmc_drv_obj.response);
    if (result != EMMC_SUCCESS)
    {
        PutStr("CMD8 error",1);
        return;
    }

	disp_ext_csd();

	return;
}


/****************************************************************
	MODULE				: dg_emmc_set_ext_csd 					*
	FUNCTION			: Set EXT_CID							*
	COMMAND				: EMMC_DECSD							*
	INPUT PARAMETER		: EMMC_DECSD							*
*****************************************************************/
void	dg_emmc_set_ext_csd(void)
{
	EMMC_ERROR_CODE result;
	uint32_t chkInput;
	uint32_t index;
	uint32_t value;
	uint32_t arg;
	int8_t buf[16];
	int32_t chCnt;
#ifdef EXTCSD_PROTECT
	uint32_t chkProtect;
#endif /* EXTCSD_PROTECT */

	result = dg_emmc_check_init();
	if( EMMC_SUCCESS != result )
	{
		PutStr("eMMC Init ERROR!",1);
		return;
	}

	// emmc_set_ext_csd
	arg = ( EXTCSD_ACCESS_BYTE | ( EMMC_EXT_CSD_ERASE_GROUP_DEF << 16 ) | ( 1 << 8 ) );
	result = emmc_set_ext_csd(arg);
	if( EMMC_SUCCESS != result )
	{
		PutStr(" EM_SECSD ERASE_GROUP_DEF CHG ERR!", 1 );
		return;
	}

	/* CMD8 (EXT_CSD) */
    emmc_make_trans_cmd(CMD8_SEND_EXT_CSD, 0x00000000, (uint32_t *)(&mmc_drv_obj.ext_csd_data[0]), EMMC_MAX_EXT_CSD_LENGTH, HAL_MEMCARD_READ, HAL_MEMCARD_NOT_DMA);
    result = emmc_exec_cmd(EMMC_R1_ERROR_MASK, mmc_drv_obj.response);
    if (result != EMMC_SUCCESS)
    {
        PutStr("EM_SECSD CMD8 ERR!",1);
        return;
    }

	// Disp Change Before Values
//	disp_ext_csd();

	chkInput = InputExtCsdParam(&index, &value);
#ifdef EMMC_DEBUG
	PutStr("Index = ",0);
	Hex2DecAscii((int32_t)index,buf,&chCnt);
	PutStr(buf,1);
	PutStr("Value = 0x",0);
	Hex2Ascii((int32_t)value,buf,&chCnt);
	PutStr(buf,1);
#endif /* EMMC_DEBUG */
	if( 1 != chkInput )
	{
		return;
	}

#ifdef EXTCSD_PROTECT
	chkProtect = emmcChkExtCsdProtectIndex( index );
	if( 0 != chkProtect )
	{
		/* Warning */
		warningChgProtectIndex();
		if( WaitKeyIn_YorN() ){
			DelStr(34);
			PutStr(" EM_SECSD CANCEL!", 1 );
			return;
		}
		DelStr(34);
		warningChgProtectIndex();
		if( WaitKeyIn_YorN() ){
			DelStr(34);
			PutStr(" EM_SECSD CANCEL!", 1 );
			return;
		}
		DelStr(34);
	}
#endif /* EXTCSD_PROTECT */

	// emmc_set_ext_csd
	arg = ( EXTCSD_ACCESS_BYTE | ( index << 16 ) | ( value << 8 ) );
	result = emmc_set_ext_csd(arg);
	if( EMMC_SUCCESS != result )
	{
		PutStr(" EM_SECSD ERR!", 1 );
		return;
	}

	/* CMD8 (EXT_CSD) */
    emmc_make_trans_cmd(CMD8_SEND_EXT_CSD, 0x00000000, (uint32_t *)(&mmc_drv_obj.ext_csd_data[0]), EMMC_MAX_EXT_CSD_LENGTH, HAL_MEMCARD_READ, HAL_MEMCARD_NOT_DMA);
    result = emmc_exec_cmd(EMMC_R1_ERROR_MASK, mmc_drv_obj.response);
    if (result != EMMC_SUCCESS)
    {
        PutStr("EM_SECSD CMD8 ERR!",1);
        return;
    }

	// Disp Change After Values
	PutStr("  EXT_CSD[",0);
	Hex2Ascii(index,buf,&chCnt);
	PutStr(&buf[6],0);
	PutStr("] = 0x",0);
	Hex2Ascii((int32_t)mmc_drv_obj.ext_csd_data[index],buf,&chCnt);
	PutStr(&buf[6],1);

	return;
}


/****************************************************************
	MODULE				: disp_cid		 						*
	FUNCTION			: Display CID							*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void disp_cid(void)
{
	int8_t buf[16];
	uint32_t value;
	uint32_t loop;	
	uint32_t dispCnt;
	uint32_t top;
	uint32_t end;
	uint32_t cnt;
	uint32_t bitCnt;

#ifdef EMMC_TOOL_DUMP
	uint32_t i;
	// CSD=128bit
	/* dump disp */
	PutStr("",1);
	PutStr("[CID Raw Data]",1);
	PutStr("<--BIT127                               BIT0-->",1);
	for(i=0; i<EMMC_MAX_CID_LENGTH; i++){
		Data2HexAscii(mmc_drv_obj.cid_data[i],buf,1);
		PutStr(buf,0);
		PutStr(" ",0);
	}
	PutStr("",1);
#endif /* EMMC_TOOL_DUMP */

	/* field disp */
	PutStr("",1);
	PutStr("[CID Field Data]",1);
	for(loop = 0; loop < CID_FIELD_MAX; loop++)
	{
		dispField((int32_t)dg_cid_data[loop].top,(int32_t)dg_cid_data[loop].end);
		PutStr(dg_cid_data[loop].name,0);
		PutStr("0x",0);

		bitCnt = (dg_cid_data[loop].top - dg_cid_data[loop].end) + 1;
		dispCnt = ( bitCnt >> 3 );
		if(0 != (bitCnt & 0x7))
		{
			dispCnt++;
		}

		value = 0;
		for( cnt = dispCnt; cnt > 0; cnt-- )
		{
			end = dg_cid_data[loop].end + ((cnt-1) * 8);
			top = end + 7;
			if( top > dg_cid_data[loop].top )
			{
				top = dg_cid_data[loop].top;
			}
			value = EMMC_GET_CID(top,end);
			Data2HexAscii((uint32_t)value,buf,1);
			PutStr(buf,0);
		}
		PutStr("",1);
	}
	PutStr("",1);
}

/****************************************************************
	MODULE				: disp_csd		 						*
	FUNCTION			: Display CSD							*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void disp_csd(void)
{
	int8_t buf[16];
	uint32_t value;
	uint32_t loop;
	uint32_t dispCnt;
	uint32_t top;
	uint32_t end;
	uint32_t cnt;
	uint32_t bitCnt;

#ifdef EMMC_TOOL_DUMP
	uint32_t i;
	// CSD=128bit
	/* dump disp */
	PutStr("",1);
	PutStr("[CSD Raw Data]",1);
	PutStr("<--BIT127                               BIT0-->",1);
	for(i=0; i<EMMC_MAX_CSD_LENGTH; i++){
		Data2HexAscii(mmc_drv_obj.csd_data[i],buf,1);
		PutStr(buf,0);
		PutStr(" ",0);
	}
	PutStr("",1);
#endif /* EMMC_TOOL_DUMP */

	/* field disp */
	PutStr("",1);
	PutStr("[CSD Field Data]",1);
	for(loop = 0; loop < CSD_FIELD_MAX; loop++)
	{
		dispField((int32_t)dg_csd_data[loop].top,(int32_t)dg_csd_data[loop].end);
		PutStr(dg_csd_data[loop].name,0);
		PutStr("0x",0);

		bitCnt = (dg_csd_data[loop].top - dg_csd_data[loop].end) + 1;
		dispCnt = ( bitCnt >> 3 );
		if(0 != (bitCnt & 0x7))
		{
			dispCnt++;
		}

		value = 0;
		for( cnt = dispCnt; cnt > 0; cnt-- )
		{
			end = dg_csd_data[loop].end + ((cnt-1) * 8);
			top = end + 7;
			if( top > dg_csd_data[loop].top )
			{
				top = dg_csd_data[loop].top;
			}

			value = EMMC_GET_CSD(top,end);
			Data2HexAscii((uint32_t)value,buf,1);
			PutStr(buf,0);
		}
		PutStr("",1);
	}
	PutStr("",1);
}

/****************************************************************
	MODULE				: disp_ext_csd	 						*
	FUNCTION			: Display EXT_CSD						*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void disp_ext_csd(void)
{
	int8_t buf[16];
	uint32_t value;
	uint32_t loop;
	uint32_t index;
	uint32_t cnt;
	uint32_t byteCnt;
	int32_t chCnt;

#ifdef EMMC_TOOL_DUMP
	uint32_t i,j;
	// EXT_CSD=512Byte
	PutStr("",1);
	PutStr("[EXT_CSD Raw Data]",1);
	PutStr("addr 00 01 02 03 04 05 06 07 08 09 | 10 11 12 13 14 15 16 17 18 19",1);
	PutStr("-----------------------------------|------------------------------",1);
	for(i=0; i<EMMC_MAX_EXT_CSD_LENGTH; i+=20){
		if(i<10) PutStr("0",0);
		if(i<100) PutStr("0",0);

		Hex2DecAscii(i,buf,&chCnt);
		PutStr(buf,0);
		PutStr("  ",0);
		for(j=i; j<(i+20); j++){
			if(j==(i+10)) PutStr("| ",0);
			if(j<EMMC_MAX_EXT_CSD_LENGTH)
			{
				Data2HexAscii(mmc_drv_obj.ext_csd_data[j],buf,1);
				PutStr(buf,0);
				PutStr(" ",0);
			}
		}
		PutStr("",1);
	}
#endif /* EMMC_TOOL_DUMP */

	/* field disp */
	PutStr("",1);
	PutStr("[EXT_CSD Field Data]",1);
	for(loop = 0; loop < EXT_CSD_FIELD_MAX; loop++)
	{
		dispField((int32_t)dg_ext_csd_data[loop].top,(int32_t)dg_ext_csd_data[loop].end);
		PutStr(dg_ext_csd_data[loop].name,0);
		PutStr("0x",0);

		byteCnt = (dg_ext_csd_data[loop].top - dg_ext_csd_data[loop].end) + 1;
		for( cnt = 0; cnt < byteCnt; cnt++ )
		{
			index = dg_ext_csd_data[loop].top - cnt;

			if ((cnt != 0) && (cnt % 8) == 0) {
				PutStr("",1);
				PutStr("                                                        ",0);
			}

			value = mmc_drv_obj.ext_csd_data[index];
			Hex2Ascii((uint32_t)value,buf,&chCnt);
			PutStr(&buf[6],0);
		}
		PutStr("",1);
	}
	PutStr("",1);
}

/****************************************************************
	MODULE				: InputExtCsdParam 						*
	FUNCTION			: Input Palam Change EXT_CSD			*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t InputExtCsdParam( uint32_t *index, uint32_t *value )
{
	uint32_t loop;
	uint32_t wrData;
	uint32_t result;
	int32_t lchCnt;
	int8_t buf[16];
	int8_t key[16];
	int8_t chCnt = 0;
	int8_t chPtr;

	loop = EMMC_EXT_CSD_INPUT_INDEX;
	while(loop)
	{
		if( EMMC_EXT_CSD_INPUT_INDEX == loop )
		{
			PutStr("  Please Input EXT_CSD Index(H'00 - H'1FF) :",0);
		}
		else
		{
			PutStr("  Please Input Value(H'00 - H'FF) :",0);
		}

		GetStr(key,&chCnt);
		chPtr=0;
		if(!GetStrBlk(key,buf,&chPtr,0))
		{
			if(chPtr==1)
			{											/* Case Return */
				return(0);
			}
			else if(chPtr > (int8_t)((SIZE_32BIT<<1)+1) )	/* Case Data Size Over */
			{
				PutStr("Syntax Error",1);
			}
			else
			{
				wrData = 0xFFFFFFFFU;
				if(HexAscii2Data((uint8_t*)buf,&wrData))
				{
					PutStr("Syntax Error",1);
				}
				else
				{
					/* Check Param */
					if(EMMC_EXT_CSD_INPUT_INDEX == loop)		/* case Index */
					{
						if(EXT_CSD_INDEX_MAX < wrData)		/* Param Error */
						{
							PutStr("Param Error",1);
						}
						else
						{
							result = emmcChkExtCsdWriteIndex( wrData );
							if( 1 != result )
							{
								PutStr("Unwritable Index",1);
							}
							else
							{
								*index = wrData;
								loop--;
								PutStr("  EXT_CSD[",0);
								Hex2Ascii(wrData,buf,&lchCnt);
								PutStr(&buf[6],0);
								PutStr("] = 0x",0);
								Hex2Ascii((int32_t)mmc_drv_obj.ext_csd_data[wrData],buf,&lchCnt);
								PutStr(&buf[6],1);
							}
						}
					}
					else										/* case value */
					{
						if(EXT_CSD_VALUE_MAX < wrData)		/* Size Over */
						{
							PutStr("Param Error",1);
						}
						else
						{
							*value = wrData;
							loop--;
						}
					}
				}
			}
		}
	}

	return(1);
}

/****************************************************************
	MODULE				: emmcChkExtCsdWriteIndex				*
	FUNCTION			: Check Change EXT_CSD Index			*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t emmcChkExtCsdWriteIndex(uint32_t index)
{
	uint32_t cnt;

	for( cnt = 0; cnt < EXT_CSD_WRITE_INDEX_NUM; cnt++)
	{
		if( extCsdWriteIndex[cnt] == index )
		{
			return(1);
		}
	}
	return(0);
}

#ifdef EXTCSD_PROTECT
/****************************************************************
	MODULE				: emmcChkExtCsdProtectIndex				*
	FUNCTION			: Check Change EXT_CSD Protect Index	*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static uint32_t emmcChkExtCsdProtectIndex(uint32_t index)
{
	uint32_t cnt;

	for( cnt = 0; cnt < EXT_CSD_PROTECT_INDEX_NUM; cnt++)
	{
		if( extCsdProtectIndex[cnt] == index )
		{
			return(1);
		}
	}
	return(0);
}

/****************************************************************
	MODULE				: warningChgProtectIndex				*
	FUNCTION			: Check Change EXT_CSD Protect Index	*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void warningChgProtectIndex(void)
{
	PutStr("!! Warning !! This field contains the item of protection.",1);
	PutStr("              Change OK?(y/n)",0);
}

#endif /* EXTCSD_PROTECT */

/****************************************************************
	MODULE				: dispField								*
	FUNCTION			: Display Field							*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void dispField( uint32_t start, uint32_t end )
{
	int8_t buf[16];
	int32_t chCnt;

	PutStr("[",0);
	Hex2DecAscii((int32_t)start,buf,&chCnt);
	dispOffset(chCnt);
	PutStr(buf,0);
	PutStr(":",0);
	Hex2DecAscii((int32_t)end,buf,&chCnt);
	dispOffset(chCnt);
	PutStr(buf,0);
	PutStr("]",0);
	PutStr("  ",0);
}

/****************************************************************
	MODULE				: dispOffset							*
	FUNCTION			: Display Field Offset					*
	COMMAND				: 										*
	INPUT PARAMETER		: 										*
*****************************************************************/
static void dispOffset( int8_t cnt )
{
	switch( cnt )
	{
	case 1:
		PutStr("  ",0);
		break;
	case 2:
		PutStr(" ",0);
		break;
	default:
		break;
	}
}
