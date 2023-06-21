#include <stdio.h>
#include <string.h>

int main() {
     char a[100];
     scanf("%s", a);
     int l=strlen(a);
     for(int i=0;i<l;i++)
     {
        if(isupper(a[i]))
        {
            printf("%c",tolower(a[i]));
        }
        else if(islower(a[i]))
        {
            printf("%c",toupper(a[i]));
        }
     }

    return 0;
}