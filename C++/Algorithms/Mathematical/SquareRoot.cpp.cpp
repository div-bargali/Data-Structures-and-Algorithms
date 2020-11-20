#include <iostream>
using namespace std;


//These 2 functions will accept user input and return the resulting Square Root of that user input


//Iterative Function
double sqrtIterative(double x) {
	double sqrt = x * pow(0.3, log10(x));
	for (int i = 0; i < 5; i++)
		sqrt = (sqrt + (x / sqrt)) * 0.5;
	return sqrt;
}


//Recursive function
double sqrtRecursive(double num, double prev)
{
	double next = (prev + num / prev) / 2;
	if (fabs(next - prev) < DBL_EPSILON * next)
		return next;
	return sqrtRecursive(num, next);
}

int main(void) {



	//Iterative Function

	cout << "Iterative Function" << endl;
	cout << "Please enter a number" << endl;
	double iFn;
	cin >> iFn;
	double answerIterative = sqrtIterative(iFn);
	cout << answerIterative << endl;


	//Recursive Function
	cout << "Recursive Function" << endl;
	cout << "Please enter 2 numbers, the first will be the square root number" << endl;
	double rFp;
	double rFn;
	cin >> rFn;
	cin >> rFp;
	double answerRecursion = sqrtRecursive(rFn, rFp);
	cout << answerRecursion << endl;


}