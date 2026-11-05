# include <stdio.h>
# include <stdlib.h>

int main(){

    // char programStatus = '\0';
    int userChoice;
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;


    printf("\n === The Basic Calculator ===\n"
        " 1. Add\n"
        " 2. Subtract\n"
        " 3. Multiply\n"
        " 4. Divide\n"
//     (" 5. Modulo (remainder)");
//     (" 6. Power");
//     (" 7. Square root");
//     (" 8. Factorial");
//     (" 9. Sine (radians)");
//     ("10. Cosine (radians)");
//     ("11. Tangent (radians)");
// 0   ("12. Natural logarithm");
//     ("13. Base-10 logarithm");
       "0. Exit\n"
    "Do enter your choice of operation : ");
    scanf("%d", &userChoice);
    
// Condition to be evaluated for the user
if(userChoice == 0) {
printf("Exiting Calculator...Goodbye!!\n");
 }
 else if(userChoice >= 1 && userChoice <= 4) {
    
//  Input from the user to be computed
printf("Enter the first number : ");
scanf("%lf",&num1);


//  Input from the user to be computed
printf("Enter the second number : ");
scanf("%lf",&num2);

switch (userChoice){
case 1:
printf("Result : %.1lf + %.1lf = %.1lf\n", num1,num2,num1 + num2);
break;

case 2:
printf("Result : %.1lf - %.1lf = %.1lf\n", num1, num2 , num1 - num2);
break;

case 3:
printf("Result : %.1lf * %.1lf = %.1lf\n", num1,num2, num1 * num2);
break;
// Division
// We have to enter a condition to cater for the udefined cases and math error and also infinity
case 4:
if(num2 != 0){
printf("Result : %.1lf / %.1lf = %.1lf\n", num1 ,num2, num1 / num2);
}else if(num1 == 0){
    printf("The result %.1lf MUST be 0", num1 / num2);
}
else {
    printf("Error!This is a Math Error\n");
};
break;

}
else{
printf("Invalid choice.Please do pick a number from 0 to 4 to continue\n");
 }
 
return 0;
}