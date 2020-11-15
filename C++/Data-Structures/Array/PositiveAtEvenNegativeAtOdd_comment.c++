#include <iostream>
using namespace std;
#define ll long long int
#define MAXSIZE 100

int main() {
   ll arr[MAXSIZE] = {NULL, } ,i=0;
   while(cin>>arr[i]){
       i++;                  //input value (if value is ^z[ctrl + z] break while)
   }
   ll n = i;
   
   ll pos[MAXSIZE],neg[MAXSIZE];
       ll pi=0,pn=0,xp=0,xn=0;
       for(i=0;i<n;i++){         //first sorting
           if(arr[i] >= 0){
               pos[pi] = arr[i];   //positive number = pos[]
               pi++;
           }
           else{
               neg[pn] = arr[i];   //negative number = neg[]
               pn++;
           }
       }      
       for(i=0;i<n;i++){         //second sorting
           if(i%2==0 && xp<pi){
               arr[i] = pos[xp];   //if i = even and xp < pi
               xp++;
           }
           else if(i%2!=0 && xn<pn){//else if i = odd and xn < pn
               arr[i] = neg[xn];
               xn++;
           }
           else if(xp>=pi){      //else if xp >= pi
               arr[i] = neg[xn++];
           }
           else if(xn>=pn){
               arr[i] = pos[xp++];   //else if xn >= pn
           }
       }
   
   for(i=0;i<n;i++){
       cout<<arr[i]<<" ";         //print Array completed sorting
   }
   return 0;
}
