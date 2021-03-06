#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

extern const int kTableSize;
extern const char* kDummy;

typedef struct KeyValue {
    char *key;
    char *value;
} key_value;

typedef struct HashTable {
    key_value **data;
    int size;
} hash_table;

hash_table *create_hash_table(int size);

int hash(char *key, int m);

bool exists(hash_table *table, char *key);

void add(hash_table *table, char *key, char *value);

char *get(hash_table *table, char *key);

void delete(hash_table *table, char *key);

void check_address(void *addr);

void destroy_table(hash_table* table);


#endif
