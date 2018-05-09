/* 树的遍历 */

#include <iostream>
#define NIL -1
using namespace std;

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node *tree;
static int num;

void preParse(int u)
{
    if (u == NIL)
        return;
    cout << u << ' ';
    preParse(tree[u].left);
    preParse(tree[u].right);
}

void inParse(int u)
{
    if (u == NIL)
        return;
    inParse(tree[u].left);
    cout << u << ' ';
    inParse(tree[u].right);
}

void postParse(int u)
{
    if (u == NIL)
        return;
    postParse(tree[u].left);
    postParse(tree[u].right);
    cout << u << ' ';
}

int main(void)
{
    int id, root;

    cin >> num;

    tree = (Node*)malloc(num * sizeof(Node));

    for (int i = 0; i < num; i++)
        tree[i].parent = tree[i].left = tree[i].right = NIL;

    for (int i = 0; i < num; i++) {
        cin >> id >> tree[id].left >> tree[id].right;
        tree[tree[id].left].parent = tree[tree[id].right].parent = id;
    }

    for (int i = 0; i < num; i++)
        if (tree[i].parent == NIL)
            root = i;
    
    cout << "Preorder: ";
    preParse(root);
    cout << "\nInorder: ";
    inParse(root);
    cout << "\nPostorder: ";
    postParse(root);
    cout << '\n';

    return 0;
}