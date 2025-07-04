


public class Test {
    public static void main(String[] args) {
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
