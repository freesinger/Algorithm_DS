/* 广度优先搜索 */

#include<iostream>
#include<queue>
using namespace std;
#define N 100
#define INFTY (1<<21)

int num;
int M[N][N], dis[N];

void bfs(int u)
{
    queue<int> Q;

    Q.push(u);
    // 距离初始化为无穷大
    for (int i = 0; i < num; i++)
        dis[i] = INFTY;

    dis[u] = 0;
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for (int i = 0; i < num; i++)
            // 判断条件防止重复入队
            if (M[top][i] == 1 && dis[i] == INFTY) {
                Q.push(i);
                dis[i] = dis[top] + 1;
            }
    }

    for (int i = 0; i < num; i++)
        printf("%d %d\n", i + 1, dis[i]);    
}

int main(void)
{
    int vertex, degree, node;
    
    cin >> num;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            M[i][j] = 0;

    for (int i = 0; i < num; i++) {
        cin >> vertex >> degree;
        while (degree-- > 0) {
            cin >> node;
            M[vertex - 1][node - 1] = 1;
        }
    }

    bfs(0);

    return 0;
}