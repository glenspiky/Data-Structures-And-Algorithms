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
  if (hash_table[index] != NULL) {
    return false;
  }
  hash_table[index] = p;
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

  person glen = {.name = "GLen", .age = 200};
  person jacob = {.name = "Jacob", .age = 200};

  hash_table_insert(&jacob);
  hash_table_insert(&glen);

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
