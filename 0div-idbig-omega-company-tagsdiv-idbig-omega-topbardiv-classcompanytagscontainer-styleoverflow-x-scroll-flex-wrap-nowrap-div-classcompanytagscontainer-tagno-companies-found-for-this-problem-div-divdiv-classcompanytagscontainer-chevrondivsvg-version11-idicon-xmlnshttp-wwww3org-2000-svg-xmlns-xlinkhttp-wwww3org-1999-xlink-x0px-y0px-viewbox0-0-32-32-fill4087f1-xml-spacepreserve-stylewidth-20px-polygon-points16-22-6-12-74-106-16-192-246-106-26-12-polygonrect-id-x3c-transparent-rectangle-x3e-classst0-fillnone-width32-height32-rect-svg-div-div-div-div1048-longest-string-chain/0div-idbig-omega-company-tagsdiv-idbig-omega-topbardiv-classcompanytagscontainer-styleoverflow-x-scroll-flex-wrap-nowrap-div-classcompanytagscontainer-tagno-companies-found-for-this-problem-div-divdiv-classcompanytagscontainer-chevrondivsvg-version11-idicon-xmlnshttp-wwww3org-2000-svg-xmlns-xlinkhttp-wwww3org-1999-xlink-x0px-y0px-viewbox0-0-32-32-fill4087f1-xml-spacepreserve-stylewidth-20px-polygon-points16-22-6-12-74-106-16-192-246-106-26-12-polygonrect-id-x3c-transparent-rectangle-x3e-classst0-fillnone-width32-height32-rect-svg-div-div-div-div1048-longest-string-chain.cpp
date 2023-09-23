class Solution {
public:
    bool possible(string &word1, string &word2)
    {
        int n=word1.size();
        int m=word2.size();
        if(n!=m+1) return false;
        int i=0,j=0;

        while(i<n)
        {
            if(word1[i]==word2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==n && j==m)return true;
        return false;
        
    }
    bool static cmp(string &a, string &b)
    {
        if(a.size()<b.size()) return true;
        if(a.size()>b.size()) return false;
        if(a[0]<b[0]) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>dp(n+1,1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(possible(words[i],words[j]) && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};