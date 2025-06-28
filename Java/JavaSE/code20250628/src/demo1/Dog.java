package demo1;

public class Dog extends Animal{

    public Dog(){
        super();

        // this用来访问本类的方法和属性，super用来访问父类继承下来的方法和属性
        System.out.println("Dog()");
    }
    public void bark(){
        System.out.println(name + "旺旺");
    }

    void tets(){
        System.out.println(super.name); // 使用了super
        super.eat();
        a = 40; // 可以访问protected
//        b = 30; // 无法访问private
    }
}
