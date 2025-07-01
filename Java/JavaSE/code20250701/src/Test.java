

class MyArray<E extends Number> {
    public Object[] array = new Object[10];

    public void setValue(int pos,E val) {
        array[pos] = val;
    }

    public E getVal(int pos) {
        return (E)array[pos]; // 数组中的每一个元素是Object父类，所以就需要强转
    }
}

public class Test {
    public static void main(String[] args) {
        MyArray<Number> myArray = new MyArray<>();
//        MyArray<String> myArray1 = new MyArray<String>(); // 不能使用不同类型
    }

    public static void main2(String[] args) {
        int a = 10;
        Integer b = Integer.valueOf(a);
        System.out.println(b);
    }
    public static void main1(String[] args) {
        Integer a = 100;
        Integer b = 100;
        System.out.println(a == b);

        Integer c = 200;
        Integer d = 200;
        System.out.println(c == d);
    }
}
