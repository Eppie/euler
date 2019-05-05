__Z4hashj:                              ## @_Z4hashj
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	shrl	$16, %eax
	xorl	%edi, %eax
	imull	$-24773, %eax, %eax     ## imm = 0x9F3B
	andl	$511, %eax              ## imm = 0x1FF
	popq	%rbp
	retq
                                        ## -- End function
LCPI1_0:
	.long	8                       ## 0x8
	.long	9                       ## 0x9
	.long	10                      ## 0xa
	.long	11                      ## 0xb
	.long	12                      ## 0xc
	.long	13                      ## 0xd
	.long	14                      ## 0xe
	.long	15                      ## 0xf
LCPI1_1:
	.long	0                       ## 0x0
	.long	1                       ## 0x1
	.long	2                       ## 0x2
	.long	3                       ## 0x3
	.long	4                       ## 0x4
	.long	5                       ## 0x5
	.long	6                       ## 0x6
	.long	7                       ## 0x7
LCPI1_2:
	.long	0                       ## 0x0
	.long	2                       ## 0x2
	.long	4                       ## 0x4
	.long	6                       ## 0x6
	.long	4                       ## 0x4
	.long	6                       ## 0x6
	.long	6                       ## 0x6
	.long	7                       ## 0x7
LCPI1_3:
	.byte	0                       ## 0x0
	.byte	1                       ## 0x1
	.byte	4                       ## 0x4
	.byte	5                       ## 0x5
	.byte	8                       ## 0x8
	.byte	9                       ## 0x9
	.byte	12                      ## 0xc
	.byte	13                      ## 0xd
	.byte	8                       ## 0x8
	.byte	9                       ## 0x9
	.byte	12                      ## 0xc
	.byte	13                      ## 0xd
	.byte	12                      ## 0xc
	.byte	13                      ## 0xd
	.byte	14                      ## 0xe
	.byte	15                      ## 0xf
	.byte	16                      ## 0x10
	.byte	17                      ## 0x11
	.byte	20                      ## 0x14
	.byte	21                      ## 0x15
	.byte	24                      ## 0x18
	.byte	25                      ## 0x19
	.byte	28                      ## 0x1c
	.byte	29                      ## 0x1d
	.byte	24                      ## 0x18
	.byte	25                      ## 0x19
	.byte	28                      ## 0x1c
	.byte	29                      ## 0x1d
	.byte	28                      ## 0x1c
	.byte	29                      ## 0x1d
	.byte	30                      ## 0x1e
	.byte	31                      ## 0x1f
LCPI1_4:
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
	.short	40763                   ## 0x9f3b
LCPI1_5:
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
	.short	511                     ## 0x1ff
LCPI1_6:
	.long	16                      ## 0x10
LCPI1_7:
	.long	32                      ## 0x20
LCPI1_8:
	.long	48                      ## 0x30
LCPI1_9:
	.long	64                      ## 0x40
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%rbx
	andq	$-32, %rsp
	subq	$64, %rsp
	movq	%rsi, %r14
	movl	$67108864, %edi         ## imm = 0x4000000
	callq	__Znam
	movq	%rax, %rbx
	movq	8(%r14), %rdi
	callq	_atoi
	vmovd	%eax, %xmm0
	vpbroadcastd	%xmm0, %ymm0
	vmovdqa	%ymm0, 32(%rsp)         ## 32-byte Spill
	vmovdqa	LCPI1_0(%rip), %ymm1    ## ymm1 = [8,9,10,11,12,13,14,15]
	vmovdqa	LCPI1_1(%rip), %ymm2    ## ymm2 = [0,1,2,3,4,5,6,7]
	xorl	%eax, %eax
	vmovdqa	LCPI1_2(%rip), %ymm3    ## ymm3 = [0,2,4,6,4,6,6,7]
	vmovdqa	LCPI1_3(%rip), %ymm4    ## ymm4 = [0,1,4,5,8,9,12,13,8,9,12,13,12,13,14,15,16,17,20,21,24,25,28,29,24,25,28,29,28,29,30,31]
	vpbroadcastd	LCPI1_6(%rip), %ymm0 ## ymm0 = [16,16,16,16,16,16,16,16]
	vmovdqa	%ymm0, (%rsp)           ## 32-byte Spill
	vpbroadcastd	LCPI1_7(%rip), %ymm8 ## ymm8 = [32,32,32,32,32,32,32,32]
	vpbroadcastd	LCPI1_8(%rip), %ymm9 ## ymm9 = [48,48,48,48,48,48,48,48]
	vpbroadcastd	LCPI1_9(%rip), %ymm10 ## ymm10 = [64,64,64,64,64,64,64,64]
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	vmovdqa	32(%rsp), %ymm0         ## 32-byte Reload
	vpaddd	%ymm2, %ymm0, %ymm11
	vpaddd	%ymm1, %ymm0, %ymm12
	vextracti128	$1, %ymm12, %xmm0
	vpmovzxdq	%xmm0, %ymm0    ## ymm0 = xmm0[0],zero,xmm0[1],zero,xmm0[2],zero,xmm0[3],zero
	vpmovzxdq	%xmm12, %ymm14  ## ymm14 = xmm12[0],zero,xmm12[1],zero,xmm12[2],zero,xmm12[3],zero
	vextracti128	$1, %ymm11, %xmm5
	vpmovzxdq	%xmm5, %ymm5    ## ymm5 = xmm5[0],zero,xmm5[1],zero,xmm5[2],zero,xmm5[3],zero
	vpmovzxdq	%xmm11, %ymm13  ## ymm13 = xmm11[0],zero,xmm11[1],zero,xmm11[2],zero,xmm11[3],zero
	vpsrlq	$16, %ymm0, %ymm15
	vpxor	%ymm0, %ymm15, %ymm0
	vpsrlq	$16, %ymm14, %ymm15
	vpxor	%ymm14, %ymm15, %ymm14
	vpsrlq	$16, %ymm5, %ymm15
	vpxor	%ymm5, %ymm15, %ymm5
	vpsrlq	$16, %ymm13, %ymm15
	vpxor	%ymm13, %ymm15, %ymm13
	vpermd	%ymm13, %ymm3, %ymm13
	vpermd	%ymm5, %ymm3, %ymm5
	vinserti128	$1, %xmm5, %ymm13, %ymm5
	vpshufb	%ymm4, %ymm5, %ymm5
	vpermq	$232, %ymm5, %ymm5      ## ymm5 = ymm5[0,2,2,3]
	vpermd	%ymm14, %ymm3, %ymm13
	vpermd	%ymm0, %ymm3, %ymm0
	vinserti128	$1, %xmm0, %ymm13, %ymm0
	vpshufb	%ymm4, %ymm0, %ymm0
	vpermq	$232, %ymm0, %ymm0      ## ymm0 = ymm0[0,2,2,3]
	vinserti128	$1, %xmm0, %ymm5, %ymm0
	vmovdqa	LCPI1_4(%rip), %ymm14   ## ymm14 = [40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763,40763]
	vpmullw	%ymm14, %ymm0, %ymm0
	vmovdqa	LCPI1_5(%rip), %ymm15   ## ymm15 = [511,511,511,511,511,511,511,511,511,511,511,511,511,511,511,511]
	vpand	%ymm15, %ymm0, %ymm0
	vmovdqu	%ymm0, (%rbx,%rax,2)
	vmovdqa	(%rsp), %ymm5           ## 32-byte Reload
	vpaddd	%ymm5, %ymm11, %ymm0
	vpaddd	%ymm5, %ymm12, %ymm5
	vextracti128	$1, %ymm5, %xmm6
	vpmovzxdq	%xmm6, %ymm6    ## ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpmovzxdq	%xmm5, %ymm5    ## ymm5 = xmm5[0],zero,xmm5[1],zero,xmm5[2],zero,xmm5[3],zero
	vextracti128	$1, %ymm0, %xmm7
	vpmovzxdq	%xmm7, %ymm7    ## ymm7 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpmovzxdq	%xmm0, %ymm0    ## ymm0 = xmm0[0],zero,xmm0[1],zero,xmm0[2],zero,xmm0[3],zero
	vpsrlq	$16, %ymm6, %ymm13
	vpxor	%ymm6, %ymm13, %ymm6
	vpsrlq	$16, %ymm5, %ymm13
	vpxor	%ymm5, %ymm13, %ymm5
	vpsrlq	$16, %ymm7, %ymm13
	vpxor	%ymm7, %ymm13, %ymm7
	vpsrlq	$16, %ymm0, %ymm13
	vpxor	%ymm0, %ymm13, %ymm0
	vpermd	%ymm0, %ymm3, %ymm0
	vpermd	%ymm7, %ymm3, %ymm7
	vinserti128	$1, %xmm7, %ymm0, %ymm0
	vpshufb	%ymm4, %ymm0, %ymm0
	vpermq	$232, %ymm0, %ymm0      ## ymm0 = ymm0[0,2,2,3]
	vpermd	%ymm5, %ymm3, %ymm5
	vpermd	%ymm6, %ymm3, %ymm6
	vinserti128	$1, %xmm6, %ymm5, %ymm5
	vpshufb	%ymm4, %ymm5, %ymm5
	vpermq	$232, %ymm5, %ymm5      ## ymm5 = ymm5[0,2,2,3]
	vinserti128	$1, %xmm5, %ymm0, %ymm0
	vpmullw	%ymm14, %ymm0, %ymm0
	vpand	%ymm15, %ymm0, %ymm0
	vmovdqu	%ymm0, 32(%rbx,%rax,2)
	vpaddd	%ymm8, %ymm11, %ymm0
	vpaddd	%ymm8, %ymm12, %ymm5
	vextracti128	$1, %ymm5, %xmm6
	vpmovzxdq	%xmm6, %ymm6    ## ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpmovzxdq	%xmm5, %ymm5    ## ymm5 = xmm5[0],zero,xmm5[1],zero,xmm5[2],zero,xmm5[3],zero
	vextracti128	$1, %ymm0, %xmm7
	vpmovzxdq	%xmm7, %ymm7    ## ymm7 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpmovzxdq	%xmm0, %ymm0    ## ymm0 = xmm0[0],zero,xmm0[1],zero,xmm0[2],zero,xmm0[3],zero
	vpsrlq	$16, %ymm6, %ymm13
	vpxor	%ymm6, %ymm13, %ymm6
	vpsrlq	$16, %ymm5, %ymm13
	vpxor	%ymm5, %ymm13, %ymm5
	vpsrlq	$16, %ymm7, %ymm13
	vpxor	%ymm7, %ymm13, %ymm7
	vpsrlq	$16, %ymm0, %ymm13
	vpxor	%ymm0, %ymm13, %ymm0
	vpermd	%ymm0, %ymm3, %ymm0
	vpermd	%ymm7, %ymm3, %ymm7
	vinserti128	$1, %xmm7, %ymm0, %ymm0
	vpshufb	%ymm4, %ymm0, %ymm0
	vpermq	$232, %ymm0, %ymm0      ## ymm0 = ymm0[0,2,2,3]
	vpermd	%ymm5, %ymm3, %ymm5
	vpermd	%ymm6, %ymm3, %ymm6
	vinserti128	$1, %xmm6, %ymm5, %ymm5
	vpshufb	%ymm4, %ymm5, %ymm5
	vpermq	$232, %ymm5, %ymm5      ## ymm5 = ymm5[0,2,2,3]
	vinserti128	$1, %xmm5, %ymm0, %ymm0
	vpmullw	%ymm14, %ymm0, %ymm0
	vpand	%ymm15, %ymm0, %ymm0
	vmovdqu	%ymm0, 64(%rbx,%rax,2)
	vpaddd	%ymm9, %ymm11, %ymm0
	vpaddd	%ymm9, %ymm12, %ymm5
	vextracti128	$1, %ymm5, %xmm6
	vpmovzxdq	%xmm6, %ymm6    ## ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpmovzxdq	%xmm5, %ymm5    ## ymm5 = xmm5[0],zero,xmm5[1],zero,xmm5[2],zero,xmm5[3],zero
	vextracti128	$1, %ymm0, %xmm7
	vpmovzxdq	%xmm7, %ymm7    ## ymm7 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpmovzxdq	%xmm0, %ymm0    ## ymm0 = xmm0[0],zero,xmm0[1],zero,xmm0[2],zero,xmm0[3],zero
	vpsrlq	$16, %ymm6, %ymm11
	vpxor	%ymm6, %ymm11, %ymm6
	vpsrlq	$16, %ymm5, %ymm11
	vpxor	%ymm5, %ymm11, %ymm5
	vpsrlq	$16, %ymm7, %ymm11
	vpxor	%ymm7, %ymm11, %ymm7
	vpsrlq	$16, %ymm0, %ymm11
	vpxor	%ymm0, %ymm11, %ymm0
	vpermd	%ymm0, %ymm3, %ymm0
	vpermd	%ymm7, %ymm3, %ymm7
	vinserti128	$1, %xmm7, %ymm0, %ymm0
	vpermd	%ymm5, %ymm3, %ymm5
	vpermd	%ymm6, %ymm3, %ymm6
	vinserti128	$1, %xmm6, %ymm5, %ymm5
	vpshufb	%ymm4, %ymm0, %ymm0
	vpermq	$232, %ymm0, %ymm0      ## ymm0 = ymm0[0,2,2,3]
	vpshufb	%ymm4, %ymm5, %ymm5
	vpermq	$232, %ymm5, %ymm5      ## ymm5 = ymm5[0,2,2,3]
	vinserti128	$1, %xmm5, %ymm0, %ymm0
	vpmullw	%ymm14, %ymm0, %ymm0
	vpand	%ymm15, %ymm0, %ymm0
	vmovdqu	%ymm0, 96(%rbx,%rax,2)
	addq	$64, %rax
	vpaddd	%ymm10, %ymm2, %ymm2
	vpaddd	%ymm10, %ymm1, %ymm1
	cmpq	$33554432, %rax         ## imm = 0x2000000
	jne	LBB1_1
## %bb.2:
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vpxor	%xmm1, %xmm1, %xmm1
	vpxor	%xmm2, %xmm2, %xmm2
	vpxor	%xmm3, %xmm3, %xmm3
LBB1_3:                                 ## =>This Inner Loop Header: Depth=1
	vpmovzxwq	(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm0, %ymm0
	vpmovzxwq	8(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm1, %ymm1
	vpmovzxwq	16(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	24(%rbx,%rax,2), %ymm5 ## ymm5 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm2, %ymm2
	vpaddq	%ymm5, %ymm3, %ymm3
	vpmovzxwq	32(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	40(%rbx,%rax,2), %ymm5 ## ymm5 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	48(%rbx,%rax,2), %ymm6 ## ymm6 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	56(%rbx,%rax,2), %ymm7 ## ymm7 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	64(%rbx,%rax,2), %ymm8 ## ymm8 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm8, %ymm4, %ymm4
	vpaddq	%ymm4, %ymm0, %ymm0
	vpmovzxwq	72(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm5, %ymm4
	vpaddq	%ymm4, %ymm1, %ymm1
	vpmovzxwq	80(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm6, %ymm4
	vpaddq	%ymm4, %ymm2, %ymm2
	vpmovzxwq	88(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm7, %ymm4
	vpaddq	%ymm4, %ymm3, %ymm3
	vpmovzxwq	96(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm0, %ymm0
	vpmovzxwq	104(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm1, %ymm1
	vpmovzxwq	112(%rbx,%rax,2), %ymm4 ## ymm4 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	120(%rbx,%rax,2), %ymm5 ## ymm5 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpaddq	%ymm4, %ymm2, %ymm2
	vpaddq	%ymm5, %ymm3, %ymm3
	addq	$64, %rax
	cmpq	$33554432, %rax         ## imm = 0x2000000
	jne	LBB1_3
## %bb.4:
	vpaddq	%ymm0, %ymm1, %ymm0
	vpaddq	%ymm0, %ymm2, %ymm0
	vpaddq	%ymm0, %ymm3, %ymm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddq	%ymm1, %ymm0, %ymm0
	vpshufd	$78, %xmm0, %xmm1       ## xmm1 = xmm0[2,3,0,1]
	vpaddq	%ymm1, %ymm0, %ymm0
	vmovq	%xmm0, %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	vzeroupper
	callq	_printf
	xorl	%eax, %eax
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
                                        ## -- End function
L_.str:                                 ## @.str
	.asciz	"%llu\n"


