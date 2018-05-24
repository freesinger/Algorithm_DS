/* 穷举法判断满足B中元素可由A中组合得到 */

#include <stdio.h>

int num, A[20];

// 从输入值M中减去所选元素的递归函数
int solve(int i, int m)
{
    if (m == 0)
        return 1;
    if (i >= num)
        return 0;
    // 类似huffuman树的选择
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    
    return res;
}

int main(void)
{
    int q, B;

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int j = 0; j < q; j++) {
        scanf("%d", &B);
        if (solve(0, B))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}