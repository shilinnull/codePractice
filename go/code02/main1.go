package main

import (
	"fmt"
	"math"
)

func showFloat() {
	var num1 float32 = math.MaxFloat32
	var num2 float64 = math.MaxFloat64
	fmt.Printf("num1的类型是%T,num1是%g\n", num1, num1)
	fmt.Printf("num2的类型是%T,num1是%g\n", num2, num2)
}

func main() {
	showFloat()
}
