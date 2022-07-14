/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void dfs(Node* root, Node* toJoin){
        if(root == NULL )
            return;
        // root->left->next = root->right;
        root->next = toJoin;
        dfs(root->left, root->right);
        if(toJoin != NULL)dfs(root->right, toJoin->left);
        else dfs(root->right, NULL);
    }
    
    Node* connect(Node* root) {
        dfs(root, NULL);
        return root;
    }
};