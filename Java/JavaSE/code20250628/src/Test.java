


/*
* 抽象类不能直接实例化对象
* 抽象方法不能是 private 的
* 抽象方法不能被final和static修饰，因为抽象方法要被子类重写
* 抽象类必须被继承，并且继承后子类要重写父类中的抽象方法，否则子类也是抽象类，必须要使用 abstract 修饰
* 抽象类中不一定包含抽象方法，但是有抽象方法的类一定是抽象类
* 抽象类中可以有构造方法，供子类创建对象时，初始化父类的成员变量
* */
abstract class A{
    abstract void show();

}

public class Test extends A{

    @Override
    void show() {
        System.out.println("重写抽象类");
    }

    public static void main(String[] args) {
        Test a = new Test();
        a.show();
    }

}
