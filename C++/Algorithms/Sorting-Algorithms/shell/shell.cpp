//shell sort.cpp   *note- watch it before going to code 
#include<iostream>
#include<vector>
using namespace std;

void shell(vector <int> arr){ 

for(int i=arr.size()/2;i>=1;i/=2){          //purpose of this is as in insertion sort we compare the consecutive elements (but in this we compare element at which are at difference of i  and this difference keeps on decreasing on everay iteration )


// for lines 12 to 27 whole meaning is we start from i and compare every element which is at index at a differnce of i(we do this for every  iteraiton of j)

for(int j=i;j<arr.size();j++){    // startig from i we go until size of array(or vector) and compare
    int k=j;
    while(k-i>=0){                 // swaping of var at position k-i and k  until out k-i become less than 0
        if(arr[k] < arr[k-i]){
            int temp=arr[k];
            arr[k]=arr[k-i];
            arr[k-i]=temp;
            k-=i;
        }
        else{
            break;              //we are  if our arr[k] > arr[k+1] because we dont need to check previos they will be already sorted
        }
       
    }
}
}
for(auto i:arr)           //printing of array(or vector )
cout<<i;                   
}

int main(){
   
     int size;
     cin>>size;                   //taking the size and array(or vector) input
      vector<int> a(size);
      for(auto &i:a)
       {
           int value;
           cin>>value;
           i=value;
       }
       shell(a);
}