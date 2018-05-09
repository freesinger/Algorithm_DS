/* 二叉搜索树搜索操作 */

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

static Node *root = NULL;

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
    int num, new_num, tar_num;
    string order;
    //char *order;

    cin >> num;

    //order = (char*)malloc(10 * sizeof(char));

    for (int i = 0; i < num; i++) {
        cin >> order;
        // strcmp() declare error
        if (order == "insert") {
            cin >> new_num;
            insert(new_num);
        } else if (order[0] == 'f') {
            cin >> tar_num;
            Node *res = find(tar_num);
            if (res)
                cout << "yes\n";
            else 
                cout << "no\n";
        } else if (order[0] == 'p') {
            inOrder(root);
            cout << '\n';
            preOrder(root);
            cout << '\n';
        } 
    }

    return 0;
}