class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
      unordered_map<string,int>mp;
      for(auto forbiddenString : forbidden)
         mp[forbiddenString]=1;
        int i=word.size()-1,j=word.size()-1;
        int ans=-1;
        while(i>=0)
        {
            string temp="";
            for(int k=i;k<=min(i+10,j);k++)
            {
                temp+=word[k];
                if(mp.find(temp)!=mp.end())
                {
                    j=k-1;
                    break;
                }
            }
            ans=max(ans,j-i+1);
            i--;
        }
        return ans;
    }
};