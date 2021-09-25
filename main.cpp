/*! \mainpage Onegin
 *
 * This project was created during MIPT Ded's course.
 * It reads some text from the file given (command line <FILENAME> as an argument or input_text.txt by default), sorts it on lexicographic principles and
 * puts the result into output_text.txt.
 * In theory, this program can work with arbitrary-sized text and strings. Cyrillic symbols
 * are also supported.
 * The code structure is pseudo object oriented and divided into many functions.
 *
 * by nerett
 * (c) 2021
 */


#include "string-operations.h"
#include "string-sort.h"

int main( int N_arguments, char** arguments )
{
    char* filename = NULL;
    if( N_arguments >= MIN_ARGUMENTS_NUMBER )
    {
        filename = arguments[1];
    }


    struct text onegin;
    TryToExecute(
        input_text( &onegin, filename ),
            &onegin );

    sort_strings( &onegin, false );

    TryToExecute(
        text_file_output( &onegin, false ),
            &onegin );
    TryToExecute(
        text_file_add_delimiter(),
            &onegin );

    sort_strings( &onegin, true );

    TryToExecute(
        text_file_output( &onegin, true ),
            &onegin );
    TryToExecute(
        text_file_add_delimiter(),
            &onegin );
    TryToExecute(
        text_file_file_plain_output( &onegin, true ),
            &onegin );


    free_memory( &onegin );
    return 0;
}
