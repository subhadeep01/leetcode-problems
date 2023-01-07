class Solution {
public:
    int strStr(string haystack, string needle) {
        int start=needle[0];
        for(int i=0;i<haystack.size();i++)
        {
            if(haystack[i]==start)
            {
                int x=i;
                int y=0;
                while(x<haystack.size() && y<needle.size() && haystack[x]==needle[y])
                {
                    x++;
                    y++;
                }
                if(y==needle.size())
                return i;
            }
        }
        return -1;
    }
};