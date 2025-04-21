#include <stdio.h>

int main() {
  int num = 1, bdlTshirt = 0, bdlPen = 0, ordTshirt = 0;
  int size[6] = {0};

  scanf("%d", &num);
  scanf("%d %d %d %d %d %d", &size[0], &size[1], &size[2], &size[3], &size[4],
        &size[5]);
  scanf("%d %d", &bdlTshirt, &bdlPen);

  for (int i = 0; i < 6; i++) {
    ordTshirt += size[i] / bdlTshirt;
    if (0 < size[i] % bdlTshirt) {
      ordTshirt++;
    }
  }

  printf("%d\n%d %d", ordTshirt, num / bdlPen, num % bdlPen);
  return 0;
}