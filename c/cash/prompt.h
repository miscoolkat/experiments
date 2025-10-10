#ifndef PROMPT_H
#define PROMPT_H

#include <stdio.h>

// Header-only prompt function for a non-negative double amount
static inline double prompt_change(void) {
    double dollars = -1.0;
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
    return dollars;
}

#endif // PROMPT_H
