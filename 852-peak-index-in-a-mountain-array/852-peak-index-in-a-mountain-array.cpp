class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int low=0,high=arr.size()-1;
        int mid;int ans;
        int t= *max_element(arr.begin(),arr.end());
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr[mid]==t)
            {
                ans=mid;
                break;
            }
            else if(arr[mid]<t)
            {
            if((mid-1>=0 && arr[mid]>arr[mid-1]) ||(mid+1<arr.size() && arr[mid]<arr[mid+1]))
                    low=mid+1;
                else
                    high=mid-1;
            }
            
        }
        return ans;
    }
};