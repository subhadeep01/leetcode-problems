class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,2e9));
        dist[0][0]=0;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
    
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            for(int i=-1;i<2;i++)
            {
                for(int j=-1;j<2;j++)
                {
                    int nr=row+i;
                    int nc=col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0)
                    {
                        if(distance+1<dist[nr][nc])
                        {
                            dist[nr][nc]=distance+1;
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                    }
                }
            }
                
        }
        if(dist[n-1][n-1]==2e9) return -1;
        return dist[n-1][n-1]+1;
    }
};