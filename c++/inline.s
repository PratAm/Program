	.file	"inline.cpp"
	.section	.rodata
.LC0:
	.string	"testing call"
	.section	.text._Z7callfuni,"axG",@progbits,_Z7callfuni,comdat
	.weak	_Z7callfuni
	.type	_Z7callfuni, @function
_Z7callfuni:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, (%esp)
	call	puts
	movl	8(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	_Z7callfuni, .-_Z7callfuni
	.section	.rodata
.LC1:
	.string	"value %d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$6, (%esp)
	call	_Z7callfuni
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 4
	.type	_ZL3ptr, @object
	.size	_ZL3ptr, 4
_ZL3ptr:
	.long	5
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
