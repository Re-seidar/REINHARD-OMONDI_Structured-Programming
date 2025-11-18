#include <stdio.h>

int main (void)
{
    char name[100];
    int length = 0;

    // ask ths user to enter a string
    printf("Enter your name :");
    scanf("%s" ,&name);

    // print the string back to the user
    printf("your name is: %s\n" ,name);

    // find and display the length of the string
    while (name[length] != '\0'){
        length++;
    }
    printf("The length of the string is: %d\n", length);



    return 0 ;
}
