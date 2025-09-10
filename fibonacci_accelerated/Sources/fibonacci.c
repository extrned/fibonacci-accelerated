#include <stdio.h>
#include "fibonacci.h"

static void mul_mat (const U64 a[2][2], const U64 b[2][2], U64 r[2][2]) {
    r[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    r[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    r[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    r[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

static void pow_mat (U64 N, U64 r[2][2]) {
    U64 base[2][2] = { {1, 1}, {1, 0} }, dust[2][2];
    /* INIT */
    r[0][0] = 1; r[0][1] = 0; r[1][0] = 0; r[1][1] = 1;
    while (N) {
        if (N & 1) {
            mul_mat(r, base, dust);
            r[0][0] = dust[0][0]; r[0][1] = dust[0][1];
            r[1][0] = dust[1][0]; r[1][1] = dust[1][1];
        }
        mul_mat(base, base, dust);
        base[0][0] = dust[0][0]; base[0][1] = dust[0][1];
        base[1][0] = dust[1][0]; base[1][1] = dust[1][1];
        N >>= 1;
    }
}

U64 fibonacci (U64 N) {
    if (N == 0) return 0;
    U64 for_pow[2][2];
    pow_mat(N - 1, for_pow);
    return for_pow[0][0]; // F(n)
}
int main() {
    U64 N;
    clock_t cl = clock();
    puts("Enter some number: ");
    if (scanf("%llu", &N) != 1) return 1;
    printf("\nFibonacci number: %llu\n", fibonacci(N));
    cl = clock() - cl;
    double t_taken = ((double)cl) / CLOCKS_PER_SEC;
    printf("It took %fs to execute.", t_taken);
    return 0;
}
