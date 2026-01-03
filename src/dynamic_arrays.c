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
            array->items = realloc(array->items,array->size*(sizeof(array->size)));
        }
        array->items[array->count++] += item;
    

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
    printf("\n");
}
