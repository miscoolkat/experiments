/*
 * Animated and Colored Christmas Tree in ANSI C
 * Prints a festive ASCII Christmas tree with colors and animation
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for usleep

#define TREE_HEIGHT 7  // Number of tree sections
#define TRUNK_HEIGHT 2 // Height of the trunk
#define TRUNK_WIDTH 3  // Width of the trunk
#define STAR "★"
#define TREE_CHAR '*'
#define TRUNK_CHAR '|'
#define FRAME_DELAY 400000 // microseconds (0.4 seconds)

// ANSI color codes
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RED "\x1b[31m"
#define BROWN "\x1b[33m"
#define BRIGHT "\x1b[1m"

void print_spaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		putchar(' ');
	}
}

void print_star(int maxWidth, int frame)
{
	print_spaces(maxWidth / 2);
	// Animate star by changing color/character
	const char *stars[] = {"✦", "✧", "★", "☆"};
	printf(YELLOW BRIGHT "%s" RESET, stars[frame % 4]);
	putchar('\n');
}

void print_tree(int height, int maxWidth, int frame)
{
	for (int i = 1; i <= height; i++)
	{
		int width = i * 2 + 1;
		int spaces = (maxWidth - width) / 2;
		print_spaces(spaces);
		for (int j = 0; j < width; j++)
		{
			double random = (double)rand() / RAND_MAX;
			if (random < 0.1)
			{
				printf(RED "%c" RESET, frame % 2 ? 'o' : 'O'); // Red ornament
			}
			else if (random < 0.15)
			{
				printf(YELLOW "%c" RESET, frame % 2 ? 'o' : 'O'); // Yellow ornament
			}
			else
			{
				printf(GREEN "%c" RESET, TREE_CHAR); // Green tree
			}
		}
		putchar('\n');
	}
}

void print_trunk(int maxWidth)
{
	int spaces = (maxWidth - TRUNK_WIDTH) / 2;
	for (int i = 0; i < TRUNK_HEIGHT; i++)
	{
		print_spaces(spaces);
		printf(BROWN);
		for (int j = 0; j < TRUNK_WIDTH; j++)
		{
			putchar(TRUNK_CHAR);
		}
		printf(RESET);
		putchar('\n');
	}
}

void clear_screen()
{
	// ANSI escape code to clear screen and move cursor to top
	printf("\x1b[2J\x1b[H");
}

int main(void)
{
	srand((unsigned int)time(NULL)); // Seed random for ornaments
	int maxWidth = TREE_HEIGHT * 2 + 1;
	int frame = 0;
	printf("\n\nPress Ctrl+C to stop the animation\n\n");
	while (1)
	{
		clear_screen();
		print_star(maxWidth, frame);
		print_tree(TREE_HEIGHT, maxWidth, frame);
		print_trunk(maxWidth);
		fflush(stdout);
		usleep(FRAME_DELAY);
		frame++;
	}
	return 0;
}
