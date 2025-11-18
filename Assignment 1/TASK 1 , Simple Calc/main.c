#include <stdio.h>

int main() {
    int num1, num2;

    // Take two numbers as input
    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Perform arithmetic operations and display results
    printf("\n--- Calculation Results ---\n");

    // Addition
    printf("%d + %d = %d\n", num1, num2, num1 + num2);

    // Subtraction
    printf("%d - %d = %d\n", num1, num2, num1 - num2);

    // Multiplication
    printf("%d * %d = %d\n", num1, num2, num1 * num2);

    // Division (with check for division by zero)
    if (num2 != 0) {
        printf("%d / %d = %d\n", num1, num2, num1 / num2);
    } else {
        printf("%d / %d = undefined (cannot divide by zero)\n", num1, num2);
    }

    // Modulus (with check for modulus by zero)
    if (num2 != 0) {
        printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    } else {
        printf("%d %% %d = undefined (cannot modulus by zero)\n", num1, num2);
    }

    return 0;
}
