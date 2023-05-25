#include <stdio.h>
#include <stdlib.h>

void print_string(char *str) {
  int i = 0;

  if (!str) {
    return;
  }
  while (str[i] != '\0') {
    printf("%c", str[i]);
    i++;
  }
}

void print_character(char c) {
  printf("%c", c);
}

void print_fd(char c, int fd) {
  write(fd, &c, 1);
}

int print_string_fd(char *str, int fd) {
  int i = 0;

  if (!str) {
    return 0;
  }
  while (str[i] != '\0') {
    print_fd(str[i], fd);
    i++;
  }
  return i;
}

