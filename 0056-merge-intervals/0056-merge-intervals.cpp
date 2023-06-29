class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int n=intervals.size();
        int f=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>end)// no overlap
            {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else
            {
                if(intervals[i][1]<=end)// complete overlap
                {
                   
                }
                else // partial overlap
                {
                    end=intervals[i][1];
                }
            }
            
        }
        
        ans.push_back({start,end});
        return ans;
    }
};