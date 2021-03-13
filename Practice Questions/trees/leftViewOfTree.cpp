#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val)
        {
            this->val = val;
            left = right = NULL;
        }
};

void printLeftView(TreeNode *root)
{
    if (root == NULL) return;
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty())
    {
        int cnt = q.size();
        for (int i=0;i<cnt;i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (i==0) cout<<curr->val<<" ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
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
    root->left->left->right = new TreeNode(141);
    
    root->left->right->left = new TreeNode(49);
    root->left->right->right = new TreeNode(51);

    cout<<"Left View : ";
    printLeftView(root);
    cout<<endl;
    return 0;
}
