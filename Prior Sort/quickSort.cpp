/* 快速排序 */

#include <iostream>
#include <utility>
#include <stdlib.h>
#define MAX 10000
#define SENTINEL 200000
using namespace std;

typedef struct {
    char suit;
    int value;
} Card;

Card Left[MAX / 2 + 2], Right[MAX / 2 + 2];

void merge(Card A[], int n, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left;
    int n2 = right = mid;

    for (int i = 0; i < n1; i++)
        Left[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        Right[i] = A[mid + i];

    Left[n1].value = Right[n2].value = SENTINEL;

    i = j = 0;
    for (k = left; k < right; k++) {
        if (Left[i].value < Right[j].value)
            A[k] = Left[i++];
        else
            A[k] = Right[i++];
    }
}

void mergeSort(Card A[], int n, int left, int right)
{
    int mid; 
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(Card A[], int n, int p, int r)
{
    int i, j;
    Card t, x;
    x = A[r];
    i = p - 1;
    
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value)
            swap(A[++i], A[j]);
    }
    swap(A[i + 1], A[r]);

    return i + 1;
}

void quickSort(Card A[], int n, int p, int r)
{
    int q;
    if (p < r) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q + 1, r);
    }
}

int main(void)
{
    int n, i, v;
    Card A[MAX], B[MAX];
    char S[10];
    bool stable;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> S >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    for (i = 0; i < n; i++)
        // 比较归并快排的结果
        if (A[i].suit != B[i].suit)
            stable = false;

    if (stable)
        printf("Stable\n");
    else
        printf("Not stable\n");

    for (i = 0; i < n; i++)
        cout << B[i].suit << ' ' << B[i].value << endl;

    return 0;
}