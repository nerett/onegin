#ifndef STRING-OPERATIONS_H_INCLUDED
#define STRING-OPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
//#include "string-utils/string-utils.h"
//!TODO перевести программу на самописные функции (библиотека string-utils)

// FOPEN_ERR
enum err_code { OK, FOPEN_ERR, FSEEK_ERR, FTELL_ERR, FREAD_ERR, CALLOC_ERR }; ///< Enum of error codes, returned by functions below
//enum sort_algo { QSORT_DEFAULT, QSORT_CUSTOM, BUBBLESORT };

//const int MAX_STRING_LENGTH = 100;
const char NOT_A_LETTER[] = ".,-!?\"( )':;";

struct text ///< Structture which is text you can easilly work with
{
    char** index_string = NULL; ///< Array pf pointers that point at the strings beginnings // struct string { char * data, int size}
    char* text_line = NULL; ///< Line holding all text // buffer
    int N_symbols = 0; ///< Number of symbols in the text
    int N_strings = 0; ///< Number of strings in the text
};

err_code input_text( struct text* some_text ); ///< Reads text from input_text.txt, determines it's size, allocates memory, puts text into text_line and puts pointers from index_stringto the beginnings of lines (with a help of find_strings_beginnings). Returns error code
err_code text_file_output( struct text* some_text, bool enable_loseless_adding ); ///< Puts strings given into the output_text.txt
err_code text_file_add_delimiter(); ///< Ads awesome text label into the output_text.txt. Returns error code
err_code text_file_file_plain_output( struct text* some_text, bool enable_loseless_adding ); ///< Puts the contents of the text_line into the output_text.txt (usually text_line contains non-modified text red from file). Returns error code
int text_console_output( struct text* some_text ); ///< Displays strings into the console

static int count_strings( struct text* some_text ); ///< Counts number of strings in the text and result into N_strings
static int find_string_beginning( struct text* some_text ); ///< Puts pointers from index_stringto the beginnings of lines

int cmp_strings( const void* string_1_ptr, const void* string_2_ptr ); ///< Returns -1 if the second string is greater than first, 0 if they're equal and 1 if first string is greater
int cmp_strings_back( const void* string_1_ptr, const void* string_2_ptr ); ///< This function is like cmp_strings, but compares strings from their end (soon it'll be overwritten and merged with cmp_strings)

int sort_strings( struct text* some_text, bool enable_reverse ); ///< Choses string sorting algorithm and sorting mode (reverse or not)
int change_strings( struct text* some_text, int first_string, int second_string ); ///< Swaps pointers to two input strings

static int qsort_strings( struct text* some_text, int start, int finish ); ///< Custom qsort algorithm for strings (that doesn't work yet)
static int bubblesort_strings( struct text* some_text ); ///< Sorts the strings given with bubblesort algorithm
static int bubblesort_strings_back( struct text* some_text ); ///< This function is like bubblesort_strings, but it uses cmp_strings_back (soon it'll be overwritten and merged with bubblesort_strings)

int find_first_letter( char* some_string, bool find_from_end ); ///< Returns the number of the first letter in the string
bool is_letter( char symbol ); ///< Returns true if this symbol is letter, false if it isn't

void TryToExecute( err_code func_return_code, text* operand_to_free_mem );
int free_memory( struct text* some_text ); ///< Frees all heap memory occupied by text

#endif // STRING-OPERATIONS_H_INCLUDED
