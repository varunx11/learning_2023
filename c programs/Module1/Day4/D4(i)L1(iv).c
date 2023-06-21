#include <stdio.h>

int findEvensum(int arr[],int size)
{
    int sum=0;
     for(int i=0;i<size;i++)
        {
            if(arr[i]%2==0)
            {
            sum=sum+arr[i];
            }
        }
        return sum;
}

int findOddsum(int arr[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2!=0)
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
    
    int evenSum=findEvensum(arr,size);
    printf("The sum of even numbers is :%d\n", evenSum);
    int oddSum=findOddsum(arr,size);
    printf("The sum of odd numbers is :%d\n", oddSum);
    
    

       return 0;
}