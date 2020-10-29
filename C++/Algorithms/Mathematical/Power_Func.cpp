#include <iostream>
using namespace std;


//These 2 functions will accept user input and return the resulting power of that user input


//Iterative Function
double powerIterative(double base, unsigned int n) {
	double power = 1.0;

	for (int i = 1; i <= n; i++) //For loop
	{
		power = power * base;
	}

	return (power);
}


//Recursive function
double powerRecursive(double base, unsigned int n) {
	

	if (n != 0)
		return (base * powerRecursive(base, n - 1)); //Function calling itself
	else
		return 1; //base function
	
}

int main(void){

	
	
	//Iterative Function

	cout << "Iterative Function" << endl;
	cout << "Please enter a number" << endl;
	double iF;
	cin >> iF;
	double answerIterative = powerIterative(2, iF);
	cout << answerIterative << endl;
	

	//Recursive Function
	cout << "Recursive Function" << endl;
	cout << "Please enter a number" << endl;
	double rF;
	cin >> rF;
	double answerRecursion = powerRecursive(2, rF);
	cout << answerRecursion << endl;

	
}
