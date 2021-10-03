class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(!st.empty() || root!=NULL)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
                
            }
            else{
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
                
                
            }
        }
        return ans;
    }
};