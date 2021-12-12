#include "inventory.c"
#include "locals.h"

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
                    // a function print_formatted() can be called to print formatted table
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
