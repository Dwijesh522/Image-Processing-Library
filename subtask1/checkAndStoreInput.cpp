#include<string>
#include<iostream>
#include "functions.h"
using namespace std;

bool checkAndStoreInput(char* str[], int* sap, int* sfp, int* padValuep, bool * withMult, bool *isPadp, string* file1p, string* file2p)
{	
	if((string)str[1] == "convolve_without_padding" or (string)str[1] == "conv_without_padding_mult")
	{
		if((string)str[1] == "convolve_without_padding")
			*withMult = false;
		else
			*withMult = true;
		*isPadp = false;
		*file1p = str[2];//will br chacked in some other function

		int tempInt;
		if(sscanf(str[3], "%d", &tempInt) == 0)
			return false;
		else
			*sap = tempInt;

		*file2p = str[4];

		if(sscanf(str[5], "%d", &tempInt) == 0)
			return false;
		else
			*sfp = tempInt;

		return true;
	}
	else if( (string)str[1] == "convolve_with_padding" or (string)str[1] == "conv_with_padding_mult")
	{
		*isPadp = true;
		if((string)str[1] == "convolve_with_padding")
			*withMult = false;
		else
			*withMult = true;
		
		int tempInt;
		if(sscanf(str[2], "%d", &tempInt) == 0)
			return false;
		else
			*padValuep = tempInt;

		*file1p = str[3];//will br chacked in some other function

		if(sscanf(str[4], "%d", &tempInt) == 0)
			return false;
		else
			*sap = tempInt;

		*file2p = str[5];

		if(sscanf(str[6], "%d", &tempInt) == 0)
			return false;
		else
			*sfp = tempInt;

		return true;
	}
	else
		return false;
}