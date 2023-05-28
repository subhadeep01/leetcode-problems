class Solution {
public:
    bool f(int ind, int target, vector<int>&a, vector<vector<int>>&dp)
{
    
    if(target==0)return true;  
   if(ind==0)return (a[0]==target);
   if(dp[ind][target]!=-1)return dp[ind][target];
   bool take=false;
   if(a[ind]<=target)
    take= f(ind-1, target-a[ind],a, dp);
   bool not_take=f(ind-1, target,a,dp);
   return dp[ind][target]= take | not_take;
}

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
    for(auto x: nums)
        sum+=x;
    if(sum%2==1)return false;
    vector<vector<int>>dp(n+1,vector<int>(sum/2+2,-1));
    return f(n-1,sum/2,nums,dp);
    }
};