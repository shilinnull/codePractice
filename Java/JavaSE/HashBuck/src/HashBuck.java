import java.util.Arrays;

public class HashBuck {

    static class Node {
        public int key;
        public int val;
        public Node next;

        public Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    public Node[] array = new Node[10];
    public int usedSize;

    public static final double DEFAULT_LOAD_FACTOR = 0.75f;

    public void push(int key, int val) {
        int index = key % array.length;  // 计算哈希值
        Node cur = array[index];
        while (cur != null) {
            if (cur.key == key) {
                cur.val = val;
                return;
            }
            cur = cur.next;
        }
        // 插入
        Node node = new Node(key, val);
        node.next = array[index]; // 头插法
        array[index] = node;
        usedSize++;
        if (doLoadFactor() >= DEFAULT_LOAD_FACTOR) {
            resize();
        }
    }

    private void resize() {
        Node[] newArray = new Node[2 * array.length];

        // 重新映射
        for (int i = 0; i < array.length; i++) {
            Node cur = array[i];
            while (cur != null) {
                int newIndex = cur.key % newArray.length;
                Node curN = cur.next;
                cur.next = newArray[newIndex];
                newArray[newIndex] = cur;
                cur = curN;
            }
        }
        array = newArray;
    }

    private double doLoadFactor() {
        return usedSize * 1.0 / array.length;
    }

    public int getVal(int key) {
        int index = key % array.length;
        Node cur = array[index];
        while (cur != null) {
            if (cur.key == key) {
                return cur.val;
            }
            cur = cur.next;
        }
        return -1;
    }
}
