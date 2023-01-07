class Solution {
public:
     bool dfs(int node, vector<int>&vis, vector<int>&dfsvis, vector<vector<int>>&graph)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsvis,graph)) return true;
            }
            else if(vis[it]==dfsvis[it] && vis[it]==1) return true;
        }
        dfsvis[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
         vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        bool f=false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
              if(dfs(i,vis,dfsvis,graph))
              {
                  f=true;
              }
            }
            
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(dfsvis[i]==0)
            ans.push_back(i);
        }
        return ans;
    }
};