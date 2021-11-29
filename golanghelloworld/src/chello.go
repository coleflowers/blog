// chello.go
package main

import (
	"fmt"
	"unsafe"
)

/*
#include <stdlib.h>
#include <stdio.h>
typedef const char* const_char_ptr;
*/
import "C"

func main() {
    fmt.Println("string print by go")
    cmsg := (C.const_char_ptr)(C.CString("string print by C"))
    defer C.free(unsafe.Pointer(cmsg))

    // link : https://stackoverflow.com/questions/21869668/passing-string-literal-to-c
    // C.printf(cmsg)
    C.puts(cmsg)
}
