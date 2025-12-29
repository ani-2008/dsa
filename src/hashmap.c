#include <stdio.h>
#include <stdlib.h>



typedef struct{
    unsigned int key;
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
    table->items = calloc(table->size,sizeof(ht_item*));
    return table;

}

ht_item *new_item(int k, int v)
{
    ht_item *item = malloc(sizeof(ht_item));
    item->key = k;
    item->value = v;
    return item;
}

int hash_func(unsigned int k, int m)
{
    const int PRIME = 997;
    k *= PRIME;
    k = k >> 2;
    return k % m;
}

int insert_ht(hash_table *table, ht_item *item,int hash_key)
{
    if((table->count) >= (table->size)){
        printf("ERROR: count is larger than table size\n");
        return 1;
    }
    table->count++;
    while((table->items)[hash_key] != NULL){
        hash_key++;
    }
    (table->items)[hash_key] = item;
    
    return 0;
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
    int k = 2;
    int v = 25;
    ht_item *item = new_item(k,v);
    
    hash_table *ht = init_table();
    
    int hashed_key = hash_func(item->key,ht->size);
    insert_ht(ht,item,hashed_key);
     


    del_table(ht);
}
