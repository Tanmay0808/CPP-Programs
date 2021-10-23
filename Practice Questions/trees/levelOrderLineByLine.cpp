#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int value)
        {
            val = value;
            left = right = NULL;
        }
};

//Method 1
void printBFS(TreeNode *root)
{
    queue<TreeNode *>q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1)
    {
        TreeNode *curr = q.front();q.pop();
        if (curr == NULL){
            cout<<endl;
            q.push(NULL);
        }
        else{
            cout<<curr->val<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

//Method 2
void printBFSLineByLine(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();
        for (int i=0;i<count;i++)
        {
            TreeNode *curr = q.front();q.pop();
            cout<<curr->val<<" ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout<<endl;
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
    root->left->left->right = new TreeNode(41);
    
    root->left->right->left = new TreeNode(49);
    root->left->right->right = new TreeNode(51);

    cout<<"Method 1 : -\n";
    printBFS(root);
    cout<<"\nMethod 2 : -\n";
    printBFSLineByLine(root);
    return 0;
}
