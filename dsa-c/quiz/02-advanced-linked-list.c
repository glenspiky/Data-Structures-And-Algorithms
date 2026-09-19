#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

// not using it for now
typedef struct {
  Node *head;
  Node *tail;
  size_t *size;
} linked_list;

Node *create_node(int data) {
  Node *node = malloc(sizeof(Node));

  if (node == NULL)
    return NULL;

  node->data = data;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

void append(linked_list *list, Node **head, int data) {
  // crete new node
  Node *new_node = create_node(data);

  if (new_node == NULL) {
    return;
  }

  // Check if the head is empty then initialize it if emty
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  // if the head is not emty we make the current node to point the head
  Node *current = *head;

  // move the current to the last node so that we can append the new node
  // now current points to head since head is not NULL it points to lets say
  // next node which is 10, the loop will continue to run until it reaches the
  // last node which will be pointing ot NULL Litterally we are noving current
  // from head to last node
  while (current->next != NULL) {
    current = current->next;
  }
  // We have found the last lelement now we add the new node to it
  current->next = new_node;
  new_node->prev = current;
}

void print_foword(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d<->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void print_backword(Node *head) {
  if (head == NULL) {
    return;
  }
  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }
  while (current != NULL) {
    printf("%d<->", current->data);
    current = current->prev;
  }
  printf("NULL\n");
}
int main(void) {
  Node *head = NULL;

  append(&head, 10);
  append(&head, 20);
  append(&head, 30);
  append(&head, 40);

  printf("Forward: ");
  print_foword(head);

  printf("Backward: ");
  print_backword(head);

  return 0;
}
