#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using namespace std;

#define Maxsize 50

typedef struct {
	int data[Maxsize];
	int length;
}SqList;

//删除相同元素
SqList DelSameElem(SqList& L1, SqList& L2) {
	//新建临时顺序表TempList,用来存储普通情况的合并元素
	SqList TempList;
	//判断两个有序顺序表是否可以直接拼接
	if (L1.data[L1.length - 1] <= L2.data[0]) {
		int templen = L1.length;
		for (int i = 0; i < L2.length; i++) {
			L1.length++;
			L1.data[templen + i] = L2.data[i];
		}
		return L1;
	}
	else if (L1.data[0] > L2.data[L2.length - 1]) {
		int templen = L2.length;
		for (int i = 0; i < L1.length; i++) {
			L2.length++;
			L2.data[templen + i] = L1.data[i];
		}
		return L2;
	}
	//普通情况，将两有序顺序表逐个元素比较大小并合并进新表TempList
	else {
		int i = 0, j = 0, z = 0;
		while (i < L1.length && j < L2.length) {
			if (L1.data[i] >= L2.data[j]) {
				TempList.data[z] = L2.data[j];
				j++;
				z++;
				TempList.length++;
			}
			else {
				TempList.data[z] = L1.data[i];
				i++;
				z++;
				TempList.length++;
			}
		}
		//将循环后残留有元素
		while (i < L1.length) {
			TempList.length++;
			TempList.data[z++] = L1.data[i++];
		}
		while (j < L2.length) {
			TempList.length++;
			TempList.data[z++] = L2.data[j++];
		}
		return TempList;
	}
	
}

int main()
{
	
	SqList List1, List2;
	printf("输入数组L1大小");
	scanf("%d", &List1.length);
	for (int i = 0; i < List1.length; i++) {
		scanf("%d", &List1.data[i]);
	}

	printf("输入数组L2大小");
	scanf("%d", &List2.length);
	for (int i = 0; i < List2.length; i++) {
		scanf("%d", &List2.data[i]);
	}
	SqList temp = DelSameElem(List1, List2);

	for (int i = 0; i < temp.length; i++) {
		printf("%d", temp.data[i]);
		printf(" "); 
	}
	return 0;
}
