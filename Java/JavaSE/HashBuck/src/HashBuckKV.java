public class HashBuckKV<K, V> {

    static class Node<K, V> {
        public K key;
        public V val;
        public Node<K, V> next;

        public Node(K key, V val) {
            this.key = key;
            this.val = val;
        }
    }

    public Node<K, V>[] array = (Node<K, V>[]) new Node[10];
    public int usedSize;

    public static final double DEFAULT_LOAD_FACTOR = 0.75f;

    public void push(K key, V val) {
        int hashcode = key.hashCode();
        int index = hashcode % array.length;
        Node<K, V> cur = array[index];
        while (cur != null) {
            if (cur.key.equals(key)) {
                cur.val = val;
                return;
            }
            cur = cur.next;
        }
        Node<K, V> node = new Node<>(key, val);
        node.next = array[index];
        array[index] = node;
        usedSize++;
    }

    public V getVal(K key) {
        int hashcode = key.hashCode();
        int index = hashcode % array.length;
        Node<K, V> cur = array[index];
        while (cur != null) {
            if (cur.key.equals(key)) {
                return cur.val;
            }
            cur = cur.next;
        }
        return null;
    }
}
