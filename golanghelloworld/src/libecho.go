// libecho.go
package main

/*
#cgo darwin LDFLAGS: -Wl,-rpath,./
*/
import "C"
import (
	"fmt"
)

//export echo
func echo(name string) {
	fmt.Println("Hello", name)
}

func main() {}