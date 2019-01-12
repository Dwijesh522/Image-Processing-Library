#include "functions.h"
#include<iostream>

using namespace std;  

void convolve_without_padding(int sa, float *a, float *c, float *f, int sf)
{
	// assuming matrx f is rotated 180 degree
	//a, f, c are pointing to 2d matrices
	int ansSize = sa - sf + 1;
	for(int i=0; i<= sa - sf; i++)
	{
		for(int j=0; j<= sa - sf; j++)
		{
			*(c + i*ansSize + j) = 0;
			for(int p=0; p< sf; p++)
			{
				for(int q=0; q< sf; q++)
				{
					*(c + i*ansSize + j) += (*(f + p*sf + q)) * (*(a + (i+p)*sa + (j+q)));
				}
			}
		}
	}
}
