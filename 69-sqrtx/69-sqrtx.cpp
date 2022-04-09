class Solution {
public:
    int mySqrt(int num) {
        long long low=1,high=num;
        long long ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(mid*mid<=num)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};