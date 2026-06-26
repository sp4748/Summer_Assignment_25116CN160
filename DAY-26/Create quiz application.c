#include <stdio.h>

int main() {
    int answer, score = 0;

    printf("===== Welcome to the Quiz Application =====\n\n");

    // Question 1
    printf("1. What is the capital of India?\n");
    printf("1. Mumbai\n2. Delhi\n3. Kolkata\n4. Chennai\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 2)
        score++;

    // Question 2
    printf("\n2. Which language is used for C programming?\n");
    printf("1. Compiler Language\n2. High-Level Programming Language\n3. Markup Language\n4. Database Language\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 2)
        score++;

    // Question 3
    printf("\n3. How many days are there in a leap year?\n");
    printf("1. 365\n2. 366\n3. 364\n4. 360\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 2)
        score++;

    // Question 4
    printf("\n4. Which symbol is used to end a statement in C?\n");
    printf("1. .\n2. :\n3. ;\n4. ,\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 3)
        score++;

    // Question 5
    printf("\n5. Which function is the entry point of a C program?\n");
    printf("1. start()\n2. run()\n3. main()\n4. init()\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 3)
        score++;

    // Display Result
    printf("\n===== Quiz Result =====\n");
    printf("Your Score: %d out of 5\n", score);

    if (score == 5)
        printf("Excellent! You got all answers correct.\n");
    else if (score >= 3)
        printf("Good Job!\n");
    else
        printf("Keep practicing!\n");

    return 0;
}