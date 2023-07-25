class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
    int n=arr.size();
    int res=n;
    int low=0,high=n-1;
	while(low<=high)
	{
		int mid =(low+high)>>1;
		if(arr[mid]>=x)
		{
			res=min(res,mid);
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return res;
    }
};