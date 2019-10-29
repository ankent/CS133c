	#include <stdio.h>
	#include <string.h>

	int main()
	{
        char answer[100]; // the answer
        //int high =100;//High of range
	   // int low = 1;//low of the range
        int contin=0;//contune the game!

        //intro to game and programmer
		printf("Word guessing game\n");
		printf("By Ann Kent\n");

		//game start
		printf("Welcome to the word guessing game. Player 1 will enter a word. Player 2 will get 5 tries to guess the word!\n");
        printf("Please enter a word: ");
        scanf("%s", &answer);
        printf("okay Player 2, time to guess.\n");

    while(contin==0)
    {
	    char guess[100]; // the guess
	    int countdown = 5;//countdown to the end of the game
	    int again;//play again!
	    int result; //do the words match?


        while(countdown>0)
        {
            countdown--;
            printf("You have %d guesses left \n",countdown);
            printf("Guess a word:\n");
            scanf("%s", &guess);
            result = strcmp(answer, guess);



            if( result== 0)
            {
                printf("congrats you win!\n");
                break;//get the heck out of my if loop!
            }
            if( guess>answer||guess<answer)
            {

                printf("Sorry, not correct.\n");
            }

        }

        if(countdown<0);
        {
            printf("you ran out of guesses. Game over. ");
            printf("The secret word was: %d\n",answer);
        }

        printf("Want to play again? 1 for yes 2 for no: ");
        scanf("%d",&again);
        if(again==1)
        {
            contin = 0;
            printf("Player 1, please pick a new word: \n");
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

