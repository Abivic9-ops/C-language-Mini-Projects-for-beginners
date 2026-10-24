// User Input Mini System for Unversity Students

#include <stdio.h>
#include <string.h>

 int main (){

    char name[50] = "";
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    
// Getting the User input

        printf("Enter your name: ");
      fgets(name, sizeof(name),stdin);
      name[strlen(name)-1] = '\0';
    //   Conditions
      (strlen(name) == 0) ? 
      printf("You did not enter your name.Kindly enter your name above\n") :

       printf("Enter your curent age: ");
   scanf("%d", &age);
   (age <= 14 ) ? printf("Kindly enter your curent age again: ") : 

       printf("Enter your KCSE Mean Score: \n");
   scanf("%f", &gpa);

       printf("Enter your KCSE Grade: \n");
    scanf(" %c", &grade);

    // The Outputs as per the User input
    printf("My name is %s\n",name );
    printf("I am %d years old\n",age);
    printf("This is the score i amassed in the KCSE: %.2f\n",gpa);
    printf("I had a grade of %c in the KCSE\n",grade);

   
    return 0;

 }