class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, middle;
        while(left<=right){
            middle=left+(right-left)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]>target)
                right=middle-1;
            else
                left=middle+1;
        }
        return -1;
    }
}; 