#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main (void)
{
    int key, num;
    char com[20];

    printf("Enter number of operation: ");
    scanf("%d", &num);
    init();

    printf("Insert/Delete and %d number: ", num);
    for (int n = 0; n < num; n++) {
        scanf("%s%d", com, &key);
        if (com[0] == 'i') {
            insertKey(key);
        } else if (com[0] == 'd')
            deleteKey(key);  
    }

    printf("Number left: ");    
    printList();

    return 0;
}

 /* if (strlen(com) > 6) {
        if (com[6] == 'f' || com[6] == 'F') {
            deleteFirst();
        } else if (com[6] == 'l' || com[6]== 'L') {
            deleteLast();
        } else */