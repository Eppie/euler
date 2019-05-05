__Z8sieveOfEv:                          ## @_Z8sieveOfEv
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	_B(%rip), %r9
	andq	$-4, (%r9)
	movl	$3, %r8d
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_4 Depth 2
	movq	%r8, %rcx
	shrq	$7, %rcx
	movl	%r8d, %edx
	shrb	%dl
	movq	(%r9,%rcx,8), %rcx
	movzbl	%dl, %edx
	btq	%rdx, %rcx
	jae	LBB0_5
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	%r8, %rsi
	imulq	%r8, %rsi
	movq	%rsi, %rcx
	shrq	$32, %rcx
	jne	LBB0_5
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	(%r8,%r8), %rdi
LBB0_4:                                 ##   Parent Loop BB0_1 Depth=1
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
	je	LBB0_4
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	addq	$2, %r8
	cmpq	$65537, %r8             ## imm = 0x10001
	jb	LBB0_1
## %bb.6:
	popq	%rbp
	retq
                                        ## -- End function
__Z8isPrimeEj:                          ## @_Z8isPrimeEj
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
                                        ## kill: def $edi killed $edi def $rdi
	testb	$1, %dil
	sete	%cl
	cmpl	$2, %edi
	setne	%dl
	xorl	%eax, %eax
	cmpl	$2, %edi
	jb	LBB1_7
## %bb.1:
	andb	%cl, %dl
	jne	LBB1_7
## %bb.2:
	cmpl	$3, %edi
	je	LBB1_5
## %bb.3:
	movl	%edi, %eax
	movl	$2863311531, %ecx       ## imm = 0xAAAAAAAB
	imulq	%rax, %rcx
	shrq	$33, %rcx
	leal	(%rcx,%rcx,2), %eax
	movl	%edi, %ecx
	subl	%eax, %ecx
	jne	LBB1_5
## %bb.4:
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	popq	%rbp
	retq
LBB1_5:
	movb	$1, %al
	cmpl	$4, %edi
	jb	LBB1_7
## %bb.6:
	movl	%edi, %eax
	shrl	%eax
	shrl	$4, %edi
	movq	_B(%rip), %rcx
	andl	$-8, %edi
	movq	(%rcx,%rdi), %rcx
	btq	%rax, %rcx
	setb	%al
LBB1_7:
                                        ## kill: def $al killed $al killed $eax
	popq	%rbp
	retq
                                        ## -- End function
__Z7is_SPRPjj:                          ## @_Z7is_SPRPjj
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%esi, %edx
                                        ## kill: def $edi killed $edi def $rdi
	leal	-1(%rdi), %r10d
	xorl	%ecx, %ecx
	movl	%r10d, %eax
	testb	$1, %r10b
	jne	LBB2_3
## %bb.1:
	xorl	%ecx, %ecx
	movl	%r10d, %esi
	movl	%r10d, %eax
LBB2_2:                                 ## =>This Inner Loop Header: Depth=1
	addl	$1, %ecx
	shrl	%eax
	testb	$2, %sil
	movl	%eax, %esi
	je	LBB2_2
LBB2_3:
	movb	$1, %r8b
	testl	%eax, %eax
	je	LBB2_22
## %bb.4:
	movl	%eax, %esi
	movl	%edi, %r9d
	movl	$1, %r11d
LBB2_5:                                 ## =>This Inner Loop Header: Depth=1
	movl	%edx, %edi
	testb	$1, %sil
	je	LBB2_9
## %bb.6:                               ##   in Loop: Header=BB2_5 Depth=1
	imulq	%rdi, %r11
	movq	%r11, %rax
	shrq	$32, %rax
	je	LBB2_7
## %bb.8:                               ##   in Loop: Header=BB2_5 Depth=1
	xorl	%edx, %edx
	movq	%r11, %rax
	divq	%r9
	movq	%rdx, %r11
LBB2_9:                                 ##   in Loop: Header=BB2_5 Depth=1
	imulq	%rdi, %rdi
	movq	%rdi, %rax
	shrq	$32, %rax
	je	LBB2_10
LBB2_11:                                ##   in Loop: Header=BB2_5 Depth=1
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%r9
	shrq	%rsi
	jne	LBB2_5
	jmp	LBB2_13
LBB2_7:                                 ##   in Loop: Header=BB2_5 Depth=1
	xorl	%edx, %edx
	movl	%r11d, %eax
	divl	%r9d
	movl	%edx, %r11d
	imulq	%rdi, %rdi
	movq	%rdi, %rax
	shrq	$32, %rax
	jne	LBB2_11
LBB2_10:                                ##   in Loop: Header=BB2_5 Depth=1
	xorl	%edx, %edx
	movl	%edi, %eax
	divl	%r9d
                                        ## kill: def $edx killed $edx def $rdx
	shrq	%rsi
	jne	LBB2_5
LBB2_13:
	cmpq	$1, %r11
	je	LBB2_22
## %bb.14:
	xorl	%esi, %esi
	testl	%ecx, %ecx
	je	LBB2_21
## %bb.15:
	movl	%r10d, %edi
LBB2_16:                                ## =>This Inner Loop Header: Depth=1
	cmpq	%rdi, %r11
	je	LBB2_22
## %bb.17:                              ##   in Loop: Header=BB2_16 Depth=1
	imulq	%r11, %r11
	movq	%r11, %rax
	shrq	$32, %rax
	je	LBB2_18
## %bb.19:                              ##   in Loop: Header=BB2_16 Depth=1
	xorl	%edx, %edx
	movq	%r11, %rax
	divq	%r9
	movq	%rdx, %r11
	addl	$1, %esi
	cmpl	%ecx, %esi
	jb	LBB2_16
	jmp	LBB2_21
LBB2_18:                                ##   in Loop: Header=BB2_16 Depth=1
	xorl	%edx, %edx
	movl	%r11d, %eax
	divl	%r9d
	movl	%edx, %r11d
	addl	$1, %esi
	cmpl	%ecx, %esi
	jb	LBB2_16
LBB2_21:
	xorl	%r8d, %r8d
LBB2_22:
	movl	%r8d, %eax
	popq	%rbp
	retq
                                        ## -- End function
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	movq	___stdoutp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	xorl	%esi, %esi
	callq	_setbuf
	movq	_B(%rip), %rax
	andq	$-4, (%rax)
	movl	$3, %r8d
LBB3_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB3_4 Depth 2
	movq	%r8, %rcx
	shrq	$7, %rcx
	movl	%r8d, %ebx
	shrb	%bl
	movq	(%rax,%rcx,8), %rcx
	movzbl	%bl, %esi
	btq	%rsi, %rcx
	jae	LBB3_5
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	%r8, %rsi
	imulq	%r8, %rsi
	movq	%rsi, %rcx
	shrq	$32, %rcx
	jne	LBB3_5
## %bb.3:                               ##   in Loop: Header=BB3_1 Depth=1
	leaq	(%r8,%r8), %rdi
LBB3_4:                                 ##   Parent Loop BB3_1 Depth=1
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
	je	LBB3_4
LBB3_5:                                 ##   in Loop: Header=BB3_1 Depth=1
	addq	$2, %r8
	cmpq	$65537, %r8             ## imm = 0x10001
	jb	LBB3_1
## %bb.6:
	movl	$994, -28(%rbp)         ## imm = 0x3E2
	leaq	l___unnamed_1(%rip), %r14
	leaq	_.omp_outlined.(%rip), %r15
	leaq	-28(%rbp), %rbx
LBB3_7:                                 ## =>This Inner Loop Header: Depth=1
	movl	$1, %esi
	xorl	%eax, %eax
	movq	%r14, %rdi
	movq	%r15, %rdx
	movq	%rbx, %rcx
	callq	___kmpc_fork_call
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	cmpl	$65536, %eax            ## imm = 0x10000
	jb	LBB3_7
## %bb.8:
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
                                        ## -- End function
_.omp_outlined.:                        ## @.omp_outlined.
Lfunc_begin0:
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$184, %rsp
	movq	%rdx, %r12
	movl	$0, -48(%rbp)
	movl	$511, -44(%rbp)         ## imm = 0x1FF
	movl	$1, -60(%rbp)
	movl	$0, -56(%rbp)
	movl	(%rdi), %esi
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	l___unnamed_2(%rip), %rdi
	leaq	-56(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-44(%rbp), %r9
	movl	$34, %edx
	movl	%esi, -52(%rbp)         ## 4-byte Spill
	callq	___kmpc_for_static_init_4u
	movl	-44(%rbp), %eax
	cmpl	$511, %eax              ## imm = 0x1FF
	movl	$511, %ecx              ## imm = 0x1FF
	cmovbl	%eax, %ecx
	movl	%ecx, -44(%rbp)
	movl	-48(%rbp), %r15d
	cmpl	%ecx, %r15d
	ja	LBB4_36
## %bb.1:
	leaq	-80(%rbp), %r14
LBB4_2:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB4_4 Depth 2
                                        ##       Child Loop BB4_15 Depth 3
                                        ##       Child Loop BB4_18 Depth 3
                                        ##       Child Loop BB4_28 Depth 3
	xorl	%eax, %eax
	leaq	-192(%rbp), %rbx
	movq	%rbx, %rdi
	leaq	L_.str.1(%rip), %rsi
	movl	%r15d, %edx
	callq	_sprintf
Ltmp0:
	movq	%rbx, %rdi
	leaq	L_.str.2(%rip), %rsi
	callq	_fopen
Ltmp1:
## %bb.3:                               ##   in Loop: Header=BB4_2 Depth=1
	movq	%rax, %r13
	jmp	LBB4_4
LBB4_11:                                ##   in Loop: Header=BB4_4 Depth=2
	movb	$1, %r8b
	cmpl	$4, %eax
	jb	LBB4_13
## %bb.12:                              ##   in Loop: Header=BB4_4 Depth=2
	movl	%eax, %ecx
	shrl	%ecx
	movl	%eax, %edx
	shrl	$4, %edx
	movq	_B(%rip), %rsi
	andl	$-8, %edx
	movq	(%rsi,%rdx), %rdx
	btq	%rcx, %rdx
	setb	%r8b
	jmp	LBB4_13
LBB4_4:                                 ##   Parent Loop BB4_2 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB4_15 Depth 3
                                        ##       Child Loop BB4_18 Depth 3
                                        ##       Child Loop BB4_28 Depth 3
	xorl	%eax, %eax
	movq	%r13, %rdi
	leaq	L_.str.3(%rip), %rsi
	movq	%r14, %rdx
	callq	_fscanf
	cmpl	$-1, %eax
	je	LBB4_34
## %bb.5:                               ##   in Loop: Header=BB4_4 Depth=2
	movq	%r14, %rdi
	callq	_atoi
                                        ## kill: def $eax killed $eax def $rax
	testb	$1, %al
	sete	%cl
	cmpl	$2, %eax
	setne	%dl
	xorl	%edi, %edi
	cmpl	$2, %eax
	jb	LBB4_10
## %bb.6:                               ##   in Loop: Header=BB4_4 Depth=2
	movl	$0, %r8d
	andb	%cl, %dl
	jne	LBB4_13
## %bb.7:                               ##   in Loop: Header=BB4_4 Depth=2
	cmpl	$3, %eax
	je	LBB4_11
## %bb.8:                               ##   in Loop: Header=BB4_4 Depth=2
	movl	%eax, %ecx
	movl	$2863311531, %edx       ## imm = 0xAAAAAAAB
	imulq	%rdx, %rcx
	shrq	$33, %rcx
	leal	(%rcx,%rcx,2), %ecx
	movl	%eax, %edx
	subl	%ecx, %edx
	jne	LBB4_11
LBB4_10:                                ##   in Loop: Header=BB4_4 Depth=2
	xorl	%r8d, %r8d
LBB4_13:                                ##   in Loop: Header=BB4_4 Depth=2
	movl	(%r12), %edx
	leal	-1(%rax), %r9d
	movl	%r9d, %ecx
	testb	$1, %r9b
	jne	LBB4_16
## %bb.14:                              ##   in Loop: Header=BB4_4 Depth=2
	xorl	%edi, %edi
	movl	%r9d, %esi
	movl	%r9d, %ecx
LBB4_15:                                ##   Parent Loop BB4_2 Depth=1
                                        ##     Parent Loop BB4_4 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	addl	$1, %edi
	shrl	%ecx
	testb	$2, %sil
	movl	%ecx, %esi
	je	LBB4_15
LBB4_16:                                ##   in Loop: Header=BB4_4 Depth=2
	testl	%ecx, %ecx
	je	LBB4_33
## %bb.17:                              ##   in Loop: Header=BB4_4 Depth=2
	movl	%ecx, %ebx
	movl	%eax, %r10d
	movl	$1, %ecx
LBB4_18:                                ##   Parent Loop BB4_2 Depth=1
                                        ##     Parent Loop BB4_4 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	%edx, %esi
	testb	$1, %bl
	je	LBB4_21
## %bb.19:                              ##   in Loop: Header=BB4_18 Depth=3
	imulq	%rsi, %rcx
	movq	%rcx, %rax
	shrq	$32, %rax
	je	LBB4_23
## %bb.20:                              ##   in Loop: Header=BB4_18 Depth=3
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r10
	movq	%rdx, %rcx
LBB4_21:                                ##   in Loop: Header=BB4_18 Depth=3
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	je	LBB4_24
LBB4_22:                                ##   in Loop: Header=BB4_18 Depth=3
	xorl	%edx, %edx
	movq	%rsi, %rax
	divq	%r10
	shrq	%rbx
	jne	LBB4_18
	jmp	LBB4_25
LBB4_23:                                ##   in Loop: Header=BB4_18 Depth=3
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r10d
	movl	%edx, %ecx
	imulq	%rsi, %rsi
	movq	%rsi, %rax
	shrq	$32, %rax
	jne	LBB4_22
LBB4_24:                                ##   in Loop: Header=BB4_18 Depth=3
	xorl	%edx, %edx
	movl	%esi, %eax
	divl	%r10d
                                        ## kill: def $edx killed $edx def $rdx
	shrq	%rbx
	jne	LBB4_18
LBB4_25:                                ##   in Loop: Header=BB4_4 Depth=2
	cmpq	$1, %rcx
	je	LBB4_33
## %bb.26:                              ##   in Loop: Header=BB4_4 Depth=2
	testl	%edi, %edi
	je	LBB4_32
## %bb.27:                              ##   in Loop: Header=BB4_4 Depth=2
	movl	%r9d, %esi
	xorl	%ebx, %ebx
LBB4_28:                                ##   Parent Loop BB4_2 Depth=1
                                        ##     Parent Loop BB4_4 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpq	%rsi, %rcx
	je	LBB4_33
## %bb.29:                              ##   in Loop: Header=BB4_28 Depth=3
	imulq	%rcx, %rcx
	movq	%rcx, %rax
	shrq	$32, %rax
	je	LBB4_31
## %bb.30:                              ##   in Loop: Header=BB4_28 Depth=3
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r10
	movq	%rdx, %rcx
	addl	$1, %ebx
	cmpl	%edi, %ebx
	jb	LBB4_28
	jmp	LBB4_32
LBB4_31:                                ##   in Loop: Header=BB4_28 Depth=3
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r10d
	movl	%edx, %ecx
	addl	$1, %ebx
	cmpl	%edi, %ebx
	jb	LBB4_28
LBB4_32:                                ##   in Loop: Header=BB4_4 Depth=2
	testb	%r8b, %r8b
	je	LBB4_4
	jmp	LBB4_35
LBB4_33:                                ##   in Loop: Header=BB4_4 Depth=2
	testb	%r8b, %r8b
	jne	LBB4_4
	jmp	LBB4_35
LBB4_34:                                ##   in Loop: Header=BB4_2 Depth=1
	movl	(%r12), %esi
	xorl	%eax, %eax
	leaq	L_.str.4(%rip), %rdi
	movl	%r15d, %edx
	callq	_printf
LBB4_35:                                ##   in Loop: Header=BB4_2 Depth=1
	movq	%r13, %rdi
	callq	_fclose
	addl	$1, %r15d
	cmpl	-44(%rbp), %r15d
	jbe	LBB4_2
LBB4_36:
	leaq	l___unnamed_2(%rip), %rdi
	movl	-52(%rbp), %esi         ## 4-byte Reload
	callq	___kmpc_for_static_fini
	addq	$184, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB4_37:
Ltmp2:
	movq	%rax, %rdi
	callq	___clang_call_terminate
Lfunc_end0:
GCC_except_table4:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase0-Lttbaseref0
Lttbaseref0:
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp1-Ltmp0            ##   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0     ##     jumps to Ltmp2
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp1-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Lfunc_end0-Ltmp1       ##   Call between Ltmp1 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
Lttbase0:
                                        ## -- End function
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.weak_def_can_be_hidden	___clang_call_terminate
___clang_call_terminate:                ## @__clang_call_terminate
## %bb.0:
	pushq	%rax
	callq	___cxa_begin_catch
	callq	__ZSt9terminatev
                                        ## -- End function
	.weak_def_can_be_hidden	__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev
__ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev: ## @_ZNSt3__16vectorIbNS_9allocatorIbEEED1Ev
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	LBB6_1
## %bb.2:
	popq	%rbp
	jmp	__ZdlPv                 ## TAILCALL
LBB6_1:
	popq	%rbp
	retq
                                        ## -- End function
LCPI7_0:
	.quad	2147483648              ## 0x80000000
	.quad	33554432                ## 0x2000000
__GLOBAL__sub_I_hash4.cpp:              ## @_GLOBAL__sub_I_hash4.cpp
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%rax
	vxorps	%xmm0, %xmm0, %xmm0
	vmovups	%xmm0, _B(%rip)
	movq	$0, _B+16(%rip)
	leaq	_B(%rip), %rbx
	movl	$268435456, %edi        ## imm = 0x10000000
	callq	__Znwm
	movq	%rax, _B(%rip)
	vmovaps	LCPI7_0(%rip), %xmm0    ## xmm0 = [2147483648,33554432]
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
                                        ## -- End function
.zerofill __DATA,__common,_B,24,3
L_.str:                                 ## @.str
	.asciz	";unknown;unknown;0;0;;"

l___unnamed_2:
	.long	0                       ## 0x0
	.long	514                     ## 0x202
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.quad	L_.str

L_.str.1:                               ## @.str.1
	.asciz	"%u.txt"

L_.str.2:                               ## @.str.2
	.asciz	"r"

L_.str.3:                               ## @.str.3
	.asciz	"%s"

L_.str.4:                               ## @.str.4
	.asciz	"%d, %d\n"

l___unnamed_1:
	.long	0                       ## 0x0
	.long	2                       ## 0x2
	.long	0                       ## 0x0
	.long	0                       ## 0x0
	.quad	L_.str

	.quad	__GLOBAL__sub_I_hash4.cpp

