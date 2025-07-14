import java.util.Arrays;
import java.util.Random;

public class Test {
    public static void orderArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            //array[i] = i;
            array[i] = array.length-1-i;
        }
    }

    public static void notOrderArray(int[] array) {
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(10_0000) ;
        }
    }
    public static void testInsert(int[] array) {
        array = Arrays.copyOf(array,array.length);
        long startTime = System.currentTimeMillis();
        Sort.insertSort(array);
        long endTime = System.currentTimeMillis();
        System.out.println("直接插入排序耗时："+(endTime-startTime));
    }

    public static void testSimple() {
        int[] array = { 2, 1, 4, 7, 5, 8, 9, 10, 3, 6};
        System.out.println("排序前："+Arrays.toString(array));
//        Sort.insertSort(array);
//        Sort.shellSort(array);
//        Sort.selectSort(array);
//        Sort.heapSort(array);
//        Sort.bubbleSort(array);
//        Sort.quickSort(array);
        Sort.mergeSort(array);
        System.out.println("排序后："+Arrays.toString(array));
    }

    public static void main(String[] args) {
        testSimple();
    }
}
