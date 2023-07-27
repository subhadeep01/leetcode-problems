class Solution {
public:
    bool check(int x, vector<int>&weights, int days)
    {
        int day=0;
        int sum=0;
        for(auto wt: weights)
        {
            sum+=wt;
            if(sum<=x)
            {
                continue;
            }
            else
            {
                day++;
                sum=wt;
            }
        }
        if(sum>0 && sum<=x) day++;
        return (day<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low=*max_element(weights.begin(),weights.end()),high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,weights,days))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};