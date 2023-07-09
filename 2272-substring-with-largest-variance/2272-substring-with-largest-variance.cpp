class Solution {
public:
    int largestVariance(string s) {
        vector<int>freq(26);
        for(auto x: s)
        {
            freq[x-'a']++;
        }
        int ans=0;
        for(char ch1='a'; ch1<='z';ch1++)
        {
            for(char ch2='a'; ch2<='z'; ch2++)
            {
                if(ch1==ch2 || freq[ch1-'a']==0 || freq[ch2-'a']==0)
                    continue;
                
                for(int rev=1;rev<=2;rev++)
                {
                    int f1=0,f2=0;
                    for(auto x: s)
                    {
                    f1+=(x==ch1);
                    f2+=(x==ch2);
                    if(f1<f2)
                    {
                        f1=f2=0;
                    }
                    if(f1>0 && f2>0)
                    {
                    ans=max(ans,f1-f2);
                    }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};