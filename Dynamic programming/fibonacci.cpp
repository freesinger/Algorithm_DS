/* 动态规划计算斐波那契数列 */

#include<iostream>
using namespace std;

int main(void)
{
    int num;

    cin >> num;
    int *fib = (int*)malloc(sizeof(int) * (num + 1));

    fib[0] = fib[1] = 1;

    for(int i = 2; i <= num; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[num] << endl;

    return 0;
}