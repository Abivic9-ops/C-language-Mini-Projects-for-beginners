#include <stdio.h>
#include <string.h>


int main(){

    char name[50] = "";
    char dayOfTheWeek = '\0';
    int validDay = 0;   // 0 means "no valid day entered yet"

    // The Name of User
    printf("Enter your name: ");
      fgets(name, sizeof(name),stdin);

      // Only remove the newline if fgets actually read something
      if (strlen(name) > 0) {
          name[strlen(name)-1] = '\0';
      }
 
      // A condition that makes the User to enter their name 
      if (strlen(name) == 0) {
          printf("Kindly enter your name to proceed\n");
          return 0;   // stop here, there is nothing more to do
      }

// Get a users input based on a character he or she selects
  printf("Enter a day of the week ( M, T, W, R, F, S, U): ");
    scanf("%c",&dayOfTheWeek);

    // The Condition 
   switch(dayOfTheWeek){  
        case 'M' :
        printf("Learn C basics from Free Code Camp!\n");
        validDay = 1;
        break;
          case 'T' :
        printf(" Move on to work on the Functions\n");
        validDay = 1;
        break;
          case 'W' :
        printf(" Craft a random guessing number\n");
        validDay = 1;
        break;
          case 'R' :
        printf(" Do the daily activity: Temperature Converter?\n");
        validDay = 1;
        break;
          case 'F' :
        printf("Getting links to other C content to work on\n");
        validDay = 1;
        break;
        case 'S' :
        printf("A Networking Day at the Nairobi Hackathon!!\n");
        validDay = 1;
        break;
          case 'U' :
        printf("Huree!A Resting and meditation  Day\n");
        validDay = 1;
        break;
        default :
       printf("You are required to first enter a character only from the set \n");
    }

    // validDay is still 0 if the switch fell into default
    if(validDay == 1){
        printf("Dear %s,your plan for the day has been processed successfully\n",name);
  }else {
        printf("Dear %s,an error was encountered,try again\n",name);
  }

    return 0;
}