/* 计数排序（桶排序）*/

#include <iostream>
#define MAX 200
using namespace std;

int main(void)
{
    int num, C[MAX];

    cin >> num;

    int *A = (int*)malloc(num * sizeof(int));
    int *B = (int*)malloc(num * sizeof(int));
    
    for (int i = 0; i < num; i++)
        cin >> A[i];

    for (int i = 0; i < num; i++)
        C[A[i]]++;

    for (int i = 1; i < num; i++)
        C[i] = C[i] + C[i - 1];

    for (int i = 0; i < num; i++)
        B[--C[A[i]]] = A[i];   

    for (int i = 0; i < num; i++)
        cout << B[i] << ' ';
    cout << endl;

    return 0;
}