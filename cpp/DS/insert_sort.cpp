#include <stdio.h>

/*Insert Sort 直接插入排序*/
void insert_sort(int a[], int n) {
    int temp, i, j; //temp conserves element temporarily
    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1]) {
            temp = a[i];
            for (j = i - 1; j >= 0 && temp < a[j]; j--) //find the position to insert
                a[j + 1] = a[j]; //move backwards to making room for inserting
            a[j + 1] = temp; //insert the element
        }
}

/*Binary Insert Sort 折半插入排序*/
void insert_sortt(int a[], int n) {
    int low, high, mid, temp, i, j; //step is length of per comparison
    for (i = 1; i < n; i++) {
        low = 0;
        high = i - 1;
        temp = a[i];
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] > temp)
                high = mid - 1; 
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--) 
            a[j + 1] = a[j];
        a[high + 1] = temp;
    }
}

/*Shell Sort 希尔排序*/
void shell_sort(int a[], int n) {
    int step, temp, i, j;
    for (step = n/2; step >= 1; step /= 2)
        for (i = step; i < n; i++) 
            if (a[i] < a[i - step]) {
                temp = a[i];
                for (j = i - step; j >= 0 && temp < a[j]; j -= step)
                    a[j + step] = a[j];
                a[j + step] = temp;
            }
}


int main() {
    int a[11];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    insert_sort(a, 10);
    printf("Insert Sort: \n");
    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);

    insert_sortt(a, 10);
    printf("Binary Insert Sort: \n");
    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);

    shell_sort(a, 10);
    printf("Shell Sort: \n");
    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    return 0;
}

