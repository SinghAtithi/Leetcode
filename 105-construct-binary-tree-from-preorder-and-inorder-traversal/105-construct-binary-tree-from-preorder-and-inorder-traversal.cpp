class Solution {
    unordered_map<int, int> posMap;
    int nxtNode = 0, currVal;
    TreeNode* dfs(vector<int> &preorder, int st, int ed) {
        if (st > ed) return NULL;
        currVal = preorder[nxtNode++];
        int currPos = posMap[currVal];
        return new TreeNode(
            currVal,
            dfs(preorder, st, currPos - 1),
            dfs(preorder, currPos + 1, ed)
        );
    }
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int len = inorder.size() - 1;
        for (int i = 0; i <= len; i++) {
            posMap[inorder[i]] = i;
        }
        return dfs(preorder, 0, len);
    }
};