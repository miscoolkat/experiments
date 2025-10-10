#include <stdio.h>
#include <math.h>

int main(void)
{
    double dollars = -1.0;

    // Prompt until non-negative value
    while (dollars < 0.0)
    {
        printf("Change owed: ");
        if (scanf("%lf", &dollars) != 1) {
            // Clear invalid input and continue prompting
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            dollars = -1.0;
        }
    }

    // Convert to cents with rounding to avoid float imprecision
	int cents = (int) round(dollars * 100.0);

    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    int n = sizeof(denominations) / sizeof(denominations[0]);

	printf("%d\n", n);

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

