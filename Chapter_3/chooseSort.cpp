#include <stdio.h>

#define N 20

void choose_sort(int *p, int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (*(p + j) < *(p + i)) {
                temp = *(p + j);
                *(p + j) = *(p + i);
                *(p + i) = temp;
            }
}

int main(void)
{
    int array[N], *pointer, input;

    printf("Enter %d integers: ", N);
    
    for (int i = 0; i < N; i++)
        scanf("%d", &array[i]);   //scanf("%d", p++);
    
    /* for (pointer = array; pointer < array + N; pointer++)
            scanf("%d", pointer); */

    pointer = array;  // pointer must be pointed to the array here

    choose_sort(pointer, N);

    printf("Sorted array: ");
    for (pointer = array; pointer < array + N; pointer++)
        printf("%d ", *pointer);
    printf("\n");

    return 0;
}