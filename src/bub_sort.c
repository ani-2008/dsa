#include <stdio.h>

void bub_sort(int arr[], int len);

int main()
{
    int array[] = {2,3,4,5,1};
    int n = 5;
    bub_sort(array,n);
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void bub_sort(int arr[], int len)
{
    int i,j;
    for (i = 0; i < len; i++){
        for (j = 0; j < (len-i-1); j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

}   


