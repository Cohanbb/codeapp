#include <stdio.h>

/*Bubble Sort 冒泡排序*/
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0; //set initial flag = 0
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                flag = 1; //set flag = 1 while swapping
            }
        if (flag == 0) //flag = 0 for no swapping happened
            return;
   }
}

/*Quick Sort 快速排序
void quick_sort(int a[], int low, int high) {

}

int Partition(int a[], int low, int high) {


}
*/

int main() {
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    return 0;
}
