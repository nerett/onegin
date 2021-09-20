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

int main()
{
    struct text onegin;
    input_text( &onegin );

    //bubblesort_strings_back( &onegin );

    sort_strings( &onegin, false );
    //qsort_strings( &onegin, 0, onegin.N_strings );

    text_file_add_delimiter();
    //text_console_output( &onegin );
    text_file_output( &onegin, false );

    text_file_add_delimiter();

    sort_strings( &onegin, true );
    text_file_output( &onegin, true );

    text_file_add_delimiter();

    text_file_file_plain_output( &onegin, true );

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    free_memory( &onegin );

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
