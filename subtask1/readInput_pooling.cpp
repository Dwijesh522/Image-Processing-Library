#include<iostream>
#include "functions.h"
#include<fstream>

using namespace std;

bool readInput_pooling(float* A, int sa, string file1)
{
	int currSize;
	fstream myfile;

	currSize = sa;
	myfile.open(file1);

	if(myfile.is_open())
	{
		int i=0, j=0;
		string currStr="";
		char * currStrPointer = &currStr[0];
		while(getline(myfile, currStr) and i < currSize)
		{
			sscanf(currStrPointer, "%f", (A + j*currSize + i));
			if(j <= currSize-2)
				j++;
			else
			{
				j=0;
				i++;
			}
		}
	}
	else
	{
		cout << "File name is incorrect, can not open the file\n";
		return false;
	}
	myfile.close();
	return true;
}