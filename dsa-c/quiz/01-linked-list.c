#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

int main() {
  // Node is a pointer coz it stores the address of the first node
  Node *head = NULL;
  // Malloc reaturns a pointer to the allocated memory
  head = malloc(sizeof(Node));

  // we can acces the next node via the "->" operator. It means
  // Go to the Node that head points to, then access its data
  // We are not using the (.) becouse head is a pointer
  head->data = 10;
  head->prev = NULL;
  // We will update the next after we create the second node
  head->next = NULL;
  free(head);

  Node *second = malloc(sizeof(Node));

  // update the head to point to second
  head->next = second;
  second->data = 20;
  second->prev = head;
  second->next = NULL;

  free(second);

  Node *third = malloc(sizeof(Node));
  second->next = third;
  third->data = 30;
  third->prev = second;
  third->next = NULL;

  printf("%d", second->prev->data);

  free(third);
}
