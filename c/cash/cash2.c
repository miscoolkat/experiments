#include <stdio.h>
#include <math.h>
#include "prompt.h"

int main(void)
{
    double dollars = prompt_change();

    // Convert to cents with rounding to avoid float imprecision
    int cents = (int) round(dollars * 100.0);

    int coins = 0;
	// Coin denominations in cents
    int denominations[] = {25, 10, 5, 1};
    int n = sizeof(denominations) / sizeof(denominations[0]);

    for (int i = 0; i < n; i++)
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }

    printf("%d\n", coins);
    return 0;
}

/*
The llround(double) function in C rounds the given double-precision
floating-point value to the nearest integer, returning the result as
a long long type. It follows the current rounding mode and raises a
domain error if the input is not within the representable range of long long.
*/

