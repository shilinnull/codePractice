package com.shilin.www;

public class TestPackage {
    int a; // 默认权限，只能再同一个包内访问
    public int b;
    public static int c;
    private int d = 40; // 默认给予初始值

    private static int e;
    // 一般用来初始化静态成员变量
    static {
        e = 50;
    }

    // 实例代码块
    {
        a = 666;
    }

    // 构造
    public TestPackage(){
        // 使用this调用其他的构造进行初始化
        // this()必须是构造的第一句
        this(1, 2);
    }
    // 先初始化静态->实例代码块->构造
    // 静态只初始化一次
    /// //////////////////////////////


    public TestPackage(int a, int b){
        this.a = a;
        this.b = b;
    }



    // 在我自己类的方法可以直接调用static修饰的方法
    public void show() {
        System.out.println(a);
    }

    // ststic 是属于类的，不依赖对象，也就是可以不用对象来进行访问
    // ststic 修饰的方法没有this指针


    @Override
    public String toString() {
        return "TestPackage{" +
                "a=" + a +
                ", b=" + b +
                ", d=" + d +
                '}';
    }

    public static void Test() {
        System.out.println("TestPackage test");
        // this.a = 10; // 不能使用this
    }
}
