#ifndef STRING-OPERATIONS_H_INCLUDED
#define STRING-OPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
//#include "string-utils/sring-operations.h"
//!TODO перевести программу на самописные функции (библиотека string-utils)

const int MAX_STRING_LENGTH = 100;
const int MAX_NUMBER_STRINGS = 6000; //! TODO сделать подсчёт примерной оценки исходя из длины строки

struct text
{
    char* index_string[MAX_NUMBER_STRINGS] = {}; //массив указателей на строки текста
    int N_strings = MAX_NUMBER_STRINGS;
};

int input_text( struct text* some_text );
int cmp_strings( char* first_string, char* second_string ); //-1 при 1<2, 0 при 1=2, 1 при 1>2
int change_strings( char** index_strings, int first_string, int second_string );
int sort_strings( struct text* some_text );
int qsort_strings( struct text* some_text );
int text_console_output( struct text* some_text );


#endif // STRING-OPERATIONS_H_INCLUDED
