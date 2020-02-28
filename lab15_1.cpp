#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *data,int N,int M)
{
	for(int j =0;j < (M*N);j++)
	{
		double y = rand()%101;
		*(data+j) =  y/100;
	}
}

void findRowSum(const double *data,double *result,int N,int M)
{
	for(int i =0;i < N;i++)
	{
		*(result+i) = 0;
		for(int j = i*M;j < (i+1)*M;j++)
		{
			*(result+i) = *(result+i) + *(data+j) ;
		}
	}
}

void showData(double *data,int N,int M)
{
	for(int j =0;j < (M*N) ;j++)
	{
		if(j != 0 && j%M==0)cout << "\n";
		cout << setw(6) << *(data+j) ;
	}
	cout << "\n";
}
