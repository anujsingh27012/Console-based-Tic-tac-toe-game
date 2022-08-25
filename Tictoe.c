#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<MMstream.h>
void check(char,char);
char a[9]={'1','2','3','4','5','6','7','8','9'}; //for the position number

void Name()
{
   system("color 2e");//Used for the color of console
           Beep(10,10);
           printf("\t\t\t\t\t------Wlecome To Game media-------");
           printf("\n\t\t\t\t\t------This is the TicToe Game------\n");
           PlaySound(TEXT("welcome to game media.wav"),NULL,SND_ASYNC);
           system("pause");//just like getch()
           fflush(stdin);

}
void show() //to show the position number;
{

     printf("\n\n\n\t\t\t\t\t___|___|___\n");
     printf("\t\t\t\t\t%c  | %c | %c \n",a[0],a[1],a[2]);
     printf("\t\t\t\t\t___|___|___\n");
     printf("\t\t\t\t\t%c  | %c | %c \n",a[3],a[4],a[5]);
     printf("\t\t\t\t\t___|___|___\n");
     printf("\t\t\t\t\t%c  | %c | %c \n",a[6],a[7],a[8]);
     printf("\t\t\t\t\t___|___|___\n");
     printf("\t\t\t\t\t   |   |   ");
}

void input_symbol()
{

    printf("\n\n \tPlayer 1 Symbol: X\n");
    printf("\tPlayer 2 Symbol: 0\n");

}

void start()
{
     system("color 84");//change the color once after the console is open
     char ch;
     printf("\n\tWho will start the game:: Player 1 or Player 2:: \n        -->");
     printf("\t");
     scanf("%c",&ch);
     Beep(550,80);

}

int count=0;//to count the no. of times user has input the symbol//
void play()
{
     system("color 74");
     char pos,sym;
     printf("\n\tenter the position and symbol\n");
     printf("\033[2;33m");
     printf("\t\t\t\t\t If you want to exit the game enter \"/\"\n");
     //printf("\033[0m");
     fflush(stdin);
     printf("\033[2;31m");
     printf("\t-->");
     scanf("%c",&pos);
     if(pos=="/")
        exit(0);
     Beep(550,80);
     fflush(stdin);
     printf("\n\t-->");
     scanf("%c",&sym);
     if(sym=="/")
         exit(0);
     Beep(550,80);
     count++;
     check(pos,sym);
}

void check(char POS,char SYM)
{  //POS = position and SYM = symbol

     int i;
     for(i=0;i<9;i++)
      {
        if(a[i]==POS)
        {
            a[i]=SYM;
        }
      }
}

int end() //to find who won the game
{
    //return 100 for x and return 200 for y
   if( (a[0]=='x'&&a[1]=='x'&&a[2]=='x')||(a[0]=='x'&&a[3]=='x'&&a[6]=='x')||(a[0]=='x'&&a[4]=='x'&&a[8]=='x') )
   return(100);
   else if( (a[0]=='0'&&a[1]=='0'&&a[2]=='0')||(a[0]=='0'&&a[3]=='0'&&a[6]=='0')||(a[0]=='0'&&a[4]=='0'&&a[8]=='0'))
   return(200);
   else if( (a[1]=='x'&&a[0]=='x'&&a[2]=='x')||(a[1]=='x'&&a[4]=='x'&&a[7]=='x') )
   return(100);
   else if( (a[1]=='0'&&a[0]=='0'&&a[2]=='0')||(a[1]=='0'&&a[4]=='0'&&a[7]=='0') )
   return(200);
   else if( (a[2]=='x'&&a[1]=='x'&&a[0]=='x')||(a[2]=='x'&&a[5]=='x'&&a[8]=='x')||(a[2]=='x'&&a[4]=='x'&&a[6]=='x') )
   return(100);
   else if( (a[2]=='0'&&a[1]=='0'&&a[0]=='0')||(a[2]=='0'&&a[5]=='0'&&a[8]=='0')||(a[2]=='0'&&a[4]=='0'&&a[6]=='0'))
   return(200);
   else if( (a[3]=='x'&&a[4]=='x'&&a[5]=='x') )
   return(100) ;
   else if( (a[3]=='0'&&a[4]=='0'&&a[5]=='0') )
   return(200)  ;
   else if(a[6]=='x'&&a[7]=='x'&&a[8]=='x')
   return(100);
   else if(a[6]=='0'&&a[7]=='0'&&a[8]=='0')
   return(200);
   else
     return(300);
}

main()
{
int result;
char ch;
labell:
    system("cls");//this is used when the user want to play the game again;
Name();
show();//to print the position number of each block;
input_symbol();
start();
play();

label:
system("cls");//this is to clear the screen after the user han given X or 0 as input;
show();//to print the format after the input is taken
input_symbol();
play();
result=end();
system("cls");
show();//to print winning format of blocks;

if(count<9)
{
    if(result==100)
     {
          printf("\n\tCongratulations Player 1 has won the Game\n");
          PlaySound(TEXT("made by anuj.wav"),NULL,SND_ASYNC);
          system("pause\n");
          count=0;//next time when the game restart the count will have some value;//
     }
    else if(result==200)
      {
          printf("\nCongratulations Player 2 has won the Game\n");
          PlaySound(TEXT("made by anuj.wav"),NULL,SND_ASYNC);
          system("pause\n");
          count=0;//next time when the game restart the count will have some value;//
      }
    else
      goto label;
}
else
   {
       printf("\n\tGame draw::\n");
       PlaySound(TEXT("made by anuj.wav"),NULL,SND_ASYNC);
          system("pause\n");
       count=0;
   }


 printf("\n\n\tWant to play again...?\n\n\tEnter 'y' for yes and 'n' for no:");
 fflush(stdin);
 scanf("%c",&ch);//to hold the 'y' or 'n';
 if(ch=='y'||ch=='Y')
  {
     a[0]='1';/*here we are overwriting because when the user want to play game again the box should display 123...9 again in box*/
     a[1]='2';
     a[2]='3';
     a[3]='4';
     a[4]='5';
     a[5]='6';
     a[6]='7';
     a[7]='8';
     a[8]='9';
    goto labell;
  }

getch();
}
