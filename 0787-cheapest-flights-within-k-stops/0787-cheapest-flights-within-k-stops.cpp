class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
          vector<pair<int,int>>adj[n];
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,2e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        // steps,node,dist
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            int steps=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            
            q.pop();
            
            if(steps>K) continue;
            
            for(auto it: adj[node])
            {
                int v=it.first;
                int cost=it.second;
                if(cost+dis<dist[v] && steps<=K)
                {
                    dist[v]=cost+dis;
                    q.push({steps+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==2e9) return -1;
        return dist[dst];
    }
};