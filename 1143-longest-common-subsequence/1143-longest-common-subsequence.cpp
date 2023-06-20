class Solution {
public:
        int f(string &s1, string &s2, int ind1, int ind2 , vector<vector<int>>&dp)
{
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])
    {
       return dp[ind1][ind2]=1+f(s1,s2,ind1-1,ind2-1,dp);
    }
    return dp[ind1][ind2]=0+max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
}
    int longestCommonSubsequence(string s1, string s2) {
        int x=s1.size();
        int y=s2.size();
         vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return f(s1,s2,x-1,y-1,dp);
    }
};