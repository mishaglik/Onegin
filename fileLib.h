#ifndef ONEGIN_FILELIB_H
#define ONEGIN_FILELIB_H
#include "stdlib.h"
#include "stdio.h"
#include "text.h"



/*!
 * Print sorted text to file(filename)
 * @param file_ptr - file to write
 * @param strings - text to write
 * @param len - length of text
 */
void printSortedText(FILE *file_ptr, String *strings, const size_t len);

/*!
 * Prints n(nStr) strings of text to file with filename
 * @param file_ptr
 * @param text
 * @param nStr
 */
void printRawText(FILE *file_ptr, char *text, const size_t nStr);

/*!
* Fills text with text from file
* @param file_ptr
*/

void getText(FILE *file_ptr, char** text, size_t size);

/*!
 * Counts size of file.
 * !!!!!! Returns carriage to begin of file !!!!!!
 * @param file_ptr - pointer to open file
 * @return how much chars file contain. Returns zero if file is NULL
 */
size_t getFileSize(FILE* file_ptr);



#endif //ONEGIN_FILELIB_H
