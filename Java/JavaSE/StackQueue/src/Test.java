import java.util.LinkedList;

public class Test {


    public static void main(String[] args) {
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
