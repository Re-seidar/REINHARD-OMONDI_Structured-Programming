#include <stdio.h>

int main(void)
{
    float radius ,Area;

    // input radius from user
    printf("Enter the radius of the circle:");
    scanf("%f" , &radius );

    // calculate the surface area
    Area = 4*3.142*radius*radius ;

    //output the result
    printf("The surface area of the sphere : %f\n" , Area);




    return 0;


}
