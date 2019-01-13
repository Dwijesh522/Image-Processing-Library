#include<iostream> 
#include<string>
#include<fstream>
using namespace std;
#include "functions.h"
int main(int argc, char *argv[])
{
	if(argc == 5 or argc == 6 or argc == 7)
	{
		int sa=0, sf=0, padValue = 0, ansMatSize=0;			//sa and sf becomes rows and cols interchangably
		bool isRelu = false, withMult = false;
		string file1 = "", file2 = "";
		//check and store input parameters
		if(checkAndStoreInput(argc, argv, &sa, &sf, &padValue, &withMult, &isRelu, &file1, &file2) == false)
		{
			guideUser();
			return 0;
		}

		//ansM_without_padding is a global answer, ans ans_without_padding_mult is an intermidiate
		float inputM[sa][sa], filterM[sf][sf], inputMP[sa + 2*padValue][sa + 2*padValue];
		float ansM_without_padding[sa-sf+1][sa-sf+1], ansM_with_padding[sa + 2*padValue - sf + 1][sa + 2*padValue - sf + 1];
		float ansM_without_padding_mult[sa+sf-1][sa+sf-1], ansM_with_padding_mult[sa + 2*padValue + sf - 1][sa + 2*padValue + sf - 1];
		float *a = inputM[0], *ap = inputMP[0], *f = filterM[0], *c = ansM_without_padding[0], *cp = ansM_with_padding[0];
		float *cm = ansM_without_padding_mult[0], *cpm = ansM_with_padding_mult[0];
		//read inputs matrices from file
		if((string)argv[1] == "convolve_without_padding" or (string)argv[1] == "convolve_with_padding" or (string)argv[1] == "conv_without_padding_mult" or (string)argv[1] == "conv_with_padding_mult")		
		{
			if(readInput_conv(a, f, sa, sf, file1, file2, padValue) == false)
				return 0;
		}
		else if( (string)argv[1] == "relu_of_matrix" or (string)argv[1] == "tanh_of_matrix")
		{
			if(readInput_relu_tanh(a, sa, sf, file1) == false)
				return 0;
		}
		else if((string)argv[1] == "maxPooling_of_matrix" or (string)argv[1] == "avgPooling_of_matrix")
		{
			if(readInput_pooling(a, sa, file1) == false)
				return 0;
		}


		if((string)argv[1] == "convolve_without_padding" or (string)argv[1] == "convolve_with_padding" or (string)argv[1] == "conv_without_padding_mult" or (string)argv[1] == "conv_with_padding_mult")
		{
			if(padValue != 0)
			{
				padMatrix(a, ap, sa, padValue);
				sa += 2*padValue;
			}
			//rotate and convolve
			// if(padValue == 0)
			// {
			if(!withMult)
			{
				ansMatSize = sa - sf + 1;
				rotateMatrix(f, sf);

				if(padValue == 0)
				{
					convolve_without_padding(sa, a, c, f, sf);
					printMatrix(c, ansMatSize, ansMatSize);
				}
				else
				{
					convolve_without_padding(sa, ap, cp, f, sf);
					printMatrix(cp, ansMatSize, ansMatSize);	
				}
			}
			else
			{
				if(padValue == 0)
				{
					ansMatSize = sa-sf+1;
					conv_without_padding_mult(a, f, cm, sa, sf, sa+sf-1);
					contractTheSize(cm, sa+sf-1, sf-1, sa-sf+1, c);
					//reduce the size********************************************************************************************************
					printMatrix(c, ansMatSize, ansMatSize);
				}
				else
				{
					ansMatSize = sa-sf+1;
					conv_without_padding_mult(ap, f, cpm, sa, sf, sa+sf-1);
					contractTheSize(cpm, sa+sf-1, sf-1, sa-sf+1, cp);
					//reduce the size********************************************************************************************************
					printMatrix(cp, ansMatSize, ansMatSize);	
				}	
			}
			// }
			// else
		}
		else if((string)argv[1] == "relu_of_matrix" or (string)argv[1] == "tanh_of_matrix")
		{
			if(isRelu)
			{
				relu_of_matrix(a, sa, sf, c);
				printMatrix(c, sa, sf);
			}
			else
			{
				tanh_of_matrix(a, sa, sf, c);
				printMatrix(c, sa, sf);
			}
		}
		else if((string)argv[1] == "maxPooling_of_matrix" or (string)argv[1] == "avgPooling_of_matrix")
		{
			if(isRelu)//  isRelu === maxPooling
			{
				printMatrix(a, sa, sa);
				cout << padValue << endl;
			}
			else
			{
				printMatrix(a, sa, sa);
				cout << padValue << endl;
			}
		}
		return 0;
	}
	else if(argc == 4)
	{
		int sizeOfVector = 0;
		bool isSig = false;
		string file;

		if(checkAndStoreInput_4(argv, &sizeOfVector, &file, &isSig) == false)
		{
			guideUser();
			return 0;
		}
		float inputVec[sizeOfVector], ansVec[sizeOfVector];

		if(readInput_sig_softMax(&inputVec[0], file, sizeOfVector) == false)
			return 0;
		if(isSig)
			sigmoid(inputVec, ansVec, sizeOfVector);
		else
			softMax(inputVec, ansVec, sizeOfVector);
		printMatrix(ansVec, sizeOfVector, 1);
		return 0;
	}
	else
	{
		guideUser();
		return 0;
	}
}