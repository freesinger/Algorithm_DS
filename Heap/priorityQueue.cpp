/* 优先级队列输入输出 */

#include<iostream>
#include<string>
using namespace std;
#define INFTY (1<<30)

static int H;
int *heap = (int*)malloc(sizeof(int) * 20);

void maxHeapify(int i)
{
    int max;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= H && heap[left] > heap[i])
        max = left;
    else
        max = i;
    
    if (right <= H && heap[right] > heap[max])
        max = right;
    
    if (max != i) {
        swap(heap[max], heap[i]);
        maxHeapify(max);
    }     
}

int extract(void)
{
    int max;

    if (H < 1)
        return -INFTY;
    max = heap[1];
    heap[1] = heap[H--];
    maxHeapify(1);

    return max;
}

void insertKey(int i, int key)
{
    if (key < heap[i])
        return;
    heap[i] = key;

    while (i > 1 && heap[i / 2] < heap[i]) {
        swap(heap[i / 2], heap[i]);
        i /= 2;
    }
}

void insert(int key)
{
    heap[++H] = -INFTY;
    insertKey(H, key);
}

int main(void)
{
    int key;
    string com;

    while (1) {
        cin >> com;
        if (com == "end")
            break;
        if (com[0] == 'i') {
            scanf("%d", &key);
            insert(key);
        } else {
            printf("%d\n", extract());
        }
    }

    free(heap);
    
    return 0;
}