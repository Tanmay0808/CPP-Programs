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

TreeNode * cTreePreOrder(int in[], int pre[], int is, int ie)
{
    static int preIndex = is;
    if (is > ie) return NULL;
    TreeNode *root = new TreeNode(pre[preIndex++]);

    int index;
    for (int i=is;i<=ie;i++)
        if (in[i] == root->data)
        {
            index = i;
            break;
        }

    root->left = cTreePreOrder(in, pre, is, index-1);
    root->right = cTreePreOrder(in, pre, index+1, ie);
    return root;
}

TreeNode * cTreePostOrder(int in[], int post[], int is, int ie)
{
    static int postIndex = ie;
    if (is > ie || postIndex < 0) return NULL;
    TreeNode *root = new TreeNode(post[postIndex--]);

    int index;
    for (int i=is;i<=ie;i++)
        if (in[i] == root->data)
        {
            index = i;
            break;
        }
    root->right = cTreePostOrder(in, post, index+1, ie);
    root->left = cTreePostOrder(in, post, is, index-1);
    return root;
}

void preOrder(TreeNode *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int in[] = {40,20,50,10,30,80,70,90},
        //pre[] = {10,20,40,50,30,70,80,90};
        post[] = {40,50,20,80,90,70,30,10};
    cout<<"Pre Order Traversal : ";
    preOrder(cTreePostOrder(in, post, 0, 7));
    cout<<endl;
    return 0;
}

