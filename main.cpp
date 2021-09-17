#include "string-operations.h"

int main()
{
    struct text onegin;
    onegin.N_strings = input_text( onegin.index_string );

    char* index_string[MAX_NUMBER_STRINGS] = {}; //массив указателей на строки текста


    int N_strings = input_text( index_string ); //передача указателя на массив указателей
    sort_strings( index_string, N_strings );
    //qsort_strings( index_string, MAX_NUMBER_STRINGS );

    text_console_output( index_string, N_strings );

    //!TODO add free()
    return 0;
}
