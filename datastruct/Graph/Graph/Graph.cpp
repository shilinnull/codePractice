//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXV 6      // 定义顶点个数 (0-5 共6个)
//#define INF 32767   // 定义无穷大
//
///* ------------------ 邻接矩阵结构定义 ------------------ */
//typedef struct {
//    int no;                     // 顶点编号
//    // 可以添加其他顶点信息
//} VertexType;
//
//typedef struct {
//    int edges[MAXV][MAXV];      // 邻接矩阵数组
//    int n, e;                   // 顶点数，边数
//    VertexType vexs[MAXV];      // 存放顶点信息
//} MGraph;
//
///* ------------------ 邻接表结构定义 ------------------ */
//typedef struct ANode {
//    int adjvex;                 // 该边的邻接点编号
//    struct ANode* nextarc;      // 指向下一条边的指针
//    int weight;                 // 权值
//} ArcNode;
//
//typedef struct VNode {
//    // 顶点信息 data 这里简化省略，直接用数组下标代表
//    ArcNode* firstarc;          // 指向第一条边
//} VNode;
//
//typedef struct {
//    VNode adjlist[MAXV];        // 邻接表头数组
//    int n, e;                   // 顶点数，边数
//} ALGraph;
//
///* ------------------ 函数声明 ------------------ */
//
//// 1. 创建图G的邻接矩阵 (根据题目图片硬编码数据)
//void CreateMat(MGraph* g) {
//    int i, j;
//    g->n = MAXV;
//    g->e = 10; // 图中有10条边
//
//    // 初始化矩阵：对角线为0，其余为INF
//    for (i = 0; i < g->n; i++) {
//        for (j = 0; j < g->n; j++) {
//            if (i == j)
//                g->edges[i][j] = 0;
//            else
//                g->edges[i][j] = INF;
//        }
//    }
//
//    // 根据题目图片手动插入边和权值
//    // 格式: g->edges[起点][终点] = 权值;
//    g->edges[0][1] = 5;
//    g->edges[0][3] = 7;
//
//    g->edges[1][2] = 4;
//
//    g->edges[2][0] = 8;
//    g->edges[2][5] = 9;
//
//    g->edges[3][2] = 5;
//    g->edges[3][5] = 6;
//
//    g->edges[4][3] = 5;
//
//    g->edges[5][0] = 3;
//    g->edges[5][4] = 1;
//}
//
//// 输出邻接矩阵
//void DispMat(MGraph g) {
//    int i, j;
//    printf("(1)图G的邻接矩阵:\n");
//    for (i = 0; i < g.n; i++) {
//        for (j = 0; j < g.n; j++) {
//            if (g.edges[i][j] == INF)
//                printf("%4s", "∞"); // 使用 ∞ 符号，如果乱码可改为 "inf"
//            else
//                printf("%4d", g.edges[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// 2. 将邻接矩阵转换为邻接表 (实现建立邻接表)
//void MatToList(MGraph g, ALGraph* G) {
//    int i, j;
//    ArcNode* p;
//
//    G->n = g.n;
//    G->e = g.e;
//
//    // 初始化邻接表头
//    for (i = 0; i < G->n; i++) {
//        G->adjlist[i].firstarc = NULL;
//    }
//
//    // 遍历矩阵创建链表
//    // 为了保持输出顺序为邻接点编号递增 (如图例所示: 1[5]->3[7])
//    // 我们需要采用尾插法，或者倒序遍历采用头插法。
//    // 这里采用倒序遍历 + 头插法，代码更简洁，且能得到正序链表。
//    for (i = 0; i < g.n; i++) {
//        for (j = g.n - 1; j >= 0; j--) {
//            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
//                p = (ArcNode*)malloc(sizeof(ArcNode));
//                p->adjvex = j;
//                p->weight = g.edges[i][j];
//                // 头插法
//                p->nextarc = G->adjlist[i].firstarc;
//                G->adjlist[i].firstarc = p;
//            }
//        }
//    }
//}
//
//// 输出邻接表
//void DispAdj(ALGraph* G) {
//    int i;
//    ArcNode* p;
//    printf("(2)图G的邻接表:\n");
//    for (i = 0; i < G->n; i++) {
//        printf("  %d: ", i);
//        p = G->adjlist[i].firstarc;
//        while (p != NULL) {
//            printf("%d[%d]→", p->adjvex, p->weight);
//            p = p->nextarc;
//        }
//        printf("^\n"); // ^ 表示 NULL
//    }
//}
//
//// 3. 销毁图G的邻接表
//void DestroyAdj(ALGraph* G) {
//    int i;
//    ArcNode* pre, * p;
//    for (i = 0; i < G->n; i++) {
//        pre = G->adjlist[i].firstarc;
//        if (pre != NULL) {
//            p = pre->nextarc;
//            while (p != NULL) {
//                free(pre);
//                pre = p;
//                p = p->nextarc;
//            }
//            free(pre);
//        }
//    }
//    printf("(3)销毁图G的邻接表\n");
//}
//
///* ------------------ 主函数 ------------------ */
//int main() {
//    MGraph g;
//    ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
//
//    // 1. 建立并输出邻接矩阵
//    CreateMat(&g);
//    DispMat(g);
//
//    // 2. 建立并输出邻接表
//    MatToList(g, G);
//    DispAdj(G);
//
//    // 3. 销毁邻接表
//    DestroyAdj(G);
//
//    // 释放ALGraph结构本身
//    free(G);
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memset

#define MAXV 6      // 顶点个数 0-5
#define INF 32767   // 定义无穷大

/* ================== 数据结构定义 ================== */

// 边节点 (Arc Node)
typedef struct ANode {
    int adjvex;             // 该边的邻接点编号
    struct ANode* nextarc;  // 指向下一条边的指针
    int weight;             // 权值
} ArcNode;

// 头节点 (Vertex Node)
typedef struct VNode {
    ArcNode* firstarc;      // 指向第一条边
} VNode;

// 邻接表图结构 (Adjacency List Graph)
typedef struct {
    VNode adjlist[MAXV];    // 邻接表头数组
    int n, e;               // 顶点数，边数
} ALGraph;

// 全局访问标记数组
int visited[MAXV];

/* ================== 辅助结构：栈和队列 ================== */

// 1. 顺序栈 (用于非递归DFS)
typedef struct {
    int data[MAXV];
    int top;
} SqStack;

void InitStack(SqStack* s) { s->top = -1; }
int StackEmpty(SqStack* s) { return (s->top == -1); }
void Push(SqStack* s, int e) { s->data[++(s->top)] = e; }
int Pop(SqStack* s, int* e) {
    if (s->top == -1) return 0;
    *e = s->data[(s->top)--];
    return 1;
}

// 2. 循环队列 (用于BFS)
typedef struct {
    int data[MAXV];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue* q) { q->front = q->rear = 0; }
int QueueEmpty(SqQueue* q) { return (q->front == q->rear); }
int EnQueue(SqQueue* q, int e) {
    if ((q->rear + 1) % MAXV == q->front) return 0; // 队满
    q->rear = (q->rear + 1) % MAXV;
    q->data[q->rear] = e;
    return 1;
}
int DeQueue(SqQueue* q, int* e) {
    if (q->front == q->rear) return 0; // 队空
    q->front = (q->front + 1) % MAXV;
    *e = q->data[q->front];
    return 1;
}

/* ================== 邻接表创建函数 (基于图数据) ================== */

// 创建图G的邻接表
void CreateALGraph(ALGraph* G) {
    int i, j;
    G->n = MAXV;
    G->e = 10; // 图中有10条边

    // 初始化邻接表头
    for (i = 0; i < G->n; i++) {
        G->adjlist[i].firstarc = NULL;
    }

    // 邻接矩阵数据 (用于方便创建)
    int M[MAXV][MAXV] = {
        {0, 5, INF, 7, INF, INF},
        {INF, 0, 4, INF, INF, INF},
        {8, INF, 0, INF, INF, 9},
        {INF, INF, 5, 0, INF, 6},
        {INF, INF, INF, 5, 0, INF},
        {3, INF, INF, INF, 1, 0}
    };

    // 遍历矩阵创建链表 (使用倒序遍历+头插法实现正序输出)
    for (i = 0; i < G->n; i++) {
        for (j = G->n - 1; j >= 0; j--) {
            if (M[i][j] != 0 && M[i][j] != INF) {
                ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = M[i][j];
                // 头插法
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
}

// 输出邻接表
void DispAdj(ALGraph* G) {
    int i;
    ArcNode* p;
    printf("图G的邻接表:\n");
    for (i = 0; i < G->n; i++) {
        printf("%d: ", i);
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            printf("%d[%d]→", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

/* ================== 图的遍历算法实现 ================== */

// (1) 深度优先遍历 (DFS) 递归算法
void DFS(ALGraph* G, int v) {
    ArcNode* p;

    printf("%d ", v);       // 访问并输出顶点
    visited[v] = 1;         // 标记已访问

    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        int w = p->adjvex;
        if (visited[w] == 0) {
            DFS(G, w);      // 递归访问未访问的邻接点
        }
        p = p->nextarc;
    }
}

// (2) 深度优先遍历 (DFS) 非递归算法
void DFS_NonRecursive(ALGraph* G, int v) {
    SqStack s;
    ArcNode* p;
    int w, u;

    // 1. 初始化
    memset(visited, 0, sizeof(visited)); // 重置访问标记
    InitStack(&s);

    printf("%d ", v);
    visited[v] = 1;
    Push(&s, v); // 起点入栈

    // 2. 循环遍历
    while (!StackEmpty(&s)) {
        Pop(&s, &u); // 栈顶元素出栈 (u为当前正在探索的顶点)

        // 遍历 u 的所有邻接点
        p = G->adjlist[u].firstarc;
        int next_found = 0; // 用于判断是否找到下一个未访问的邻接点

        while (p != NULL) {
            w = p->adjvex;
            if (visited[w] == 0) {
                printf("%d ", w);
                visited[w] = 1;

                // 关键步骤：为了模拟递归“回退”到 u，需要将 u 重新入栈
                // 然后将 w 入栈，进行下一步探索
                Push(&s, u);
                Push(&s, w);
                next_found = 1;
                break; // 找到第一个未访问邻接点 w 后，立即转向 w
            }
            p = p->nextarc;
        }

        // 如果 next_found 为 0，说明 u 的所有邻接点都已访问，
        // 此时 u 已经出栈，下次循环会弹出新的栈顶元素（即回溯后的前驱）
    }
}


// (3) 广度优先遍历 (BFS) 算法
void BFS(ALGraph* G, int v) {
    SqQueue q;
    ArcNode* p;
    int u, w;

    // 1. 初始化
    memset(visited, 0, sizeof(visited)); // 重置访问标记
    InitQueue(&q);

    printf("%d ", v);
    visited[v] = 1;
    EnQueue(&q, v); // 起点入队

    // 2. 循环遍历
    while (!QueueEmpty(&q)) {
        DeQueue(&q, &u); // 队头元素出队 (u为当前顶点)

        p = G->adjlist[u].firstarc;
        while (p != NULL) {
            w = p->adjvex;
            if (visited[w] == 0) {
                printf("%d ", w);
                visited[w] = 1;
                EnQueue(&q, w); // w 入队
            }
            p = p->nextarc;
        }
    }
}


/* ================== 主函数 ================== */
int main() {
    ALGraph G;

    // 1. 建立并输出邻接表
    CreateALGraph(&G);
    DispAdj(&G);
    printf("\n");

    // (1) 深度优先遍历 (递归)
    memset(visited, 0, sizeof(visited)); // 重置访问标记
    printf("从顶点0开始的DFS(递归算法):\n");
    DFS(&G, 0);
    printf("\n\n");

    // (2) 深度优先遍历 (非递归)
    printf("从顶点0开始的DFS(非递归算法):\n");
    DFS_NonRecursive(&G, 0);
    printf("\n\n");

    // (3) 广度优先遍历 (BFS)
    printf("从顶点0开始的BFS:\n");
    BFS(&G, 0);
    printf("\n");
    return 0;
}

