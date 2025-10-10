#include <stdio.h>

// The integer "height" stands for Height in my code.
// The integer "row" stands for Row in my code.
// The integer "column" stands for Column in my code.

void clear_screen(void) {
    // ANSI escape code to clear screen and move cursor to top left
    printf("\033[2J\033[H");
}

int main(void)
{
    clear_screen();
    int height = 0;
    do
    {
        printf("Height (1-8): ");
        if (scanf("%d", &height) != 1) {
            // Clear invalid input
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            height = 0;
        }
    } while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        // Print spaces
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // Print left hashes
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        // Print gap
        printf("  ");
        // Print right hashes
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}

