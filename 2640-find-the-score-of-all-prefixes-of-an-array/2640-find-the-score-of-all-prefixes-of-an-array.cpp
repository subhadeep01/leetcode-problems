class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        // [2 3 7 5 10]
        // [4 6 14 12 20]
        // [4 10 24 36 56]
        int mx=nums[0];
        int n=nums.size();
        vector<long long>pre(n,0);
        pre[0]=nums[0]+mx;
        for(int i=1;i<n;i++)
        {
            mx=max(mx,nums[i]);
            pre[i]=nums[i]+mx;
        }
        vector<long long>ans(n,0);
        ans[0]=pre[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=pre[i]+ans[i-1];
        }
        return ans;
    }
};