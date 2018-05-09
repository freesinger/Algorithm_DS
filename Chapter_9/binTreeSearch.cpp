/* 二叉搜索树 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;
 
void insert(int key)
{
    Node *cur = root;
    Node *pre = NIL;
    Node *n = (Node*)malloc(sizeof(Node));

    n->key = key;
    n->left = n->right = NIL;

    while (cur != NIL) {
        // save previous node as parent node
        pre = cur;
        if (n->key > cur->key)
            cur = cur->right;
        else
            cur = cur->left;
    }

    n->parent = pre;

    // set root
    if (pre == NIL)
        root = n;
    else
        if (pre->key > n->key)
            pre->left = n;
        else
            pre->right = n;
}

void inOrder(Node *u)
{
    if (u == NIL) return;
    inOrder(u->left);
    cout << u->key << ' ';
    inOrder(u->right);
}

void preOrder(Node *u)
{
    if (u == NIL) return;
    cout << u->key << ' ';
    preOrder(u->left);
    preOrder(u->right);
}

int main(void)
{
    int num, new_number;
    char order;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> order;
        if (order == 'i') {
            cin >> new_number;
            insert(new_number); 
        } else if (order == 'p') {
            inOrder(root);
            cout << '\n';
            preOrder(root);
            cout << '\n';
        }
    }

    return 0;
}