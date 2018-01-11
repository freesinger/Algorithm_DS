#ifndef DOUBLELLIST
#define DOUBLELLIST

typedef struct NODE {
    int key;
    struct NODE *pre, *next;
} Node;

Node* listSearch (int key);
void init ();
void printList ();
void deleteNode (Node *t);
void deleteFirst ();
void deleteLast ();
void deleteKey (int key);
void insertKey (int key);

#endif