#include <stdio.h>
#include <string.h>


// Problem definition
/* This weekend in Matopeni School,there is a Psychology Seminar by The Motivation Group that is to educate the student so on different trends and offer advise to the topics they have and answers alike.Though there is a catch to this.For the various sessions there is an age set for each that a student is to meet so as to enter a certain room as IDs will be generated later for each student.So do craft a program to tackle this and make the process efficient.*/

// Have a function to run checks on the student once entered
void studAgeCheck(int studAge){

    if(studAge > 17){
        printf("You are to go to Room 6\n");
    }else if(studAge == 17){
        printf("You are to go to Room 5\n");
    }else if(studAge >= 15){
        printf("You are to go to Room 4\n");
    }else if(studAge >= 13){
        printf("You are to go to Room 3\n");
    }else if(studAge >= 10){
        printf("You are to go to Room 2\n");
    }else{
        printf("You are to go to Room 1\n");
    }
}

int main(){

    char name[50] = "";
    int studAge = 0;

    printf("Enter your name : ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if(strlen(name) == 0){
        printf("Kindly enter your name to proceed\n");
        return 1;
    }

    printf("Enter your age : ");
    scanf("%d", &studAge);

    if(studAge < 1){
        printf("Invalid age.Kindly enter a valid age to proceed\n");
        return 1;
    }

    printf("Hello %s, ", name);
    studAgeCheck(studAge);

    return 0;
}
