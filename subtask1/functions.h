#include<string>
using namespace std;
void convolve_without_padding(int , float *, float *, float *, int );
void rotateMatrix(float *, int ); 
bool checkAndStoreInput(char* str[], int* sap, int* sfp, int* padValuep, bool*, bool *isPadp, string* file1p, string* file2p);
bool readInput(float* , float* , int , int , string , string , int );
void printMatrix(float *, int , int );
void guideUser(void);
void conv_without_padding_mult(float* , float* , float *, int , int , int);
void multiplyMatrixVector(float*, float*, int , int , float*);
void fillTheDBTM(float*, int , int , int , float*, int , int );
void createTPaddedF(float*, int , int , float);
void contractTheSize(float*, int , int , int , float* );