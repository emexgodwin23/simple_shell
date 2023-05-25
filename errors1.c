#include <stdio.h>
#include <stdlib.h>

int convert_number(long int num, int base, int flags) {
  static char *array = "0123456789abcdef";
  static char buffer[50];
  char sign = 0;
  char *ptr;
  unsigned long n = num;

  if (!(flags & CONVERT_UNSIGNED) && num < 0) {
    n = -num;
    sign = '-';
  }

  ptr = &buffer[49];
  *ptr = '\0';

  do {
    *--ptr = array[n % base];
    n /= base;
  } while (n != 0);

  if (sign) {
    *--ptr = sign;
  }

  return ptr - buffer;
}

void remove_comments(char *buf) {
  int i;

  for (i = 0; buf[i] != '\0'; i++) {
    if (buf[i] == '#' && (!i || buf[i - 1] == ' ')) {
      buf[i] = '\0';
      break;
    }
  }
}

