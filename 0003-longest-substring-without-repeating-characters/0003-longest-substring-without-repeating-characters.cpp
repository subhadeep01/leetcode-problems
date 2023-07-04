class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hashmap(256,-1);
        int l=0,r=0;
        int n=s.size();
        int len=0;
        while(r<n)
        {
            if(hashmap[s[r]]!=-1)
                l=max(l,hashmap[s[r]]+1);
            hashmap[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};