//Demonstration of the Sort 0 1 2 Technique using 3 pointers.
//index 0 - (low - 1) represent all the 0s
//index low - (mid - 1) represent all the 1s
//index high - (n-1) represent all the 2s
//Example:
// Initially: 0 1 2 1 2 0 1
// Finally:
//  0  0  1  1  1  1  2  2
//        |           |
//        |           |
//       low      mid & high

//Test cases:
/*
4
5
1 0 0 1 2
0 0 1 1 2
8
0 0 1 0 1 2 2 1
0 0 0 1 1 1 2 2
3
0 1 0
0 0 1
4
1 0 0 1 
0 0 1 1 
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
  {
    int test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
      int n;
      cin>>n;
      int arr[n];
      for(int i = 0; i<n; i++)
      {
         cin>>arr[i];
      }
      int low = 0, mid = 0, high = n-1;

      //We use the mid pointer to traverse through the array
      while(mid<=high)
      {
        if(arr[mid]==0)
        {
          swap(arr[mid++], arr[low++]);

        }
        else if(arr[mid]==1)
        {
          mid++;
        }
        else if(arr[mid]==2)
        {
          swap(arr[mid], arr[high]);
          high--;
        }
      }

      for(int i = 0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }

    return 0;
  }
