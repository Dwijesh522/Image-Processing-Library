#include<iostream>
#include "functions.h"
#include<fstream>

using namespace std;

bool readInput_relu_tanh(float* a, int rows, int cols, string file1)
{
	fstream myfile;	
	myfile.open(file1);

	if(myfile.is_open())
	{
		int i=0, j=0;
		string currStr="";
		char * currStrPointer = &currStr[0];
		while(getline(myfile, currStr) and j < cols)
		{
			sscanf(currStrPointer, "%f", (a + i*cols + j));
			if(i <= rows-2)
				i++;
			else
			{
				i=0;
				j++;
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