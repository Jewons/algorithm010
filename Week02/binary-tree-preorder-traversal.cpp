 //递归
class Solution {
public:
    void preOrder(TreeNode* root,std::vector<int> &result)
    {
        if(root == nullptr)
            return;
        result.push_back(root->val);
        preOrder(root->left,result);
        preOrder(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;

        preOrder(root,result);

        return result;
    }
};
//迭代 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> st;

        TreeNode* node = root;
        while(1)
        {
            if(node != nullptr)
            {
                result.push_back(node->val);
                if(node->right != nullptr)
                    st.push(node->right);
                node = node->left;
            }
            else if(st.empty())
            {
                break;
            }
            else
            {
                node = st.top();
                st.pop();
            }
        }
        return result;
    }
};