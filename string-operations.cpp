#include "string-operations.h"

#define BUBBLESORT
//#define USER_QSORT
//#define DEFAULT_QSORT


int input_text( struct text* some_text ) // text *some_text
{
    FILE* input_file = fopen( "input_text.txt", "r" );

    //printf("11!\n");

    // проверка fopen

    fseek( input_file, 0L, SEEK_END ); //определение размера файла
    //проверка fseek
    some_text->N_symbols = ftell( input_file );
    //проверка ftell
    fseek( input_file, 0L, SEEK_SET );
    //проверка fseek

    //printf("12!\n");
                                                                                        //!TODO read func
    some_text->text_line = ( char* ) calloc( some_text->N_symbols, sizeof( char ) ); //выделение памяти и чтение из файла
    fread( some_text->text_line, sizeof( char ), some_text->N_symbols, input_file ); //fread!

    //printf("13!\n");

    printf("count_strings: %d\n", count_strings( some_text ));

    //printf("14!\n");

    some_text->index_string = ( char** ) calloc( some_text->N_strings, sizeof( char* ) ); //выделение памяти под массив указателей на начало строк и его заполнение

    //printf("15!\n");

    assert( some_text->index_string != NULL );

    //! DEBUG:

for( int k = 0; k < some_text->N_symbols; k++ )
{
    if( some_text->text_line[k] == '\n' )
    {
            some_text->text_line[k] = '\0';
    }
}

    find_string_beginning( some_text );

    //printf("16!\n");

/*
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
*/

    return 0;
}



int cmp_strings( char* first_string, char* second_string )
{
    assert( first_string != NULL );
    assert( second_string != NULL );
/*
    int result = strcmp( first_string, second_string );

    if( result > 0 )
    {
        return 1;
    }
    else if( result < 0 )
    {
        return -1;
    }
*/
    //int length_1 = strlen( first_string );
    //int length_2 = strlen( second_string );
    //int cmp_iterations = 0;
    int first_startfrom = 0, second_startfrom = 0;
    int i;

    first_startfrom = find_first_letter( first_string );
    second_startfrom = find_first_letter( second_string );
/*
if( first_startfrom != 0 )
printf( "first====%d\n", first_startfrom );

if( second_startfrom != 0 )
printf( "second====%d\n", second_startfrom );
*/
    i = 0;
    while( first_string[i] != '\n' || second_string[i] != '\n' ) //собственно сравниваем
    {
        if( first_string[first_startfrom + i] < second_string[second_startfrom + i] )
        {
//printf( "=============%c\n", first_string[first_startfrom + i] );
            return -1;
        }
        else if( first_string[first_startfrom + i] > second_string[second_startfrom + i] )
        {
            return 1;
        }
        i++;
    }

    return 0;
}



int change_strings( struct text* some_text, int first_string, int second_string )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );

    assert( isfinite( first_string ) );
    assert( isfinite( second_string ) );


    char* temporary = some_text->index_string[first_string];
    some_text->index_string[first_string] = some_text->index_string[second_string];
    some_text->index_string[second_string] = temporary;

    return 0;
}



int sort_strings( struct text* some_text, bool enable_reverse )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );

    #ifdef DEFAULT_QSORT

        if( enable_reverse )
        {
            qsort( some_text->index_string, some_text->N_strings, sizeof( some_text->text_line ), ( __compar_fn_t )cmp_strings_back );
        }
        else
        {
            qsort( some_text->index_string, some_text->N_strings, sizeof( some_text->text_line ), ( __compar_fn_t )cmp_strings );
        }

    #endif
    #ifdef USER_QSORT

        if( enable_reverse )
        {

        }
        else
        {

        }

    #endif
    #ifdef BUBBLESORT

        if( enable_reverse )
        {
            bubblesort_strings_back( some_text );
        }
        else
        {
            bubblesort_strings( some_text );
        }

    #endif
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
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );


    for( int i = 0; i < some_text->N_strings; i++ )
    {
        printf("%s", some_text->index_string[i] );
    }

    return 0;
}



int text_file_output( struct text* some_text, bool enable_loseless_adding )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );


    FILE* output_file;
    if( enable_loseless_adding )
    {
        output_file = fopen( "output_text.txt", "a" );
    }
    else
    {
        output_file = fopen( "output_text.txt", "w" );
    }
    //output_file = fopen( "output_text.txt", "w" );

    for( int i = 0; i < some_text->N_strings; i++ )
    {
        fputs( some_text->index_string[i], output_file );
        fputs( "\n", output_file );
    }

    fclose( output_file ); ///TODO убрать
    return 0;
}



int free_memory( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );

    free( some_text->index_string );
    free( some_text->text_line );

//    fclose( output_file );

    return 0;
}



int bubblesort_strings( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );


    int sort_step = 1; //изначально единица отнималась от длины сама, это просто оптимизация, так надо
    for( int sort_iterations = 0; sort_iterations <= some_text->N_strings; sort_iterations++ ) //повторить некое число раз
    {
        for( int i = 0; i < some_text->N_strings - sort_step; i++ ) //пробежаться по массиву и сравнить строки
        {
            if( cmp_strings( some_text->index_string[i], some_text->index_string[i+1] ) > 0 )
            {
                change_strings( some_text, i, i + 1 );
            }
        }

        printf( "sort_iterations = %d/%d\n", sort_iterations, some_text->N_strings );
        sort_step++;
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
    //assert( isfinite( symbol ) );


    if( symbol == '"' || symbol == '(' || symbol == ')' || symbol == ' ' || symbol == '.' || symbol == ',' || symbol == '-' )
    {
        return false;
    }
    else
    {
        return true;
    }
}



int count_strings( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->N_symbols > 0 );


    for( int i = 0; i < some_text->N_symbols; i++ )
    {
        if( some_text->text_line[i] == '\n' ) //а если '\0' ну или выделять памяти на одну строку больше
        {
            some_text->N_strings++;
        }
    }

    return some_text->N_strings;
}



int find_string_beginning( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );

    //isfinite убрать

    // желательно заменить \n на \0 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //some_text->index_string[0] = &(some_text->text_line[0]);
    char last_read = '\n';

//printf("151!\n");

    int j = 0;

    for( int i = 0; i < some_text->N_symbols; i++ ) //начинать с нуля
    {
        //printf("! i = %d ", i);printf("1!\n");
        if( last_read == '\n' || last_read == '\0' )
        {
            printf("! %d !\n", i);

            //some_text->text_line[i-1] = '\0'; //замена на слеш-нули!

            some_text->index_string[j] = some_text->text_line + i;
            j++;
        }

        //printf("%c\n", some_text->text_line[i]);
        last_read = some_text->text_line[i];
    }


/// DEBUG
/*
    for (j = 0; j < some_text->N_strings; j++)
    {
        printf("%d\n", some_text->index_string[j]);
    }
*/

    return 0;
}



int bubblesort_strings_back( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );


    int sort_step = 1; //изначально единица отнималась от длины сама, это просто оптимизация, так надо
    for( int sort_iterations = 0; sort_iterations <= some_text->N_strings; sort_iterations++ ) //повторить некое число раз
    {
        for( int i = 0; i < some_text->N_strings - sort_step; i++ ) //пробежаться по массиву и сравнить строки
        {
            if( cmp_strings_back( some_text->index_string[i], some_text->index_string[i+1] ) > 0 )
            {
                change_strings( some_text, i, i + 1 );
            }
        }

        printf( "sort_iterations = %d/%d\n", sort_iterations, some_text->N_strings );
        sort_step++;
    }

    return 0;
}



int cmp_strings_back( char* first_string, char* second_string )
{
    assert( first_string != NULL );
    assert( second_string != NULL );

    int i1 = strlen( first_string );
    //printf( "i1======%d\n", i1 );
    int i2 = strlen( second_string );
    while( first_string[i1] != '\n' || second_string[i2] != '\n' || first_string[i1] != '\0' || second_string[i2] != '\0' ) //собственно сравниваем
    {
        if( first_string[i1] < second_string[i2] )
        {
            return -1;
        }
        else if( first_string[i1] > second_string[i2] )
        {
            return 1;
        }
        i1--;
        i2--;
    }
    return 0;
}



int text_file_add_delimiter()
{
    FILE* output_file;
    output_file = fopen( "output_text.txt", "a" );

    fputs( "\n", output_file );
    fputs( "================================", output_file );
    fputs( "СЛЕДУЮЩАЯ ЧАСТЬ ЗАДАНИЯ", output_file );
    fputs( "================================", output_file );
    fputs( "\n", output_file );

    fclose( output_file ); ///TODO убрать

    return 0;
}



int text_file_file_plain_output( struct text* some_text, bool enable_loseless_adding )
{
    FILE* output_file;
    if( enable_loseless_adding )
    {
        output_file = fopen( "output_text.txt", "a" );
    }
    else
    {
        output_file = fopen( "output_text.txt", "w" );
    }

    //fputs( some_text->text_line, output_file);

    for( int i = 0; i < some_text->N_symbols; i++ )
    {
        if( some_text->text_line[i] == '\0' )
        {
            fputs( "\n", output_file);
            continue;
        }
        fputc( some_text->text_line[i], output_file );

        //fputs( "\n", output_file);
    }

    fclose( output_file );

    return 0;
}



