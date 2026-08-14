
#include <stdio.h>
int main(void) {
  int numbers[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                     11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int target = 16;

  int left = 0;
  int right = (sizeof numbers / sizeof numbers[0]) - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    printf("Checking index %d: %d\n", mid, numbers[mid]);

    if (numbers[mid] == target) {
      printf("Found: %d\n", numbers[mid]);
      break;
    };
    if (target > numbers[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}
