import java.util.ArrayList;

public class Test {

    public static void main(String[] args) {
        MyArrayList myArrayList = new MyArrayList();
        myArrayList.add(1);
        myArrayList.add(2);
        myArrayList.add(3);
        myArrayList.add(4);
        myArrayList.add(5);

//        System.out.println(myArrayList.get(10));

        myArrayList.add(1,15);
        myArrayList.add(2,115);
//        myArrayList.add(8,999);

        myArrayList.display();
        MyArrayList myArrayList1 = myArrayList;
        myArrayList1.set(1, 999);
        System.out.println(myArrayList1);
        System.out.println(myArrayList); // 同时修改了
    }

    public static void main1(String[] args) {
        MyArrayList myArrayList = new MyArrayList();

        IList list = new MyArrayList(); // 接口可以直接接收

        System.out.println(list.size());
        System.out.println(myArrayList.size());

        System.out.println("=====");
        list.display();
        myArrayList.display();
    }





}
