#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    size_t count;
    size_t size;
} DynamicArray;

void append(DynamicArray *array, int item)
{
    
    if(array->count >= array->size){
        if(array->size == 0){
            array->size = 100;
        }else{array->size *= 2;}
        array->items = realloc(array->items,array->size*(sizeof(int)));
    }
    array->items[array->count++] = item; 

}

size_t len(DynamicArray *array)
{
    return array->count;
}

int get_ele(DynamicArray *array,size_t index)
{
    if(index > (array->count-1)){
        printf("Invalid index\n");
        return -1;
    }else{
        return array->items[index];
    }

}

int main()
{
    DynamicArray array = {0};

    for(int i = 0; i < 10; i++){
        append(&array,i);
    }
    
    for(size_t i = 0; i < 10; i++){
        printf("%d ",array.items[i]);
    }
    printf("\n"); // 0 1 2 3 4 5 6 7 8 9
    
    printf("%zu\n",len(&array)); // 10
    append(&array,10);
    printf("%zu\n",len(&array)); // 11
    printf("%d\n",get_ele(&array,10));
    
    free(array.items);
    /* TODO
     * delete from any index
     * update
    */
}
