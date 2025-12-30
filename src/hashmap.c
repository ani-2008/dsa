#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    uint32_t key;
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

ht_item *new_item(uint32_t k, int v)
{
    ht_item *item = malloc(sizeof(ht_item));
    item->key = k;
    item->value = v;
    return item;
}

int hash_func(uint32_t k, int m)
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
    
    int org_hash = hash_key;

    while((table->items)[hash_key] != NULL){
        hash_key = (hash_key + 1) % table->size;
        if(org_hash == hash_key){
            printf("ERROR: no empty buckets\n");
            return 1;
        }

    }
    (table->items)[hash_key] = item;
    table->count++;
    return 0;
}

int search_ht(hash_table *table, uint32_t key)
{
    int hash_key = hash_func(key,table->size);
    int org_hash = hash_key;

    while(table->items[hash_key] != NULL){
        if(table->items[hash_key]->key == key){
            return table->items[hash_key]->value;
        }
        hash_key = (hash_key + 1) % table->size;
        if(org_hash == hash_key){
            break;
        }
    }
    
    return -1;
    
}

int del_item(hash_table *table, uint32_t k)
{
    int hash_key = hash_func(k,table->size);
    int org_hash = hash_key;

    while(table->items[hash_key] != NULL){
        if(table->items[hash_key]->key == k){
            free(table->items[hash_key]);
            table->items[hash_key] = NULL;
            table->count--;
            return 0;
        }
        
        hash_key = (hash_key + 1) % table->size;

        if (org_hash == hash_key){
            break;
        }
    }
    return -1;
}

void del_table(hash_table *ht)
{
    for(size_t i = 0; i < ht->size; i++){
        if(ht->items[i] != NULL){
            free(ht->items[i]);
        }
    }
    free(ht->items);
    free(ht);

}

int main()
{
    hash_table *ht = init_table();
    
    uint32_t key = 1;
    int val = 25;
    ht_item *item1 = new_item(key,val);
    int hashed = hash_func(key,ht->size);
    insert_ht(ht, item1, hashed);
    printf("value for the key 1 is : %d\n",search_ht(ht,key)); // value for the key 1 is : 25
    
    uint32_t key2 = 2;
    int val2 = 9;
    ht_item *item2 = new_item(key2,val2);
    int hashed2 = hash_func(key2,ht->size);
    insert_ht(ht,item2, hashed2);
    if (search_ht(ht,key2) < 0)
        printf("Key %d not found !!!\n",key2);
    else
        printf("value for the key 2 is : %d\n",search_ht(ht,key2)); //value for the key 2 is : 9
    
    del_item(ht,key); // key 1 is deleted from table
    
    if(search_ht(ht,key) < 0)
        printf("key %d not found !!!\n",key);
    else 
        printf("value for the key 1 is : %d\n",search_ht(ht,key));

    del_table(ht);

    /*
     * resizing
     * fix: duplicate keys
    */
}
