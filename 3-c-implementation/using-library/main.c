/**************************************************************************************************
Copyright (c) 2016 Prakash B Hegade, Vishwanath A Telsang

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sub-license, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

***************************************************************************************************/

#include<inventory.h>
#include<stdlib.h>
#include<stdio.h>


// This is a local variable file
// Following variables can be used in the main program

// Variable for take choice input from the user
// Can be used for:
//  -- switch cases
//  -- menu options
//  -- Any other scenario where user is prompted for a choice to input
int choice = 0;


// The return status of success or failure of any function can be
// captured in status variable
int status = 0;


// string_array is a variable to capture the string variables
// Memory for this has to be allocated as per need based on
// the number of strings to be loaded.
char ** string_array;

// The tindex variable can be used as a index in loops
// It stands for temporary index
int tindex = 0;

// The variable index_number is used to refer to any index
// value for Key or property
// It is a integer value referring to index of any array
int index_number = 0;


// The variable string_value can be used to hold a string
// The maximum value set is 25 and can be changed as per need
char string_value[25];


// The variable count is used to hold the counters
int count = 0;


// Pointer to hold the single index [x,y] of the table
int *sindex;


// Use the search_index variable to hold the search results
// It carries the indexes of the results in the inventory table
// The index search_index[0][0] holds the count of number of search results.
// If the value search_index[0][0] == -1, then no results were found.
int search_index[100][2];

void menu()
{
    printf("----------------------------------\n");
    printf("\n\t\tMENU\n");
    printf("----------------------------------\n");
    printf("0-exit\n");
    printf("1-Print Table\n");
    printf("2-Get All Keys\n");
    printf("3-Get All Specs\n");
    printf("4-Get Properties for Key\n");
    printf("5-Get Specific Key\n");
    printf("6-Get Specific Property\n");
    printf("7-Search for a Key\n");
    printf("8-Search for a Property\n");
    printf("9-Search for Any\n");
    printf("10-Add a New Key\n");
    printf("--------------------------------\n");
}

int main()
{
    status = load();
    if(status != 1){
        printf("Load Failed\n");
        return 0;
    }

    while(1)
    {
        menu();
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0: printf("Data dumped to file\n");
                    status = dump();
                    if(status != 1)
                        printf("Dump Failed\n. Please see the tempfile.txt\n");
                    return 0;


            case 1: print();
                    break;

            case 2: string_array = get_keys();
                    for (tindex = 0; tindex <= key_count; tindex++)
                        printf("%s\n", string_array[tindex]);
                    free(string_array);
                    break;

            case 3: string_array = get_properties();
                    for (tindex = 0; tindex <= property_count; tindex++)
                        printf("%s\n", string_array[tindex]);
                    free(string_array);
                    break;

            case 4: printf("Enter index number of key\n");
                    scanf("%d", &index_number);
                    string_array = get_key_properties(index_number);
                    if(string_array == NULL)
                    printf("Invalid input or Failure\n");
                    else {
                        for (tindex = 0; tindex <= property_count; tindex++)
                            printf("%s\n", string_array[tindex]);
                        free(string_array);
                    }
                    break;

            case 5: printf("Enter index number. There are %d keywords\n", key_count);
                    scanf("%d", &index_number);
                    printf("The returned keyword is %s\n", get_key_name(index_number));
                    break;

            case 6: printf("Enter index number.There are %d specs\n", property_count);
                    scanf("%d", &index_number);
                    printf("The returned spec is %s\n", get_property_name(index_number));
                    break;

            case 7: printf("\nEnter the key to be searched\n");
                    scanf("%s", string_value);

                    sindex = search_key(string_value);
                    if(sindex == NULL)
                        printf("Key NOT found\n");
                    else
                        printf("Key found at [%d %d]\n", sindex[0], sindex[1]);
                    break;

            case 8: printf("\nEnter the spec to be searched\n");
                    scanf("%s", string_value);

                    sindex = search_property(string_value);
                    if(sindex == NULL)
                        printf("Spec NOT found\n");
                    else
                        printf("Spec found at [%d %d]\n", sindex[0], sindex[1]);
                    break;

            case 9: printf("\nEnter any word to be searched\n");
                    scanf("%s", string_value);
                    search_any(string_value, search_index);

                    if(search_index[0][0] == -1)
                        printf("No Occurrences found\n");
                    else {
                        count = search_index[0][0];
                        for (tindex = 1; tindex<= count; tindex++)
                            printf("Occurrence found at [%d %d]\n", search_index[tindex][0], search_index[tindex][1]);
                    }
                    break;

            case 10: add_key();
                     break;


        }

    }
}
