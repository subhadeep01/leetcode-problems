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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                level.push_back(temp->val);
            }
            if(!LeftToRight)
            reverse(level.begin(),level.end());
            ans.push_back(level);
            LeftToRight=!LeftToRight;
        }
        return ans;
    }
};