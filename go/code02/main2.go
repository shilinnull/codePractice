package main

import (
	"fmt"
	"unsafe"
)

func showChar() {
	var x byte = 65
	var y uint8 = 65
	fmt.Printf("x = %c\n", x) // x = A
	fmt.Printf("y = %c\n", y) // y = A
}

func sizeOfChar() {
	var x byte = 65
	fmt.Printf("x = %c\n", x)
	fmt.Printf("x 占用 %d 个字节\n", unsafe.Sizeof(x))

	var y rune = 'A'
	fmt.Printf("y = %c\n", y)
	fmt.Printf("y 占用 %d 个字节\n", unsafe.Sizeof(y))
}

func main() {
	showChar()
	sizeOfChar()
}
