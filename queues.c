#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *first = NULL;
Node *last = NULL;

void insertData(int data);
void display();
bool isEmpty();
bool isFull();
int peek();
void pop();

int main() {

  insertData(20);
  insertData(30);
  insertData(40);
  insertData(50);
  display();
  printf("Peek: %d\n", peek());
  pop();
  display();

  return 0;
}

void insertData(int data) {

  if (isFull() == true) {
    return;
  }

  Node *newnode = (Node*)malloc(sizeof(Node));

  if (isEmpty() == true) {
    newnode->data = data;
    newnode->next = NULL;
    first = newnode;
    last = newnode;
    return;
  }

  Node *temp = first;

  if (first->next == NULL) {
    newnode->data = data;
    newnode->next = NULL;

    temp->next = newnode;
    last = newnode;

    return;
  }

  while(temp->next != last->next) {
    temp = temp->next;
  }

  newnode->data = data;
  newnode->next = NULL;

  temp->next = newnode;
  last = newnode;
}

void display() {
  Node *temp = first;

  if (isEmpty() == false) {
    while(temp != last->next) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

bool isEmpty() {

  if (first == NULL && last == NULL) {
    return true;
  }

  return false;
}

bool isFull() {
  Node *temp = first;

  int count = 0;

  while(temp != NULL) {
    count++;
    temp = temp->next;
  }

  if (count >= 10) {
    return true;
  }

  return false;
}

int peek() {
  return first->data;
}

void pop() {
  Node *temp = first;
  first = first->next;

  free(temp);
}
