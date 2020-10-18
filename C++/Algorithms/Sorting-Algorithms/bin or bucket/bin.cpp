//bin | bucket sort.cpp  with use use of vector
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//bin sort 
void bin(vector<int> arr){
   
    auto p=max_element(arr.begin(),arr.end());  //p is max element used for creating the array(or bin) to store the elements at same index as value
    vector<vector<int>> a(*p+1,vector<int>());  //2d vector of size max element + 1
    
    for(int i:arr){                    //pushing our value's of arr to 2d vector (index == value)
        a[i].push_back(i);             
     }

    arr.clear();                        //clearing arr before pushing values into it 
    for(auto i:a){                        
        for(int j=0;j<i.size();j++){
            arr.push_back(i[j]);         //pushing back value from a(vector to arr)
        }
    }
    for(auto i:arr){
        cout<<i;                 //printing of sorted array(vector)
    }

}


int main(){
    int size;
    cout<<"enter the size";           //taking the input 
    cin>>size;
    vector<int> arr (size);
    cout<<"enter the array";
    for(auto &a:arr)
    {
        int value;
        cin>>value;
        a=value;
    }
    bin(arr);

   

}
