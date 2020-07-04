/*

ALL IN COVID-19

Course Code: CS110
Course Title: Computer Programming
Semester: B. Tech 2nd Sem
Section: S2
Academic Year: 2019-20
Course Instructor: Marwa Mohiddin

Source code by:
Team Members:
1. Devika Harikrishnan, ME226, 9113503488, devikaharikrishnan.191me226@nitk.edu.in
2. Harshitha Reddy, ME294, 720467468, yharshithareddy.191me294@nitk.edu.in
3. Spandana Bhat K, ME186, 9481266475, spandanabhatk.191me186@nitk.edu.in
4. Viba R Udupa, ME291, 9740871536, vibarudupa.191me291@nitk.edu.in

*/


//begin code for ALL IN ONE COVID-19

//inclusion of standard libraries.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

//structure for storing user login details and mini_games points and high-score, ratings and reviews..
struct database
{
  char user_name[10];
  char password[5];
  int point;
  int high_score;
  int rating[4];
  float avg_rate;
  char review[200];
}user[10];  //structure variable creation.

//Structure for storing the self-assessment results.
struct result
    {
        int ch1,ch2,ch3,ch4;
        char username[10];
    }patient[10]; //structure variable creation.


//user defined functions to perform specific features mentioned in the abstract.
void mini_games(int *a);
void riddles_quiz(int **a);
void hangman(int a);
void tic_tac_toe(int a);
void user_game();
void comp_game();
void check_game(char x);
void result(int x, int a);
void lockdownActivities();
void selfAssessment(int c,int b);
void safetyandrandom();
void presentCases();
void internationalNews();
void lockdownRestrictions();
void ratings_review(int index, struct database *users);

//global variables for mini_games.
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char  User, comp, box;
char garbage;
int flag=0,a;
char loc_avail[9]={'1','2','3','4','5','6','7','8','9'};

FILE *fptr[10]; //creationg an array of file pointers to store user data permamently.


//main() function.
void main()
{

    //creating/opening files for secondary storage of data.
    for(int i=0; i<10; i++)
    {
    char w[50]; //string to store text file name.
//    itoa(i+1,w,10);
    sprintf(w,"%d",i+1);
    char s[50]="_User_details.txt";
    strcat(w,s);  //name each file of the format: i+1_User_details.txt   Ex: 1_User_details.txt
    fptr[i]=fopen(w,"a+");  //open file named i+1_User_details.txt in read and append mode. fptr[i] points to the file opened.
    }


  static int i=0;
  char cont;
  int c1,j=0,c2,index=-1,current_index=-1;
  A:printf("\n\n\t\t\t\t************************************************************************\n\n\t\t\t\t\t\t\t\tWELCOME!!!\n\n\t\t\t\t************************************************************************\n\n\n\n\t1.New user(sign up)\n\t2.Existing user(sign in)\n\nEnter your choice: ");
  scanf("%d",&c1);
  //Sign-in/Sign-up procedures.
  switch(c1)
  {
    case 1: if(i>=10)
            {
              //More than 10 users try to access the code.
              printf("Session overload!");
              exit(1);
            }
            //Input user_name from user.
            D: printf("\n\t\tEnter your user name(less than 10 characters): ");
            char id[10];
            scanf("  %[^\n]s",&id);
            for(int k=0; k<i; k++)
            if(strcmp(user[k].user_name,id)==0) //check if the user_name is not available(already used).
            {
              printf("\n\t\tSORRY!!! User name not available, try with another name.\n");
              goto D;
            }
            //user_nameis available.
            strcpy(user[i].user_name,id);     //store the user_name in structure database's variable user[i].user_name
            fprintf(fptr[i],"User Name: %s\n",id);     //save the user_name in i+_User_details.txt file.

            //Input user_password from user.
            E: printf("\n\t\tEnter a password(less than 5 characters): ");
            char pd[5],ch;int x2=0;
            //display * when password is entered for the sake of privacy.
            for(x2 = 0; x2 <5; x2++)
            {
                ch = getch();
                if(ch == 13)    //if ch is NULL
                break;
                pd[x2] = ch;
                ch = '*' ;
                printf("%c ", ch);
            }
             pd[x2] = '\0'; //append NULL at the end

            //check for password availability.
            for(int k=0; k<i; k++)
            if(strcmp(user[k].password,pd)==0)    //check if password is not available.
            {
              printf("\n\t\tSORRY!!! Password not available, try with another name.\n");
              goto E;
            }
            //password is available.
            strcpy(user[i].password,pd);    //store the password in user[i].password
            fprintf(fptr[i],"Password: %s\n",pd);   //save the password in i+1_User_details.txt file.
            printf("\n\n\n\n\t\t\tACCOUNT CREATION SUCCESSFUL!!!\n\n");
            current_index=i;
            break;

    case 2:
            //Input user_name from user.
            printf("\n\t\tEnter your user name: ");
            char name[10],pwd[5],ch1;int x1=0;
            scanf("  %[^\n]s",&name);
            for(j=0;j<i;j++)    //Find User_name from database Structure.
            {
              if(strcmp(name,user[j].user_name)==0)   //if find is successful, assign j to index.
              index=j;
            }
            if(index==-1)   //user name not found in the database.
            {
              printf("\n\t\tOOPS!!!User name not found in data base.");
              goto A;
            }
            else
            {
              //user name found in the database.
              //Input password from the user.
              printf("\n\t\tEnter password: ");
              //display * when password is entered for the sake of privacy.
              for(x1 = 0;x1 <5;x1++)
              {
                  ch1 = getch();
                  if(ch1 == 13)     //if ch is NULL
                  break;
                  pwd[x1] = ch1;
                  ch1 = '*' ;
                  printf("%c ", ch1);
              }
               pwd[x1] = '\0';

              //check if the password matches with user_name's password already stored in database.
              if(strcmp(pwd,user[index].password)==0)
              {
                //match successful.
                printf("\n\n\n\t\t\tLOGIN SUCCESSFUL!!! WELCOME BACK!!!");
                current_index=index;
              }
              else
             {
               //match failure.
              printf("\n\t\tIncorrect password!\n");
              goto A;
             }
            }
            break;

    default: printf("\nInvalid choice.\n");
             goto A;
  }

    a=current_index;

    printf("\n\n\n\t\t\t\t\t\tWELCOME TO ALL IN ONE COVID-19!!!\n\n ");

    //read and display time from system.
    time_t t;
    time(&t);
    printf("\nYou have logged in at %s", ctime(&t));

    fprintf(fptr[current_index],"\nYou have logged in at %s\n", ctime(&t)); //save in file i+1_User_details.txt the login time.
    fprintf(fptr[current_index],"ACTIVITY:\n");     //save history in file i+1_User_details.txt

    //display introduction.
    printf("\n\n\t\t This app is aimed at providing the users with all necessary information regarding the current pandemic\n\n");
    printf("\nWe currently have the following options for you.");
    L:printf("\n1. Present cases in the country and worldwide, updated manually every 24 hours.\n2. Self-Assessment\n3. Safety Measures and random facts\n4. Updates from government on Lockdown restrictions.\n5. Latest international news updates about COVID-19.\n6. Mini Games when you need a break.\n7. Lockdown activities.");
    printf("\n\nKindly select one of the following: ");
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            presentCases(); //function call
            fprintf(fptr[current_index],"The user accessed Present cases.\n");  //save data in file.
            break;
        }
        case 2:
        {
            fprintf(fptr[current_index],"The user accessed Self Assessment.\n");       //save data in file.
            selfAssessment(i,a);  //function call
            break;
        }
        case 3:
        {
            safetyandrandom();  //function call
            fprintf(fptr[current_index],"The user accessed Safety measures and random facts.\n");       //save data in file.
            break;
        }
        case 4:
        {
            lockdownRestrictions(); //function call
            fprintf(fptr[current_index],"The user accessed Government imposed lock-down restrictions.\n");      //save data in file.
            break;
        }
        case 5:
        {
            internationalNews();  //function call
            fprintf(fptr[current_index],"The user accessed international news about COVID-19.\n");      //save data in file.
            break;
        }
        case 6:
        {

            user[current_index].point=0; //initialize users points to zero.
            mini_games(&current_index);  //function call.
            fprintf(fptr[current_index],"The user accessed Mini games:\n");         //save data in file.
            fprintf(fptr[current_index],"\t\t\t\tHighscore: %d\n",user[current_index].high_score);  //save the high score into i+1_User_details.txt file.
            break;
        }
        case 7:
        {
            lockdownActivities(); //function call
            fprintf(fptr[current_index],"The user accessed Lock-down activities.\n");       //save data in file.
            break;
        }
        default:
        {
            printf("Please enter a valid choice:\n");
            goto L;
        }

    }

    //Ask for user input on his/her choice of continuing our services.
    K: printf("\n\n\nDo you want to continue with our service? Press (Y/N): ");
    scanf("  %c",&cont);
    if(cont=='y' || cont=='Y')
    {
      //the user wants to continue our services.
        goto L;
    }
    else if(cont=='n' || cont=='N')
    {
        //the user does not want to continue our facilities.
        //Log-out/Exit facility
        B:printf("\n1.Log out(Your data will be saved)\n2.Exit(Your data will be lost)\nEnter your choice: ");
        scanf("%d", &c2);
        switch(c2)
        {
        case 1:

            //function call to receive user opinion.
            ratings_review(current_index,&user[current_index]);

            //the user wants to log out
            printf("\nLogging out...");
            sleep(1);

            time_t t2;
            time(&t2);
            printf("\nSuccessfully Logged off.\n");

            fprintf(fptr[current_index],"\nYou have logged out at %s\n-----------------------------------------------------------------\n", ctime(&t2));  //save the logout time to i+1_User_details.txt file.
            fclose(fptr[i]);        //close file i+1_user_details.txt

            if(c1==1)
            i++;

            sleep(1);

            main();     //recursive functions.

            break;

        case 2:

            //the user wants to exit. Check for confirmation.
            printf("If you exit, all your data will be lost.\nARE YOU SURE YOU WANT TO EXIT! (Y/N): ");
            char c3;
            scanf(" %c",&c3);
            if(c3=='Y' || c3=='y')
            {
                //function call to get user details.
                ratings_review(current_index,&user[current_index]);

                //exit user.
                printf("\nThank you!!! It was a pleasure serving you!!\n");

                time_t t1;
                time(&t1);
                printf("You exited at %s",ctime(&t1));

                fprintf(fptr[current_index],"\nYou have logged out at %s\n-----------------------------------------------------------------\n", ctime(&t1));   //save logout time to i+1_User_details.txt file.
                fclose(fptr[i]);        //close file.
              exit(0);  //EXIT
            }

            else
            //the user doesnt want to exit.
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

//end of main()


//User-defined functions begin.


//function definition for mini_games
void mini_games(int *current_index)
{
    //user can select a game among available choices.
  A: printf("\n\n\t\t\t\tWELCOME!!!\n\nYou have choosen to play mini-games.\nThe following games are available for you to play:\n1.Riddles and Quizes.\n2.Hangman.\n3.Tic-Tac-Toe.\nEnter your choice(For a high score, we suggest you pick 1, and play all the games.): ");
  int choice,ind=*current_index;
  char ch;
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: riddles_quiz(&current_index); //function call.
            break;

    case 2: hangman(ind);  //function call.
            break;

    case 3: tic_tac_toe(ind);  //function call.
            printf("\nThis is the last mini-game.\n");  //end of mini games.
            break;

    default: printf("\nINVALID CHOICE! Chose again.\n");
             goto A;
  }
  //display user score and highscore.
  printf("\nYou have completed mini-games.\nPoints: %d\nHigh score: %d\n\n",user[*current_index].point, user[*current_index].high_score);
  return;
  //end of mini_games
}

//function definition for riddles_quiz
void riddles_quiz(int **j)
{
    //function for riddles and quiz game.
  char a, ans[20];
  int point=0;
  //display of instructions.
  printf("\nWELCOME\nThe Riddles and Quizes game.\nGeneral Instructions.\n1.Four riddles will be displayed first, one after another.\n2.A correct guess will award you with 10 points.\n3.After the riddles, four general knowledge questions will be asked one after another(MCQs).\n4.The correct answer will give you 10 points.\nIMPORTANT: ALL ANSWERS MUST BE IN LOWER CASE alphabets.\n\nALL THE BEST!!!\n\n ");
  printf("\nRIDDLES:\n");

  //display of questions.
  printf("\nQuestion 1.\nWhat has roots as nobody sees,\nIs taller than trees,\nUp, up it goes,\nAnd yet never grows?\n\nAns:");
  scanf("  %s",&ans);
  if(strcmp(ans,"mountains")==0 || strcmp(ans,"mountain")==0) //check if the ans is correct.
  {
    //the answer is correct.
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;   //add 10 to points
  }
  else
  {
    //the ans is wrong. display correct ans.
    printf("Incorrect guess! The answer is : mountains\n\n");
  }

  for(int i=0; i<20; i++)
  ans[i]='\0';  //reinitialize ans variable to 0 to avoid overwriting.

  printf("\nQuestion 2.\nThis thing all things devours;\nBirds, beasts, trees, flowers;\nGnaws iron, bites steel;\nGrinds hard stones to meal;\nSlays king, ruins town,\nAnd beats mountain down.\n\nAns:");
  scanf("  %s",&ans);
  if(strcmp(ans,"time")==0)
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("Incorrect guess! The answer is : time\n\n");}

  for(int i=0; i<20; i++)
  ans[i]='\0';

  printf("\nQuestion 3.\nA box without hinges, key, or lid,\nYet golden treasure inside is hidden.\n\nAns:");
  scanf("  %s",&ans);
  if(strcmp(ans,"egg")==0 || strcmp(ans,"eggs")==0)
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("Incorrect guess! The answer is : egg\n\n");}

  for(int i=0; i<20; i++)
  ans[i]='\0';

  printf("\nQuestion 4.\nWhat has a neck,\nbut no head,\nYet wears a cap.\n\nAns:");
  scanf("  %s",&ans);
  if(strcmp(ans,"bottle")==0 || strcmp(ans,"bottles")==0)
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("Incorrect guess! The answer is : bottle\n\n");}

  printf("\nYou have completed the riddles. Now moving on to GK quiz: \n");

  printf("\nQuestion 1.\nWho discovered penicillin?\na.Alexander Fleming.\nb.Edward Jenner\nc.Louis Pasteur\nd.Robert Koch\nAns:");
  scanf("  %c",&a);
  if(a=='a'||a=='A')
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("\nIncorrect guess! The answer is : a.Alexander Fleming\n\n");}

  printf("\nQuestion 2.\nThe Indian to beat the computers in mathematical wizardry is\nA.Ramanujam\nB.Rina Panigrahi\nC.Raja Ramanna\nD.Shakunthala Devi\nAns:");
  scanf("  %c",&a);
  if(a=='d'||a=='D')
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("\nIncorrect guess! The answer is : D. Shakunthala Devi\n\n");}

  printf("\nQuestion 3.\nThe members of Lok Sabha hold office for a term of\nA.4 years\nB.5 years\nC.6 years\nD.3 years\nAns:");
  scanf("  %c",&a);
  if(a=='b'||a=='B')
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("\nIncorrect guess! The answer is : B. 5 years\n\n");}

  printf("\nQuestion 4.\nThe Battle of Plassey was fought in:\nA.1757\nB.1782\nC.1748\nD.1764\nAns:");
  scanf("  %c",&a);
  if(a=='a'||a=='A')
  {
    printf("\nCorrect Guess! You got 10 points\n\n");
    point=point+10;
  }
  else
  { printf("\nIncorrect guess! The answer is : A. 1757\n\n");}

  //end of riddles and quiz. update and display result.
  user[**j].point=point;
  if( user[**j].high_score==0 ||  user[**j].high_score<user[**j].point )
  user[**j].high_score=user[**j].point;
  printf("\n\nYour score: %d \nYour high score: %d\n", user[**j].point, user[**j].high_score);
  printf("\nWould like to try the next game? (Y/N): ");
  char ch, arg=**j;
  scanf("  %c",&ch);
  if(toupper(ch)=='Y')  //the user wants to continue the next game.
  hangman(arg);   //function call
  return;
}
//end of riddles_quiz

//function definitionfor hangman()
void hangman(int a)
{
    //function for hangman game.
char hangman[6][10]={"ARCHITECT", "BADMINTON", "KANGAROOS", "ISOLATION", "ARGENTINA", "PINEAPPLE"};
char ans[6][10]={"A___I_E__", "_A__I__O_", "_A__A_OO_", "I_O_A_IO_", "A__E__I_A", "_I_EA___E" };
char guess;
int dash=0, chance=5, value=0;

//display instructions.
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
              //display hints for every question.
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
       if(guess==hangman[i][j]){  //check if entered letter is a correct guess.
          ans[i][j]=guess;
          value++;
      }
    }
    if(value==0)  //incorrect guess. Decrement number of chances.
       chance--;
    for(int d=0; d<10; d++){
       if(ans[i][d]=='_' )    //check number of letters yet to be guessed.
           dash++;
    }
    if(value==0 && chance!=0) //wrong guess but game is pending.
    {
      printf("\nWRONG GUESS. But you can still try again.");
      value=0;
      goto L;
    }
    if(value==0 && chance==0) //game over
    {
      char end;
      printf("\nGAME OVER - YOUR HAVE ZERO CHANCES LEFT.\nThe word is %s \nPress any key to continue.\n",hangman[i]);
      scanf("  %c",&end);
      value=0;
      break;
    }
    if(dash!=0 && value!=0) //correct guess but game is pending.
    {
      printf("\nGOOD GUESS.");
      value=0;
      dash=0;
      goto L;
    }
    if(dash==0 && value!=0) //Entire word guessed correctly.
    {
      printf("\n%s \nCONGRATULATIONS. \nYou have successfully guessed the word.\n", ans[i]);
      char end;
      printf(" \nPress any key to continue.\n");
      scanf("  %c",&end);
      user[a].point=user[a].point+10; //add 10 points.
      //re-initialize variables.
      chance=5;
      value=0;
      dash=0;
    }
}
//update highscore.
if( user[a].high_score==0 ||  user[a].high_score<user[a].point )
user[a].high_score=user[a].point;
//display result.
printf("\n\nYour score: %d \nYour high score: %d\n", user[a].point, user[a].high_score);
printf("\nWould like to try the next game? (Y/N): ");
char ch;
scanf("  %c",&ch);
if(toupper(ch)=='Y')  //the user wants to continue on to the next game.
tic_tac_toe(a); //function call.
return;
}
//end of hangman()

//function definition for tic_tac_toe().
void tic_tac_toe(int a)
{
    //Tic-tac toe game.
    //display instructions.
    printf("\n\n\t\t\t\tWELCOME TO TIC-TAC-TOE\n\nThe instructions for this game are as follows:\n1.The user must choose either 'X' or 'O'.\n2.The game always starts with 'X'.\n3.The boxes for the game are numbered as follows:\n");
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

    A: printf("What is your choice 'X' or 'O'? : ");  //ask user choice.
       scanf(" %c",&User);

    User=toupper(User);
    switch(User)
    {
      case 'X': comp='O';
                printf("\nAs you have chosen X, you must begin the game.");
                user_game(); //function call
                break;
      case 'O': comp='X';
                printf("\nAs you have chosen O, computer will begin the game.");
                comp_game();  //function call
                break;
      default: printf("INVALID CHOICE ENTERED.");
               goto A;
    }
    //update and display high score.
    if( user[a].high_score==0 ||  user[a].high_score<user[a].point )
    user[a].high_score=user[a].point;
  printf("\nYour current points: %d\n", user[a].point);
  printf("\nYour high score: %d\n", user[a].high_score);

  //re-initialize matrices for next game.
  int z=0;
  for(int b=0; b<3; b++)
    for(int c=0; c<3; c++)
  {
      matrix[b][c]=z+'1';
      z++;
  }
  z=0;
    for(int v=0;v<10;v++)
    {
        loc_avail[v] = z+'1';
        z++;
    }
  return;
  }
//end of tic_tac_toe

//function definition for check_game()
  void check_game(char Last_player)
    {
      //check if game is won.
      {
        //check all possible combinations of winning the game.
            char key1=matrix[1][1], key2=matrix[0][0], key3=matrix[2][2];
            if((key1==matrix[0][0] && key1==matrix[2][2]) || (key1==matrix[1][0] && key1==matrix[1][2]) || (key1==matrix[0][1] && key1==matrix[2][1]) || (key1==matrix[0][2] && key1==matrix[2][0]))
            {result(key1,a); return;}
            if((key2==matrix[1][0] && key2==matrix[2][0]) ||(key2==matrix[0][1] && key2==matrix[0][2]))
            {result(key2,a); return;}
            if((key3==matrix[1][2] && key3==matrix[0][2]) ||(key3==matrix[2][0] && key3==matrix[2][1]))
            {result(key3,a); return;}

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
        comp_game();  //function call
        else
        user_game();  //function call.
      }
      else
      //game-draw
      {printf("\nGAME OVER \nThe game has been drawn.\n"); return;}
  }
//end of check_game()


//function definition for user_game
  void user_game()
   {
       //fill in for the user.
      flag=0;
      printf("\nIts your turn.\nEnter the box number to fill[1-9]: ");
      scanf("  %c",&box);
      for(int i=0; i<9; i++)
      { //check if location is available.
        if(box==loc_avail[i])
        {
          flag=1;
          loc_avail[i]='a';
          break;
        }
      }
      if(flag==0)
      {
        //location is unavailable.
        printf("\nSORRY! Location not available. Try again");
        user_game();
      }
      for(int i=0;i<3;i++)
      {
        //fill the game board with user's move.
        for(int j=0;j<3;j++)
        if(matrix[i][j]==box)
        {
          matrix[i][j]=User;
          break;
        }
      }
      //game board display.
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
        check_game('U');  //function call.
        return;
    }
//end of user_game()


//function definitionfor comp_game()
    void comp_game()
    {
        //fill in for computer.
      printf("\n\n\nIts computers turn.\n");
      flag=0;
      int loc;
      char k;
      for(int i=0;i<9;i++)
      { //check location availablity.
        if(loc_avail[i]!='a')
        {
          k=loc_avail[i];
          loc_avail[i]='a';
          break;
        }
      }

      for(int i=0;i<3;i++)
      {
        //game_board filling by computer.
        for(int j=0;j<3;j++)
        if(matrix[i][j]==k)
        {
          matrix[i][j]=comp;

        }
      }
      printf("\nThe computer is thinking...\n\n");
      //game_board display.
      sleep(1);
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
      check_game('C');  //function call.
      return;
    }
//end od comp_game()


//function definition for result()
  void result(int key, int a)
  {
      //display result for the tic-tac-toe game.

      printf("GAME OVER.\n%c has WON the game.",key);
      if(key==User)
      {
        user[a].point+=10;
        printf("\nYou have won over the computer. CONGRAGULATIONS!\nYou won 10 points.\n");
        printf("press any key(except enter key) to continue:");
        scanf("   %c",&garbage);
        return;
      }
      else
      {
        printf("\nThe computer has won the game. You have got 0 points in this game.\n");
        printf("press any key(except enter key) to continue:");
        scanf("   %c",&garbage);
        return;
      }

   }
//end of result.


//function definition of lockdownActivities()
void lockdownActivities()
{
    //function to display lock-down activities.
  int choice;
  char ch;
  LA1:printf("\n\n\t\t\t\t\t\tLOCKDOWN ACTIVITIES\n\n\nEasy cooking recipes\n\t1. Milkshake\n\t2.Sandwich\n\t3.French Fries.\n\nDifferent levels of exercises\n\t4.Easy exercises\n\t5.Medium Exercises\n\t6.Difficult Excercises\n\nReading books\n\t7.The Alchemist\n\t8.The maze runner.\n\t9.The Kite runner.\n\n\t10.Go Back.\n");
  printf("\n\nEnter the number of your choice: ");
  scanf("%d",&choice);
  if(choice==10)
    return;
  printf("\n");
  if(choice==1||choice==2||choice==3)
  {
  switch(choice)
  {
    case 1:

    printf("\n\tMilkshake recipe:\n");
    printf("\nTake 4 scoops of icecream,1/2 cup milk,1/2cup Hershey's syrup.\n1. Place ice cream, milk and syrup in blender container.\n2.Cover and blend until smooth.\n3.Transfer it to a glass.\n4.Garnish with chocolate if required.\n");
    break;


    case 2:

    printf("\n\tSandwich recipe:\n");
    printf("\nSpread mayonnaise, butter or cream cheese all the way to the edges of each slice of bread to create a seal against wet sandwich fillings.\n Also, try packing high moisture ingredients, like tomatoes, pickles, and cucumbers, separately.\nJust add them to the sandwich when you're ready to eat.\n Grill the bread for better taste.\n");
    break;

    case 3:

    printf("\n\tFrench fries recipe:\n");
    printf("\nSlice potatoes into French fries, place them into cold water so they won't turn brown.\nThen start to prepare the oil. Heat oil in a large skillet over medium-high heat.\nWhile the oil is heating, sift the flour, garlic salt, onion salt, regular salt and paprika into a large bowl.\nThen fry the slices in oil till golden colour and add it into the spices bowl. Mix well and enjoy.\n");
    break;
  }
  }
  else if(choice==4||choice==5||choice==6)
  {
    switch (choice)
    {
    case 4:

    printf("\n\tEasy exercises:\n\n(1 set)\n1.High stepping = 30 seconds\n2.Squats = 12\n3.Mountain climber = 14");
    break;

    case 5:

    printf("\n\tMedium exercises:\n\n(2 sets)\n1.High stepping = 30 seconds\n2.Squats = 12\n3.Mountain climber = 14");
    break;

    case 6:

    printf("\n\tHard exercises:\n\n(3 sets)\n1.High stepping = 30 seconds\n2.Squats = 12\n3.Mountain climber = 14");
    break;
    }
    }
   else if(choice==7||choice==8||choice==9)
   {
    switch(choice)
    {
    case 7:

    printf("\nSummary of The Alchemist:\n\tThe Alchemist follows the journey of an Andalusian shepherd boy named Santiago.\nBelieving a recurring dream to be prophetic, he asks a Gypsy fortune teller in the nearby town about its meaning.\nThe woman interprets the dream as a prophecy telling the boy that he will discover a treasure at the Egyptian pyramids.\n");
    break;

    case 8:

    printf("\nSummary of The Maze Runner:\n\tThomas wakes up in a strange elevator, with memories lost and no idea what is going to happen.\nHe is accepted into a glade full of other teenage boys who call themselves Gladers.\nAfter learning about the Maze that surrounds them all, Thomas becomes obsessed with finding a way out, which could mean certain death.\n");
    break;

    case 9:

    printf("\nSummary of The Kite Runner:\n\tThe story skips to winter, when the kite fighting tournament occurs.\nBoys cover their kite strings in glass and battle to see who can sever the string of the opposing kite.\nWhen a kite loses, boys chase and retrieve it, called kite running.\nWhen Amir wins the tournament, Hassan sets off to run the losing kite.\n");
    break;
    }
   }
printf("\n\n\nEnter 1 to continue reading. Enter any other key(except enter key) to go back to the main menu: ");
scanf(" %c",&garbage);
if(garbage==49)
goto LA1;
}
//end of lockdownActivities().


//function definition of selfAssessment()
void selfAssessment(int c,int b)
{
    //Self assessment function.
    int choice;
    printf("\n\t\t\t\t\t\tWelcome To The Self-Assessment");
    printf("\n\n Please enter 1 to do the self assessment and enter 2 to access your previous assessment: ");
    scanf("%d",&choice);
    if(choice==1)
    {
      //collect information from the user by their responses for the below questionnaire.
        printf("\n\nQUESTION1:");
        printf("\nPress 1 if any one or more of these condition are satisfied: \n Press 2 if these conditions are not applicable for you :- \n\n Are you immuno-compromised (for example if you have HIV/AIDS, are receiving immuno-suppression therapy or treatment for cancer or have had a transplant) \n Have returned to India from foreign travel in the last 4 months or has a travel history inside the country in the last 60 days. \n Have come into contact with someone with respiratory symptoms. \n\n Enter your Choice: ");
        scanf("%d",&patient[c].ch1);
        printf("\n\nQUESTION2:");
        printf("\nPress 1 if you experience any one or more of these symptoms: \n Press 2 if these conditions are not applicable for you:- \n\n Severe difficulty breathing (for example, struggling for each breath, speaking in single words). \n Severe chest pain. \n Having a very hard time waking up. \n Feeling confused. \n Lost consciousness. \n \n Enter your Choice: ");
        scanf("%d",&patient[c].ch2);
        printf("\n\nQUESTION3:");
        printf("\nPress 1 If this evaluation is for a child of age below 5 years or an adult above 60 years of age.\n Press 2 if these conditions are not applicable for you\n\n Enter your choice: ");
        scanf("%d",&patient[c].ch3);
        if(patient[c].ch3==1)
        {
            printf("\n\nQUESTION4:");
            printf("\nPress 1 if you experience any of these symptoms:\n Press 2 if these conditions are not applicable for you:- \nDo you experience any floppiness or a lack of response? \n ");
            scanf("%d",&patient[c].ch4);
            printf("\nThank you...Your result is being generated....Please wait for some time...");
            sleep(1);
        }
        else
        {
            printf("\nThank you...Your result is being generated....Please wait for some time...");
            sleep(1);
        }

        //Display result and save the result in i+1_user_details.txt file.
        if((patient[c].ch1==1)&&( patient[c].ch2==1)&&( patient[c].ch3==2))
        {

          printf("\n\n\tRESULT:-\n ALERT!! You are at a high risk of a COVID-19 infection.\n\nPlease take all necessary precautions and Please contact the nearest hospital for treatment in case of severe display of symptoms.\n");
          fprintf(fptr[b],"\nSelf-Assessment Result:\nRESULT:-\n ALERT!! You are at a high risk of a COVID-19 infection.\n\nPlease take all necessary precautions and Please contact the nearest hospital for treatment in case of severe display of symptoms.\n\n");
        }
        else if((((patient[c].ch1==1)&&(patient[c].ch2==2))||((patient[c].ch1==2)&&( patient[c].ch2==1)))&&( patient[c].ch3==2))
        {

            printf("\n\n\tRESULT:-\n The risk of COVID-19 infection is medium. Please follow all the self isolation protocols and keep in check for new symptoms. In case of any new symptoms, contact the nearest hospital\n");
            fprintf(fptr[b],"\nSelf-Assessment Result:\nRESULT:-\n The risk of COVID-19 infection is medium. Please follow all the self isolation protocols and keep in check for new symptoms. In case of any new symptoms, contact the nearest hospital.\n\n");
        }
        else if((patient[c].ch1==1)&&(patient[c].ch2==1)&&( patient[c].ch3==1))
        {
            printf("\n\n\tRESULT:-\n ALERT!! Your child/senior citizen is at a high risk of having a COVID-19 infection. Kindly rush to the nearest hospital\n");
            fprintf(fptr[b],"\nSelf-Assessment Result:\nRESULT:-\n ALERT!! Your child/senior citizen is at a high risk of having a COVID-19 infection. Kindly rush to the nearest hospital.\n\n");
        }
        else if((((patient[c].ch1==1)&&( patient[c].ch2==2))||((patient[c].ch1==2)&&(patient[c].ch2==1)))&&(patient[c].ch3==1))
        {
            fprintf(fptr[b],"\nSelf-Assessment Result:\nRESULT:-\n The risk of COVID-19 infection is medium. But your child/senior citizen might be facing some other infection. Kindly rush to the hospital to be on the safer side.\n");
            printf("\n\n\tRESULT:-\n The risk of COVID-19 infection is medium. But your child/senior citizen might be facing some other infection. Kindly rush to the hospital to be on the safer side.\n\n");

        }
        else
        {
            fprintf(fptr[b],"\nSelf-Assessment Result:\nRESULT:-\n The risk of COVID-19 infection is low. However you can be a disease carrier to immuno-compromised people.\n Hence, Please follow all safety protocols to ensure your and your beloved's safety.\n");
            printf("\n\n\tRESULT:-\n The risk of COVID-19 infection is low. However you can be a disease carrier to immuno-compromised people.\n Hence, Please follow all safety protocols to ensure your and your beloved's safety.\n\n");
        }
    }

    else if(choice==2)
    {
      //display previous assessment results.
        printf("\n\n User name= %s",user[b].user_name);
        z: printf("\nDo you wish to see the entire result(press 1) or the end result(press 2): ");
        int n;
        scanf("%d",&n);
        if(n==1)
        {
          //display entire result from result database.
            printf("\n\nQUESTION1:");
            printf("\nPress 1 if any of these condition are satisfied: \n Press 2 if these conditions are not applicable for you:- \n\n Are you immuno-compromised (for example if you have HIV/AIDS, are receiving immuno-suppression therapy or treatment for cancer or have had a transplant). \n Have returned to India from travel foreign in the last 4 months or have recorded inter-country travel in the last 60 days. \n Have come into contact with someone with respiratory symptoms. \n");
            printf("\nYour option was %d",patient[b].ch1);
            printf("\n\nQUESTION2:");
            printf("\nPress 1 if you experience any of these symptoms:\n Press 2 if these conditions are not applicable for you:- \n Severe difficulty breathing (for example, struggling for each breath, speaking in single words) \n Severe chest pain \n having a very hard time waking up. \n Feeling confused. \n Lost consciousness. \n");
            printf("\nYour option was %d",patient[b].ch2);
            printf("\n\nQUESTION3:");
            printf("\nPress 1 If you are a child of age below 5 or a senior adult above 60 years. \n Press 2 if these conditions are not applicable for you \n");
            //printf("Does the child experience any floppiness or a lack of response? \n");
            printf("\nYour option was %d",patient[b].ch3);
            if(patient[b].ch3==1)
            {
                printf("\n\nQUESTION4:");
                printf("\nPress 1 if you experience any of these symptoms:\n Press 2 if these conditions are not applicable for you:- \nDo you experience any floppiness or a lack of response? \n ");
                printf("\nYour option was %d",patient[b].ch4);
            }
            if((patient[b].ch1==1)&&( patient[b].ch2==1)&&( patient[b].ch3==2))
        {
            printf("\nRESULT:-\nALERT!!You are at a high risk of a COVID-19 infection\nPlease contact the nearest hospital for treatment\n");
        }
        else if((((patient[b].ch1==1)&&(patient[b].ch2==2))||((patient[b].ch1==2)&&( patient[b].ch2==1)))&&( patient[b].ch3==2))
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is medium. Please follow all the self isolation protocols and keep in check for new symptoms. In case of any new symptoms, contact the nearest hospital\n");
        }
        else if((patient[b].ch1==1)&&(patient[b].ch2==1)&&( patient[b].ch3==1))
        {
            printf("\nRESULT:-\nALERT!!Your child or senior citizen is at a high risk of having a COVID-19 infection. Kindly rush to the nearest hospital\n");

        }
        else if((((patient[b].ch1==1)&&( patient[b].ch2==2))||((patient[b].ch1==2)&&(patient[b].ch2==1)))&&(patient[b].ch3==1))
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is medium. But your child/senior citizen might be facing some other infection.Kindly rush to the hospital to be on the safer side.\n");

        }
        else
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is low.Please follow all safety protocols to ensure your safety\n");

        }

        }
        else if(n==2)
        {
            if((patient[b].ch1==1)&&( patient[b].ch2==1)&&( patient[b].ch3==2))
        {
            printf("\nRESULT:-\nALERT!!You are at a high risk of a COVID-19 infection\nPlease contact the nearest hospital for treatment\n");

        }
        else if((((patient[b].ch1==1)&&(patient[b].ch2==2))||((patient[b].ch1==2)&&( patient[b].ch2==1)))&&( patient[b].ch3==2))
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is medium. Please follow all the self isolation protocols and keep in check for new symptoms. In case of any new symptoms, contact the nearest hospital\n");

        }
        else if((patient[b].ch1==1)&&(patient[b].ch2==1)&&( patient[b].ch3==1))
        {
            printf("\nRESULT:-\nALERT!!Your child/senior citizen is at a high risk of having a COVID-19 infection. Kindly rush to the nearest hospital\n");

        }
        else if((((patient[b].ch1==1)&&( patient[b].ch2==2))||((patient[b].ch1==2)&&(patient[b].ch2==1)))&&(patient[b].ch3==1))
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is medium. But your child/senior citizen might be facing some other infection.Kindly rush to the hospital to be on the safer side.\n");

        }
        else if((patient[b].ch1==0)&&( patient[b].ch2==0)&&(patient[b].ch3==0))
        {
            printf("\nRESULT:-\nInvalid Result!! Please do the self assessment.\n");

        }
        else
        {
            printf("\nRESULT:-\nThe risk of COVID-19 infection is low. Please follow all safety protocols to ensure your safety\n");

        }

        }
        else
        {
            printf("\nInvalid choice. Re-enter\n");
            goto z;
        }
    }
printf("\n\n\nEnter any key(except enter key) to continue: ");
scanf(" %c",&garbage);

}
//end of selfAssessment()


////function definition of  safetyandrandom()
void safetyandrandom()
    {
        //function to display safety and random facts.
        int a,b,c,d,e,f;

        S1: printf("\n\t\t\t\t\t\t\t\tSAFETY MEASURES AND RANDOM FACTS\n\n Stay aware of the latest information on the COVID-19 outbreak, available on the WHO website and through your national and local public health authority.\n Most countries around the world have seen cases of COVID-19 and many are experiencing outbreaks.\n Authorities in China and some other countries have succeeded in slowing their outbreaks.\n However, the situation is unpredictable so check regularly for the latest news.\n");
        printf("\n1.Protecting yourself and others from the spread COVID-19\n");
        printf("2.Advice on the safe use of alcohol-based hand sanitizers\n");
        printf("3.When and how to use masks\n");
        printf("4.Common inquiries\n");
        printf("5.COVID-19 Home care\n");
        printf("6.COVID-19: Pregnancy & breastfeeding\n");
        printf("7.Getting your workplace ready for COVID-19\n");
        printf("8.Myth-Busters\n");
        printf("9.Go back.\n");
        printf("\nEnter your choice: ");

        scanf("%d",&a);

        if(a==9)
            return;
        switch(a)
        //display details according to user preference.
        {
        case 1:
        printf("\n\nYou can reduce your chances of being infected or spreading COVID-19 by taking some simple precautions:\n");
        printf("\n1. Regularly and thoroughly clean your hands with an alcohol-based hand rub or wash them with soap and water.\n");
        printf("\t\tWhy?Washing your hands with soap and water or using alcohol-based hand rub kills viruses that may be on your hands.");
        printf("\n\n2. Maintain at least 1 meter (3 feet) distance between yourself and others.");
        printf("\n\t\tWhy? When someone coughs, sneezes, or speaks they spray small liquid droplets from their nose or mouth which may contain virus.");
        printf("\n\n3. Avoid going to crowded places\n");
        printf("\t\tWhy? Where people come together in crowds, you are more likely to come into close contact with someone that has COIVD-19\n\t\tAnd it is more difficult to maintain physical distance of 1 metre (3 feet).\n");
        printf("\n4. Avoid touching eyes, nose and mouth.\n");
        printf("\t\tWhy? Hands touch many surfaces and can pick up viruses. Once contaminated, hands can transfer the virus to your eyes, nose or mouth.\n\t\tFrom there, the virus can enter your body and infect you.\n");
        printf("\n5. Make sure you, and the people around you, follow good respiratory hygiene.This means covering your mouth and nose with your bent elbow or tissue when you cough or sneeze.\n   Then dispose of the used tissue immediately and wash your hands.\n");
        printf("\t\tWhy? Droplets spread virus. By following good respiratory hygiene, you protect the people around you from viruses such as cold, flu and COVID-19.");
        printf("\n\n6. Stay home and self-isolate even with minor symptoms such as cough, headache, mild fever, until you recover. Have someone bring you supplies.\n   If you need to leave your house, wear a mask to avoid infecting others.\n");
        printf("\t\tWhy? Avoiding contact with others will protect them from possible COVID-19 and other viruses.\n");
        printf("\n7. If you have a fever, cough and difficulty breathing, seek medical attention, but call by telephone in advance if possible and follow the directions of your local health authority. \n");
        printf("\t\tWhy? National and local authorities will have the most up to date information on the situation in your area.\n\t\tCalling in advance will allow your health care provider to quickly direct you to the right health facility.\n\t\tThis will also protect you and help prevent spread of viruses and other infections.\n");
        printf("\n8. Keep up to date on the latest information from trusted sources, such as WHO or your local and national health authorities. \n");
        printf("\t\tWhy? Local and national authorities are best placed to advise on what people in your area should be doing to protect themselves\n");
        break;
        case 2:
        printf("\n\n   USE OF SANITIZER\n");
        printf("\nTo protect yourself and others against COVID-19, clean your hands frequently and thoroughly.\nUse alcohol-based hand sanitizer or wash your hands with soap and water.\nIf you use an alcohol-based hand sanitizer, make sure you use and store it carefully.\n");
        printf("\n1.Keep alcohol-based hand sanitizers out of children’s reach. Teach them how to apply the sanitizer and monitor its use.\n2.Apply a coin-sized amount on your hands. There is no need to use a large amount of the product\n3.Avoid touching your eyes, mouth and nose immediately after using an alcohol-based hand sanitizer, as it can cause irritation.\n4.Hand sanitizers recommended to protect against COVID-19 are alcohol-based and therefore can be flammable.\nDo not use before handling fire or cooking.\n5.Under no circumstance, drink or let children swallow an alcohol-based hand sanitizer. It can be poisonous. \n6.Remember that washing your hands with soap and water is also effective against COVID-19.\n"
         );
        break;
        case 3:
        printf("\n\n   WHEN TO WEAR MASK\n");
        printf("\n1.If you are healthy, you only need to wear a mask if you are taking care of a person with COVID-19.\n2. Wear a mask if you are coughing or sneezing.\n3. Masks are effective only when used in combination with frequent hand-cleaning with alcohol-based hand rub or soap and water.\n4.If you wear a mask, then you must know how to use it and dispose of it properly.\n");
        printf("\n\n   HOW TO WEAR A MASK\n");
        printf("\n1.Before putting on a mask, clean hands with alcohol-based hand rub or soap and water.\n2.Cover mouth and nose with mask and make sure there are no gaps between your face and the mask.\n3.Avoid touching the mask while using it; if you do, clean your hands with alcohol-based hand rub or soap and water.\n4.Replace the mask with a new one as soon as it is damp and do not re-use single-use masks.\n5.To remove the mask: remove it from behind (do not touch the front of mask); discard immediately in a closed bin; clean hands with alcohol-based hand rub or soap and water.\n");
        printf("\nPlease note: Wearing a medical mask is one of the prevention measures that can limit the spread of certain respiratory viral diseases, including COVID-19.\nHowever, the use of a mask alone is insufficient to provide an adequate level of protection, and other measures should also be adopted.\n");
        break;
        case 4:
        printf("\n\n   COMMON ENQUIRIES\n");
        printf("\n1.Should I avoid hand shaking because of new virus?\n2.Is wearing rubber gloves while out in public effective in spreading virus?\n3.How can I grocery shop safely?\n4.How should I wash fruits and vegetables?\n5.Can virus spread through coins and notes?\n6.What are essential services?\n7.How do I properly disinfect surface?\n8.Can pets get virus?\n");
        printf("\nEnter your choice: ");
        scanf("%d",&b);
        switch(b)
         {
             case 1:
             printf("Yes,respiratory diseases can spread through shaking hands, touching hands,eyes and mouth\nGreet people with nod, bow and Namaste instead.");
             break;
             case 2:
             printf("No, regularly washing hands provide more protection than wearing gloves.\nRubber gloves can be source of COVID 19\n");
             break;
             case 3:
             printf("While grocery shopping keep atleast 1m distance from others.\nIf possible sanitize trolleys and baskets.\nThere is currently no confirmed case of virus spreading through fruits and packages.\n");
             break;
             case 4:
             printf("Before handling them wash your hands with water.Then wash them thoroughly with clean water");
             break;
             case 5:
             printf("Currently there is no proof to confirm or disapprove hat the virus can be spread through coins and notes.\nBut virus can persists on surfaces.Therefore it is better to wash hands regularly.");
             break;
             case 6:
             printf("1.Transportation of all goods without distinction of essential and non-essential have been allowed.\n2.Grocery shops.\n3.The entire supply chain of milk collection and distribution, including its packaging material, is allowed.\n4.Newspaper delivery supply chain is also allowed under print media\n5.Hospitals and all related medical establishments, including their manufacturing and distribution units, both in public and private sector, will continue to remain fully functional. The transportation for all medical personnel, nurses, para-medical staff and other hospital support services are permitted.\n6.Banks, insurance offices and ATMs\n7.Delivery of all essential goods including food, pharmaceutical, medical equipment through e-commerce.\n8.Petrol pumps, LPG, petroleum and gas retail and storage outlets.\n");
             break;
             case 7:
             printf("Complete disinfecting protocol includes four steps: \nwiping a surface of obvious dirt and residue; \n""dwell time"" to let the disinfectant sit; \nwiping the surface clean; and \nrinsing with water.");
             break;
             case 8:
             printf("In April, a dog in North Carolina tested positive for COVID-19,\nas did two pet cats in New York and a eight tigers at New York City Bronx Zoo.\nHowever, there has been no evidence that pets such as dogs or cats can spread the COVID-19.\nAccording to the World Health Organization and the C.D.C. (The animals showed mostly mild symptoms — though the tiger was visibly sick — and have recovered.)\nStill,if you are sick with COVID-19, it is best not to pet your family dog. And avoid petting other people''s dogs as well.");
             break;
             default:
             printf("Question does not exist\n");

         }
         break;
         case 5:
         printf("\n\nCOVID HOME CARE\n");
         printf("\n1.For ill people.\n2.For all members of household\n");
         printf("\nEnter the number to know more about it:");
         scanf("%d",&c);
         switch(c)
         {
             case 1:
             printf( "\nIf you're ill with cough and fever\n1.Wash hands frequently\n2.Stay at home.Do not attend public places.\n3.Stay in a separate room. Maintain atleat 3m distance from family.\n4.While coughing or sneezing use disposable tissue.\n5.Drink plenty of fluid and eat nutritious food\n");
             printf("\nWhen to Seek Emergency Medical Attention\n");
             printf("Look for emergency warning signs* for COVID-19. If someone is showing any of these signs, seek emergency medical care immediately\n1.Trouble breathing\n2.Persistent pain or pressure in the chest\n3.New confusion\n4.Inability to wake or stay awake\n5.Bluish lips or face\n");
             break;
             case 2:
             printf("\nIf any household member is ill then\n1.Wash hands regularly. Specifically after\n   (a)coughing or sneezing\n   (b)preparing and eating food\n   (c)After using toilet\n   (d)After caring sick person\n");
             printf("2.Avoid sharing personal items such as soap,towels,utensils and drinks\n Designate a bathroom for the patient.\n");
             printf("3.Monitor everyone's symptoms such as fever, coughing and difficulty in breathing\n");
         }
        break;
        case 6:
        printf("\n\nPREGNANCY AND BREASTFEEDING\n");
        printf("\nAll Women have right to safe and positive childbirth, whether or not they are positive COVID-19 cases.\n");
        printf("We have a collection of answers to questions parents might have. \nThese answers have been collated from reliable sources to provide you with useful information. \n");
        printf("\n1.I am pregnant.Will it Hurt the baby if  I get COVID during pregnancy?\n2.I am pregnant.Is it easier for pregnant women to become ill with COVID?\n3.How do I protect myself from COVID during pregnancy?\n4.What happens when a women with COVID-19 gives birth to baby?\n5.Can I breastfeed if I have COVID-19?\n");
        printf("Enter the question number to know the answer: ");
        scanf("%d",&d);
        printf("\n\n");
        switch(d)
            {
            case 1:
            printf("At this time, there is not enough evidence to determine whether the virus is transmitted from a mother to \nher baby during pregnancy, or the potential impact this may have on the baby.This is currently being\n investigated.at this time. A small number of problems with pregnancy or delivery (e.g. preterm birth)\nhave been reported in babies born to mothers who tested positive for COVID-19 during their pregnancy.\n However, it is not clear if these outcomes were actually related to maternal infection or not.\n");
            break;
            case 2:
            printf("The Royal College of Obstetricians and Gynecologists state that pregnant women do not appear to be more\nsusceptible to the consequences of infection with COVID-19 than the general population.\nPregnant women experience changes in their bodies that may increase their risk of some infections.\nIt is known that with viruses from the same family as COVID-19, and other viral respiratory infections,\nsuch as influenza, women have had a higher risk of developing severe illness.\nThis is why the it is always important for pregnant women to protect themselves from illnesses.\n");
            break;
            case 3:
            printf("Pregnant women should do the same things as the general public to avoid infection.\n");
            break;
            case 4:
            printf("In order to reduce the risk of transmission of COVID-19 to the newborn, when a mother with COVID-19 gives birth,\nthe baby may be temporarily separated from the mother in the immediate postpartum setting.\nIf the temporary separation is prolonged, primarily because the mother needs medical care for herself,providing the baby with expressed breast milk is recommended.\nIf possible, a dedicated breast pump should be provided.\nSpecial care must be taken to clean and disinfect the breast pump prior to it being used.\nJohns Hopkins Medicine states that once the mother’s symptoms improve and she and her baby \nare ready to be discharged home, it is possible for her to either continue using expressed \nbreast milk or to breastfeed,taking the necessary precautions to avoid spreading the virus \nto her infant. These include washing hands before holding her baby, and wearing a face mask \nwhen in close contact with her baby\n");
            break;
            case 5:
            printf("The Academy of Breastfeeding Medicine and the WHO state that considering the benefits of breastfeeding and the \ninsignificant role of breast milk in the transmission of other respiratory viruses,\nthe mother can continue breastfeeding, while applying all the necessary precautions.\nThere is limited evidence for the presence of viral RNA in breast milk,\nwhile there is neither evidence for active virus in breast milk nor transmission via breast milk. \nCurrently, the primary concern is not whether the virus can be transmitted through breast milk,\nbut rather whether an infected mother can transmit the virus through respiratory droplets breastfeeding.\nPrecautions to avoid spreading the virus to your infant include washing hands before holding your baby,\nand wearing a face mask when in close contact with your baby as, for example, during direct breastfeeding. \n");
            break;
            }
        break;
        case 7:
        printf("\n\nWORKSPACE READY FOR COVID-19\n");
        printf("1.Simple ways to prevent the spread of COVID-19 in your workplace\n2.How to manage COVID-19 risks when organizing meetings and events?\n3.Getting your workplace ready in case COVID-19 arrives in your community\n");
        printf("\nTo know more about above enter the number: ");
        scanf("%d",&e);
        printf("\n\n");
        switch(e)
        {
            case 1:
            printf("\n	The low-cost measures below will help prevent the spread of infections in your workplace,\n such as colds, flu and stomach bugs, and protect your customers, contractors,and employees.\n  Employers should start doing these things now, even if COVID-19 has not arrived in the\n communities where they operate.These  measures can reduce  working days lost  due  to illness\n  And stop or slow the spread of COVID-19 if it arrives at one of your workplaces.\n");
            printf("\n1.Make sure your workplaces are clean and hygienic.\n  Surfaces (e.g. desks and tables) and objects (e.g. telephones, keyboards) need to be wiped with disinfectant regularly\n");
            printf("\n2.Promote regular and thorough hand-washing by employees, contractors,and customers.\n  Put sanitizing hand rub dispensers in prominent places around the workplace.\n  Make sure these dispensers are regularly refilled–Display posters promoting hand-washing.\n  ask your local public health authority for these or consult www.WHO.int.\n–Combine with other communication measures such as offering  guidance from occupational\n health and safety officers, briefings at meetings,and information on intranetsitesto promote hand-washing.\n  Make sure that  staff, contractors,and customers have  access to places where they can wash their hands with soap and water");
            printf("\n3.Promote good respiratory hygiene in the workplace.\n  Display posters promoting respiratory hygiene.\n  Ensure that face masks or paper tissues are available at your workplaces,  along with closed bins for hygienically disposing of them\n");
            printf("\n4.Advise employees and contractors to consult national travel advice before going on business trips.\n");
            printf("\n5.Brief  your  employees,  contractors,and  customers  that  if  COVID-19  starts  spreading  in your community anyone with even a mild cough or mild-fever(37.3 C or more)needs to stay at home. \n  Display   posters   with   this   message   in   your   workplaces.\n  Make clear to employees that they will be able to count this time off as sick leave\n");
            break;


            case 2:
            printf("\nKey considerations to prevent or reduce COVID-19 risks.\n");
            printf("\nBEFORE the meeting or event.\n");
            printf("\n1.Develop and agree a preparedness plan to prevent infection at your meeting or event.\n Conduct teleconference or on-line event when ever it is possible.\n Meeting  be scaled down so that fewer people attend.\n Pre-order  sufficient supplies  and  materials, including tissues  and hand  sanitizer  for  all participants.\n Have surgical masks  available  to  offer  anyone  who  develops symptoms.\n Actively monitor where COVID-19 is circulating.Advise participants in advance\nthat if they have any symptoms or feel unwell, they should not attend.\n");
            printf("\n2.Develop and agree a response plan in case someone at the meeting becomes ill \nwith symptoms of COVID-19 (dry cough, fever, malaise). This plan should include at least:\nIdentify  a room or area where  someone who is feeling unwell or has symptoms can be safely isolated.\nHave a plan for how they can be safely transferred from there to a health facility.\n Know what to do if a meeting participant, staff member,or service provider tests positive for COVID-19\n during or just after the meeting\n");
            printf("\nDURING the meeting \n");
            printf("\n1.Provide  information  or  a  briefing,  preferably  both  orally  and  in  writing, \non COVID-19 and the measures that organizers are taking to make this event safe for participants.\nEncourage regular hand-washing or use of an alcohol rub by all participants at the meeting or event.\nEncourage participants to cover their face if they cough or sneeze. \nSupply tissues and closed binsfor disposal.\n");
            printf("\n2.Display dispensers of alcohol-based hand rub prominently around the venue\n");
            printf("\n3.If there is space, arrange seats so that participants are at least 1 meterapart\n");
            printf("\n4.Open windows and doors whenever possible to make sure the venue is well ventilated.\n");
            printf("\n5.If anyone who starts to feel unwell, follow your preparedness plan or call your hotline.\n\n");
            printf("\nAFTER the meeting\n");
            printf("\n1.Retain the names and contact details of all participants for at least one month.\n2.If someone at the meeting or event was isolated as a suspected COVID-19 case, \nthe organizer should inform participants.They should be advised to monitor themselves\nfor symptoms for 14 days and take their temperature twice a day.\n3.If they develop even a mild cough or low-grade fever (i.e. a temperature of 37.3 C or more)\nthey should stay at home and self-isolate.\n");
            break;


            case 3:
            printf("\nGetting your workplaceready in case COVID-19 arrives in your community.\n");
            printf("\n1.Develop a plan for what to do if someone  becomes ill with suspected COVID-19 at one of your workplaces.\nThe plan should cover putting the ill person in a room or area where they are isolated from others in the workplace.\nConsider how to identify persons who may be at risk, and support them.\nThis could include persons who have recently traveled to an area reporting cases or other personnel who have conditions that put them at higher risk of serious illness \n(e.g. diabetes, heart and lung disease, older age).\n");
            printf("\n2.Promote regular teleworking across your organization. \nIf there is an outbreak of COVID-19 in your community  the  health  authorities  may  advise  people to avoid public transport and crowded places.\nTeleworking will help your business keep operating while\n your employees stay safe.\n");
            printf("\n3.Develop a contingency and business continuity plan for an outbreak in the communities where your business operates.\nThe plan should address how to keep your business running even if a significant number of  employees, contractors  and  suppliers  cannot  come  to  your  place  of  business.\nBe sure your plan addresses the mental health and social consequences of a case of COVID-19 in the workplace.\nFor  small  and  medium-sized  businesses  without  in-house  staff  health  and  welfare support, develop plans with your local health and social service providers.\n");
            break;


        }
        break;
        case 8:
        printf("\n\nMYTH-BUSTERS\n\n");
        printf("1.Most people who get COVID-19 recover from it\n");
        printf("2.Drinking alcohol does not protect you against COVID-19 and can be dangerous\n");
        printf("3.Thermal scanners CANNOT detect COVID-19\n");
        printf("4.There are currently no drugs licensed for the treatment or prevention of COVID-19\n");
        printf("5.Adding pepper to your soup or other meals DOES NOT prevent or cure COVID-19\n");
        printf("6.COVID-19 IS NOT transmitted through houseflies or mosquitoes\n");
        printf("7.Exposing yourself to the sun or to temperatures higher than 25C degrees DOES NOT prevent the COVID-19 disease (COVID-19)\n");
        printf("8.Being able to hold your breath for 10 seconds or more without coughing or feeling discomfort DOES NOT mean you are free from the COVID-19 disease or any other lung disease.\n");
        printf("9.Cold weather and snow CANNOT kill the new COVID-19.\n\n");
        printf("To know reason about above myths enter the number:");
        scanf("%d",&f);
        printf("\n\n");
        switch(f)
        {
            case 1:
            printf("Most people who get COVID-19 have mild or moderate symptoms and can recover thanks to supportive care.\nIf you have a cough, fever and difficulty breathing seek medical care early - call your health facility by telephone first.\n");
            break;
            case 2:
            printf("The harmful use of alcohol increases your risk of health problems.Thereby increase the risk of COVID\n");
            break;
            case 3:
            printf("Thermal scanners are effective in detecting people who have a fever (i.e. have a higher than normal body temperature).\n They cannot detect people who are infected with COVID-19.\n");
            break;
            case 4:
            printf("While several drug trials are ongoing, there is currently no proof that hydroxychloroquine or any other drug can cure or prevent COVID-19.\n");
            break;
            case 5:
            printf("Hot peppers in your food, though very tasty, cannot prevent or cure COVID-19..\n");
            break;
            case 6:
            printf("To date, there is no evidence or information to suggest that the COVID-19 virus transmitted through houseflies or mosquitoes. \n");
            break;
            case 7:
            printf("You can catch COVID-19, no matter how sunny or hot the weather is.\n");
            break;
            case 8:
            printf("The best way to confirm if you have  the virus producing COVID-19 disease is with a laboratory test. \nYou cannot confirm it with this breathing exercise, which can even be dangerous.\n");
            break;
            case 9:
            printf("There is no reason to believe that cold weather can kill the new COVID-19 or other diseases.\n");
            break;
            default:
            printf("MYth doesn't exist\n");

}
}

printf("\n\n\nEnter 1 to continue reading.Enter any other key(except enter key) to go back to main menu : ");
scanf(" %c",&garbage);
if(garbage==49)
goto S1;

}
//end of safetyandrandom()


//function definition of presentCases()
void presentCases()
{
    //function to display present cases in the world.
    printf("\n\n\t*****************************WORLD COUNT*******************************************\n");
    printf("\n\tCountry\t Total cases \t New cases \t Total deaths \t New deaths \t Total recovered");
    printf("\n\tWorld  \t 6,441,152   \t  77,956   \t 380,265      \t 3,075      \t 2,946,617      ");
    printf("\n\tUS     \t 1,870,238   \t  10,915\t 107,620      \t 695        \t 618,867        ");
    printf("\n\tBRAZIL \t 539,045     \t  9,640    \t 30,486       \t 440        \t 211,080        ");
    printf("\n\tRUSSIA \t 423,741     \t  8,863    \t 5,037        \t 182        \t 186,985        ");
    printf("\n\tSPAIN  \t 287,012     \t  294      \t 27,127       \t 0          \t N/A            ");
    printf("\n\tUK     \t 277,985     \t  1,653    \t 39,369       \t 324        \t N/A            ");
    printf("\n\n\n\t*****************************INDIA COUNT*******************************************\n");
    printf("\n\tState       \t Total cases \t Total deaths \t Total recovered");
    printf("\n\tINDIA       \t 207,135     \t 5,829        \t 100,205        ");
    printf("\n\tMaharashtra \t 70013       \t 2362         \t 30108          ");
    printf("\n\tTamil Nadu  \t 23495       \t 184          \t 13170          ");
    printf("\n\tDelhi       \t 20834       \t 523          \t 8746           ");
    printf("\n\tGujarat     \t 17200       \t 1063         \t 10780          ");
    printf("\n\tRajasthan   \t 8980        \t 198          \t 6040           ");
    printf("\n\n\nThis information is manually updated every 24 hours. The sources for the world count is worldometer covid and for India count is mygov.in.\n Thank you and Stay safe\n");


printf("\n\n\nEnter any key(except enter key) to continue: ");
scanf(" %c",&garbage);

}
//end of presentcases()


//function definition of internationalNews()
void internationalNews()
{
    //function to display international news.
    printf("\n\n                        LATEST INTERNATIONAL UPDATES ON CORONA VIRUS VACCINE                  ");
    printf("\n\n1.""REMDESIVIR""\nA California biotech company says its experimental drug remdesivir improved");
    printf("\nsymptoms when given for five days to moderately ill, hospitalised patients with COVID-19.");
    printf("\nGilead Sciences gave few details on Monday but said full results would soon be published");
    printf("\n in a medical journal.");
    printf("\nRemdesivir is the only treatment that's been shown in a rigorous experiment to help fight");
    printf("\nthe coronavirus. A large study led by the National Institutes of Health recently found it");
    printf("\ncould shorten average recovery time from 15 days to 11 days in hospitalised patients with");
    printf("\nsevere disease.");
    printf("\nThe drug is given through an IV and is designed to interfere with an enzyme the virus uses");
    printf("\nto copy its genetic material. It's approved for treating COVID-19 in Japan and is ");
    printf("\nauthorized for emergency use in the United States for certain patients.");
    printf("\nThere were no deaths among patients on five days of the drug, two among those on 10 days,");
    printf("\nand four among patients getting standard care alone. Nausea and headache were a little");
    printf("\nmore common among those on the drug.");
    printf("\n\n\n\n");
    printf("\n2.""MODERNA""\n");
    printf("\nUS-based Moderna Therapeutic's innovative messenger RNA-1273 prototype is being seen as one");
    printf("\nof the most promising contenders globally. The pharma group has proceeded to conduct stage ");
    printf("\n2 of the clinical trials and has started dosing patients accordingly, a statement released by ");
    printf("\nthe company said. In the second phase of its trial and plans to enrol around 600 more patients");
    printf("\nmoving forward.");
    printf("\nEarly data collated from the first phase of the vaccine trial have been by and large successful ");
    printf("\nwhich showed that mRNA-1272 spike protein was able to speed up the production of neccessary ");
    printf("\nantibodies in healthy patients. If deemed effective, the pharmaceutical giant plans to start mass");
    printf("\n-scale production to fight the ongoing battle.");
    printf("\n\n\n\n");
    printf("\n3.""SINOVAC""\n");
    printf("\nThe Chinese pharma company, Sinovac Biotech, who has been working on producing a vaccine earmarked");
    printf("\nCoronaVac are hopeful of getting good results and have even said that they are 99%% sure that the");
    printf("\nvaccine could help curb the spread of the virus.");
    printf("\nJust like its competitors, the company too is in stage 2 of trials. The vaccine has shown promising");
    printf("\nresults in the first phase where it was tested on monkeys and if reports are to go by, stage 3 ");
    printf("\ntrials will be kickstarted in parts of the United Kingdom soon enough. They have already received ");
    printf("\nneccessary funding and factory space to spruce up productions if all the safety checks are passed");
    printf("\ngoing forward.\n");

printf("\n\n\nEnter any key(except enter key) to continue: ");
scanf(" %c",&garbage);


}
//end of internationalNews


//function definition of  lockdownRestrictions()
void lockdownRestrictions()
{
    //function to display lockdown restrictions imposed by governmentof INDIA.
    int a;
    R1:printf("\n\n\t\t\t\tLOCKDOWN RESTRICTIONS\n\nOn 24 March 2020, the Government of India under Prime Minister Narendra Modi ordered a nationwide lockdown for 21 days, limiting movement of the entire 1.3 billion population of India\nas a preventive measure against the COVID-19 pandemic in India\n");
    printf("\n1.TimeLine Of Events:\n");
    printf("2.Travel restrictions during COVID\n");
    printf("3.Go Back.\n");
    printf("\nEnter the number: ");
    scanf("%d",&a);
    if(a==3)
        return;
    printf("\n\n");

    switch(a)
    {
    case 1:
    printf("\n\nPhase 1 (25 March to 14 April)\n\n");
    printf("From 25 March all activities was completely ceased,nearly all services and factories were suspended.\nThe government held meetings with e-commerce websites and vendors to ensure a seamless supply of essential goods across the nation during the lockdown period\n");
    printf("On 26 March, finance minister Nirmala Sitharaman announced a ₹170,000 crore (US$24 billion) stimulus package to help those affected by the lockdown.\nThe package was aimed to provide food security measures for poor households through direct cash transfers, free cereal and cooking gas for three months.\nIt also provided insurance coverage for medical personnel.\n");
    printf("On 27 March, the Reserve Bank of India announced a slew of measures to help mitigate the economic impacts of the lockdown\n");
    printf("The government had announced that the Indian Railways would suspend passenger operations through 31 March. The national rail network has maintained its freight operations to transport essential goods.\nOn 29 March, the Indian Railways announced that it would start services for special parcel trains to transport essential goods.\n");
    printf("On 5 April, citizens all over India cheered and showed solidarity with the health workers, police, and all those fighting the disease\nby switching off the electric lights at home for 9 minutes from 9:00 p.m. to 9:09 p.m. and observed lighting diya, candle; and flashing torchlight and mobile flashlight.\n");
    printf("\n\nPhase 2 (15 April to 3 May)\n\n");
    printf("On 14 April, PM Modi extended the nationwide lockdown till 3 May, with a conditional relaxation promised after 20 April for the regions where the spread had been contained by then\n");
    printf("On 16 April, lockdown areas were classified as red zone, indicating the presence of infection hotspots, orange zone indicating some infection, and green zone with no infections\n");
    printf("The government also announced certain relaxations from 20 April, allowing agricultural businesses, including dairy, aquaculture and plantations, as well as shops selling farming supplies, to open\n");
    printf(" Public works programmes were also allowed to reopen with instructions to maintain social distancing.\n Banks and government centres distributing benefits would open as well.\n");
    printf("On 25 April, small retail shops were allowed to open with half the staff. Again social distancing norms were to be followed.\n");
    printf("On 29 April, The Ministry of Home Affairs issued guidelines for the states to allow inter-state movement of the stranded persons.\nStates have been asked to designate nodal authorities and form protocols to receive and send such persons. States have also been asked to screen the people, quarantine them and to do periodic health checkups.\n");
    printf("\n\nPhase 3 (4 May to 17 May)\n");
    printf("The country has been split into 3 zones: red zones (130 districts), orange zones (284 districts) and green zones (319 districts).\n[48] Red zones are those with high coronavirus cases and a high doubling rate, orange zones are those with comparatively fewer cases and green zones are those without any cases in the past 21 days\n");
    printf("Normal movement is permitted in green zones with buses limited to 50 percent capacity.\n Orange zones would allow only private and hired vehicles but no public transportation. The red zones would remain under lockdown.\n The zone classification would be revised once a week\n");
    printf("\n\nPhase 4 (18 May to 31 May)\n");
    printf(" Unlike the previous extensions, states were given a larger say in the demarcation of Green, Orange and Red zones and the implementation roadmap.\n Red zones were further divided into to containment and buffer zones.\n The local bodies were given the authority to demarcate containment and buffer zones\n");
    printf("\n\nPhase 5 (1 June to 30 June)\n");
    printf("Lockdown restrictions would only be imposed in containment zones, while activities would be permitted in other zones in a phased manner.\n");
    printf("This first phase of reopening is termed as Unlock 1 and permits shopping malls, religious places, hotels and restaurants to reopen from 8 June.\n");
    printf("However, night curfews would be in effect from 9 p.m. to 5 a.m. in all areas and state governments would be allowed to put suitable restrictions on all activities.\n");
    printf("In Phase II, all educational institutions are scheduled to reopen in July, pending consultations with state governments.\n");
    printf("In Phase III, easing of restrictions on international air travel, operation of metros and recreation (swimming pools, gymnasiums, theatres, entertainment parks, bars auditoriums and assembly halls)\n would be decided upon in August\n");
    printf("However, further in June, Human Resource And Development Minister Ramesh Nishank Pokhriyal announced in an interview that all the educational institutes will reopen after 15th August\n");
   break;

   case 2:
    printf("\n\nAIRWAYS\n");
   printf("1. Flights to India are suspended.\n- This does not apply to flights that carry goods for trade or essential goods and supplies, and their crew members, helpers, cleaners.\n");
   printf("2. Nationals of India are only allowed to return to India by flights arranged by Ministry of Civil Aviation (MOCA).\n");
   printf("3. Passengers with an Overseas Citizen of India (OCI) card or booklet are allowed to enter India. They must be:\n- minor children born to nationals of India abroad; or\n- coming to India due to family emergencies like death in family; or\n- couples where one spouse is an OCI holder and the other is a national of India and they have a permanent residence in India; or\n- university students whose parents are nationals of India living in India.\n");
   printf("4. Passengers with a Business visa (excluding B-3 visa for sports) or an Employment visa issued after 1 June 2020 are allowed to enter.\n");
   printf("5. Passengers are required to undergo mandatory quarantine for 14 days.\n");
   printf("\n\nRAILWAYS\n");
   printf("The railways, called the lifeline of the country, had suspended passenger services from March 22 midnight due to the pandemic.\n");
   printf("1.Indian Railways, among the world's largest rail networks, tentatively ground back to life on May 12 as a gradual lifting \nof the world's biggest coronavirus lockdown gathered pace even as new cases surged. \n");
   printf("2.All passengers with confirmed tickets will need to reach railway station before 90 mim\n");
   printf("3.Only passengers with tickets and thermal screening will be allowed in platform.\n");
   printf("4.Arogya Setu app must be installed.\n");
   printf("5.Passengers will have to bring their own food.\n");
   break;
   default:
   printf("Not valid number\n");

}
printf("\n\n\nEnter 1 to continue reading. Enter any other key (except enter key) to go back to the main menu: ");
scanf(" %c",&garbage);
if(garbage==49)
goto R1;
}
//end of lockdownRestrictions


//The function definition for ratings_review()
void ratings_review(int index, struct database *users)
{
    char ch;
    int v=0;

    //display the objective of the function.
    printf("\n\n\n\tDear %s,\n\n\tIt was our pleasure to serve you today.\n\n\tWe are working very hard to build a higher quality product for our customers.\n\n\tWe would love to learn more about your opinion.",(*users).user_name);
    printf("\n\n\tIt would only cost you a couple of minutes but it would mean a lot to us.\n\n\tPlease Enter Y if you would like to give us a feedback: ");
    scanf("  %c", &ch);

    if (!(ch=='y' || ch=='y'))      //the user does not want to review us.
        return;

    //assign avg_rate to 0.
    users->avg_rate=0.0;

    //get user ratings.
    printf("\n\n  On the scale of 1 to 5 (with 5 being the highest):\n\n");
    printf(" How would you rate the user interface of the program: ");
    scanf("%d",&users->rating[v]); v++;
    printf("\n How would you rate the available facilities of the program: ");
    scanf("%d",&users->rating[v]); v++;
    printf("\n How would you rate data provided in the program: ");
    scanf("%d",&users->rating[v]); v++;
    printf("\n How would you rate the usefulness of the program to you: ");
    scanf("%d",&users->rating[v]); v++;

    //calculate and display average ratings
    for(int q=0; q<4; q++)
    {
        if(users->rating[q]>5)
                users->rating[q]=5;
        else
        if(users->rating[q]<1)
                users->rating[q]=1;
        else
        users->avg_rate+=users->rating[q];
    }
    users->avg_rate/=4.0;
    printf("\n\n\tYour average rating: %.2f\n",users->avg_rate);

    //Get user review.
    printf("\n\nPlease leave a review(less than 200 words):\n\n\t ");
    scanf("    %[^\n]s",users->review);

    sleep(1);

    printf("\n\n\tTHANK YOU!!! Your opinion is highly valued! It will only help us get better and serve you efficiently.\n\n");

    //save the user entered details into the file i+1_User_details.txt
    fprintf(fptr[index],"\nUSER RATING: Average rating: %.2f\nUSER REVIEW: %s\n",users->avg_rate,users->review);

    return;
}
//end of rating_review().


//end of ALL_IN_ONE_COVID-19 source code.
