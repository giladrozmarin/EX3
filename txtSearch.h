#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

void textToString(char strTotxt[LINE][WORD],char allLine[LINE]);
void copyWordToFind(char findWord[WORD],char strTotxt[0][WORD]);
void optionA(char strTotxt[LINE][WORD],char findWord[WORD]);
void optionB(char strTotxt[LINE][WORD], char findWord[WORD]);
void printAllLine(char strTotxt[LINE][WORD],int i);
