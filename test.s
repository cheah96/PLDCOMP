   .text 
	.globl	main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $184,   %rsp

	movq  $2,-16(%rbp)
	movq  $3,-24(%rbp)
	movq  -16(%rbp), %rax
	addq  -24(%rbp), %rax
	movq  %rax, -32(%rbp)
	movq  $-8,-40(%rbp)
	movq  %rbp, %rax
	addq  -40(%rbp), %rax
	movq  %rax, -40(%rbp)
	movq  -40(%rbp), %rax
	movq  -32(%rbp), %r10
	movq  %r10, (%rax)
	movq  $1,-56(%rbp)
	movq  $8,-64(%rbp)
	movq  -56(%rbp), %rax
	addq  -64(%rbp), %rax
	movq  %rax, -72(%rbp)
	movq  $-48,-80(%rbp)
	movq  %rbp, %rax
	addq  -80(%rbp), %rax
	movq  %rax, -80(%rbp)
	movq  -80(%rbp), %rax
	movq  -72(%rbp), %r10
	movq  %r10, (%rax)
	movq  -8(%rbp), %rax
	addq  -48(%rbp), %rax
	movq  %rax, -96(%rbp)
	movq  $-88,-104(%rbp)
	movq  %rbp, %rax
	addq  -104(%rbp), %rax
	movq  %rax, -104(%rbp)
	movq  -104(%rbp), %rax
	movq  -96(%rbp), %r10
	movq  %r10, (%rax)
	movq  $2,-112(%rbp)
	movq  -88(%rbp), %rax
	addq  -112(%rbp), %rax
	movq  %rax, -120(%rbp)
	movq  $-88,-128(%rbp)
	movq  %rbp, %rax
	addq  -128(%rbp), %rax
	movq  %rax, -128(%rbp)
	movq  -128(%rbp), %rax
	movq  -120(%rbp), %r10
	movq  %r10, (%rax)
	movq  -48(%rbp), %rax
	addq  -8(%rbp), %rax
	movq  %rax, -136(%rbp)
	movq  $-48,-144(%rbp)
	movq  %rbp, %rax
	addq  -144(%rbp), %rax
	movq  %rax, -144(%rbp)
	movq  -144(%rbp), %rax
	movq  -136(%rbp), %r10
	movq  %r10, (%rax)
	movq  -48(%rbp), %rax
	addq  -88(%rbp), %rax
	movq  %rax, -152(%rbp)
	movq  $-8,-160(%rbp)
	movq  %rbp, %rax
	addq  -160(%rbp), %rax
	movq  %rax, -160(%rbp)
	movq  -160(%rbp), %rax
	movq  -152(%rbp), %r10
	movq  %r10, (%rax)
	movq  $3,-168(%rbp)
	movq  -8(%rbp), %rax
	addq  -168(%rbp), %rax
	movq  %rax, -176(%rbp)
	movl  -176(%rbp),%eax

    addq    $184,   %rsp
    popq   %rbp
    retq
