package main

import "fmt"

func showBool() {
	a := true
	b := false
	fmt.Println("a=", a)
	fmt.Println("b=", b)
	fmt.Println("true && false = ", a && b)
	fmt.Println("true || false = ", a || b)
}

func main() {
	showBool()
}
