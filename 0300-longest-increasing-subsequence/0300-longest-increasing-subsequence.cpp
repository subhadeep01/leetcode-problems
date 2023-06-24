class Solution {
public:
    int LCS(int ind, int prev_ind, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(ind==nums.size())return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int not_take=0+LCS(ind+1,prev_ind,nums,dp);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        take=1+LCS(ind+1,ind,nums,dp);
        return dp[ind][prev_ind+1]=max(take,not_take); 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return LCS(0,-1,nums,dp);
        
    }
};