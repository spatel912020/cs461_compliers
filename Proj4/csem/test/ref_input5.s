	.text
	.file	"<stdin>"
	.p2align	4, 0x90                         # -- Begin function scale
	.type	scale,@function
scale:                                  # @scale
	.cfi_startproc
# %bb.0:
	movsd	%xmm0, -8(%rsp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_1
	jp	.LBB0_1
# %bb.5:                                # %L0
	xorl	%eax, %eax
	retq
.LBB0_1:                                # %L1
	movl	$0, -12(%rsp)
	movq	m@GOTPCREL(%rip), %rax
	cmpl	$6, -12(%rsp)
	jge	.LBB0_4
	.p2align	4, 0x90
.LBB0_3:                                # %L4
                                        # =>This Inner Loop Header: Depth=1
	movslq	-12(%rsp), %rcx
	movsd	(%rax,%rcx,8), %xmm0            # xmm0 = mem[0],zero
	mulsd	-8(%rsp), %xmm0
	movsd	%xmm0, (%rax,%rcx,8)
	incl	-12(%rsp)
	cmpl	$6, -12(%rsp)
	jl	.LBB0_3
.LBB0_4:                                # %L5
	movl	$1, %eax
	retq
.Lfunc_end0:
	.size	scale, .Lfunc_end0-scale
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI1_0:
	.quad	0x4014000000000000              # double 5
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	$0, 4(%rsp)
	movq	m@GOTPCREL(%rip), %rbx
	cmpl	$5, 4(%rsp)
	jg	.LBB1_3
	.p2align	4, 0x90
.LBB1_2:                                # %L7
                                        # =>This Inner Loop Header: Depth=1
	movslq	4(%rsp), %rax
	xorps	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	movsd	%xmm0, (%rbx,%rax,8)
	incl	%eax
	movl	%eax, 4(%rsp)
	cmpl	$5, 4(%rsp)
	jle	.LBB1_2
.LBB1_3:                                # %L8
	movsd	(%rbx), %xmm0                   # xmm0 = mem[0],zero
	movsd	16(%rbx), %xmm1                 # xmm1 = mem[0],zero
	movsd	40(%rbx), %xmm2                 # xmm2 = mem[0],zero
	leaq	.L__unnamed_1(%rip), %rdi
	movb	$3, %al
	callq	print@PLT
	movabsq	$4617315517961601024, %rax      # imm = 0x4014000000000000
	movq	%rax, 8(%rsp)
	movsd	.LCPI1_0(%rip), %xmm0           # xmm0 = mem[0],zero
	callq	scale
	movsd	(%rbx), %xmm0                   # xmm0 = mem[0],zero
	movsd	16(%rbx), %xmm1                 # xmm1 = mem[0],zero
	movsd	40(%rbx), %xmm2                 # xmm2 = mem[0],zero
	leaq	.L__unnamed_2(%rip), %rdi
	movb	$3, %al
	callq	print@PLT
	xorl	%eax, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	m,@object                       # @m
	.bss
	.globl	m
	.p2align	4
m:
	.zero	48
	.size	m, 48

	.type	.L__unnamed_1,@object           # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%5.1f %5.1f %5.1f\n"
	.size	.L__unnamed_1, 19

	.type	.L__unnamed_2,@object           # @1
.L__unnamed_2:
	.asciz	"%5.1f %5.1f %5.1f"
	.size	.L__unnamed_2, 18

	.section	".note.GNU-stack","",@progbits
