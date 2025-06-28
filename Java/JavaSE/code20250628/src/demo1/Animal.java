package demo1;

public class Animal {
    // final修饰的类无法被继承
    public String name;
    public int age;
    protected int a = 10;
    private int b = 20;

    public Animal(){
        System.out.println("Animal()");
    }

    public void eat() {
        System.out.println(name + "正在吃");
    }
    // 被private修饰的方法不能被重写
    // 子类重写父类的方法，子类的权限要>=父类的权限
    protected void Test(){
        System.out.println("Test()...");
    }

    // 父类返回父类的对象
    // 子类返回子类的对象
    // 也构成重写 C++中的协变
    public Animal Test1(){
        System.out.println("Animal Test1()");
        return null;
    }
    /*
    * 重写规则：
    * 返回值类型 方法名 (参数列表) 要完全一致
    * 被重写的方法返回值类型可以不同，但是必须是具有父子关系的
    * 父类被static、private修饰的方法、构造方法都不能被重写。
    * */
}
