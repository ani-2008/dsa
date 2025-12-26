#include <stdio.h>
#include <stdlib.h>

// For simplicity data in Hash Table will be int(both key and value)

typedef struct{
    int key;
    int value;
}ht_item;

typedef struct{
    size_t size;
    size_t count;
    ht_item **items;
}hash_table;

hash_table *init_table()
{
    hash_table *table = malloc(sizeof(hash_table));
    table->size = 53;
    table->count = 0;
    table->items = calloc(table->size,sizeof(ht_item));
    return table;

}

ht_item *new_item(int k, int v)
{
    ht_item *item = malloc(sizeof(ht_item));
    item->key = k;
    item->value = v;
}

void del_item(ht_item *i)
{
    free(i);
}

void del_table(hash_table *ht)
{
    free(ht->items);
    free(ht);

}

int main()
{

}
