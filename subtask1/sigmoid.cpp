#include<cmath>

using namespace std;

void sigmoid(float* inputVec, float* ansVec, int size)
{
	for(int i=0; i< size; i++)
		*(ansVec + i) = 1/(1+exp((-1)*(*(inputVec + i))));
}