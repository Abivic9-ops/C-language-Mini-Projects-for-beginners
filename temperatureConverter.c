// A TEMPERATURE CONVERSION PROGRAM

#include <stdio.h>

int main(){

    char choice = '\0'; // Initialised a space in the memory for a character
    float fahrenheit = 0.0f;
    float celsius = 0.0f;

// The title
printf("Temperature Converter\n");
printf("C. Celsius to Fahrenheit\n");
printf("F. Fahrenheit to Celsius\n");
printf("Is the temperature in Celsius(C) or Fahrenheit (F)?:  ");
scanf("%c", &choice);

if (choice == 'C') {
    // C to 
  printf("Enter the Temperature in Celsius : ");
  scanf("%f", &celsius);
//   formula
fahrenheit = (celsius * 9/5) + 32; 
printf("Based on the conversion set above,then %.1f Celsius is equal to %.1f Fahrenheit\n",celsius, fahrenheit);

}
else if (choice == 'F') {
        // F to C
        printf("Enter the Temperature in Fahrenheit : ");
        scanf("%f", &fahrenheit);
//   formula
       celsius = (fahrenheit - 32) * 5 / 9; 
       printf("Based on the conversion set above,then %.1f Fahrenheit is equal to %.1f Celsius\n",fahrenheit, celsius);

}
else{
printf("Invalid choice! Please select C or F\n");
}

    return 0;
}