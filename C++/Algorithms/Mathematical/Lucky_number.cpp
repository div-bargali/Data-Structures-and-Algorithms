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
  if(flag==1)
  cout<<n<<" is not a lucky number";
  else 
  cout<<n<<" is a lucky number";
    return 0;
}