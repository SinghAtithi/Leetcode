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
    
    void dfs(TreeNode* root, int &ans, int &k){
        if(root == NULL || ans != -1)
            return;
        dfs(root->left, ans, k);
        k--;
        if(k == 0)
            ans = root->val;
        dfs(root->right, ans, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        int ans = -1;
        dfs(root, ans, k);
        return ans;
    }
};