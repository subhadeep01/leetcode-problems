class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int>m;
        // for(auto x: nums)
        //     m[x]++;
        // for(auto x: m)
        // {
        //     if(x.second==1)
        //         return x.first;
        // }
        // return -1;
        int ones=0,twos=0;
        for(auto x: nums)
        {
            ones = (ones^x) & ~twos;
            twos = (twos^x) & ~ones;
        }
        return ones;
    }
};