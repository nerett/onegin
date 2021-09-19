#include "string-operations.h"

int main()
{
    struct text onegin;
    printf("1!\n");
    input_text( &onegin );

    printf("2!\n");
    sort_strings( &onegin );
    //qsort_strings( &onegin, 0, onegin.N_strings );

    //text_console_output( &onegin );
    text_file_output( &onegin );

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //free_memory( &onegin );

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
