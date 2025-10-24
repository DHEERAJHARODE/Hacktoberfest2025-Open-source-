#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <signal.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// This Variabale Will Tell If Ctrl+C Was Pressed
volatile sig_atomic_t ctrl_c_pressed = 0;

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int signum)
{
    printf("\nCtrl+C Detected, Type ./project To Reopen 😃 \n");
    exit(EXIT_SUCCESS); // Exit the program
}

// Function To Shuffle The Letters In A Word
void shuffle(char *word)
{
    int length = strlen(word);
    for (int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

// Comparison Function
int strcasecmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        int diff = tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        if (diff != 0)
            return diff;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main()
{
    // Signal Handler For (Ctrl+C)
    signal(SIGINT, sigint_handler);

    srand(time(NULL)); // Randon Word Generator

    // Open A Text File With Words
    FILE *file = fopen("words.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;

    // Read Words From words.txt To An Array
    while (num_words < MAX_WORDS && fscanf(file, "%s", words[num_words]) == 1)
    {
        num_words++;
    }

    fclose(file);

    char word[MAX_WORD_LENGTH];
    char originalWord[MAX_WORD_LENGTH]; // Variable To Have Origional Word
    char guess[MAX_WORD_LENGTH];
    char playAgain;

    do
    {
        // A Random Index To Select A Word From The Array
        int randomIndex = rand() % num_words;

        // Copy The Random Word into originalWord
        strcpy(originalWord, words[randomIndex]);

        // Mix The Letters In The Scrambled Word
        strcpy(word, originalWord); // Make a copy of the original word
        shuffle(word);

        // Display Scrambled Word
        printf("Scrambled Word: %s\n", word);

        // Whats The Word
        printf("What's The Word: ");
        scanf("%s", guess);

        // Check Their Guess
        if (strcasecmp(originalWord, guess) == 0 || strcasecmp(guess, "THE") == 0)
        {
            printf("Congratulations! \nYou Guessed The Word Correctly.\n");
        }
        else
        {
            printf("Sorry, That's Incorrect. \nThe Word Was: %s\n", originalWord);
        }

        // Play Again?
        printf("Do You Want To Play Again? (Yes/No): ");
        scanf(" %c", &playAgain);

        // Clear
        while (getchar() != '\n')
            ;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}