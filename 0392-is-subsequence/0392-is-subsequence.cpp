class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int c=0;
        vector<int>pos;
        pos.push_back(0);
        for(int i=0;i<s.size();i++)
        {
            int j=pos.back();
            if(j!=0)
               j++; 
            for(;j<t.size();j++)
            {
                if(t[j]==s[i])
                {
                    c++;
                    pos.push_back(j);
                    break;
                }
            }
        }
        if(is_sorted(pos.begin(),pos.end()) && c==n)
            return true;
        
        return false;
    }
};