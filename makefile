#
# Copyright (c) 2015-2018, Renesas Electronics Corporation. All rights reserved.
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

#/* Select BOARD("SALVATOR"or"ULCB"or"EBISU"or"EBISU4D"or"DRAAK" )**************
ifeq ("$(BOARD)", "")
BOARD = SALVATOR
endif

#/* Select BOOT("AREA0"or"WRITER"or"WRITER_WITH_CERT" )*************************
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

#/* Select USB("ENABLE"or"DISABLE" )********************************************
ifeq ("$(USB)", "")
USB = ENABLE
endif

#/* Select SERIAL_FLASH("ENABLE"or"DISABLE" )***********************************
ifeq ("$(SERIAL_FLASH)", "")
SERIAL_FLASH = ENABLE
endif

#/* Select EMMC("ENABLE"or"DISABLE" )*******************************************
ifeq ("$(EMMC)", "")
EMMC = ENABLE
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
	AS_NEON = 
	CC_NEON = 
	ALIGN   = -mno-unaligned-access
endif
ifeq ("$(AArch)", "64")
	THUMB   = 
	AS_NEON = 
	CC_NEON = -mgeneral-regs-only
	ALIGN   = -mstrict-align
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

ifeq ("$(BOARD)", "EBISU")
	BOARD_NAME   =  Ebisu
	FILENAME_ADD = _ebisu
	CFLAGS += -DRCAR_GEN3_EBISU=1
else ifeq ("$(BOARD)", "EBISU4D")
	BOARD_NAME   =  Ebisu4d
	FILENAME_ADD = _ebisu4d
	CFLAGS += -DRCAR_GEN3_EBISU=1
else ifeq ("$(BOARD)", "DRAAK")
	BOARD_NAME   =  Draak
	FILENAME_ADD = _draak
	CFLAGS += -DRCAR_GEN3_DRAAK=1
else ifeq ("$(BOARD)", "ULCB")
	BOARD_NAME   =  ULCB
	FILENAME_ADD = _ULCB
	CFLAGS += -DRCAR_GEN3_ULCB=1
	CFLAGS += -DRCAR_GEN3_SALVATOR=1
	CFLAGS += -DRCAR_DRAM_LPDDR4_MEMCONF=0
else
	BOARD_NAME   =  SALVATOR
	FILENAME_ADD = _salvator-x
	CFLAGS += -DRCAR_GEN3_ULCB=0
	CFLAGS += -DRCAR_GEN3_SALVATOR=1
	CFLAGS += -DRCAR_DRAM_LPDDR4_MEMCONF=0
endif

ifeq ("$(BOOT)", "AREA0")
	BOOT_DEF    = Area0Boot
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_Flash_writer_Area0$(FILENAME_ADD)
	MEMORY_DEF = memory_area0.def
endif

ifeq ("$(BOOT)", "WRITER")
	BOOT_DEF    = Writer
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_Flash_writer_SCIF_E6304000$(FILENAME_ADD)
ifeq ("$(BOARD)", "EBISU")
	MEMORY_DEF = memory_writer_small.def
else ifeq ("$(BOARD)", "EBISU4D")
	MEMORY_DEF = memory_writer_small.def
else ifeq ("$(BOARD)", "DRAAK")
	MEMORY_DEF = memory_writer_small.def
else
	MEMORY_DEF = memory_writer.def
endif
endif

ifeq ("$(BOOT)", "WRITER_WITH_CERT")
	BOOT_DEF    = Writer
	FILE_NAME   = $(OUTPUT_DIR)/AArch$(AArch)_Flash_writer_SCIF_DUMMY_CERT_E6300400$(FILENAME_ADD)
ifeq ("$(BOARD)", "EBISU")
	MEMORY_DEF  = memory_writer_small_with_cert.def
else ifeq ("$(BOARD)", "EBISU4D")
	MEMORY_DEF  = memory_writer_small_with_cert.def
else ifeq ("$(BOARD)", "DRAAK")
	MEMORY_DEF  = memory_writer_small_with_cert.def
else
	MEMORY_DEF  = memory_writer_with_cert.def
endif
endif

ifeq ("$(SCIF_CLK)", "EXTERNAL")
	SCIF_DEF    = SCIF_CLK_EXTERNAL
endif

ifeq ("$(SCIF_CLK)", "INTERNAL")
	SCIF_DEF    = SCIF_CLK_INTERNAL
endif

#USB download function can not be used with the starter kit.
ifeq ("$(USB)", "ENABLE")
	CFLAGS += -DUSB_ENABLE=1
endif

ifeq ("$(USB)", "DISABLE")
	CFLAGS += -DUSB_ENABLE=0
endif

ifeq ("$(SERIAL_FLASH)", "ENABLE")
	CFLAGS += -DSERIAL_FLASH=1
endif

ifeq ("$(SERIAL_FLASH)", "DISABLE")
	CFLAGS += -DSERIAL_FLASH=0
endif

ifeq ("$(EMMC)", "ENABLE")
	CFLAGS += -DEMMC=1
endif

ifeq ("$(EMMC)", "DISABLE")
	CFLAGS += -DEMMC=0
endif

DDR_DEF = ddr_qos_init_setting

LIBS        = -L$(subst libc.a, ,$(shell $(CC) -print-file-name=libc.a 2> /dev/null)) -lc
LIBS        += -L$(subst libgcc.a, ,$(shell $(CC) -print-libgcc-file-name 2> /dev/null)) -lgcc
ifeq ("$(USB)", "ENABLE")
LIBS        += -L./$(AArch32_64)_lib/ -lusb
endif

INCLUDE_DIR = include
DDR_DIR = ddr
TOOL_DEF = "REWRITE_TOOL"

OUTPUT_FILE = $(FILE_NAME).axf

#Object file
OBJ_FILE_BOOT =						\
	$(OBJECT_DIR)/boot_mon.o			\
	$(OBJECT_DIR)/stack.o

SRC_FILE :=						\
	main.c						\
	init_scif.c					\
	scifdrv.c					\
	devdrv.c					\
	common.c					\
	dgtable.c					\
	dgmodul1.c					\
	Message.c					\
	dmaspi.c					\
	ramckmdl.c					\
	cpudrv.c					\
	b_boarddrv.c					\
	boardid.c					\
	switch.c					\
	boot_init_lbsc.c				\
	boot_init_port.c				\
	boot_init_gpio.c				\
	micro_wait.c

ifeq ("$(SERIAL_FLASH)", "ENABLE")
SRC_FILE +=						\
	dgmodul4.c					\
	rpchyperdrv.c					\
	rpcqspidrv.c					\
	hyperflashdrv.c					\
	spiflash1drv.c					\
	spiflash0drv.c
endif

ifeq ("$(EMMC)", "ENABLE")
SRC_FILE +=						\
	dg_emmc_config.c				\
	dg_emmc_access.c				\
	emmc_cmd.c					\
	emmc_init.c					\
	emmc_interrupt.c				\
	emmc_mount.c					\
	emmc_write.c					\
	emmc_erase.c					\
	emmc_utility.c
endif

ifeq ("$(BOOT)", "WRITER_WITH_CERT")
	SRC_FILE += cert_param.c
endif

ifeq ("$(BOARD)", "EBISU")
include ddr/ddr3l/ddr.mk
else ifeq ("$(BOARD)", "EBISU4D")
include ddr/ddr3l/ddr.mk
else ifeq ("$(BOARD)", "DRAAK")
include ddr/ddr3l/ddr.mk
else
include ddr/lpddr4/ddr.mk
endif

OBJ_FILE := $(addprefix $(OBJECT_DIR)/,$(patsubst %.c,%.o,$(SRC_FILE)))

#Dependency File
DEPEND_FILE = $(patsubst %.lib, ,$(OBJ_FILE:%.o=%.d))

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
CL = rm -rf

###################################################
# Suffixes
.SUFFIXES : .s .c .o

###################################################
# Command

.PHONY: all
all: $(OBJECT_DIR) $(OUTPUT_DIR) $(OBJ_FILE_BOOT) $(OBJ_FILE) $(OUTPUT_FILE)

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
$(OBJECT_DIR)/%.o:$(BOOTDIR)/%.s
	$(AS)  -g $(CPU) $(AS_NEON) --MD $(patsubst %.o,%.d,$@) -I $(BOOTDIR) -I $(INCLUDE_DIR) -I $(DDR_DIR) $< -o $@ --defsym $(AArch32_64)=0 --defsym $(BOOT_DEF)=0 --defsym $(TOOL_DEF)=0 --defsym $(SCIF_DEF)=0

$(OBJECT_DIR)/%.o:%.c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) -g -Os $(ALIGN) $(CPU) $(CC_NEON) $(THUMB) -MMD -MP -c -I $(BOOTDIR) -I $(INCLUDE_DIR) -I $(DDR_DIR) $< -o $@ -D$(AArch32_64)=0 -D$(BOOT_DEF)=0 -D$(TOOL_DEF)=0 -D$(SCIF_DEF)=0 $(CFLAGS) -D$(DDR_DEF)=0

#------------------------------------------
# Linker
#------------------------------------------
$(OUTPUT_FILE): $(OBJ_FILE_BOOT) $(OBJ_FILE) $(MEMORY_DEF)
	$(LD) $(OBJ_FILE_BOOT) $(OBJ_FILE) \
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
