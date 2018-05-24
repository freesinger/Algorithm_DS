/* 线性搜索统计重复元素个数 */

#include <stdio.h>

// 线性搜索
int linearSearch(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;
    while (A[i] != key)
        i++;
    return i != n;
}

int main(void)
{
    int A[10000+1], n, p, key, sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &key);
        if (linearSearch(A, n, key))
            sum++;
    }

    printf("%d\n", sum);

    return 0;
}