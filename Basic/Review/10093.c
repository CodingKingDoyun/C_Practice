#include <stdio.h>

int main() {
  long long a, b, str, end, cnt;
  scanf("%lld %lld", &str, &end);
  if (str > end) {
    long long tmp = str;
    str = end;
    end = tmp;
  }

  cnt = (end > str + 1) ? end - (str + 1) : 0;
  printf("%lld\n", cnt);
  for (long long i = str + 1; i < end; i++) {
    printf("%lld ", i);
  }
  return 0;
}
