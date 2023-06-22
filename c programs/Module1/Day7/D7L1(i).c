#include <stdio.h>

int main()
{
   FILE *sourceFile , *destinationFile;
   char ch;

   sourceFile = fopen("sourceFile.txt","r");
   if (sourceFile==NULL)
   {
    printf("Unable to open source file\n");
    return 1;
   }

   destinationFile = fopen("destinationFile.txt","w");
   if (destinationFile==NULL)
   {
    printf("Unable to open destination file\n");
    fclose(sourceFile);
    return 1;
   }

   while((ch=getc(destinationFile))!=EOF){
   fputc(ch,destinationFile);
}

printf("File copied succesfully\n");

fclose(sourceFile);
fclose(destinationFile);
return 0;
}