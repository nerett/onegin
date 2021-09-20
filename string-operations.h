#ifndef STRING-OPERATIONS_H_INCLUDED
#define STRING-OPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
//#include "string-utils/sring-operations.h"
//!TODO перевести программу на самописные функции (библиотека string-utils)

const int MAX_STRING_LENGTH = 100;
const int MAX_NUMBER_STRINGS = 6000; //! TODO сделать подсчёт примерной оценки исходя из длины строки

struct text
{
    char** index_string = NULL; //массив указателей на строки текста
    //int N_strings = MAX_NUMBER_STRINGS;
    char* text_line = NULL; //строка, содержащая весь текст
    int N_symbols = 0, N_strings = 0;
};

int input_text( struct text* some_text ); ///< Reads text from input_text.txt, divides it into several strings and put them into dynamically allocated memory.
int cmp_strings( char* first_string, char* second_string ); ///< Returns -1 if the second string is greater than first, 0 if they're equal and 1 if first string is greater
int change_strings( struct text* some_text, int first_string, int second_string ); ///< Swaps pointers to two input strings
int sort_strings( struct text* some_text ); ///< Choses string sorting algorithm
int back_sort_strings( struct text* some_text );
int qsort_strings( struct text* some_text, int start, int finish ); ///< Custom qsort algorithm for strings
int bubblesort_strings( struct text* some_text ); ///< Sorts the strings given with bubblesort algorithm
int text_console_output( struct text* some_text ); ///< Displays strings into the console
int text_file_output( struct text* some_text ); ///< Puts strings given into the output_text.txt
int free_memory( struct text* some_text ); ///< Frees heap memory occupied by strings
int find_first_letter( char* some_string ); ///< Returns the number of the first letter in the string
bool is_letter( char symbol ); ///< Returns true if this symbol is letter, false if it isn't
int count_strings( struct text* some_text );
int find_string_beginning( struct text* some_text );

int bubblesort_strings_back( struct text* some_text );
int cmp_strings_back( struct text* some_text, int str1_number, int str2_number );


#endif // STRING-OPERATIONS_H_INCLUDED
