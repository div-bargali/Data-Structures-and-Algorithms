//Sum of two different arrays, arr1 and arr2, of size n and m respectively, where both the arrays contain single digits at each index.
//For example, given two arrays, each of size 3, arr1 = 6 2 6, arr2 = 6 5 4, the output would be 1 2 8 0
//If the sizes of the two arr are different, The value is calculated after it is aligned backwards.
//For example, arr1 = 1 2 3, arr2 = 1, 2, 3, 4, the output would be 0 1 3 5 7

/*Test case:
	
Input:
	2
	3
	1 5 2
	2
	1 3
	4
	9 7 1 2
	3
	5 8 8

Output:
	0 1 6 5
	1 0 3 0 0
	
*/

#include <iostream>
using namespace std;

void sumOfTwoArrays(int *arr1, int m, int *arr2, int n, int *output)
{
    int i = m-1, j = n-1, k = m, carry = 0, number = 0;
    if(m >= n) {
   k = m;
        while(i >= 0) {
       number = carry;
            if(j >= 0)
               number = number + arr2[j];
            number = arr1[i] + number;
            output[k] = number%10;
            carry = number/10;
            j--;
            i--;
            k--;            
        }
        output[k] = carry;       
        
    }
    else {
   k = n;
        while(j >= 0) {
            number = arr2[j] + carry;
            if(i >= 0)
               number = number + arr1[i];
            output[k] = number%10;
            carry = number/10;
            i--;
            j--;
            k--;
        }
        output[k] = carry;
    }
}

int main()
{
   int t;
   cout << "input count" << endl; // Added to know what value is being entered each time cin
   cin >> t;
   
   while (t--)
   {
      int m;
      cout << "input first array size" << endl;
      cin >> m;
      int *arr1 = new int[m];
      cout << "input first array value" << endl;
      for (int i = 0; i < m; i++) {
         cin >> arr1[i];
      }
      int n;
      cout <<"input second array size" << endl;
      cin >> n;
      int *arr2 = new int[n];
      cout <<"input second array value" << endl;
      for (int i = 0; i < n; i++) {
         cin >> arr2[i];
      }

      int output_size = 1 + max(m, n);

      int *output = new int[output_size];

      sumOfTwoArrays(arr1, m, arr2, n, output);

      cout << "output: "; // Added to know that the output value is output
      for (int i = 0; i < output_size; ++i)
      {
         cout << output[i] << " ";
      }
      cout << endl;
      delete[] arr1;
      delete[] arr2;
      delete[] output;
   }

   return 0;
}
