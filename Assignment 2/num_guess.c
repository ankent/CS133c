	#include <stdio.h>
	#include <stdlib.h>

	int main()
	{
        int answer; // the answer
        int high =100;//High of range
	    int low = 1;//low of the range
        int contin=0;//contune the game!

        //intro to game and programmer
		printf("Number guessing game\n");
		printf("By Ann Kent\n");

		//game start
		printf("Welcome to the number guessing game. Player 1 will enter a number. Player 2 will get 5 tries to guess the number!\n");
        printf("Please enter a number between %d-%d:\n",low,high);
        scanf("%d", &answer);
        printf("okay Player 2, time to guess.\n");

    while(contin==0)
    {
	    int guess=1; // the guess
	    int countdown = 5;//countdown to the end of the game
	    int again;//play again!
	    int close; //keep track of the cloesest guess.
	    high = 100;//resetting high and low for loop
	    low = 1;

        while(countdown>0)
        {
            countdown--;
            printf("You have %d guesses left \n",countdown);
            printf("Guess a number between %d-%d:\n",low,high);
            scanf("%d", &guess);
            //printf("%d", guess); Testing guess, working!

            //diff = anser-guess;


            if( guess== answer)
            {
                printf("congrats you win!\n");
              //  contin=2; tried to break
               // around= 5;
                break;//get the heck out of my if loop!
            }
            if( guess>answer)
            {

                high = guess-1;
                printf("too high\n");
            }
            if( guess<answer)
            {
                low = guess+1;
                printf("too low\n");
            }
        }

        if(countdown<0);
        {
            printf("you ran out of guesses. Game over. ");
            printf("The secret number was: %d",answer);
            printf("your closest guess was %d \n",close);
        }

        printf("Want to play again? 1 for yes 2 for no: ");
        scanf("%d",&again);
        if(again==1)
        {
            contin = 0;
            printf("Player 1, please pick a new number: \n");
            scanf("%d",&answer);
            printf("okay Player 2, time to guess.\n");
            again = 0;

        }
        if(again==2)
        {
            printf("thanks for playing");
            contin = 1;
        }

    }
		return 0;
	}

