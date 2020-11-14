/*
This function receives the value of n1 from the user, and outputs a "lucky number" 
if there is a duplicate number among the input numbers, and a "not lucky number" if there is no duplicate number.
*/

#include<iostream>
using namespace std;

int main() {
  int n,n1,n2,d1,d2,ct=0,flag=0;
  cout<<"Enter a number: ";
  cin>>n1;
  n2=n1;
  n=n1;
  while(n1>0) 
  {
      d1=n1%10;
      while(n2>0) 
      {
          d2=n2%10;
          if(d1==d2)
          ct++;
          n2=n2/10;
      }
      if(ct>1)
      {
          flag=1;
          break;
      }
      ct=0;
      n2=n;
      n1=n1/10;
  }
  if(flag==1) // flag == 1 it means that the numbers do overlap
  cout<<n<<" is not a lucky number";
  else // flag != 1 it means that there is even one duplicate number
  cout<<n<<" is a lucky number";
    return 0;
}