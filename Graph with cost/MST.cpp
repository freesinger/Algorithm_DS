/* 最小生成树 */

#include<iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int num, M[MAX][MAX];

int prim(void)
{
    int color[MAX];
    int dist[MAX];   // 记录连接点集与非点集边中权值最小的值
    int parent[MAX];

    for (int i = 0; i < num; i++) {
        color[i] = WHITE;
        dist[i] = INFTY;
        parent[i] = 0;
    }

    dist[0] = 0;
    parent[0] = -1;
    int tem;

    while (1) {
        int mincost = INFTY;
        // 寻找顶点tem，tem与点集里点距离最小
        for (int i = 0; i < num; i++)
            if (color[i] != BLACK && dist[i] < mincost) {
                mincost = dist[i];
                tem = i;
            }

        // 最后一个点时距离为INFITY跳出循环
        if (mincost == INFTY)
            break;
        
        color[tem] = BLACK;

        // 给与点集相接的顶点赋值和父节点
        for (int i = 0; i < num; i++)
            if (color[i] != BLACK && M[tem][i] != INFTY)
                if (M[tem][i] < dist[i]) {
                    dist[i] = M[tem][i];
                    parent[i] = tem;
                    color[i] = GRAY;
                }
    }

    int sum = 0;
    for (int i = 0; i < num; i++)
        if (parent[i] != -1)
            sum += M[i][parent[i]];

    return sum;
}

int main(void)
{
    cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            int distance;
            cin >> distance;
            M[i][j] = (distance == -1) ? INFTY : distance;
        }
    }

    // 输出最小生成树的各边权值和
    cout << prim() << endl;

    return 0;
}