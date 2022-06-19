/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    map<pair<ListNode* , TreeNode*>, bool>dp;
    
    bool dfs(ListNode* head, TreeNode* root, ListNode* par){
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        
        if(dp.find({head, root}) != dp.end())
            return dp[{head,root}];
        
        bool ans = false;
        if(head->val == root->val){
            ans = ans || dfs(head->next, root->left, par);
            ans = ans || dfs(head->next, root->right, par);
        }
        ans = ans || dfs(par, root->left, par);
        ans = ans || dfs(par, root->right, par);
        return  dp[{head,root}] = ans;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root, head);
    }
};