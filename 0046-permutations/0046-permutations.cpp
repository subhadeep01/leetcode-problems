class Solution {
public:
    void f(int ind, vector<int>&nums, vector<vector<int>>&ds)
    {
        if(ind==nums.size())
        {
            ds.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ds);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ds;
        f(0,nums,ds);
        return ds;
    }
};