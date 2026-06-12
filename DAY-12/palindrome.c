#include <stdio.h>

int isPalindrome(int num)
{
    int original, reverse = 0, remainder;

    original = num;

    while (num != 0)
    {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num = num / 10;
    }

    if (original == reverse)
        return 1;  
    else
        return 0;   
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a Palindrome number.\n", number);
    else
        printf("%d is not a Palindrome number.\n", number);

    return 0;
}