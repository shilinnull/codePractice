package main

import "fmt"

func showComplex() {
	// 内置的 complex 函数用于构建复数
	var x complex64 = complex(1, 2)
	var y complex128 = complex(3, 4)
	var z complex128 = complex(5, 6)
	fmt.Println("x = ", x)
	fmt.Println("y = ", y)
	fmt.Println("z = ", z)

	// 内建的 real 和 imag 函数分别返回复数的实部和虚部
	fmt.Println("real(x) = ", real(x))
	fmt.Println("imag(x) = ", imag(x))
	fmt.Println("y * z = ", y*z)
}

func main() {
	showComplex()
}
