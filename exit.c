#include <stdlib.h>

void main() {
        exit(0);
}

// (gdb) disassemble _exit
// Dump of assembler code for function _exit:
//    0x000000000043e7c0 <+0>:	movslq %edi,%rdx
//    0x000000000043e7c3 <+3>:	mov    $0xffffffffffffffd0,%r9
//    0x000000000043e7ca <+10>:	mov    $0xe7,%r8d
//    0x000000000043e7d0 <+16>:	mov    $0x3c,%esi
//    0x000000000043e7d5 <+21>:	jmp    0x43e7f0 <_exit+48>
//    0x000000000043e7d7 <+23>:	nopw   0x0(%rax,%rax,1)
//    0x000000000043e7e0 <+32>:	mov    %rdx,%rdi
//    0x000000000043e7e3 <+35>:	mov    %esi,%eax
//    0x000000000043e7e5 <+37>:	syscall
//    0x000000000043e7e7 <+39>:	cmp    $0xfffffffffffff000,%rax
//    0x000000000043e7ed <+45>:	ja     0x43e810 <_exit+80>
//    0x000000000043e7ef <+47>:	hlt
//    0x000000000043e7f0 <+48>:	mov    %rdx,%rdi
//    0x000000000043e7f3 <+51>:	mov    %r8d,%eax
//    0x000000000043e7f6 <+54>:	syscall
//    0x000000000043e7f8 <+56>:	cmp    $0xfffffffffffff000,%rax
//    0x000000000043e7fe <+62>:	jbe    0x43e7e0 <_exit+32>
//    0x000000000043e800 <+64>:	neg    %eax
//    0x000000000043e802 <+66>:	mov    %eax,%fs:(%r9)
//    0x000000000043e806 <+70>:	jmp    0x43e7e0 <_exit+32>
//    0x000000000043e808 <+72>:	nopl   0x0(%rax,%rax,1)
//    0x000000000043e810 <+80>:	neg    %eax
//    0x000000000043e812 <+82>:	mov    %eax,%fs:(%r9)
//    0x000000000043e816 <+86>:	jmp    0x43e7ef <_exit+47>
// End of assembler dump.
