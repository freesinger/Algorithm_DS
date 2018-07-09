/* 单源最短路径 */

#include<iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int num;
int color[MAX];
int dis[MAX];
int M[MAX][MAX];

void dijkstra(void)
{
    int mincost, tem;
    dis[0] = 0;
    color[0] = GRAY;

    while (1) {
        mincost = INFTY;
        for (int i = 0; i < num; i++)
            if (dis[i] < mincost && color[i] != BLACK) {
                tem = i;
                mincost = dis[i];
            }
        
        if (mincost == INFTY)
            break;
        
        color[tem] = BLACK;

        // 循环处理更新
        for (int i = 0; i < num; i++)
            if (color[i] != BLACK && M[tem][i] != INFTY)
                if (dis[tem] + M[tem][i] < dis[i]) {
                    dis[i] = dis[tem] + M[tem][i];
                    color[i] = GRAY;
                }
        // 处理完后每个顶点存储着最短成本
    }

    for (int i = 0; i < num; i++)
        cout << i << ' ' << (dis[i] == INFTY ? -1 : dis[i]) << endl;
}

int main(void)
{
    cin >> num;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            color[i] = WHITE;
            dis[i] = INFTY;
            M[i][j] = INFTY;
        }

    int node, degree, next, value;

    for (int i = 0; i < num; i++) {
        cin >> node >> degree;
        for (int j = 0; j < degree; j++) {
            cin >> next >> value;
            M[i][next] = value;
        }
    }

    dijkstra();

    return 0;
}