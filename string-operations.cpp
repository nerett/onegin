#include "string-operations.h"

#define BUBBLESORT
//#define USER_QSORT
//#define DEFAULT_QSORT

//#define AAAAA

int input_text( struct text* some_text )
{
    char temp_buffer[MAX_STRING_LENGTH];
    FILE* input_file;

    input_file = fopen( "input_text.txt", "r" );

    void* error_indicator = NULL;
    int i = 0;
    for( i = 0; i < MAX_NUMBER_STRINGS; i++ )
    {
        error_indicator = fgets( temp_buffer, sizeof( temp_buffer ), input_file );
        if( error_indicator == NULL )
        {
            break;
        }
        //int current_string_length = strlen( temp_buffer ); //!TODO определение количества элементов строки, перевести на свои библиотеки

        some_text->index_string[i] = strdup( temp_buffer );

        //index_strings[i] = ( char* ) calloc( current_string_length, sizeof( char ) );
        //*( index_strings[i] ) = temp_buffer;
    }

    fclose( input_file );

    some_text->N_strings = i;
    return i;
}



int cmp_strings( char* first_string, char* second_string )
{
#ifdef AAAAA
    int result = strcmp( first_string, second_string );

    if( result > 0 )
    {
        return 1;
    }
    else if( result < 0 )
    {
        return -1;
    }
#endif
#ifndef AAAAA
    //int length_1 = strlen( first_string );
    //int length_2 = strlen( second_string );
    //int cmp_iterations = 0;
    int first_startfrom = 0, second_startfrom = 0;
    int i;

    first_startfrom = find_first_letter( first_string );
    second_startfrom = find_first_letter( second_string );

    i = 0;
    while( first_string[i] != '\n' || second_string[i] != '\n' ) //собственно сравниваем
    {
        if( first_string[first_startfrom + i] < second_string[second_startfrom + i] )
        {
            return -1;
        }
        else if( first_string[first_startfrom + i] > second_string[second_startfrom + i] )
        {
            return 1;
        }
        i++;
//printf( "=============\n=============\n=============\n=============\n=============\n=============\n=============\n=============\n=============\n=============\n" );
    }

//printf( "returned 0\n" );
#endif
    return 0;
}



int change_strings( struct text* some_text, int first_string, int second_string )
{
    char* temporary = some_text->index_string[first_string];
    some_text->index_string[first_string] = some_text->index_string[second_string];
    some_text->index_string[second_string] = temporary;

    return 0;
}



int sort_strings( struct text* some_text )
{
    #ifdef DEFAULT_QSORT



    #endif
    #ifdef USER_QSORT



    #endif
    #ifdef BUBBLESORT

        bubblesort_strings( some_text );

    #endif
    return 0;
}



int back_sort_strings( struct text* some_text )
{

    return 0;
}


/*
int qsort_strings( struct text* some_text, const int start, const int finish )
{
    //char** base_element = some_text->index_string + start + ( finish / 2 );
    //char** left_element = some_text->index_string + start;
    //char** right_element = some_text->index_string + start + finish;

    int base_element = start + ( finish / 2 );
    int left_element = start;
    int right_element = finish;

    while( left_element >= right_element )
    {
        for( int i = 0; i < ( ( finish - start ) / 2 ); i++ )
        {
            if( cmp_strings( &*some_text->index_string[left_element], &*some_text->index_string[base_element] ) > 0 ) //работа со значениями по адресу
            {
                break;
            }
            left_element++; //работа с адресами как с числами
        }

        for( int i = 0; i < ( ( finish - start ) / 2 ); i++ )
        {
            if( cmp_strings( &*some_text->index_string[right_element], &*some_text->index_string[base_element] ) <= 0 ) //работа со значениями по адресу
            {
                break;
            }
            right_element--; //работа с адресами как с числами
        }


        change_strings( some_text, left_element, right_element );
    }

    if( base_element > start ) //работа с адресами как с числами
    {
        qsort_strings( some_text, start, base_element ); //работа с адресами как с числами
    }
    if( base_element < finish ) //работа с адресами как с числами
    {
        qsort_strings( some_text, base_element, finish ); //работа с адресами как с числами
    }


    return 0;
}
*/


int text_console_output( struct text* some_text )
{
    for( int i = 0; i < some_text->N_strings; i++ )
    {
        printf("%s", some_text->index_string[i] );
    }

    return 0;
}



int text_file_output( struct text* some_text )
{
    FILE* output_file;
    output_file = fopen( "output_text.txt", "w" );

    for( int i = 0; i < some_text->N_strings; i++ )
    {
        fputs( some_text->index_string[i], output_file );
    }

    fclose( output_file );

    return 0;
}



int free_memory( struct text* some_text )
{
    for( int i = 0; i < some_text->N_strings; i++ )
    {
        free( some_text->index_string[i] );
    }

    return 0;
}



int bubblesort_strings( struct text* some_text )
{
/*
    int increment = 1;
    int startfrom = 0;

    if( back_sort )
    {
        increment = -1;
    }
*/

    for( int sort_iterations = 0; sort_iterations < some_text->N_strings; sort_iterations++ )
    {
        for( int i = 0; i < some_text->N_strings - 1; i++ )
        {
            if( cmp_strings( some_text->index_string[i], some_text->index_string[i+1] ) > 0 )
            {
                change_strings( some_text, i, i + 1 );
            }
        }
printf( "sort_iterations=%d\n", sort_iterations );
    }

    return 0;
}



int find_first_letter( char* some_string )
{
    assert( some_string != NULL );

    int first_letter = 0;
    int i = 0;
    while( some_string[i] != '\n' ) //ищем первую букву первой строки
    {
        if( is_letter( some_string[i] ) )
        {
            first_letter = i;
            break;
        }
        i++;
    }
    i = 0;
    return first_letter;
}



bool is_letter( char symbol )
{
    if( symbol == '"' || symbol == '(' || symbol == ')' || symbol == ' ' || symbol == '.' || symbol == ',' || symbol == '-' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
