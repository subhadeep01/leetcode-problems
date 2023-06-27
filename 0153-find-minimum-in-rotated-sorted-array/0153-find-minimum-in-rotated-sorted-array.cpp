class Solution {
public:
    int findMin(vector<int>& nums) {
        // int res=INT_MAX;
        // int low=0,high=nums.size()-1;
        // int mid=0;
        // while(low<=high)
        // {
        //     if(nums[low]<nums[high])return nums[low];
        //     mid=(low+high)/2;
        //     res=min(res,nums[mid]);
        //     if(nums[mid]>=nums[low])
        //         low=mid+1;
        //     else
        //         high=mid;
        // }
        // return res;
        int lo=0,hi=nums.size()-1;
        while(lo<hi)
        {
            int mid=(lo+hi)>>1;
            if(nums[mid]>=nums[hi])
                lo=mid+1;
            else
                hi=mid;
        }
        return nums[lo];
    }
};