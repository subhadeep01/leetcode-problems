class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto i:nums)
            x^=i;
        long long first_set_bit=(x & (x-1)) ^ x;
        int ans1=0,ans2=0;
        for(auto i: nums)
        {
            if(i&first_set_bit)
                ans1^=i;
            else
                ans2^=i;
        }
        vector<int>ans{ans1,ans2};
        return ans;
    }
};