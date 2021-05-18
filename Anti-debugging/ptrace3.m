// author : 爱写代码的小马

// for arm arch
// compile: clang ptrace3.m -o ptrace3
// for x86_64
// compile: clang ptrace3.m -o ptrace3 -arch x86_64
#include <stdio.h>

int main(int argc,char* argv[]) {
	printf("before ptrace\n");

#ifdef __arm64__
    asm("mov x0, #31");
    asm("mov x1, #0");
    asm("mov x2, #0");
    asm("mov x3, #0");
    asm("mov x16, #26");
    asm("svc #0x80");
#else
    asm("movq $0, %rcx");
    asm("movq $0, %rdx");
    asm("movq $0, %rsi");
    asm("movq $0x1f, %rdi");      /* PT_DENY_ATTACH 31 (0x1f)*/
    asm("movq $0x200001a, %rax"); /* ptrace syscall number 26 (0x1a) */
    asm("syscall");
#endif

	printf("after ptrace\n");
	return 0;
}
