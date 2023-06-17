class Solution {
public:
    int partitionString(string s) {
        vector<int>m(27,0);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]-'a']==1)
            {
                fill(m.begin(),m.end(),0);
                ans++;
                m[s[i]-'a']=1;
            }
            else if(m[s[i]-'a']==0)
            {
                m[s[i]-'a']=1;
            }
        }
        return ans+1;
    }
};