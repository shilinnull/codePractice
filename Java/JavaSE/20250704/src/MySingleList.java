public class MySingleList implements IList{

    static class ListNode{
        public int val;
        public ListNode next;

        public ListNode(int val){
            this.val = val;
        }
    }
    public ListNode head;

    public void createList() {
        ListNode node1 = new ListNode(12);
        ListNode node2 = new ListNode(23);
        ListNode node3 = new ListNode(34);
        ListNode node4 = new ListNode(45);
        ListNode node5 = new ListNode(56);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        this.head = node1;
    }

    @Override
    public void display() {
        ListNode cur = head;
        while(cur != null){
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    public void display(ListNode newHead) {
        ListNode cur = newHead;
        while(cur != null){
            System.out.println(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    @Override
    public int size() {
        int len = 0;
        ListNode cur = head;
        while(cur != null){
            len++;
            cur = cur.next;
        }
        return len;
    }

    @Override
    public boolean contains(int key) {
        ListNode cur = head;
        while(cur != null){
            if(cur.val == key){
                return true;
            }
        }
        return false;
    }

    @Override
    public void addFirst(int data) {
        ListNode node = new ListNode(data);

        node.next = head;
        head = node;
    }

    @Override
    public void addLast(int data) {
        ListNode node = new ListNode(data);
        if(head == null) {
            head = node;
            return;
        }
        // 找尾
        ListNode cur = head;
        while(cur.next != null){
            cur = cur.next;
        }
        cur.next = node;
    }

    @Override
    public void addIndex(int index, int data) throws PositionException{
        int len = size();
        if(index < 0 || index > len){
            throw new PositionException("index不合法!");
        }
        if(index == 0){
            addFirst(data);
            return;
        }
        if(index == len){
            addLast(data);
            return;
        }
        ListNode cur = head;
        int count = index - 1;
        while(count != 0){
            cur = cur.next;
            count--;
        }

        ListNode node = new ListNode(data);
        node.next = cur.next;
        cur.next = node;
    }

    @Override
    public void remove(int key) {
        if(head == null){
            return;
        }
        if(head.val == key){
            head = head.next;
        }
        ListNode cur = findNodeOfKey(key);
        if(cur == null){
            return;
        }
        ListNode del = cur.next;
        cur.next = del.next;
    }

    public ListNode findNodeOfKey(int key) {
        ListNode cur = head;
        while(cur != null){
            if(cur.next.val == key) {
                return cur;
            }
            cur = cur.next;
        }
        return null;
    }

    @Override
    public void removeAllKey(int key) {
        if(head == null){
            return;
        }
        ListNode prev = head;
        ListNode cur = head.next;
        while (cur != null) {
            if(cur.val == key) {
                prev.next = cur.next;
                cur = cur.next;
            } else {
                prev = cur;
                cur = cur.next;
            }
        }
        if(head.val == key) {
            head = head.next;
        }
    }

    @Override
    public void clear() {
        ListNode cur = head;
        while (cur != null) {
            ListNode curN = cur.next;
            cur.next = null;
            cur = curN;
        }
        head = null;
    }
}
