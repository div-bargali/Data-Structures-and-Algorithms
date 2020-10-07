// A C++ Program to implement subset sum problem using the dynammic programming approach

#include<iostream>
using namespace std;


//Returns true if there exists a subset of the set with sum equal to the given sum and false otherwise
bool subsetSum(int set[], int sum, int n){

    //create a new matrix in which dp[i][j] will
    //be true if there exists a subset of the set[0...j-1] with
    // sum equal to i

    bool dp[n+1][sum+1];

    //if sum itself is 0,then we can get 0 sum by not selecting any element from the set

    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    
    //if set is empty and sum is not zero then answer would be false

    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    
    //filling dp table
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){

            //if the element chosen currently is less than or equal to the current sum
            if(set[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
            }

            //if current sum is less than the current element in the set
            else if (j < set[i-1])
                dp[i][j] = dp[i-1][j];

        }
    }
    return dp[n][sum];
}

//Driver program to test the above subsetSum function
int main(){

    int sum = 41;
    int set[11] = {6, 7, 9, 13, 55, 4, 12, 34, 5, 2, 3 };
    int n=11;

    if(subsetSum(set, sum, n))
        cout<<"Found a subset with given sum = "<<sum<<endl;
    else 
        cout<<"There does not exist a subset with the given sum"<<endl;
    
    return 0;


}
//Output of the above code would be "Found a subset with given sum = 41"