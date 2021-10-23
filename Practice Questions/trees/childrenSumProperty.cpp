#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};

bool isChildSum(TreeNode *root)
{
    if (root == NULL || (!root->left && !root->right)) return true;
    if (root->data != ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0)))
        return false;
    else
        return isChildSum(root->left) && isChildSum(root->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    isChildSum(root) ? cout<<"YES\n" : cout<<"NO\n";
    return 0;
}
