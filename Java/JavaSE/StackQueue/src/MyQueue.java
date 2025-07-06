import java.util.List;

public class MyQueue {

    private class ListNode{
        public int val;
        public ListNode prev;
        public ListNode next;
        public ListNode(int val){
            this.val = val;
        }
    }
    private ListNode first = null;
    private ListNode last = null;

    private int usedSize = 0;

    public void offer(int val) {
        ListNode node = new ListNode(val);
        if(isEmpty()){
            first = last = node;
        }else{
            last.next = node;
            node.prev = last;
            last = last.next;
        }
        usedSize++;
    }


    public int poll() {
        if(isEmpty()){
            return -1;
        }
        int val = first.val;
        first = first.next;
        if(first != null){
            first.prev = null;
        }
        usedSize--;

        return val;
    }

    public int peek() {
        if(isEmpty()){
            return -1;
        }
        return first.val;
    }

    public boolean isEmpty() {
        return usedSize == 0;
    }

}
