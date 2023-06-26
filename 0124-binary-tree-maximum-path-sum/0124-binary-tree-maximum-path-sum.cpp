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
    int f(TreeNode* root, int &result)
    {
        if(root==NULL) return 0;
        int left=f(root->left,result);
        int right=f(root->right,result);
        int ms=max(root->val, max(left,right)+root->val);
        int mr=max(ms,(left+right+root->val));
        result=max(result,mr);
        return ms;
    }
    int maxPathSum(TreeNode* root) {
        // logic watch techdose
        int result=INT_MIN;
        f(root,result);
        return result;
    }
};