class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>buy)
            {
                ans=max(ans,prices[i]-buy);
            }
            else
                buy=prices[i];
        }
        return ans;
    }
};