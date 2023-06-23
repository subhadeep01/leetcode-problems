class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            int start=i;
            while(i+1<n && prices[i]<prices[i+1])
                i++;
            if(i!=start && prices[start]<prices[i])
                ans+=(prices[i]-prices[start]);
        }
        return ans;
    }
};