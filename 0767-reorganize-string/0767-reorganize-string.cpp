class Solution {
public:
    string reorganizeString(string s) {
        vector<int>cnt(26,0);
        for(int i=0;i<s.size();i++)
        cnt[s[i]-'a']++;
        int maxf=0; int letter=0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>maxf)
            {
            maxf=cnt[i];
            letter=i;
            }
        }
        if(maxf>(s.size()+1)/2)return "";
        int ind=0;
        while(cnt[letter]>0)
        {
            s[ind]=(char)(letter+'a');
            ind+=2;
            cnt[letter]--;
        }
        for(int i=0;i<26;i++)
        {
            while(cnt[i]>0)
            {
                if(ind>=s.size()) 
                {
                    ind=1;
                }
                s[ind]=(char)(i+'a');
                ind+=2;
                cnt[i]--;
            }
        } 
        return s;
    }
};