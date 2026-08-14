#include <stdio.h>
int main(void) {
  int numbers[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                     11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int target = 38;

  for (int i = 0; i < 20; ++i) {
    if (target == numbers[i]) {
      return printf("Found: %d \n", numbers[i]);
      break;
    }
  }
  printf("Target not found\n");
}
