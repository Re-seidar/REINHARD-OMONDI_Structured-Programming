#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;

    // Input number of elements
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Input %d elements in the array :\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Display result
    printf("\nSum of all elements stored in the array is : %d\n", sum);

    return 0;
}
