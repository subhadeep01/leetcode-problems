class Solution {
public:
     int f(vector<int>&nums, vector<int>&dp,int n)
    {
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);
        if(dp[n]!=-1)return dp[n];
        return dp[n]=max(nums[n-1]+f(nums,dp,n-2),f(nums,dp,n-1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        vector<int>dp1(n+3,-1);
        vector<int>dp2(n+3,-1);
        return max(f(numsA,dp1,n-1),f(numsB,dp2,n-1));
    }
    
    
};