	.file "C:\\Users\\dconcors\\demos\\l1demo\\src\\main.c"
	.section	.debug_abbrev,info
.Ldebug_abbrev0:
	.section	.debug_info,info
.Ldebug_info0:
	.section	.debug_line,info
.Ldebug_line0:
	.section	.text,code
.Ltext0:
	.section	.text,code
	.align	2
	.global	_uart_rx	; export
	.type	_uart_rx,@function
_uart_rx:
.LFB0:
	.file 1 "src/main.c"
	.loc 1 22 0
	.set ___PA___,1
	.loc 1 23 0
	mov	#__iob,w0
	rcall	_fgetc
	.loc 1 24 0
	return	
	.set ___PA___,0
.LFE0:
	.size	_uart_rx, .-_uart_rx
	.align	2
	.global	_uart_tx	; export
	.type	_uart_tx,@function
_uart_tx:
.LFB1:
	.loc 1 27 0
	.set ___PA___,1
	.loc 1 28 0
	se	w0,w0
	mov	#__iob+14,w1
	rcall	_fputc
	.loc 1 29 0
	return	
	.set ___PA___,0
.LFE1:
	.size	_uart_tx, .-_uart_tx
	.align	2
	.global	_uart_puts	; export
	.type	_uart_puts,@function
_uart_puts:
.LFB2:
	.loc 1 32 0
	.set ___PA___,1
	mov.d	w8,[w15++]
.LCFI0:
	mov	w10,[w15++]
.LCFI1:
	mov	w0,w10
	.loc 1 33 0
	mov.b	[w10],w0
	cp0.b	w0
	.set ___BP___,9
	bra	z,.L3
	clr	w8
	.loc 1 35 0
	mov	#__iob+14,w9
	.loc 1 33 0
	inc	w10,w10
.L5:
	.loc 1 35 0
	se	w0,w0
	mov	w9,w1
	rcall	_fputc
	.loc 1 33 0
	mov.b	[w8+w10],w0
	inc	w8,w8
	cp0.b	w0
	.set ___BP___,91
	bra	nz,.L5
.L3:
	.loc 1 39 0
	mov	[--w15],w10
	mov.d	[--w15],w8
	return	
	.set ___PA___,0
.LFE2:
	.size	_uart_puts, .-_uart_puts
	.align	2
	.global	_readline	; export
	.type	_readline,@function
_readline:
.LFB3:
	.loc 1 42 0
	.set ___PA___,1
	mov.d	w8,[w15++]
.LCFI2:
	.loc 1 45 0
	rcall	_uart_rx
	.loc 1 46 0
	rcall	_uart_rx
	clr.b	w8
	sub.b	w0,#13,[w15]
	.set ___BP___,9
	bra	z,.L8
	.loc 1 48 0
	mov	#_line,w9
.L9:
	ze	w8,w1
	mov.b	w0,[w9+w1]
	inc.b	w8,w8
	.loc 1 49 0
	rcall	_uart_tx
	.loc 1 46 0
	rcall	_uart_rx
	sub.b	w0,#13,[w15]
	.set ___BP___,91
	bra	nz,.L9
.L8:
	.loc 1 51 0
	mov.b	#13,w0
	rcall	_uart_tx
	.loc 1 52 0
	mov.b	#10,w0
	rcall	_uart_tx
	.loc 1 53 0
	ze	w8,w8
	mov	#_line,w0
	add	w0,w8,w8
	clr.b	[w8]
	.loc 1 54 0
	mov.d	[--w15],w8
	return	
	.set ___PA___,0
.LFE3:
	.size	_readline, .-_readline
	.section .const,psv,page
.LC0:
	.asciz	"\015\012> "
	.section	.text,code
	.align	2
	.global	_main	; export
	.type	_main,@function
_main:
.LFB4:
	.loc 1 58 0
	.set ___PA___,1
	mov.d	w8,[w15++]
.LCFI3:
	.loc 1 59 0
	rcall	_gpio_init
	.loc 1 60 0
	mov	#49664,w0
	mov	#1,w1
	rcall	_config_uart
	.loc 1 63 0
	mov	#.LC0,w8
	.loc 1 65 0
	mov	#_line,w9
.L13:
	.loc 1 63 0
	mov	w8,w0
	rcall	_uart_puts
	.loc 1 64 0
	rcall	_readline
	.loc 1 65 0
	mov	w9,w0
	rcall	_uart_puts
	bra	.L13
.LFE4:
	.size	_main, .-_main
	.section	.bss,bss
	.type	_line,@object
	.global	_line
_line:	.space	80
	.section	.debug_frame,info
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x1
	.byte	0
	.uleb128 0x1
	.sleb128 2
	.byte	0x25
	.byte	0x12
	.uleb128 0xf
	.sleb128 -2
	.byte	0x9
	.uleb128 0x25
	.uleb128 0xf
	.align	4
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.align	4
.LEFDE0:
.LSFDE2:
	.4byte	.LEFDE2-.LASFDE2
.LASFDE2:
	.4byte	.Lframe0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.align	4
.LEFDE2:
.LSFDE4:
	.4byte	.LEFDE4-.LASFDE4
.LASFDE4:
	.4byte	.Lframe0
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.byte	0x4
	.4byte	.LCFI0-.LFB2
	.byte	0x13
	.sleb128 -4
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0x13
	.sleb128 -5
	.byte	0x8a
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x2
	.align	4
.LEFDE4:
.LSFDE6:
	.4byte	.LEFDE6-.LASFDE6
.LASFDE6:
	.4byte	.Lframe0
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.byte	0x4
	.4byte	.LCFI2-.LFB3
	.byte	0x13
	.sleb128 -4
	.byte	0x88
	.uleb128 0x2
	.align	4
.LEFDE6:
.LSFDE8:
	.4byte	.LEFDE8-.LASFDE8
.LASFDE8:
	.4byte	.Lframe0
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.byte	0x4
	.4byte	.LCFI3-.LFB4
	.byte	0x13
	.sleb128 -4
	.byte	0x88
	.uleb128 0x2
	.align	4
.LEFDE8:
	.section	.text,code
.Letext0:
	.file 2 "c:\\program files (x86)\\microchip\\xc16\\v1.36\\bin\\bin\\../..\\include/stdio.h"
	.file 3 "c:\\program files (x86)\\microchip\\xc16\\v1.36\\bin\\bin\\../..\\include/stddef.h"
	.file 4 "c:\\program files (x86)\\microchip\\xc16\\v1.36\\bin\\bin\\../..\\include/stdint.h"
	.section	.debug_info,info
	.4byte	0x2fd
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.asciz	"GNU C 4.5.1 (XC16, Microchip v1.36) (B) Build date: Jan 25 2019"
	.byte	0x1
	.asciz	"src/main.c"
	.asciz	"C:\\\\Users\\\\dconcors\\\\demos\\\\l1demo"
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.asciz	"int"
	.uleb128 0x3
	.asciz	"size_t"
	.byte	0x3
	.byte	0x5
	.4byte	0x9c
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.asciz	"long unsigned int"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.asciz	"short unsigned int"
	.uleb128 0x4
	.asciz	"_iobuf"
	.byte	0xe
	.byte	0x2
	.byte	0x39
	.4byte	0x135
	.uleb128 0x5
	.asciz	"_ptr"
	.byte	0x2
	.byte	0x3a
	.4byte	0x135
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x5
	.asciz	"_cnt"
	.byte	0x2
	.byte	0x3b
	.4byte	0x87
	.byte	0x2
	.byte	0x23
	.uleb128 0x2
	.uleb128 0x5
	.asciz	"_base"
	.byte	0x2
	.byte	0x3c
	.4byte	0x135
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x5
	.asciz	"_flag"
	.byte	0x2
	.byte	0x3d
	.4byte	0xb1
	.byte	0x2
	.byte	0x23
	.uleb128 0x6
	.uleb128 0x5
	.asciz	"_file"
	.byte	0x2
	.byte	0x3e
	.4byte	0x143
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x5
	.asciz	"_size"
	.byte	0x2
	.byte	0x3f
	.4byte	0x8e
	.byte	0x2
	.byte	0x23
	.uleb128 0xa
	.byte	0x0
	.uleb128 0x6
	.byte	0x2
	.4byte	0x13b
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.asciz	"char"
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.asciz	"short int"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.asciz	"signed char"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.asciz	"long int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.asciz	"long long int"
	.uleb128 0x3
	.asciz	"uint8_t"
	.byte	0x4
	.byte	0x2b
	.4byte	0x18b
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.asciz	"unsigned char"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.asciz	"unsigned int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.asciz	"long long unsigned int"
	.uleb128 0x7
	.byte	0x1
	.asciz	"uart_rx"
	.byte	0x1
	.byte	0x15
	.4byte	0x17c
	.4byte	.LFB0
	.4byte	.LFE0
	.byte	0x1
	.byte	0x5f
	.uleb128 0x8
	.byte	0x1
	.asciz	"uart_tx"
	.byte	0x1
	.byte	0x1a
	.byte	0x1
	.4byte	.LFB1
	.4byte	.LFE1
	.byte	0x1
	.byte	0x5f
	.4byte	0x207
	.uleb128 0x9
	.asciz	"c"
	.byte	0x1
	.byte	0x1a
	.4byte	0x17c
	.byte	0x1
	.byte	0x50
	.byte	0x0
	.uleb128 0x8
	.byte	0x1
	.asciz	"uart_puts"
	.byte	0x1
	.byte	0x1f
	.byte	0x1
	.4byte	.LFB2
	.4byte	.LFE2
	.byte	0x1
	.byte	0x5f
	.4byte	0x232
	.uleb128 0x9
	.asciz	"msg"
	.byte	0x1
	.byte	0x1f
	.4byte	0x135
	.byte	0x1
	.byte	0x5a
	.byte	0x0
	.uleb128 0xa
	.byte	0x1
	.asciz	"readline"
	.byte	0x1
	.byte	0x29
	.4byte	.LFB3
	.4byte	.LFE3
	.byte	0x1
	.byte	0x5f
	.4byte	0x264
	.uleb128 0xb
	.asciz	"i"
	.byte	0x1
	.byte	0x2b
	.4byte	0x17c
	.byte	0x1
	.byte	0x58
	.uleb128 0xb
	.asciz	"c"
	.byte	0x1
	.byte	0x2c
	.4byte	0x17c
	.byte	0x1
	.byte	0x50
	.byte	0x0
	.uleb128 0xc
	.byte	0x1
	.asciz	"main"
	.byte	0x1
	.byte	0x3a
	.byte	0x1
	.4byte	0x87
	.4byte	.LFB4
	.4byte	.LFE4
	.byte	0x1
	.byte	0x5f
	.4byte	0x29d
	.uleb128 0x9
	.asciz	"argc"
	.byte	0x1
	.byte	0x3a
	.4byte	0x87
	.byte	0x1
	.byte	0x50
	.uleb128 0x9
	.asciz	"argv"
	.byte	0x1
	.byte	0x3a
	.4byte	0x29d
	.byte	0x1
	.byte	0x51
	.byte	0x0
	.uleb128 0x6
	.byte	0x2
	.4byte	0x135
	.uleb128 0xd
	.4byte	0xc7
	.4byte	0x2b3
	.uleb128 0xe
	.4byte	0x9c
	.byte	0x2
	.byte	0x0
	.uleb128 0xf
	.asciz	"_iob"
	.byte	0x2
	.byte	0x40
	.4byte	0x2a3
	.byte	0x1
	.byte	0x1
	.uleb128 0xd
	.4byte	0x13b
	.4byte	0x2d1
	.uleb128 0xe
	.4byte	0x9c
	.byte	0x4f
	.byte	0x0
	.uleb128 0xf
	.asciz	"line"
	.byte	0x1
	.byte	0x13
	.4byte	0x2c1
	.byte	0x1
	.byte	0x1
	.uleb128 0xf
	.asciz	"_iob"
	.byte	0x2
	.byte	0x40
	.4byte	0x2a3
	.byte	0x1
	.byte	0x1
	.uleb128 0x10
	.asciz	"line"
	.byte	0x1
	.byte	0x13
	.4byte	0x2c1
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	_line
	.byte	0x0
	.section	.debug_abbrev,info
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,info
	.4byte	0x53
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x301
	.4byte	0x1c6
	.asciz	"uart_rx"
	.4byte	0x1e0
	.asciz	"uart_tx"
	.4byte	0x207
	.asciz	"uart_puts"
	.4byte	0x232
	.asciz	"readline"
	.4byte	0x264
	.asciz	"main"
	.4byte	0x2ed
	.asciz	"line"
	.4byte	0x0
	.section	.debug_pubtypes,info
	.4byte	0x30
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x301
	.4byte	0x8e
	.asciz	"size_t"
	.4byte	0xc7
	.asciz	"_iobuf"
	.4byte	0x17c
	.asciz	"uint8_t"
	.4byte	0x0
	.section	.debug_aranges,info
	.4byte	0x14
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.2byte	0x0
	.2byte	0x0
	.4byte	0x0
	.4byte	0x0
	.section	.debug_str,info
	.section	.text,code



	.section __c30_signature, info, data
	.word 0x0001
	.word 0x0001
	.word 0x0001

; MCHP configuration words
; Configuration word @ 0x0002abfe
	.section	.config_JTAGEN, code, address(0x2abfe), keep
__config_JTAGEN:
	.pword	16255
; Configuration word @ 0x0002abfc
	.section	.config_IESO, code, address(0x2abfc), keep
__config_IESO:
	.pword	39870
; Configuration word @ 0x0002abfa
	.section	.config_WPEND, code, address(0x2abfa), keep
__config_WPEND:
	.pword	60671

	.set ___PA___,0
	.end
