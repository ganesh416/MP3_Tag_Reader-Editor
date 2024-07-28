#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>


void get_view_details(char file[]);
void edit_details(char *argv[]);
int normal_to_int(unsigned char bytes[4]);
int find_header(char title[]);

#endif
