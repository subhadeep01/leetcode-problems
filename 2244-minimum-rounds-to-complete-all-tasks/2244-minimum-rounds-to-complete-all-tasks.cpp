class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int,int>mp;
        for(auto it: tasks)
        {
            mp[it]++;
        }
        for(auto x: mp)
        {
            if(x.second==1) return -1;
            if(x.second%3==0)
            ans+=(x.second/3);
            else
            ans+=(x.second/3)+1;
        }
        return ans;
    }
};