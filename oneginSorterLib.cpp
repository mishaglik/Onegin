#include <assert.h>
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "oneginSorterLib.h"
#include "text.h"


int isLessStr(const void *p1, const void *p2) {
    if(p1 == p2)
        return 0;

    String *s1 = (String *)p1, *s2 = (String *)p2;

    char* pos1 = s1->pBegin, *pos2 = s2->pBegin;

    assert(s1 != NULL);
    assert(s2 != NULL);

    skipToLetter(&pos1);
    skipToLetter(&pos2);

    unsigned char c1 = *pos1, c2 = *pos2;
    do{
        c1 = *pos1, c2 = *pos2;

        if(c1 != c2)
            return c1 < c2;

        pos1++, pos2++;
    } while (*pos1 != '\0' || *pos2 != '\0');   //exits only if both are '\0'. '||' for firecase

    return 0;
}

//----------------------------------------------------------------------

void mergeTextSort(String *pBegin, String* pBuffBegin, size_t size, int (*comparator)(const void*, const void*)) {
    assert(pBegin != NULL);
    assert(comparator != NULL);
    assert(pBuffBegin);

    if(size <= 1)
        return;

    String* pMid = pBegin + size / 2;
    String* pBuffMid = pBuffBegin + size / 2;

    mergeTextSort(pBegin, pBuffBegin, size/2, comparator); // Recursive calling
    mergeTextSort(pMid, pBuffMid, size - size / 2, comparator);

    int left = 0, right = 0;

    for(int pos = 0; pos < size; ++pos){  // Merging
        if(pBegin + left == pMid){
            pBuffBegin[pos] = pMid[right++];
            continue;
        }
        if(pMid + right == pBegin + size){
            pBuffBegin[pos] = pBegin[left++];
            continue;
        }

        pBuffBegin[pos] = (comparator(&pBegin[left], &pMid[right]) ? pBegin[left++] : pMid[right++]);
    }
    for(int pos = 0; pos < size; ++pos){
        pBegin[pos] = pBuffBegin[pos];
    }
}

//-------------------------------------------------------------------------------------------------

int isLetter(char c){
    return isalpha(c) || (c >= '\300' && c <= '\337') || (c >= '\340' && c <= '\377'); // + Russian alphabet
}

//-------------------------------------------------------------------------------------------------------

void skipToLetter(char **string){
    assert(string != NULL);
    assert(*string != NULL);

    while(**string != '\0' && !isLetter(**string)) (*string)++;
}

//--------------------------------------------------------------------------------------------------

int isLessStrReverse(const void *p1, const void *p2){
    assert(p1 != NULL);
    assert(p2 != NULL);
    if(p1 == p2)
        return 0;

    String *s1 = (String *)p1, *s2 = (String *)p2;

    char *endStr1 = s1->pBegin + s1->size, *endStr2 = s2->pBegin + s2->size;

    skipToLetterReverse(&endStr1, s1->pBegin);
    skipToLetterReverse(&endStr2, s2->pBegin);

    unsigned char c1 = *endStr1, c2 = *endStr2;
    do{
        c1 = *endStr1, c2 = *endStr2;
        if(c1 != c2)
            return (int)c1 - (int)c2;
        endStr1--, endStr2--;
    } while (endStr1 != s1->pBegin || endStr2 != s2->pBegin);

    return 0;
}

//----------------------------------------------------------------------

void skipToLetterReverse(char **pChr, const char *beginOfStr){
    while (!isLetter(**pChr) && *pChr!=beginOfStr)
        (*pChr)--;
}
