#include <stdio.h>

int getCharType(char ch) {
    int charType;
    
    if (ch >= 'A' && ch <= 'Z') {
        charType = 1;
    } else if (ch >= 'a' && ch <= 'z') {
        charType = 2;
    } else if (ch >= '0' && ch <= '9') {
        charType = 3;
    } else if (ch >= 32 && ch <= 126) {
        charType = 4;
    } else {
        charType = 5;
    }
    
    return charType;
}

int main() {
    char ch;
    
    printf("Enter a character: ");
    scanf(" %c", &ch);
    
    int result = getCharType(ch);
    
    switch (result) {
        case 1:
            printf("Type: 'A' to 'Z'\n");
            break;
        case 2:
            printf("Type: 'a' to 'z'\n");
            break;
        case 3:
            printf("Type: '0' to '9'\n");
            break;
        case 4:
            printf("Type: Any Other printable symbols\n");
            break;
        case 5:
            printf("Type: Non printable symbols\n");
            break;
    }
    
    return 0;
}
