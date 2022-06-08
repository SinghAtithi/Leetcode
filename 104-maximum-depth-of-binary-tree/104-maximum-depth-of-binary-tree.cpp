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
    void dfs(TreeNode* root, int depth, int &ans){
        if(root == NULL)
            return;
        ans = max(ans, depth+1);
        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);

    }
    int maxDepth(TreeNode* root) {
        int ans = {};
        dfs(root, 0, ans);
        return ans;
    }
};