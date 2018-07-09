/* 使用优先级队列实现dijkstra算法 */

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int num;
vector<pair<int, int> > adj[MAX]; // 有向加权图的邻接表表示

void dijkstra(void)
{
    priority_queue<pair<int, int> > PQ;
    int color[MAX];
    int dis[MAX];
    for (int i = 0; i < num; i++) {
        dis[i] = INFTY;
        color[i] = WHITE;
    }

    dis[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;

    while (!PQ.empty()) {
        pair<int, int> f = PQ.top();
        PQ.pop();
        int tem = f.second;

        color[tem] = BLACK;

        // 取出最小值，若不是最短路径则忽略
        if (dis[tem] < f.first * (-1))
            continue;

        for (int i = 0; i < adj[tem].size(); i++) {
            int v = adj[tem][i].first;
            if (color[v] == BLACK) continue;
            if (dis[v] > dis[tem] + adj[tem][i].second) {
                dis[v] = dis[tem] + adj[tem][i].second;
                // 优先级队列有限比较最大值 需要转为负值
                PQ.push(make_pair(dis[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }

    for (int i = 0; i < num; i++)
        cout << i << ' ' << (dis[i] == INFTY ? -1 : dis[i]) << endl;
}

int main(void)
{
    cin >> num;

    int node, degree, next, value;

    for (int i = 0; i < num; i++) {
        cin >> node >> degree;
        for (int j = 0; j < degree; j++) {
            cin >> next >> value;
            adj[node].push_back(make_pair(next, value));
        }
    }

    dijkstra();

    return 0;
}