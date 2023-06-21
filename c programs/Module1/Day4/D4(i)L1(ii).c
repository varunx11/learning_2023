#include <stdio.h>

int findMin(int arr[], int size)
{
    int min=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]<min)
        {
        min=arr[i];
        }
    }
    
    return min;
    
}

int findMax(int arr[], int size)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    
    return max;
}


int main() {
       int arr[]={64,84,20,36,12,90,72,10,45,56};
       int size=sizeof(arr)/sizeof(arr[0]);
       int minNumber=findMin(arr,size);
       printf("The minimun number is %d\n", minNumber);
       int maxNumber=findMax(arr,size);
       printf("The maximum number is %d\n", maxNumber);
       return 0;
}