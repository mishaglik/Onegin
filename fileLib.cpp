#include "fileLib.h"
#include "string.h"
#include "assert.h"
#include "stdio.h"
#include "text.h"

void printRawText(FILE *file_ptr, char *text, const size_t nStr){
    assert(file_ptr != NULL);
    int nWrite = 0;
    for(int i = 0; i < nStr; i++){
        fprintf(file_ptr,"%s\n%n", text, &nWrite);
        text += nWrite;
    }
    fprintf(file_ptr, "\n");

}

//--------------------------------------------------------------------------

void printSortedText(FILE *file_ptr, String *strings, const size_t len) {
    assert(file_ptr != NULL);

    for(int i = 0; i < len; ++i){
        assert(strings[i].pBegin != NULL);

        fprintf(file_ptr, "%s\n", strings[i].pBegin);
    }
    fprintf(file_ptr, "\n");

}

//----------------------------------------------------

size_t getFileSize(FILE *file_ptr){
    if(file_ptr == NULL){
        return 0;
    }

    fseek(file_ptr, 0L, SEEK_END);
    size_t size = ftell(file_ptr);
    rewind(file_ptr);
    return size;
}

//----------------------------------------------------------------------

void getText(FILE *file_ptr, char** text, size_t size){
    assert(file_ptr != NULL);
    assert(text != NULL);

    if(!size){
        printf("getText(): Warn: File's size is 0\n");
        return;
    }

    *text = (char*)calloc(size + 1, sizeof(char));

    assert(text != NULL);

    fread(*text, sizeof(char), size, file_ptr);

    if(**text == '\0'){
        printf("getText(): Warn: Nothing to read\n");
        return;
    }
}