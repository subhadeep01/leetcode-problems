class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size();
        string temp;
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                f=1;
                temp+=s[i];
            }
            else
            {
                if(f==1)// there are some characters visited
                {
                ans=' '+temp+ans;
                temp="";
                f=0;
                }
            }
        }
        if(f==1)
        ans=' '+temp+ans;
        n=ans.size();
        if(ans[0]==' ')
            return ans.substr(1,n-1);
        else
            return ans;
    }
};