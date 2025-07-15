import java.util.*;

class Student implements Comparable<Student>{
    private int num = 1;

    @Override
    public int compareTo(Student o) {
        return this.num - o.num;
    }
}
public class Test {
    public static void main(String[] args) {
        HashMap<String,Integer> map = new HashMap<>();
        map.put("abcd",3);
        map.put("hello",13);
        map.put("world",5);
        System.out.println(map);

        HashSet<String> set = new HashSet<>();
        set.add("abcd");
        set.add("hello");
        set.add("world");
        System.out.println(set);

        int[] array1 = {1,1,2,3,4,5,7,8,3,1,12,4,5,7,43,3,3,5};
        HashSet<Integer> set1 = new HashSet<>();
        for (int i = 0; i < array1.length; i++) {
            set1.add(array1[i]);
        }
        System.out.println(set1);


        //找到这组数据当中 第一个重复的数据
        int[] array = {1,1,2,3,4,5,7,8,3,1,12,4,5,7,43,3,3,5};
        HashSet<Integer> set2 = new HashSet<>();
        for (int i = 0; i < array.length; i++) {
           if(!set2.contains(array[i])) {
               set2.add(array[i]);
           }else {
               System.out.println(array[i]);
               return;
           }
        }
        HashMap<Student,Integer> map2 = new HashMap<>();
        map2.put(new Student(),10);
        map2.put(new Student(),20);
    }
    public static void main4(String[] args) {
        TreeSet<String> set = new TreeSet<>();
        set.add("abcd");
        //set.add("abcd");
        set.add("hello");
        set.add("def");


        //System.out.println(set.contains("abcd"));
        Iterator<String> it = set.iterator();
        while (it.hasNext()) {
            System.out.print(it.next()+" ");
        }
        System.out.println();
    }


    public static void main3(String[] args) {
        TreeMap<Student,Integer> treeMap = new TreeMap<>();
        treeMap.put(new Student(),1);
        treeMap.put(new Student(),2);
    }

    public static void main2(String[] args) {
        TreeMap<String,Integer> treeMap = new TreeMap<>();
        treeMap.put("abc",3);
        treeMap.put("hello",2);
        treeMap.put("world",5);

//        Set<Map.Entry<K, V>> entrySet()
        Set<Map.Entry<String,Integer>> entrySet = treeMap.entrySet();
        for(Map.Entry<String,Integer> entry : entrySet) {
            System.out.println("key: "+entry.getKey() +" val: "+entry.getValue());
        }

        Integer val = treeMap.getOrDefault("hello2",100);
        System.out.println(val);

        Integer val1 = treeMap.get("hello");
        System.out.println(val1);

        treeMap.remove("hello");

    }


    public static void main1(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(9);
        bst.insert(3);
        bst.insert(18);

        BinarySearchTree.TreeNode ret = bst.search(15);
        System.out.println(ret.val);

        bst.remove(10);
    }
}
