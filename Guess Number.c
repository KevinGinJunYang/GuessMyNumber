#include <stdio.h>// import pre processors 
#include <stdlib.h>
#include <time.h>
#define MIN_NUMBER 1 // define the macros 
#define MAX_NUMBER 100
#define MAX_ATTEMPTS 5

int generate_secret(int start, int end);
int get_guess(void);
int is_game_won(int secret, int guess);

int maxTries = MAX_ATTEMPTS;
int randGuess;

int main(void){
    
    
int getRandNum = generate_secret(MIN_NUMBER,MAX_NUMBER);
    int failed = 1; // failed set to true for positive int 
    int restart = 1; 
    char input;
    
    
    printf("Guess my number between 1 and 100. You have max. 5 attempts. \n");
    while(maxTries > 0){ // while tries is less than 5 loop 
    int inputGuess = get_guess();

if(is_game_won(getRandNum,inputGuess) == 0){ // if returned 0 then game won 
 printf("Congratulations! You found it!\n");
 failed = 0; // return failed to false
 break;
 
}



}


if(failed){
 printf("Game over. My number is %d.\n", getRandNum);// no more tries so end 
}
printf("Play again? (Y/N)"); 
    
while(input != 'Y' && input != 'y' && input != 'n' && input != 'N'){ // while inputs are not valid continue until found valid inputs 
    input = getchar();
}
   
if(input == 'Y'|| input == 'y'){ // if input is y restart game 
    maxTries = MAX_ATTEMPTS;
    main();
}
else if(input =='N'|| input == 'n'){ // ends game when input is n 
    printf("See you later!\n");   
    
 }

}

int generate_secret(int start, int end){
    srand(time(NULL));
    int random_number = (rand() % end ) + start; // generate random num using macros 
    return random_number;
    
}

int get_guess(void){
    scanf("%d", &randGuess); // gets user input 
    printf("Your guess: %d\n",randGuess);
    return randGuess;
}

int is_game_won(int secret, int guess){
    
    if(secret == guess){// checks if correct guess 
    return 0;
    }else if(secret > guess){// checks if guess is greater then print message     
        printf("Sorry... My number is bigger than yours.\n");
    maxTries--;
    
    }else{
         printf("Sorry... My number is smaller than yours.\n");
    maxTries--;
    
    }
    return 1; // didn't win 

}
