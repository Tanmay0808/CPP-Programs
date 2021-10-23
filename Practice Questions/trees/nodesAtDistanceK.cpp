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

void nodesAtDistanceK(TreeNode *root, int k)
{
    if (root == NULL) return;
    if (k==0) cout<<root->val<<" ";
    else{
        nodesAtDistanceK(root->left, k-1);
        nodesAtDistanceK(root->right, k-1);
    }
}

int main()
{
    int k = 3;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);
    cout<<"Nodes At Distance "<<k<<" From Root : ";
    nodesAtDistanceK(root, k);
    cout<<endl;
    return 0;
}

