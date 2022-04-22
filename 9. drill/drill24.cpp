#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try {

	cout << "sizeof:\n";
	cout << "char\t" << sizeof(char) << '\n';
	cout << "shor\t" << sizeof(short) << '\n';
	cout << "int\t" << sizeof(int) << '\n';
	cout << "long\t" << sizeof(long) << '\n';
	cout << "float\t" << sizeof(float) << '\n';
	cout << "double\t" << sizeof(double) << '\n';
	cout << "inr*\t" << sizeof(int*) << '\n';
	cout << "double*\t" << sizeof(double*) << '\n';


	cout << "Matrix:" << '\n';



	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	cout << "1D int 10 \t" << sizeof(a) << endl;
	cout << "1D int 10 \t" << sizeof(b) << endl;
	cout << "1D double 10 \t" << sizeof(c) << endl;
	cout << "2D int 10x10 \t" << sizeof(d) << endl;
	cout << "3D int 10x10x10 \t" << sizeof(e) << endl;



	cout << "numb 1D int 10 \t" << a.size() << endl;
	cout << "numb 1D int 10 \t" << b.size() << endl;
	cout << "numb 1D double 10 \t" << c.size() << endl;
	cout << "numb 2D int 10x10 \t" << d.size() << endl;
	cout << "numb 3D int 10x10x10 \t" << e.size() << endl;

	

	for (int i = 7; i > 3; i++)
	{

		int n;
		cout << "n: ";
		cin >> n;

		if (n < 0)
		{
			cout << "Negatív n" << '\n';

		} else if(n == 0){
			cout << "sqrt(n): " << sqrt(n) << endl;
			i = 0;

		}else{
			cout << "sqrt(n): " << sqrt(n) << endl;	
		}

		
	}

	cin.ignore();

	cout << "Enter 10 floats!" << endl;

	Matrix<double> m2(10);

	double k;

	for (int i = 0; i < m2.size(); ++i)
	{
		cin >> k;
		if(!cin) throw runtime_error("Cin problen");
		m2[i] = k;
	}

	cout << "Matrix:\n" << m2 << endl;


	int x;
	int y;

	cout << "n: ";
	cin >> x;
	cout << "m: ";
	cin >> y;

	Matrix<int, 2> m3(x, y);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			m3(i, j) = (i+1)*(j+1);
		}
	}

	for (int i = 0; i < x; ++i)
	{
		cout << endl;

		for (int j = 0; j < y; ++j)
		{
			cout << m3(i, j) << '\t';
		}
	}

	cout << endl;	



// setw)(szam)


	Matrix<complex <double>> mcomp(10);

	cout << "10 comp numb (re, im):" << endl;
	complex<double> comp;
	complex<double> sumcomp;

	for (int i = 0; i < mcomp.size(); ++i)
	{
		cin >> comp;
		mcomp[i] = comp;
		sumcomp = sumcomp + comp;
	}

	cout << "Sum: " << sumcomp << endl;;




	Matrix<int,2> m4(2,3);

	int intm4;


	cout << '\n';
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			cout << "[" << i+1 << ", " << j+1 << "]: ";
			cin >> intm4;
			m4(i, j) = intm4;
		}
	}


	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			cout <<m4(i, j) << '\t';
		}
		cout << '\n';
	}


}
catch(exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Unknown exception\n";
	return 2;
}