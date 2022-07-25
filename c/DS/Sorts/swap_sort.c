#include "Sorts.h"

/* Bubble Sort 冒泡排序 */
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int flag = 0; //set initial flag = 0
        for (int j = n - 1; j > i; --j)
            if (a[j - 1] > a[j]) {
                int tp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tp;
                flag = 1; // set flag = 1 while swapping
            }
        if (flag == 0) // flag = 0 for no swapping happened
            return;
   }
}

/* Quick Sort 快速排序 */
void quick_sort(int a[], int low, int high) {
    if (low > high) 
        return;
    int i = low;
    int j = high;
    int temp = a[low];
    while (i < j) {
        while (i < j && a[j] >= temp)
            --j;
        while (i < j && a[i] <= temp)
            ++i;
        if (i < j) {
            int tp = a[i];
            a[i] = a[j];
            a[j] = tp;
        }
    }
    a[low] = a[i];
    a[i] = temp;
    quick_sort(a, low, i - 1);
    quick_sort(a, i + 1, high);
}

void showarray(int a[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d\n", a[i]);
}

int main() {
    int a[10];
    for (int i = 0; i < 10; ++i)
        scanf("%d", &a[i]);

    bubble_sort(a, 10);
    printf("Bubble Sort: \n");
    showarray(a,10);

    quick_sort(a, 0, 9);
    printf("Quick Sort: \n");
    showarray(a,10);
    return 0;
}
