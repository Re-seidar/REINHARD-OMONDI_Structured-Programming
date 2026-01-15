#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Input the size of array : ");
    scanf("%d", &n);

    int arr[n + 1]; // Create array with one extra space for insertion

    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Display current array
    printf("\nThe current list of the array : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value, position;

    printf("\nInput the value to be inserted : ");
    scanf("%d", &value);

    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &position);

    // Validate position
    if(position < 0 || position > n) {
        printf("Invalid position! Position should be between 0 and %d\n", n);
        return 1;
    }

    // Shift elements to the right from the insertion point
    for(int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value
    arr[position] = value;

    // Display the new array
    printf("After Insert the element the new list is : ");
    for(int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
