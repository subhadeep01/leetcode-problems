class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();

        // int f=0;
        // for(auto x: citations)
        // {
        //     if(x!=0)
        //     {
        //         f=1;
        //         break;
        //     }
        // }
        // if(f==0) return 0;
        sort(citations.begin(),citations.end());
        int low=0,high=citations.back();
        int ans=0;
        while(low<=high)
        {
            int mid = (low)+(high-low)/2;
            int lb=lower_bound(citations.begin(),citations.end(),mid)-citations.begin();
            if(mid<=(n-lb))
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