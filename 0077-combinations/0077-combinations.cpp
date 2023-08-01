class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind, int n, int k, vector<vector<int>>&dp, vector<int>&v)
    {
        if(k==0)
        {
            ans.push_back(v);
            return;
        }
        
        if(ind==n+1) return;
        
        if(dp[ind][k]!=-1) return;
        
        v.push_back(ind);
        f(ind+1,n,k-1,dp,v);
        
        v.pop_back();
        f(ind+1,n,k,dp,v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<int>v;
        f(1,n,k,dp,v);
        return ans;
    }
};