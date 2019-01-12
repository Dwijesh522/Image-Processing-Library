#include<iostream>
using namespace std;
void contractTheSize(float* bigger, int sBigger, int x, int sc, float* c)
{
	for(int i=0; i< sc; i++)
		for(int j=0; j< sc; j++)
			*(c + i*sc + j) = *(bigger + sBigger*(x + i) + (x + j));
}