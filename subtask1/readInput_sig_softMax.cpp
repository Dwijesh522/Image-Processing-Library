#include<iostream>
#include<fstream>
using namespace std;
bool readInput_sig_softMax(float* A, string file, int sizeOfVector)
{
	fstream myFile;
	myFile.open(file);
	if(myFile.is_open())
	{
		int i=0;
		string currStr="";
		char * currStrPointer = &currStr[0];
		while(getline(myFile, currStr) and i < sizeOfVector)
		{
			sscanf(currStrPointer, "%f", (A + i));
			i++;
		}
		return true;
	}
	else
	{
		cout << "File name is incorrect, can not open the file\n";
		return false;
	}
}