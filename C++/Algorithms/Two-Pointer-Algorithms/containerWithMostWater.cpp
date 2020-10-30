/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
 * Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
 * */
#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
        int min_height,max_area = 0,i=0, j= height.size()-1;
        while(i<j){
            min_height = (height[i]<height[j])?height[i]:height[j];
            int newArea = min_height * (j - i);
            if(newArea > max_area)
                max_area = newArea;
            if(min_height == height [i]){
               while(height[i]<= min_height && i<j)
                   i++;
                
            }
            else{
                while(height[j]<= min_height && i<j)
                   j--;
            }
        }
        return max_area;
}
int main(){
    vector <int> height;
    int max,n;
    cin>>n;
    for(int i = 0; i< n ; i++){
        int in;
        cin>>in;
        height.push_back(in);
    }
    max= maxArea(height);
    cout<<"Container with most water:"<<max;
}