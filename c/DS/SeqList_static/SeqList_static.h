#ifndef __SEQLIST_STATIC_H__
#define __SEQLIST_STATIC_H__
#include <stdio.h>

typedef struct SeqList_static sqlists;

/* Initialize Sequential List 初始化顺序表 */
void InitList(sqlists *L);

int Empty(sqlists L);

/* Insert element 插入元素 */
void InsertElem(sqlists *L, int i, int e);

/* Delete element 删除元素 */
void DeleteElem(sqlists *L, int i, int *e);

/* Search Element by Value 按值查找 */
void LocateElem(sqlists L, int *i, int e);

/* Print Sequential List 打印顺序表 */
void PrintList(sqlists L);

#endif