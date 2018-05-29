/* 求解最长公共子序列 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static const int N = 100;

int lcs(string X, string Y)
{
    int c[N + 1][N + 1];
    int x = X.size();
    int y = Y.size();
    int maxlen = 0;

    X = ' ' + X;
    Y = ' ' + Y;
    for (int i = 0; i <= x; i++)
        c[i][0] = 0;
    for (int j = 0; j <= y; j++)
        c[0][j] = 0;
    
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
            maxlen = max(maxlen, c[i][j]);
        }
    }

    return maxlen;
}

int main(void)
{
    string s1, s2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }

    return 0;
}