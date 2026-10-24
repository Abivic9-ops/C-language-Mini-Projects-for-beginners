#include <stdio.h>
#include <string.h>

int main(){

    // A GAMIFIED STRING GAME

char noun[60] = "";
char verb[60] = "" ;
char adjective1[60] = "";
char adjective2[60] = "";
char adverb[60] = "";

printf("Enter an adjective (Hint : Description): ");
fgets(adjective1, sizeof(adjective1), stdin);
adjective1[strlen(adjective1) - 1] = '\0';  //cute

printf("Enter an noun (Hint :An animal or person): ");
fgets(noun, sizeof(noun), stdin);
noun[strlen(noun) - 1] = '\0'; //girl

printf("Enter an adjective (Hint : Description): ");
fgets(adjective2, sizeof(adjective2), stdin);
adjective2[strlen(adjective2) - 1] = '\0';  //fast

printf("Enter an verb (Hint : Ends with  -ing): ");
fgets(verb, sizeof(verb), stdin);  //interesting
verb[strlen(verb) - 1] = '\0';

printf("Enter an adverb (Hint : Description of a verb): ");
fgets(adverb, sizeof(adverb), stdin);
adverb[strlen(adverb) - 1] = '\0';  //admire

// The Outputs

printf("\nIn our reknowned school the top %s is always %s.\n.Moroever, she is %s and %s to score in class assignments.We all %s her prowess and aim to be better than her.", noun, adjective1, verb, adjective2, adverb); //In our reknowned school the top girl is always cute..Moroever, she is interesting and fast to score in class assignments.We all admire her prowess and aim to be better than her.


    return 0;
}