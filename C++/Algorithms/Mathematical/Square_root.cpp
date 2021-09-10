#include <iostream>
#include <math.h> //for log10(), fabs(), pow()

using namespace std;

#define DBL_EPSILON 2.2204460492503131e-16

//These 2 functions will accept user input and return the resulting Square Root of that user input

//Iterative Function
double sqrtIterative(double x)
{
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

int main(void)
{

    //Iterative Function
    cout << "*************************Iterative Function*************************" << endl;
    cout << "Please enter a number : ";
    double it;
    cin >> it;
    double answerIterative = sqrtIterative(it);
    cout << "The Square Root is : " << answerIterative << endl
         << endl;

    //Recursive Function
    cout << "*************************Recursive Function*************************" << endl;
    cout << "Please enter a numbers : ";
    double rc;
    cin >> rc;
    double answerRecursion = sqrtRecursive(rc, 1);
    cout << "The Square Root is : " << answerRecursion << endl;
}