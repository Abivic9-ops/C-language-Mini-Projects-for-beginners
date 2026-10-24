// A WEIGHT CONVERTER PROGRAM FOR KILOGRAMS TO POUNDS OR VICE VERSA

#include <stdio.h>

int main(){

int userChoice = 0;
float pounds = 0.0f;
float kilograms = 0.0f;

printf("Weight Conversion Calculator\n");
printf("1. Kilograms to Pounds\n");
printf("2. Pounds to Kilograms\n");
// To get the User choice
printf("Enter your choice to execute(1 0r 2): ");
scanf("%d", &userChoice);

if(userChoice == 1){
    // Kilograms to Pounds
    printf("Enter the weight in Kilograms: ");
    scanf("%f", &kilograms);

    pounds = kilograms * 2.20462;

    // Output
    printf("%.1f is equal to %.1f pounds\n", kilograms, pounds);
}
else if(userChoice == 2){
    // Pounds to Kilograms
    printf("Enter the weight in pounds\n");
     scanf("%f", &pounds);

   kilograms =  pounds / 2.20462;

    // Output
    printf("%.1f is equal to %.1f pounds\n", pounds , kilograms);
}
else{
    // To Counter incase a user inputs a value that is not either a 1 or 2
    printf("Invalid choice!You are to enter either 1 or 2.\n");
}

return 0;
}