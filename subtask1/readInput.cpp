#include<iostream>
#include "functions.h"
#include<fstream>

using namespace std;

bool readInput_conv(float* a, float* f, int sizeA, int sizeF, string file1, string file2, int padValue)
{
	int maxDigitElements = 10;

	int currSize;
	fstream myfile;
	
	if(sizeA >= sizeF)
	{
		currSize = sizeA;
		myfile.open(file1);
	}
	else
	{
		currSize = sizeF;
		myfile.open(file2);
	}
	if(myfile.is_open())
	{
		int i=0, j=0;
		string currStr="";
		char * currStrPointer = &currStr[0];
		while(getline(myfile, currStr) and i < currSize)
		{
			sscanf(currStrPointer, "%f", (a + j*currSize + i));
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


	if(sizeA >= sizeF)
	{
		currSize = sizeF;
		myfile.open(file2);
	}
	else
	{
		currSize = sizeA;
		myfile.open(file1);
	}
	if(myfile.is_open())
	{
		int i=0, j=0;
		string currStr = "";
		char * currStrPointer = &currStr[0];
		while(getline(myfile, currStr) and i < currSize)
		{
			sscanf(currStrPointer, "%f", (f + j*currSize + i));
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