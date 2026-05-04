package main // 包

//import "fmt" //导入fmt包
import (
	"fmt"
)

func main() {
	fmt.Println("Hello World")
	var name string = "zhangsan"
	fmt.Printf("What is your name? name: %s\n", name)
	var xx, yy int = 1, 2
	fmt.Printf("xx: %d, yy: %d\n", xx, yy)

	var a int
	fmt.Printf("a的类型: %T\n", a)

	var b = "www"
	fmt.Printf("b的类型: %T\n", b)

	c := 111
	fmt.Printf("c的类型：%T\n", c)

	var (
		m int  = 111
		n bool = false
	)
	fmt.Printf("a的类型是：%T, b的类型是%T\n", m, n)

	const length int = 4
	fmt.Println(length)

	//const (
	//	BEIJING  = 0
	//	SHANGHAI = 1
	//	SHENZHEN = 2
	//)

	const (
		// 可以在const()中添加一个关键字iota, 每行的iota都会累加1, 第一行的iota默认是0
		BEIJING  = 10 * iota // iota = 0
		SHANGHAI             // iota = 1
		SHENZHEN             // iota = 2
	)

	fmt.Println(BEIJING, SHANGHAI, SHENZHEN)

}
