//there's only one thing now need to be done 
//a function that at each frame check if any of the body 
//elements's direction need to be changed 
//by checking transitions and the coordinate of the element
//if equal the element's direction is assigned to the transition's direction

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "snakeh.h"
int test;
direction newDirection;
char key;
int main()
{
	
    snake real;
    snake* me=&real;
    snakeInit(me);
    initiateExample(me);
    while(1)
    {
		elementDirection(me);
		if(!kbhit())
			{
				goForward(me);
				print(me);
			}
		else if(kbhit())
		{
			key=getch();
			if(key=='a')
				newDirection=LEFT;
			else if(key=='w')
				newDirection=UP;
			else if(key=='d')
				newDirection=RIGHT;
			else if(key=='s')
				newDirection=DOWN;
				
				
			newDirectionFunc(me , newDirection);
			goForward(me);
			print(me);
		}
	system("cls");
	}
    return 0;
}



/* me.snakeBody.length=35;
    snake *snakeptr=&me;
    printf("%d\n",snakeptr->snakeBody.length); //ok good :D

    int test[20];
    for(int i=0;i<20;i++)
    {
        if(i<=9)
            test[i]=i;
        else
            test[i]=(int)NULL;
    }

    for(int i=0;i<20;i++)
        printf("%d\n",test[i]);
        */
