#include <stdio.h>

int evenIndices(int arr[], int size)
{
int sum=0;

    for(int i=0;i<size;i++)
    {
        if(i%2==0)
        {
            sum=sum+arr[i];
        }
    }
    return sum;
    
}

int oddIndices(int arr[], int size)
{
    int sum=0;
    
    for(int i=0;i<size;i++)
    {
        if(i%2!=0)
        {
            sum=sum+arr[i];
        }
    }
    return sum;
}

int main()
{
    int arr[]={64,84,21,36,17,90,77,10,48,55};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sumofEvenindices=evenIndices(arr,size);
    printf("The sum of even indies is : %d\n",sumofEvenindices);
    int sumofOddindices=oddIndices(arr,size);
    printf("The sum of odd indices is : %d\n",sumofOddindices);
    
    
    
    return 0;
}