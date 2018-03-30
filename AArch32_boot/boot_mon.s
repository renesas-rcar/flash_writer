;/*
; * Copyright (c) 2015-2018, Renesas Electronics Corporation
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

	.INCLUDE		"boot_mon.h"
	.ALIGN	4

;#---CACHE_SET--------------------------------------------------------------------------------------
.equ 	CACHE_MODE,ENABLE			;# ENABLE
;#.equ 	CACHE_MODE,DISABLE			;# DISABLE
;#--------------------------------------------------------------------------------------------------


;####################################################################################################
;# Vector table
;####################################################################################################
Vector_Table:
	LDR		PC,=Reset_Handler
	LDR		PC,=Undefined_Handler
	LDR		PC,=SVC_Handler
	LDR		PC,=Prefetch_Handler
	LDR		PC,=Abort_Handler
	NOP
	LDR		PC,=IRQ_Handler
	LDR		PC,=FIQ_Handler

;####################################################################################################
;# Exception handler
;####################################################################################################
Undefined_Handler:
	STMFD	SP!, {R0-R12,LR}
	LDMFD	SP!, {R0-R12,PC}^

SVC_Handler:
	STMFD	SP!, {R0-R12,LR}
	LDMFD	SP!, {R0-R12,PC}^

Prefetch_Handler:
	SUB		R14, R14 , #4
	STMFD	SP!, {R0-R12,LR}
	LDMFD	SP!, {R0-R12,PC}^

Abort_Handler:
	SUB		R14,R14,#8
	STMFD	SP!, {R0-R12,LR}
	LDMFD	SP!, {R0-R12,PC}^

IRQ_Handler:
	SUB		R14, R14 , #4
	STMFD	SP!, {R0-R12,LR}
	LDMFD	SP!, {R0-R12,PC}^

FIQ_Handler:
	SUB		R14,R14,#4
	STMFD	SP!, {R0-R7,LR}
	LDMFD	SP!, {R0-R7,PC}^

;####################################################################################################
;####################################################################################################
;######
;######        reset handler
;######
;####################################################################################################
;####################################################################################################
Reset_Handler:
Register_init:
	LDR		R0, =0
	LDR		R1, =0
	LDR		R2, =0
	LDR		R3, =0
	LDR		R4, =0
	LDR		R5, =0
	LDR		R6, =0
	LDR		R7, =0
	LDR		R8, =0
	LDR		R9, =0
	LDR		R10, =0
	LDR		R11, =0
	LDR		R12, =0
	LDR		R13, =0
	LDR		R14, =0
;#	LDR		R15, =0

Set_EnableRAM:
	LDR		R0,	=0xE67F0018
	LDR		R1, =0x00000001			;#Resource Alloc On
	STR		R1, [R0]


Stack_init:
;#--------------------------------------------------------------------------------------------------
Stack_init_irq:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_IRQ
	MSR		CPSR_c, R1
	LDR		R0, =STACK_IRQ_ADR
	MOV		SP, R0

;#--------------------------------------------------------------------------------------------------
Stack_init_frq:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_FIQ
	MSR		CPSR_c, R1
	LDR		R0, =STACK_FIQ_ADR
	MOV		SP, R0

;#--------------------------------------------------------------------------------------------------
Stack_init_abt:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_ABT
	MSR		CPSR_c, R1
	LDR		R0, =STACK_ABT_ADR
	MOV		SP, R0

;#--------------------------------------------------------------------------------------------------
Stack_init_svc:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_SVC
	MSR		CPSR_c, R1
	LDR		R0, =STACK_SVC_ADR
	MOV		SP, R0

;#--------------------------------------------------------------------------------------------------
Stack_init_und:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_UND
	MSR		CPSR_c, R1
	LDR		R0, =STACK_UND_ADR
	MOV		SP, R0

;#--------------------------------------------------------------------------------------------------
Stack_init_sys:
	MRS		R1, CPSR
	BIC		R1, R1, #0x1F
	ORR		R1, R1, #PSR_MODE_SYS
	MSR		CPSR_c, R1
	LDR		R0, =STACK_SYS_ADR
	MOV		SP, R0


;####################################################################################################
;#
;#  board initialize
;#
;####################################################################################################

;####################################################################################################
;####		RWDT,SystemWDT setting (Timer Disable setting)
;####################################################################################################
.ifdef Area0Boot
Init_set_WDT:
	LDR		R0, =RWDT_RWTCSRA
	LDR		R1, =0xA5A5A500				;#Timer disabled
	STR		R1, [R0]

Init_set_SYSWDT:
	LDR		R0, =SYSWDT_WTCSRA
	LDR		R1, =0xA5A5A500				;#Timer  disabled (Enable -> disabled)
	STR		R1, [R0]
.endif


.IF CACHE_MODE == ENABLE
;####################################################################################################
;#####		enable I cache
;####################################################################################################

CACHE_ENABLE:
  MRC	p15, 0, R1, c1, c0, 0	;# Read System Control Register configuration data
  ORR 	R1, R1, #0x1 <<12		;# instruction cache enable
  MCR 	p15, 0, r0, c7, c5, 0	;# Invalidate entire instruction cache
  MCR 	p15, 0, R1, c1, c0, 0	;# enabled instruction cache
  ISB
  B       CACHE_ENABLE_END
.ENDIF

CACHE_ENABLE_END:

	/* clear bss section */
	mov	r0, #0x0
	ldr	r1, =__BSS_START__
	ldr	r2, =__BSS_SIZE__
bss_loop:
	subs	r2, r2, #4
	bcc	bss_end
	str	r0, [r1, +r2]
	b	bss_loop
bss_end:

.ifdef Area0Boot
	/* copy data section */
	ldr	r0, =__DATA_COPY_START__
	ldr	r1, =__DATA_START__
	ldr	r2, =__DATA_SIZE__
data_loop:
	subs	r2, r2, #4
	bcc	data_end
	ldr	r3, [r0, +r2]
	str	r3, [r1, +r2]
	b	data_loop
data_end:
.endif


.ifdef Area0Boot
	BL InitPORT
	BL InitGPIO
	BL InitLBSC
	BL InitScif
	BL InitDram
.endif

.ifdef Writer
	BL InitPORT
	BL InitGPIO
	BL InitLBSC
	BL InitScif
	BL InitDram
.endif

	cmp	r0, #0
	beq	Jmp_MAIN_C	/* InitDram success */ 
	mov	r4, r0

	ldr	r0, =dram_err_msg
	mov	r1, #0
	bl	PutStr

	mov	r0, r4	/* return value of InitDram */
	ldr	r1, =str_buf
	ldr	r2, =cnt
	bl	Hex2Ascii
	mov	r0, r1
	mov	r1, #1
	bl	PutStr
1:
	wfi		/* InitDram fail */
	b	1b

;####################################################################################################
;####	go to main
;####################################################################################################
Jmp_MAIN_C:
	BL		Main


	.section .rodata
dram_err_msg:
	.asciz "InitDram error=0x"

	.section .bss
	.align	4
cnt:
	.space	4
str_buf:
	.space	16

	.END
