// Bubble Sort : Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

#include<iostream>
using namespace std;


//Function to implement bubble sort  
void bubblesort(int a[],int n){
   int i,j;
   int rounds = 0;
   for ( i = 0; i < n; i++)
   {
       rounds++;
       for ( j = 0; j< n-i-1; j++)
       {
           if (a[j] > a[j+1])
           {
               int temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
           
       }
       
   }
   cout<<"no of rounds : "<<rounds<<endl;
}
// DRIVER CODE
int main()  
{  
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    int myarr[n];
    // Input the array 
    cout << "enter the  integers in any order " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    //print arry before bubble sort
      cout << "before bubble sort " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
    // print the sorted array 
    
    cout << "after bubble sort " << endl;
    bubblesort(myarr,n);
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
}  
  
// CONTRIBUTOR : satyam kumar
