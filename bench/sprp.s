_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%rax
	xorl	%esi, %esi
	movl	$2, %r8d
	movabsq	$2505271668025, %r9     ## imm = 0x2474DD3ED39
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
                                        ##     Child Loop BB0_13 Depth 2
	leaq	-1(%r8), %r10
	movl	$1582805, %eax          ## imm = 0x1826D5
	xorl	%edx, %edx
	divl	%r8d
	movl	%edx, %ecx
	xorl	%r11d, %r11d
	tzcntl	%r10d, %r11d
	shrxl	%r11d, %r10d, %eax
	shrl	%eax
	testl	%eax, %eax
	je	LBB0_11
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	%eax, %ebx
	movq	%r9, %rdi
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	%rdi, %rax
	orq	%r8, %rax
	shrq	$32, %rax
	je	LBB0_4
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=2
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%r8
	movq	%rdx, %rdi
	testb	$1, %bl
	jne	LBB0_7
LBB0_10:                                ##   in Loop: Header=BB0_3 Depth=2
	imulq	%rdi, %rdi
	shrq	%rbx
	jne	LBB0_3
	jmp	LBB0_11
LBB0_4:                                 ##   in Loop: Header=BB0_3 Depth=2
	xorl	%edx, %edx
	movl	%edi, %eax
	divl	%r8d
	movl	%edx, %edi
	testb	$1, %bl
	je	LBB0_10
LBB0_7:                                 ##   in Loop: Header=BB0_3 Depth=2
	imulq	%rdi, %rcx
	movq	%rcx, %rax
	orq	%r8, %rax
	shrq	$32, %rax
	je	LBB0_8
## %bb.9:                               ##   in Loop: Header=BB0_3 Depth=2
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r8
	movq	%rdx, %rcx
	imulq	%rdi, %rdi
	shrq	%rbx
	jne	LBB0_3
	jmp	LBB0_11
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=2
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r8d
	movl	%edx, %ecx
	imulq	%rdi, %rdi
	shrq	%rbx
	jne	LBB0_3
LBB0_11:                                ##   in Loop: Header=BB0_1 Depth=1
	cmpq	$1, %rcx
	je	LBB0_18
## %bb.12:                              ##   in Loop: Header=BB0_1 Depth=1
	xorl	%edi, %edi
	testl	%r11d, %r11d
	je	LBB0_19
LBB0_13:                                ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	%r10, %rcx
	je	LBB0_18
## %bb.14:                              ##   in Loop: Header=BB0_13 Depth=2
	imulq	%rcx, %rcx
	movq	%rcx, %rax
	orq	%r8, %rax
	shrq	$32, %rax
	je	LBB0_15
## %bb.16:                              ##   in Loop: Header=BB0_13 Depth=2
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r8
	movq	%rdx, %rcx
	addl	$1, %edi
	cmpl	%r11d, %edi
	jb	LBB0_13
	jmp	LBB0_19
LBB0_15:                                ##   in Loop: Header=BB0_13 Depth=2
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r8d
	movl	%edx, %ecx
	addl	$1, %edi
	cmpl	%r11d, %edi
	jb	LBB0_13
LBB0_19:                                ##   in Loop: Header=BB0_1 Depth=1
	addq	$1, %r8
	cmpq	$1000000, %r8           ## imm = 0xF4240
	jne	LBB0_1
	jmp	LBB0_20
LBB0_18:                                ##   in Loop: Header=BB0_1 Depth=1
	addl	$1, %esi
	addq	$1, %r8
	cmpq	$1000000, %r8           ## imm = 0xF4240
	jne	LBB0_1
LBB0_20:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
                                        ## kill: def $esi killed $esi killed $rsi
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
                                        ## -- End function
L_.str:                                 ## @.str
	.asciz	"%d\n"


