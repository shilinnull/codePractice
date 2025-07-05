import java.lang.reflect.Array;
import java.util.Arrays;

public class myStack {
    private int[] elem;
    private int usedSize;

    public myStack() {
        this.elem = new int[10];
    }

    public void push(int val){
        if(isFull()){
            this.elem = Arrays.copyOf(elem, 2 * elem.length);
        }
        elem[usedSize++] = val;
    }
    private boolean isFull(){
        return usedSize == elem.length;
    }

    public int pop() throws EmptyStackException{
        if(isEmpty()){
            throw new EmptyStackException("栈已经为空！");
        }
        return elem[--usedSize];
    }

    public int peek() {
        if(isEmpty()){
            throw new EmptyStackException();
        }
        return elem[usedSize];
    }

    private boolean isEmpty(){
        return usedSize == 0;
    }
}
