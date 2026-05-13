//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//using namespace std;
//
//#define MAXSIZE 100
//
//typedef struct {
//	int data[MAXSIZE];
//	int length;
//}SeqList;
//
////输出顺序表
//void PrintList(SeqList L) {
//	printf("顺序表元素为：\n");
//	for (int i = 0; i < L.length; i++) {
//		printf("&d", L.data[i]);
//	}
//	printf("\n");
//}
//
////查找元素
//void SearchElement(SeqList L,int key) {
//	for (int i = 0; i < L.length; i++) {
//		if (L.data[i] == key) {
//			printf("插入位置不合法！\n");
//			return;
//		}
//		printf("无此元素!\n");
//	}
//}
//
//
////插入元素
//void InsertElement(SeqList* L, int pos, int value) {
//	//判断位置是否合法
//	if (pos< 1 || pos > L->length + 1) {
//		printf("插入位置不合法\n");
//		return;
//	}
//	//元素后移
//	for (int i = L->length; i >= pos; i--) {
//		L->data[i] = L->data[i - 1];
//	}
//
//	//插入新元素
//	L->data[pos - 1] = value;
//	L->length++;
//	printf("插入成功！\n");
//}
//
////删除元素
//void DeleteElement(SeqList* L, int pos) {
//	//判断位置是否合法
//	if (pos < 1 || pos > L->length) {
//		printf("删除位置不合法！\n");
//		return;
//	}
//	int deleted = L->data[pos - 1];
//	//元素前移
//	for (int i = pos - 1; i < L->length - 1; i++) {
//		L->data[i] = L->data[i + 1];
//		
//	}
//	L->length--;
//	printf("删除成功！删除元素为：%d\n", deleted);
//}
//
//int main() {
//	SeqList L;
//	L.length = 10;
//	srand(time(NULL));
//
//	//随机生成10个整数
//	for (int i = 0; i < 10; i++) {
//		L.data[i] = rand() % 100;
//	}
//	//输出顺序表
//	PrintList(L);
//	//查找元素
//	int key;
//	printf("请输入要查找的元素：");
//	scanf("%d", &key);
//
//	SearchElement(L, key);
//	//插入元素
//	int pos, value;
//	printf("请输入插入位置：");
//	scanf("%d", &pos);
//
//	printf("请输入插入元素：");
//	scanf("%d", &value);
//
//	InsertElement(&L, pos, value);
//
//	PrintList(L);
//
//	// 删除元素
//	printf("请输入删除位置：");
//	scanf("%d", &pos);
//
//	DeleteElement(&L, pos);
//
//	PrintList(L);
//
//	return 0;
//}