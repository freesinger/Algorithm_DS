#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *nil;

Node* listSearch (int key)
{
    Node *cur = nil->next;
    while ( cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void init ()
{
    nil = (Node*)malloc(sizeof(Node));
    nil->next = nil;
    nil->pre = nil;
}

void printList ()
{
    Node *cur = nil->next;
    while (1) {
        if (cur == nil) break;
        printf("%d ", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode (Node *t)
{
    if (t == nil) return;
    t->pre->next = t->next;
    t->next->pre = t->pre;
    free(t);
}

void deleteFirst ()
{
    deleteNode(nil->next);
}

void deleteLast ()
{
    deleteNode(nil->pre);
}

void deleteKey (int key)
{
    deleteNode(listSearch(key));
}

 //头插法
void insertKey (int key)
{
    Node *cur = (Node*)malloc(sizeof(Node));
    cur->key = key;
    cur->next = nil->next;
    nil->next->pre = cur;
    nil->next = cur;
    cur->pre = nil;
}