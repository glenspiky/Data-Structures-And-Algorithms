#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
  char name[MAX_NAME];
  int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
  int length = strlen(name);
  unsigned int hash_value = 0;
  for (int i = 0; i < length; i++) {
    hash_value += name[i];
    hash_value = hash_value * name[i] % TABLE_SIZE;
  }
  return hash_value;
}

void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

void print_table() {
  printf("Start\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
  printf("End\n");
}

bool hash_table_insert(person *p) {
  if (p == NULL)
    return false;
  int index = hash(p->name);
  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL) {
      hash_table[try] = p;
      return true;
    }
  }
  // if (hash_table[index] != NULL) {
  //   return false;
  // }
  // hash_table[index] = p;
  return true;
}

person *hash_table_lookup(char *name) {
  int index = hash(name);
  if (hash_table[index] != NULL &&
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
    return hash_table[index];
  } else {
    return NULL;
  }
}
int main() {
  init_hash_table();
  print_table();

  person alex = {.name = "Alex", .age = 25};
  person sara = {.name = "Sara", .age = 31};
  person liam = {.name = "Liam", .age = 19};
  person maya = {.name = "Maya", .age = 42};
  person emma = {.name = "Emma", .age = 22};
  person ryan = {.name = "Ryan", .age = 35};
  person zoe = {.name = "Zoe", .age = 29};
  person cole = {.name = "Cole", .age = 40};
  person mia = {.name = "Mia", .age = 24};

  hash_table_insert(&alex);
  hash_table_insert(&sara);
  hash_table_insert(&liam);
  hash_table_insert(&maya);
  hash_table_insert(&emma);
  hash_table_insert(&ryan);
  hash_table_insert(&zoe);
  hash_table_insert(&cole);
  hash_table_insert(&mia);
  print_table();

  person *tmp = hash_table_lookup("Jacob");

  if (tmp == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found %s.\n", tmp->name);
  }
  tmp = hash_table_lookup("Gorge");

  if (tmp == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found %s.\n", tmp->name);
  }

  // printf("Glen => %u\n", hash("Glen"));
  // printf("Jacob => %u\n", hash("Jacob"));
  // printf("Sara => %u\n", hash("Sara"));
  // printf("Bill => %u\n", hash("Bill"));
  // printf("John => %u\n", hash("John"));
  // printf("Jone => %u\n", hash("Jone"));
  // printf("joe => %u\n", hash("joe"));
  // printf("Sharon => %u\n", hash("Sharon"));
  // printf("Joy => %u\n", hash("Joy"));
  // printf("Jomes => %u\n", hash("James"));
}
