#include <stdio.h>
#include <string.h>
#include "libecho.h"

// gcc -I. -L. -lecho test.c -o test
int main(void) {
	const char *name = "张三";
	GoString str = {
		name,
		strlen(name)
	};
	echo(str);
	return 0;
}
