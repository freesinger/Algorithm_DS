#include <stdio.h>
#include <string.h>
#define LEN 8888

typedef struct task {
    char name[100];
    int t;
} TASK;

TASK Queue[LEN];
int head, tail;

void enqueue (TASK t)
{
    Queue[tail] = t;
    tail = (tail + 1) % LEN;
}

TASK dequeue (void)
{
    TASK t = Queue[head];
    head = (head + 1) % LEN;
    return t;
}

int minimum (int a, int b)
{
    return a < b ? a : b;
}

int main (void) 
{
    int comp_time = 0, min;
    int num, qtime;
    TASK temp;

    printf("Input number and time per task: ");
    scanf("%d %d", &num, &qtime);

    printf("Enter %d name and task time:", num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%s", Queue[i].name);
        scanf("%d", &Queue[i].t);
    }

    head = 1, tail = num + 1;

    while(tail != head) {
        temp = dequeue();
        min = minimum(temp.t, qtime);
        comp_time += min;
        if (temp.t - min > 0) {
            enqueue(temp);
        } else {
            printf("\n%s %d", temp.name, comp_time);
        }
    }

    return 0;
}