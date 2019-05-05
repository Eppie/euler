LCPI0_0:
	.space	16
_main:                                  ## @main
Lfunc_begin0:
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	movl	$1024, %edi             ## imm = 0x400
	callq	__Znam
	movq	%rax, %r14
	movl	$0, -52(%rbp)
	movl	$0, -48(%rbp)
	leaq	-80(%rbp), %rax
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, -80(%rbp)
	movq	%rax, -88(%rbp)
	vmovdqa	%xmm0, -112(%rbp)
	movq	$0, -96(%rbp)
	xorl	%r15d, %r15d
	jmp	LBB0_1
LBB0_27:                                ##   in Loop: Header=BB0_1 Depth=1
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	xorl	%r12d, %r12d
	jmp	LBB0_32
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	leaq	L_.str(%rip), %rdi
	leaq	-52(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	callq	_scanf
	movq	-80(%rbp), %rbx
	testq	%rbx, %rbx
	movl	%r15d, -44(%rbp)        ## 4-byte Spill
	je	LBB0_2
## %bb.7:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax
	leaq	-80(%rbp), %r13
	cmpl	%eax, 32(%rbx)
	jbe	LBB0_15
	jmp	LBB0_9
LBB0_17:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	%rcx, %rbx
	cmpl	%eax, 32(%rbx)
	jbe	LBB0_15
LBB0_9:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	(%rbx), %rcx
	movq	%rbx, %r13
	testq	%rcx, %rcx
	jne	LBB0_17
	jmp	LBB0_10
LBB0_15:                                ##   in Loop: Header=BB0_1 Depth=1
	jae	LBB0_11
## %bb.16:                              ##   in Loop: Header=BB0_1 Depth=1
	leaq	8(%rbx), %r13
	movq	8(%rbx), %rcx
	testq	%rcx, %rcx
	jne	LBB0_17
LBB0_11:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	(%r13), %r15
	testq	%r15, %r15
	je	LBB0_12
LBB0_20:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	48(%r15), %r13
	movq	56(%r15), %rax
	cmpq	%rax, %r13
	je	LBB0_22
LBB0_21:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-48(%rbp), %eax
	movl	%eax, (%r13)
	addq	$4, %r13
	movq	%r13, 48(%r15)
	jmp	LBB0_36
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	leaq	-80(%rbp), %rax
	movq	%rax, %rbx
	movq	%rax, %r13
	movq	(%r13), %r15
	testq	%r15, %r15
	jne	LBB0_20
	jmp	LBB0_12
LBB0_10:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	%rbx, %r13
	movq	(%r13), %r15
	testq	%r15, %r15
	jne	LBB0_20
LBB0_12:                                ##   in Loop: Header=BB0_1 Depth=1
Ltmp0:
	movl	$64, %edi
	callq	__Znwm
Ltmp1:
## %bb.13:                              ##   in Loop: Header=BB0_1 Depth=1
	movq	%rax, %r15
	movl	-52(%rbp), %eax
	movl	%eax, 32(%r15)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 40(%r15)
	movq	$0, 56(%r15)
	vmovdqu	%xmm0, (%r15)
	movq	%rbx, 16(%r15)
	movq	%r15, (%r13)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	LBB0_14
## %bb.18:                              ##   in Loop: Header=BB0_1 Depth=1
	movq	%rax, -88(%rbp)
	movq	(%r13), %rsi
	jmp	LBB0_19
LBB0_14:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	%r15, %rsi
LBB0_19:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-80(%rbp), %rdi
	callq	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	addq	$1, -72(%rbp)
	movq	48(%r15), %r13
	movq	56(%r15), %rax
	cmpq	%rax, %r13
	jne	LBB0_21
LBB0_22:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	40(%r15), %rdi
	movq	(%rdi), %r8
	subq	%r8, %r13
	movq	%r13, %rbx
	sarq	$2, %rbx
	leaq	1(%rbx), %rcx
	cmpq	%r12, %rcx
	ja	LBB0_23
## %bb.25:                              ##   in Loop: Header=BB0_1 Depth=1
	subq	%r8, %rax
	movq	%rax, %rdx
	sarq	$2, %rdx
	movq	%r12, %rdi
	movabsq	$2305843009213693951, %rsi ## imm = 0x1FFFFFFFFFFFFFFF
	cmpq	%rsi, %rdx
	jae	LBB0_30
## %bb.26:                              ##   in Loop: Header=BB0_1 Depth=1
	sarq	%rax
	cmpq	%rcx, %rax
	movq	%rax, %rdi
	cmovbq	%rcx, %rdi
	testq	%rdi, %rdi
	je	LBB0_27
## %bb.28:                              ##   in Loop: Header=BB0_1 Depth=1
	cmpq	%r12, %rdi
	ja	LBB0_29
LBB0_30:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	%r8, -64(%rbp)          ## 8-byte Spill
	movq	%rdi, -120(%rbp)        ## 8-byte Spill
	leaq	(,%rdi,4), %rdi
Ltmp2:
	callq	__Znwm
Ltmp3:
## %bb.31:                              ##   in Loop: Header=BB0_1 Depth=1
	movq	%rax, %r12
	movq	-64(%rbp), %r8          ## 8-byte Reload
	movq	-120(%rbp), %rcx        ## 8-byte Reload
LBB0_32:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	(%r12,%rcx,4), %rdx
	movl	-48(%rbp), %ecx
	movl	%ecx, (%r12,%rbx,4)
	leaq	(%r12,%rbx,4), %rbx
	addq	$4, %rbx
	testq	%r13, %r13
	jle	LBB0_34
## %bb.33:                              ##   in Loop: Header=BB0_1 Depth=1
	movq	%rax, %rdi
	movq	%r8, %rsi
	movq	%rdx, -64(%rbp)         ## 8-byte Spill
	movq	%r13, %rdx
	movq	%r8, %r13
	callq	_memcpy
	movq	-64(%rbp), %rdx         ## 8-byte Reload
	movq	%r13, %r8
LBB0_34:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	%r12, 40(%r15)
	movq	%rbx, 48(%r15)
	movq	%rdx, 56(%r15)
	testq	%r8, %r8
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	je	LBB0_36
## %bb.35:                              ##   in Loop: Header=BB0_1 Depth=1
	movq	%r8, %rdi
	callq	__ZdlPv
LBB0_36:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-44(%rbp), %r15d        ## 4-byte Reload
	addl	$1, %r15d
	cmpl	$448, %r15d             ## imm = 0x1C0
	jb	LBB0_1
## %bb.3:
	movq	-88(%rbp), %r13
	leaq	-80(%rbp), %rax
	cmpq	%rax, %r13
	je	LBB0_43
## %bb.4:
	movl	$256, %ebx              ## imm = 0x100
	jmp	LBB0_5
LBB0_65:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	-112(%rbp), %r9
	subq	%r9, %rbx
	movq	%r12, %rsi
	movq	%rbx, %r12
	sarq	$2, %r12
	leaq	1(%r12), %rcx
	cmpq	%rsi, %rcx
	ja	LBB0_66
## %bb.67:                              ##   in Loop: Header=BB0_5 Depth=1
	subq	%r9, %rax
	movq	%rax, %rdx
	sarq	$2, %rdx
	movq	%rsi, %rdi
	movabsq	$2305843009213693951, %rsi ## imm = 0x1FFFFFFFFFFFFFFF
	cmpq	%rsi, %rdx
	movq	%r9, -64(%rbp)          ## 8-byte Spill
	jae	LBB0_72
## %bb.68:                              ##   in Loop: Header=BB0_5 Depth=1
	sarq	%rax
	cmpq	%rcx, %rax
	movq	%rax, %rdi
	cmovbq	%rcx, %rdi
	testq	%rdi, %rdi
	je	LBB0_69
## %bb.70:                              ##   in Loop: Header=BB0_5 Depth=1
	movabsq	$4611686018427387903, %rax ## imm = 0x3FFFFFFFFFFFFFFF
	cmpq	%rax, %rdi
	ja	LBB0_71
LBB0_72:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	%r10, %r15
	movl	%r8d, -120(%rbp)        ## 4-byte Spill
	movq	%rdi, -160(%rbp)        ## 8-byte Spill
	leaq	(,%rdi,4), %rdi
Ltmp13:
	vzeroupper
	callq	__Znwm
Ltmp14:
## %bb.73:                              ##   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %r15
	movl	-120(%rbp), %r8d        ## 4-byte Reload
	movq	-64(%rbp), %r9          ## 8-byte Reload
	movq	-160(%rbp), %rcx        ## 8-byte Reload
LBB0_74:                                ##   in Loop: Header=BB0_5 Depth=1
	leaq	(%r15,%rcx,4), %rcx
	movl	%r8d, (%r15,%r12,4)
	leaq	(%r15,%r12,4), %r12
	addq	$4, %r12
	testq	%rbx, %rbx
	jle	LBB0_76
## %bb.75:                              ##   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %rdi
	movq	%r9, %rsi
	movq	%rbx, %rdx
	movq	%rcx, %rbx
	vzeroupper
	callq	_memcpy
	movq	%rbx, %rcx
	movq	-64(%rbp), %r9          ## 8-byte Reload
LBB0_76:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	%r15, -112(%rbp)
	movq	%r12, -104(%rbp)
	movq	%rcx, -96(%rbp)
	testq	%r9, %r9
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	je	LBB0_78
## %bb.77:                              ##   in Loop: Header=BB0_5 Depth=1
	movq	%r9, %rdi
	vzeroupper
	callq	__ZdlPv
LBB0_78:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	-152(%rbp), %esi
	xorl	%eax, %eax
	leaq	L_.str.1(%rip), %rdi
	vzeroupper
	callq	_printf
	movl	-44(%rbp), %ebx         ## 4-byte Reload
	movq	-144(%rbp), %rdi
	testq	%rdi, %rdi
	jne	LBB0_85
	jmp	LBB0_86
LBB0_69:                                ##   in Loop: Header=BB0_5 Depth=1
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	xorl	%r15d, %r15d
	jmp	LBB0_74
LBB0_5:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_58 Depth 2
                                        ##     Child Loop BB0_64 Depth 2
                                        ##     Child Loop BB0_90 Depth 2
                                        ##     Child Loop BB0_89 Depth 2
	movl	%ebx, %r15d
	movl	32(%r13), %r8d
	movl	%r8d, -152(%rbp)
	leaq	-144(%rbp), %rax
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, (%rax)
	movq	$0, 16(%rax)
	movq	48(%r13), %rdi
	subq	40(%r13), %rdi
	je	LBB0_6
## %bb.46:                              ##   in Loop: Header=BB0_5 Depth=1
	movq	%r12, %rax
	movq	%rdi, %rbx
	sarq	$2, %rbx
	cmpq	%r12, %rbx
	ja	LBB0_47
## %bb.48:                              ##   in Loop: Header=BB0_5 Depth=1
	movl	%r8d, %r12d
Ltmp7:
	callq	__Znwm
Ltmp8:
## %bb.49:                              ##   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %r10
	movq	%rax, -136(%rbp)
	movq	%rax, -144(%rbp)
	leaq	(%rax,%rbx,4), %rax
	movq	%rax, -128(%rbp)
	movq	40(%r13), %rsi
	movq	48(%r13), %rbx
	subq	%rsi, %rbx
	testq	%rbx, %rbx
	jle	LBB0_50
## %bb.53:                              ##   in Loop: Header=BB0_5 Depth=1
	movl	%r15d, -44(%rbp)        ## 4-byte Spill
	movq	%r10, %r15
	movq	%r10, %rdi
	movq	%rbx, %rdx
	callq	_memcpy
	movq	%r15, %r10
	movq	%r15, %rax
	addq	%rbx, %rax
	movq	%rax, -136(%rbp)
	testq	%rbx, %rbx
	je	LBB0_54
## %bb.55:                              ##   in Loop: Header=BB0_5 Depth=1
	addq	$-4, %rbx
	movl	%ebx, %edx
	shrl	$2, %edx
	addl	$1, %edx
	andq	$7, %rdx
	movl	%r12d, %r8d
	movl	-44(%rbp), %r15d        ## 4-byte Reload
	je	LBB0_56
## %bb.57:                              ##   in Loop: Header=BB0_5 Depth=1
	negq	%rdx
	movq	%r10, %rcx
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
LBB0_58:                                ##   Parent Loop BB0_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%rcx), %esi
	addl	$1, (%r14,%rsi,4)
	addq	$4, %rcx
	addq	$1, %rdx
	jne	LBB0_58
## %bb.59:                              ##   in Loop: Header=BB0_5 Depth=1
	cmpq	$28, %rbx
	jae	LBB0_64
	jmp	LBB0_60
LBB0_6:                                 ##   in Loop: Header=BB0_5 Depth=1
	xorl	%r10d, %r10d
	jmp	LBB0_60
LBB0_50:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	%r12d, %r8d
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	jmp	LBB0_60
LBB0_54:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	%r12d, %r8d
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	movl	-44(%rbp), %r15d        ## 4-byte Reload
	jmp	LBB0_60
LBB0_56:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	%r10, %rcx
	movabsq	$4611686018427387903, %r12 ## imm = 0x3FFFFFFFFFFFFFFF
	cmpq	$28, %rbx
	jb	LBB0_60
LBB0_64:                                ##   Parent Loop BB0_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	4(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	8(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	12(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	16(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	20(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	24(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	movl	28(%rcx), %edx
	addl	$1, (%r14,%rdx,4)
	addq	$32, %rcx
	cmpq	%rax, %rcx
	jne	LBB0_64
LBB0_60:                                ##   in Loop: Header=BB0_5 Depth=1
	vpxor	%xmm6, %xmm6, %xmm6
	vpcmpeqd	(%r14), %ymm6, %ymm0
	vpsrld	$31, %ymm0, %ymm0
	vpcmpeqd	32(%r14), %ymm6, %ymm1
	vpsrld	$31, %ymm1, %ymm1
	vpcmpeqd	64(%r14), %ymm6, %ymm2
	vpcmpeqd	96(%r14), %ymm6, %ymm3
	vpsrld	$31, %ymm2, %ymm2
	vpsrld	$31, %ymm3, %ymm3
	vpcmpeqd	128(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	160(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	192(%r14), %ymm6, %ymm4
	vpcmpeqd	224(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	256(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	288(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	320(%r14), %ymm6, %ymm4
	vpcmpeqd	352(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	384(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	416(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	448(%r14), %ymm6, %ymm4
	vpcmpeqd	480(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	512(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	544(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	576(%r14), %ymm6, %ymm4
	vpcmpeqd	608(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	640(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	672(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	704(%r14), %ymm6, %ymm4
	vpcmpeqd	736(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	768(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	800(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpcmpeqd	832(%r14), %ymm6, %ymm4
	vpcmpeqd	864(%r14), %ymm6, %ymm5
	vpsubd	%ymm4, %ymm2, %ymm2
	vpsubd	%ymm5, %ymm3, %ymm3
	vpcmpeqd	896(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm0, %ymm0
	vpcmpeqd	928(%r14), %ymm6, %ymm4
	vpsubd	%ymm4, %ymm1, %ymm1
	vpaddd	%ymm0, %ymm1, %ymm0
	vpcmpeqd	960(%r14), %ymm6, %ymm1
	vpsubd	%ymm1, %ymm2, %ymm1
	vpcmpeqd	992(%r14), %ymm6, %ymm2
	vpsubd	%ymm2, %ymm3, %ymm2
	vpaddd	%ymm2, %ymm1, %ymm1
	vpaddd	%ymm1, %ymm0, %ymm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddd	%ymm1, %ymm0, %ymm0
	vpshufd	$78, %xmm0, %xmm1       ## xmm1 = xmm0[2,3,0,1]
	vpaddd	%ymm1, %ymm0, %ymm0
	vphaddd	%ymm0, %ymm0, %ymm0
	vmovd	%xmm0, %ebx
	cmpl	%r15d, %ebx
	jae	LBB0_83
## %bb.61:                              ##   in Loop: Header=BB0_5 Depth=1
	movl	%ebx, -44(%rbp)         ## 4-byte Spill
	movq	-104(%rbp), %rbx
	movq	-96(%rbp), %rax
	cmpq	%rax, %rbx
	je	LBB0_65
## %bb.62:                              ##   in Loop: Header=BB0_5 Depth=1
	movl	%r8d, (%rbx)
	addq	$4, %rbx
	movq	%rbx, -104(%rbp)
	jmp	LBB0_78
LBB0_83:                                ##   in Loop: Header=BB0_5 Depth=1
	xorl	%eax, %eax
	leaq	L_.str.2(%rip), %rdi
	movl	%r8d, %esi
	vzeroupper
	callq	_printf
	movq	-144(%rbp), %rdi
	testq	%rdi, %rdi
	je	LBB0_86
LBB0_85:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	%rdi, -136(%rbp)
	callq	__ZdlPv
LBB0_86:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	8(%r13), %rcx
	testq	%rcx, %rcx
	je	LBB0_87
LBB0_90:                                ##   Parent Loop BB0_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	%rcx, %rax
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	jne	LBB0_90
	jmp	LBB0_91
LBB0_87:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	16(%r13), %rax
	cmpq	%r13, (%rax)
	je	LBB0_91
## %bb.88:                              ##   in Loop: Header=BB0_5 Depth=1
	addq	$16, %r13
LBB0_89:                                ##   Parent Loop BB0_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	(%r13), %rcx
	movq	16(%rcx), %rax
	leaq	16(%rcx), %r13
	cmpq	%rcx, (%rax)
	jne	LBB0_89
LBB0_91:                                ##   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %r13
	leaq	-80(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_5
LBB0_43:
	movq	-112(%rbp), %rdi
	testq	%rdi, %rdi
	je	LBB0_45
## %bb.44:
	movq	%rdi, -104(%rbp)
	callq	__ZdlPv
LBB0_45:
	movq	-80(%rbp), %rsi
	leaq	-88(%rbp), %rdi
	callq	__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
	xorl	%eax, %eax
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB0_47:
Ltmp10:
	leaq	-144(%rbp), %rdi
	callq	__ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
Ltmp11:
	jmp	LBB0_24
LBB0_23:
Ltmp21:
	callq	__ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
Ltmp22:
	jmp	LBB0_24
LBB0_29:
Ltmp5:
	callq	__ZNSt3__1L20__throw_length_errorEPKc
Ltmp6:
	jmp	LBB0_24
LBB0_66:
Ltmp18:
	leaq	-112(%rbp), %rdi
	vzeroupper
	callq	__ZNKSt3__120__vector_base_commonILb1EE20__throw_length_errorEv
Ltmp19:
	jmp	LBB0_24
LBB0_71:
Ltmp16:
	vzeroupper
	callq	__ZNSt3__1L20__throw_length_errorEPKc
Ltmp17:
LBB0_24:
	ud2
LBB0_80:
Ltmp20:
	movq	%rax, %rbx
	movq	-144(%rbp), %r15
	testq	%r15, %r15
	jne	LBB0_82
	jmp	LBB0_40
LBB0_51:
Ltmp12:
	movq	%rax, %rbx
	movq	-144(%rbp), %rdi
	testq	%rdi, %rdi
	je	LBB0_40
## %bb.52:
	movq	%rdi, -136(%rbp)
	callq	__ZdlPv
	movq	-112(%rbp), %rdi
	testq	%rdi, %rdi
	jne	LBB0_41
	jmp	LBB0_42
LBB0_38:
Ltmp23:
	jmp	LBB0_39
LBB0_79:
Ltmp15:
	movq	%rax, %rbx
	testq	%r15, %r15
	je	LBB0_40
LBB0_82:
	movq	%r15, %rdi
	movq	%r15, -136(%rbp)
	callq	__ZdlPv
	movq	-112(%rbp), %rdi
	testq	%rdi, %rdi
	jne	LBB0_41
	jmp	LBB0_42
LBB0_63:
Ltmp9:
	jmp	LBB0_39
LBB0_37:
Ltmp4:
LBB0_39:
	movq	%rax, %rbx
LBB0_40:
	movq	-112(%rbp), %rdi
	testq	%rdi, %rdi
	je	LBB0_42
LBB0_41:
	movq	%rdi, -104(%rbp)
	callq	__ZdlPv
LBB0_42:
	movq	-80(%rbp), %rsi
	leaq	-88(%rbp), %rdi
	callq	__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
	movq	%rbx, %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end0:
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp3-Ltmp0            ##   Call between Ltmp0 and Ltmp3
	.uleb128 Ltmp4-Lfunc_begin0     ##     jumps to Ltmp4
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp3-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Ltmp13-Ltmp3           ##   Call between Ltmp3 and Ltmp13
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp13-Lfunc_begin0    ## >> Call Site 4 <<
	.uleb128 Ltmp14-Ltmp13          ##   Call between Ltmp13 and Ltmp14
	.uleb128 Ltmp15-Lfunc_begin0    ##     jumps to Ltmp15
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp14-Lfunc_begin0    ## >> Call Site 5 <<
	.uleb128 Ltmp7-Ltmp14           ##   Call between Ltmp14 and Ltmp7
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp7-Lfunc_begin0     ## >> Call Site 6 <<
	.uleb128 Ltmp8-Ltmp7            ##   Call between Ltmp7 and Ltmp8
	.uleb128 Ltmp9-Lfunc_begin0     ##     jumps to Ltmp9
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp8-Lfunc_begin0     ## >> Call Site 7 <<
	.uleb128 Ltmp10-Ltmp8           ##   Call between Ltmp8 and Ltmp10
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp10-Lfunc_begin0    ## >> Call Site 8 <<
	.uleb128 Ltmp11-Ltmp10          ##   Call between Ltmp10 and Ltmp11
	.uleb128 Ltmp12-Lfunc_begin0    ##     jumps to Ltmp12
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp21-Lfunc_begin0    ## >> Call Site 9 <<
	.uleb128 Ltmp6-Ltmp21           ##   Call between Ltmp21 and Ltmp6
	.uleb128 Ltmp23-Lfunc_begin0    ##     jumps to Ltmp23
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp18-Lfunc_begin0    ## >> Call Site 10 <<
	.uleb128 Ltmp17-Ltmp18          ##   Call between Ltmp18 and Ltmp17
	.uleb128 Ltmp20-Lfunc_begin0    ##     jumps to Ltmp20
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp17-Lfunc_begin0    ## >> Call Site 11 <<
	.uleb128 Lfunc_end0-Ltmp17      ##   Call between Ltmp17 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
                                        ## -- End function
__ZNSt3__1L20__throw_length_errorEPKc:  ## @_ZNSt3__1L20__throw_length_errorEPKc
Lfunc_begin1:
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%rbx
	movl	$16, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rbx
Ltmp24:
	movq	%rax, %rdi
	callq	__ZNSt12length_errorC1EPKc
Ltmp25:
## %bb.1:
	movq	__ZTISt12length_error@GOTPCREL(%rip), %rsi
	movq	__ZNSt12length_errorD1Ev@GOTPCREL(%rip), %rdx
	movq	%rbx, %rdi
	callq	___cxa_throw
LBB1_2:
Ltmp26:
	movq	%rax, %r14
	movq	%rbx, %rdi
	callq	___cxa_free_exception
	movq	%r14, %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end1:
GCC_except_table1:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end1-Lcst_begin1
Lcst_begin1:
	.uleb128 Lfunc_begin1-Lfunc_begin1 ## >> Call Site 1 <<
	.uleb128 Ltmp24-Lfunc_begin1    ##   Call between Lfunc_begin1 and Ltmp24
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp24-Lfunc_begin1    ## >> Call Site 2 <<
	.uleb128 Ltmp25-Ltmp24          ##   Call between Ltmp24 and Ltmp25
	.uleb128 Ltmp26-Lfunc_begin1    ##     jumps to Ltmp26
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp25-Lfunc_begin1    ## >> Call Site 3 <<
	.uleb128 Lfunc_end1-Ltmp25      ##   Call between Ltmp25 and Lfunc_end1
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end1:
                                        ## -- End function
__ZNSt12length_errorC1EPKc:             ## @_ZNSt12length_errorC1EPKc
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%rax
	movq	%rdi, %rbx
	leaq	L_.str.3(%rip), %rsi
	callq	__ZNSt11logic_errorC2EPKc
	movq	__ZTVSt12length_error@GOTPCREL(%rip), %rax
	addq	$16, %rax
	movq	%rax, (%rbx)
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
                                        ## -- End function
	.weak_def_can_be_hidden	__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE: ## @_ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
## %bb.0:
	testq	%rsi, %rsi
	je	LBB3_4
## %bb.1:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%rbx
	movq	%rsi, %rbx
	movq	%rdi, %r14
	movq	(%rsi), %rsi
	callq	__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
	movq	8(%rbx), %rsi
	movq	%r14, %rdi
	callq	__ZNSt3__16__treeINS_12__value_typeIjNS_6vectorIjNS_9allocatorIjEEEEEENS_19__map_value_compareIjS6_NS_4lessIjEELb1EEENS3_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE
	movq	40(%rbx), %rdi
	testq	%rdi, %rdi
	je	LBB3_3
## %bb.2:
	movq	%rdi, 48(%rbx)
	callq	__ZdlPv
LBB3_3:
	movq	%rbx, %rdi
	popq	%rbx
	popq	%r14
	popq	%rbp
	jmp	__ZdlPv                 ## TAILCALL
LBB3_4:
	retq
                                        ## -- End function
	.weak_def_can_be_hidden	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_: ## @_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	cmpq	%rdi, %rsi
	sete	24(%rsi)
	je	LBB4_23
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	16(%rsi), %rdx
	cmpb	$0, 24(%rdx)
	jne	LBB4_23
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	leaq	24(%rdx), %r8
	movq	16(%rdx), %rax
	movq	(%rax), %rcx
	cmpq	%rdx, %rcx
	je	LBB4_3
## %bb.13:                              ##   in Loop: Header=BB4_1 Depth=1
	testq	%rcx, %rcx
	je	LBB4_15
## %bb.14:                              ##   in Loop: Header=BB4_1 Depth=1
	cmpb	$0, 24(%rcx)
	je	LBB4_5
	jmp	LBB4_15
LBB4_3:                                 ##   in Loop: Header=BB4_1 Depth=1
	movq	8(%rax), %rcx
	testq	%rcx, %rcx
	je	LBB4_6
## %bb.4:                               ##   in Loop: Header=BB4_1 Depth=1
	cmpb	$0, 24(%rcx)
	jne	LBB4_6
LBB4_5:                                 ##   in Loop: Header=BB4_1 Depth=1
	addq	$24, %rcx
	movb	$1, (%r8)
	movq	%rax, %rsi
	cmpq	%rdi, %rax
	sete	24(%rax)
	movb	$1, (%rcx)
	jne	LBB4_1
LBB4_23:
	popq	%rbp
	retq
LBB4_15:
	cmpq	%rsi, (%rdx)
	jne	LBB4_19
## %bb.16:
	movq	8(%rsi), %rcx
	movq	%rcx, (%rdx)
	testq	%rcx, %rcx
	je	LBB4_18
## %bb.17:
	movq	%rdx, 16(%rcx)
	movq	16(%rdx), %rax
LBB4_18:
	movq	%rax, 16(%rsi)
	movq	16(%rdx), %rax
	xorl	%ecx, %ecx
	cmpq	%rdx, (%rax)
	setne	%cl
	movq	%rsi, (%rax,%rcx,8)
	movq	%rdx, 8(%rsi)
	movq	%rsi, 16(%rdx)
	movq	16(%rsi), %rax
	addq	$24, %rsi
	movq	%rsi, %r8
LBB4_19:
	movb	$1, (%r8)
	movb	$0, 24(%rax)
	movq	8(%rax), %rcx
	movq	(%rcx), %rdx
	movq	%rdx, 8(%rax)
	testq	%rdx, %rdx
	je	LBB4_21
## %bb.20:
	movq	%rax, 16(%rdx)
LBB4_21:
	movq	16(%rax), %rdx
	movq	%rdx, 16(%rcx)
	movq	16(%rax), %rdx
	xorl	%esi, %esi
	cmpq	%rax, (%rdx)
	setne	%sil
	movq	%rcx, (%rdx,%rsi,8)
	movq	%rax, (%rcx)
	movq	%rcx, 16(%rax)
	popq	%rbp
	retq
LBB4_6:
	cmpq	%rsi, (%rdx)
	je	LBB4_10
## %bb.7:
	movq	8(%rdx), %r8
	movq	(%r8), %rcx
	movq	%rcx, 8(%rdx)
	testq	%rcx, %rcx
	je	LBB4_9
## %bb.8:
	movq	%rdx, 16(%rcx)
	movq	16(%rdx), %rax
LBB4_9:
	movq	%rax, 16(%r8)
	movq	16(%rdx), %rax
	xorl	%ecx, %ecx
	cmpq	%rdx, (%rax)
	setne	%cl
	movq	%r8, (%rax,%rcx,8)
	movq	%rdx, (%r8)
	movq	%r8, 16(%rdx)
	movq	16(%r8), %rax
	addq	$24, %r8
LBB4_10:
	movb	$1, (%r8)
	movb	$0, 24(%rax)
	movq	(%rax), %rcx
	movq	8(%rcx), %rdx
	movq	%rdx, (%rax)
	testq	%rdx, %rdx
	je	LBB4_12
## %bb.11:
	movq	%rax, 16(%rdx)
LBB4_12:
	movq	16(%rax), %rdx
	movq	%rdx, 16(%rcx)
	movq	16(%rax), %rdx
	xorl	%esi, %esi
	cmpq	%rax, (%rdx)
	setne	%sil
	movq	%rcx, (%rdx,%rsi,8)
	movq	%rax, 8(%rcx)
	movq	%rcx, 16(%rax)
	popq	%rbp
	retq
                                        ## -- End function
L_.str:                                 ## @.str
	.asciz	"%d, %d"

L_.str.1:                               ## @.str.1
	.asciz	"Added: %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"Skipped: %d\n"

L_.str.3:                               ## @.str.3
	.asciz	"allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"


