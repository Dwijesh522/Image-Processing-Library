#include<string>
using namespace std;

void convolve_without_padding(int , float *, float *, float *, int );
void rotateMatrix(float *, int ); 
bool checkAndStoreInput(int, char* str[], int* sap, int* sfp, int* padValuep, bool*, bool *isPadp, string* file1p, string* file2p);
bool readInput_conv(float* , float* , int , int , string , string , int);
void printMatrix(float *, int , int );
void guideUser(void);
void conv_without_padding_mult(float* , float* , float *, int , int , int);
void multiplyMatrixVector(float*, float*, int , int , float*);
void fillTheDBTM(float*, int , int , int , float*, int , int );
void createTPaddedF(float*, int , int , float);
void contractTheSize(float*, int , int , int , float* );
void padMatrix(float*, float*, int, int);


bool readInput_relu_tanh(float*, int, int, string);
void relu_of_matrix(float*, int, int, float*);
void tanh_of_matrix(float*, int, int, float*);


void softMax(float* , float* , int );
void sigmoid(float* , float* , int );
bool checkAndStoreInput_4(char* str[], int* , string* , bool* );
bool readInput_sig_softMax(float* , string , int );


bool readInput_pooling(float* , int , string );