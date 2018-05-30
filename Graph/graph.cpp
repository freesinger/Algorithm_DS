/* 输出图的邻接矩阵 */

#include<iostream>
using namespace std;

int main(void)
{
    int num, degree, vertex;
    
    cin >> num;
    int M[num][num], node;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            M[i][j] = 0;
            
    for (int i = 0; i < num; i++) {
        cin >> vertex >> degree;
        while (degree > 0) {
            cin >> node;
            M[vertex - 1][node - 1] = 1;
            degree--;
        }
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            cout << M[i][j] << ' ';
        cout << endl;
    }

    return 0;
}