#
# Copyright (c) 2018, Renesas Electronics Corporation
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#   - Redistributions of source code must retain the above copyright notice,
#     this list of conditions and the following disclaimer.
#
#   - Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#   - Neither the name of Renesas nor the names of its contributors may be
#     used to endorse or promote products derived from this software without
#     specific prior written permission.
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


#The Ebisu board have two 16bit-width 4Gbit DRAMs.
ifeq ("$(BOARD)", "EBISU")
SRC_FILE += ddr/ddr3l/ddr_init_e3.c
SRC_FILE += ddr/dram_sub_func.c
CFLAGS += -DRCAR_DRAM_DDR3L_MEMCONF=0 -DRCAR_DRAM_DDR3L_MEMDUAL=0

#The Ebisu-4D board have four 8bit-width 4Gbit DRAMs.
else ifeq ("$(BOARD)", "EBISU4D")
SRC_FILE += ddr/ddr3l/ddr_init_e3.c
SRC_FILE += ddr/dram_sub_func.c
CFLAGS += -DRCAR_DRAM_DDR3L_MEMCONF=1 -DRCAR_DRAM_DDR3L_MEMDUAL=1

#The Draak board have one 16bit-width 4Gbit DRAM.
else ifeq ("$(BOARD)", "DRAAK")
SRC_FILE += ddr/ddr3l/boot_init_dram.c
SRC_FILE += ddr/ddr3l/ddr_init_d3.c
endif
