#include <stdio.h>
#include <gmp.h>

int main()
{
    // Initialize GMP integers
    mpz_t num1, num2, result;
    mpz_init(num1);
    mpz_init(num2);
    mpz_init(result);

    // Input
    gmp_scanf("%Zd", num1);
    gmp_scanf("%Zd", num2);

    // Perform multiplication
    mpz_mul(result, num1, num2);

    // Output
    gmp_printf("%Zd\n", result);

    // Free allocated memory
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(result);

    return 0;
}
