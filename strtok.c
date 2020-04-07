#include <stdio.h>
#include <stdlib.h>

int strlen(char *string)
{
    int len = 0;
    while (string[len++] != NULL)
        ;
    return len - 1;
}

// Checks whether the character 'c' is one of the characters in the string 'characters'.
int isOneOf(char c, char *characters)
{
    for (int i = 0; i < strlen(characters); i++)
    {
        if (characters[i] == c)
            return 1;
    }
    return 0;
}

char **strtok(char *string, char *delimiters)
{
    char **tokens;
    int len = strlen(string), j = 0, k = 0, foundDelemiter = 0;
    tokens = (char **)malloc(len * sizeof(char));
    *tokens = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        if (isOneOf(string[i], delimiters))
        {
            if (!foundDelemiter)
            {
                (*(tokens + k))[++j] = '\0';
                k++;
            }
            *(tokens + k) = (char *)malloc(len * sizeof(char));
            foundDelemiter = 1;
            j = 0;
        }
        else
        {
            (*(tokens + k))[j++] = string[i];
            foundDelemiter = 0;
        }
    }
    return tokens;
}

int main()
{
    char sentence[1024];
    scanf("%[^\n]%*c", sentence);
    char **p = strtok(sentence, " ,.");
    while (*p != '\0')
    {
        printf("%s\n", *p);
        p++;
    }
    return 0;
}