/*! \mainpage Onegin
 *
 * This project was created during MIPT Ded's course.
 * It reads some text from the input_text.txt, sorts it on lexicographic principles and
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

int main()
{
    struct text onegin;
    TryToExecute(
        input_text( &onegin ),
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
