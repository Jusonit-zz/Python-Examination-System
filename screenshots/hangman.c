/*
Name: Junior Figuereo
Course: CS288-101

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool win = false; //WIN CONDITION

//****************************
    //CHECK FUNCTION:
    //      check whether the letter is in the word
    //                  if it is: reveal the letters in the word by replacing the *'s where the letter belongs
    //                  if it is not: minus one misses left
    //      returns bool
//****************************
bool check(char *word, char *hidden, char letter, int length)
{
    int i = 0;
    bool guess = false;
    for(i; i<length; i++)
    {
        if(word[i] == letter)
        {
            hidden[i] = word[i]; //or letter
            guess = true;
        }
    }

    bool fullword = true;
    i = 0;

    for (i; i<length; i++)
    {
        if(hidden[i] == '*')
        {
            fullword = false;
            break;
        }
    }
    if (fullword)
        win = true;
    return guess;
}

//****************************
    //DISPLAY FUNCTION:
    //      PARAMETERS PASSED:
            //CHAR *HIDDEN
            //INT LENGTH
    //Displays the current state of the guessing word.
    //Display correct guessed letters and rest are *'s
//****************************
void display(char *hidden, int length)
{
    int i = 0;
    for(i; i<length; i++)
        printf(" %c", hidden[i]);

    printf("\n\n\n");
    return;
}

int main ()
{
//****************************
    //VARIABLES DECLARATION
//****************************
    bool guessed_right = false;
    int misses_left = 6;
    char word[80] = "strengthen";
    char letter;
    int length = strlen(word);

    char hidden[length+1];
    int i = 0;
    for (i; i<length; i++)
    {
        hidden[i] = '*';
        printf(" %c", hidden[i]);
    }


//****************************
//****************************

    printf("Welcome to Hangman!\n");
    printf("Try to guess the secret word one letter at a time. \n");

//****************************
    //WHILE LOOP:
    //      asks for a letter
    //      calls check function
    //      keeps track of missed letters (misses_left)
    //      calls Display function
    //      repeat until misses == 0 or until win condition is true;
//****************************
    while(misses_left > 0 && !win)
    {
        if(win)
            printf("WIN IS TRUE\n");
        printf("# misses left = %d \n", misses_left);
        printf("enter a letter: ");
        scanf(" %c", &letter);

        guessed_right = check(word, hidden, letter, length);

        if (!guessed_right)
            misses_left--;

         display(hidden, length);
    }

    if(!win)
    {
        printf("YOU LOSE! The word is: ");
        i = 0;
        for (i; i < length; i++)
            printf("%c", word[i]);
    }
    else
    {
        printf("YOU WIN! The word is: ");
        i = 0;
        for (i; i < length; i++)
            printf("%c", word[i]);
    }

    return 0;

}
