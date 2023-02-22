/******************************
 * Author: Zachary R. Perales *
 ******************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

int comparator(const void* a, const void* b) {
    triangle tr_a = *((triangle*) a);
    triangle tr_b = *((triangle*) b);
    double p1 = (tr_a.a + tr_a.b + tr_a.c) / 2.0;
    double p2 = (tr_b.a + tr_b.b + tr_b.c) / 2.0;
    double a1 = sqrt(p1 * (p1 - tr_a.a) * (p1 - tr_a.b) * (p1 - tr_a.c));
    double a2 = sqrt(p2 * (p2 - tr_b.a) * (p2 - tr_b.b) * (p2 - tr_b.c));
    if (a1 > a2)
      return 1;
    else if (a1 < a2)
      return -1;
    else
      return 0;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    
    qsort(tr, n, sizeof(triangle), comparator);
}

int main()