#include<string>
#include<iostream>
#include "functions.h"
using namespace std;

bool checkAndStoreInput(int argc, char* str[], int* sap, int* sfp, int* padValuep, bool * withMult, bool *isRelup, string* file1p, string* file2p)
{	
	if(argc == 6 or argc == 7)
	{
		if((string)str[1] == "convolve_without_padding" or (string)str[1] == "conv_without_padding_mult")
		{
			if((string)str[1] == "convolve_without_padding")
				*withMult = false;
			else
				*withMult = true;

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
	}
	else if(argc == 5)
	{
		if((string)str[1] == "relu_of_matrix")
		{
			*isRelup = true;
			//relu_of_matrix inputMatrix.txt rows cols
			*file1p = str[2];

			int tempInt;
			if(sscanf(str[3], "%d", &tempInt) == 1)
				*sap = tempInt;
			else
				return false;

			if(sscanf(str[4], "%d", &tempInt) == 1)
				*sfp = tempInt;
			else
				return false;

			return true;
		}
		else if((string)str[1] == "tanh_of_matrix")
		{
			*isRelup = false;
			//tanh_of_matrix inputMatrix.txt rows cols
			*file1p = str[2];
			
			int tempInt;
			if(sscanf(str[3], "%d", &tempInt) == 1)
				*sap = tempInt;
			else
				return false;

			if(sscanf(str[4], "%d", &tempInt) == 1)
				*sfp = tempInt;
			else
				return false;

			return true;
		}
		else if((string)str[1] == "maxPooling_of_matrix" or (string)str[1] == "avgPooling_of_matrix")
		{
			//maxPooling_of_matrix matrix.txt size strideValue
			//sap === size of input matrix, file1p === matrixFile.txt  padValuep === stride value  isrelup === isMaxPooling
			if((string)str[1] == "maxPooling_of_matrix")
				*isRelup = true;
			else
				*isRelup = false;
			//tanh_of_matrix inputMatrix.txt rows cols
			*file1p = str[2];
			
			int tempInt;
			if(sscanf(str[3], "%d", &tempInt) == 1)
				*sap = tempInt;
			else
				return false;

			if(sscanf(str[4], "%d", &tempInt) == 1)
				*padValuep = tempInt;
			else
				return false;

			return true;
		}
		else 
			return false;
	}
	else
		return false;
}