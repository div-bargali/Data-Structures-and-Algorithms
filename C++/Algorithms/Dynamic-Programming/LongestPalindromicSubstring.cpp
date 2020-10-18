/*

Given the string s , this program will output 
the first longest palindromic substring and it's length

*/
#include<iostream>
using namespace std;

string findLongestPalindromeSubstring(string s){
       int n = s.length();

       bool dp[n+1][n+1];
       
       for(int i=0;i<=n;i++){
           for(int j=0;j<=n;j++){
               dp[i][j] = false;
           }
       } 

       int max_length  = 0; 

       //start index of longest substring
       int indexx = -1;
       //end index of longest substring
       int indexy = -1;
       
       //for length 1 strings
       for(int i=0;i<n;i++){
           dp[i+1][i+1]  = true; 

           //to output only the first string
           if (max_length < 1){
             max_length = 1;
             indexx = i;
             indexy = i;
           }
       }

       //length 2 strings which are palindrome
       for(int i=0;i<n-1;i++){
           if (s[i] == s[i+1]){
               dp[i+1][i+2] = true;
              
               if (max_length < 2){ 
                 max_length = 2;
                 indexx = i;
                 indexy = i+1;
               }
           }
       }

       //length 3 strings which are palindrome
       for(int i=0;i<n-2;i++){
           if (s[i] == s[i+2]){
               dp[i+1][i+3] = true;

               if (max_length < 3){ 
                  max_length = 3;
                  indexx = i;
                  indexy = i+2;
               }
           }
       } 

       //length 4 or more strings which are palindrome
       for(int i=4;i<=n;i++){
           for(int j=0;j<n-i+1;j++){
               if (s[j] == s[j+i-1] && dp[j+2][j+i-1]){
                   dp[j+1][j+i] = true;
                    if (max_length < i){
                        max_length = i;
                        indexx = j;
                        indexy = j+i-1;
                    }
               }
           }
       }
       cout<<"longest palindrome substring length = " << max_length << "\n"; 

       string res;
        
       for(int i=indexx;i <= indexy ; i++){
           res+=s[i];
       } 
       return res; 
}
int main(){
    string s;
    cin >> s;

    string res =  findLongestPalindromeSubstring(s);
    cout << "longest palindrome substring = " << res <<"\n";

}