#include<iostream>
#include "functions.h"
using namespace std; 

void guideUser()
{
	cout << "follow the syntex given below\n\n";
	cout << "convolve_without_padding matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
	cout << "or\n\n";
	cout << "convolve_with_padding padding_value matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
}