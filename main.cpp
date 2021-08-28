#include <stdio.h>
#include "assert.h"
#include "string.h"

#include "fileLib.h"
#include "text.h"

#include "oneginSorterLib.h"

const char* OUT_FILENAME_APPEND = ".new";

int main(int argc, const char *argv[]){
    if(argc < 2){
        printf("Please specify filename of input text when calling program.");
        return 0;
    }

    const char* inFilename = argv[1];
    char* outFilename = NULL;

    for(int i = 2; i < argc; ++i){
        if(strcmp(argv[i], "-o") == 0){
            if(i+1 == argc){
                printf("Please specify filename of out file.\n");
                return 0;
            }
            else{
                outFilename = strdup(argv[i+1]);
            }
        }
    }

    if(!outFilename){
        outFilename = (char*) calloc(strlen(inFilename) + strlen(OUT_FILENAME_APPEND), sizeof(char));
        strcpy(outFilename, inFilename);
        strcat(outFilename, OUT_FILENAME_APPEND);
    }

    FILE* in_file_ptr = fopen(inFilename, "r");
    assert(in_file_ptr != NULL);

    Text text = {};
    readTextf(in_file_ptr, &text);
    parseText(&text);
    fclose(in_file_ptr);

    FILE *out_file_ptr = fopen(outFilename, "w");

    sortText(&text);                                                            //Sorting
    printSortedText(out_file_ptr, text.strings, text.nStrings);

    qsort(text.strings, text.nStrings, sizeof(String), isLessStrReverse);       //Reverse sorting
    printSortedText(out_file_ptr, text.strings, text.nStrings);

    printRawText(out_file_ptr, text.text, text.nStrings);

    fclose(out_file_ptr);
    free(outFilename);
    freeText(&text);
}



