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

  if (head != NULL && strcmp(head->site, data) == 0) {
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
      _History *curr = temp;
      temp = temp->next;

      if (stack_size > 1) {
        free(curr);
        stack_size--;
      }
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
  while(1) {
    int options;

    printf("Choose give options below\n");
    printf("1 - Visit a site\n2 - Back\n3 - Display\n4 - Current Site\n5 - Exit\n");
    printf("Enter option: ");
    scanf("%d", &options);

    switch (options) {
      case 1: char visit_site[100];
        getchar();
        printf("\nEnter site url: ");
        fgets(visit_site, 100, stdin);
        visit_site[strcspn(visit_site, "\n")] = '\0';
        visit(visit_site);
        break;

      case 2: int pages;
        printf("No. of pgaes to go back: ");
        scanf("%d", &pages);
        back(pages);
        break;

      case 3: 
        printf("\n");
        display_history();
        printf("\n");
        break;

      case 4: 
        printf("\n");
        printf("Current Site: %s\n", current_site()->site);
        break;

      case 5: return 1;

      default: printf("Not valid\n");
        break;
    }
  }
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
