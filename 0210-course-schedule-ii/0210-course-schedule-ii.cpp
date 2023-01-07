class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
          vector<int>adj[V];
	    for(auto x: prerequisites)
	    {
	        adj[x[1]].push_back(x[0]);
	    }
	   vector<int>indegree(V,0);
	   for(int i=0;i<V;i++)
	   {
	       for(auto it: adj[i])
	       indegree[it]++;
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0)
	       q.push(i);
	   }
	   vector<int>topo;
	   while(!q.empty())
	   {
	       int node=q.front();
	       topo.push_back(node);
	       q.pop();
	       for(auto it: adj[node])
	       {
	           indegree[it]--;
	           if(indegree[it]==0) q.push(it);
	       }
	   }
	   if(topo.size()<V){
	       topo.clear();
	       return topo;
	   }
	   return topo;
    }
};