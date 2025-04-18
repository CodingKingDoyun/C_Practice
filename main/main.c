#include <stdio.h>

int main() {
  int test;
  scanf("%d", &test);
  for (int i = 0; i < test; i++) {
    int wNum, eNum, wArr[31] = {0}, eArr[31] = {0};
    scanf("%d %d", &wNum, &eNum);
    for (int j = wNum; j > 0; j--) {
      int temp = j + eNum--;
      printf("%d", temp);
    }
  }
  return 0;
}
/*
2 1
5 4 3 2 1

7 6 5 4, 5 4 3 2


3 2 1
5 4 3 2 1

8 7 6, 6 5 4, 4 3 2


4 3 2 1
5 4 3 2 1

9 8, 7 6, 5 4, 3 2

4 3 2 1
6 5 4 3 2 1

10 9 8, 8 7 6, 6 5 4, 4 3 2
2차원 배열 사용해보기
*/
