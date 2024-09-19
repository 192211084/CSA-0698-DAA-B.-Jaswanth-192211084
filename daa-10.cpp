#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return isPalindrome(str, start + 1, end - 1);
}
int main() {
    char str[100];
    int length;
    printf("Enter a string: ");
    scanf("%s",&str);
    length=strlen(str);
    if (isPalindrome(str, 0, length - 1))
        printf("\"%s\" is a palindrome.\n", str);
    else
        printf("\"%s\" is not a palindrome.\n", str);

    return 0;
}

