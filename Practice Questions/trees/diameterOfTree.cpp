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
            left = right - NULL;
        }
};

//Method 1 : O(n^2)
int height(TreeNode *root)
{
    if (root == NULL) return 0;
    if (!root->left && !root->right) return 1;
    return 1 + max(height(root->left),height(root->right));
}
int diameter(TreeNode *root)
{
    if (root == NULL) return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));
}

//Method 2 : O(n)
int d = INT32_MIN;
int diameterTree(TreeNode *root)
{
    if (root==NULL) return 0;
    if (!root->left && !root->right) return 1;
    int lh_max = diameterTree(root->left);
    int rh_max = diameterTree(root->right);
    d = max(d, 1 + lh_max + rh_max);
    return 1 + max(lh_max, rh_max);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(80);
    root->left->left->left = new TreeNode(40);
    root->left->left->right = new TreeNode(50);
    root->left->left->left->left = new TreeNode(60);
    root->left->right->right = new TreeNode(90);
    root->left->right->right->right = new TreeNode(18);
    diameterTree(root);
    cout<<"Diameter : "<<d<<endl;
    return 0;
}
