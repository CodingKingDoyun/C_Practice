#include <stdio.h>

// 힙 삽입 함수 (최대 힙)
void insertMaxHeap(int heap[], int *size, int value) {
    int i = (*size)++;
    while (i > 0 && heap[(i - 1) / 2] < value) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = value;
}

// 힙 삽입 함수 (최소 힙)
void insertMinHeap(int heap[], int *size, int value) {
    int i = (*size)++;
    while (i > 0 && heap[(i - 1) / 2] > value) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = value;
}

// 힙 삭제 함수 (최대 힙)
int removeMaxHeap(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0, child;
    while ((child = 2 * i + 1) < *size) {
        if (child + 1 < *size && heap[child] < heap[child + 1]) child++;
        if (heap[i] >= heap[child]) break;
        int tmp = heap[i];
        heap[i] = heap[child];
        heap[child] = tmp;
        i = child;
    }
    return root;
}

int main() {
    int cnt, num;
    int maxHeap[100000], minHeap[100000];
    int maxcnt = 0, mincnt = 0;

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num);

        if (maxcnt == 0 || num <= maxHeap[0]) {
            insertMaxHeap(maxHeap, &maxcnt, num);
        } else {
            insertMinHeap(minHeap, &mincnt, num);
        }

        // 균형 유지
        if (maxcnt > mincnt + 1) {
            insertMinHeap(minHeap, &mincnt, removeMaxHeap(maxHeap, &maxcnt));
        } else if (mincnt > maxcnt) {
            insertMaxHeap(maxHeap, &maxcnt, minHeap[0]);
            minHeap[0] = minHeap[--mincnt];
        }

        printf("%d\n", maxHeap[0]);
    }
    return 0;
}