#include "text.h"
#include "string.h"
#include "stdio.h"
#include "assert.h"
#include "fileLib.h"
#include "oneginSorterLib.h"

void readTextf(FILE* file_ptr, Text* text){
    assert(file_ptr != NULL);

    text->size = getFileSize(file_ptr);
    getText(file_ptr, &(text->text), text->size);
}

//---------------------------------------------------------------

void parseText(Text* text){
    splitText(text);

    text->strings = (String*) calloc(text->nStrings, sizeof(String)); //! array of pointers to begins of strings
    assert(text->strings != NULL);

    buildText(text);
}

//-------------------------------------------------------------

void splitText(Text* text){
    assert(text != NULL);

    text->nStrings = 1;
    char* curChar = text->text, *nextChar = NULL;
    do{
        nextChar = strchr(curChar, '\n');
        *nextChar = '\0';
        nextChar++;

        if(*nextChar != '\n' && *nextChar != '\0')
            text->nStrings++;

        curChar = nextChar;
    }while(*curChar != '\0');

}

//----------------------------------------------------------

void buildText(Text* text){
    assert(text!=NULL);
    assert(text->strings!=NULL);

    char* curChar = text->text;
    size_t curString = 0;
    do{

        while (*curChar == '\0') {        //Skipping empty lines
            curChar++;
            if(curChar == text->text + text->size) return;
        }

        text->strings[curString].pBegin = curChar;
        text->strings[curString].size = strlen(text->strings[curString].pBegin);
        curChar += text->strings[curString].size;
        curString++;

    } while (curChar != text->text + text->size);
}

//-------------------------------------------------------------

void freeText(Text* text){
    if(text->text)
        free(text->text);
    if(text->strings)
        free(text->strings);
}
//---------------------------------------------------------------
void sortText(Text *text){
    assert(text != NULL);
    String* buffer = (String*) calloc(text->size, sizeof(String));
    assert(buffer != NULL);

    mergeTextSort(text->strings, buffer, text->nStrings, isLessStr);

    free(buffer);
}
