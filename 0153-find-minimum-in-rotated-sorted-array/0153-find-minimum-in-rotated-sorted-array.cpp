class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
           int mid=(low+high)/2;
           if(nums[mid]>=nums[low]) // left sorted
           {
             res=min(res,nums[low]);
               low=mid+1;
           }
            else
            {
                res=min(res,nums[mid]);
                high=mid-1;
            }
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