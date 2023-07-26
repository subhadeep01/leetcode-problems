class Solution {
public:
    bool check(int mid, vector<int>&bloomDay, int m, int k)
    {
        int l=0,r=0;
        int n=bloomDay.size();
        int ans=0;
        while(r<n)
        {        
            if(bloomDay[r]<=mid)
            {
                r++;
            }
            else
            {
                r++;
                l=r;
            }
            if((r-l)==k)
            {
               ans++;
               l=r;
            }
           
        }
        return (ans>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((n/m)<k) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,bloomDay,m,k))
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