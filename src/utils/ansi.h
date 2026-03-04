#ifndef ANSI_H
#define ANSI_H

/* ANSI escape codes
   These codes allow command line applications to show colored or styled text in most terminals.
   Advanced commands can move the cursor or clear the screen. */
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[94m"
#define WHITE "\x1b[97m"
#define HOME "\x1b[H"
#define CLEAR "\x1b[J"

#endif /* ANSI_H */
