#include <stdio.h>

void decimalTobinary(int decimalNumber)
{
    int binarynumber[32];
    int index=0;
    
    while(decimalNumber>0)
    {
        binarynumber[index]=decimalNumber%2;
        decimalNumber/=2;
        index++;
    }
    if(index==0)
    {
        printf("0\n");
    }
    else
    {
        for(int i=index-1;i>=0;i--)
        {
        printf("%d\n",binarynumber[i]);
        }
        
    }
    printf("\n");
}


int main() {
     int decimalNumber;
     printf("Enter the decimal number\n");
     scanf("%d",&decimalNumber);
     decimalTobinary(decimalNumber);
     

    return 0;
}