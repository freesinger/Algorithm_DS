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
    
    Node *y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
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

void treeDelete(Node *z)
{   
    // 删除的对象
    Node *tar;       
    Node *tarChild;

    // 确定要删除的节点
    if (z->left == NULL && z->right == NULL)
        tar = z;
    else
        tar = getSuccessor(z);

    // 确定tar的子节点
    if (tar->left != NULL)
        tarChild = tar->left;
    else
        tarChild = tar->right;

    if (tarChild != NULL)
        tarChild->parent = tar->parent;
    
    if (tar->parent == NULL)
        root = tar;
    else {
        if (tar == tar->parent->left)
            tar->parent->left = tarChild;
        else
            tar->parent->right = tarChild;
    }

    if (tar != z)
        z->key = tar->key;
    
    free(tar);
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
    int num, tar;
    string com;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> com;
        if (com[0] == 'f') {
            cin >> tar;
            Node *tem = find(tar);
            if (tem != NULL)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        } else if (com[0] == 'i') {
            cin >> tar;
            insert(tar);
        } else if (com[0] == 'p') {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        } else if (com[0] == 'd') {
            cin >> tar;
            treeDelete(find(tar));
        }
    }

    return 0;
}