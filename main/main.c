#include <stdio.h>

int main() {
  int num, price, res = 50001;
  scanf("%d %d", &num, &price);
  if (num >= 5) {
    if (price - 500 < res) {
      res = price - 500;
    }
  }
  if (num >= 10) {
    if (price - (price * 0.1) < res) {
      res = price - (price * 0.1);
    }
  }
  if (num >= 15) {
    if (price - 2000 < res) {
      res = price - 2000;
    }
  }
  if (num >= 20) {
    if (price - (price * 0.25) < res) {
      res = price - (price * 0.25);
    }
  }
  if (res < 0) res == 0;
  printf("%d", res);
  return 0;
}