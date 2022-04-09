class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0; int high= nums.size()-1;
        int index=nums.size();
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else 
                high=mid-1;
        }
        return (lower_bound(nums.begin(),nums.end(),target)-nums.begin());
    }
};