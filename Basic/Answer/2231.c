#include <stdio.h>

int function(int num) {
  for (int i = num - 63; i < num; i++) {
    int sum = i, tmp = i;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (sum == num) return i;
  }
  return 0;
}

int main() {
  int num;
  scanf("%d", &num);
  printf("%d", function(num));
}