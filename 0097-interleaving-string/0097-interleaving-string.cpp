class Solution {
public:
    unordered_map<string,int>mp;
    bool f(string s1, string s2, string s3,int i, int j, int k)
    {
        if(k==s3.size())
        {
            return ((i==s1.size() && j==s2.size())?true:false);
        }
        
        string key = to_string(i)+"*"+to_string(j)+"*"+to_string(k);
        
        if(mp.find(key)!=mp.end()) return mp[key];
        
        if(i==s1.size())
        {
            return mp[key]=(s2[j]==s3[k])?f(s1,s2,s3,i,j+1,k+1):false;
        }
        
        if(j==s2.size())
        {
            return mp[key]=(s1[i]==s3[k])?f(s1,s2,s3,i+1,j,k+1):false;
        }
        
        bool ans1 = false, ans2= false;
        
        if(s1[i]==s3[k])
        ans1 = f(s1,s2,s3,i+1,j,k+1);
        
        if(s2[j]==s3[k])
        ans2= f(s1,s2,s3,i,j+1,k+1);
        
        return mp[key] = (ans1 | ans2);
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        return f(s1,s2,s3,0,0,0);
    }
};