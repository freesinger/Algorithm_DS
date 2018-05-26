/* 给定数组生成最大堆 */

#include <iostream>
using namespace std;

int *heap, H;

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
        // 调整之后需要对子树再调用
        maxHeapify(max);
    }     
}

int main(void)
{
    cin >> H;

    heap = (int*)malloc(sizeof(int) * (H + 1));

    for (int i = 1; i <= H; i++)
        cin >> heap[i];

    for (int i = H / 2; i >= 1; i--)
        maxHeapify(i);

    for (int i = 1; i <= H; i++)
        cout << heap[i] << ' ';
    cout << endl;

    return 0;
}