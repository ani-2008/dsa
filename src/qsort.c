#include <stdio.h>

void swap(int arr[],int i, int j);
void qsort(int arr[], int left, int right);

int main()
{    
    int arr[] = {2,10,3,1,6,4,7,8,5,9};
    int left = 0;
    int right = 9;
    
    qsort(arr,left,right);
    
    for (int i = 0; i <= right; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void qsort(int arr[], int left, int right)
{
    int last, i;

    if (left >= right)
        return;

    swap(arr,left,(left+right)/2);
    last = left;

    for (i = left+1; i <= right; i++){
        if (arr[i] < arr[left]){
            swap(arr,++last, i);
        }
        
    }
    swap(arr,left,last);
    qsort(arr,left,last-1);
    qsort(arr,last+1,right);
}

void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;

}
