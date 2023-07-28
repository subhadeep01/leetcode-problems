class Solution {
public:
    #define ll long long
    ll dp[25][25][2];
    ll f(vector<int>&nums, int i, int j, int turn)
    {
        if(i>j)return 0;
        
        if(dp[i][j][turn]!=-1)return dp[i][j][turn];
        
        if(turn==0)// player 1 turn
        return dp[i][j][turn]=max(nums[i]+f(nums,i+1,j,1),nums[j]+f(nums,i,j-1,1));
        
        return dp[i][j][turn]=min(f(nums,i+1,j,0),f(nums,i,j-1,0));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        ll sum1=0,sum2=0;
        sum2=accumulate(nums.begin(),nums.end(),0);
        sum1=f(nums,0,n-1,0);
        sum2-=sum1;
        return (sum1>=sum2);
        
    }
};