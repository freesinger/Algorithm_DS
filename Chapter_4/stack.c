/* Simple calculation use staack */

#include <stdio.h>
#include <stdlib.h>

int top, Stack[1000];

void push(int number)
{
    Stack[++top] = number;
}

int pop()
{
    return Stack[top--];
}

int main (void)
{
    int a, b;
    top = 0;
    char stack[100];

    while (scanf("%s", stack) != EOF) {
        if (stack[0] == '+') {
            a = pop();
            b = pop();
            push(a + b);   
        } else if (stack[0] == '-') {
            b = pop();
            a = pop();
            push(a - b);
        } else if (stack[0] == '*') {
            a = pop();
            b = pop();
            push(a * b);
        } else {
            push(atoi(stack));
        }
    }
    printf("%d\n", pop());
    return 0;
}