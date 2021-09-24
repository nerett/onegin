#include "string-operations.h"

//#define BUBBLESORT
//#define USER_QSORT
#define DEFAULT_QSORT


err_code input_text( struct text* some_text ) // text *some_text
{
    int error_int = 0;  // ret  / retval / res
    void* error_ptr = NULL;


    FILE* input_file = fopen( "input_text.txt", "r" ); // argc argv
    if (input_file == NULL) // I LIKE IT BETTER
    {
        return FOPEN_ERR;
    }

    error_int = fseek( input_file, 0L, SEEK_END ); //определение размера файла
    if( error_int != 0 )
    {
        return FSEEK_ERR;
    }

    some_text->N_symbols = ftell( input_file );
    if( some_text->N_symbols < 0 )
    {
        return FTELL_ERR;
    }

    error_int = fseek( input_file, 0L, SEEK_SET );
    if( error_int != 0 )
    {
        return FSEEK_ERR;
    }

                                                                                        //!TODO read func
    some_text->text_line = ( char* ) calloc( some_text->N_symbols, sizeof( char ) ); //выделение памяти и чтение из файла
    error_int = fread( some_text->text_line, sizeof( char ), some_text->N_symbols, input_file );
    if( error_int != some_text->N_symbols )
    {
        return FREAD_ERR;
    }

    count_strings( some_text );

    some_text->index_string = ( char** ) calloc( some_text->N_strings, sizeof( char* ) ); //выделение памяти под массив указателей на начало строк
    if( some_text->index_string == NULL )
    {
        return CALLOC_ERR;
    }

    find_string_beginning( some_text );


    return OK;
}



int cmp_strings( const void* string_1_ptr, const void* string_2_ptr )
{
    assert( string_1_ptr != NULL );
    assert( string_2_ptr != NULL );


    char* first_string = *( char** )string_1_ptr;
    char* second_string = *( char** )string_2_ptr;

/*
    int result = strcmp( first_string, second_string ); // это быстрее за счёт strcmp!

    if( result > 0 )
    {
        return 1;
    }
    else if( result < 0 )
    {
        return -1;
    }
*/

    int first_startfrom = 0, second_startfrom = 0;
    int i;

    first_startfrom = find_first_letter( first_string, false );
    second_startfrom = find_first_letter( second_string, false );

    i = 0;
    while( first_string[i] != '\n' || second_string[i] != '\0' ) //собственно сравниваем // \0
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
            qsort( some_text->index_string, some_text->N_strings, sizeof( char* ), cmp_strings_back );
        }
        else
        {
            qsort( some_text->index_string, some_text->N_strings, sizeof( some_text->text_line ), cmp_strings );
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




int qsort_strings( struct text* some_text, const int start, const int finish ) //DOESN'T WORK!!
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



err_code text_file_output( struct text* some_text, bool enable_loseless_adding )
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
    if( output_file == NULL )
    {
        return FOPEN_ERR;
    }

    for( int i = 0; i < some_text->N_strings; i++ )
    {
        fputs( some_text->index_string[i], output_file );
        fputs( "\n", output_file );
    }

    fclose( output_file );
    return OK;
}



int free_memory( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );

    free( some_text->index_string );
    free( some_text->text_line );

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



int find_first_letter( char* some_string, bool find_from_end )
{
    assert( some_string != NULL );


    int i = 0;
    int increment = 1;
    int first_letter = 0;

    if( find_from_end )
    {
        i = strlen( some_string );
//i = string_utils_strlen( some_string );
//printf( "i= %d string= %s\n", i, some_string );
        increment = -1;
//first_letter = -1; ///DEBUG
    }

    while( some_string[i] != '\0' ) //ищем первую букву первой строки
    {
        if( is_letter( some_string[i] ) )
        {
            //first_letter = i;
            break;
        }
        i += increment;
        first_letter += increment;
    }

//printf( "%s ", some_string );
//printf( "%d\n", first_letter );
    return first_letter;
}



bool is_letter( char symbol )
{
    int i = 0;
    while( NOT_A_LETTER[i] != '\0' )
    {
        if( symbol == NOT_A_LETTER[i] )
        {
            return false;
        }
        i++;
    }

    return true;
}



int count_strings( struct text* some_text )
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->N_symbols > 0 );


    for( int i = 0; i < some_text->N_symbols; i++ ) // strchr
    {
        if( some_text->text_line[i] == '\n' ) //а если '\0' ну или выделять памяти на одну строку больше
        {
            some_text->N_strings++;
            some_text->text_line[i] = '\0';
        }
    }

    return some_text->N_strings;
}



int find_string_beginning( struct text* some_text ) // init_strings
{
    assert( some_text != NULL );
    assert( some_text->text_line != NULL );
    assert( some_text->index_string != NULL );
    assert( some_text->N_strings > 0 );
    assert( some_text->N_symbols > 0 );


    //some_text->index_string[0] = &(some_text->text_line[0]);
    char last_read = '\n';

    int j = 0;

    for( int i = 0; i < some_text->N_symbols; i++ ) //начинать с нуля
    {
        //printf("! i = %d ", i);printf("1!\n");
        if( last_read == '\n' || last_read == '\0' )
        {
//printf("! %d !\n", i);

            //some_text->text_line[i-1] = '\0'; //замена на слеш-нули!

            some_text->index_string[j] = some_text->text_line + i;
            j++;
        }
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



int cmp_strings_back( const void* string_1_ptr, const void* string_2_ptr )
{
    assert( string_1_ptr != NULL );
    assert( string_2_ptr != NULL );


    char* first_string = *( char** )string_1_ptr;
    char* second_string = *( char** )string_2_ptr;
/*
if(  find_first_letter( first_string, true ) != 0 )
{
    printf( "%d ", find_first_letter( first_string, true ) );
}
*/
    int i1 = strlen( first_string ) + find_first_letter( first_string, true );
    int i2 = strlen( second_string ) + find_first_letter( second_string, true );
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



err_code text_file_add_delimiter()
{
    FILE* output_file = fopen( "output_text.txt", "a" );
    if( output_file == NULL )
    {
        return FOPEN_ERR;
    }

    fputs( "\n", output_file );
    fputs( "================================", output_file );
    fputs( "СЛЕДУЮЩАЯ ЧАСТЬ ЗАДАНИЯ", output_file );
    fputs( "================================", output_file );
    fputs( "\n", output_file );

    fclose( output_file );

    return OK;
}



err_code text_file_file_plain_output( struct text* some_text, bool enable_loseless_adding )
{
    FILE* output_file;
    if( enable_loseless_adding )
    {
        output_file = fopen( "output_text.txt", "a" );
        if( output_file == NULL )
        {
            return FOPEN_ERR;
        }
    }
    else
    {
        output_file = fopen( "output_text.txt", "w" );
        if( output_file == NULL )
        {
            return FOPEN_ERR;
        }
    }


    for( int i = 0; i < some_text->N_symbols; i++ )
    {
        if( some_text->text_line[i] == '\0' )
        {
            fputs( "\n", output_file);
            continue;
        }
        fputc( some_text->text_line[i], output_file );
    }

    fclose( output_file );

    return OK;
}



void TryToExecute( err_code func_return_code, text* operand_to_free_mem )
{
    if( func_return_code != OK )
    {
        printf( "ERROR %d\n", func_return_code );
        printf( "You can find more information about error codes in enum err_code documentation.\n\n" );
        free_memory( operand_to_free_mem );

        abort();
    }
}



