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
    TreeNode *answer;
    //深度遍历
    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        //terminator
        if(root == nullptr)
            return false;
        //process

        //drill down
        bool lson = dfs(root->left,p,q);
        bool rson = dfs(root->right,p,q);
        if((lson && rson) ||( (root->val == p->val || root->val == q->val) && (lson || rson)) )
        {
            answer = root;
        }
        return lson || rson || (p->val == root->val || q->val == root->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return answer;
    }
};