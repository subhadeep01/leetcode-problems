class Solution {
public:
    // dp[i][j] denotes minimum ASCII Sum of deleted character when consider string1 to be of length i+1 and string2 of length j+1
    int f(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(i==n && j==m) return 0;
        
        if(i==n)
        {
            int sum=0;
            for(int x=j;x<m;x++)
                sum+=s2[x];
            return sum;
        }
        if(j==m)
        {
            int sum=0;
            for(int x=i;x<n;x++)
                sum+=s1[x];
            return sum;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
        return dp[i][j]=f(i+1,j+1,n,m,s1,s2,dp);
        
        return dp[i][j]=min((int)s1[i]+f(i+1,j,n,m,s1,s2,dp), (int)s2[j]+f(i,j+1,n,m,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,n,m,s1,s2,dp);
    }
};