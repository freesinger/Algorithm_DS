/* 归并排序 */

#include <iostream>
using namespace std;

#define MAX 5000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

// 整合收集
void merge(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    
    L[n1] = R[n2] = SENTINEL;

    int i = 0, j = 0;

    // L[]和R[]存储数组A的元素
    // 按升序排列
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] < R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

// 递归分割
void mergeSort(int A[], int n, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main(void)
{
    int A[MAX], n, i;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    mergeSort(A, n, 0, n);

    for (i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}