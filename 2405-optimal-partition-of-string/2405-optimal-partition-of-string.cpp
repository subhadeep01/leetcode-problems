class Solution {
public:
    int partitionString(string s) {
        map<char,int>m;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                m.clear();
                ans++;
                m[s[i]]++;
            }
            else
            {
                m[s[i]]++;
            }
        }
        return ans+1;
    }
};