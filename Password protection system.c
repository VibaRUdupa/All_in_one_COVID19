#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct database
{
  char user_name[10];
  char password[5];
  int points;
}user[10];

void main()
{
  static int i=0;
  int c1,j=0,c2,index=-1,current_index=-1;
  A:printf("\nWelcome.\n1.New user(sign up)\n2.Existing user(sign in)\nEnter your choice: ");
  scanf("%d",&c1);
  switch(c1)
  {
    case 1: if(i>=5)
            {
              printf("Session overload!");
              exit(1);
            }
            printf("Enter your user name(less than 10 characters): ");
            scanf("  %[^\n]s",&user[i].user_name);
            printf("Enter a password(less than 5 characters): ");
            scanf("  %[^\n]s",&user[i].password);
            printf("Account created successfully!");
            current_index=i;
            printf("\nAdd a value to your current points: ");
            scanf("%d",&user[current_index].points);
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
  printf("\nCurrent value of your points=%d",user[current_index].points);
  printf("\nchange the value of your current points: ");
  scanf("%d",&user[current_index].points);
  B:printf("\n1.log out\n2.Exit\nEnter your choice: ");
  scanf("%d", &c2);
  switch(c2)
  {
    case 1: printf("\nLogging out...");
            sleep(1);
            printf("\nsuccessfully Logged off.\n");
            if(c1==1)
            i++;
            main();
            break;

    case 2: printf("If you exit, all your data will be lost.\nARE YOU SURE YOU WANT TO EXIT! (Y/N): ");
            char c3;
            scanf(" %c",&c3);
            if(c3=='Y' || c3=='y')
            {
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
