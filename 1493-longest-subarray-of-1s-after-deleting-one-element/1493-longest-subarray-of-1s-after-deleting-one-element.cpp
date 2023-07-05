class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
         int ans=0, flip_count=0;
        int n=nums.size();
        int s=0,e=0;
        while(e<n)
        {
            if(nums[e]==1)
                e++;
            else if(nums[e]==0 && flip_count<k)
            {
                flip_count++;
                e++;
            }
            else // flip_count>=k
            {
                while(flip_count>=k)
                {
                    if(nums[s]==0)
                    flip_count--;
                    s++;
                }
                
            }
            ans=max(ans,e-s);
        }
        return ans-1;
    }
};