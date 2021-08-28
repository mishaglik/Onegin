#ifndef ONEGIN_ONEGINSORTERLIB_H
#define ONEGIN_ONEGINSORTERLIB_H

#include "stdlib.h"
#include "text.h"

/*!
 * Compares strings s1 and s2 in lexicographical order by characters
 * @param s1 -------^      ^
 * @param s2 ---------------
 * @return true if s1 < s2, 0 otherwise
 */
int isLessStr(const void *p1, const void *p2);

/*!
 * Compares strings s1 and s2 in REVERSED lexicographical order by characters
 * @param s1 -------^      ^
 * @param s2 ---------------
 * @return true if s1 < s2, 0 otherwise
 */
int isLessStrReverse(const void *s1, const void *s2);



/*!
 * Sorts text with merge sort. Must be given with buffer
 * @param pBegin - pointer to begin of sorting array
 * @param buffBegin - pointer to begin of buffer
 * @param size - size of array to sort
 * @param comparator - function that must return true if first string is less than the second one
 */
void mergeTextSort(String *pBegin, String* buffBegin, size_t size, int (*comparator)(const void*, const void*));

/*!
 * Checks if c is letter of alphabet
 * @param c - char to char
 * @return 1(letter) / 0(not letter)
 */
int isLetter(char c);


/*!
 * Skips text to first letter or end of string
 * @param string - pointer to string to process
 */
void skipToLetter(char **string);

/*!
 * Skips text to first letter from end or beginning of string
 * @param pChr - pointer to last symbol
 * @param beginOfStr - pointer to first symbol
 */
void skipToLetterReverse(char **pChr, const char *beginOfStr);
#endif //ONEGIN_ONEGINSORTERLIB_H
