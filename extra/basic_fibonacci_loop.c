/* This is an example of a simple (SLOW) iterative Fibonacci */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
  int n, i;
  uint64_t t1 = 0, t2 = 1, next;
  puts("Enter some number: ");
  scanf("%d", &n);
  if (n == 0) next = 0;
  else if (n == 1) next = 1;
  else {
    for (i = 2; i <= n; i++) {
      next = t1 + t2;
      t1 = t2;
      t2 = next;
    }
  }
  printf("Fibonacci number: %" PRIu64 "\n", next); //64bit values support
  return 0;
}
