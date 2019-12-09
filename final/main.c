#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "monster.h"
#include "person.h"

#define MONWIN 2
#define PLAYWIN 1


//Created by Ann Kent


//stages of grief

//denial
//anger
//bargaining
//depression
//acceptance


int main()
{
    int contin=0;
    char getname[20];
    int room = 0;
    int tryagain;
    int loadsavefile;
    char*save="file.txt";
    FILE*read;



    printf("You find yourself in a room.\n");
    printf("There is only one way forward. There is something in the next room.\n");
    printf("You are not a good fighter. But you can block to recover 5 health. Quick, ");


    struct Person player;


    printf("What is your name?: ");
    fgets(player.name, 20, stdin);
    player.phealth= 10;
    player.emotion= 0;
    printf("Do you have a save file you would like to load? yes(1) no(2) ");
    scanf("%d",&loadsavefile);

    if(loadsavefile==1){
        char convert;
        printf("\nloading Save...\n");
        read = fopen("file.txt", "r");
        convert = fgetc(read);
        room = atoi(&convert);
        fclose(read);
        if (read == NULL){
            printf("\nNo save file found\n");
            printf("starting game from beginning\n\n");
        }
        //FILE *fopen("file.txt","r" );
    }




    //creating monster 1, denial. Nothing special about this one
    struct monster denial;
    denial.mhealth = 10;
    denial.attack.lvl=5;

    struct monster anger;
    anger.mhealth=15;
    anger.attack.lvl=2;

    struct monster depression;
    depression.mhealth=15;
    depression.attack.lvl=2;



    while(room == 0){

        printf("You move forward to the next room\n");
        printf("You have entered the first room...there is a monster. You can't believe this is happening to you. Prepare to fight.");
        int fightresult = fight(denial.mhealth,player.phealth,denial.attack.lvl,player.emotion);


        if (fightresult== PLAYWIN){
            printf("\nYou defeated the monster.\n");
            room =1;
            player.emotion=1;

        }
        if (fightresult== MONWIN){
            printf("\nGame Over\n");
            printf("Try again? yes(1) no(2)\n");
            scanf("%d",&tryagain);
            if(tryagain==2){
                exit(0);
            }
        }

    }

    while(room==1){
        printf("\nYou have entered the second room...Prepare to fight.");
        int fightresult = fight(anger.mhealth,player.phealth,anger.attack.lvl,player.emotion);


        if (fightresult== PLAYWIN){
            printf("\nYou win\n");
            room =2;
            player.emotion=2;
            write(room);
        }
        if (fightresult== MONWIN){
            printf("\nGame Over\n");
            printf("Try again? yes(1) no(2)\n");
            scanf("%d",&tryagain);
            if(tryagain==2){
                exit(0);
            }
        }
    }
    while(room==2){
        printf("You have entered the third room...Prepare to fight.");
        int fightresult = fight(depression.mhealth,player.phealth,depression.attack.lvl,player.emotion);


        if (fightresult== PLAYWIN){
            printf("\nYou win\n");
            printf("\nEnd of Game. You Win!\n");
            room =2;
            exit(0);
        }
        if (fightresult== MONWIN){
            printf("\nGame Over\n");
            printf("Try again? yes(1) no(2)\n");
            scanf("%d",&tryagain);
            if(tryagain==2){
                exit(0);
            }
        }
    }

}

int fight(int monhealth, int playerhealth, int attack, int emotion){

    while(playerhealth>0 && monhealth>0){
        int move;
        int playerattack=2;
        int block=5;

        if(emotion==1){
            playerhealth=10;
            block=2;
            playerattack= 5;
            printf("\nYou are filled with rage. Blocking only recovers 2, Attack upped to 5\n");
        }

        if(emotion==2){
            playerhealth=10;
            block=6;
            playerattack=2;
            printf("\nDepression consumes you. Blocking recovers 6, Attack dropped to 2\n");

        }


        printf("\n\nYour health: %d  Monster Health: %d\n\n",playerhealth,monhealth);

        printf("It's your turn. Attack(1) or block(2)? ");
        scanf("%d",&move);

        if(move==1){
            printf("You attacked\n");
            monhealth=monhealth-playerattack;
            printf("Monster's health is now %d\n",monhealth);

        }
        if(move==2){
            printf("You prepare to block the Monster's attack.\n");
            if(playerhealth<10){
                playerhealth=playerhealth+block;
                printf("Health is: %d\n", playerhealth);
            }
            if(playerhealth>=10){
                printf("You are at full health\n");
            }

        }

        printf("The Monster is Attacking!\n");
        int monattack=random(attack);
        playerhealth=playerhealth-monattack;
        printf("\nYour health is now %d\n",playerhealth);
    }

   if(playerhealth<=0){
        return MONWIN;
        //game over
    }

    if(monhealth<=0){
        return PLAYWIN;
        //return 2;
    }


}

int random(int level){
    int hit;
    int min=1;
    //monster always does a min of 1 damage. Max damage is decided by level.
    hit = min + rand() / (RAND_MAX / (level - min + 1) + 1);
    return hit;
}


int write(roomnum){
    FILE*read;

    read = fopen("file.txt", "w");

    if (read == NULL){
    printf("Error saving file, your progress has not been saved.\n");
    return roomnum;
    }
    fprintf(read,"%d",roomnum);

    fclose(read);

}



