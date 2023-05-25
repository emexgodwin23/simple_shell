#include "shell.h"

/**
 * Checks if the shell is in interactive mode.
 *
 * @param info The shell's information structure.
 *
 * @return 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info) {
  // Check if the standard input is a terminal.
  if (isatty(STDIN_FILENO)) {
    // Check if the standard input is not a pipe or a socket.
    if (info->readfd <= 2) {
      return 1;
    }
  }
  return 0;
}

/**
 * Checks if the character is a delimiter.
 *
 * @param c The character to check.
 * @param delim The delimiter string.
 *
 * @return 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim) {
  // Loop over the delimiter string.
  while (*delim) {
    // Check if the current character is equal to the next character in the delimiter string.
    if (*delim++ == c) {
      // Return true if the character is a delimiter.
      return 1;
    }
  }
  // Return false if the character is not a delimiter.
  return 0;
}

/**
 * Checks if the character is alphabetic.
 *
 * @param c The character to check.
 *
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int is_alpha(int c) {
  // Check if the character is between 'a' and 'z'.
  if ((c >= 'a' && c <= 'z')) {
    // Return true if the character is alphabetic.
    return 1;
  }
  // Check if the character is between 'A' and 'Z'.
  if ((c >= 'A' && c <= 'Z')) {
    // Return true if the character is alphabetic.
    return 1;
  }
  // Return false if the character is not alphabetic.
  return 0;
}

/**
 * Converts a string to an integer in C.
 *
 * @param s The string to be converted.
 *
 * @return 0 if no numbers in string, converted number otherwise.
 */
int atoi(const char *str) {
  int sign = 1;
  unsigned int result = 0;

  // Skip any leading whitespace.
  while (*str && isspace(*str)) {
    str++;
  }

  // Check for a negative sign.
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  // Convert the string to an integer.
  while (*str && isdigit(*str)) {
    result *= 10;
    result += (*str - '0');
    str++;
  }

  // Return the result.
  return result * sign;
}

