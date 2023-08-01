class Solution {
public:
    int dp[101][10003];
    int f(int ind, int sum, vector<int>&v)
    {
         if(sum==0) return 1;
        
        if(v[ind]>sum) return 1e7;
        
       
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        return dp[ind][sum]=min(1+f(ind,sum-v[ind],v),f(ind+1,sum,v));
    }
    int numSquares(int n) {
        vector<int>v;
        for(int i=1;i<=100;i++)
        {
            v.push_back(i*i);
        }
        memset(dp,-1,sizeof(dp));
        return f(0,n,v)-1;
    }
};