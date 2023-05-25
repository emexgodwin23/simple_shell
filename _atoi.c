#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  char *command;
  char *args[10];
  int argc;

  // Get the user's command
  printf("Enter your command: ");
  fgets(command, 100, stdin);

  // Parse the command into arguments
  argc = parse_command(command, args);

  // Execute the command
  execute_command(argc, args);

  return 0;
}

int parse_command(char *command, char *args[]) {
  // Count the number of arguments
  int argc = 0;
  while (command[argc] != '\0') {
    if (command[argc] == ' ') {
      ++argc;
    }
    ++argc;
  }

  // Populate the arguments array
  for (int i = 0; i < argc; ++i) {
    args[i] = command + i;
  }

  return argc;
}

int execute_command(int argc, char *args[]) {
  // Check for the built-in commands
  if (argc == 1) {
    if (strcmp(args[0], "help") == 0) {
      print_help();
    } else if (strcmp(args[0], "exit") == 0) {
      exit(0);
    }
  }

  // Otherwise, execute the command as an external command
  else {
    int status = system(args[0]);
    if (status != 0) {
      printf("Error executing command: %s\n", args[0]);
    }
  }

  return 0;
}

void print_help() {
  printf("The following commands are supported:\n");
  printf("help\t\tPrints this help message.\n");
  printf("exit\t\tExits the shell.\n");
}

