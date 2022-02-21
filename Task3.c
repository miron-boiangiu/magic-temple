#include "utils.h"
#define MAXBUF 1200
#define MAXSTRINGSIZE 10000

void replace_character(char **string, char removable)
{
    for (int i = 0; i < strlen(*string); i++)
    {
        if ((*string)[i] == removable)
        {
            (*string)[i] = ' '; //Put a space where you find the character.
        }
    }
}
void remove_character(char **string, int position)
{
    for (int i = position; i < strlen(*string); i++)
    {
        (*string)[i] = (*string)[i + 1]; //Move everything to the right of the
    }                                    //character one position to the left.
}
void remove_excess_spaces(char **string)
{
    int length = strlen(*string);
    for (int i = 0; i < length; i++)
    {
        if ((*string)[i] == ' ' && (*string)[i + 1] == ' ')
        {
            while ((*string)[i + 1] == ' ')
            {
                remove_character(string, i + 1);
            }
        }
        length = strlen(*string);
    }
    if ((*string)[strlen(*string) - 1] == ' ')
    {
        (*string)[strlen(*string) - 1] = '\0';
    }
} /*This function checks for where it finds a double space
And then proceeds to remove all the spaces that follow that space,
leaving a single one after this process.*/

void SolveTask3()
{
    char c = '\n';
    scanf("%c", &c); //Remove trailing newline.
    char *buffer;
    buffer = calloc(MAXBUF, 1);
    char *string;
    string = calloc(MAXSTRINGSIZE, 1);
    strcpy(string, ""); //Create string to contain the text
    while (fgets(buffer, MAXBUF, stdin) != NULL)
    {
        strcat(string, buffer); //Read all lines into the single string
    }
    char to_remove[] = {';', ',', '\n', '.', '!'}; //Characters to be removed
    for (int i = 0; i < sizeof(to_remove); i++)
    {
        replace_character(&string, to_remove[i]);
    } //Replace all the irrelevant characters with spaces.
    remove_excess_spaces(&string);
    int word_count = 0;
    for (int i = 0; i <= strlen(string); i++)
    {
        if (string[i] == ' ' || string[i] == '\0')
        {
            word_count++;
        }
    }
    char *word = strtok(string, " ");
    char **words;
    words = calloc(word_count, sizeof(char *));
    int word_pos = 0;
    while (word != NULL)
    {
        words[word_pos] = word;
        word_pos++;
        word = strtok(NULL, " ");
    } //Check how many unique ngrams there are.

    int ngram_number = 0;
    for (int i = 0; i < word_count - 1; i++)
    {
        int already_checked = 0;
        for (int j = 0; j < i; j++)
        {
            if ((strcmp(words[i], words[j]) == 0) && (strcmp(words[i + 1], words[j + 1]) == 0))
            {
                already_checked = 1;
                break;
            }
        }
        if (already_checked)
        {
            continue;
        }
        ngram_number++;
    }
    printf("%d\n", ngram_number);
    //Check how many times each ngram shows up.

    for (int i = 0; i < word_count - 1; i++)
    {
        int frequency = 0;
        int already_checked = 0;
        for (int j = 0; j < i; j++)
        {
            if ((strcmp(words[i], words[j]) == 0) && (strcmp(words[i + 1], words[j + 1]) == 0))
            {
                already_checked = 1;
                break;
            }
        }
        if (already_checked)
        {
            continue;
        }
        printf("%s %s ", words[i], words[i + 1]);
        for (int j = i; j < word_count - 1; j++)
        {
            if ((strcmp(words[i], words[j]) == 0) && (strcmp(words[i + 1], words[j + 1]) == 0))
            {
                frequency++;
            }
        }
        printf("%d\n", frequency);
    }
}