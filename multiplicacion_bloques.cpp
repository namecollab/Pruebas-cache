#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <stdio.h>
#include <windows.h>
using namespace std;
const int MAX = 1200;
double A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int b=MAX/2;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(){
	ofstream myfile ("salida_e3.txt");
	myfile<<MAX<<" ";
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			A[i][j]=0;
			B[i][j]=0;
			C[i][j]=0;
		}
	}

	LARGE_INTEGER t_ini, t_fin;
	double secs;
	QueryPerformanceCounter(&t_ini);

	for(int i=0; i<MAX; i+=b){
		for(int j=0; j<MAX; j+=b){
			for(int k=0; k<MAX; k+=b){
				for(int i1=i; i1<i+b; i1++){
					for(int j1=j; j1<j+b; j1++){
						for(int k1=k; k1<k+b; k1++){
							C[i1][j1]=C[i1][j1]+A[i1][k1]*B[k1][j1];
						}
					}							
				}
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