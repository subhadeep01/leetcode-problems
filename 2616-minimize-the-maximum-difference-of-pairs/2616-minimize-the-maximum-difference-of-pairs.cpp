class Solution {
public:
    #define ll long long
    bool check(int mid, vector<int>&nums, int p)
    {
        // see whether there are atleast p pairs with difference<=mid
        int pairs=0;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]-nums[i-1])<=mid){
                pairs++;
                i++;
            }
        }
        
        return (pairs>=p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(check(mid,nums,p))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};