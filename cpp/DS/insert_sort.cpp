#include <stdio.h>

/*Insert Sort 直接插入排序*/
void insert_sort(int a[], int n) {
    //Differing from other algorithms, insert sorting deals with a[1] ~ a[n] 
    int i, j;
    for (i = 2; i <= n; i++)
        if (a[i] < a[i - 1]) {
            a[0] = a[i];
            for (j = i - 1; a[0] < a[j]; j--) //find the position to insert
                a[j + 1] = a[j]; //move backwards to making room for inserting
            a[j + 1] = a[0]; //insert the element
        }
}

/*Binary Insert Sort 折半插入排序*/
void insert_sortt(int a[], int n) {
    int low, high, mid, i, j;
    for (i = 2; i <= n; i++) {
        low = 1; 
        high = i - 1;
        a[0] = a[i];
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] > a[0])
                high = mid - 1; 
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--) 
            a[j + 1] = a[j];
        a[high + 1] = a[0];
    }
}

/*Shell Sort 希尔排序*/
void shell_sort(int a[], int n) {
    
}


int main() {
    int a[11];
    for (int i = 1; i < 11; i++)
        scanf("%d", &a[i]);
    insert_sort(a, 10);
    for (int i = 1; i < 11; i++) {
        printf("Insert Sort: \n");
        printf("%d\n", a[i]);
    }
    insert_sortt(a, 10);
    for (int i = 1; i < 11; i++) {
        printf("Binary Insert Sort: \n");
        printf("%d\n", a[i]);
    }
    shell_sort(a, 10);
    for (int i = 1; i < 11; i++) {
        printf("Shell Sort: \n");
        printf("%d\n", a[i]);
    }
    return 0;
}

