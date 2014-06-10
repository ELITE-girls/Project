/*
Birthday Paradox
Description:  
 In this program random values will be assigned between 1-365 
 where each day of year is having one value 
eg :-
       1 january = 1
       2 january = 2
       5 march = 65
       22 september = 264

If 23 persons are chosen at random, then the chances are more than 50%
                   that at least 2 will have the same birthday!

*/
    
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<TIME.h>
#include<math.h>
#define EXPO 2.718281828

float no_match(int group_size,int no_times);

void add_bday(int date[],int group_size);

void sorting(int date[],int group_size);

int chk_match(int date[],int group_size);

void main()
{

 int group_size,no_times=1000;
 float match=1.00,temp,prob,k,r;
time_t t;
clrscr();
srand(time(NULL));
//srand((unsigned)time(&t));
printf("\n********** Birthday Paradox *********\n\n");
printf("\nEnter the no. of people in a group :-  ");
scanf("%d",&group_size);
   /*match=no_match(group_size,no_times);
   r=(match/no_times);
   printf("\nResult :- \n %d out of 1000 %f  of the groups contained matching birthdays.\n",match,r);
*/
 k=group_size*group_size;
 temp=k/730;
 prob=(1-pow(2.7178,(-temp)))*100;
 printf("\n\nprobability of repeating same birthdays:-  %f %",prob);
 getch();
}

float no_match (int group_size, int no_times)
{
int date[1001];       //makes array with size the same as the number we want

int k=0;
float Matches = 0;

while (k <= no_times-1)    //will exit after k = the number of sets
	  {
	  add_bday(date, group_size);  //will fill array with random bdays

	  sorting(date, group_size);         //sorts

	  if (chk_match(date,group_size))      //tests if matches
		 {
		 ++Matches;            //adds to number of matches found
		 }

	  ++k;
	  }
 return Matches;
}

void add_bday(int date[],int group_size)
{
int k=0;

while (k <= group_size-1)
	 {
	 date[k] = 1 + rand()% 365;   //random number between 1 and 365
	 ++k;
	 }

}

void sorting(int date[],int group_size)
{
 int s, Start, i,temp;

 for (Start = 0; Start < group_size-1; ++Start)
   {
   s = Start;

   for (i = Start + 1; i < group_size; i++)
	  if (date[i] < date[s])
		 s=i;
   temp=date[s];
   date[s]=date[Start];
   date[Start]=temp;
 }
}

int chk_match(int date[],int group_size)

{
int k=0 ;

while (k < group_size-1 )
	 {
	 if (date[k]==date[k+1])
		return 1;    //yes match
	 ++k;
	 }
 return 0;   //no match
 }

