#include "string-operations.h"

int main()
{

    char* index_string[MAX_NUMBER_STRINGS] = {}; //массив указателей на строки текста

    input_text( index_string ); //передача указателя на массив указателей

    sort_strings( index_string );

    //change_strings( index_string, 0, 1 );


    printf( "\n-------------------------------------------------------------------------------\nRESULT:\n" );
    for( int i = 0; i < MAX_NUMBER_STRINGS; i++ )
    {
        printf("%s\n", index_string[i] );
    }

/*
    char s1[] = "абв";
    char s2[] = "аба";
    int bolian = strcmp( s1, s2 );
    printf( "%d", bolian );
*/
    return 0;
}
