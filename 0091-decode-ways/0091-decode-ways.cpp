class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int mod =(int)1e9+7;
        s='$'+s;
        int n=s.size();
        vector<long long>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n;i++)
        {
            long long op1=(s[i]!='0')?dp[i-1]:0;
            long long op2=((s[i-1]-'0')*10+ (s[i]-'0')>=10 &&(s[i-1]-'0')*10+ (s[i]-'0')<=26)?dp[i-2]:0;
            dp[i]=(op1+op2);
            //dp[i]%=mod;
        }
        return dp[n-1];
    }
};