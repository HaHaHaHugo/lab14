#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);
void findLocalMax(const double [][N], bool [][N]);
void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double inp[][N])
{
	for(int i=0; i<N; i++)
	{
		cout <<"Row "<< i+1 <<": ";
		for(int j=0; j<N; j++)
		{
	        cin >> inp[i][j];
		}
	}
}

void findLocalMax(const double inp[][N], bool outp[][N])
{
	int ti=0, tj=0, uti=0, dti=0, ltj=0, rtj=0;
    for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			ti = i;
			tj = j;
			uti = ti-1;
			dti = ti+1;
			rtj = tj+1;
			ltj = tj-1;
			outp[ti][tj] = 0;
			if(inp[ti][tj]>=inp[uti][tj]&&inp[ti][tj]>=inp[dti][tj]&&inp[ti][tj]>=inp[ti][rtj]&&inp[ti][tj]>=inp[ti][ltj]) outp[i][j] = 1;
			if(ti==0 || tj==0 || ti==N-1 || tj==N-1) outp[i][j] = 0;
		}
	}
}

void showMatrix(const bool outp[][N])
{
    for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << outp[i][j] <<" ";
		}
		cout << "\n";
	}
}