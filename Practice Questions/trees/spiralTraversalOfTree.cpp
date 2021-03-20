#include<iostream>
#include<stack>
#include<queue>
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

//Method1
void spiralTraversal(TreeNode *root)
{
    if (root==NULL) return;
    queue<TreeNode *> q;
    q.push(root);

    stack<TreeNode *> s;
    bool reverse = false;

    while(!q.empty())
    {
        int cnt = q.size();
        for (int i=0;i<cnt;i++)
        {
            TreeNode *curr = q.front();q.pop();
            if (reverse) s.push(curr);
            else cout<<curr->data<<" ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (reverse){
            while(!s.empty())
            {
                cout<<(s.top()->data)<<" ";
                s.pop();
            }
        }

        reverse = !reverse;
    }
}

//Method 2
void spiralT(TreeNode *root)
{
    if (root == NULL) return;
    stack<TreeNode *> s1,s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            TreeNode *curr = s1.top();s1.pop();
            cout<<curr->data<<" ";
            if (curr->left) s2.push(curr->left);
            if (curr->right) s2.push(curr->right);
        }

        while(!s2.empty())
        {
            TreeNode *curr = s2.top();s2.pop();
            cout<<curr->data<<" ";
            if (curr->right) s1.push(curr->right);
            if (curr->left) s1.push(curr->left);
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    cout<<"Spiral Traversal : ";
    //spiralTraversal(root);
    spiralT(root);
    cout<<endl;
    return 0;
}
