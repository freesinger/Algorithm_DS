/* 分割排序 */

#include <iostream>
#include <utility>
using namespace std;

int partition(int A[], int r)
{
    int x = A[r];
    int i = -1;
    for (int j = 0; j < r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
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
