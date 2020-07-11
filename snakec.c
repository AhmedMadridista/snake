#include <stdio.h>
#include <conio.h>
#include "snakeh.h"

void snakeInit(snake *me)
{
    me->head='>';
    me->headDirection=RIGHT;
    me->headCoordinate.x=30;
    me->headCoordinate.y=30;
    me->snakeBody.length=0;
    me->transitionNum=0;
}

void newDirectionFunc(snake *me, direction newDirection)//this function is good but it shouldn't update
{														//the head coordinatessince since this is done
 														//by goforward function .. so delete the headcoordinate
	if(newDirection!=me->headDirection)					//updating from it ... and add a part that concern
		{												//to make transations as a new direction is occured
			me->headDirection=newDirection;
			
			if(newDirection==UP){
				me->head='^';
				}
			
			else if(newDirection==DOWN){
				me->head='v';
				}
				
			else if(newDirection==RIGHT){
				me->head='>';
				}
			else if(newDirection==LEFT){
				me->head='<';
				}
		}
		
	me->transitionNum++;
	me->transition[me->transitionNum-1].x=me->headCoordinate.x;
	me->transition[me->transitionNum-1].y=me->headCoordinate.y;
	me->transitionDirection[me->transitionNum-1]=me->headDirection;
			
}

void goForward(snake *me)
	{
		int lengthCount;
		if(me->headDirection==UP)
			me->headCoordinate.x=me->headCoordinate.x - 1;
			
		else if(me->headDirection==DOWN)
			me->headCoordinate.x=me->headCoordinate.x + 1;
			
		else if(me->headDirection==RIGHT)
			me->headCoordinate.y=me->headCoordinate.y + 1;
			
		else if(me->headDirection==LEFT)
			me->headCoordinate.y=me->headCoordinate.y - 1;
		
		for(lengthCount=0;lengthCount<me->snakeBody.length;lengthCount++)
			{
				
		if(me->snakeBody.elementDirection[lengthCount]==UP)
			me->snakeBody.elementCoordinate[lengthCount].x=me->snakeBody.elementCoordinate[lengthCount].x - 1;
			
		else if(me->snakeBody.elementDirection[lengthCount]==DOWN)
			me->snakeBody.elementCoordinate[lengthCount].x=me->snakeBody.elementCoordinate[lengthCount].x + 1;
			
		else if(me->snakeBody.elementDirection[lengthCount]==RIGHT)
			me->snakeBody.elementCoordinate[lengthCount].y=me->snakeBody.elementCoordinate[lengthCount].y + 1;
			
		else if(me->snakeBody.elementDirection[lengthCount]==LEFT)
			me->snakeBody.elementCoordinate[lengthCount].y=me->snakeBody.elementCoordinate[lengthCount].y - 1;			
			
			}	
		
	}

void print(snake *me)
	{
		int i,j,lengthCounter,flag;
		for(i=0;i<=50;i++)
			{
				for(j=0;j<=50;j++)
					{
						if(i==me->headCoordinate.x&&j==me->headCoordinate.y)
							{
								
								printf("%c",me->head);	
								continue;
							}
							flag=0;						
						for(lengthCounter=0;lengthCounter<me->snakeBody.length;lengthCounter++)
							{
								if(i==me->snakeBody.elementCoordinate[lengthCounter].x&&j==me->snakeBody.elementCoordinate[lengthCounter].y)
									{
										printf("%c",me->snakeBody.element[lengthCounter]);
										break;
									}	
								else           //this flag is incremented each time if there's
									flag++;    //nothing to be printed whether a head or element  
							}				   //so we use it to print a space instead
							
						if(flag==me->snakeBody.length)
							printf(" ");
					}
				printf("\n");
			}	
	
	}
	
	
void initiateExample(snake *me)
	{
		me->snakeBody.length=29;
		int i;
		for(i=0;i<me->snakeBody.length;i++)
			{
				me->snakeBody.elementDirection[i]=RIGHT;
				me->snakeBody.element[i]='-';
				me->snakeBody.elementCoordinate[i].x=30;
				me->snakeBody.elementCoordinate[i].y=30-(i+1);
			}
	}

void elementDirection(snake *me)
	{

		int i,j,k;
		for(i=0;i<me->snakeBody.length;i++)
			{
				for(j=0;j<me->transitionNum;j++)
					{
						if(me->snakeBody.elementCoordinate[i].x==me->transition[j].x&&me->snakeBody.elementCoordinate[i].y==me->transition[j].y)
							{
								me->snakeBody.elementDirection[i]=me->transitionDirection[j];
								if(me->transitionDirection[j]==UP||me->transitionDirection[j]==DOWN)
									me->snakeBody.element[i]='|';
								else if(me->transitionDirection[j]==RIGHT||me->transitionDirection[j]==LEFT)
									me->snakeBody.element[i]='-';
								
						if(i==me->snakeBody.length-1) //if the transition element is the tail of snake
							{						  //delete the transition and displace the remaining 
													 //transition one place.
								for(k=0;k<me->transitionNum;k++)
									{
										me->transition[k].x= me->transition[k+1].x;
										me->transition[k].y= me->transition[k+1].y;
										me->transitionDirection[k]=me->transitionDirection[k+1];
									}
								me->transitionNum--;
							}
							}
					}
			}
	}
