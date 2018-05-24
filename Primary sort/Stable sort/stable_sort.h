#ifndef STABLE_SORT_H
#define STABLE_SORT_H

struct Card {
    char suit, value;
};

void bubble (struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 1; j--) {
            if (A[j].value < A[j - 1].value) {
                Card t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
        }
    }
}

void selection (struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j].value < A[j - 1].value)
                minj = j;
        }
        Card t = A[i];
        A[i] = A[minj];
        A[minj] = t;
    }
}

#endif