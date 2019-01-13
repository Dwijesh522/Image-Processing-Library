#include<iostream>
#include "functions.h"
using namespace std; 

void guideUser()
{
	cout << "follow the syntex given below\n\n";
	cout << "convolve_without_padding matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
	cout << "convolve_with_padding padding_value matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
	cout << "conv_without_padding_mult matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
	cout << "conv_with_padding_mult padding_value matrix1.txt matrix1_no_rows matrx2.txt matrix2_no_rows\n\n";
	cout << "relu_of_matrix inputMatrix.txt rows cols\n\n";
	cout << "tanh_of_matrix inputMatrix.txt rows cols\n\n";
}