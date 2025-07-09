import java.util.Arrays;

public class Heap {
    public int[] elem;
    public int usedSize;

    public Heap() {
        this.elem = new int[11];
    }

    public void initElem(int[] array) {
        for (int i = 0; i < array.length; i++) {
            this.elem[i] = array[i];
            this.usedSize++;
        }
    }

    public void create() {
        // 从倒数第二层开始调整
        for (int i = (this.usedSize - 1 - 1) / 2; i >= 0; i--) {
            siftDown(i, this.usedSize);
        }
    }

    private void siftDown(int parent, int usedSize) {
        int child = parent * 2 + 1;
        while (child < usedSize) {
            if (child + 1 < usedSize && elem[child] < elem[child + 1]) {
                child++;
            }
            if(elem[child] > elem[parent]){
                swap(elem, child, parent);
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
    }

    private void swap(int[] elem,int i,int j) {
        int tmp = elem[i];
        elem[i] = elem[j];
        elem[j] = tmp;
    }

    public void offer(int e) {
        if(isFull()){
            elem = Arrays.copyOf(elem, 2 * elem.length);
        }

        elem[usedSize] = e;
        siftUp(usedSize);
        usedSize++;
    }

    private void siftUp(int child) {
        int parent = (child - 1) / 2;
        while(parent >= 0){
            if(elem[parent] < elem[child]){
                swap(elem, child, parent);
                child = parent;
                parent = (child - 1) / 2;
            }
            else break;
        }
    }

    private boolean isFull() {
        return usedSize == elem.length;
    }
    public int poll(){
        if(isEmpty()){
            return -1;
        }
        int val = elem[0];
        swap(elem, 0, usedSize - 1);  // 和最后一个元素交换
        siftDown(0, usedSize - 1);
        usedSize--;
        return val;
    }

    private boolean isEmpty() {
        return usedSize == 0;
    }

    public int peek() {
        if(isEmpty()) {
            return -1;
        }
        return elem[0];
    }
    public void heapSort() {
        int end = usedSize - 1;
        while(end-- != 0){
            swap(elem, 0, end);
            siftDown(0, end);
        }
    }
}


















