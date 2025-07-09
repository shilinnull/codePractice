

public class Test {
    public static void main(String[] args) {
        int[] array = {27,15,19,18,28,34,65,49,25,37 };
        Heap testHeap = new Heap();

//        testHeap.initElem(array);
//        testHeap.create();
//        testHeap.heapSort();

        System.out.println(testHeap.poll());
        for (int i = 0; i < array.length; i++) {
            testHeap.offer(array[i]);
        }
        testHeap.offer(80);
    }
}
