#ifndef LOG_H
#define LOG_H

/* Headers */
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "ansi.h" /* used for ANSI color codes */

/* Macros */
#define log_trace(...) log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) log_log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

/* Log levels */
typedef enum
{
	LOG_TRACE = 0,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
} log_level_t;

/* Global log level */
static log_level_t global_log_level = LOG_TRACE; /* (default: LOG_TRACE) */

/* ANSI color codes for log levels */
static const char *level_colors[] = {
	[LOG_TRACE] = WHITE,
	[LOG_DEBUG] = BLUE,
	[LOG_INFO] = GREEN,
	[LOG_WARN] = YELLOW,
	[LOG_ERROR] = RED,
	[LOG_FATAL] = MAGENTA};

/* Log level names */
static const char *level_names[] = {
	[LOG_TRACE] = "TRACE",
	[LOG_DEBUG] = "DEBUG",
	[LOG_INFO] = "INFO",
	[LOG_WARN] = "WARN",
	[LOG_ERROR] = "ERROR",
	[LOG_FATAL] = "FATAL"};

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

	/* Print log level, file, line, and message */
	fprintf(stderr, "%s %s%s%s %s:%d: ", time_buf, level_colors[level], level_names[level], RESET, file, line);

	/* Format user message */
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n"); /* RESET */
}

#endif /* LOG_H */
