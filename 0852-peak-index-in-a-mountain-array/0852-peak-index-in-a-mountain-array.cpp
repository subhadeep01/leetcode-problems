class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        int res;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid]<arr[mid+1])
            {
                low=mid+1;
                res=low;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
};