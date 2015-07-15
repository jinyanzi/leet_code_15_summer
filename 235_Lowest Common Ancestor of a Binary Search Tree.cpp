/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root is NULL or p and q are NULL
        if(!root || (!p && !q)) 
            return NULL;
        
        if(!p)  return q;
        if(!q)  return p;
        
        TreeNode* min_node = (p->val <= q->val ? p : q);
        TreeNode* max_node = (p->val > q->val ? p : q);
        
        // p and q in left and right each, that is the node
        if(min_node->val <= root->val && max_node->val >= root->val )
            return root;
        // if p and q all in the same descendant node, keep looking down
        if(max_node->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        if(min_node->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
    }
};