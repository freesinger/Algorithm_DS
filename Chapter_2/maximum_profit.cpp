#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 200000;

int main (void)
{
    int R[MAX], n;

    cout << "Enter number you want insert: ";
    cin >> n;
    cout << "Insert numbers: ";
    for (int i = 0; i < n; i++)         //mark
        cin >> R[i];
    
    int maxv = -2000000000;
    int minv = R[0];

    for (int i = 1; i < n; i++) {       //start from i = 1
        maxv = max(maxv, R[i] - minv);  //update maxv
        minv = min(minv, R[i]);         //update minv
    }

    cout << "Maxmium profit: " << maxv <<endl;

    return 0;
}