#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Maxwords 200
#define Maxlen 10

int showhangman(int);

int main()
{
srand(time(NULL));
char guessword[Maxwords][Maxlen];
int wordread=0;

FILE *fp;
fp=fopen("words.txt","r");
if(fp==NULL)
{
printf("Failed to open the file\n");
}
char ip[40];
while(fgets(ip,40,fp))
{
sscanf(ip,"%s",guessword[wordread]);
wordread++;
}
printf("Total words read in from the file: %d\n\n",wordread);
fclose(fp);
printf("HINT: IT'S A COLOUR\n\n");
int randindex= rand()% wordread;
int lives=5;
int numcorrect=0;
int oldcorrect=0;
int lenword=strlen(guessword[randindex]);
int letguess[8]={0,0,0,0,0,0,0,0};
int loopindex=0;
int quit=0;
int letent;
char guess[20];

printf("It is a %d letter word\n",lenword);
printf("You have %d chances\n\n",lives);
while(numcorrect<lenword)
{
printf("\n\nHangman Word  ");
for(loopindex=0;loopindex<lenword;loopindex++)
{
if(letguess[loopindex]==1)
{
printf("%c ",guessword[randindex][loopindex]);
}
else
{
printf("_ ");
}
}
printf("\n");
printf("Number correct so far:%d\n",numcorrect);
printf("Enter a guess\n");
fgets(guess,20,stdin);
if(strcmp(guess,"quit")==0)
{
quit=1;
break;
}
letent=guess[0];
printf("Letter entered:%c\n",letent);

oldcorrect=numcorrect;
for(loopindex=0;loopindex<lenword;loopindex++)
{
if(letguess[loopindex]==1)
{
continue;
}
if(letent==guessword[randindex][loopindex])
{
letguess[loopindex]=1;
numcorrect++;
}
}
if(oldcorrect==numcorrect)
{
lives--;
printf("Sorry wrong\n");
showhangman(lives);
printf("No of lives reamining:%d\n",lives);
if(lives==0)
{
break;
}
}
else
{
printf("Correct guess\n");
showhangman(lives);
}
}
if(quit==1)
{
printf("The user quit early\n");
}
else if(lives==0)
{
printf("Sorry you lose ,The word was : %s\n",guessword[randindex]);
printf("THE MAN IS DEAD\n");
}
else
{
printf("!!!!YOU WIN!!!!\n");
}
return 0;
}

int showhangman(int lives)
{
switch(lives)
{
case 5: printf("===========\n");
	printf("     |     \n");
	printf("\n");
	break;
case 4: printf("===========\n");
	printf("     |     \n");
	printf("     0     \n");
	printf("\n");
	break;
case 3: printf("===========\n");
	printf("     |     \n");
	printf("     0     \n");
	printf("     |     \n");
	printf("     |     \n");
	printf("     |     \n");
	printf("\n");
	break;
case 2: printf("===========\n");
	printf("     |     \n");
	printf("     0     \n");
	printf("     |     \n");
	printf("    /|\\   \n");
	printf("     |     \n");
	printf("\n");
	break;
case 1: printf("===========\n");
	printf("     |     \n");
	printf("     0     \n");
	printf("     |     \n");
	printf("    /|\\   \n");
	printf("     |     \n");
	printf("    /      \n");
	printf("\n");
	break;
case 0: printf("===========\n");
	printf("     |     \n");
	printf("     0     \n");
	printf("     |     \n");
	printf("    /|\\   \n");
	printf("     |     \n");
	printf("    / \\   \n");
	printf("\n");
	break;
}
}
