// callc.go
package main

/*
#cgo darwin CFLAGS: -I./base64
#cgo darwin LDFLAGS: -L. -lbase64
#include <stdlib.h>
#include <stdio.h>
#include <base64.h>
#include <string.h>
typedef const char* const_char_ptr;
*/
import "C"
import (
	"fmt"
	"unsafe"
)

// git clone https://github.com/sigusr1/base64
// gcc -fPIC -shared ./base64/base64.c -o libbase64.dylib
func main() {
    input := (C.const_char_ptr)(C.CString("pleasure."))
    defer C.free(unsafe.Pointer(input))
 
    output := (*C.char)(C.CString(""))
    defer C.free(unsafe.Pointer(output))

	len := C.Base64encode(output, input, C.int(C.strlen(input)));

	fmt.Println("长度", len, "base64", unsafe.Pointer(output))
	fmt.Println(C.GoString(output))
}