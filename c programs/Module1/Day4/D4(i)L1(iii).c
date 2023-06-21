#include <stdio.h>

int main()
{
    int arr[]={32,45,37,23,65};
    int revarr[5];
    int size=sizeof(arr)/sizeof(arr[0]);
    //printf("%d\n",size);
    for(int i=size-1;i>=0;i--)
    {
         revarr[size-1-i]=arr[i];
    }
    for(int i=0;i<size;i++)
    {
    printf(" %d\t", revarr[i]);
    }

       return 0;
}