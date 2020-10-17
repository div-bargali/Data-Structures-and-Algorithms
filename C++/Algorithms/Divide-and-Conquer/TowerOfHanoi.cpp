#include<bits/stdc++.h>
using namespace std;

//Function that would calculate no of steps for discs transfer from tower 1 to tower 3

//count is accepted as reference to directly reflect changes in main()
void solveTower(int n,int s,int h,int d,int &count){
    if(n==1){
        count++;
        return ;
    }

// recursively transferring n-1 discs from source to helper tower 
    solveTower(n-1,s,d,h,count);
    count++;

//transfering discs from helper to destination tower
    solveTower(n-1,h,s,d,count);
    
}


int main(){

int n,source=1,helper=2,dest=3,count=0;

//input n discs
cin>>n;

//calling function
solveTower(n,source,helper,dest,count);

//displaying no. of steps
cout<<count<<endl;

return 0;
}
