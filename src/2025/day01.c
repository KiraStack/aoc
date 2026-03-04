/* Copyright (c) 2025, Kira Hasegawa
 * Licensed under the MIT license.
 *
 * This project demonstrates advanced C programming concepts.
 */

/* Headers */
#include <stdio.h>
#include "ansi.h"

/* Program entry */
int main(int argc, char *argv[])
{
	printf(BOLD GREEN "Hello, World!\n" RESET);
	printf(CLEAR);
	return 0;
}
