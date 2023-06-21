#include <stdio.h>


int main() {
       int arr[]={12,84,20,36,64,56,72,10,45,90};
       int size=sizeof(arr)/sizeof(arr[0]);
       int sum=0;
       int avg;
       for(int i=0;i<size;i++)
       {
           sum=sum+arr[i];
       }
       avg=sum/size;
       printf("The sum is %d\n", sum);
       printf("The average is %d\n", avg);
       return 0;
}