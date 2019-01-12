#include<iostream>
using namespace std;

void createTPaddedF(float* A, int row, int col, float ref[])
{
	//Hi
	//initialising and extending the A matrix
	for(int i=0; i< row; i++)
	{
		*(A + i*col) = ref[i];
		int p = i, q = 0;
		while(p < row and q < col)
		{
			*(A + p*col + q) = ref[i];
			q++;
			p++;
		}
	}
	for(int j = 1; j< col; j++)
	{
		*(A + j) = 0;
		int p = 0, q = j;
		while(p < row and q < col)
		{
			*(A + p*col + q) = 0;
			p++;
			q++;
		}
	}
}

void fillTheDBTM(float* fillThisMat, int c1, int coorI, int coorJ, float* useThisMat, int rows2, int cols2)
{
	for(int i=0; i<rows2; i++)
		for(int j=0; j<cols2; j++)
			*(fillThisMat + c1*(coorI + i) + (coorJ + j)) = *(useThisMat + cols2*i + j);
}

void multiplyMatrixVector(float* ans, float* a, int r, int c, float* b)
{
	//a == r*c and b = c*1 and ans == r*1
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			*(ans + i) += (*(a + i*c + j))*(*(b + j));
}

void conv_without_padding_mult(float* a, float* f, float *c, int sa, int sf, int sc)
{

	//padding f matrix
	float paddedF[sc][sc];
	for(int i=0; i< sc; i++)
	{
		for(int j=0; j< sc; j++)
		{
			if(i<sf and j<sf)
				paddedF[i][j] = *(f + i*sf + j);
			else
				paddedF[i][j] = 0;
		}
	}

	//creating doubly blocked toeplitz matrix from paddedF
	float doublyBlockedTPaddedFIntermidiate[sc][sc][sa];
	for(int i=0; i<sc; i++)
		createTPaddedF(doublyBlockedTPaddedFIntermidiate[i][0], sc, sa, paddedF[i]);

	float doublyBlockedToeplitzMatrix[sc*sc][sa*sa];
	int firstIndex = 0;
	for(int i=0; i<sc*sc; i = i + sc)
	{
		int counter = firstIndex;
		for(int j=0; j < sa*sa; j = j + sa)
		{
			fillTheDBTM(doublyBlockedToeplitzMatrix[0], sa*sa, i, j, doublyBlockedTPaddedFIntermidiate[counter][0], sc, sa);
			if(counter == 0)
				counter = sc-1;
			else 
				counter--;
		}
		firstIndex++;
	}


	//creating f vector
	int counter = 0;
	float vectorA[sa*sa];
	for(int i=0; i<sa; i++)
		for(int j=0; j<sa; j++, counter++)
			vectorA[counter] = *(a + sa*i + j);

	// matrix multiplication
	float ansVector[sc*sc];
	for(int i=0; i<sc*sc; i++)
		ansVector[i] = 0;
	multiplyMatrixVector(ansVector, doublyBlockedToeplitzMatrix[0], sc*sc, sa*sa, vectorA);
	
	for(int i=0; i<sc; i++)
		for(int j=0; j<sc; j++)
			*(c + i*sc + j) = ansVector[j + i*sc];
}