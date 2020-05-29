#include<stdio.h>
#include<stdlib.h>

char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char  user, comp, box;
char garbage;
int flag=0,points=0;
char loc_avail[9]={'1','2','3','4','5','6','7','8','9'};

void user_game();
void comp_game();
void check_game(char x);
void result(int x);

void main()
{
  printf("\t\tWELCOME TO TIC-TAC-TOE\n\nThe instructions for this game are as follows:\n1.The user must choose either 'X' or 'O'.\n2.The game always starts with 'X'.\n3.The boxes for the game are numbered as follows:\n");
  printf("\n\n");

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("\t%c\t|",matrix[i][j]);
    }
    printf("\n");
    if(i==2)
        continue;
    printf("   __________________________________________\n");
  }

  printf("\nThe user must enter the box number to fill in the that box.\n\nALL THE BEST!!!!\nPress any key to continue: ");
  scanf(" %c",&garbage);

  A: printf("What is your choice 'X' or 'O'? : ");
     scanf(" %c",&user);

  user=toupper(user);
  switch(user)
  {
    case 'X': comp='O';
              printf("\nAs you have chosen X, you must begin the game.");
              user_game();
              break;
    case 'O': comp='X';
              printf("\nAs you have chosen O, computer will begin the game.");
              comp_game();
              break;
    default: printf("INVALID CHOICE ENTERED.");
             goto A;
  }
}

void check_game(char Last_player)
  {
    //check if game is won.
    {
          char key1=matrix[1][1], key2=matrix[0][0], key3=matrix[2][2];
          if((key1==matrix[0][0] && key1==matrix[2][2]) || (key1==matrix[1][0] && key1==matrix[1][2]) || (key1==matrix[0][1] && key1==matrix[2][1]) || (key1==matrix[0][1] && key1==matrix[2][0]))
          {result(key1); return;}
          if((key2==matrix[1][0] && key2==matrix[2][0]) ||(key2==matrix[0][1] && key2==matrix[0][2]))
          {result(key2); return;}
          if((key3==matrix[1][2] && key3==matrix[0][2]) ||(key3==matrix[2][0] && key3==matrix[2][1]))
          {result(key3);return;}

    }
    //check if game is drawn or ongoing.
    int flag=0;
    for(int i=0; i<9;i++)
    {
      if(loc_avail[i]!='a')
      {  flag=1;
         break;
      }
    }
    if(flag==1)
    {
      if(Last_player=='U')
      comp_game();
      else
      user_game();
    }
    else
    {printf("\nGAME OVER \nThe game has been drawn.\n"); exit(0);}
}


void user_game()
{
    flag=0;
    printf("\nIts your turn.\nEnter the box number to fill[1-9]: ");
    scanf("  %c",&box);
    for(int i=0; i<9; i++)
    {
      if(box==loc_avail[i])
      {
        flag=1;
        loc_avail[i]='a';
        break;
      }
    }
    if(flag==0)
    {
      printf("\nSORRY! Location not available. Try again");
      user_game();
    }
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      if(matrix[i][j]==box)
      {
        matrix[i][j]=user;
        break;
      }
    }
    //matrix filling.
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
          printf("\t%c\t|",matrix[i][j]);
        }
        printf("\n");
        if(i==2)
            continue;
        printf("   __________________________________________\n");
      }
      flag==0;
      char Last_player='U';
      check_game('U');
      return;
  }

  void comp_game()
  {
    printf("\n\n\nIts computers turn.\n");
    flag=0;
    int loc;
    char k;
    for(int i=0;i<9;i++)
    {
      if(loc_avail[i]!='a')
      {
        k=loc_avail[i];
        loc_avail[i]='a';
        break;
      }
    }

    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      if(matrix[i][j]==k)
      {
        matrix[i][j]=comp;

      }
    }
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        printf("\t%c\t|",matrix[i][j]);
      }
      printf("\n");
      if(i==2)
          continue;
      printf("   __________________________________________\n");
    }
    flag==0;
    char Last_player='C';
    check_game('C');
    return;
  }

void result(int key)
{

    printf("GAME OVER.\n%c has WON the game.",key);
    if(key==user)
    {
      points=10;
      printf("\nYou have won over the computer. CONGRAGULATIONS!\nYour points: %d\n",points);
      printf("press any key to continue:");
      scanf("%c",&garbage);
      exit(0);
    }
    else
    {
      printf("\nThe computer has won the game. You have 0 points.\n");
      printf("press any key to continue:");
      scanf("%c",&garbage);
      exit(0);
    }

}
