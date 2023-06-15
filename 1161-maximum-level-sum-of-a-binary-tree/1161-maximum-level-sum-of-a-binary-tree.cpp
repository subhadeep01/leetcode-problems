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
    // int maxLevelSum(TreeNode* root) {
    //     pair<int,int>mx={root->val,1};
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     q.push(NULL);
    //     int s=0;
    //     int i=0;
    //     while(q.size())
    //     {
    //         TreeNode* front=q.front();
    //         q.pop();
    //         if(front==NULL)
    //         {
    //             i++;
    //             if(s>mx.first)
    //             {
    //                 mx.first=s;
    //                 mx.second=i;
    //             }
    //             s=0;
    //             if(q.size()==0) break;
    //             q.push(NULL);
    //         }
    //         else
    //         {
    //             s+=front->val;
    //             if(front->left){
    //             q.push(front->left);
    //             }
    //             if(front->right) 
    //             {
    //             q.push(front->right);
    //             }
    //        }
    //     }
    //     return mx.second;
    // }
    int maxLevelSum(TreeNode* root) {
    if (root == NULL) return 0;
        int res = 0, level = 0, global_sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size(), tmp_sum = 0;
            while (count--) {
                TreeNode* tmp = q.front();
                q.pop();
                tmp_sum += tmp->val;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            level++;
            if (tmp_sum > global_sum) 
            {
            res = level;
            global_sum =tmp_sum;
            }
        }
        return res;
    }
};