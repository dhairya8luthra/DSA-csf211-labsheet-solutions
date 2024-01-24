#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t N, M, result;
    mpz_inits(N, M, result, NULL);

    // Input
    gmp_scanf("%Zd", N);
    gmp_scanf("%Zd", M);

    // Compute passcode using mpz_invert
    if (mpz_invert(result, N, M) != 0) {
        // Output passcode
        gmp_printf("%Zd\n", result);
    }

    mpz_clears(N, M, result, NULL);
    return 0;
}
