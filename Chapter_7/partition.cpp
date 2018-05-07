/* 分割排序 */

#include <iostream>
#include <utility>
using namespace std;

int partition(int A[], int r)
{
    int x = A[r];
    // i指向数组首元素前
    int i = -1;

    // j依次向后遍历
    for (int j = 0; j < r; j++)
        if (A[j] <= x)
            swap(A[++i], A[j]);
    swap(A[i + 1], A[r]);

    // 返回基准数的数组位置
    return i + 1;
}

int main(void)
{
    int r, *s;

    cin >> r;
    s = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++)
        cin >> s[i];

    int q = partition(s, r - 1);

    for (int i = 0; i < r; i++) {
        if (i == q)
            cout << '[' << s[i] << ']' << " ";
        else
            cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}
