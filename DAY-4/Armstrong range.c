#include <stdio.h>
#include <math.h>

int main() {
    int lower, upper, num, temp, remainder, digits;
    double sum;

    printf("Enter lower limit: ");
    scanf("%d", &lower);

    printf("Enter upper limit: ");
    scanf("%d", &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);

    for (num = lower; num <= upper; num++) {
        temp = num;
        digits = 0;
        sum = 0;

        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = num;

        while (temp != 0) {
            remainder = temp % 10;
            sum += pow(remainder, digits);
            temp /= 10;
        }

        if ((int)sum == num)
            printf("%d ", num);
    }

    return 0;
}