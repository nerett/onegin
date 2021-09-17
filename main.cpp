#include "string-operations.h"

int main()
{

    char* index_string[MAX_NUMBER_STRINGS] = {}; //массив указателей на строки текста


    input_text( index_string ); //передача указателя на массив указателей
    sort_strings( index_string );

    text_console_output( index_string );

    return 0;
}
