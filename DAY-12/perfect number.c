#include <stdio.h>

int isPerfect(int num)
{
    int i, sum = 0;

    for(i = 1; i < num; i++)
    {
        if(num % i == 0)
            sum += i;
    }

    return (sum == num);
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if(isPerfect(number))
        printf("%d is a Perfect Number.\n", number);
    else
        printf("%d is not a Perfect Number.\n", number);

    return 0;
}