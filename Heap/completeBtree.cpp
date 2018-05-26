/* 完全二叉树 */

#include <iostream>
using namespace std;

int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return i * 2;
}

int right(int i)
{
    return i * 2 + 1;
}

int main(void)
{
    int num;

    cin >> num;

    int tree[num + 1];

    for (int i = 1; i <= num; i++)
        cin >> tree[i];

    for (int i = 1; i <= num; i++) {
        printf("node %d: key = %d, ", i, tree[i]);
        if (parent(i) >= 1)
            printf("parent key = %d, ", tree[parent(i)]);
        if (left(i) <= num)
            printf("left key = %d, ", tree[left(i)]);
        if (right(i) <= num)
            printf("right key = %d,", tree[right(i)]);
        printf("\n");
    }

    return 0;
}