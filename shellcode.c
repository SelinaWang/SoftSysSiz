#include <stdio.h>

void main() {
   char *name[2];

   name[0] = "/bin/sh";
   name[1] = NULL;
   execve(name[0], name, NULL);
}


// Dump of assembler code for function main:
//    0x00000000004009ae <+0>:	push   %rbp
//    0x00000000004009af <+1>:	mov    %rsp,%rbp
//    0x00000000004009b2 <+4>:	sub    $0x20,%rsp
//    0x00000000004009b6 <+8>:	mov    %fs:0x28,%rax
//    0x00000000004009bf <+17>:	mov    %rax,-0x8(%rbp)
//    0x00000000004009c3 <+21>:	xor    %eax,%eax
// copying the value 0x4a0f24 (the address of the string "/bin/sh")
// into the first pointer of name[]. This is equivalent to: name[0] = "/bin/sh"
//    0x00000000004009c5 <+23>:	movq   $0x4a0f24,-0x20(%rbp)
// copy the value 0x0 (NULL) into the seconds pointer of name[].
// This is equivalent to: name[1] = NULL
//    0x00000000004009cd <+31>:	movq   $0x0,-0x18(%rbp)
// push the arguments to execve() in reverse order onto the stack.
// start with NULL.
//    0x00000000004009d5 <+39>:	mov    -0x20(%rbp),%rax
// load the address of name[] into the RAX register.
//    0x00000000004009d9 <+43>:	lea    -0x20(%rbp),%rcx
//    0x00000000004009dd <+47>:	mov    $0x0,%edx
//    0x00000000004009e2 <+52>:	mov    %rcx,%rsi
//    0x00000000004009e5 <+55>:	mov    %rax,%rdi
//    0x00000000004009e8 <+58>:	callq  0x43e870 <execve>
//    0x00000000004009ed <+63>:	nop
//    0x00000000004009ee <+64>:	mov    -0x8(%rbp),%rax
//    0x00000000004009f2 <+68>:	xor    %fs:0x28,%rax
//    0x00000000004009fb <+77>:	je     0x400a02 <main+84>
//    0x00000000004009fd <+79>:	callq  0x442b20 <__stack_chk_fail>
//    0x0000000000400a02 <+84>:	leaveq
//    0x0000000000400a03 <+85>:	retq
// End of assembler dump.


// Dump of assembler code for function execve:
// Copy 0x3b onto the stack. This is the index into the
// syscall table.
//    0x000000000043e870 <+0>:	mov    $0x3b,%eax
//    0x000000000043e875 <+5>:	syscall
//    0x000000000043e877 <+7>:	cmp    $0xfffffffffffff001,%rax
//    0x000000000043e87d <+13>:	jae    0x4441c0 <__syscall_error>
//    0x000000000043e883 <+19>:	retq
// End of assembler dump.


// if the execve() call fails for some reason?  The program will
// continue fetching instructions from the stack, which may contain random data!
// The program will most likely core dump.
// We want the program to exit cleanly if the execve syscall fails. (exit.c)
