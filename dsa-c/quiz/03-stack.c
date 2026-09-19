
#include <stdio.h>
int stack_size = 8;
int top = -1;
int stack[8];

int is_full() {
  if (top == stack_size - 1) {
    return 1;
  }
  return 0;
}

int is_empty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}

int push(int data) {
  if (!is_full()) {
    top = top + 1;
    stack[top] = data;
    return data;
  }
  printf("Error, The stack is full\n");
  return 1;
}

int pop() {
  if (!is_empty()) {
    int value = stack[top];
    top = top - 1;
    printf("The poped element is -> %d\n", value);
    return value;
  } else {
    printf("The stack is emty\n");
    return 1;
  }
}

void print_stack() {
  for (int i = 0; i <= top; i++) {
    printf("%d\n", stack[i]);
  }
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  push(7);
  push(8);
  push(9);
  push(9);
  print_stack();
}
