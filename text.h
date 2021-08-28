#ifndef ONEGIN_TEXT_H
#define ONEGIN_TEXT_H
#include "stdlib.h"
#include "stdio.h"
/*!
 * Class to keep strings information
 */
struct String{
    char* pBegin = NULL;
    size_t size = 0;
};

/*!
 * Struct to keep parsed text
 */
class Text{
public:
    char* text = NULL;                 //! Pointer to text

    String* strings = NULL;     //! Array of parsed strings
    size_t size = 0;            //! Size of text
    size_t nStrings = 0;        //! Number of strings
};

/*!
 * Reads file to text
 * @param file_ptr - pointer to file
 * @param text - text to write on
 */
void readTextf(FILE* file_ptr, Text* text);

/*!
 * Parsing text. Splits strings and build map of strings
 * @param text
 */
void parseText(Text* text);

/*!
 * Splits text into array of strings
 * @param text - text to split
 * @param max_str_cnt - maximum strings to find
 * @return number of strings found
 */
void splitText(Text* text);

/*!
 * Building map: Fills array of pointers to begins of strings
 * @param text - text to process
 * @param strings - array to fill
 */
void buildText(Text* text);

/*!
 * Sorts text by lexicographical order
 * @param text - text to sort (array of strings)
 * @param size - number of lines to sort
 */
void sortText(Text *text);

/*!
 * Frees space taken by file
 * @param text
 */
void freeText(Text* text);
#endif //ONEGIN_TEXT_H
