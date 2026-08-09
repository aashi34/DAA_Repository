// Q4. Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    j = strlen(str) - 1;

    for(i = 0; i < j; i++) {

        if(str[i] == ' ')
            continue;

        while(str[j] == ' ' || str[j] == '\n')
            j--;

        if(tolower(str[i]) != tolower(str[j])) {
            flag = 0;
            break;
        }

        j--;
    }

    if(flag == 1)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
