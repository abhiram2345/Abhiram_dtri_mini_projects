#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 5

int main() {
  char word[WORD_LENGTH + 1];
  char guess[WORD_LENGTH + 1];

  printf("Enter the secret word (length %d): ", WORD_LENGTH);
  scanf("%s", word);


  for (int i = 0; i < 6; i++) {
    printf("Guess %d (length %d): ", i + 1, WORD_LENGTH);
    scanf("%s", guess);

    if (strcmp(word, guess) == 0) {
      printf("Congratulations! You guessed the word in %d tries.\n", i + 1);
      return 0;
    }
  }

  printf("Sorry, you ran out of guesses. The word was %s.\n", word);
  return 0;
}


