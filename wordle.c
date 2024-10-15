#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int  WORD_LENGTH=5;
int MAX_GUESSES=6;

char *wordlist[]={"apple","daily","place","peace","mango","plane"};

int wordlistsize=sizeof(wordlist)/sizeof(wordlist[0]);

char *selectword()
{
    srand(time(NULL));
    int index=rand()%wordlistsize;
    return wordlist[index];
}

void wordle(const char* target, const char* guess, char* feedback)
{
    for (int i=0;i<WORD_LENGTH;i++)
        {
        if (guess[i] == target[i])
        {
            feedback[i] = 'G';
        }
    else if (strchr(target, guess[i]))
        {
            feedback[i] = 'Y';
        }
    else
        {
            feedback[i] = 'B';
        }
    }
    feedback[WORD_LENGTH] = '\0';
}

int isValidGuess(const char* guess) {
    for (int i = 0; i <wordlistsize; i++) {
        if (strcmp(guess, wordlist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    const char* targetWord = selectword();
    char guess[WORD_LENGTH + 1];
    char feedback[WORD_LENGTH + 1];
    int guesses = 0;
    int won = 0;

    printf("Welcome to Wordle!\n");

    while (guesses < MAX_GUESSES)
        {
        printf("Enter your guess (%d/%d): ", guesses + 1, MAX_GUESSES);
        scanf("%5s", guess);

        if (!isValidGuess(guess))
            {
            printf("Invalid guess. Try again.\n");
            continue;
        }

        guesses++;

        wordle(targetWord, guess, feedback);
        printf("Feedback: %s\n", feedback);

        if (strcmp(guess, targetWord) == 0) {
            won = 1;
            break;
        }
    }

    if (won) {
        printf("Congratulations! You guessed the word '%s'.\n", targetWord);
    } else {
        printf("Sorry, you used all your guesses. The word was '%s'.\n", targetWord);
    }

    return 0;
}
