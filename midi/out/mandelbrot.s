	.file "/home/dconcors/projects/l1demo/src/mandelbrot.c"
	.section	.text,code
	.align	2
	.global	_fmul	; export
	.type	_fmul,@function
_fmul:
	.set ___PA___,1
	lnk	#8
	mov	w0,[w14+4]
	mov	w1,[w14+6]
	mov	[w14+4],w0
	asr	w0,#15,w1
	mov.d	w0,[w14]
	mov	[w14+6],w0
	asr	w0,#15,w1
	mov	[w14+2],w2
	mul.ss	w2,w0,w2
	mov	w2,w2
	mov	[w14],w3
	mul.ss	w3,w1,w6
	mov	w6,w3
	add	w2,w3,w2
	mov	[w14],w3
	mul.uu	w3,w0,w0
	add	w2,w1,w2
	mov	w2,w1
	mov.d	w0,[w14]
	mov.d	w0,[w14]
	mov.d	[w14],w0
	sl	w1,#2,w2
	lsr	w0,#14,w4
	ior	w2,w4,w4
	asr	w1,#14,w5
	mov.d	w4,[w14]
	mov	[w14],w0
	ulnk	
	return	
	.set ___PA___,0
	.size	_fmul, .-_fmul
	.align	2
	.global	_fadd	; export
	.type	_fadd,@function
_fadd:
	.set ___PA___,1
	lnk	#4
	mov	w0,[w14]
	mov	w1,[w14+2]
	mov	[w14+2],w0
	add	w0,[w14],w0
	ulnk	
	return	
	.set ___PA___,0
	.size	_fadd, .-_fadd
	.align	2
	.global	_mag	; export
	.type	_mag,@function
_mag:
	.set ___PA___,1
	lnk	#8
	mov	w0,[w14+6]
	mov	[w14+6],w0
	mov	[w0],w1
	mov	[w14+6],w0
	mov	[w0],w0
	rcall	_fmul
	mov	w0,[w14]
	mov	[w14+6],w0
	mov	[w0+2],w1
	mov	[w14+6],w0
	mov	[w0+2],w0
	rcall	_fmul
	mov	w0,[w14+2]
	mov	[w14],w0
	asr	w0,#14,w0
	mov	w0,[w14]
	mov	[w14+2],w0
	asr	w0,#14,w0
	mov	w0,[w14+2]
	mov	[w14+2],w0
	add	w0,[w14],w0
	mov	w0,[w14+4]
	mov	[w14+4],w0
	ulnk	
	return	
	.set ___PA___,0
	.size	_mag, .-_mag
	.align	2
	.global	_cadd	; export
	.type	_cadd,@function
_cadd:
	.set ___PA___,1
	lnk	#10
	mov	w0,[w14+4]
	mov	w1,[w14+6]
	mov	w2,[w14+8]
	mov	[w14+8],w0
	mov	[w0],w1
	mov	[w14+6],w0
	mov	[w0],w0
	rcall	_fadd
	mov	w0,[w14]
	mov	[w14+8],w0
	mov	[w0+2],w1
	mov	[w14+6],w0
	mov	[w0+2],w0
	rcall	_fadd
	mov	w0,[w14+2]
	mov	[w14+4],w0
	mov	[w14],[w0]
	mov	[w14+4],w0
	mov	[w14+2],w1
	mov	w1,[w0+2]
	ulnk	
	return	
	.set ___PA___,0
	.size	_cadd, .-_cadd
	.align	2
	.global	_cmul	; export
	.type	_cmul,@function
_cmul:
	.set ___PA___,1
	lnk	#10
	mov	w8,[w15++]
	mov	w0,[w14+4]
	mov	w1,[w14+6]
	mov	w2,[w14+8]
	mov	[w14+8],w0
	mov	[w0],w1
	mov	[w14+6],w0
	mov	[w0],w0
	rcall	_fmul
	mov	w0,w8
	mov	[w14+8],w0
	mov	[w0+2],w1
	mov	[w14+6],w0
	mov	[w0+2],w0
	rcall	_fmul
	sub	w8,w0,[w14]
	mov	[w14+8],w0
	mov	[w0+2],w1
	mov	[w14+6],w0
	mov	[w0],w0
	rcall	_fmul
	mov	w0,w8
	mov	[w14+8],w0
	mov	[w0],w1
	mov	[w14+6],w0
	mov	[w0+2],w0
	rcall	_fmul
	add	w8,w0,w0
	mov	w0,[w14+2]
	mov	[w14+4],w0
	mov	[w14],[w0]
	mov	[w14+4],w0
	mov	[w14+2],w1
	mov	w1,[w0+2]
	mov	[--w15],w8
	ulnk	
	return	
	.set ___PA___,0
	.size	_cmul, .-_cmul
	.align	2
	.global	_iterate	; export
	.type	_iterate,@function
_iterate:
	.set ___PA___,1
	lnk	#8
	mov	w0,[w14+6]
	clr	w0
	mov	w0,[w14]
	clr	w0
	mov	w0,[w14+2]
	clr	w0
	mov	w0,[w14+4]
	bra	.L7
.L10:
	mov	#255,w0
	mov	[w14],w1
	sub	w1,w0,[w15]
	.set ___BP___,0
	bra	nz,.L8
	mov	#255,w0
	bra	.L9
.L8:
	inc2	w14,w2
	inc2	w14,w1
	inc2	w14,w0
	rcall	_cmul
	inc2	w14,w1
	inc2	w14,w0
	mov	[w14+6],w2
	rcall	_cadd
	inc	[w14],[w14]
.L7:
	inc2	w14,w0
	rcall	_mag
	sub	w0,#1,[w15]
	.set ___BP___,0
	bra	leu,.L10
	mov	[w14],w0
.L9:
	ulnk	
	return	
	.set ___PA___,0
	.size	_iterate, .-_iterate



	.section __c30_signature, info, data
	.word 0x0001
	.word 0x0000
	.word 0x0000

; MCHP configuration words

	.set ___PA___,0
	.end
