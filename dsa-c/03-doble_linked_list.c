#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

int main(void) {
  Node *head = NULL;
  head = malloc(sizeof(Node));

  head->data = 10;
  head->prev = NULL;
  head->next = NULL;

  Node *second = malloc(sizeof(Node));

  second->data = 20;
  second->prev = head;
  second->next = NULL;

  head->next = second;

  Node *tail = malloc(sizeof(Node));

  tail->data = 30;
  tail->prev = second;
  tail->next = NULL;

  second->next = tail;

  printf("%d -> %d -> %d\n", head->data, head->next->data,
         head->next->next->data);

  printf("%d <- %d\n", tail->data, tail->prev->data);

  return 0;
}
