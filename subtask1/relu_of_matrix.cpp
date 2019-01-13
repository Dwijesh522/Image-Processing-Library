void relu_of_matrix(float* inputMat, int rows, int cols, float* reluMat)
{
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			if(*(inputMat + i*cols + j) >=0)
				*(reluMat + i*cols + j) = *(inputMat + i*cols + j);
			else
				*(reluMat + i*cols + j) = 0;
}