/*
This function is a function that calculates the sum of the number of digits in the integer entered by the user by the number of digits in the entered integer.
If the number is the same as the number initially entered, it prints that the Armstrong number is correct, and if it is different, it prints that it is not.
*/
#include <cmath>
#include <iostream>

using namespace std;

int main() {
   int n, ognum, d, ct = 0, sum = 0, power;
   cout << "Enter an integer: ";
   cin >> n;

   ognum = n;

   while (ognum != 0) { // Finding the number of digits of the input integer
      ognum /= 10;
      ++ct;
   }
   ognum = n;

   while (ognum != 0) { // Square the numbers in each digit by the number of digits in the input integer. Then, the squared numbers are added together
      d = ognum % 10;
      power = round(pow(d, ct));
      sum += power;
      ognum /= 10;
   }

   if (sum == n) //  Armstrong's number if the sum of the number of digits from the inputted integers squared by the number of digits received is equal to the number initially input
      cout << n << " is an Armstrong number.";
   else // If it's wrong, it's not Armstrong's number.
      cout << n << " is not an Armstrong number.";
   return 0;
}