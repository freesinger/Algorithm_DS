/* 深度优先搜索(递归) */

#include<iostream>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY  1
#define BLACK 2

int num, *color, *start, *finish;
int M[N][N];
static int ttime = 0;

void dfs_visit(int u)
{
    color[u] = GRAY;
    start[u] = ++ttime;
    for (int v = 1; v <= num; v++) {
        if (M[u][v] == 0) continue;
        if (color[v] == WHITE) {
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    finish[u] = ++ttime;
}

int main(void)
{
    int degree, vertex, node;

    cin >> num;
    
    color = (int*)malloc(sizeof(int) * (num + 1));
    start = (int*)malloc(sizeof(int) * (num + 1));
    finish = (int*)malloc(sizeof(int) * (num + 1));

    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            M[i][j] = 0;

    for (int i = 1; i <= num; i++)
        color[i] = WHITE;
    
    for (int i = 1; i <= num; i++) {
        cin >> vertex >> degree;
        while (degree-- > 0) {
            cin >> node;
            M[vertex][node] = 1;
        }
    }

    for (int i = 1; i <= num; i++)
        if (color[i] == WHITE)
            dfs_visit(i);

    for (int i = 1; i <= num; i++)
        printf("%d %d %d\n", i, start[i], finish[i]);

    free(start);
    free(finish);
    free(color);

    return 0;
}