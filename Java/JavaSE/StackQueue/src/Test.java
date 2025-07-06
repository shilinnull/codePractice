import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class Test {
    public static void main5(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        Deque<Integer> deque = new LinkedList<>();
        Deque<Integer> deque1 = new ArrayDeque<>();

    }
    public static void main(String[] args) {
        MyQueue queue = new MyQueue();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        queue.offer(4);

        System.out.println(queue.poll());//1
        System.out.println(queue.poll());//2
        System.out.println(queue.poll());//3
        System.out.println(queue.peek());//4
        System.out.println(queue.poll());//4
        System.out.println(queue.poll());
    }

    public static void main3(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        LinkedList<Integer> queue2 = new LinkedList<>();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        queue.offer(4);

        System.out.println(queue.poll());//1
        System.out.println(queue.peek());//2
    }

    public static void main2(String[] args) {
        LinkedList<Integer> stack = new LinkedList<>();

        stack.push(12);
        stack.push(23);
        stack.push(34);
        stack.push(45);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.peek());

    }

    public static void main1(String[] args) {
        myStack stack = new myStack();
        stack.push(12);
        stack.push(23);
        stack.push(34);
        stack.push(45);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
    }
}
