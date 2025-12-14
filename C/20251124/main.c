#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createTree() {
    char ch;
    scanf("%c", &ch);

    TreeNode *node = NULL;
    if (ch == '#') {
        node = NULL;
    } else {
        // 分配内存
        node = (TreeNode*)malloc(sizeof(TreeNode));
        if (node == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        node->data = ch;
        node->left = createTree();
        node->right = createTree();
    }
    return node;
}

// 计算二叉树的深度
int getDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

// 计算二叉树的节点总数
int getNodeCount(TreeNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        return getNodeCount(root->left) + getNodeCount(root->right) + 1;
    }
}

// 先序遍历 (根 -> 左 -> 右)
void preOrder(TreeNode *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历 (左 -> 根 -> 右)
void inOrder(TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

// 后序遍历 (左 -> 右 -> 根)
void postOrder(TreeNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    printf("请按先序遍历顺序输入二叉树节点（用#表示空节点）：\n");
    // printf("示例输入: ABD##E##CF###\n");

    // 建立二叉树
    TreeNode *root = createTree();

    printf("对应的二叉树结构:\n");
    printf("      A      \n");
    printf("     / \\    \n");
    printf("    B   C    \n");
    printf("   / \\  \\    \n");
    printf("  D  E    F  \n");
    printf("ABD##E##CF###\n\n");

    // 计算并输出深度和节点数
    printf("二叉树的深度为：%d\n", getDepth(root));
    printf("二叉树的节点总数为：%d\n", getNodeCount(root));

    printf("\n");

    printf("先序遍历结果：");
    preOrder(root);
    printf("\n");

    printf("中序遍历结果：");
    inOrder(root);
    printf("\n");

    printf("后序遍历结果：");
    postOrder(root);
    printf("\n");

    return 0;
}