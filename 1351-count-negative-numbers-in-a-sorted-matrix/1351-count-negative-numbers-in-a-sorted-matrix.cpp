class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            int low=0,high=m-1;
            int pos=m+1;
            while(low<=high)
            {
                int mid=(low)+(high-low)/2;
                if(grid[i][mid]<0)
                {
                    pos=min(pos,mid);
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            c+=max(0,(m-pos));
        }
        return c;
    }
};