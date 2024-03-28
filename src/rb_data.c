#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rb_data.h"

mydata *makedata(u64 cksum)
{
	mydata *p;

	p = (mydata *) malloc(sizeof(mydata));
	if (p != NULL)
		p->cksum = cksum;

	return p;
}

int compare_func(const void *d1, const void *d2)
{
	mydata *p1, *p2;
	
	assert(d1 != NULL);
	assert(d2 != NULL);
	
	p1 = (mydata *) d1;
	p2 = (mydata *) d2;
	
	if (p1->cksum == p2->cksum)
		return 0;
	else if (p1->cksum > p2->cksum)
		return 1;
	else
		return -1;
}

void destroy_func(void *d)
{
	mydata *p;
	
	assert(d != NULL);
	
	p = (mydata *) d;
	free(p);
}

void print_func(void *d)
{
	mydata *p;
	
	assert(d != NULL);
	
	p = (mydata *) d;
	printf("%d", p->cksum);
}

void print_cksum_func(void *d)
{
	mydata *p;
	
	assert(d != NULL);
	
	p = (mydata *) d;
	printf("%ll", p->cksum);
}