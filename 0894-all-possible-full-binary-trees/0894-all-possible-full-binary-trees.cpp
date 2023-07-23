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
    vector<TreeNode*> f(int n)
    {
        vector<TreeNode*>ans;
        if(n==1) 
        {
        ans.push_back(new TreeNode(0));
        return ans;
        }
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*>left=f(i);
            vector<TreeNode*>right=f(n-1-i);
            for(auto l: left)
            {
                for(auto r: right)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return f(n);
    }
};