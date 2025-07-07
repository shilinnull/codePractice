public class Test {
    public static void main(String[] args) {
        BinaryTree binaryTree = new BinaryTree();
        BinaryTree.TreeNode root = binaryTree.createTree();

        System.out.println("节点的个数: "+ binaryTree.size(root));
        System.out.println("叶子节点的个数: "+ binaryTree.getLeafNodeCount(root));
        System.out.println("第K层节点的个数: "+ binaryTree.getKLevelNodeCount(root,4));
        int ret = binaryTree.getHeight(root);
        System.out.println("树的高度为："+ret);

        BinaryTree.TreeNode ret2 = binaryTree.findVal(root,'A');
        System.out.println(ret2.val);

    }
}
