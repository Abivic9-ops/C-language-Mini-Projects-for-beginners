// A Shopping Cart Program for purchasing of a single item based on a buyer's input

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(){

    char item[50] = "";
    float price = 0.0f;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;
    bool hasPaid = false;

 // The User inputs cause it is more of an order thing
printf("What item would you like to buy?: ");
fgets(item, sizeof(item), stdin); //Stanley Cup
item[strlen(item)- 1] = '\0'

printf("What is the price for each?: ");
scanf("%f", &price); // 26.23

printf("How many would you like?: ");
scanf("%d", &quantity);  // 7

// Total

total = price * quantity ; //Compute is done based on your inputs on the above (26.23 * 7)

printf("Here is the resultant summation:%c %.2f\n",currency, total);

// A Manual to check on whether the Customer has sucessfully cashed out the items which is a conditional statement.
  {(hasPaid) ? 
    printf("Our esteemed customer,you have successfully purchased %d %s/s.Do have a lovely nice day!\n",quantity, item): printf("Kindly follow on the steps correctly and have the inputs in a perfect order");
  };

    return 0;
}