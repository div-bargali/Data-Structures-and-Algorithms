#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//Activity Selection Problem using Recursion


int activity(int **T,vector<pair<int,int>> ac,int i,int j)
{
    if(i>=j)                                                                                //base case
        return 0;                                                                           //all ac. in between are counted

    int max=0;
    for(int k=i+1;k<j;++k)                                                                   //Activity is compatible
        if(ac[k].first>=ac[i].second && ac[k].second<=ac[j].first)                           //if start time is not greater finish time of previous
        {                                                                                    //and finish time is not greater than start time of next
            if(T[i][k]==-1)
                T[i][k]=activity(T,ac,i,k);
            if(T[k][j]==-1)
                T[k][j]= activity(T,ac,k,j);

            
            // S[i,j] are compatible activities between i and j
            // To find maximum possible  max(S[i,k] + 1 + S[k,j])

            if(max<T[i][k] +1 + T[k][j])      
                max=T[i][k] +1 + T[k][j];
        }
    return max;
}

int main()
{
    vector<pair<int,int>> ac;

    ac.push_back(make_pair(1,2));  
    ac.push_back(make_pair(3,4)); 
    ac.push_back(make_pair(0,6)); 
    ac.push_back(make_pair(5,7)); 
    ac.push_back(make_pair(8,9)); 
    ac.push_back(make_pair(5,9));   

         
    ac.push_back(make_pair(0,0));                                               //0,0 and INF,INF are added at start and end
    ac.push_back(make_pair(INT_MAX,INT_MAX));                                   //We will not be counting first and last activities                  

    sort(ac.begin(),ac.end());                                                  //Sorting based on start time

//  Table for memoization----------------------------------

    int **T;
    T = new int *[ac.size()];
    for(int i = 0; i <ac.size(); i++)
        T[i] = new int[ac.size()];

    for(int i=0;i<ac.size();++i)
        for(int j=0;j<ac.size();++j)
            T[i][j]=-1;

//-------------------------------------------------------------


    int sol=activity(T,ac,0,ac.size()-1);

    cout<<"No of activities are : "<<sol;


}