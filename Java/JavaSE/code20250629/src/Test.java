

public class Test {
    private int a = 10;


    public class InnerClass1{
//        a = 10;

    }

    // 静态
    static class InnerClass2{

    }

    public void method(){
        // 局部
        // 不能被public、static等访问限定符修饰
        class InnerClass3 {

        }
        // 只能在这个方法内部使用
    }

    public static void main(String[] args) {
        Test.InnerClass1 a = new Test().new InnerClass1(); // 直接创建内部类

        // 先创建外部类
        // 然后创建内部类
        Test b = new Test();
        Test.InnerClass1 c = b.new InnerClass1();

        // 创建静态内部类
        Test.InnerClass2 d = new Test.InnerClass2();

    }
}















