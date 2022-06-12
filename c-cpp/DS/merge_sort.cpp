#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*非递归实现归并排序*/
void merge_sort(int a[], int n) {
    int len1, len2, i, j, k;
    int *t;
    int step = 1;
    int *p = a;
    int *q = (int *)malloc(sizeof(int *) * n);
    int *temp = q;
    while (step < n) {
        i = 0;
        j = i + step;
        k = i;
        len1 = i + step < n ? i + step : n;
        len2 = j + step < n ? j + step : n;
        while (i < n) {
            while (i < len1 && j < len2) 
                q[k++] = p[i] < p[j] ? p[i++] : p[j++];
            while (i < len1)
                q[k++] = p[i++];
            while (j < len2)
                q[k++] = p[j++];
            i = j;
            j = i + step;
            k = i;
            len1 = i + step < n ? i + step : n;
            len2 = j + step < n ? j + step : n;
        }
        step *= 2;
        t = p;
        p = q;
        q = t;
    }
    if (a != p)
        memcpy(a, p, sizeof(int *) * n);
    free(temp);
}

void showarray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 10);
    printf("Merge Sort: \n");
    showarray(a, 10);
    return 0;
}