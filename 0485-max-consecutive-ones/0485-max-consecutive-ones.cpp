class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,ones=0;
        for (auto x: nums)
        {
            if(x==1)
            ones++;
            else
            ones=0;
            ans=max(ans,ones);
        }
        return ans;
    }
};