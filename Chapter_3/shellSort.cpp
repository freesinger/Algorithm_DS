#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long cnt;
int l, A[1000000], n;
vector<int> G;

//insertSort in a step of g
void insertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g]  = v;
    }
}

void shellSort(int A[], int n)
{
    //generate the struct G
    int h = 1;
    while (h <= n) {
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--)
        //in reverse make G[i] = g
        insertionSort(A, n, G[i]);
}

int main(void)
{
    cout << "Enter number of integers: ";
    cin  >> n;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, n);

    cout << "Size: " << G.size() << endl;
    cout << "Step values: ";
    for (int i = G.size() - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i) 
            printf(" ");
    }
    printf("\n");
    
    printf("Count times: %lld\n", cnt);

    cout << "Sort result: ";
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}