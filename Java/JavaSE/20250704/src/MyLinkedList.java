import java.util.List;

public class MyLinkedList implements IList {

    static class ListNode {
        public int val;
        public ListNode prev;
        public ListNode next;

        public ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode head;
    public ListNode last;

    @Override
    public void addFirst(int data) {
        ListNode node = new ListNode(data);
        if(head == null){
            head = last = node;
        }
        else {
            node.next = head;
            head.prev = node;
            head = node;
        }
    }

    @Override
    public void addLast(int data) {
        ListNode node = new ListNode(data);
        if(head == null){
            head = last = node;
        }else {
            last.next = node;
            node.prev = last;
            last = last.next;
        }
    }

    @Override
    public void addIndex(int index, int data) throws PositionException {
        int len = size();
        if (index < 0 || index > len) {
            throw new PositionException("index位置错误！");
        }
        if (index == 0) {
            addFirst(data);
            return;
        }
        if (index == len) {
            addLast(data);
            return;
        }

        // 插入节点
        ListNode node = new ListNode(data);
        ListNode cur = findIndex(index);
        node.next = cur;
        cur.prev.next = node;
        node.prev = cur.prev;
        cur.prev = node;
    }
    private ListNode findIndex(int index){
        ListNode cur = head;
        while (index != 0) {
            cur = cur.next;
            index--;
        }
        return cur;
    }

    @Override
    public boolean contains(int key) {
        ListNode cur = head;
        while (cur != null) {
            if(cur.val == key) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }

    @Override
    public void remove(int key) {
        ListNode cur = head;
        while (cur != null) {
            // 删除
            if (cur.val == key) {


            }

        }
    }

    @Override
    public void removeAllKey(int key) {

    }

    @Override
    public int size() {
        ListNode cur = head;
        int n = 0;
        while (cur != null) {
            n++;
            cur = cur.next;
        }
        return n;
    }

    @Override
    public void clear() {
        ListNode cur = head;
        while (cur != null) {
            ListNode curN = cur.next;
            cur.prev = null;
            cur.next = null;
            cur = curN;
        }
        head = last = null;
    }

    @Override
    public void display() {
        ListNode cur = head;
        while (cur != null) {
            System.out.println(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }
}
