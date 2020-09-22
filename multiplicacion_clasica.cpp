#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <stdio.h>
#include <windows.h>
using namespace std;
const int MAX = 1200;
int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(){
	ofstream myfile ("salida_e2_12.txt");
	myfile<<MAX<<" ";
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			A[i][j]=1;
			B[i][j]=1;
			C[i][j]=1;
		}
	}

	LARGE_INTEGER t_ini, t_fin;
	double secs;
	QueryPerformanceCounter(&t_ini);

	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			for(int k=0; k<MAX;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}

	QueryPerformanceCounter(&t_fin);
	secs=performancecounter_diff(&t_fin, &t_ini);
	myfile<<secs<<"\n";
	myfile.close();
	//cout<<"Tiempo tomado: "<<secs<<endl;
    
	/*for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			cout<<C[i][j]<<endl;
		}
	}*/
    return 0;
}