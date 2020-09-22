#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>
#include <stdio.h>
#include <windows.h>
using namespace std;
const int MAX = 12000;
int A[MAX][MAX], x[MAX], y[MAX];

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(){
	ofstream myfile ("salida12.txt");
	myfile<<MAX<<" ";
    for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			A[i][j]=0;
		}
		x[i]=0; y[i]=0;
	}
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	QueryPerformanceCounter(&t_ini);
	/**/
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			y[i] += A[i][j] * x[j];
		}
	}
	/**/
	QueryPerformanceCounter(&t_fin);
	secs=performancecounter_diff(&t_fin, &t_ini);
	myfile<<secs<<" ";
	//cout<<"Primer par de loops: "<<secs<<endl;
	
	LARGE_INTEGER t_ini1, t_fin1;
	double secs1;
	QueryPerformanceCounter(&t_ini1);
	/**/
	for(int j=0; j<MAX; j++){
		for(int i=0; i<MAX; i++){
			y[i] += A[i][j] * x[j];
		}
	}
	/**/
	QueryPerformanceCounter(&t_fin1);
	secs1=performancecounter_diff(&t_fin1, &t_ini1);
	myfile<<secs1<<"\n";
	//cout<<"Segundo par de loops: "<<secs1<<endl;
	myfile.close();
    return 0;
}
