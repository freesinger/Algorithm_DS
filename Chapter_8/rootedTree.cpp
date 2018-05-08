/* 有根树 */

#include <iostream>
using namespace std;
#define NIL -1

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node *tree;
int *depth;
static int num;

// 递归求深度
void rec(int u, int p)
{
    depth[u] = p;
    if (tree[u].left != NIL)
        rec(tree[u].left, p + 1);
    if (tree[u].right != NIL)
        rec(tree[u].right, p);
}

void printChiledren(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << tree[u].parent << ", ";
    cout << "depth = " << depth[u] << ", ";
    
    if (tree[u].parent == NIL)
        cout << "root, [";
    else if (tree[u].left == NIL)
        cout << "leaf, [";
    else
        cout << "internal node, [";

    int c;
    for (int i = 0, c = tree[u].left; c != NIL; i++, c = tree[c].right) {
        if (i) cout << ", ";
        cout << c;
    }
    /* for (int i = 0; i < num; i++)
        if (tree[i].parent == u)
            cout << i << ','; */
    cout << ']' << endl;
}

int main(void)
{
    int id, degree, *elem, root;
    cin >> num;

    tree = (Node*)malloc(num * sizeof(Node));
    depth = (int*)malloc(num * sizeof(int));

    // 初始化所有节点
    for (int i = 0; i < num; i++)
        tree[i].parent = tree[i].left = tree[i].right = NIL;

    for (int i = 0; i < num; i++) {
        cin >> id >> degree;
        elem = (int*)malloc(degree * sizeof(int));
        for (int j = 0; j < degree; j++) {
            cin >> elem[j];
            if (j == 0) {
                tree[id].left = elem[j];
                tree[elem[j]].parent = id; 
            } else {
                tree[elem[j - 1]].right = elem[j];
                tree[elem[j]].parent = id;
            }
        }
        free(elem);
    }
    
    // 寻找根节点
    for (int i = 0; i < num; i++)
        if (tree[i].parent == NIL)
            root = i;
    
    rec(root, 0);

    for (int i = 0; i < num; i++)
        printChiledren(i);

    free(tree);
    free(depth);

    return 0;
}