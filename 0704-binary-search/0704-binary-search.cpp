class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low=0; int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            if(nums[mid]>=target)
            {
                if(nums[mid]==target)
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};