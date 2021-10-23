#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data){
            this->data = data;
            left = right = NULL;
        }
};

//Method 1
bool findPath(TreeNode *root, vector<TreeNode *> &p, int n)
{
    if (root == NULL) return false;
    p.push_back(root);
    if (root->data == n) return true;

    if (findPath(root->left,p,n) || findPath(root->right,p,n))
        return true;
    p.pop_back();
    return false;
}

TreeNode * LCA_Tree(TreeNode *root, int n1, int n2)
{
    if (root==NULL) return NULL;
    vector<TreeNode *> path1,path2;
    if (findPath(root,path1,n1)==false || findPath(root,path2,n2)==false)
        return NULL;
    for (int i=0;i<max(path1.size()-1,path2.size()-1);i++)
    {
        if (path1[i+1]!=path2[i+1])
            return path1[i];
    }
    return NULL;
}

//Method 2
TreeNode * LCA_T(TreeNode *root, int n1, int n2){
    if (root==NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    TreeNode *llca = LCA_T(root->left, n1, n2);
    TreeNode *rlca = LCA_T(root->right, n1, n2);
    if (llca && rlca) return root;
    else if (llca) return llca;
    return rlca;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->left->left = new TreeNode(60);
    root->right->right = new TreeNode(50);
    root->right->right->left = new TreeNode(70);
    root->right->right->right = new TreeNode(80);
    cout<<"LCA : "<<LCA_T(root,20,70)->data<<endl;
    return 0;
}
