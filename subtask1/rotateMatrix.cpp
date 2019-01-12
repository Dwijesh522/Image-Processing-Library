#include "functions.h"
#include<iostream>
using namespace std;    

void rotateMatrix(float *a, int size)
{
	int i1 = 0, j1 = 0, i2 = size - 1, j2 = size - 1;
	for(; i1< size; i1++, i2--)
	{
		for(j1 = 0, j2 = size - 1; not(i1==i2 and j1 >= j2) and j1<size and not(i1 > i2); j1++, j2--)
		{
			float temp = *(a + size*i1 + j1);
			*(a + size*i1 + j1) = *(a + size*i2 + j2);
			*(a + size*i2 + j2) = temp;
		}
		if((i1==i2 and j1 >= j2) or (i1 > i2))
			break;
	}
}