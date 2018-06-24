/************************************************************
 * Perform convolution of two signals (with lengths N and M)
 * and return the result as an N+M sequence
 * 
 * author: blkaron
 * e-mail: tekla.makkan@yahoo.co.uk
 ************************************************************/

#ifndef CONV_H_
#define CONV_H_

#include <stdio.h>
#include <stdlib.h>

extern int * conv(int *, int *, size_t, size_t);
extern void print_conv(int *, int *, int *,size_t, size_t, size_t);

#endif /* CONV_H_ */
