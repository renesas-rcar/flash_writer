#pragma once
#include <stdint.h>

#define RCAR_E3_DDR_VERSION    "rev.0.02"
#define REFRESH_RATE  3900      // Average periodic refresh interval[ns]. Support 3900,7800

uint32_t init_ddr_e31866(void);
uint32_t init_ddr_e31600(void);

