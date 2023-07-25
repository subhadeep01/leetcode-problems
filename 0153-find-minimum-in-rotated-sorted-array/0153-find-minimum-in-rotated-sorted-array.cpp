class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
           int mid=(low+high)/2;
            if(nums[mid]>=nums[high])
            {
                res=min(res,nums[mid]);
                low=mid+1;
            }
            else
                high=mid;
        }
        return res;
        // int lo=0,hi=nums.size()-1;
        // while(lo<hi)
        // {
        //     int mid=(lo+hi)>>1;
        //     if(nums[mid]>=nums[hi])
        //         lo=mid+1;
        //     else
        //         hi=mid;
        // }
        // return nums[lo];
    }
};