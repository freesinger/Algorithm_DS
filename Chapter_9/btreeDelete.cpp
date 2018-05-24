/* 二叉搜索树删除操作 */

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *right, *left, *parent;
};

static Node *root = NULL;

Node *treeMinimum(Node *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node *getSuccessor(Node *x)
{
    if (x->right != NULL)
        return treeMinimum(x->right);
    
    // Node *y = x->parent;

}
void insert(int key)
{
    Node *cur = root;
    Node *pre;
    Node *n = (Node*)malloc(sizeof(Node));

    n->key = key;
    n->left = n->right = NULL;

    while (cur != NULL) {
        pre = cur;
        if (n->key > cur->key)
            cur = cur->right;
        else
            cur = cur->left;
    }

    n->parent = pre;

    if (pre == NULL)
        root = n;
    else
        if (pre->key > n->key)
            pre->left = n;
        else
            pre->right = n;
}

Node* find(int key)
{
    Node *cur = root;

    while (cur != NULL && cur->key != key)
        if (key > cur->key)
            cur = cur->right;
        else
            cur = cur->left;

    return cur;
}

void inOrder(Node *u)
{
    if (u == NULL) return;
    inOrder(u->left);
    cout << u->key << ' ';
    inOrder(u->right);
}

void preOrder(Node *u)
{
    if (u == NULL) return;
    cout << u->key << ' ';
    preOrder(u->left);
    preOrder(u->right);
}

int main(void)
{
    return 0;
}