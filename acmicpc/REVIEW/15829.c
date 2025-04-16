#include <stdio.h>

int main() {
  int leg, M = 1234567891;
  unsigned long long hash = 0, r = 1;
  char str[50];
  scanf("%d", &leg);
  scanf("%s", str);
  for (int i = 0; i < leg; i++) {
    hash = (hash + (str[i] - 96) * r) % M;
    r = (r * 31) % M;
  }
  printf("%lld", hash % M);
  return 0;
}