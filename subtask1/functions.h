#include<string>
using namespace std;
void convolve_without_padding(int , float *, float *, float *, int );
void rotateMatrix(float *, int ); 
bool checkAndStoreInput(char* str[], int* sap, int* sfp, int* padValuep, bool *isPadp, string* file1p, string* file2p);
bool readInput(float* , float* , int , int , string , string , int );
void printMatrix(float *, int , int );
void guideUser(void);