#include <stdio.h>

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            return;
   }
}

void quick_sort(int a[], int n) {

}

void select_sort(int a[], int n) {

}

void insertion_sort(int a[], int n) {

}

void shell_sort(int a[], int n) {

}

void merge_sort(int a[], int n) {

}

int main() {
    int a[2] = {1,2};
    quick_sort(a, 2);
    printf("%d\n", a[0]);
    return 0;
}
