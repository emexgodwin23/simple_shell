#include "shell.h"

/**
 * Exits the shell with a given exit status.
 *
 * @param info The shell's information structure.
 *
 * @return 0 if info.argv[0] != "exit", -1 otherwise.
 */
int my_exit(info_t *info) {
  int exit_status;

  if (info->argv[1]) {
    exit_status = atoi(info->argv[1]);
    if (exit_status == -1) {
      info->status = 2;
      printf("Illegal number: %s\n", info->argv[1]);
      return 1;
    }
  } else {
    exit_status = -1;
  }

  info->err_num = exit_status;
  return -2;
}

/**
 * Changes the current directory of the process.
 *
 * @param info The shell's information structure.
 *
 * @return 0 if successful, -1 otherwise.
 */
int my_cd(info_t *info) {
  char *s, *dir, buffer[1024];
  int chdir_ret;

  s = getcwd(buffer, 1024);
  if (!s) {
    printf("TODO: >>getcwd failure emsg here<<\n");
    return -1;
  }

  if (!info->argv[1]) {
    dir = getenv("HOME");
    if (!dir) {
      chdir("/");
    } else {
      chdir(dir);
    }
  } else if (strcmp(info->argv[1], "-") == 0) {
    dir = getenv("OLDPWD");
    if (!dir) {
      return 1;
    }
    chdir(dir);
  } else {
    chdir(info->argv[1]);
  }

  if (chdir_ret == -1) {
    printf("can't cd to %s\n", info->argv[1]);
    return -1;
  }

  setenv("OLDPWD", s, 1);
  setenv("PWD", getcwd(buffer, 1024), 1);

  return 0;
}

/**
 * Prints the help message for a given command.
 *
 * @param info The shell's information structure.
 *
 * @return 0 if successful, -1 otherwise.
 */
int my_help(info_t *info) {
  char **arg_array;

  arg_array = info->argv;
  printf("help call works. Function not yet implemented \n");
  if (0)
    printf("%s\n", *arg_array); /* temp att_unused workaround */
  return 0;
}

