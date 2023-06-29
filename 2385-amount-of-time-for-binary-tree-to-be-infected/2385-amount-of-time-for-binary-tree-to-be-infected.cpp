/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int tm=0;
    void buildGraph(TreeNode* root, vector<int>adj[])
    {
        if(root==NULL) return;
        
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        
        buildGraph(root->left,adj);
        buildGraph(root->right,adj);
        
    }
    void bfs(int start, vector<int>&visited, vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int node=q.front().first;
                visited[node]=1;
                int t=q.front().second;
                q.pop();
                tm=max(tm,t);
                for(auto it: adj[node])
                {
                    if(!visited[it])
                    q.push({it,t+1});
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<int>adj[100005];
        buildGraph(root,adj);
        vector<int>visited(100005,0);
        bfs(start,visited,adj);
        return tm;
    }
};