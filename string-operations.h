#ifndef STRING-OPERATIONS_H_INCLUDED
#define STRING-OPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
//#include "string-utils/sring-operations.h"

const int MAX_STRING_LENGTH = 100;
const int MAX_NUMBER_STRINGS = 100;


int input_text( char** index_strings );
int cmp_strings( char* first_string, char* second_string ); //-1 при 1<2, 0 при 1=2, 1 при 1>2
int change_strings( char** index_strings, int first_string, int second_string );
int sort_strings( char** index_strings );


#endif // STRING-OPERATIONS_H_INCLUDED
