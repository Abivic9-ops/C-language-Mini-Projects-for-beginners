#include <stdio.h>
#include <math.h>

int main(){

const double PI = 3.14159;
double radius = 0.0;
double area = 0.0;
double surfaceArea = 0.0;
double volumeOfSphere = 0.0;

// Input the radius quote
printf("Enter the radius: ");
scanf("%lf", &radius);

// We calculate the  of circle
area = PI * pow(radius, 2);
printf("Area: %.2lf\n", area);
// the Surface area
surfaceArea = 4 * PI * pow(radius, 2);
printf("Surface area: %.2lf", surfaceArea);
// The Volume of Sphere
volumeOfSphere = (4.0/3.0) * PI * pow(radius, 3);
printf("Volume of Sphere : %.2lf", volumeOfSphere);

    return 0;
}

