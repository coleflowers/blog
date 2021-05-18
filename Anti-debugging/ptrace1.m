// author : 爱写代码的小马
// compile: clang ptrace1.m -o ptrace1
#include <stdio.h>
#include <sys/types.h>

#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

int ptrace(int _request, pid_t _pid, caddr_t _addr, int _data);

int main(int argc,char* argv[]) {
	printf("before ptrace\n");
	ptrace(PT_DENY_ATTACH, 0, 0, 0);
	printf("after ptrace\n");
	return 0;
}