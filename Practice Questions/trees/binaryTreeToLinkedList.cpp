#include<iostream>
#include<vector>
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

void inOrderTraversal(TreeNode *root, vector<TreeNode *> &list)
{
    if (root!=NULL)
    {
        inOrderTraversal(root->left, list);
        list.push_back(root);
        inOrderTraversal(root->right, list);
    }
}

void printLL(TreeNode *root)
{
    vector<TreeNode *> DLL;
    inOrderTraversal(root, DLL);

    TreeNode *head;

    for (int i=0;i<DLL.size();i++)
    {
        DLL[i]->left = i==0 ? NULL : DLL[i-1];
        DLL[i]->right = i==DLL.size()-1 ? NULL : DLL[i+1];
    }

    head = DLL[0];

    cout<<"NULL"<<" <=> ";
    while(head!=NULL)
    {
        cout<<head->data<<" <=> ";
        head = head->right;
    }
    cout<<"NULL"<<endl;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);
    cout<<"Doubly Linked List : - "<<endl;
    printLL(root);
    return 0;
}
