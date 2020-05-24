#include<stdio.h>
#include<ctype.h>

void main(){

    char hangman[6][10]={"ARCHITECT", "BADMINTON", "KANGAROOS", "ISOLATION", "ARGENTINA", "PINEAPPLE"};		//create an array of strings to store the words to play for hangman.
	char ans[6][10]={"A___I_E__", "_A__I__O_", "_A__A_OO_", "I_O_A_IO_", "A__E__I_A", "_I_EA___E" }; 	//create another array of strings to store the words with hidden consonants, to be displayed to the user.
	char guess;  	//to store the alphabet guessed by the user.
	int dash=0, chance=5, value=0, points=0;  	
	//dash:to count number of spaces yet to be filled by the user.
	//chance:to count remaining trials for the user.
	//value: intended to store boolean value(0 or 1) to determine a right or wrong guess by the user.
	//points: to keep a track of points scored by the user.
	
	//set of instructions to be displayed.
	printf("\t\t\t\t\t\tWELCOME TO HANGMAN \n");
	printf("\t\t\t\t\t       --- INSTRUCTIONS ---");
	printf("\n\n1.Only vowels of the word will be displayed and the consonants will be hidden. ");
	printf("\n2.The user must guess the missing alphabets one by one. ");
	printf("\n3.If the guessed letter is a part of the word, then it will be displayed. ");
	printf("\n4.Else the user loses a chance. The maximum number of allowed incorrect guesses are 5.");
	printf("\n5.If you lose all your turns, your game ends. If you guess a word correctly, you get 10 points and the game will automatically go to next level. ");
	printf("\n\n\t\t\tALL THE BEST\n\n");

	for(int i=0; i<6; i++){
		//switch to be executed once per loop to give users the hints for each word.
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
		    for(int j=0; j<10; j++){		//checks if the guessed letter is a part of the hidden word.
			   if(guess==hangman[i][j]){
				    ans[i][j]=guess;	//if true, then the guessed letter will be updated in to the answer array.
				    value++;		//incrementation of value to note that guessed letter is correct.
				}
			}
			if(value==0)			//value=0 means the user guessed a wrong alphabhet,the number of chances left will be decremented by one.
			   chance--;
			for(int d=0; d<10; d++){	//to update dash on the pending blanks in the word.
			   if(ans[i][d]=='_' )
			       dash++;
			}
			if(value==0 && chance!=0)
			{	//wrong guess but still can try the game.
				printf("\nWRONG GUESS. But you can still try again.");
				value=0;
				goto L;
			}
			if(value==0 && chance==0)
			{	//wrong guess and number of pending tries equals zero.
				char end;
				printf("\nGAME OVER - YOUR HAVE ZERO CHANCES LEFT.\nThe word is %s \nPress any key to continue.\n",hangman[i]);
				scanf("  %c",&end);
				value=0;
				break;
			}
			if(dash!=0 && value!=0)
			{	//a correct guess by user but the word is still incomplete.
				printf("\nGOOD GUESS.");
				value=0;
				dash=0;
				goto L;
			}
			if(dash==0 && value!=0)
			{	//all the missing blanks in the word have been guessed correctly by the user.
				printf("\n%s \nCONGRATULATIONS. \nYou have successfully guessed the word.\n", ans[i]);
				char end;
				printf(" \nPress any key to continue.\n");
				scanf("  %c",&end);
				points=points+10;
				chance=5;
				value=0;
				dash=0;
			}
	}
	printf("\nYour score: %d \n", points);

}
