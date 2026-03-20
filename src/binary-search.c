#include <stdio.h>

int binsearch(int x[], int item, int n);

int main()
{
    int arr[] = {1,2,3,4,5};
    printf("%d\n",binsearch(arr,3,sizeof(arr)/sizeof(int)));
}

int binsearch(int x[],int item,int n){
    int low,high,mid;
    
    low = 0;
    high = n - 1;
   
    while (low <= high){
        mid = (low + high)/2;
        if ((x[mid] = item)){
            return mid;
        }
        else if (x[mid] < item){
            low = mid;
        }
        else if(x[mid] > item){
            high = mid;
        }

    }
    return -1;

}
