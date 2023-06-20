#include <math.h>
#include <stdio.h>

int binaryToDecimal(int binaryNumber)
{
    int decimalNumber=0;
    int i=0;
    int remainder;
    
    while(binaryNumber!=0)
    {
        remainder=binaryNumber%10;
        binaryNumber/=10;
        decimalNumber+=remainder * pow(2,i);
        ++i;
        
    }
    return decimalNumber;
}

int main()
{
    int binaryNumber;
    printf("Enter the binary number\n");
    scanf("%d",&binaryNumber);
    int DecimalNumber;
    DecimalNumber=binaryToDecimal(binaryNumber);
    printf("decimal number is %d\n",DecimalNumber);
    
    
    return 0;
}