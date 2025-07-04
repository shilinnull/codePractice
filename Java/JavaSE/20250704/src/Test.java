import java.util.*;

public class Test {

    public static void main2(String[] args) {
        LinkedList<Integer> linkedList2 = new LinkedList<>();
        linkedList2.add(1);//默认都是尾插
        linkedList2.addLast(3);
        linkedList2.addLast(4);
        linkedList2.addLast(5);
        System.out.println(linkedList2);

        System.out.println("===== ListIterator ====");
        ListIterator<Integer> lit2 =  linkedList2.listIterator(linkedList2.size());
        while (lit2.hasPrevious()) {
            System.out.print(lit2.previous()+" ");
        }
        System.out.println();

        System.out.println("===== ListIterator ====");
        ListIterator<Integer> lit =  linkedList2.listIterator();
        while (lit.hasNext()) {
            System.out.print(lit.next()+" ");
        }
        System.out.println();

        System.out.println("===== Iterator ====");
        Iterator<Integer> it = linkedList2.iterator();
        while (it.hasNext()) {
            System.out.print(it.next()+" ");
        }
        System.out.println();


        System.out.println("=====for each====");

        for(Integer x : linkedList2) {
            System.out.print(x +" ");
        }
        System.out.println();

        System.out.println("=====for====");
        for (int i = 0; i < linkedList2.size(); i++) {
            System.out.print(linkedList2.get(i) +" ");
        }
        System.out.println();


    }
    public static void main6(String[] args) {
        List<Integer> linkedList1 = new LinkedList<>();
        LinkedList<Integer> linkedList2 = new LinkedList<>();
        linkedList2.add(1);//默认都是尾插
        linkedList2.addFirst(2);
        linkedList2.addLast(3);
        linkedList2.addLast(4);
        linkedList2.addLast(5);
        System.out.println(linkedList2);

        ArrayList<Integer> list = new ArrayList<>();
        list.add(11);
        list.add(21);
        list.add(31);

        linkedList2.addAll(list);

        System.out.println(linkedList2);

        linkedList2.remove(2);
        System.out.println(linkedList2);

    }

    public static void main(String[] args) {
        MyLinkedList myLinkedList = new MyLinkedList();
        myLinkedList.addLast(1);
        myLinkedList.addLast(1);
        myLinkedList.addLast(1);
        myLinkedList.addLast(1);
        myLinkedList.addLast(1);

        myLinkedList.display();

        myLinkedList.clear();
        //myLinkedList.addIndex(3,9);
        myLinkedList.display();

    }

    public static void main1(String[] args) {
        MySingleList list = new MySingleList();
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        list.display();

        list.remove(3);
        list.display();
        System.out.println("==============");
        list.clear();
        list.display();

        System.out.println("===========");
        list.createList();
        list.display();
        list.addFirst(99);
        list.addFirst(12);
        list.addFirst(23);
        list.addFirst(34);
        list.display();
        list.addIndex(0,199);
        list.addIndex(1,299);
        list.addIndex(6,699);
        list.addIndex(20, 699);
        list.display();
        System.out.println(list.size());
    }
}
