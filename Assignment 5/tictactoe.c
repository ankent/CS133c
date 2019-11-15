#include <stdio.h>
#include <conio.h>
#include <string.h>
//Code by ann kent, referenced Alexander Mote

int check(char table[]){
    //checks callums
    int i;
    for( int i=0; i< 3; i++){
        if(table[i] == table[i+3]&& table[i+3]== table[i+6]){
            return 1;
            printf("q");
        }
    }
    //checks rows
    for( int i=0; i<6; i+=3){
        if(table[i] == table[i+1]&& table[i+1]== table[i+2]){
            return 1;
            printf("w");
        }
    }

    i=1;
        if(table[i*0] == table[i*4]&& table[i*4]== table[i*8]){
            return 1;
            printf("e");
        }

        if(table[i*2] == table[i*4]&& table[i*4]== table[i*6]){
            return 1;
            printf("r");
        }


}

int draw(char table[]){

printf("  %c|%c|%c\n",table[0],table[1],table[2]);
printf("  - - -\n");
printf("  %c|%c|%c\n",table[3],table[4],table[5]);
printf("  - - -\n");
printf("  %c|%c|%c\n",table[6],table[7],table[8]);



}


int main()
{

    char turn = 'x';
    int place;
    int contin=0;//contune the game!
    int coutdown=9;
    int again; //play again
    printf("Tic Tac Toe, Three In a Row!\n");



    while(contin==0){
            char table[10] = {'0','1','2','3','4','5','6','7','8','\0'};

    while(coutdown>0){
        coutdown--;
        draw(table);
        printf("You go Player %c:\n",turn);
        scanf("%d", &place);
        while (getchar() != '\n');


        table[place] = turn;
        if(check(table)== 1){
            printf("Player %c Wins",turn);
            break;
        }

        if(turn== 'x'){
            turn='o';
        }
        else{
            if(turn=='o'){
                turn='x';
            }
        }
    }

    if(coutdown<0){
        printf("Ran out of turns with no winners, Cat's game.\n");
    }

    printf("Want to play again? 1 for yes 2 for no: ");
    scanf("%d",&again);
    if(again==1)
    {
        contin = 0;
        again = 0;
        }

    if(again==2)
    {
        printf("thanks for playing");
        contin = 1;
        }

    }




}


