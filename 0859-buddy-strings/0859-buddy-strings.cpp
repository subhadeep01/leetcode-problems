class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s==goal)
        {
            int cnt=0;
            map<char,int>m;
            for(auto x: s)
            {
                m[x]++;
                if(m[x]>1)
                    return true;
            }
            return false;
        }
        int c=0;
        int x=-1,y=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                c++;
                if(x==-1)
                x=i;
                else
                y=i;
            }
        }
        if(c==2)
        {
            swap(s[x],s[y]);
            if(s==goal)return true;
            else
                return false;
        }
        else
            return false;
    }
};