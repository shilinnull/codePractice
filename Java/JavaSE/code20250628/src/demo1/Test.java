package demo1;

public class Test {

    /**
     * 父类的静态
     * 子类的静态
     * 父类的实例
     * 父类的构造
     * 子类的实例
     * 子类的构造
     * */
    public static void main1(String[] args) {
        Dog dog = new Dog(); // 执行的时候先调用父类的构造
        dog.name = "旺财";
        dog.bark();
        dog.eat();
    }

    public static void main2(String[] args) {
        Cat cat = new Cat("小苗：");
        cat.eat();
    }

    public static void main3(String[] args) {
        Animal a = new Cat();
        a.eat();
        a.Test();
        a.Test1();
    }

    public static void main(String[] args) {
        // 向上转，不能调用子类的方法
        Cat a = new Cat();
        Animal a1 = a;

        // 向下转
        Animal b = new Animal();
//        Cat b1 = (Cat)b; // 强制转
//        b1.mew(); // 运行抛异常

        System.out.println("===========");
        Cat cat = new Cat();
        Dog dog = new Dog();
        Animal animal = new Animal();
        animal.eat();
//        animal = dog;
        animal = cat;
        animal.eat();
        // 使用关键字
        if(animal instanceof Cat){
            cat = (Cat)animal;
            cat.mew();
        }
        if(animal instanceof Dog){
            dog = (Dog)animal;
            dog.bark();
        }

    }
}
