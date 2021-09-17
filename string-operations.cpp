#include "string-operations.h"

int input_text( char** index_strings )
{
    char temp_buffer[MAX_STRING_LENGTH];
    FILE* input_file;

    input_file = fopen( "input_text.txt", "r" );

    int i;
    for( i = 0; i < MAX_NUMBER_STRINGS; i++ )
    {
        fgets( temp_buffer, sizeof( temp_buffer ), input_file );
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



int sort_strings( char** index_strings )
{
    for( int sort_iterations = 0; sort_iterations < MAX_NUMBER_STRINGS; sort_iterations++ )
    {
        for( int i = 0; i < MAX_NUMBER_STRINGS - 1; i++ )
        {
            if( cmp_strings( index_strings[i], index_strings[i+1] ) > 0 )
            {
                change_strings( index_strings, i, i + 1 );
            }
        }
    }

    return 0;
}

