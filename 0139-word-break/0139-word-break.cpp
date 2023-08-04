class Solution {
public:
    bool f(int ind, string &s, vector<string>&wordDict, vector<vector<int>>&dp)
    {
        if(ind==s.size()) return true;
        
        for(int i=ind;i<s.size();i++)
        {
            for(auto x: wordDict)
            {
                if(x==s.substr(ind,i-ind+1))
                {
                    if(dp[ind][i]!=-1)
                    {
                        return (dp[ind][i]);
                    }
                    bool ans = f(i+1,s,wordDict,dp);
                    if(ans) 
                    {
                        dp[ind][i]=1;
                        return true;
                    }
                }
            }
            dp[ind][i]=0;
        }
        return false;  
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,s,wordDict,dp);
    }
};