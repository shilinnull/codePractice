import com.shilin.www.TestPackage; // 声明

import java.util.Date; // 导入指定类
import java.util.*; // 导入所有类

import static java.lang.Math.*;// 使用静态方式

// 一个文件中可以有多个类，多个类中可以有main方法
public class TestRename {
    public static void main(String[] args) {
        TestPackage a = new TestPackage();
        System.out.println(a); // 通过重写来进行打印访问
        a.show();
    }
    public static void main4(String[] args) {
        // java.util.Date date = new java.util.Date();
        Date date =  new Date(); // 这样也可以
        System.out.println(date.getTime());

        double result = Math.pow(1, 2); //导入类这样使用
        double result1 = pow(2, 3); // 导入静态包后就可以这样使用
    }

    public static void main3(String[] args) {
        TestPackage a = new TestPackage();
        a.show();
    }

    public static void main2(String[] args) {
        TestPackage a = new TestPackage();
        System.out.println(a.b);
        a.Test(); // 不建议，但可以调用
        TestPackage.Test(); // 直接使用  类名.静态方法名字/成员名字
        TestPackage.c = 20;
        System.out.println(TestPackage.c);
    }


    public static void main1(String[] args) {
        Dog d = new Dog("小黄", 1);
        d.Say();
        Dog d1 = new Dog("小黑", 2);
        d1.Say();
    }
}

class Dog {
    public String name;
    public int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Dog(String name, int age) {
        this.name = name;
        this.age = age;
    }

    /* public Dog(String name, int age){
            this.name = name;
            this.age = age;
        }*/
    public void Say() {
        System.out.println(name + "wangwang");
    }

    // 这里也可以执行main
    public static void main(String[] args) {

    }
}

