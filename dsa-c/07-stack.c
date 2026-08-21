
#include <stdio.h>
int max_size = 8;
int stack[8];
int top = -1;

int is_empty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int peek() { return stack[top]; }

int is_full() {
  if (top == max_size) {
    return 1;
  } else {
    return 0;
  }
}

int pop() {
  int data;
  if (!is_empty()) {
    data = stack[top];
    top = top - 1;
    return data;
  } else {
    printf("There was an error! probably the stack is empty!\n");
    return 0;
  }
}
int push(int data) {
  if (!is_full()) {
    top = top + 1;
    stack[top] = data;
    return data;

  } else {
    printf("The stack is filled up to the top");
    return 0;
  }
}

int main() {
  push(3);
  push(2);
  push(5);
  push(8);
  push(9);

  printf("Element at the top of the stack is : %d \n", peek());
  pop();
  printf("Element at the top of the stack is : %d \n", peek());

  while (!is_empty()) {
    int data = pop();
    printf("%d \n", data);
  }
  return 0;
}
