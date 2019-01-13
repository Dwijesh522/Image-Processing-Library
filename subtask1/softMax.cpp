#include<cmath>
#include<iostream>
using namespace std;

void softMax(float* inputVec, float* ansVec, int size)
{
	float deleteThisVariable = 0;
	float sum = 0;
	for(int i=0; i<size; i++)
		sum += exp(*(inputVec + i));

	for(int i=0; i<size; i++)
	{
		*(ansVec + i) = (exp(*(inputVec + i)))/sum;
		deleteThisVariable += *(ansVec + i);
	}

}