class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int intervals_size=intervals.size();
        if(intervals_size==1) return 0;
        int erase=0;
        int prev_end=intervals[0][1];
        for(int i=1;i<intervals_size;i++)
        {
            if(intervals[i][0]<prev_end) // overlapping
            {
                if(intervals[i][1]>prev_end)
                {
                    // prev_end remains as it is
                }
                else
                {
                    prev_end=intervals[i][1];
                }
                erase++;
            }
            else
                prev_end=intervals[i][1];
        }
        return erase;
    }
};