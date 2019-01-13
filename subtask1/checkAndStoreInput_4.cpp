#include<string>
#include<iostream>
#include "functions.h"
using namespace std;
//sigmoid_of_matrix vector.txt size
bool checkAndStoreInput_4(char* str[], int* sizeP, string* fileP, bool* isSigP)
{
	if((string)str[1] == "sigmoid_of_vector" or (string)str[1] == "softMax_of_vector")
	{
		if((string)str[1] != "sigmoid_of_vector")
			*isSigP = false;
		else
			*isSigP = true;

		*fileP = str[2];//will br chacked in some other function

		int tempInt;
		if(sscanf(str[3], "%d", &tempInt) == 0)
			return false;
		else
			*sizeP = tempInt;

		return true;
	}
	else
		return false;
}