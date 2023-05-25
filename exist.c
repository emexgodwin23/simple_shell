#include <stdio.h>
#include <stdlib.h>

void strncpy(char *dest, char *src, int n) {
  int i;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  dest[i] = '\0';
}

void strncat(char *dest, char *src, int n) {
  int i, j;

  for (i = 0; dest[i] != '\0'; i++) {
  }

  for (j = 0; j < n && src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }

  dest[i + j] = '\0';
}

char *strchr(char *s, char c) {
  while (*s != '\0') {
    if (*s == c) {
      return s;
    }
    s++;
  }

  return NULL;
}

