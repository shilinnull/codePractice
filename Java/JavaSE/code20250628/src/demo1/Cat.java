package demo1;

public class Cat extends Animal {
    public void mew() {
        System.out.println(name + "喵喵");
    }

    public Cat(){

    }

    public Cat(String name) {
        super.name = name;
    }

    @Override
    public void eat(){ // 对父类的eat进行重写
        System.out.println(name + "喵喵" + "吃鱼");
    }

    @Override
    protected void Test() {
        System.out.println("Cat Test()");
    }

    public Cat Test1(){
        System.out.println("Cat Test1()");
        return null;
    }
}
