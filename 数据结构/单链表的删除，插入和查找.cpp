#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//定义单链表结构结点
typedef struct LNode {
	int data;               //数据域
	struct LNode* next;     //指针域
}LNode,*LinkList;

//初始化单链表
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode)); //分配头结点
	if (L == NULL) return false;       //内存分配失败
	L->next = NULL;                    //头结点之后暂时没有结点
	return true;
}

//查找：按值查找值为e的结点
LNode* locateElem(LinkList L, int e) {
	LNode* p = L->next;   //从第一个有效数据结点开始查找
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p; //找到则返回指针，否则返回NULL
}

//插入：在第i个位置插入值为e的结点
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1) return false;
	LNode* p = L; //p指向头结点（第0个位置）
	int j = 0;
	//找到第i-1个结点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) return false; //i超出链表范围
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false; //内存分配失败
	s->data = e;
	s->next = p->next; 
	p->next = s;
	return true;
}

//删除：删除第i个结点，并用e返回其值
bool ListDelete(LinkList& L, int i, int& e) {
	if (i < 1) return false;
	LNode* p = L;
	int j = 0;
	//找到第i-1个结点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) return false; //找不到第i个结点

	LNode* q = p->next; //q指向被删除结点
	e = q->data;        //保存被删除的数据
	p->next = q->next;  //将前驱结点指向第i+1个结点
	free(p);            //释放内存
	return true;
}

//打印链表
void PrintList(LinkList L) {
	LNode* p = L->next;
	printf("当前链表内容：\n");
	while (p != NULL) {
		printf("当前链表内容:");
		p = p->next;
	}
	printf("NULL\n");
}

int main() {
	
	system("chcp 65001");
	LinkList L;
	if (InitList(L)) {
		printf("单链表初始化成功！\n");
	}

	// 1. 插入演示
	ListInsert(L, 1, 10); // 插入 10
	ListInsert(L, 2, 20); // 插入 20
	ListInsert(L, 1, 5);  // 在第1个位置前插入 5，现在是 5, 10, 20
	PrintList(L);

	// 2. 查找演示
	int searchVal = 10;
	LNode* res = locateElem(L, searchVal);
	if (res) {
		printf("查找成功：找到值为 %d 的结点\n", res->data);
	}
	else {
		printf("查找失败：未找到值为 %d 的结点\n", searchVal);
	}

	// 3. 删除演示
	int deletedVal;
	if (ListDelete(L, 2, deletedVal)) { // 删除第2个位置（即10）
		printf("成功删除第2个位置的元素，值为: %d\n", deletedVal);
	}
	PrintList(L);

	return 0;
}