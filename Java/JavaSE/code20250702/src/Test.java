import java.util.Comparator;

interface HelloService {   // 接口实现
    // Java8, 接⼝可以有默认⽅法。Java9之后，可以在接⼝内实现私有⽅法实现

    public void sayHello();
    // 默认方法
    default void saySomething(){
        syaEngHello();
        sayHello();
    };
    // 私有方法
    private void syaEngHello(){
        System.out.println("Hello!");
    }
}


sealed class Animal permits Dog{ // 必须要有子类
    private String name;
    private int age;
    public void eat(){
        System.out.println("eat()....");
    }
}


non-sealed class Dog extends Animal{
    @Override
    public void eat() {
        System.out.println("小狗eat()");
    }
}


public class Test implements HelloService{

    public static void main1(String[] args) {
        String data = "one";
        int result = switch (data) {
            case "one" -> 1;
            case "two" -> 2;
            default -> -1;
        };

        int result1 = switch (data){
            case "one" : yield 10;
            case "two" : yield 22;
            default : yield -1;
        };
        System.out.println(result);
        System.out.println(result1);

        var name = "张三";  // 可以变量
        System.out.println(name);
    }

    public static void main(String[] args) {
        Animal a = new Animal();
        a.eat();
        Test b = new Test();
        b.sayHello();
        b.saySomething();

    }

    @Override
    public void sayHello() {
        System.out.println("sayHello()!!!");
    }

    /*var age = 10;*/  // 不允许字段
}
