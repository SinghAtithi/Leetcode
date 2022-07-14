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
    
    TreeNode* build(vector<int>&preOrder, int &ind, int maxi){
        
        if(ind >= preOrder.size() || preOrder[ind] >= maxi)
            return NULL;
        
        TreeNode* root = new TreeNode(preOrder[ind++]);
        root->left = build(preOrder, ind, preOrder[ind - 1]);
        root->right = build(preOrder, ind , maxi);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(preorder, ind, INT_MAX);
    }
};