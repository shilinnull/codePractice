package demo3;

public class Test {
    public static void main(String[] args) throws CloneNotSupportedException {
        Person person1 = new Person();
        Person person2 = (Person) person1.clone();

        person1.money.m++;
        System.out.println(person1.money.m);
        System.out.println(person2.money.m);
        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
    }
}
