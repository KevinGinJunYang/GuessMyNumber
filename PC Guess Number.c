#include <stdio.h>// import pre processors 
#include <stdlib.h>
#include <time.h>
#define MIN_NUMBER 1 // define the macros 
#define MAX_NUMBER 100
#define MAX_ATTEMPTS 5

int get_guess(int max, int min); // init methods 
int is_game_won(int secret, int guess);

int maxTries = MAX_ATTEMPTS; // global fields 
int randGuess;
int max;
int min;

int main(void){
int chosenValue;
    int failed = 1; // failed set to true for positive int 
    int restart = 1; 
    char input;
    max = MAX_NUMBER; // init 
    min = MIN_NUMBER;
    
    printf("Pick a number for the PC to try and guess. It has 5 attempts\n");
	scanf("%d",&chosenValue); // gets chosen value 
	printf("The number you have chosen is: %d\n",chosenValue);
	
	
    while(maxTries > 0){ // while tries is less than 5 loop 
    int inputGuess = get_guess(max, min); // get pc guess 
	printf("The PC has guessed %d\n",inputGuess);
	if(is_game_won(chosenValue,inputGuess) == 0){ // returns value of gamewon 
	printf("The computer found your number!\n");
    failed = 0; // failed set to false if won 
	break;
	
}
}


if(failed){
 printf("Game over. The number was %d!\n", chosenValue);// no more tries so end 
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



int get_guess(int max, int min){
	
	randGuess = ((max + min) / 2); // uses bisection to get values and halfs each time 
	
	return randGuess;
}



int is_game_won(int value, int guess){
	
	char help;
    
    if(value == guess){// checks if correct guess 
    return 0;
    }else if(value != guess){// checks if guess is greater then print message     
        printf("The PC gussed incorrectly!\n");
		printf("Help by giving it a hint using (l) if lower or (h) for higher\n");
    maxTries--; 
	while( help != 'l' && help != 'L' && help != 'h' && help != 'H' ){ // checks if valid input 
		help = getchar();
	}
	if(help == 'l' || help == 'L'){ // l for lower 
		printf("My number is lower\n");
		max = guess; // makes the max value = pc guess 
	}
	else if( help == 'h' || help == 'H' ){
		printf("My number is higher\n");
			min = guess;
	}
	}
    
    return 1;

}



