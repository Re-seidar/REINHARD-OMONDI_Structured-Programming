#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;

    printf("Input the size of array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Bubble Sort algorithm
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nElements of array in sorted ascending order: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
