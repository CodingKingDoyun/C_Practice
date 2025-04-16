#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int result;
  switch (n % 8) {
    case 1:
      result = 1;
      break;
    case 2:
      result = 2;
      break;
    case 3:
      result = 3;
      break;
    case 4:
      result = 4;
      break;
    case 5:
      result = 5;
      break;
    case 6:
      result = 4;
      break;
    case 7:
      result = 3;
      break;
    case 0:
      result = 2;
      break;
  }

  printf("%d\n", result);
  return 0;
}