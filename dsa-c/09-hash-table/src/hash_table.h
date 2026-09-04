typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int count;
  ht_item **item;
} ht_hash_table;
