class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       int max_time=0;
       unordered_map<int,vector<int>>m;
       for(int i=0;i<n;i++)
       {
           m[manager[i]].push_back(i);
       }
       queue<pair<int,int>>q;
       q.push({headID,0});
       while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
            int head=q.front().first;
            int tm=q.front().second;
            q.pop();
            int t=informTime[head]+tm;
            max_time=max(max_time,t);
            for(auto it: m[head])
            q.push({it,t});
            }
        }
        return max_time;
    }
};