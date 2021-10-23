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

int res = 0;
int burnTime(TreeNode *root, int leaf, int &dist)
{
    if (root==NULL) return 0;
    if (root->data == leaf){dist=0;return 1;}
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);
    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return 1 + max(lh, rh);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->left->left = new TreeNode(30);
    root->left->left->right = new TreeNode(50);
    root->left->left->left = new TreeNode(40);
    root->left->left->left->left = new TreeNode(60);
    root->left->left->left->left->left = new TreeNode(70);
    int dist = -1;
    burnTime(root, 50, dist);
    cout<<"Total Time : "<<res<<"s\n";
    return 0;
}
