/*
 * Copyright (c) 2019 xieqing. https://github.com/xieqing
 * May be freely redistributed, but copyright notice must be retained.
 */
#include "types.h"



#ifndef _RB_DATA_HEADER
#define _RB_DATA_HEADER

typedef struct {
	u64 cksum;
} mydata;

mydata *makedata(u64 cksum);
int compare_func(const void *d1, const void *d2);
void destroy_func(void *d);
void print_func(void *d);
void print_cksum_func(void *d);

#endif /* _RB_DATA_HEADER */