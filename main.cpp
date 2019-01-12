#include<iostream> 
#include<string>
#include<fstream>
using namespace std;
#include "functions.h"
int main(int argc, char *argv[])
{
	int sa, sf, padValue = 0, ansMatSize;
	bool isPad;
	string file1, file2;
	//check and store input parameters
	if(argc == 7 or argc ==6)
	{
		if(checkAndStoreInput(argv, &sa, &sf, &padValue, &isPad, &file1, &file2) == false)
		{
			guideUser();
			return 0;
		}
	}
	else
	{
		guideUser();
		return 0;
	}

	float inputM[sa][sa], filterM[sf][sf];
	float ansM_without_padding[sa-sf+1][sa-sf+1], ansM_with_padding[sa + 2*padValue - sf + 1][sa + 2*padValue - sf + 1];
	float *a = inputM[0], *f = filterM[0], *c = ansM_without_padding[0], *cp = ansM_with_padding[0];    
	//read inputs matrices from file
	if(readInput(a, f, sa, sf, file1, file2, padValue) == false)
		return 0;
	//rotate and convolve
	if(padValue == 0)
	{
		if(sa >= sf)
		{
			ansMatSize = sa - sf + 1;
			rotateMatrix(f, sf);
			convolve_without_padding(sa, a, c, f, sf);
		}
		else
		{
			ansMatSize = sf - sa + 1;
			rotateMatrix(f, sa);
			convolve_without_padding(sf, a, c, f, sa);
		}
	}
	//print a matrix
	printMatrix(c, ansMatSize, ansMatSize);
	return 0;
}