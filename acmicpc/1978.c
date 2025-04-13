#include <math.h>
#include <stdio.h>

int isPrime(int num) {
  if (num < 2) return 0;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

int main() {
  int cnt, num, prime = 0;
  scanf("%d", &cnt);
  for (int i = 0; i < cnt; i++) {
    scanf("%d", &num);
    prime += isPrime(num);
  }
  printf("%d", prime);
  return 0;
}