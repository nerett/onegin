#include "string-operations.h"

int main()
{
    struct text onegin;
    input_text( &onegin );

    //char* index_string[MAX_NUMBER_STRINGS] = {}; //массив указателей на строки текста


    //int N_strings = input_text( index_string ); //передача указателя на массив указателей
    sort_strings( &onegin );
    //qsort_strings( &onegin, 0, onegin.N_strings );

    text_console_output( &onegin );

    //!TODO add free()
    return 0;
}
