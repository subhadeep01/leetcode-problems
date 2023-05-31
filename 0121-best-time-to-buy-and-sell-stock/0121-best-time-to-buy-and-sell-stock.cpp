class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0; int prev=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i]-prev>0)
                ans=max(ans,prices[i]-prev);
            else
                prev=prices[i];
        }
        return ans;
    }
};