	.file "C:\\Users\\dconcors\\demos\\l1demo\\src\\gpio.c"
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
	.global	_ledon	; export
	.type	_ledon,@function
_ledon:
.LFB0:
	.file 1 "src/gpio.c"
	.loc 1 8 0
	.set ___PA___,1
	.loc 1 9 0
	bset.b	_PORTB,#4
	.loc 1 10 0
	return	
	.set ___PA___,0
.LFE0:
	.size	_ledon, .-_ledon
	.align	2
	.global	_ledoff	; export
	.type	_ledoff,@function
_ledoff:
.LFB1:
	.loc 1 13 0
	.set ___PA___,1
	.loc 1 14 0
	bclr.b	_PORTB,#4
	.loc 1 15 0
	return	
	.set ___PA___,0
.LFE1:
	.size	_ledoff, .-_ledoff
	.align	2
	.global	_gpio_init	; export
	.type	_gpio_init,@function
_gpio_init:
.LFB2:
	.loc 1 18 0
	.set ___PA___,1
	.loc 1 19 0
	clr	_ANSB
	.loc 1 20 0
	clr	_ANSC
	.loc 1 21 0
	clr	_ANSD
	.loc 1 22 0
	clr	_ANSF
	.loc 1 23 0
	clr	_ANSG
	.loc 1 24 0
	clr	_TRISB
	.loc 1 25 0
	return	
	.set ___PA___,0
.LFE2:
	.size	_gpio_init, .-_gpio_init
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
	.align	4
.LEFDE4:
	.section	.text,code
.Letext0:
	.file 2 "c:\\program files (x86)\\microchip\\xc16\\v1.36\\bin\\bin\\../..\\support\\PIC24F\\h/p24FJ256DA206.h"
	.file 3 "c:\\program files (x86)\\microchip\\xc16\\v1.36\\bin\\bin\\../..\\include/stdint.h"
	.section	.debug_info,info
	.4byte	0x233
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.asciz	"GNU C 4.5.1 (XC16, Microchip v1.36) (B) Build date: Jan 25 2019"
	.byte	0x1
	.asciz	"src/gpio.c"
	.asciz	"C:\\\\Users\\\\dconcors\\\\demos\\\\l1demo"
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.asciz	"signed char"
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.asciz	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.asciz	"long int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.asciz	"long long int"
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.asciz	"unsigned char"
	.uleb128 0x3
	.asciz	"uint16_t"
	.byte	0x3
	.byte	0x31
	.4byte	0xdb
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.asciz	"unsigned int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.asciz	"long unsigned int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.asciz	"long long unsigned int"
	.uleb128 0x4
	.byte	0x1
	.asciz	"ledon"
	.byte	0x1
	.byte	0x7
	.4byte	.LFB0
	.4byte	.LFE0
	.byte	0x1
	.byte	0x5f
	.uleb128 0x4
	.byte	0x1
	.asciz	"ledoff"
	.byte	0x1
	.byte	0xc
	.4byte	.LFB1
	.4byte	.LFE1
	.byte	0x1
	.byte	0x5f
	.uleb128 0x4
	.byte	0x1
	.asciz	"gpio_init"
	.byte	0x1
	.byte	0x11
	.4byte	.LFB2
	.4byte	.LFE2
	.byte	0x1
	.byte	0x5f
	.uleb128 0x5
	.asciz	"TRISB"
	.byte	0x2
	.2byte	0xda1
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x6
	.4byte	0xcb
	.uleb128 0x5
	.asciz	"PORTB"
	.byte	0x2
	.2byte	0xdb7
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSB"
	.byte	0x2
	.2byte	0x1339
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSC"
	.byte	0x2
	.2byte	0x134f
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSD"
	.byte	0x2
	.2byte	0x1358
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSF"
	.byte	0x2
	.2byte	0x1361
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSG"
	.byte	0x2
	.2byte	0x1368
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"TRISB"
	.byte	0x2
	.2byte	0xda1
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"PORTB"
	.byte	0x2
	.2byte	0xdb7
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSB"
	.byte	0x2
	.2byte	0x1339
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSC"
	.byte	0x2
	.2byte	0x134f
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSD"
	.byte	0x2
	.2byte	0x1358
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSF"
	.byte	0x2
	.2byte	0x1361
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.asciz	"ANSG"
	.byte	0x2
	.2byte	0x1368
	.4byte	0x16b
	.byte	0x1
	.byte	0x1
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
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0x35
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,info
	.4byte	0x31
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x237
	.4byte	0x11a
	.asciz	"ledon"
	.4byte	0x12e
	.asciz	"ledoff"
	.4byte	0x143
	.asciz	"gpio_init"
	.4byte	0x0
	.section	.debug_pubtypes,info
	.4byte	0x1b
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x237
	.4byte	0xcb
	.asciz	"uint16_t"
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
	.word 0x0000
	.word 0x0000

; MCHP configuration words

	.set ___PA___,0
	.end
