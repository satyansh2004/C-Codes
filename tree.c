#include <stdio.h>
#include <stdlib.h>

typedef enum {
  BFS,
  DFS_INORDER = 10,
  DFS_PREORDER,
  DFS_POSTORDER
} TRAVERSE_TYPES;

struct Node{
  int value;
  struct Node *left_child;
  struct Node *right_child;
};

typedef struct Node Node;

Node *root_node = NULL;

void add_node(int data) {

  Node *new_node = (Node*)malloc(sizeof(Node));

  if (!new_node) {
    printf("Memory Allocation failed!\n");
    return;
  }

  new_node->value = data;
  new_node->left_child = NULL;
  new_node->right_child = NULL;

  if (root_node == NULL) {
    root_node = new_node;
    return;
  }

  if (data == root_node->value && root_node != NULL) {
    return;
  }

  if (data < root_node->value && root_node->left_child == NULL) {
    root_node->left_child = new_node;
    return;
  }

  if (data > root_node->value && root_node->right_child == NULL) {
    root_node->right_child = new_node;
    return;
  }

  Node *temp = root_node;
  Node *curr = temp;

  while (temp != NULL) {
    if (data == temp->value) {
      return;
    }
    if (data < temp->value) {
      curr = temp;
      temp = temp->left_child;
    }
    else if (data > temp->value) {
      curr = temp;
      temp = temp->right_child;
    }
  }

  if (data > curr->value) {
    curr->right_child = new_node;
  }
  else if (data < curr->value) {
    curr->left_child = new_node;
  }
}

void traverse(Node *node, TRAVERSE_TYPES traverse_type) {

  if (node == NULL) {
    return;
  }

  if (traverse_type == DFS_PREORDER) {
    printf("%d ", node->value);
    traverse(node->left_child, DFS_PREORDER);
    traverse(node->right_child, DFS_PREORDER);
    return;
  }

  if (traverse_type == DFS_POSTORDER) {
    traverse(node->left_child, DFS_PREORDER);
    traverse(node->right_child, DFS_PREORDER);
    printf("%d ", node->value);
    return;
  }

  if (traverse_type == DFS_INORDER) {
    traverse(node->left_child, DFS_PREORDER);
    printf("%d ", node->value);
    traverse(node->right_child, DFS_PREORDER);
    return;
  }
}

int main(void) {
  add_node(20);
  add_node(10);
  add_node(30);
  add_node(50);
  add_node(5);

  traverse(root_node, DFS_PREORDER);
  printf("\n");
  traverse(root_node, DFS_POSTORDER);

  return 0;
}
