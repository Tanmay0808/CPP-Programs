#include<iostream>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val)
        {
            this->val = val;
            this->left = this->right = NULL;
        }
};

int heightOfBInaryTree(TreeNode *root)
{
    if (root == NULL) return 0;
    if (!root->left && !root->right) return 1;
    return 1 + max(heightOfBInaryTree(root->left), heightOfBInaryTree(root->right));
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->right->right = new TreeNode(25);
    root->right->right->left = new TreeNode(20);
    cout<<"\nHeight : ";
    cout<<heightOfBInaryTree(root)<<endl;
    return 0;
}

