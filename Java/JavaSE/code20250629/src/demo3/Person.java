package demo3;


import java.util.Objects;

class Money implements Cloneable{
    public double m = 10.1;

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}

public class Person implements Cloneable{
    public String name = "";
    public int age;

    public Money money = new Money();

    @Override
    protected Object clone() throws CloneNotSupportedException {
        // 实现深拷贝
        Person tmp = (Person) super.clone();
        tmp.money = (Money)this.money.clone();
        return tmp;
    }

    @Override
    public boolean equals(Object o) {
        if(o == null) return false;
        if(this == o) return true;
        if(! (o instanceof Person)) return false;

        Person obj = (Person) o;
        return this.name.equals(obj.name) && (this.age == obj.age);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age, money);
    }
}
