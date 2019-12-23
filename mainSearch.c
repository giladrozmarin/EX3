#include "txtSearch.h"
#
int main()
{

  
    char strTotxt[LINE][WORD]; // 256 30
    char allLine[LINE];
    textToString(strTotxt,allLine);    //copy all text to 2d array
    char findWord[WORD];       //the first word in the text this is what we are goiing to looking for
    copyWordToFind(findWord, strTotxt);
    char option = strTotxt[1][0];
    if (option == 'a')
    {
        optionA(strTotxt, findWord);
    }

       else if (option == 'b'){
           optionB(strTotxt, findWord);
       }
       else
       {
           puts("pleas chose a or b as option ");
       }

}
