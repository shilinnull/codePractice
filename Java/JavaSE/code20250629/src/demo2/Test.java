package demo2;
import java.util.Arrays;

import static demo2.Student.MySort;
import static demo2.Student.swap;

class Student implements Comparable<Student>{
    protected String name;
    protected int score;

    public Student(String name, int score) {
        this.name = name;
        this.score = score;
    }
    public Student(){

    }

    @Override
    public String toString() {
        return "student{" +
                "name='" + name + '\'' +
                ", score=" + score +
                '}';
    }

    public static void swap(MyValue e1, MyValue e2) {
        int tmp = e1.val;
        e1.val = e2.val;
        e2.val = tmp;
    }

    class MyValue{
        public MyValue(int val) {
            this.val = val;
        }

        public int val;
    }

    public static void MySort(Comparable[] array){
        for(int i = 0;i < array.length - 1; i++){
            for (int j = 0; j < array.length - 1 - i; j++) {
                if(array[j].compareTo(array[j + 1]) > 0){
                    Comparable tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }

//    @Override
//    public int compareTo(Object o) {
//        Student s = (Student)o;
//        if(this.score > s.score) {
//            return -1;
//        } else if (this.score < s.score) {
//            return 1;
//        }
//        else return 0;
//    }

    @Override
    public int compareTo(Student o) {
//        if(this.score > o.score) {
//            return 1;
//        } else if (this.score < o.score) {
//            return -1;
//        }
//        else return 0;
          return this.score - o.score;
//        return this.name.compareTo(o.name);
    }
}


public class Test {

    public static void main(String[] args) {
        Student.MyValue m = new Student().new MyValue(1);
        Student.MyValue n = new Student().new MyValue(2);

        System.out.println(m.val + " " + n.val);
        swap(m, n);
        System.out.println(m.val + " " + n.val);

    }

    public static void main3(String[] args) {
        Student[] students = new Student[]{
                new Student("张三", 95),
                new Student("李四", 96),
                new Student("王五", 97),
                new Student("赵六", 92)
        };

        System.out.println(Arrays.toString(students));
//        Arrays.sort(students);
        MySort(students);
        System.out.println(Arrays.toString(students));
        /////////////////////////////////////////////////
        System.out.println("===============");
        Student a = new Student("haha", 20);
        Student b = new Student("haha", 15);
        NameComparator nameComparator = new NameComparator();
        System.out.println(nameComparator.compare(a, b));
    }

    public static void main2(String[] args) {
        Student a = new Student("haha", 20);
        Student b = new Student("hehe", 15);
        System.out.println(a.compareTo(b));
    }


    public static void main1(String[] args) {
        Student[] students = new Student[]{
                new Student("张三", 95),
                new Student("李四", 96),
                new Student("王五", 97),
                new Student("赵六", 92)
        };
        Arrays.sort(students);
        System.out.println(Arrays.toString(students));
    }
}
