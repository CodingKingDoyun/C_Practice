/*
두 힙의 크기 차이를 비교하고 중간값을 구하는 방법을 더 자세히 설명하겠습니다. 이 과정은 **최대 힙(Max-Heap)**과 **최소 힙(Min-Heap)**을 사용하여 중간값을 효율적으로 계산하는 알고리즘의 핵심입니다.

1. 두 힙의 역할
최대 힙 (maxHeap): 입력된 값 중 중간값 이하의 값을 저장합니다.
최대 힙의 루트 값은 중간값 이하의 값 중 가장 큰 값입니다.
최소 힙 (minHeap): 입력된 값 중 중간값 이상의 값을 저장합니다.
최소 힙의 루트 값은 중간값 이상의 값 중 가장 작은 값입니다.
2. 두 힙의 크기 차이를 비교하는 이유
중간값을 정확히 구하려면 두 힙의 크기를 다음 조건에 맞게 유지해야 합니다:

최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 많아야 합니다.
즉, |maxHeap.size() - minHeap.size()| <= 1을 유지해야 합니다.
이 조건을 유지하면, 중간값은 항상 최대 힙의 루트 값으로 결정됩니다.
크기 조정 과정
최대 힙의 크기가 최소 힙보다 2 이상 크다면:
최대 힙의 루트 값을 최소 힙으로 이동합니다.
최소 힙의 크기가 최대 힙보다 크다면:
최소 힙의 루트 값을 최대 힙으로 이동합니다.
3. 중간값을 구하는 방법
두 힙의 크기가 같거나 최대 힙이 더 큰 경우, 중간값은 최대 힙의 루트 값입니다.
이유: 최대 힙은 중간값 이하의 값들을 저장하고, 최대 힙의 루트 값이 그 중 가장 큰 값이기 때문입니다.
4. 동작 과정 예시
입력값: 1, 5, 2, 10, -99, 7, 5
입력값: 1

최대 힙이 비어 있으므로 1을 최대 힙에 삽입.
최대 힙: [1], 최소 힙: []
중간값: 1 (최대 힙의 루트 값)
입력값: 5

5는 최대 힙의 루트 값 1보다 크므로 최소 힙에 삽입.
최대 힙: [1], 최소 힙: [5]
중간값: 1 (최대 힙의 루트 값)
입력값: 2

2는 최대 힙의 루트 값 1보다 크므로 최소 힙에 삽입.
최대 힙: [1], 최소 힙: [2, 5]
최소 힙의 크기가 더 크므로, 최소 힙의 루트 값 2를 최대 힙으로 이동.
최대 힙: [2, 1], 최소 힙: [5]
중간값: 2 (최대 힙의 루트 값)
입력값: 10

10은 최대 힙의 루트 값 2보다 크므로 최소 힙에 삽입.
최대 힙: [2, 1], 최소 힙: [5, 10]
중간값: 2 (최대 힙의 루트 값)
입력값: -99

-99는 최대 힙의 루트 값 2보다 작으므로 최대 힙에 삽입.
최대 힙: [2, 1, -99], 최소 힙: [5, 10]
최대 힙의 크기가 더 크므로, 최대 힙의 루트 값 2를 최소 힙으로 이동.
최대 힙: [1, -99], 최소 힙: [2, 10, 5]
중간값: 2 (최대 힙의 루트 값)
입력값: 7

7은 최대 힙의 루트 값 1보다 크므로 최소 힙에 삽입.
최대 힙: [1, -99], 최소 힙: [2, 7, 5, 10]
최소 힙의 크기가 더 크므로, 최소 힙의 루트 값 2를 최대 힙으로 이동.
최대 힙: [2, -99, 1], 최소 힙: [5, 7, 10]
중간값: 2 (최대 힙의 루트 값)
입력값: 5

5는 최대 힙의 루트 값 2보다 크므로 최소 힙에 삽입.
최대 힙: [2, -99, 1], 최소 힙: [5, 5, 10, 7]
중간값: 5 (최대 힙의 루트 값)
*/

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