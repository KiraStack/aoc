/* Copyright (c) 2025, Kira Hasegawa
 * Licensed under the MIT license.
 *
 * This project demonstrates advanced C programming concepts.
 */

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include "utils/ansi.h"

/* Program entry */
int main(int argc, char *argv[])
{
	int year, day;
	char command[512];

	/* Prompt user for year */
	printf("Enter year (e.g., 2025): ");
	if (scanf("%d", &year) != 1)
	{
		fprintf(stderr, "Invalid input for year.\n");
		return 1;
	}

	/* Prompt user for day */
	printf("Enter day number to run (e.g., 1): ");
	if (scanf("%d", &day) != 1)
	{
		fprintf(stderr, "Invalid input for day.\n");
		return 1;
	}

	/* Construct the compile command */
	sprintf(command, "gcc -std=c89 -Wall -Isrc/utils src/%d/day%02d.c -o target/program.out && target/program.out", year, day);
	printf("Running: %s\n", command);

	/* Execute the command */
	int ret = system(command);
	if (ret != 0)
	{
		fprintf(stderr, "Error! Command failed with exit code %d\n", ret);
		return 1;
	}

	return 0;
}
