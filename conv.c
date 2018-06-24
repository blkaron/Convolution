/************************************************************
 * Perform convolution of two signals (with lengths N and M)
 * and return the result as an N+M sequence
 * 
 * author: blkaron
 * e-mail: tekla.makkan@yahoo.co.uk
 ************************************************************/

#include "conv.h"

static void invert_signal(int *, int *, int *);
static void pad_signal(int *, int *, int, int);
static int cmp(const void *, const void *);


/************************
* Description: Classical convolution implementation
*
* Input:
* 	x - pointer to input signal array
* 	y - pointer to impulse response array of the system
* 	s - pointer to output signal array after convolution
* Output:
* 		pointer to memory holding the result from the convolution
*************************/

int * conv(int *x, int *y, size_t s_x, size_t s_y)
{
	int i,j,k;
	int *s;
	int *t;
	int *a;
	int *b;

	int retVal;
	int sizeS;
	int sizeN;
	int sizeM;

	if(NULL == x || NULL == y)
	{
		printf("Invalid pointer to array !\n");
	}

	retVal = 0;
	sizeS  = s_x + s_y;
	s = (int *)malloc(sizeS * sizeof(int));

	if (s_x >= s_y)
	{
		sizeN = s_x + 2*s_y - 2;
		sizeM = s_y;
		a = (int *)malloc(sizeN * sizeof(int));
		b = (int *)malloc(s_y * sizeof(int));
		t = y + s_y;
		invert_signal(y, t, b);
		pad_signal(x, a, s_y, s_x);

	}
	else
	{
		sizeN = s_y + 2*s_x - 2;
		sizeM = s_x;
		a = (int *)malloc(sizeN * sizeof(int));
		b = (int *)malloc(s_x * sizeof(int));
		t = x + s_x;
		invert_signal(x, t, b);
		pad_signal(y, a, s_x, s_y);
	}

	/* Perform convolution */
	for(j = 0; j < sizeS; j++)
	{
		for(i=j, k=0; i < (j + sizeM - 1) && k < sizeM; i++, k++)
		{
			retVal += *(a+i) * (*(b+k));
		}
		*(s+j) = retVal;
		retVal = 0;
	}

	/* Free no longer needed memory*/
	free(a);
	free(b);

	return s;
}

/************************
* Description: Display the signals and result
*
* Input:
* 	s    - pointer to first signal
* 	se   - pointer to second signal
* 	out  - pointer to output signal after convolution
* 	s_s  - size of s
* 	se_s - size of se
* 	out_s- size of out
* Output:
* 	None
*************************/
void print_conv(int *s, int *se, int *out, size_t s_s, size_t se_s, size_t out_s)
{
	//todo - implement
	;
}

/************************
* Description: Compare function
*
* Input:
* 	a   - const void pointer to first signal
* 	b   - const void pointer to second signal
* Output:
* 		- int
*************************/
static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

/************************
* Description: Invert the smaller signal
*
* Input:
* 	s - pointer to input signal
* 	se - pointer to end of input signal
* 	inv - pointer to inverted signal
* Output:
* 	None
*************************/
static void invert_signal(int *s, int *se, int *inv)
{
	while(se != s)
	{
		*inv++ = *--se;
	}
}

/************************
* Description: Pad the bigger signal with zeros
*
* Input:
* 	s   - pointer to original signal
* 	ns  - pointer to new signal
* 	s_m - smaller signal size
* 	s_b - bigger signal size
* Output:
* 	None
*************************/
static void pad_signal(int *s, int *ns, int s_m, int s_b)
{
	int i = 0;

	while(i != (s_b + 2*s_m - 2))
	{
		if(i < s_m - 1 || i >= (s_b + s_m - 1))
			*ns++ = 0;
		else
			*ns++ = *s++;
		i++;
	}
}

