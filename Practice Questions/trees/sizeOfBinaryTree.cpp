#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

int sizeOfTree(TreeNode *root)
{
    if (root == NULL) return 0;
    if (!root->left && !root->right) return 1;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    root->left->left->left = new TreeNode(39);
    root->left->left->right = new TreeNode(41);
    
    root->left->right->left = new TreeNode(49);
    root->left->right->right = new TreeNode(51);

    cout<<"Size : "<<sizeOfTree(root)<<endl;
    return 0;
}
