#include <stdio.h>
#include <stdlib.h>

// --- 1. 定义单链表节点结构 ---
typedef struct LNode {
    int data;           // 数据域
    struct LNode* next; // 指针域
} LNode, * LinkList;

// --- 2. 核心算法：删除所有值为 x 的结点 ---
// 对应 image_48d97f.png 中的逻辑：使用 pre, p, q 三个指针
void DeleteX(LinkList L, int x) {
    // 根据图片要求：pre 指向头结点，p 指向首元结点
    LNode* pre = L;
    LNode* p = L->next;
    LNode* q;             // q 作为操作指针，用于释放内存

    // 遍历单链表
    while (p != NULL) {
        // 对 p 指针的数据域进行比对
        if (p->data == x) {
            q = p;               // 暂存待删除结点
            pre->next = p->next; // 将 pre 的 next 指向 p 的后继结点
            p = p->next;         // p 指向下一个结点继续遍历
            free(q);             // 释放空间
        }
        else {
            // 如果不匹配，pre 和 p 同步后移
            pre = p;
            p = p->next;
        }
    }
}

// --- 3. 辅助函数：创建带头结点的单链表 (尾插法) ---
LinkList CreateList(int arr[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* rear = L; // 尾指针
    for (int i = 0; i < n; i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
    return L;
}

// --- 4. 辅助函数：打印链表 ---
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// --- 5. 主函数：测试程序 ---
int main() {
    // 准备测试数据，假设我们要删除所有的 '2'
    system("chcp 65001");
    int data[] = { 1, 2, 3, 2, 2, 4, 5 };
    int n = sizeof(data) / sizeof(data[0]);
    int target = 2;

    // 初始化链表
    LinkList list = CreateList(data, n);

    printf("原始链表: ");
    PrintList(list);

    printf("执行操作: 删除所有值为 %d 的结点\n", target);
    DeleteX(list, target);

    printf("结果链表: ");
    PrintList(list);

    // 释放头结点内存（实际应用中应递归释放全链表）
    // 这里仅展示核心算法逻辑
    return 0;
}