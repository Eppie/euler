__Z4hashj:                              ## @_Z4hashj
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	shrl	$16, %eax
	xorl	%edi, %eax
	imull	$-6927, %eax, %eax      ## imm = 0xE4F1
	andl	$511, %eax              ## imm = 0x1FF
	popq	%rbp
	retq
                                        ## -- End function
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$4232, %rsp             ## imm = 0x1088
	movl	$2400000000, %edi       ## imm = 0x8F0D1800
	callq	__Znam
	movq	%rax, %r14
	leaq	L_.str(%rip), %r15
	leaq	-176(%rbp), %r13
	leaq	L_.str.1(%rip), %r12
	xorl	%ebx, %ebx
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movq	%r13, %rdi
	movq	%r15, %rsi
	movl	%ebx, %edx
	callq	_sprintf
	movq	%r13, %rdi
	movq	%r12, %rsi
	callq	_fopen
	movq	%rax, -4272(%rbp,%rbx,8)
	addq	$1, %rbx
	cmpq	$512, %rbx              ## imm = 0x200
	jne	LBB1_1
## %bb.2:
	movl	$3, %r10d
	xorl	%r15d, %r15d
	movl	$2924233053, %ecx       ## imm = 0xAE4C415D
	movl	$3352169597, %edx       ## imm = 0xC7CE0C7D
	movl	$3134165325, %esi       ## imm = 0xBACF914D
	movl	$3435973837, %r12d      ## imm = 0xCCCCCCCD
	movl	$2863311531, %r13d      ## imm = 0xAAAAAAAB
LBB1_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	%r10d, %r11d
	imulq	$891408307, %r11, %r9   ## imm = 0x3521CFB3
	shrq	$32, %r9
	movl	%r10d, %r8d
	subl	%r9d, %r8d
	shrl	%r8d
	addl	%r9d, %r8d
	shrl	$5, %r8d
	imull	$-53, %r8d, %ebx
	addl	%r10d, %ebx
	je	LBB1_19
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	imulq	%rcx, %rdi
	shrq	$37, %rdi
	imull	$-47, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=1
	imulq	$799063683, %r11, %rdi  ## imm = 0x2FA0BE83
	shrq	$35, %rdi
	imull	$-43, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.6:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	imulq	%rdx, %rdi
	shrq	$37, %rdi
	imull	$-41, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.7:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	imulq	%rsi, %rdi
	shrq	$32, %rdi
	movl	%r10d, %ebx
	subl	%edi, %ebx
	shrl	%ebx
	addl	%edi, %ebx
	shrl	$5, %ebx
	imull	$-37, %ebx, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.8:                               ##   in Loop: Header=BB1_3 Depth=1
	imulq	$138547333, %r11, %rdi  ## imm = 0x8421085
	shrq	$32, %rdi
	movl	%r10d, %ebx
	subl	%edi, %ebx
	shrl	%ebx
	addl	%edi, %ebx
	shrl	$4, %ebx
	movl	%ebx, %edi
	shll	$5, %edi
	subl	%edi, %ebx
	addl	%r10d, %ebx
	je	LBB1_19
## %bb.9:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	movl	$2369637129, %eax       ## imm = 0x8D3DCB09
	imulq	%rax, %rdi
	shrq	$36, %rdi
	imull	$-29, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.10:                              ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	movl	$2987803337, %eax       ## imm = 0xB21642C9
	imulq	%rax, %rdi
	shrq	$36, %rdi
	imull	$-23, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.11:                              ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	movl	$2938661835, %eax       ## imm = 0xAF286BCB
	imulq	%rax, %rdi
	shrq	$32, %rdi
	movl	%r10d, %ebx
	subl	%edi, %ebx
	shrl	%ebx
	addl	%edi, %ebx
	shrl	$4, %ebx
	imull	$-19, %ebx, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.12:                              ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	movl	$4042322161, %eax       ## imm = 0xF0F0F0F1
	imulq	%rax, %rdi
	shrq	$36, %rdi
	movl	%edi, %ebx
	shll	$4, %ebx
	addl	%edi, %ebx
	movl	%r10d, %edi
	subl	%ebx, %edi
	je	LBB1_19
## %bb.13:                              ##   in Loop: Header=BB1_3 Depth=1
	imulq	$1321528399, %r11, %rdi ## imm = 0x4EC4EC4F
	shrq	$34, %rdi
	imull	$-13, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.14:                              ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rdi
	movl	$3123612579, %eax       ## imm = 0xBA2E8BA3
	imulq	%rax, %rdi
	shrq	$35, %rdi
	imull	$-11, %edi, %edi
	addl	%r10d, %edi
	je	LBB1_19
## %bb.15:                              ##   in Loop: Header=BB1_3 Depth=1
	imulq	$613566757, %r11, %rdi  ## imm = 0x24924925
	shrq	$32, %rdi
	movl	%r10d, %eax
	subl	%edi, %eax
	shrl	%eax
	addl	%edi, %eax
	shrl	$2, %eax
	leal	(,%rax,8), %edi
	subl	%edi, %eax
	addl	%r10d, %eax
	je	LBB1_19
## %bb.16:                              ##   in Loop: Header=BB1_3 Depth=1
	movq	%r11, %rax
	imulq	%r13, %rax
	shrq	$33, %rax
	leal	(%rax,%rax,2), %eax
	movl	%r10d, %edi
	subl	%eax, %edi
	je	LBB1_19
## %bb.17:                              ##   in Loop: Header=BB1_3 Depth=1
	imulq	%r12, %r11
	shrq	$34, %r11
	leal	(%r11,%r11,4), %eax
	movl	%r10d, %edi
	subl	%eax, %edi
	je	LBB1_19
## %bb.18:                              ##   in Loop: Header=BB1_3 Depth=1
	movl	%r15d, %eax
	movl	%r10d, (%r14,%rax,4)
	addl	$1, %r15d
LBB1_19:                                ##   in Loop: Header=BB1_3 Depth=1
	addq	$2, %r10
	movq	%r10, %rax
	shrq	$32, %rax
	je	LBB1_3
## %bb.20:
	movl	$4096, %edi             ## imm = 0x1000
	callq	__Znam
	movq	%rax, %r12
	movl	$2048, %edi             ## imm = 0x800
	callq	__Znam
	movq	%rax, %r13
	xorl	%ebx, %ebx
LBB1_21:                                ## =>This Inner Loop Header: Depth=1
	movl	$8000000, %edi          ## imm = 0x7A1200
	callq	__Znam
	movq	%rax, (%r12,%rbx,8)
	movl	$0, (%r13,%rbx,4)
	addq	$1, %rbx
	cmpq	$512, %rbx              ## imm = 0x200
	jne	LBB1_21
## %bb.22:
	testl	%r15d, %r15d
	je	LBB1_29
## %bb.23:
	movl	%r15d, %ecx
	movl	%ecx, %r8d
	andl	$1, %r8d
	cmpl	$1, %r15d
	jne	LBB1_25
## %bb.24:
	xorl	%edx, %edx
	testq	%r8, %r8
	jne	LBB1_28
	jmp	LBB1_29
LBB1_25:
	subq	%r8, %rcx
	xorl	%edx, %edx
LBB1_26:                                ## =>This Inner Loop Header: Depth=1
	movl	(%r14,%rdx,4), %esi
	movl	%esi, %edi
	shrl	$16, %edi
	xorl	%esi, %edi
	imull	$58609, %edi, %edi      ## imm = 0xE4F1
	andl	$511, %edi              ## imm = 0x1FF
	movq	(%r12,%rdi,8), %rbx
	movl	(%r13,%rdi,4), %eax
	movl	%esi, (%rbx,%rax,4)
	leal	1(%rax), %eax
	movl	%eax, (%r13,%rdi,4)
	movl	4(%r14,%rdx,4), %eax
	movl	%eax, %esi
	shrl	$16, %esi
	xorl	%eax, %esi
	imull	$58609, %esi, %esi      ## imm = 0xE4F1
	andl	$511, %esi              ## imm = 0x1FF
	movq	(%r12,%rsi,8), %rdi
	movl	(%r13,%rsi,4), %ebx
	movl	%eax, (%rdi,%rbx,4)
	leal	1(%rbx), %eax
	movl	%eax, (%r13,%rsi,4)
	addq	$2, %rdx
	cmpq	%rdx, %rcx
	jne	LBB1_26
## %bb.27:
	testq	%r8, %r8
	je	LBB1_29
LBB1_28:
	movl	(%r14,%rdx,4), %eax
	movl	%eax, %ecx
	shrl	$16, %ecx
	xorl	%eax, %ecx
	imull	$58609, %ecx, %ecx      ## imm = 0xE4F1
	andl	$511, %ecx              ## imm = 0x1FF
	movq	(%r12,%rcx,8), %rdx
	movl	(%r13,%rcx,4), %esi
	movl	%eax, (%rdx,%rsi,4)
	leal	1(%rsi), %eax
	movl	%eax, (%r13,%rcx,4)
LBB1_29:
	movq	%r12, -56(%rbp)         ## 8-byte Spill
	leaq	L_.str.2(%rip), %r14
	xorl	%eax, %eax
	movq	%r13, -64(%rbp)         ## 8-byte Spill
LBB1_30:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_32 Depth 2
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	movl	(%r13,%rax,4), %r15d
	testq	%r15, %r15
	je	LBB1_33
## %bb.31:                              ##   in Loop: Header=BB1_30 Depth=1
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	movq	-4272(%rbp,%rcx,8), %rbx
	movq	-56(%rbp), %rax         ## 8-byte Reload
	movq	(%rax,%rcx,8), %r12
	xorl	%r13d, %r13d
LBB1_32:                                ##   Parent Loop BB1_30 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%r12,%r13,4), %edx
	xorl	%eax, %eax
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	_fprintf
	addq	$1, %r13
	cmpq	%r15, %r13
	jb	LBB1_32
LBB1_33:                                ##   in Loop: Header=BB1_30 Depth=1
	movq	-48(%rbp), %rax         ## 8-byte Reload
	addq	$1, %rax
	cmpq	$512, %rax              ## imm = 0x200
	movq	-64(%rbp), %r13         ## 8-byte Reload
	jne	LBB1_30
## %bb.34:
	xorl	%ebx, %ebx
LBB1_35:                                ## =>This Inner Loop Header: Depth=1
	movq	-4272(%rbp,%rbx,8), %rdi
	callq	_fclose
	addq	$1, %rbx
	cmpq	$512, %rbx              ## imm = 0x200
	jne	LBB1_35
## %bb.36:
	xorl	%eax, %eax
	addq	$4232, %rsp             ## imm = 0x1088
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
                                        ## -- End function
L_.str:                                 ## @.str
	.asciz	"%hu.txt"

L_.str.1:                               ## @.str.1
	.asciz	"a"

L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


