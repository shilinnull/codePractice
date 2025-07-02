import java.util.Comparator;

class Alg<E extends Comparable<E>>{
    public  E findMax(E[] array){
        E max = array[0];
        for (int i = 1; i < array.length; i++) {
//            if(max < array[i]) {
            if(max.compareTo(array[i]) < 0) {
                max = array[i];
            }
        }
        return max;
    }
}
class Alg2 {
    public <E extends Comparable<E>> E findMax(E[] array){
        E max = array[0];
        for (int i = 1; i < array.length; i++) {
            if(max.compareTo(array[i]) < 0) {
                max = array[i];
            }
        }
        return max;
    }
}

class Alg3 {
    public static <E extends Comparable<E>> E findMax(E[] array){
        E max = array[0];
        for (int i = 1; i < array.length; i++) {
            if(max.compareTo(array[i]) < 0) {
                max = array[i];
            }
        }
        return max;
    }
}

public class TestGeneric {

    public static void main(String[] args) {
        Integer[] array = {1, 2, 3, 4, 5, 6};

        Alg2 alg2 = new Alg2();
        System.out.println(alg2.<Integer>findMax(array));
        System.out.println(Alg3.findMax(array));
    }

    public static void main1(String[] args) {
        Integer[] array = {1, 2, 3, 4, 5, 6};
        Alg<Integer> alg = new Alg<>();
        int a = alg.findMax(array);
        System.out.println(a);
    }
}
