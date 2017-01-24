#include <stdio.h>

/* selectionSort (start from 0) */
int selectionSort(int A[], int N)
{
    int i, j, minj, temp, sw = 0;

    for (i = 0; i < N - 1; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        //swap value
        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        //proc ends when i = minj
        if (i != minj)
            sw++;
    }
    return sw;
}

int main(void)
{
    int A[100], i, N, sw;

    printf("Enter number of integers: ");
    scanf("%d", &N);
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    sw = selectionSort(A, N);

    printf("Sort result: ");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("Sort numbers: %d\n", sw);

    return 0;
}