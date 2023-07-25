class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int n=nums.size();
        long long curr_sum=0;
        long long res=1;
        while(j<n)
        {
            curr_sum+=nums[j];
            
            while(nums[j] > (curr_sum + k) / (j - i + 1))
            {
                curr_sum-=nums[i];
                i++;
            }
            j++;
            
            res=max(res,(long long)j-i);
        }
        return res;
    }
};