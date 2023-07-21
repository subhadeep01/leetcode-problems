class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1),cnt(n+1,1);
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi) ans+=cnt[i];
        }
        return ans;
    }
};