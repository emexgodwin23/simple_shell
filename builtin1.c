#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alias {
  char *name;
  char *value;
};

struct alias_list {
  struct alias *head;
  struct alias *tail;
};

void init_alias_list(struct alias_list *list) {
  list->head = NULL;
  list->tail = NULL;
}

void add_alias(struct alias_list *list, char *name, char *value) {
  struct alias *new_alias = malloc(sizeof(struct alias));
  new_alias->name = name;
  new_alias->value = value;
  new_alias->next = NULL;

  if (list->head == NULL) {
    list->head = new_alias;
    list->tail = new_alias;
  } else {
    list->tail->next = new_alias;
    list->tail = new_alias;
  }
}

void print_alias_list(struct alias_list *list) {
  struct alias *node = list->head;

  while (node != NULL) {
    printf("%s=%s\n", node->name, node->value);
    node = node->next;
  }
}

int main() {
  struct alias_list alias_list;
  init_alias_list(&alias_list);

  add_alias(&alias_list, "ls", "list directory contents");
  add_alias(&alias_list, "cd", "change directory");
  add_alias(&alias_list, "pwd", "print working directory");

  print_alias_list(&alias_list);

  return 0;
}

