/* 二分搜索统计相同元素个数 */

#include <stdio.h>
#include <stdbool.h>

int A[1000], n;

/* 二分搜索 */
bool binarySearch(int key)
{
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] == key) {
            return true;
        } else if (A[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return false;
}

int main(void)
{
    int q, key, sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    scanf("%d", &q);
    for (int j = 0; j < q; j++) {
        scanf("%d", &key);
        if (binarySearch(key))
            sum++;
    }

    printf("%d\n", sum);

    return 0;
}