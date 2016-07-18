#ifndef LOCALS_H_INCLUDED
#define LOCALS_H_INCLUDED

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


#endif // LOCALS_H_INCLUDED
