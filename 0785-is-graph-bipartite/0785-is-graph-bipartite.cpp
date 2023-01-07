class Solution {
public:
    bool dfs(int node, vector<int>adj[],vector<int>&color,int curr_color)
    {
        color[node]=curr_color;

        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,adj,color,!curr_color)==false) return false;
            }
            else if(color[node]==color[it]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
           adj[i]=graph[i];
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
               if(dfs(i,adj,color,0)==false) return false;
            }
        }
        return true;
    }
};