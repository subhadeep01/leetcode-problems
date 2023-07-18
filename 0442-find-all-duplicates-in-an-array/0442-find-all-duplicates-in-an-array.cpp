class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto x: nums)
        {
            if(mp.find(x)==mp.end())
            {
              
            }
            else
            {
                ans.push_back(x);
            }
            mp[x]++;
        }
        return ans;
    }
};