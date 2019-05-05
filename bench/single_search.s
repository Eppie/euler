	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev ## -- Begin function _ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev
	.p2align	4, 0x90
__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev: ## @_ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	LBB0_1
## %bb.2:
	popq	%rbp
	jmp	__ZdlPv                 ## TAILCALL
LBB0_1:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z8sieveOfEv           ## -- Begin function _Z8sieveOfEv
	.p2align	4, 0x90
__Z8sieveOfEv:                          ## @_Z8sieveOfEv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_B(%rip), %r9
	andq	$-4, (%r9)
	movl	$3, %r8d
	.p2align	4, 0x90
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_4 Depth 2
	movq	%r8, %rcx
	shrq	$7, %rcx
	movl	%r8d, %edx
	shrb	%dl
	movq	(%r9,%rcx,8), %rcx
	movzbl	%dl, %edx
	btq	%rdx, %rcx
	jae	LBB1_5
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	%r8, %rsi
	imulq	%r8, %rsi
	movq	%rsi, %rcx
	shrq	$32, %rcx
	jne	LBB1_5
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	leaq	(%r8,%r8), %rdi
	.p2align	4, 0x90
LBB1_4:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	%rsi, %rdx
	movl	%esi, %ecx
	shrb	%cl
	movq	$-2, %rax
	rolq	%cl, %rax
	shrq	$7, %rdx
	andq	%rax, (%r9,%rdx,8)
	addq	%rdi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	je	LBB1_4
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	addq	$2, %r8
	cmpq	$65537, %r8             ## imm = 0x10001
	jb	LBB1_1
## %bb.6:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z8isPrimeEj           ## -- Begin function _Z8isPrimeEj
	.p2align	4, 0x90
__Z8isPrimeEj:                          ## @_Z8isPrimeEj
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $edi killed $edi def $rdi
	testb	$1, %dil
	sete	%cl
	cmpl	$2, %edi
	setne	%dl
	xorl	%eax, %eax
	cmpl	$2, %edi
	jb	LBB2_7
## %bb.1:
	andb	%cl, %dl
	jne	LBB2_7
## %bb.2:
	cmpl	$3, %edi
	je	LBB2_5
## %bb.3:
	movl	%edi, %eax
	movl	$2863311531, %ecx       ## imm = 0xAAAAAAAB
	imulq	%rax, %rcx
	shrq	$33, %rcx
	leal	(%rcx,%rcx,2), %eax
	movl	%edi, %ecx
	subl	%eax, %ecx
	jne	LBB2_5
## %bb.4:
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	popq	%rbp
	retq
LBB2_5:
	movb	$1, %al
	cmpl	$4, %edi
	jb	LBB2_7
## %bb.6:
	movl	%edi, %eax
	shrl	%eax
	shrl	$4, %edi
	movq	_B(%rip), %rcx
	andl	$-8, %edi
	movq	(%rcx,%rdi), %rcx
	btq	%rax, %rcx
	setb	%al
LBB2_7:
                                        ## kill: def $al killed $al killed $eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z7is_SPRPjjjj         ## -- Begin function _Z7is_SPRPjjjj
	.p2align	4, 0x90
__Z7is_SPRPjjjj:                        ## @_Z7is_SPRPjjjj
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edx, %eax
                                        ## kill: def $edi killed $edi def $rdi
	movb	$1, %r8b
	testl	%edx, %edx
	je	LBB3_19
## %bb.1:
	movl	%esi, %edx
	movl	%eax, %r11d
	movl	%edi, %r10d
	movl	$1, %r9d
	.p2align	4, 0x90
LBB3_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	%edx, %esi
	testb	$1, %r11b
	je	LBB3_6
## %bb.3:                               ##   in Loop: Header=BB3_2 Depth=1
	imulq	%rsi, %r9
	movq	%r9, %rax
	shrq	$32, %rax
	je	LBB3_4
## %bb.5:                               ##   in Loop: Header=BB3_2 Depth=1
	xorl	%edx, %edx
	movq	%r9, %rax
	divq	%r10
	movq	%rdx, %r9
LBB3_6:                                 ##   in Loop: Header=BB3_2 Depth=1
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	je	LBB3_7
LBB3_8:                                 ##   in Loop: Header=BB3_2 Depth=1
	xorl	%edx, %edx
	movq	%rsi, %rax
	divq	%r10
	shrq	%r11
	jne	LBB3_2
	jmp	LBB3_10
LBB3_4:                                 ##   in Loop: Header=BB3_2 Depth=1
	xorl	%edx, %edx
	movl	%r9d, %eax
	divl	%r10d
	movl	%edx, %r9d
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	jne	LBB3_8
	.p2align	4, 0x90
LBB3_7:                                 ##   in Loop: Header=BB3_2 Depth=1
	xorl	%edx, %edx
	movl	%esi, %eax
	divl	%r10d
                                        ## kill: def $edx killed $edx def $rdx
	shrq	%r11
	jne	LBB3_2
LBB3_10:
	cmpq	$1, %r9
	je	LBB3_19
## %bb.11:
	xorl	%esi, %esi
	testl	%ecx, %ecx
	je	LBB3_18
## %bb.12:
	addl	$-1, %edi
	.p2align	4, 0x90
LBB3_13:                                ## =>This Inner Loop Header: Depth=1
	cmpq	%rdi, %r9
	je	LBB3_19
## %bb.14:                              ##   in Loop: Header=BB3_13 Depth=1
	imulq	%r9, %r9
	movq	%r9, %rax
	shrq	$32, %rax
	je	LBB3_15
## %bb.16:                              ##   in Loop: Header=BB3_13 Depth=1
	xorl	%edx, %edx
	movq	%r9, %rax
	divq	%r10
	movq	%rdx, %r9
	addl	$1, %esi
	cmpl	%ecx, %esi
	jb	LBB3_13
	jmp	LBB3_18
	.p2align	4, 0x90
LBB3_15:                                ##   in Loop: Header=BB3_13 Depth=1
	xorl	%edx, %edx
	movl	%r9d, %eax
	divl	%r10d
	movl	%edx, %r9d
	addl	$1, %esi
	cmpl	%ecx, %esi
	jb	LBB3_13
LBB3_18:
	xorl	%r8d, %r8d
LBB3_19:
	movl	%r8d, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI4_0:
	.quad	4472406533629990549     ## double 1.0000000000000001E-9
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	callq	__ZNSt3__16chrono12steady_clock3nowEv
	movq	%rax, %r14
	movq	_B(%rip), %rax
	andq	$-4, (%rax)
	movl	$3, %r8d
	.p2align	4, 0x90
LBB4_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB4_4 Depth 2
	movq	%r8, %rcx
	shrq	$7, %rcx
	movl	%r8d, %ebx
	shrb	%bl
	movq	(%rax,%rcx,8), %rcx
	movzbl	%bl, %esi
	btq	%rsi, %rcx
	jae	LBB4_5
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	movq	%r8, %rsi
	imulq	%r8, %rsi
	movq	%rsi, %rcx
	shrq	$32, %rcx
	jne	LBB4_5
## %bb.3:                               ##   in Loop: Header=BB4_1 Depth=1
	leaq	(%r8,%r8), %rdi
	.p2align	4, 0x90
LBB4_4:                                 ##   Parent Loop BB4_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	%rsi, %rbx
	movl	%esi, %ecx
	shrb	%cl
	movq	$-2, %rdx
	rolq	%cl, %rdx
	shrq	$7, %rbx
	andq	%rdx, (%rax,%rbx,8)
	addq	%rdi, %rsi
	movq	%rsi, %rcx
	shrq	$32, %rcx
	je	LBB4_4
LBB4_5:                                 ##   in Loop: Header=BB4_1 Depth=1
	addq	$2, %r8
	cmpq	$65537, %r8             ## imm = 0x10001
	jb	LBB4_1
## %bb.6:
	callq	__ZNSt3__16chrono12steady_clock3nowEv
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	subq	%r14, %rax
	vcvtsi2sdq	%rax, %xmm0, %xmm0
	vmulsd	LCPI4_0(%rip), %xmm0, %xmm0
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	callq	_printf
	movl	$2400000000, %edi       ## imm = 0x8F0D1800
	callq	__Znam
	movl	$2400000000, %esi       ## imm = 0x8F0D1800
	movq	%rax, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	___bzero
	movl	$2400000000, %edi       ## imm = 0x8F0D1800
	callq	__Znam
	movl	$2400000000, %esi       ## imm = 0x8F0D1800
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	___bzero
	movl	$2400000000, %edi       ## imm = 0x8F0D1800
	callq	__Znam
	movl	$2400000000, %esi       ## imm = 0x8F0D1800
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	___bzero
	movl	$3, %eax
	movl	$0, -44(%rbp)           ## 4-byte Folded Spill
	movl	$2924233053, %r10d      ## imm = 0xAE4C415D
	movl	$3352169597, %r9d       ## imm = 0xC7CE0C7D
	movl	$3134165325, %r8d       ## imm = 0xBACF914D
	movl	$2369637129, %r14d      ## imm = 0x8D3DCB09
	movl	$3123612579, %r11d      ## imm = 0xBA2E8BA3
	movl	$3435973837, %r15d      ## imm = 0xCCCCCCCD
	movl	$2863311531, %r13d      ## imm = 0xAAAAAAAB
	.p2align	4, 0x90
LBB4_7:                                 ## =>This Inner Loop Header: Depth=1
	movl	%eax, %ebx
	imulq	$891408307, %rbx, %rdi  ## imm = 0x3521CFB3
	shrq	$32, %rdi
	movl	%eax, %r12d
	subl	%edi, %r12d
	shrl	%r12d
	addl	%edi, %r12d
	shrl	$5, %r12d
	imull	$-53, %r12d, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.8:                               ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rdi
	imulq	%r10, %rdi
	shrq	$37, %rdi
	imull	$-47, %edi, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.9:                               ##   in Loop: Header=BB4_7 Depth=1
	imulq	$799063683, %rbx, %rdi  ## imm = 0x2FA0BE83
	shrq	$35, %rdi
	imull	$-43, %edi, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.10:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rdi
	imulq	%r9, %rdi
	shrq	$37, %rdi
	imull	$-41, %edi, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.11:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rdi
	imulq	%r8, %rdi
	shrq	$32, %rdi
	movl	%eax, %esi
	subl	%edi, %esi
	shrl	%esi
	addl	%edi, %esi
	shrl	$5, %esi
	imull	$-37, %esi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.12:                              ##   in Loop: Header=BB4_7 Depth=1
	imulq	$138547333, %rbx, %rsi  ## imm = 0x8421085
	shrq	$32, %rsi
	movl	%eax, %edi
	subl	%esi, %edi
	shrl	%edi
	addl	%esi, %edi
	shrl	$4, %edi
	movl	%edi, %esi
	shll	$5, %esi
	subl	%esi, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.13:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	imulq	%r14, %rsi
	shrq	$36, %rsi
	imull	$-29, %esi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.14:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	movl	$2987803337, %ecx       ## imm = 0xB21642C9
	imulq	%rcx, %rsi
	shrq	$36, %rsi
	imull	$-23, %esi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.15:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	movl	$2938661835, %ecx       ## imm = 0xAF286BCB
	imulq	%rcx, %rsi
	shrq	$32, %rsi
	movl	%eax, %edi
	subl	%esi, %edi
	shrl	%edi
	addl	%esi, %edi
	shrl	$4, %edi
	imull	$-19, %edi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.16:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	movl	$4042322161, %ecx       ## imm = 0xF0F0F0F1
	imulq	%rcx, %rsi
	shrq	$36, %rsi
	movl	%esi, %edi
	shll	$4, %edi
	addl	%esi, %edi
	movl	%eax, %esi
	subl	%edi, %esi
	je	LBB4_23
## %bb.17:                              ##   in Loop: Header=BB4_7 Depth=1
	imulq	$1321528399, %rbx, %rsi ## imm = 0x4EC4EC4F
	shrq	$34, %rsi
	imull	$-13, %esi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.18:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	imulq	%r11, %rsi
	shrq	$35, %rsi
	imull	$-11, %esi, %esi
	addl	%eax, %esi
	je	LBB4_23
## %bb.19:                              ##   in Loop: Header=BB4_7 Depth=1
	imulq	$613566757, %rbx, %rsi  ## imm = 0x24924925
	shrq	$32, %rsi
	movl	%eax, %edi
	subl	%esi, %edi
	shrl	%edi
	addl	%esi, %edi
	shrl	$2, %edi
	leal	(,%rdi,8), %esi
	subl	%esi, %edi
	addl	%eax, %edi
	je	LBB4_23
## %bb.20:                              ##   in Loop: Header=BB4_7 Depth=1
	movq	%rbx, %rsi
	imulq	%r13, %rsi
	shrq	$33, %rsi
	leal	(%rsi,%rsi,2), %esi
	movl	%eax, %edi
	subl	%esi, %edi
	je	LBB4_23
## %bb.21:                              ##   in Loop: Header=BB4_7 Depth=1
	imulq	%r15, %rbx
	shrq	$34, %rbx
	leal	(%rbx,%rbx,4), %esi
	movl	%eax, %edi
	subl	%esi, %edi
	je	LBB4_23
## %bb.22:                              ##   in Loop: Header=BB4_7 Depth=1
	leal	-1(%rax), %esi
	xorl	%edi, %edi
	tzcntl	%esi, %edi
	shrxl	%edi, %esi, %esi
	movl	-44(%rbp), %ecx         ## 4-byte Reload
	movl	%ecx, %ebx
	movq	-88(%rbp), %rdx         ## 8-byte Reload
	movl	%esi, (%rdx,%rbx,4)
	movq	-72(%rbp), %rsi         ## 8-byte Reload
	movl	%edi, (%rsi,%rbx,4)
	addl	$1, %ecx
	movl	%ecx, -44(%rbp)         ## 4-byte Spill
	movq	-80(%rbp), %rsi         ## 8-byte Reload
	movl	%eax, (%rsi,%rbx,4)
LBB4_23:                                ##   in Loop: Header=BB4_7 Depth=1
	addq	$2, %rax
	movq	%rax, %rsi
	shrq	$32, %rsi
	je	LBB4_7
## %bb.24:
	callq	__ZNSt3__16chrono12steady_clock3nowEv
	subq	-56(%rbp), %rax         ## 8-byte Folded Reload
	vcvtsi2sdq	%rax, %xmm1, %xmm0
	vmulsd	LCPI4_0(%rip), %xmm0, %xmm0
	leaq	L_.str.1(%rip), %rdi
	movb	$1, %al
	movl	-44(%rbp), %ebx         ## 4-byte Reload
	movl	%ebx, %esi
	callq	_printf
	movl	%ebx, %r14d
	movl	$2, %r13d
	xorl	%edx, %edx
	movl	$0, -60(%rbp)           ## 4-byte Folded Spill
	movq	-80(%rbp), %r10         ## 8-byte Reload
	movq	-72(%rbp), %r11         ## 8-byte Reload
	.p2align	4, 0x90
LBB4_25:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB4_27 Depth 2
                                        ##       Child Loop BB4_36 Depth 3
                                        ##       Child Loop BB4_47 Depth 3
	cmpl	$0, -44(%rbp)           ## 4-byte Folded Reload
	je	LBB4_62
## %bb.26:                              ##   in Loop: Header=BB4_25 Depth=1
	movl	%edx, -56(%rbp)         ## 4-byte Spill
	movq	_B(%rip), %r8
	xorl	%r15d, %r15d
	.p2align	4, 0x90
LBB4_27:                                ##   Parent Loop BB4_25 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB4_36 Depth 3
                                        ##       Child Loop BB4_47 Depth 3
	movl	(%r10,%r15,4), %r12d
	cmpq	$2, %r12
	setne	%al
	testb	$1, %r12b
	sete	%cl
	xorl	%r9d, %r9d
	cmpq	$2, %r12
	jb	LBB4_34
## %bb.28:                              ##   in Loop: Header=BB4_27 Depth=2
	andb	%cl, %al
	jne	LBB4_34
## %bb.29:                              ##   in Loop: Header=BB4_27 Depth=2
	cmpl	$3, %r12d
	je	LBB4_32
## %bb.30:                              ##   in Loop: Header=BB4_27 Depth=2
	movl	%r12d, %eax
	movl	$2863311531, %ecx       ## imm = 0xAAAAAAAB
	imulq	%rcx, %rax
	shrq	$33, %rax
	leal	(%rax,%rax,2), %eax
	movl	%r12d, %ecx
	subl	%eax, %ecx
	jne	LBB4_32
## %bb.31:                              ##   in Loop: Header=BB4_27 Depth=2
	xorl	%r9d, %r9d
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movl	(%rax,%r15,4), %edi
	testq	%rdi, %rdi
	jne	LBB4_35
	jmp	LBB4_59
	.p2align	4, 0x90
LBB4_32:                                ##   in Loop: Header=BB4_27 Depth=2
	movb	$1, %r9b
	cmpl	$4, %r12d
	jb	LBB4_34
## %bb.33:                              ##   in Loop: Header=BB4_27 Depth=2
	movq	%r12, %rax
	shrq	%rax
	movq	%r12, %rcx
	shrq	$7, %rcx
	movq	(%r8,%rcx,8), %rcx
	btq	%rax, %rcx
	setb	%r9b
	.p2align	4, 0x90
LBB4_34:                                ##   in Loop: Header=BB4_27 Depth=2
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movl	(%rax,%r15,4), %edi
	testq	%rdi, %rdi
	je	LBB4_59
LBB4_35:                                ##   in Loop: Header=BB4_27 Depth=2
	movl	(%r11,%r15,4), %ebx
	movl	$1, %ecx
	movl	%r13d, %edx
	.p2align	4, 0x90
LBB4_36:                                ##   Parent Loop BB4_25 Depth=1
                                        ##     Parent Loop BB4_27 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	%edx, %esi
	testb	$1, %dil
	je	LBB4_40
## %bb.37:                              ##   in Loop: Header=BB4_36 Depth=3
	imulq	%rsi, %rcx
	movq	%rcx, %rax
	shrq	$32, %rax
	je	LBB4_38
## %bb.39:                              ##   in Loop: Header=BB4_36 Depth=3
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r12
	movq	%rdx, %rcx
LBB4_40:                                ##   in Loop: Header=BB4_36 Depth=3
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	je	LBB4_41
LBB4_42:                                ##   in Loop: Header=BB4_36 Depth=3
	xorl	%edx, %edx
	movq	%rsi, %rax
	divq	%r12
	shrq	%rdi
	jne	LBB4_36
	jmp	LBB4_44
LBB4_38:                                ##   in Loop: Header=BB4_36 Depth=3
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r12d
	movl	%edx, %ecx
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	jne	LBB4_42
	.p2align	4, 0x90
LBB4_41:                                ##   in Loop: Header=BB4_36 Depth=3
	xorl	%edx, %edx
	movl	%esi, %eax
	divl	%r12d
                                        ## kill: def $edx killed $edx def $rdx
	shrq	%rdi
	jne	LBB4_36
LBB4_44:                                ##   in Loop: Header=BB4_27 Depth=2
	cmpq	$1, %rcx
	je	LBB4_59
## %bb.45:                              ##   in Loop: Header=BB4_27 Depth=2
	testl	%ebx, %ebx
	je	LBB4_52
## %bb.46:                              ##   in Loop: Header=BB4_27 Depth=2
	leal	-1(%r12), %esi
	xorl	%edi, %edi
	.p2align	4, 0x90
LBB4_47:                                ##   Parent Loop BB4_25 Depth=1
                                        ##     Parent Loop BB4_27 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpq	%rsi, %rcx
	je	LBB4_59
## %bb.48:                              ##   in Loop: Header=BB4_47 Depth=3
	imulq	%rcx, %rcx
	movq	%rcx, %rax
	shrq	$32, %rax
	je	LBB4_49
## %bb.50:                              ##   in Loop: Header=BB4_47 Depth=3
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r12
	movq	%rdx, %rcx
	addl	$1, %edi
	cmpl	%ebx, %edi
	jb	LBB4_47
	jmp	LBB4_52
	.p2align	4, 0x90
LBB4_49:                                ##   in Loop: Header=BB4_47 Depth=3
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r12d
	movl	%edx, %ecx
	addl	$1, %edi
	cmpl	%ebx, %edi
	jb	LBB4_47
	.p2align	4, 0x90
LBB4_52:                                ##   in Loop: Header=BB4_27 Depth=2
	testb	%r9b, %r9b
	jne	LBB4_53
LBB4_60:                                ##   in Loop: Header=BB4_27 Depth=2
	addq	$1, %r15
	cmpq	%r14, %r15
	jb	LBB4_27
	jmp	LBB4_61
	.p2align	4, 0x90
LBB4_59:                                ##   in Loop: Header=BB4_27 Depth=2
	testb	%r9b, %r9b
	jne	LBB4_60
LBB4_53:                                ##   in Loop: Header=BB4_25 Depth=1
	cmpl	-60(%rbp), %r12d        ## 4-byte Folded Reload
	jbe	LBB4_55
## %bb.54:                              ##   in Loop: Header=BB4_25 Depth=1
	xorl	%eax, %eax
	leaq	L_.str.2(%rip), %rdi
	movl	%r12d, %esi
	movl	%r13d, %edx
	movl	-56(%rbp), %ecx         ## 4-byte Reload
	callq	_printf
	movq	-72(%rbp), %r11         ## 8-byte Reload
	movq	-80(%rbp), %r10         ## 8-byte Reload
	movl	%r12d, %eax
	movl	%r12d, -60(%rbp)        ## 4-byte Spill
LBB4_55:                                ##   in Loop: Header=BB4_25 Depth=1
	movl	-56(%rbp), %edx         ## 4-byte Reload
	cmpl	%r15d, %edx
	jae	LBB4_57
## %bb.56:                              ##   in Loop: Header=BB4_25 Depth=1
	movl	%r15d, %eax
	movl	%edx, %ecx
	movl	(%r10,%rcx,4), %esi
	movl	%r12d, (%r10,%rcx,4)
	movl	%esi, (%r10,%rax,4)
	addl	$1, %edx
LBB4_57:                                ##   in Loop: Header=BB4_25 Depth=1
	movl	%r13d, %eax
	imulq	$1441151881, %rax, %rax ## imm = 0x55E63B89
	shrq	$57, %rax
	imull	$100000000, %eax, %eax  ## imm = 0x5F5E100
	cmpl	%eax, %r13d
	je	LBB4_58
	.p2align	4, 0x90
LBB4_62:                                ##   in Loop: Header=BB4_25 Depth=1
	addl	$1, %r13d
	cmpl	$-4967295, %r13d        ## imm = 0xFFB43481
	jne	LBB4_25
	jmp	LBB4_63
	.p2align	4, 0x90
LBB4_61:                                ##   in Loop: Header=BB4_25 Depth=1
	movl	-56(%rbp), %edx         ## 4-byte Reload
	addl	$1, %r13d
	cmpl	$-4967295, %r13d        ## imm = 0xFFB43481
	jne	LBB4_25
	jmp	LBB4_63
LBB4_58:                                ##   in Loop: Header=BB4_25 Depth=1
	xorl	%eax, %eax
	leaq	L_.str.3(%rip), %rdi
	movl	%r13d, %esi
	movl	%edx, %ebx
	callq	_printf
	movl	%ebx, %edx
	movq	-72(%rbp), %r11         ## 8-byte Reload
	movq	-80(%rbp), %r10         ## 8-byte Reload
	addl	$1, %r13d
	cmpl	$-4967295, %r13d        ## imm = 0xFFB43481
	jne	LBB4_25
LBB4_63:
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## -- Begin function _GLOBAL__sub_I_single_search.cpp
LCPI5_0:
	.quad	2147483648              ## 0x80000000
	.quad	33554432                ## 0x2000000
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
__GLOBAL__sub_I_single_search.cpp:      ## @_GLOBAL__sub_I_single_search.cpp
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	vxorps	%xmm0, %xmm0, %xmm0
	vmovups	%xmm0, _B(%rip)
	movq	$0, _B+16(%rip)
	leaq	_B(%rip), %rbx
	movl	$268435456, %edi        ## imm = 0x10000000
	callq	__Znwm
	movq	%rax, _B(%rip)
	vmovaps	LCPI5_0(%rip), %xmm0    ## xmm0 = [2147483648,33554432]
	vmovups	%xmm0, _B+8(%rip)
	movl	$255, %esi
	movl	$268435456, %edx        ## imm = 0x10000000
	movq	%rax, %rdi
	callq	_memset
	movq	__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev@GOTPCREL(%rip), %rdi
	leaq	___dso_handle(%rip), %rdx
	movq	%rbx, %rsi
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	jmp	___cxa_atexit           ## TAILCALL
	.cfi_endproc
                                        ## -- End function
	.globl	_B                      ## @B
.zerofill __DATA,__common,_B,24,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Done sieving. Took %fs\n"

L_.str.1:                               ## @.str.1
	.asciz	"Done filling values! Count: %u, Took: %fs\n"

L_.str.2:                               ## @.str.2
	.asciz	"New best! Value: %u, Base: %u, swapCounter= %u\n"

L_.str.3:                               ## @.str.3
	.asciz	"At base %u, swapCounter = %u\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_single_search.cpp

.subsections_via_symbols
