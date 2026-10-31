#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 5

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node *top = NULL;

bool isEmpty();
bool isFull();
void push(int data);
int peek();
int pop();

void display();

int main() {
  printf("Before pop\n");
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  push(60);
  display();
  pop();
  printf("\n\nAfter pop\n");
  display();
  return 0;
}

bool isEmpty() {
  if (top == NULL) {
    return true;
  }

  return false;
}

bool isFull() {
  int count = 0;

  Node *temp = top;
  while(temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (count >= STACK_SIZE) {
    return true;
  }

  return false;
}

void push(int data) {
  if (isFull() == true) {
    printf("Stack is Full\n");
    return;
  }

  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;

  if (isEmpty() == true) {
    new_node->next = NULL;
    top = new_node;
    return;
  }

  new_node->next = top;
  top = new_node;
}

int peek() {
  return top->data;
}

int pop() {
  if (isEmpty() == true) {
    printf("Stack is Empty\n");
    return 1;
  }

  Node *temp = top;

  if (top->next == NULL) {
    top = NULL;
    free(temp);
    return 1;
  }
  top = top->next;

  free(temp);

  return top->data;
}

void display() {
  Node *temp = top;

  while(temp->next != NULL) {
    printf("%d\n|\n", temp->data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}
