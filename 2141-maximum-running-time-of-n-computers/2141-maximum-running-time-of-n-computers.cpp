class Solution {
public:
    #define ll long long
    bool check(ll x, vector<int>&batteries, int n)
    {
        ll c=0;
        ll ind=-INT_MAX;
        for(int i=0;i<batteries.size();i++)
        {
            if(batteries[i]<x)
            {
                if(ind==-INT_MAX) ind=i;
                c+=batteries[i];
            }
        }
        if(ind==-INT_MAX) return 1;
        if(n>ind)
        {
        ll ans=c/(n-ind);
        return (ans>=x);
        }
        return 1;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
       sort(batteries.rbegin(),batteries.rend());
       long long low=1,high=1e18;
       long long ans=1;
       while(low<=high)
       {
           long long mid=low+(high-low)/2;
           if(check(mid,batteries,n))
           {
               ans=max(ans,mid);
               low=mid+1;
           }
           else
               high=mid-1;
       }
       return ans;
    }
};