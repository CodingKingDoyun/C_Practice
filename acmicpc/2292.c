#include <stdio.h>

int main() {
  int num, floor = 1, cnt = 1;
  scanf("%d", &num);

  while (1) {
    if (num <= floor) {
      printf("%d", cnt);
      break;
    } else {
      floor += 6 * cnt;
      cnt++;
    }
  }
  return 0;
}
