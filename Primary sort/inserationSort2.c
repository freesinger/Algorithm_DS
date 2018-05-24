#include <stdio.h>

void trace(int A[], int N)
{
    int i;

    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void inserationSort(int A[], int N)
{
    int i, j, v;

    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(void)
{
    int N, i;
    int A[100];

    printf("Enter number(0 ~ 100): ");
    scanf("%d", &N);

    printf("Enter %d integers: ", N);
    for (i = 0; i < N; i++) 
        scanf("%d", &A[i]);

    trace(A, N);
    inserationSort(A, N);
    
    return 0;
}