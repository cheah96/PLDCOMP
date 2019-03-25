   .text 
	.globl	main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $152,   %rsp

	movq  $2,-24(%rbp)
	movq  $3,-32(%rbp)
	movq  -24(%rbp), %rax
	addq  -32(%rbp), %rax
	movq  %rax, -40(%rbp)
	movq  $-8,-48(%rbp)
	movq  %rbp, %rax
	addq  -48(%rbp), %rax
	movq  %rax, -48(%rbp)
	movq  -48(%rbp), %rax
	movq  -40(%rbp), %r10
	movq  %r10, (%rax)
	movq  $1,-56(%rbp)
	movq  -56(%rbp), %rax
	addq  -8(%rbp), %rax
	movq  %rax, -64(%rbp)
	movq  $-16,-72(%rbp)
	movq  %rbp, %rax
	addq  -72(%rbp), %rax
	movq  %rax, -72(%rbp)
	movq  -72(%rbp), %rax
	movq  -64(%rbp), %r10
	movq  %r10, (%rax)
	movq  -16(%rbp), %rax
	addq  -8(%rbp), %rax
	movq  %rax, -80(%rbp)
	movq  $-16,-88(%rbp)
	movq  %rbp, %rax
	addq  -88(%rbp), %rax
	movq  %rax, -88(%rbp)
	movq  -88(%rbp), %rax
	movq  -80(%rbp), %r10
	movq  %r10, (%rax)
	movq  $3,-96(%rbp)
	movq  -8(%rbp), %rax
	addq  -96(%rbp), %rax
	movq  %rax, -104(%rbp)
	movq  -16(%rbp), %rax
	imulq  -104(%rbp), %rax
	movq  %rax, -112(%rbp)
	movq  $-16,-120(%rbp)
	movq  %rbp, %rax
	addq  -120(%rbp), %rax
	movq  %rax, -120(%rbp)
	movq  -120(%rbp), %rax
	movq  -112(%rbp), %r10
	movq  %r10, (%rax)
	movb  $90,-121(%rbp)
	movl	-121(%rbp), %edi
	call putchar
	movb  $104,-122(%rbp)
	movl	-122(%rbp), %edi
	call putchar
	movb  $101,-123(%rbp)
	movl	-123(%rbp), %edi
	call putchar
	movb  $110,-124(%rbp)
	movl	-124(%rbp), %edi
	call putchar
	movb  $121,-125(%rbp)
	movl	-125(%rbp), %edi
	call putchar
	movb  $117,-126(%rbp)
	movl	-126(%rbp), %edi
	call putchar
	movb  $32,-127(%rbp)
	movl	-127(%rbp), %edi
	call putchar
	movb  $8,-128(%rbp)
	movl	-128(%rbp), %edi
	call putchar
	movb  $98,-129(%rbp)
	movl	-129(%rbp), %edi
	call putchar
	movb  $101,-130(%rbp)
	movl	-130(%rbp), %edi
	call putchar
	movb  $97,-131(%rbp)
	movl	-131(%rbp), %edi
	call putchar
	movb  $117,-132(%rbp)
	movl	-132(%rbp), %edi
	call putchar
	movb  $32,-133(%rbp)
	movl	-133(%rbp), %edi
	call putchar
	movb  $33,-135(%rbp)
	movq  $-134,-143(%rbp)
	movq  %rbp, %rax
	addq  -143(%rbp), %rax
	movq  %rax, -143(%rbp)
	movq  -143(%rbp), %rax
	movb  -135(%rbp), %dl
	movb  %dl, (%rax)
	movl	-134(%rbp), %edi
	call putchar
	movb  $10,-144(%rbp)
	movl	-144(%rbp), %edi
	call putchar
	movl  -16(%rbp),%eax

    addq    $152,   %rsp
    popq   %rbp
    retq
