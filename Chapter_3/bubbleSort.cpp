#include <iostream>
using namespace std;

//bubbleSort using flag
int bubbleSort(int A[], int N)
{
    int sw = 0;
    bool flag = 1;
    //use i to count numbers sorted 
    for(int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                //swap value
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main(void)
{
    int A[100], N, sw;

    cout << "Input number of integers: ";
    cin >> N;
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sw = bubbleSort(A, N);

    cout << "Bubblesort result: ";
    for (int i = 0; i < N; i++)
        //if (i) cout << " ";
        cout << A[i] << " ";
    cout << endl;
    cout << "Sort numbers: " << sw << endl;

    return 0;
}