/* 双向链表插入删除 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next, *prev;
} Node;

Node *head;

// 搜索特定元素
Node* listSearch(int key)
{
    /* 头结点不存储元素 */
    Node *cur = head->next;
    while (cur != NULL && cur->key != key)
        cur = cur->next;
    return cur;
}

// 初始化双链表
void init(void)
{
    // 双向链表头结点前后指针都指向自己
    head = (Node *)malloc(sizeof(Node));
    head->next = head;
    head->prev = head;
}

void printList(void)
{
    Node *cur = head->next;
    int isf = 0;
    while (1) {
        if (cur == head) break;
        if (isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *t)
{
    // 头结点不作处理
    if (t == head) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst(void)
{
    deleteNode(head->next);
}

void deleteLast(void)
{
    deleteNode(head->prev);
}

void deleteKey(int key)
{
    deleteNode(listSearch(key));
}

void insert(key)
{
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    // 头插法
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}

int main(void)
{
    int key, n;
    int size = 0;
    char com[20];

    scanf("%d", &n);
    init();

    for (int i = 0; i < n; i++) {
        // 输入要有空格 否则数字会被认为是字符
        scanf("%s%d", com, &key);
        if (com[0] == 'i') {
            insert(key);
            size++;
        } else if (com[0] == 'd') {
            if (strlen(com) > 6) {
                if (com[6] == 'F')
                    // 头插法元素是倒序排列的
                    deleteFirst();
                else if (com[6] == 'L')
                    deleteLast();
            } else {
                deleteKey(key);
            }
            size--;
        }
    }

    printList();

    return 0;
}