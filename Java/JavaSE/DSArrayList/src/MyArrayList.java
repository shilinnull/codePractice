import java.util.Arrays;

public class MyArrayList implements IList{
    private int[] array;
    private int usedSize;
    public static final int DEFAULT_CAPACITY = 10;

    public MyArrayList() {
        this.array = new int[DEFAULT_CAPACITY];
    }

    private void grow(){
        this.array = Arrays.copyOf(this.array, 2 * this.array.length);
    }

    @Override
    public void add(int data) {
        if(isFull()){
            grow(); // 扩容
        }
        this.array[this.usedSize++] = data;
    }

    @Override
    public boolean isFull() {
        return this.usedSize == this.array.length;
    }

    private void checkPos(int pos) throws PosILLegal{
        if(pos < 0 || pos > usedSize){
            throw new PosILLegal("pos位置不合法");
        }
    }

    @Override
    public void add(int pos, int data) {
        try{
            checkPos(pos);
            if(isFull()){
                grow(); // 扩容
            }
            for(int i = usedSize - 1; i >= pos; i--){
                array[i + 1] = array[i];
            }
            array[pos] = data;
            usedSize++;
        }catch (PosILLegal e){
            System.out.println("插入元素pos位置不合法..");
            e.printStackTrace();
        }
    }

    @Override
    public boolean contains(int toFind) {
        for (int i = 0; i < usedSize; i++) {
            if(array[i] == toFind){
                return true;
            }
        }
        return false;
    }

    @Override
    public int indexOf(int toFind) {
        for (int i = 0; i < usedSize; i++) {
            if(array[i] == toFind) {
                return i;
            }
        }
        return 0;
    }

    private void checkEmpty() throws EmptyException{
        if(isEmpty()){
            throw new EmptyException("顺序表为空!");
        }
    }

    public boolean isEmpty(){
        return usedSize == 0;
    }

    @Override
    public int get(int pos) {
        try {
            checkEmpty();
            checkPos(pos);

            return array[pos];
        }catch (PosILLegal e){
            e.printStackTrace();
        }catch (EmptyException e){
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public void set(int pos, int value) {
        try {
            checkEmpty();
            checkPos(pos);

            array[pos] = value;
        }catch (PosILLegal e) {
            e.printStackTrace();
        }catch (EmptyException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void remove(int toRemove) {
        try {
            checkEmpty(); // 检查是否为空
            int pos = indexOf(toRemove); // 找到要删除的下标
            if(pos == -1) {
                return;
            }
            for (int i = pos; i < usedSize-1; i++) {
                array[i] = array[i + 1];
            }
            usedSize--;
        }catch (EmptyException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int size() {
        return usedSize;
    }

    @Override
    public void clear() {
        usedSize = 0;
    }

    @Override
    public void display() {
        for (int i = 0; i < this.usedSize; i++) {
            System.out.print(array[i]+" ");
        }
    }

    @Override
    public String toString() {
        return "MyArrayList{" +
                "array=" + Arrays.toString(array) +
                ", usedSize=" + usedSize +
                '}';
    }
}
