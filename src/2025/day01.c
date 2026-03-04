/* Copyright (c) 2025, Kira Hasegawa
 * Licensed under the MIT license.
 *
 * This project demonstrates advanced C programming concepts.
 */

/* Headers */
#include <stdio.h>
#include "ansi.h"
#include "log.h"

/* Program entry */
int main(int argc, char *argv[])
{
	/* Set minimum log level (optional) */
	log_set_level(LOG_INFO); /* Can be LOG_INFO, LOG_WARN, LOG_ERROR, etc. */
	int log_level = log_get_level();
	printf("Current log level: %d\n", log_level);

	/* Logging test cases */
	log_info("Application started");
	log_warn("This is a warning with a number: %d", 42);
	log_error("An error occurred: %s", "file not found");
	log_log(LOG_DEBUG, __FILE__, __LINE__, "Debugging value: %f", 3.14159);

	return 0;
}
