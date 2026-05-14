#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

// 定义顺序表结构
typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

/**
 * 从有序顺序表中删除重复元素
 * 对应图片 image_c018bc.png 中的算法逻辑
 */
bool Delete_Duplicate(SeqList* L) {
    if (L->length == 0) return false;

    int i = 0; // 慢指针：指向非重复序列的末尾

    // j 是快指针，从第二个元素开始扫描
    for (int j = 1; j < L->length; j++) {
        // 如果发现当前元素与慢指针指向的元素不同
        if (L->data[j] != L->data[i]) {
            i++;               // 慢指针后移一位
            L->data[i] = L->data[j]; // 将新元素复制到该位置
        }
    }

    // 更新表的长度
    L->length = i + 1;
    return true;
}

// 打印顺序表
void PrintList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    // 初始化一个有序顺序表，包含重复值（如图片所示：1, 2, 2, 3, 4, 4, 5）
    SeqList L = { {1, 2, 2, 3, 4, 4, 5}, 7 };

    printf("原始顺序表: ");
    PrintList(L);

    if (Delete_Duplicate(&L)) {
        printf("去重后顺序表: ");
        PrintList(L);
        printf("当前表长度: %d\n", L.length);
    }
    else {
        printf("顺序表为空，无需操作。\n");
    }

    return 0;
}