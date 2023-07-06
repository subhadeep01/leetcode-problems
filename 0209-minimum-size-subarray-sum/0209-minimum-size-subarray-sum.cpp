class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        long long s=0;
        int ans=INT_MAX;
        while(j<n)
        {
            s+=nums[j];
            if(s>=target)
            {
               while(s>=target)
               {
                   s-=nums[i];
                   i++;
               }
              ans=min(ans,j-i+2);
            }
            j++;
        }
        return (ans==INT_MAX)?0:ans;
    }
};