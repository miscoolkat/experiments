#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Configuration
#define TREE_HEIGHT 7
#define TRUNK_HEIGHT 2
#define TRUNK_WIDTH 3
#define STAR "★"
#define TREE_CHAR '*'
#define TRUNK_CHAR '|'

// ANSI color codes for festive colors
#define COLOR_RESET "\x1b[0m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RED "\x1b[31m"
#define COLOR_BROWN "\x1b[33m"
#define COLOR_BRIGHT "\x1b[1m"

// Function to clear the screen
void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Function to print spaces
void printSpaces(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf(" ");
	}
}

// Function to print the static Christmas tree
void printChristmasTree(int height)
{
	int maxWidth = height * 2 + 1;

	// Print the star on top
	int starSpaces = maxWidth / 2;
	printSpaces(starSpaces);
	printf("%s%s%s%s\n", COLOR_YELLOW, COLOR_BRIGHT, STAR, COLOR_RESET);

	// Print the tree sections
	for (int i = 1; i <= height; i++)
	{
		int width = i * 2 + 1;
		int spaces = (maxWidth - width) / 2;
		printSpaces(spaces);

		// Add some random decorations (ornaments)
		for (int j = 0; j < width; j++)
		{
			double random = (double)rand() / RAND_MAX;

			if (random < 0.1)
			{
				printf("%so%s", COLOR_RED, COLOR_RESET); // Red ornaments
			}
			else if (random < 0.15)
			{
				printf("%so%s", COLOR_YELLOW, COLOR_RESET); // Yellow ornaments
			}
			else
			{
				printf("%s%c%s", COLOR_GREEN, TREE_CHAR, COLOR_RESET); // Green tree
			}
		}
		printf("\n");
	}

	// Print the trunk
	int trunkSpaces = (maxWidth - TRUNK_WIDTH) / 2;
	for (int i = 0; i < TRUNK_HEIGHT; i++)
	{
		printSpaces(trunkSpaces);
		printf("%s", COLOR_BROWN);
		for (int j = 0; j < TRUNK_WIDTH; j++)
		{
			printf("%c", TRUNK_CHAR);
		}
		printf("%s\n", COLOR_RESET);
	}
}

// Function to print a simple tree without colors
void printSimpleTree(int height)
{
	printf("\n--- Simple Christmas Tree ---\n");

	// Star
	int maxWidth = height * 2 + 1;
	printSpaces(maxWidth / 2);
	printf("★\n");

	// Tree
	for (int i = 1; i <= height; i++)
	{
		printSpaces(height - i);
		for (int j = 0; j < i * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	// Trunk
	printSpaces(height - 1);
	printf("|\n");
	printSpaces(height - 1);
	printf("|\n");
}

// Function to print animated tree
void printAnimatedTree()
{
	printf("\n🎄 Animated Christmas Tree 🎄\n");
	printf("Press Ctrl+C to stop the animation\n\n");

	// Different star symbols for animation frames
	const char *stars[] = {"✦", "✧", "★", "☆"};
	const char *ornaments[] = {"o", "●", "o", "○"};
	int numFrames = 4;

	int maxWidth = TREE_HEIGHT * 2 + 1;
	int frameIndex = 0;

	// Animation loop (30 frames = ~12 seconds at 400ms per frame)
	for (int frame = 0; frame < 30; frame++)
	{
		clearScreen();

		int currentFrame = frameIndex % numFrames;

		// Print the animated star
		int starSpaces = maxWidth / 2;
		printSpaces(starSpaces);
		printf("%s%s%s%s\n", COLOR_YELLOW, COLOR_BRIGHT, stars[currentFrame], COLOR_RESET);

		// Print the tree sections with animated ornaments
		for (int i = 1; i <= TREE_HEIGHT; i++)
		{
			int width = i * 2 + 1;
			int spaces = (maxWidth - width) / 2;
			printSpaces(spaces);

			for (int j = 0; j < width; j++)
			{
				double random = (double)rand() / RAND_MAX;

				if (random < 0.1)
				{
					printf("%s%s%s", COLOR_RED, ornaments[currentFrame], COLOR_RESET);
				}
				else if (random < 0.15)
				{
					printf("%s%s%s", COLOR_YELLOW, ornaments[currentFrame], COLOR_RESET);
				}
				else
				{
					printf("%s%c%s", COLOR_GREEN, TREE_CHAR, COLOR_RESET);
				}
			}
			printf("\n");
		}

		// Print the trunk
		int trunkSpaces = (maxWidth - TRUNK_WIDTH) / 2;
		for (int i = 0; i < TRUNK_HEIGHT; i++)
		{
			printSpaces(trunkSpaces);
			printf("%s", COLOR_BROWN);
			for (int j = 0; j < TRUNK_WIDTH; j++)
			{
				printf("%c", TRUNK_CHAR);
			}
			printf("%s\n", COLOR_RESET);
		}

		frameIndex++;
		usleep(400000); // Sleep for 400ms
	}

	printf("\nAnimation stopped. Happy Holidays!\n");
}

int main(void)
{
	// Seed random number generator
	srand(time(NULL));

	// Run the animated tree
	printAnimatedTree();

	return 0;
}