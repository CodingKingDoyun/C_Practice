#include <stdio.h>

int main() {
  int num, max, res = 0, card[100];
  scanf("%d %d", &num, &max);
  for (int i = 0; i < num; i++) {
    scanf("%d", &card[i]);
  }

  for (int i = 0; i < num - 2; i++) {
    for (int j = i + 1; j < num - 1; j++) {
      for (int k = j + 1; k < num; k++) {
        int sum = card[i] + card[j] + card[k];
        if (res < sum && sum <= max) {
          res = sum;
          // 조기종료
          if (res == max) {
            printf("%d", res);
            return 0;
          }
        }
      }
    }
  }
  printf("%d", res);
  return 0;
}