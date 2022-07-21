#ifndef __LINKLIST_H
#define __LINKLIST_H

typedef struct LNode lnode;
typedef struct LNode *linklist;

/* Initialize Link List 初始化链表 */
void InitList(linklist *L);

/* Empty or not 判断链表是否为空  */
int Empty(linklist L);

/* Search Element by Position 按位查找 */
lnode *GetElem(linklist L, int i);

/* Insert node 插入节点 */
void InsertElem(linklist *L, int i, int e);

/* Delete node 删除节点 */
void DeleteElem(linklist *L, int i, int *e);

/* Search Element by Value 按值查找 */
lnode *LocateElem(linklist L, int e);

/* Print Link List 打印链表 */
void PrintList(linklist L);

/* Destroy Link List 销毁链表 */
void DestroyList(linklist *L);

#endif