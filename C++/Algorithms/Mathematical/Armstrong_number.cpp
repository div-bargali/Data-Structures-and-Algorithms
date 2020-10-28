#include <cmath>
#include <iostream>

using namespace std;

int main() {
   int n, ognum, d, ct = 0, sum = 0, power;
   cout << "Enter an integer: ";
   cin >> n;

   ognum = n;

   while (ognum != 0) {
      ognum /= 10;
      ++ct;
   }
   ognum = n;

   while (ognum != 0) {
      d = ognum % 10;
      power = round(pow(d, ct));
      sum += power;
      ognum /= 10;
   }

   if (sum == n)
      cout << n << " is an Armstrong number.";
   else
      cout << n << " is not an Armstrong number.";
   return 0;
}