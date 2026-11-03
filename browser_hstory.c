#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _history{
  char site[100];
  struct _history *next;
} _History;

int stack_size = 0;

_History *head = NULL;

void visit(char *data) {

  if (!data) {
    printf("Invalid Data\n");
    return;
  }

  _History *visited = malloc(sizeof(_History));

  if (!visited) {
    printf("Memory Allocation failed\n");
    return;
  }

  strcpy(visited->site, data);

  if (head == NULL) {
    head = visited;
    visited->next = NULL;
    stack_size++;
    return;
  }

  _History *temp = head;

  head = visited;
  visited->next = temp;
  stack_size++;
}

void back(int time_back) {

  if (stack_size == 1 || head->next == NULL || time_back == 0) {
    return;
  }

  _History *temp = head;

  if (time_back >= stack_size) {


    while(temp->next != NULL) {

      if (stack_size > 1) {
        free(temp);
        stack_size--;
      }

      temp = temp->next;
    }

    head = temp;

    printf("No further History\n");
    return;
  }

  for(int i = 0; i < time_back; i++) {
    _History *curr = temp;
    temp = temp->next;
    free(curr);
  }

  head = temp;
}

_History *current_site() {
  return head;
}

void display_history();

int main() {
  visit("google.com");
  visit("facebook.com");
  visit("youtube.com");
  display_history();
  back(1);
  visit("reddit.com");
  display_history();
  printf("%s", current_site()->site);
  return 0;
}

void display_history() {
  _History *temp = head;

  while(temp != NULL) {
    printf("%s -> ", temp->site);
    temp = temp->next;
  }

  printf("NULL\n");
}
