class Solution {
public:
    int count(vector<vector<int>>& matrix, int x)
    {
        // this function will return how many elements are <= x 
        int cnt=0;
        for(int i=0;i<matrix.size();i++)
        {
            cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),x)-matrix[i].begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int res;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(count(matrix,mid)<k)
                low=mid+1;
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};