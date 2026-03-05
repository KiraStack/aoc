#ifndef LOG_H
#define LOG_H

/* Headers */
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "ansi.h" /* used for ANSI color codes */

/* Macros */
#define log_info(...) log_log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)

/**
 * @brief Log levels.
 * @details
 * Logging levels are bitfields used to filter log messages by severity.
 * Multiple levels can be combined using bitwise operations.
 *
 * Severity overview:
 *  - INFO: general informational events
 *  - WARN: something unexpected happened but recovery is possible
 *  - ERROR: an unrecoverable error occurred
 */
typedef enum
{
	LOG_INFO = 1 << 0,
	LOG_WARN = 1 << 1,
	LOG_ERROR = 1 << 2,
} log_level_t;

/* Global log level */
static log_level_t global_log_level = LOG_INFO;

/* ANSI color codes for log levels */
static const char *level_colors[] = {
	[LOG_INFO] = GREEN,
	[LOG_WARN] = YELLOW,
	[LOG_ERROR] = RED,
};

/* Log level names */
static const char *level_names[] = {
	[LOG_INFO] = "INFO",
	[LOG_WARN] = "WARN",
	[LOG_ERROR] = "ERROR",
};

/**
 * Set the global log level.
 * @param level Log level to set.
 */
void log_set_level(log_level_t level)
{
	global_log_level = level;
}

/**
 * Get the current global log level.
 * @return Current log level.
 */
log_level_t log_get_level(void)
{
	return global_log_level;
}

/**
 * Log a message with the specified level.
 * @param level Log level.
 * @param file File name.
 * @param line Line number.
 * @param fmt Format string.
 */
void log_log(log_level_t level, const char *file, int line, const char *fmt, ...)
{
	if (level < global_log_level)
		return;

	/* Get current time */
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);
	char time_buf[9];
	strftime(time_buf, sizeof(time_buf), "%H:%M:%S", tm_info);

	/* Write formatted output */
	fprintf(stderr, "%s %s%s%s %s:%d: ", time_buf, level_colors[level], level_names[level], RESET, file, line);

	/* Format user message */
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n"); /* RESET */
}

#endif /* LOG_H */
