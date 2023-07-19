#define ll long long
class Solution {
public:
    bool check(ll x, vector<int>&piles, ll h)
    {
        ll time=0;
        for(auto it: piles)
        {
            if(it%x==0)
                time+=it/x;
            else
                time+=(it/x)+1;
        }
        return (time<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int no_of_piles=piles.size();
        ll low=1,high=1e10;
        ll k;
        while(low<=high)
        {
            ll mid = low+(high-low)/2;
            if(check(mid,piles,h))
            {
                k=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return k;
    }
};