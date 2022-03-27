#ifndef all_h
#define all_h



#include <stdio.h>
#include <stdlib.h>
#include "Header.h"



void* create();
void print(void*v, int type);
void *fill(void*v, int type);
void* sum(void*v1, void*v2, void*v3, int type);
void *scalprois(void*v1, void*v2,int type);
void test();
int test_scal(void*v1, void *v2, void*p, int k);
int test_sum(void*v1, void *v2, void *v3, int k);

#endif
