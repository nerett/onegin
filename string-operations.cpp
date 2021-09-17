#include "string-operations.h"

int input_text( char** index_strings )
{
    char temp_buffer[MAX_STRING_LENGTH];
    FILE* input_file;

    input_file = fopen( "input_text.txt", "r" );

    void* error_indicator = NULL;
    int i = 0;
    for( i = 0; i < MAX_NUMBER_STRINGS; i++ )
    {
        error_indicator = fgets( temp_buffer, sizeof( temp_buffer ), input_file );

        //printf( "----------\n%d--------\n", error_indicator );
        if( error_indicator == NULL )
        {
            break;
        }
        //int current_string_length = strlen( temp_buffer ); //!TODO определение количества элементов строки, перевести на свои библиотеки

        index_strings[i] = strdup( temp_buffer );

        //index_strings[i] = ( char* ) calloc( current_string_length, sizeof( char ) );
        //*( index_strings[i] ) = temp_buffer;
    }

    return i;
}



int cmp_strings( char* first_string, char* second_string )
{
    return strcmp( first_string, second_string );
}



int change_strings( char** index_strings, int first_string, int second_string )
{
    char* temporary = index_strings[first_string];
    index_strings[first_string] = index_strings[second_string];
    index_strings[second_string] = temporary;

    return 0;
}



int sort_strings( char** index_strings, int N_strings )
{
    for( int sort_iterations = 0; sort_iterations < N_strings; sort_iterations++ )
    {
        for( int i = 0; i < N_strings - 1; i++ )
        {
            if( cmp_strings( index_strings[i], index_strings[i+1] ) > 0 )
            {
                change_strings( index_strings, i, i + 1 );
            }
        }
    }

    return 0;
}


/*
int qsort_strings( char** start_element, int length )
{
    char** base_element = start_element + ( length / 2 );
    char** left_element = start_element;
    char** right_element = start_element + length;

    while( left_element >= right_element )
    {
        for( int i = 0; i < ( length / 2 ); i++ )
        {
            if( cmp_strings( *left_element, *base_element ) > 0 ) //работа со значениями по адресу
            {
                break;
            }
            left_element++; //работа с адресами как с числами
        }

        for( int i = 0; i < ( length / 2 ); i++ )
        {
            if( cmp_strings( *right_element, *base_element ) <= 0 ) //работа со значениями по адресу
            {
                break;
            }
            right_element--; //работа с адресами как с числами
        }


        change_strings( left_element, 0, right_element - left_element );
    }

    if( base_element > start_element ) //работа с адресами как с числами
    {
        qsort_strings( start_element, base_element - start_element ); //работа с адресами как с числами
    }
    if( base_element < start_element + length ) //работа с адресами как с числами
    {
        qsort_strings( base_element, start_element + length - base_element ); //работа с адресами как с числами
    }


    return 0;
}
*/


int text_console_output( char** index_string, int N_strings )
{
    for( int i = 0; i < N_strings; i++ )
    {
        printf("%s", index_string[i] );
    }

    return 0;
}
