#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

int main(void) {
  struct node *head = NULL;
  head = (struct node *)malloc(sizeof(struct node));

  head->data = 45;
  head->link = NULL;

  struct node *second = malloc(sizeof(struct node));

  second->data = 80;
  second->link = NULL;

  head->link = second;

  struct node *third = malloc(sizeof(struct node));

  third->data = 100;
  third->link = NULL;

  second->link = third;

  printf("%d -> %d -> %d\n", head->data, head->link->data,
         head->link->link->data);

  free(head);
  free(second);

  return 0;
}
