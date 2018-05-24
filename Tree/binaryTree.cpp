/* 二叉树 */

#include <iostream>
#define NIL -1
using namespace std;

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node *tree;
int *height, *depth;
int hleft, hright, num, root;

void setDepth(int n, int p)
{
    depth[n] = p;
    if (tree[n].left != NIL)
        setDepth(tree[n].left, p + 1);
    if (tree[n].right != NIL)
        setDepth(tree[n].right, p + 1);
}

int setHeight(int u)
{
    hleft = hright = 0;

    if (tree[u].left != NIL)
        hleft = setHeight(tree[u].left) + 1;
    if (tree[u].right != NIL)
        hright = setHeight(tree[u].right) + 1;

    return height[u] = (hleft > hright ? hleft : hright);
}

int getSibling(int u)
{
    if (tree[u].parent == NIL)
        return NIL;
    else if (tree[tree[u].parent].left == u)
        return tree[tree[u].parent].right;
    else
        return tree[tree[u].parent].left;
}

int countDegree(int u)
{
    int count = 0;

    if (tree[u].left != NIL)
        count++;
    if (tree[u].right != NIL)
        count++;
    
    return count;
}

void printInfo(int u)
{
    printf("node %d: ", u);
    printf("parent = %d, ", tree[u].parent);
    printf("sibling = %d, ", getSibling(u));
    printf("degree = %d, ", countDegree(u));
    printf("depth = %d, ", depth[u]);
    printf("height = %d, ", height[u]);

    if (tree[u].parent == NIL)
        cout << "root\n";
    else if (countDegree(u) == 0)
        cout << "leaf\n";
    else
        cout << "internal node\n";
}

int main(void)
{
    int id;

    cin >> num;

    tree = (Node*)malloc(num * sizeof(Node));
    height = (int*)malloc(num * sizeof(int));
    depth = (int*)malloc(num * sizeof(int));

    for (int i = 0; i < num; i++)
        tree[i].parent = tree[i].left = tree[i].right = NIL;

    for (int i = 0; i < num; i++) {
        cin >> id >> tree[id].left >> tree[id].right;
        if (tree[id].left != NIL)
            tree[tree[id].left].parent = id;
        if (tree[id].right != NIL)
            tree[tree[id].right].parent = id;
    }

    for (int i = 0; i < num; i++)
        if (tree[i].parent == NIL)
            root = i;
    
    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < num; i++)
        printInfo(i);

    free(tree);
    free(height);
    free(depth);
    
    return 0;
}