#include<bits/stdc++.h>
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<=2) return true;
        int i=0,j=1;
        while(j<nums.size())
        {
            if(nums[i]+nums[j]>=m) return true;
            i++;
            j++;
        }
        return false;
    }
};