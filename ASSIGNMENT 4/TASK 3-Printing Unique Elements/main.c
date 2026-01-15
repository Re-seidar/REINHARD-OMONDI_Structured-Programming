#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;

    printf("Print all unique elements of an array:\n");
    printf("------------------------------------------\n");

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe unique elements found in the array are: ");

    // Check each element for uniqueness
    for(int i = 0; i < n; i++) {
        int isUnique = 1;  // Assume element is unique

        // Compare with all other elements
        for(int j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                isUnique = 0;  // Found duplicate
                break;
            }
        }

        // If element is unique, print it
        if(isUnique) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");

    return 0;
}
