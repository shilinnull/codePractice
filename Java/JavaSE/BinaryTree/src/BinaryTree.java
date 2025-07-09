import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTree {

    static class TreeNode {
        public char val;
        public TreeNode left;//存储左孩子的引用
        public TreeNode right;//存储右孩子的引用

        public TreeNode(char val) {
            this.val = val;
        }
    }

    public TreeNode createTree() {
        TreeNode A = new TreeNode('A');
        TreeNode B = new TreeNode('B');
        TreeNode C = new TreeNode('C');
        TreeNode D = new TreeNode('D');
        TreeNode E = new TreeNode('E');
        TreeNode F = new TreeNode('F');
        TreeNode G = new TreeNode('G');
        TreeNode H = new TreeNode('H');

        A.left = B;
        A.right = C;
        B.left = D;
        B.right = E;
        C.left = F;
        C.right = G;
        E.right = H;
        return A;
    }


    public void preOrder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    public void inOrder(TreeNode root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }

    public void postOrder(TreeNode root) {
        if (root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.val + " ");
    }

    public void preOrderNor(TreeNode root) {
        if(root == null) return;  // 空树直接返回
        Stack<TreeNode> stack = new Stack<>();  // 使用栈辅助遍历
        TreeNode cur = root;

        // 当前节点不为空或栈不为空
        while(cur != null || !stack.isEmpty()){
            // 一直向左走，边走边访问节点值
            while(cur != null){
                stack.push(cur);
                System.out.print(cur.val + " ");
                cur = cur.left;
            }
            // 左子树走到头了，弹出栈顶元素
            TreeNode top = stack.pop();
            // 转向右子树
            cur = top.right;
        }
    }

    public void inOrderNor(TreeNode root) {
        if(root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;  // 当前节点指针

        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 左子树走到头了，弹出栈顶元素并访问
            TreeNode top = stack.pop();
            System.out.print(top.val + " ");  // 访问根节点

            // 转向右子树
            cur = top.right;
        }
    }

    public void postOrderNor(TreeNode root) {
        if(root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        TreeNode prev = null;  // 记录上一个访问的节点

        while (cur != null || !stack.isEmpty()) {
            // 一直向左走，将路径上的节点全部入栈
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 取栈顶元素但不弹出
            TreeNode top = stack.peek();

            // 判断是否可以访问当前节点：
            // 1. 没有右子树 或 2. 右子树已经被访问过
            if (top.right == null || top.right == prev) {
                System.out.print(top.val + " ");
                stack.pop();
                prev = top;  // 更新上一个访问的节点
            } else {
                // 右子树存在且未被访问，转向右子树
                cur = top.right;
            }
        }
    }

    public int size(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return size(root.left) +
                size(root.right) + 1;
    }

    public int getLeafNodeCount(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        return getLeafNodeCount(root.left) +
                getLeafNodeCount(root.right);
    }

    public int getKLevelNodeCount(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        return getKLevelNodeCount(root.left, k - 1) +
                getKLevelNodeCount(root.right, k - 1);
    }

    public int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);

        /*return Math.max(leftHeight,rightHeight)+1;*/
        return leftHeight > rightHeight
                ? leftHeight + 1 : rightHeight + 1;
    }

    public TreeNode findVal(TreeNode root, char val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }
        TreeNode leftT = findVal(root.left, val);
        if (leftT != null) {
            return leftT;
        }
        TreeNode rightT = findVal(root.right, val);
        if (rightT != null) {
            return rightT;
        }
        return null;
    }

    public boolean isCompleteTree(TreeNode root){
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode cur = q.poll();
            if(cur != null){
                q.offer(cur.left);
                q.offer(cur.right);
            }
            else {
                break;
            }
        }
        while(!q.isEmpty()){
            TreeNode cur = q.peek();
            if(cur != null) {
                return false;
            }
            q.poll();
        }
        return true;
    }

}