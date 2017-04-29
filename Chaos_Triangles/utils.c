#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int max_2(int a ,int b ) {
    if (a > b) {
        return a ;
    }
    return b ;
}
int min_2(int a ,int b ) {
    if (a < b) {
        return a ;
    }
    return b ;
}
int min3(int a,int b,int c) {
    if (a < b) {
        if (a < c) {
            return a ;
        }
        if (a > c) {
            return c ;
        }
    }
    else
        if (b > c) {
            return c ;
        }
        else
            return b ;
}
int rand_int(int min,int max)
{
    int r;
    const int range = 1 + max - min;
    const int buckets = RAND_MAX / range;
    const  int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}
