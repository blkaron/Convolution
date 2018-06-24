/************************************************************
 * Test convolution
 * 
 * author: blkaron
 * e-mail: tekla.makkan@yahoo.co.uk
 ************************************************************/

#include "conv.h"

int main()
{
	int i;
	int *s;
	int size_x;
	int size_y;

	int x[] = {1, 2, 3, 4, 10, 22, 8, 5, 9};
	size_x = sizeof(x)/sizeof(x[0]);
	int y[] = {0, 1, 2,};
	size_y = sizeof(y)/sizeof(y[0]);


	s = conv(x,y,size_x, size_y);

	for(i=0; i < size_x + size_y; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	print_conv(x, y, s, size_x, size_y, size_x+size_y);
	return 1;
}
