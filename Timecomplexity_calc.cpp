
//Program: to measure execution time of various time complexities like O(1), O(LogN), O(N), O(N^2) 

#include<iostream>
#include<iomanip>
#include <chrono> 
#include<string>
using namespace std;

void constantTimeComplexity()   //O(1)
{
	int a = 1;
}
void linearTimeComplexity()     //O(n)
{
	for (int i = 1; i < 10000; i++);
}

void quadraticTimeComplexity()   //O(n^2)
{
	for (int i = 1; i < 10000; i++)
	{
		for (int j = 1; j < 10000; j++);
	}
}

void logTimeComplexity()		//O(log n)
{
	for (int i = 1; i < 100000; i *= 2);
}

void print(double time, const string timecomplexity)
{

	time *= 1e-9;

	cout << "Time taken by" << timecomplexity << ":" << fixed << time << setprecision(9);
	cout << " sec" << endl;
}
int main()
{

	// ------------------------O(1) ------------------------------
	auto start = chrono::high_resolution_clock::now();

	constantTimeComplexity();

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	print(time_taken, " Constant TimeComplexity:");
	
	//------------------------ O(logN) ----------------------------

	start = chrono::high_resolution_clock::now();

	logTimeComplexity();

	end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	print(time_taken, " Log TimeComplexity:");

	//------------------------ O(N) ----------------------------

	start = chrono::high_resolution_clock::now();

	linearTimeComplexity();

	end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	 time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	
	print(time_taken, " Linear TimeComplexity:");

	//------------------------ O(N2) ----------------------------

	start = chrono::high_resolution_clock::now();

	quadraticTimeComplexity();

	end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	print(time_taken, " Quadratic TimeComplexity:");
	
	cin.ignore();
	cin.get();
	return 0;
}