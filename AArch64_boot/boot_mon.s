;/*
; * Copyright (c) 2015-2016, Renesas Electronics Corporation
; * All rights reserved.
; *
; * Redistribution and use in source and binary forms, with or without
; * modification, are permitted provided that the following conditions are met:
; *
; *   - Redistributions of source code must retain the above copyright notice,
; *     this list of conditions and the following disclaimer.
; *
; *   - Redistributions in binary form must reproduce the above copyright
; *     notice, this list of conditions and the following disclaimer in the
; *     documentation and/or other materials provided with the distribution.
; *
; *   - Neither the name of Renesas nor the names of its contributors may be
; *     used to endorse or promote products derived from this software without
; *     specific prior written permission.
; *
; * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
; * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
; * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
; * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
; * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; * POSSIBILITY OF SUCH DAMAGE.
; */

;# W0-W30 : 32bit Register (W30=Link Register)
;# X0-X30 : 64bit Register (X30=Link Register)
;# WZR    : 32bit Zero Register
;# XZR    : 64bit Zero Register
;# WSP    : 32bit Stack Pointer
;# SP     : 64bit Stack Pointer

	.INCLUDE		"boot_mon.h"
	.ALIGN	4

;# Initialize registers
Register_init:
	LDR		X0, =0
	LDR		X1, =0
	LDR		X2, =0
	LDR		X3, =0
	LDR		X4, =0
	LDR		X5, =0
	LDR		X6, =0
	LDR		X7, =0
	LDR		X8, =0
	LDR		X9, =0
	LDR		X10, =0
	LDR		X11, =0
	LDR		X12, =0
	LDR		X13, =0
	LDR		X14, =0
	LDR		X15, =0
	LDR		X16, =0
	LDR		X17, =0
	LDR		X18, =0
	LDR		X19, =0
	LDR		X20, =0
	LDR		X21, =0
	LDR		X22, =0
	LDR		X23, =0
	LDR		X24, =0
	LDR		X25, =0
	LDR		X26, =0
	LDR		X27, =0
	LDR		X28, =0
	LDR		X29, =0
	LDR		X30, =0

Set_EnableRAM:
	LDR		X0,	=0xE67F0018
	LDR		W1, =0x00000001			;#Enable  DRAM/SECRAM/PUBRAM
	STR		W1, [X0]

;# Loader
    LDR x0, =0xE6330000
    MSR SP_EL0,x0
    MSR SP_EL1,x0
    MSR SP_EL2,x0
    MOV sp,x0
    MSR ELR_EL1,x0
    MSR ELR_EL2,x0
    MSR ELR_EL3,x0
    MSR SPSR_EL1,x0
    MSR SPSR_EL2,x0
    MSR SPSR_EL3,x0


;# Board Initialize
.ifdef Area0Boot

Init_set_WDT:
	LDR		W0,	=RWDT_RWTCSRA
	LDR		W1, =0xA5A5A500				;#Timer disabled
	STR		W1, [X0]

Init_set_SYSWDT:
	LDR		W0,	=SYSWDT_WTCSRA
	LDR		W1, =0xA5A5A500				;#Timer  disabled (Enable -> disabled)
	STR		W1, [X0]

.endif



;# Enable cache
;#	mov x1, #(SCTLR_I_BIT | SCTLR_A_BIT | SCTLR_SA_BIT)
	mrs x0, sctlr_el3
	orr x0, x0, #(0x1 << 12)
	orr x0, x0, #(0x1 <<  1)
	orr x0, x0, #(0x1 <<  3)
	msr sctlr_el3, x0
	isb



.ifdef Area0Boot

	BL InitPORT
	BL InitGPIO
	BL InitLBSC
	BL InitScif2_SCIFCLK
	BL InitDram

.endif

.ifdef Writer

	BL InitPORT
	BL InitGPIO
	BL InitLBSC
	BL InitScif2_SCIFCLK
	BL InitDram

.endif


	BL		Main

	.END

