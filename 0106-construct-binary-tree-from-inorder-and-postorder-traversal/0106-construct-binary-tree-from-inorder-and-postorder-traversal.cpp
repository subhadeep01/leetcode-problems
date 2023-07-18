class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeHelper(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd,
                              unordered_map<int, int>& mp) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int rootInd = mp[rootVal];
        int numLeft = rootInd - inStart;

        root->left = buildTreeHelper(inorder, inStart, rootInd - 1, postorder, postStart, postStart + numLeft - 1, mp);
        root->right = buildTreeHelper(inorder, rootInd + 1, inEnd, postorder, postStart + numLeft, postEnd - 1, mp);

        return root;
    }
};
