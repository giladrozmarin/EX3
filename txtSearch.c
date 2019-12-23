#include "txtSearch.h"

//Get text into char[][]
void textToString(char strTotxt[1][WORD], char allLine[LINE])
{
    /* condition */
    char c;
    int charCount, line = 0;
    while (scanf("%c", &c) != EOF)
    {
        //check if we get \n  or space
        if (charCount > WORD || line > LINE)
        {
            puts("Pleas edite you file the max word leangth is 30 and the max lines in file is 256");
            break;
        }
        if (c != '\n' && c != ' ' && c != '\t' && c != '\0')
        {
            strTotxt[line][charCount++] = c;
        }

        else //new line word
        {
            strTotxt[line][charCount++] = c;
            line++;
            charCount = 0;
        }
    }
}

void copyWordToFind(char findWord[WORD], char strTotxt[0][WORD])
{

    for (size_t i = 0; i < WORD; i++)
    {
        /* code */
        findWord[i] = strTotxt[0][i];
    }
}

void optionA(char strTotxt[LINE][WORD], char findWord[WORD])
{
    int charCounter = 0;
    int diffCounter = 0;
    int len = 0;
    int len1 = 0;
    for (int i = 0; i < WORD; i++)
    {

        if (findWord[i] == ' ' || findWord[i] == '\n' || findWord[i] == '\t' || findWord[i] == '\0')
        {
            break;
        }
        len++;
    }

    for (size_t i = 3; i < LINE; i++)
    {
        for (size_t j = 0; j < WORD;)
        {
            if (strTotxt[i][j] == ' ' || strTotxt[i][j] == '\n' || charCounter > 30)
            {
                break;
            }

            if (strTotxt[i][j] != findWord[charCounter])
            {
                diffCounter++;
                j++;
            }
            else
            {
                charCounter++;
                j++;
            }
        }
        if (diffCounter <= 1)
        {
            for (int k = 0; k < WORD; k++)
            {

                if (strTotxt[i][k] == ' ' || strTotxt[i][k] == '\n' || strTotxt[i][k] == '\t' || strTotxt[i][k] == '\0')
                {
                    break;
                }
                len1++;
            }

            if (len1 >= len)
            {
                printf("%s", *(strTotxt + i));
                if (strTotxt[i][len1] != '\n')
                {
                    printf("\n");
                }
            }
        }

        diffCounter = 0;
        charCounter = 0;
        len1 = 0;
    }
}

void optionB(char strTotxt[LINE][WORD], char findWord[WORD])
{
    int charCounter = 0;
    int diffCounter = 0;
    int len = 0;
    int len1 = 0;

    for (int i = 0; i < WORD; i++)
    {

        if (findWord[i] == ' ' || findWord[i] == '\n' || findWord[i] == '\t' || findWord[i] == '\0')
        {
            break;
        }
        len++;
    }

    for (int i = 3; i < LINE; i++)
    {
        for (size_t j = 0; j < WORD;)
        {
            if (strTotxt[i][j] == ' ' || strTotxt[i][j] == '\n' || charCounter > 30)
            {
                break;
            }

            if (strTotxt[i][j] != findWord[charCounter])
            {
                diffCounter++;
                j++;
            }
            else
            {
                charCounter++;
                j++;
            }
        }
        if (diffCounter <= 1)
        {
            for (int k = 0; k < WORD; k++)
            {

                if (strTotxt[i][k] == ' ' || strTotxt[i][k] == '\n' || strTotxt[i][k] == '\t' || strTotxt[i][k] == '\0')
                {
                    break;
                }
                len1++;
            }

            if (len1 >= len)
            {
                printAllLine(strTotxt, i);

                if (strTotxt[i][len1] != '\n')
                {
                    printf("\n");
                }
                int q = 0; 
                int keepit=0;
                    for(i;i<LINE;i++)
                    {
                    for (q = 0; q < WORD; q++)
                    {
                       
                        if (strTotxt[i][q] == '\n')
                        {
                            keepit=q;
                            break;
                            
                        }
                    }
                          if (strTotxt[i][keepit] == '\n')
                        {
                            break;
                        }
                  
                    i++;
                    }
                
            }
        }
        diffCounter = 0;
        charCounter = 0;
        len1 = 0;
    }
}

void printAllLine(char strTotxt[LINE][WORD], int i)
{
    int keepi = i - 1;
    int linehanter = 0;
    int r = 0;
    int l = 0;
    while (strTotxt[i][linehanter] != '\n')
    {
        if (strTotxt[i][linehanter] == ' ' || strTotxt[i][linehanter] == '\n' || strTotxt[i][linehanter] == '\t' || strTotxt[i][linehanter] == '\0')
        {
            linehanter = 0;
            i++;
        }
        linehanter++;
        r = i;
    }

    while (strTotxt[keepi][linehanter] != '\n')
    {
        if (strTotxt[keepi][linehanter] == ' ' || strTotxt[keepi][linehanter] == '\n' || strTotxt[keepi][linehanter] == '\t' || strTotxt[i][linehanter] == '\0')
        {
            linehanter = 0;
            keepi--;
        }
        linehanter++;
        l = keepi;
    }

    for (int y = l + 1; y <= r; y++)
    {
        printf("%s", *(strTotxt + y));
    }
}
