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
    vector<TreeNode*> f(int start, int end)
    {
        vector<TreeNode*>ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        if(start==end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>leftSubtree = f(start,i-1);
            vector<TreeNode*>rightSubtree = f(i+1,end);
            for(auto l: leftSubtree)
            {
                for(auto r: rightSubtree)
                {
                    TreeNode* root= new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};