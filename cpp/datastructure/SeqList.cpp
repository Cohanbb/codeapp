#include <stdio.h>
#define Maxsize 20

typedef struct SeqList {
    int length;
    int data[Maxsize];
} sqlist;

void InitList(sqlist &L) {
    for (int i = 0; i < Maxsize; i++)
       L.data[i] = 0;
    L.length = 0;
}

bool Empty(sqlist L) {
    if (L.length == 0)
        return true;
    return false;
}

void Insert(sqlist &L, int i, int e) {
    if (i <= 0 || i > L.length+1) {
        printf("Invalid Input!\n");
	return;
    }
    if (L.length == Maxsize) {
	printf("Oversize!");
        return;
    }
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
}

void Delete(sqlist &L, int i, int &e) {
    if (i <= 0 || i > L.length) {
        printf("Invalid Input!");
	return;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++)
	L.data[j-1] = L.data[j];
    L.data[L.length] = 0;
    L.length--;
}

void Printlist(sqlist L) {
    for (int i = 1; i <= L.length; i++) 
	printf("%d \n", L.data[i-1]);
}

int main() {
   sqlist list;
   InitList(list);
   Insert(list, 1, 1);
   Insert(list, 2, 3);
   Printlist(list);
}
