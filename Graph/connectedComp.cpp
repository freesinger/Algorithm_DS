/* 连通分量判断朋友关系 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAX 100
#define NIL -1

// 有MAX个顶点的图的邻接表
vector<int> G[MAX];
int num;
int color[MAX];

void dfs(int r, int c)
{
    stack<int> S;
    S.push(r);
    color[r] = c;

    while (!S.empty()) {
        int u = S.top();
        S.pop();
        
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (color[v] == NIL) {
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor(void)
{
    int id = 1;

    for (int i = 0; i < num; i++)
        color[i] = NIL;
    for (int i = 0; i < num; i++)
        if (color[i] == NIL)
            dfs(i, id++);
}

int main(void)
{
    int rel, f1, f2, que;

    cin >> num >> rel;

    for (int i = 0; i < rel; i++) {
        cin >> f1 >> f2;
        //  从顶点f1向顶点f2画边
        G[f1].push_back(f2);
        G[f2].push_back(f1);
    }

    assignColor();

    cin >> que;

    for (int i = 0; i < que; i++) {
        cin >> f1 >> f2;
        if (color[f1] == color[f2])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}