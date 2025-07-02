import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> test = new ArrayList<>();
        test.add(1);
        test.add(2);
        test.add(3);
        test.add(4);
        test.add(5);
        System.out.println(test);// 1 2 3 4 5

//        List<Integer> list = test.subList(1,3); // 2 3
        var list = test.subList(1, 3);
        System.out.println(list);

        System.out.println("=============");

        list.set(0,99);
        System.out.println(test);//1 99 3 4 5
        System.out.println(list);// 99 3
        System.out.println("=============");
        for (Integer integer : list) {
            System.out.print(integer + "  ");
        }

        Iterator<Integer> it = list.listIterator();
        while(it.hasNext()) {
            System.out.print(it.next() + " ");
        }
    }
    public static void main1(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        ArrayList<Integer> list1 = new ArrayList<>();
        list1.addAll(list);

        list1.set(1, 20);

        System.out.println(list);
        System.out.println(list1);

        list.remove(new Integer(3));
        System.out.println(list);
        System.out.println(list1);

        List<Integer> list2 = new ArrayList<>();
        list2.add(1222);
        System.out.println(list2);

    }

}
