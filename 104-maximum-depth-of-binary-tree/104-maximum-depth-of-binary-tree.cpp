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
    void dfs(TreeNode* root, int &depth, int &ans){
        if(root == NULL)
            return;
        ans = max(ans, depth+1);
        depth++;
        dfs(root->left, depth, ans);
        dfs(root->right, depth, ans);
        depth--;
        return;
    }
    int maxDepth(TreeNode* root) {
        int ans = {};
        int depth = 0;
        dfs(root, depth, ans);
        return ans;
    }
};