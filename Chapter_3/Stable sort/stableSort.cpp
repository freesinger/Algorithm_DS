#include <iostream>
#include "stable_sort.h"
using namespace std;

void print (struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        if (i > 0)
            cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

bool isStable (struct Card C1[], struct Card C2[], int N)
{
    for (int i = 0; i < N; i++) {
        if (C1[i].suit != C2[i].suit)
            return false;
    }
    return true;
}

int main (void)
{
    Card C1[100], C2[100];
    int N;

    cout << "Enter number you wanna input: ";
    cin >> N;
    cout << "Enter " << N << " cards: ";
    for (int i = 0; i < N; i++) {
        cin >> C1[i].suit >> C1[i].value;
    }

    for (int i = 0; i < N; i++)
        C2[i] = C1[i];

    bubble(C1, N);
    selection(C2, N);

    cout << "BubbleSort result: ";
    print(C1, N);
    cout << "Stable" << endl;

    cout << "SelectionSort result: ";
    print(C2, N);
    if (isStable(C1, C2, N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not Stable" << endl;
    }

    return 0;
}