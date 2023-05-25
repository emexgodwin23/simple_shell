#include <stdio.h>
#include <stdlib.h>

void print_environment() {
  char **env = environ;

  while (*env) {
    printf("%s\n", *env);
    env++;
  }
}

void set_environment(char *name, char *value) {
  char *new_env = malloc(strlen(name) + strlen(value) + 2);
  strcpy(new_env, name);
  strcat(new_env, "=");
  strcat(new_env, value);

  putenv(new_env);
}

void unset_environment(char *name) {
  unsetenv(name);
}

int main() {
  print_environment();

  set_environment("HOME", "/home/user");
  set_environment("PATH", "/usr/bin:/bin");
  set_environment("SHELL", "/bin/bash");

  print_environment();

  unset_environment("HOME");
  unset_environment("PATH");
  unset_environment("SHELL");

  print_environment();

  return 0;
}

