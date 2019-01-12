#include<iostream>
using namespace std;

void printMatrix(float *p, int rows, int cols)
{
	for(int i=0; i<rows ; i++)
	{
		for(int j=0; j<cols; j++)
			cout << *(p + i*cols + j) << " ";
		cout << endl;
	}
}