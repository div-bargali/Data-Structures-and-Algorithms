class Solution {
    public static int bs(int []nums,int start,int end,int target)
    {
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target)end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    
     public int findMin(int[] nums) {
        if(nums.length==1)
            return 0;
        
        int start=0;
        int end=nums.length-1;
        
        if(nums[0]<nums[end])
            return 0;
        
        while(end>=start)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]>nums[mid+1])
            {
                return mid+1;
            }
            
            if(nums[mid-1]>nums[mid])
            {
                return mid;
            }
            if(nums[mid]>nums[0])
            {
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
        }
        return -1;
        
        
    }
    public int search(int[] nums, int target) {
        int start = 0 ;
        int end = nums.length-1;
      int pivot= findMin(nums);
        int ans=0;
        if(nums[0]<nums[end])
        {
            return bs(nums,0,nums.length-1,target);
        }
       if(target>=nums[0])
        {
            ans=bs(nums,0,pivot,target);
        }
        else ans= bs(nums,pivot,nums.length-1,target); 
        return ans;
    }
}