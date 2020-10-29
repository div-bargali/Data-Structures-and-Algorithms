/*
    Given an array nums of n integers, find all unique triplets in the array which gives the sum of zero.
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
             return {};
        sort(nums.begin(),nums.end());
        vector <vector<int>> result;
        unordered_set<string> triplets;
        int i = 0;
        while(i < n -2){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                     string newTriplet = to_string(nums[i]) + ":"
                            + to_string(nums[j]) + ":" 
                            + to_string(nums[k]);
                     if(triplets.find(newTriplet) == triplets.end()){
                         triplets.insert(newTriplet);
                         result.push_back({nums[i],nums[j],nums[k]});
                     }
                    j++;
                    k--;
                }
                else if(sum > 0)
                    k--;
                else if(sum < 0)
                    j++;
            }
            i++;
        }        
        return result;
}

int main(){
    int n;
    vector <int> nums;
    cin>>n;
    for(int i = 0; i < n; i++){
        int input;
        cin>>input;
        nums.push_back(input);
    }
    vector <vector<int>> result = threeSum(nums);
    for(int i = 0; i< result.size(); i++){
        for(int j = 0; j< result[0].size(); j++)
            cout<<result[i][j]<<"  ";
        cout<<"\n";
    }
}
//Time complexity: O(n^2), Space complexity: O(n)