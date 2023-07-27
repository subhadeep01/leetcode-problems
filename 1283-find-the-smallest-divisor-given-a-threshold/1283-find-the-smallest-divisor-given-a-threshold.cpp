class Solution {
public:
    bool check(int x, vector<int>&nums, int threshold)
    {
        int sum=0;
        for(auto it: nums)
        {
            sum+=ceil(double(it)/x);
        }
        return (sum<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,nums,threshold))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};