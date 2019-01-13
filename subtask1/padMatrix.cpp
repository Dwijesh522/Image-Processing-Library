void padMatrix(float* processThis, float* saveInThis, int rc, int padValue)
{
	int ansSize = rc + 2*padValue;
	for(int i=0; i< ansSize; i++)
	{
		for(int j=0; j< ansSize; j++)
		{
			if(i >=padValue and i <= padValue+rc-1 and j >=padValue and j <= padValue+rc-1)
				*(saveInThis + i*(ansSize) + j) = *(processThis + rc*(i- padValue) + (j- padValue));
			else
				*(saveInThis + i*(ansSize) + j) = 0;
		}
	}
}