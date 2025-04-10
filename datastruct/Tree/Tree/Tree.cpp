#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"
#include <queue>


BTNode* BuyTreeNode(int x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);

    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BTNode* CreateTree()
{
    BTNode* node1 = BuyTreeNode(1);
    BTNode* node2 = BuyTreeNode(2);
    BTNode* node3 = BuyTreeNode(3);
    BTNode* node4 = BuyTreeNode(4);
    BTNode* node5 = BuyTreeNode(5);
    BTNode* node6 = BuyTreeNode(6);

    BTNode* node7 = BuyTreeNode(6);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    node2->right = node7;

    return node1;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
    if (*root == NULL)
        return;
    BinaryTreeDestory(&(*root)->left);
    BinaryTreeDestory(&(*root)->right);
    free(*root);
    *root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root) {

    return root == NULL ? 0 : 1 + (BinaryTreeSize(root->left) + BinaryTreeSize(root->right));
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BinaryTreeLeafSize(root->left)
        + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) 
        + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    BTNode* left = BinaryTreeFind(root->left, x);
    if (left)
        return left;
    BTNode* right = BinaryTreeFind(root->right, x);
    if (right)
        return right;
    return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", root->data);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%d ", root->data);
    BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    BinaryTreePostOrder(root->left);
    BinaryTreePostOrder(root->right);
    printf("%d ", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
    if (root == NULL)
        return;
    std::queue<BTNode*> q;
    q.push(root); // 入根节点

    int leveSize = 1;
    while (!q.empty())
    {
        while (leveSize--)
        {
            // 取队头数据进行打印
            BTNode* top = q.front();
            q.pop();
            printf("%d ", top->data);

            // 入左子树和右子树
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        printf("\n");
        leveSize = q.size();
    }
    printf("\n");
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root) {
    if (root == NULL)
        return false;
    std::queue<BTNode*> q;
    q.push(root); // 入根节点
    while (!q.empty())
    {
        // 取队头数据进行打印
        BTNode* top = q.front();
        q.pop();
        if (top == NULL)
            break;

        // 入左子树和右子树
        q.push(top->left);
        q.push(top->right);
    }
    
    while (!q.empty())
    {
        BTNode* top = q.front();
        q.pop();

        if (top)
            return false;
    }

    return true;
}

// 求树的高度
int TreeHeight(BTNode* root) {
    if (root == NULL)
        return 0;
    return TreeHeight(root->left) > TreeHeight(root->right) ?
        TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}
//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root) {
    if (root == NULL)
        return 0;
    int left = BinaryTreeDepth(root->left);
    int right = BinaryTreeDepth(root->right);
    return 1 + (left > right ? left : right);
}