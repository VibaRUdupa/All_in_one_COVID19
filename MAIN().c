//ALl IN COVID-19

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mini_games(int a);
void riddles_quiz(int a);
void hangman(int a);
void tic_tac_toe(int a);
void user_game();
void comp_game();
void check_game(char x);
void result(int x, int a);

char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char  User, comp, box;
char garbage;
int flag=0,a;
char loc_avail[9]={'1','2','3','4','5','6','7','8','9'};

struct database
{
  char user_name[10];
  char password[5];
  int point;
  int high_score;
}user[10];

void main()
{
  static int i=0;
  char cont;
  int c1,j=0,c2,index=-1,current_index=-1;
  A:printf("\nWelcome.\n1.New user(sign up)\n2.Existing user(sign in)\nEnter your choice: ");
  scanf("%d",&c1);
  switch(c1)
  {
    case 1: if(i>=10)
            {
              printf("Session overload!");
              exit(1);
            }
            D: printf("Enter your user name(less than 10 characters): ");
            char id[10];
            scanf("  %[^\n]s",&id);
            for(int k=0; k<i; k++)
            if(strcmp(user[k].user_name,id)==0)
            {
              printf("\nSORRY!!! User name not available, try with another name.\n");
              goto D;
            }
            strcpy(user[i].user_name,id);

            E: printf("Enter a password(less than 5 characters): ");
            char pd[5];
            scanf("  %[^\n]s",&pd);
            for(int k=0; k<i; k++)
            if(strcmp(user[k].password,pd)==0)
            {
              printf("\nSORRY!!! Password not available, try with another name.\n");
              goto E;
            }
            strcpy(user[i].password,pd);

            printf("Account created successfully!");
            current_index=i;
            break;

    case 2: printf("Enter your user name: ");
            char name[10],pwd[5];
            scanf("  %[^\n]s",&name);
            for(j=0;j<i;j++)
            {
              if(strcmp(name,user[j].user_name)==0)
              index=j;
            }
            if(index==-1)
            {
              printf("User name not found in data base.");
              goto A;
            }
            else
            {
              printf("Enter password: ");
              scanf("  %[^\n]s",&pwd);
              if(strcmp(pwd,user[index].password)==0)
              {
                printf("Login successful! welcome back.");
                current_index=index;
              }
              else
             {
              printf("Incorrect password!\n");
              goto A;
             }
            }
            break;

    default: printf("Invalid choice.\n");
             goto A;
  }

    a=current_index;
    printf("\n\n\n\t\t\t\t\t\tWelcome to All in one Covid-19!!\n\n ");
    time_t t;
    time(&t);
    printf("\nYou have logged in at %s", ctime(&t));
    printf("\n\t\t This app is aimed at providing the users with all necessary information regarding the current pandemic\n\n");
    printf("We currently have the following options for you.");
    L:printf("\n1. Present cases in the country and worldwide, updated manually every 24 hours.\n2. Self-Assessment\n3. Safety Measures\n4. Updates from government on Lockdown restrictions.\n5. Latest international news updates about COVID-19.\n6. Random facts to keep you entertained.\n7. Mini Games when you need a break.\n8. Lockdown activities.");
    printf("\n\nKindly select one of the following: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            //presentCases();
            break;
        }
        case 2:
        {
            //selfAssessment();
            break;
        }
        case 3:
        {
            //safetyMeasures();
            break;
        }
        case 4:
        {
            //lockdownRestrictions();
            break;
        }
        case 5:
        {
            //internationalNews();
            break;
        }
        case 6:
        {
            //randomFacts();
            break;
        }
        case 7:
        {
            user[current_index].point=0;
            mini_games(current_index);
            break;
        }
        case 8:
        {
            //lockdownActivities();
            break;
        }
        default:
        {
            printf("Please enter a valid choice");
            goto L;
        }

    }
    K: printf("\n\n\nDo you want to continue with our service? Press (Y/N): ");
    scanf("  %c",&cont);
    if(cont=='y' || cont=='Y')
    {
        goto L;
    }
    else if(cont=='n' || cont=='N')
    {
        B:printf("\n1.Log out(Your data will be saved)\n2.Exit(Your data will be lost)\nEnter your choice: ");
  scanf("%d", &c2);
  switch(c2)
  {
    case 1: printf("\nLogging out...");
            sleep(1);
            printf("\nSuccessfully Logged off.\n");
            if(c1==1)
            i++;
            main();
            break;

    case 2: printf("If you exit, all your data will be lost.\nARE YOU SURE YOU WANT TO EXIT! (Y/N): ");
            char c3;
            scanf(" %c",&c3);
            if(c3=='Y' || c3=='y')
            {
                printf("\nThank you!!! It was a pleasure serving you!!\n");
                time_t t1;
                time(&t1);
                printf("You exited at %s",ctime(&t1));
              exit(0);
            }
            else
            goto B;
            break;

    default: printf("\nInvalid choice.\n");
             goto B;
             break;

   }

    }
    else
    {
        printf("\nPlease enter a valid choice.\n");
        goto K;
    }
}


void mini_games(int current_index)
{
  A: printf("\n\nWELCOME!!!\n\nYou have choosen to play mini-games.\nThe following games are available for you to play:\n1.Riddles and Quizes.\n2.Hangman.\n3.Tic-Tac-Toe.\nEnter your choice(For a high score, we suggest you pick 1, and play all the games.): ");
  int choice;
  char ch;
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: riddles_quiz(current_index);
            break;

    case 2: hangman(current_index);
            break;

    case 3: tic_tac_toe(current_index);
            printf("\nThis is the last mini-game.\n");
            break;

    default: printf("\nINVALID CHOICE! Chose again.\n");
             goto A;
  }
  printf("\nYou have completed mini-games.\nPoints: %d\nHigh score: %d\n\n",user[current_index].point, user[current_index].high_score);
  return;
}

void riddles_quiz(int a)
{
  printf("\nCOMING SOON\n");
  printf("\nWould like to try the next game? (Y/N): ");
  char ch;
  scanf("  %c",&ch);
  if(toupper(ch)=='Y')
  hangman(a);
  return;
}

void hangman(int a)
{
char hangman[6][10]={"ARCHITECT", "BADMINTON", "KANGAROOS", "ISOLATION", "ARGENTINA", "PINEAPPLE"};
char ans[6][10]={"A___I_E__", "_A__I__O_", "_A__A_OO_", "I_O_A_IO_", "A__E__I_A", "_I_EA___E" };
char guess;
int dash=0, chance=5, value=0;

printf("\t\t\t\t\t\tWELCOME TO HANGMAN \n");
printf("\t\t\t\t\t       --- INSTRUCTIONS ---");
printf("\n\n1.Only vowels of the word will be displayed and the consonants will be hidden. ");
printf("\n2.The user must guess the missing alphabets one by one. ");
printf("\n3.If the guessed letter is a part of the word, then it will be displayed. ");
printf("\n4.Else the user loses a chance. The maximum number of allowed incorrect guesses are 5.");
printf("\n5.If you lose all your turns, your game ends. If you guess a word correctly, you get 10 points and the game will automatically go to next level. ");
printf("\n\n\t\t\tALL THE BEST\n\n");

for(int i=0; i<6; i++){
          switch(i)
          {
              case 0: printf("\nQuestion %d. \nHint: Its is a profession.\n",i+1);
              break;
              case 1: printf("\nQuestion %d. \nHint: Its is a type of sport.\n",i+1);
              break;
              case 2: printf("\nQuestion %d. \nHint: Its is an Australian animal.\n",i+1);
              break;
              case 3: printf("\nQuestion %d. \nHint: Its is a widely used term.\n",i+1);
              break;
              case 4: printf("\nQuestion %d. \nHint: Its is a country in South America..\n",i+1);
              break;
              case 5: printf("\nQuestion %d. \nHint: Its is a fruit.\n",i+1);
              break;
          }
  L: printf("\n%s \nYou have %d chances to guess the word.\nGuess an alphabet: ", ans[i], chance);
      scanf(" %c", &guess);
      guess=toupper(guess);
      for(int j=0; j<10; j++){
       if(guess==hangman[i][j]){
          ans[i][j]=guess;
          value++;
      }
    }
    if(value==0)
       chance--;
    for(int d=0; d<10; d++){
       if(ans[i][d]=='_' )
           dash++;
    }
    if(value==0 && chance!=0)
    {
      printf("\nWRONG GUESS. But you can still try again.");
      value=0;
      goto L;
    }
    if(value==0 && chance==0)
    {
      char end;
      printf("\nGAME OVER - YOUR HAVE ZERO CHANCES LEFT.\nThe word is %s \nPress any key to continue.\n",hangman[i]);
      scanf("  %c",&end);
      value=0;
      break;
    }
    if(dash!=0 && value!=0)
    {
      printf("\nGOOD GUESS.");
      value=0;
      dash=0;
      goto L;
    }
    if(dash==0 && value!=0)
    {
      printf("\n%s \nCONGRATULATIONS. \nYou have successfully guessed the word.\n", ans[i]);
      char end;
      printf(" \nPress any key to continue.\n");
      scanf("  %c",&end);
      user[a].point=user[a].point+10;
      chance=5;
      value=0;
      dash=0;
    }
}
if( user[a].high_score==0 ||  user[a].high_score<user[a].point )
user[a].high_score=user[a].point;
printf("\n\nYour score: %d \nYour high score: %d\n", user[a].point, user[a].high_score);
printf("\nWould like to try the next game? (Y/N): ");
char ch;
scanf("  %c",&ch);
if(toupper(ch)=='Y')
tic_tac_toe(a);
return;
}


void tic_tac_toe(int a)
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
       scanf(" %c",&User);

    User=toupper(User);
    switch(User)
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
    if( user[a].high_score==0 ||  user[a].high_score<user[a].point )
    user[a].high_score=user[a].point;
  printf("\nYour current points: %d\n", user[a].point);
  printf("\nYour high score: %d\n", user[a].high_score);
  return;
  }


  void check_game(char Last_player)
    {
      //check if game is won.
      {
            char key1=matrix[1][1], key2=matrix[0][0], key3=matrix[2][2];
            if((key1==matrix[0][0] && key1==matrix[2][2]) || (key1==matrix[1][0] && key1==matrix[1][2]) || (key1==matrix[0][1] && key1==matrix[2][1]) || (key1==matrix[0][1] && key1==matrix[2][0]))
            {result(key1,a); return;}
            if((key2==matrix[1][0] && key2==matrix[2][0]) ||(key2==matrix[0][1] && key2==matrix[0][2]))
            {result(key2,a); return;}
            if((key3==matrix[1][2] && key3==matrix[0][2]) ||(key3==matrix[2][0] && key3==matrix[2][1]))
            {result(key3,a);return;}

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
      {printf("\nGAME OVER \nThe game has been drawn.\n"); return;}
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
          matrix[i][j]=User;
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

  void result(int key, int a)
  {

      printf("GAME OVER.\n%c has WON the game.",key);
      if(key==User)
      {
        user[a].point+=10;
        printf("\nYou have won over the computer. CONGRAGULATIONS!\nYou won 10 points.\n");
        printf("press any key to continue:");
        scanf("   %c",&garbage);
        return(0);
      }
      else
      {
        printf("\nThe computer has won the game. You have got 0 points in this game.\n");
        printf("press any key to continue:");
        scanf("   %c",&garbage);
        return(0);
      }

  }
