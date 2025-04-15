// odd > even
#include <stdio.h>

int main() {
  int cock[3], even[3] = {0}, res = 1;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &cock[i]);
  }
  for (int i = 0; i < 3; i++) {
    if (cock[i] % 2 != 0) {
      res *= cock[i];
    }
  }
  if (res == 1) {
    res = cock[0] * cock[1] * cock[2];
  }
  printf("%d", res);
}