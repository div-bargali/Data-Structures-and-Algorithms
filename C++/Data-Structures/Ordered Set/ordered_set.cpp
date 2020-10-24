#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

/*
While using stl set we can't access the xth element and similarly we can't 
access the no the elements present below a certain element in log(n) time.
Ordered set seems to solve this problem.
I have implemented an ordered set using fenwick tree.
*/

class ordered_set{
    /*
    Creates an ordered set of capicity n and elements ranging from 1 to n.
    */
    int *ft,n;
    
public:    
    ordered_set(int n){
        this->n=n;
        ft=new int[n+1];
        fill(ft,ft+n+1,0);
    }

    int get_next(int ind){
        return ind+(ind&-ind);
    }

    int get_prev(int ind){
        return ind-(ind&-ind);
    }

    void update(int x){
        /*inserts the element x in the set*/
        while(x<=n){
            ft[x]++;
            x=get_next(x);
        }
    }

    int find_by_order(int x){
        /*
        returns the xth element present in the set (1-based indexing)
        If x > no. of elements present in the ordered set than it returns n+1.
        */     
        int curr=0;                 
        int sum=0;

        for(int j=log2(n)+1;j>=0;j--){      // max no of bits can be log2(n)+1
             curr+=1<<j;
             if(curr<=n&&sum+ft[curr]<x)
                sum+=ft[curr];
             else
                curr-=1<<j;
        }
        
        return curr+1;  
    }

    int count(int x){
        /*returns the no. of elements less than or equal to x*/
        int sum=0;
        while(x){
            sum+=ft[x];
            x=get_prev(x);
        }
        return sum;

    }

};


int main(){
    ordered_set ord(1000);
    ord.update(10);
    ord.update(20);
    ord.update(27);
    ord.update(999);   
    cout<<ord.find_by_order(1)<<endl;
    cout<<ord.find_by_order(3)<<endl;
    cout<<ord.count(1000)<<endl;
    cout<<ord.count(27)<<endl;
    if(ord.count(20)-ord.count(19)>0)
        cout<<"20 present in set"<<endl;
    if(ord.count(888)-ord.count(887)==0)
        cout<<"888 not present in set"<<endl;

}