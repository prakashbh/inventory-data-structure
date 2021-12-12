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
#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

// Including all the required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>


// Variable to hold the inventory data containing the
// keywords and properties
char ***inventory;


// Variable to capture the time details
time_t mytime;


// Keeps a log of activity. Any errors can be checked in this file
FILE *flog;


// Function Declarations
int load();
int dump();
void open_log();
int inventory_memory_allocation();
void close_log();
void write_log(char * , char *, char *);
int file_empty_check(char *);
int load();
int inventory_memory_allocation();
int add_key();
char ** string_array_memory_allocation(int);
char ** get_keys();
char ** get_properties();
char ** get_key_properties(int);
char * get_key_name(int);
char * get_property_name(int);
int * search_key(char array[]);
int * search_property(char property[]);
void search_any(char c_array[], int i_array[100][2]);
void print();
void print_formatted();
void inventory_memory_deallocation();
int dump();

#endif // INVENTORY_H_INCLUDED
