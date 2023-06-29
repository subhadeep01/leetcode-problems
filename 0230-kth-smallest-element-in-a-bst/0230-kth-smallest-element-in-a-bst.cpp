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
    vector<int>v;
    int ans;
    void f(TreeNode* root,int c, int k)
    {
        if(root==NULL) return;
        f(root->left,c,k);
        v.push_back(root->val);
        c++;
        if(c==k)
        ans=root->val;
        f(root->right,c,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return 0;
        f(root,0,k);
        return v[k-1];
    }
};