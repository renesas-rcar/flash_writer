#
# Copyright (c) 2013-2015, ARM Limited and Contributors. All rights reserved.
# Copyright (c) 2015-2017, Renesas Electronics Corporation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# Neither the name of ARM nor the names of its contributors may be used
# to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

#/* Select BOOT("AREA0"or"SPI"or"WRITER"or"WRITER_WITH_CERT" )******************
ifeq ("$(BOOT)", "")
BOOT = WRITER_WITH_CERT
endif

#/* Select SCIF_CLK("EXTERNAL"or"INTERNAL" )************************************
ifeq ("$(SCIF_CLK)", "")
SCIF_CLK = EXTERNAL
endif

#/* Select AArch("64"or"32" )***************************************************
ifeq ("$(AArch)", "")
AArch = 64
endif

#CPU
ifeq ("$(AArch)", "64")
CPU = -march=armv8-a
endif
ifeq ("$(AArch)", "32")
CPU = -mcpu=cortex-r7
endif

ifeq ("$(AArch)", "32")
	THUMB   = -marm
	AS_NEON = -mfpu=neon-vfpv4
	CC_NEON = -mfpu=neon-vfpv4
endif
ifeq ("$(AArch)", "64")
	THUMB   = 
	AS_NEON = 
	CC_NEON = -mgeneral-regs-only
endif

ifeq ("$(AArch)", "32")
	AArch32_64  = AArch32
	BOOTDIR     = AArch32_boot
	OUTPUT_DIR  = AArch32_output
	OBJECT_DIR  = AArch32_obj
	CROSS_COMPILE ?= arm-eabi-
endif
ifeq ("$(AArch)", "64")
	AArch32_64  = AArch64
	BOOTDIR     = AArch64_boot
	OUTPUT_DIR  = AArch64_output
	OBJECT_DIR  = AArch64_obj
	CROSS_COMPILE ?= aarch64-elf-
endif

LIBS        = -L$(subst libc.a, ,$(shell $(CC) -print-file-name=libc.a 2> /dev/null)) -lc
LIBS        += -L$(subst libgcc.a, ,$(shell $(CC) -print-libgcc-file-name 2> /dev/null)) -lgcc

INCLUDE_DIR = include
TOOL_DEF = "REWRITE_TOOL"

ifeq ("$(BOOT)", "AREA0")
	BOOT_DEF    = Area0Boot
	MEMORY_DEF = memory_area0.def
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_eMMC_Writer_Area0
endif

ifeq ("$(BOOT)", "SPI")
	BOOT_DEF    = SpiBoot
	MEMORY_DEF = memory_spi.def
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_eMMC_Writer_Spi_E6330000
endif

ifeq ("$(BOOT)", "WRITER")
	BOOT_DEF    = Writer
	MEMORY_DEF = memory_writer.def
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_eMMC_writer_SCIF_E6304000
endif

ifeq ("$(BOOT)", "WRITER_WITH_CERT")
	BOOT_DEF    = Writer
	MEMORY_DEF  = memory_writer_with_cert.def
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_eMMC_writer_SCIF_DUMMY_CERT_E6300400
endif

ifeq ("$(SCIF_CLK)", "EXTERNAL")
	SCIF_DEF    = SCIF_CLK_EXTERNAL
endif

ifeq ("$(SCIF_CLK)", "INTERNAL")
	SCIF_DEF    = SCIF_CLK_INTERNAL
endif

OUTPUT_FILE = $(FILE_NAME).axf

#Object file
OBJ_FILE_BOOT = $(OBJECT_DIR)/boot_mon.o

ifeq ("$(BOOT)", "SPI")
OBJ_FILE =								\
	$(OBJECT_DIR)/main.o				\
	$(OBJECT_DIR)/scifdrv.o				\
	$(OBJECT_DIR)/devdrv.o				\
	$(OBJECT_DIR)/common.o				\
	$(OBJECT_DIR)/dginit.o				\
	$(OBJECT_DIR)/dgtable.o				\
	$(OBJECT_DIR)/dgmodul1.o			\
	$(OBJECT_DIR)/Message.o				\
	$(OBJECT_DIR)/ramckmdl.o			\
	$(OBJECT_DIR)/armasm.o				\
	$(OBJECT_DIR)/cpudrv.o				\
	$(OBJECT_DIR)/b_boarddrv.o			\
	$(OBJECT_DIR)/dg_emmc_config.o		\
	$(OBJECT_DIR)/dg_emmc_access.o		\
	$(OBJECT_DIR)/timer_api.o			\
	$(OBJECT_DIR)/emmc_cmd.o			\
	$(OBJECT_DIR)/emmc_init.o			\
	$(OBJECT_DIR)/emmc_interrupt.o		\
	$(OBJECT_DIR)/emmc_mount.o			\
	$(OBJECT_DIR)/emmc_write.o			\
	$(OBJECT_DIR)/emmc_erase.o			\
	$(OBJECT_DIR)/emmc_utility.o		\
	$(OBJECT_DIR)/boot_init_lbsc.o		\

#Dependency File
DEPEND_FILE = $(patsubst %.lib, ,$(OBJ_FILE:%.o=%.d))

#BOOT= "WRITER_WITH_CERT"
else
ifeq ("$(BOOT)", "WRITER_WITH_CERT")
OBJ_FILE =								\
	$(OBJECT_DIR)/cert_param.o			\
	$(OBJECT_DIR)/main.o				\
	$(OBJECT_DIR)/scifdrv.o				\
	$(OBJECT_DIR)/devdrv.o				\
	$(OBJECT_DIR)/common.o				\
	$(OBJECT_DIR)/dginit.o				\
	$(OBJECT_DIR)/dgtable.o				\
	$(OBJECT_DIR)/dgmodul1.o			\
	$(OBJECT_DIR)/Message.o				\
	$(OBJECT_DIR)/ramckmdl.o			\
	$(OBJECT_DIR)/armasm.o				\
	$(OBJECT_DIR)/cpudrv.o				\
	$(OBJECT_DIR)/b_boarddrv.o			\
	$(OBJECT_DIR)/dg_emmc_config.o		\
	$(OBJECT_DIR)/dg_emmc_access.o		\
	$(OBJECT_DIR)/timer_api.o			\
	$(OBJECT_DIR)/emmc_cmd.o			\
	$(OBJECT_DIR)/emmc_init.o			\
	$(OBJECT_DIR)/emmc_interrupt.o		\
	$(OBJECT_DIR)/emmc_mount.o			\
	$(OBJECT_DIR)/emmc_write.o			\
	$(OBJECT_DIR)/emmc_erase.o			\
	$(OBJECT_DIR)/emmc_utility.o		\
	$(OBJECT_DIR)/boot_init_lbsc.o		\
	$(OBJECT_DIR)/boot_init_port_M3.o	\
	$(OBJECT_DIR)/boot_init_gpio.o		\
	$(OBJECT_DIR)/boot_init_dram.o		\
	$(OBJECT_DIR)/dram_sub_func.o		\
	$(OBJECT_DIR)/micro_wait.o

#Dependency File
DEPEND_FILE = $(patsubst %.lib, ,$(OBJ_FILE:%.o=%.d))


#BOOT= "AREA0" or "WRITER"
else
OBJ_FILE =								\
	$(OBJECT_DIR)/main.o				\
	$(OBJECT_DIR)/scifdrv.o				\
	$(OBJECT_DIR)/devdrv.o				\
	$(OBJECT_DIR)/common.o				\
	$(OBJECT_DIR)/dginit.o				\
	$(OBJECT_DIR)/dgtable.o				\
	$(OBJECT_DIR)/dgmodul1.o			\
	$(OBJECT_DIR)/Message.o				\
	$(OBJECT_DIR)/ramckmdl.o			\
	$(OBJECT_DIR)/armasm.o				\
	$(OBJECT_DIR)/cpudrv.o				\
	$(OBJECT_DIR)/b_boarddrv.o			\
	$(OBJECT_DIR)/dg_emmc_config.o		\
	$(OBJECT_DIR)/dg_emmc_access.o		\
	$(OBJECT_DIR)/timer_api.o			\
	$(OBJECT_DIR)/emmc_cmd.o			\
	$(OBJECT_DIR)/emmc_init.o			\
	$(OBJECT_DIR)/emmc_interrupt.o		\
	$(OBJECT_DIR)/emmc_mount.o			\
	$(OBJECT_DIR)/emmc_write.o			\
	$(OBJECT_DIR)/emmc_erase.o			\
	$(OBJECT_DIR)/emmc_utility.o		\
	$(OBJECT_DIR)/boot_init_lbsc.o		\
	$(OBJECT_DIR)/boot_init_port_M3.o	\
	$(OBJECT_DIR)/boot_init_gpio.o		\
	$(OBJECT_DIR)/boot_init_dram.o		\
	$(OBJECT_DIR)/dram_sub_func.o		\
	$(OBJECT_DIR)/micro_wait.o

#Dependency File
DEPEND_FILE = $(patsubst %.lib, ,$(OBJ_FILE:%.o=%.d))
endif
endif


###################################################
#C compiler
CC = $(CROSS_COMPILE)gcc
#Assembler
AS = $(CROSS_COMPILE)as
#Linker
LD = $(CROSS_COMPILE)ld
#Liblary
AR = $(CROSS_COMPILE)ar
#Object dump
OBJDMP = $(CROSS_COMPILE)objdump
#Object copy
OBJCOPY = $(CROSS_COMPILE)objcopy

#clean
CL = rm -f

###################################################
# Suffixes
.SUFFIXES : .s .c .o

###################################################
# Command

.PHONY: all
all: $(OBJECT_DIR) $(OUTPUT_DIR) $(OBJ_FILE_BOOT) $(OBJ_FILE)  $(OUTPUT_FILE)

#------------------------------------------
# Make Directory
#------------------------------------------
$(OBJECT_DIR):
	-mkdir "$(OBJECT_DIR)"

$(OUTPUT_DIR):
	-mkdir "$(OUTPUT_DIR)"

#------------------------------------------
# Compile
#------------------------------------------
%.o:../$(BOOTDIR)/%.s
	$(AS)  -g $(CPU) $(AS_NEON) --MD $(patsubst %.o,%.d,$@) -I $(BOOTDIR) -I $(INCLUDE_DIR) $< -o $@ --defsym $(AArch32_64)=0 --defsym $(BOOT_DEF)=0 --defsym $(TOOL_DEF)=0 --defsym $(SCIF_DEF)=0

%.o:../%.c
	$(CC) -g -Os $(CPU) $(CC_NEON) $(THUMB) -MMD -MP -c -I $(BOOTDIR) -I $(INCLUDE_DIR) $< -o $@ -D$(AArch32_64)=0 -D$(BOOT_DEF)=0 -D$(TOOL_DEF)=0 -D$(SCIF_DEF)=0


#------------------------------------------
# Linker
#------------------------------------------
$(OUTPUT_FILE): $(OBJ_FILE_BOOT) $(OBJ_FILE)  $(MEMORY_DEF)
	$(LD) $(OBJ_FILE_BOOT) $(OBJ_FILE)  \
	-T '$(MEMORY_DEF)'			\
	-o '$(OUTPUT_FILE)'			\
	-Map '$(FILE_NAME).map' 	\
	-static					\
	$(LIBS)

#   Make MOT file
	$(OBJCOPY) -O srec --srec-forceS3 "$(OUTPUT_FILE)" "$(FILE_NAME).mot"

#   Make Binary file
	$(OBJCOPY) -O binary "$(OUTPUT_FILE)" "$(FILE_NAME).bin"

#   Dis assemble
	$(OBJDMP) -d -S "$(OUTPUT_FILE)" > "$(FILE_NAME)_disasm.txt"

#	Time Stamp
	@echo ==========  %date% %time%  ==========
	@echo ========== !!! Compile Complete !!! ==========


.PHONY: clean
clean:
	$(CL)  $(OBJECT_DIR)/* $(OUTPUT_DIR)/*

-include $(DEPEND_FILE)
