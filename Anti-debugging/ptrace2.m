// author : 爱写代码的小马
// compile: clang ptrace2.m -o ptrace2
#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>

#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

typedef int(*ptrace_ptr_t)(int _request, pid_t _pid, caddr_t _addr, int _data);

int main(int argc,char* argv[]) {
	printf("before ptrace\n");

    void* handle = dlopen(0, RTLD_GLOBAL|RTLD_NOW);
    ptrace_ptr_t ptrace_ptr = dlsym(handle, "ptrace");
    ptrace_ptr(PT_DENY_ATTACH, 0, 0, 0);
    dlclose(handle);

	printf("after ptrace\n");
	return 0;
}