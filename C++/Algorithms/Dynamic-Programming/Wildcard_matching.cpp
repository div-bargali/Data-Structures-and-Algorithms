#include<bits/stdc++.h>
using namespace std;

//creating a function for wildcard matching
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    
    //declaring a dp table of size n+1 * m+1
    vector<vector<int>> dp(n+1, vector<int>(m+1, true));
    
    //initialsing mth column as false
    for(int i = n-1; i >= 0; i--){
        dp[i][m] = false;
    }
    

    for(int j = m-1; j >= 0; j--){
        if(p[j] == '*') dp[n][j] = dp[n][j+1] && true;
        else dp[n][j] = false;
    }
    

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            
            //if characters are same we move ahead.
            if(s[i] == p[j]) dp[i][j] = dp[i+1][j+1];
            
            //if we encounter a '?' we just move ahead in both strings.
            else if(p[j] == '?') dp[i][j] = dp[i+1][j+1];
        
        	//if we encounter a '*' in p we use the then match the remaining string of s with p (no change in position in p)
    		//or we just skip that letter in p.
            else if(p[j] == '*') dp[i][j] = dp[i+1][j] || dp[i][j+1];
            
            else dp[i][j] = false;
        }
    }
    
    return dp[0][0];
    
}

//driver code
int main(){
	string s = "adceb";
	string p = "*a*b";
	if(isMatch(s, p))
		cout<<"Yes the two patterns match"<<endl;
	else
		cout<<"No the two patterns dont match"<<endl;
}

// the above program will output yes.
