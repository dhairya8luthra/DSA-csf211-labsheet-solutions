#include <stdio.h>
#include <gmp.h>

void extendedGCD(mpz_t a, mpz_t b, mpz_t x, mpz_t y)
{
    if (mpz_cmp_ui(b, 0) == 0)
    {
        mpz_set_ui(x, 1);
        mpz_set_ui(y, 0);
    }
    else
    {
        mpz_t q, r, x1, y1;
        mpz_inits(q, r, x1, y1, NULL);

        mpz_fdiv_qr(q, r, a, b);
        extendedGCD(b, r, x1, y1);

        mpz_set(x, y1);
        mpz_submul(x, q, x1);

        mpz_set(y, x1);

        mpz_clears(q, r, x1, y1, NULL);
    }
}

int main()
{
    // Initialize GMP integers
    mpz_t N, M, passcode;
    mpz_inits(N, M, passcode, NULL);

    // Input
    gmp_scanf("%Zd", N);
    gmp_scanf("%Zd", M);

    // Compute passcode using Extended Euclidean Algorithm
    mpz_t x, y;
    mpz_inits(x, y, NULL);
    extendedGCD(N, M, x, y);

    // Ensure the passcode is positive
    while (mpz_cmp_ui(x, 0) < 0)
    {
        mpz_add(x, x, M);
    }

    // Output
    gmp_printf("%Zd\n", x);

    // Free allocated memory
    mpz_clears(N, M, passcode, x, y, NULL);

    return 0;
}
