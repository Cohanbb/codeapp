#ifndef __SEQLIST_DYNAMIC_H__
#define __SEQLIST_DYNAMIC_H__
#include <stdio.h>
#include <stdlib.h>

/* Definition of Dynamic Sequential List 动态顺序表的定义 */
typedef struct SeqList_dynamic {
    int *data;
    int length, maxsize;
} sqlistd;

/* Initialize Sequential List 初始化顺序表 */
void InitList(sqlistd *L);

int Empty(sqlistd L);

/* Extend Size of List 扩充顺序表容量 */
void ExtendList(sqlistd *L, int n);

/* Insert Element 插入元素 */
void InsertElem(sqlistd *L, int i, int e);

/* Delete Element 删除元素 */
void DeleteElem(sqlistd *L, int i, int *e);

/* Search Element By Value 按值查找 */
void LocateElem(sqlistd L, int *i, int e);
/* Print Sequential List 打印顺序表 */
void PrintList(sqlistd L);

/* Destroy Sequential List 销毁顺序表 */
void DestroyList(sqlistd *L);

#endif