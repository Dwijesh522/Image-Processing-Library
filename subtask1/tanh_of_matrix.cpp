#include<cmath>
void tanh_of_matrix(float* inputMat, int rows, int cols, float* tanhMat)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			int x = *(inputMat + i*cols + j);
			*(tanhMat + cols*i + j) = (exp(2*x) - 1)/(exp(2*x) + 1);
		}
	}
}