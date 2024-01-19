#include <stdio.h>
#include <gmp.h>

int countSetBits(mpz_t num)
{
    int count = 0;
    mpz_t zero, two;

    mpz_init(zero);
    mpz_init_set_ui(two, 2);

    while (mpz_cmp_ui(num, 0) > 0)
    {
        if (mpz_odd_p(num))
        {
            count++;
        }
        mpz_fdiv_q(num, num, two);
    }

    mpz_clear(zero);
    mpz_clear(two);

    return count;
}

int main()
{
    // Initialize GMP integer
    mpz_t num;
    mpz_init(num);

    // Input
    gmp_scanf("%Zd", num);

    // Count the number of set bits in the binary representation
    int result = countSetBits(num);

    // Output
    printf("%d\n", result);

    // Free allocated memory
    mpz_clear(num);

    return 0;
}
