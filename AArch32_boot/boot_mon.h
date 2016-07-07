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

;##### Stack Pointer (Memory Image) #####################
;##                                                     #
;## H'E632F600   System_stack (MiniMon)                 #
;## H'E632F800   UND_stack                              #
;## H'E632FA00   SVC(SWI)_stack                         #
;## H'E632FC00   ABT_stack                              #
;## H'E632FE00   FIQ_stack                              #
;## H'E6323000   IRQ_stack                              #
;##                                                     #
;########################################################

;#System RAM
.EQU	STACK_IRQ_ADR,	0xE6330000		;# IRQ mode (unused)
.EQU	STACK_FIQ_ADR,	0xE632FE00		;# FIQ mode (unused)
.EQU	STACK_ABT_ADR,	0xE632FC00		;# ABT mode (unused)
.EQU	STACK_SVC_ADR,	0xE632FA00		;# SVC(SWI) mode (unused)
.EQU	STACK_UND_ADR,	0xE632F800		;# UND mode(unused)
.EQU	STACK_SYS_ADR,	0xE632F600		;# SYS mode


;#################### CPSR bit ##########################
.EQU	PSR_MODE_USER, 0x10			;#USR mode
.EQU	PSR_MODE_FIQ, 0x11			;#FIQ mode
.EQU	PSR_MODE_IRQ, 0x12			;#IRQ mode
.EQU	PSR_MODE_SVC, 0x13			;#SVC mode
.EQU	PSR_MODE_ABT, 0x17			;#ABT mode
.EQU	PSR_MODE_UND, 0x1B			;#UND mode
.EQU	PSR_MODE_SYS, 0x1F			;#SYS mode

;# PRR
.EQU 	PRR				,	0xFFF00044		;#Product Register

;#RWDT
;#R-CarH3 77. RCLK Watchdog Timer
.EQU	RWDT_RWTCNT		,	0xE6020000		;#RCLK watchdog timer counter
.EQU	RWDT_RWTCSRA	,	0xE6020004		;#RCLK watchdog timer control/status register A
.EQU	RWDT_RWTCSRB	,	0xE6020008		;#RCLK watchdog timer control/status register B

;#SystemWDT
;#R-CarH3 78. System Watchdog Timer
.EQU	SYSWDT_WTCNT	,	0xE6030000		;#watchdog timer counter
.EQU	SYSWDT_WTCSRA	,	0xE6030004		;#watchdog timer control/status register A
.EQU	SYSWDT_WTCSRB	,	0xE6030008		;#watchdog timer control/status register B


