/*
    You need to construct a binary tree from a string consisting of parenthesis and integers.
    The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure. 
    You always start to construct the left child node of the parent first if it exists.

    Assumptions : Tree Will Have Atmost 5 Levels
*/

#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        string data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(string data)
        {
            this->data = data;
            left = right = NULL;
        }
};

TreeNode * makeTree(string &s)
{
    vector<vector<TreeNode *>> nodesList (5);
    int curr_level = 0, itr = 0;

    //Setting Root Node
    string currVal = "";
    while(s[itr] != '(') currVal += s[itr++];
    TreeNode *rootNode = new TreeNode(currVal);
    nodesList[curr_level].push_back(rootNode);

    //Finding level of each node
    currVal = "";
    for (;itr < s.size();itr++)
    {
        if ((s[itr] == '(') || (s[itr] == ')')){
            if (currVal != "")
            {
                TreeNode *newNode = new TreeNode(currVal);
                nodesList[curr_level].push_back(newNode);
            }
            curr_level = s[itr]=='(' ? curr_level + 1 : curr_level - 1;
            currVal = "";
        }
        else{
            currVal += s[itr];
        }
    } 

    //Creating a Tree
    for (itr = 1;itr<5;itr++)
    {
        bool lchildAdded = false, rchildAdded = false;
        int k = 0;
        for (int j=0;j<nodesList[itr].size();j++)
        {
            if (!lchildAdded)
            {
                nodesList[itr-1][k]->left = nodesList[itr][j];
                lchildAdded = true;
            }else if (!rchildAdded){
                nodesList[itr-1][k]->right = nodesList[itr][j];
                rchildAdded = true;
            }
            else{
                lchildAdded = false;
                rchildAdded = false;
                k++;j--;
            }
        }
    }
    return rootNode;
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

void inOrder(TreeNode *root)
{
    if (root!=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if (root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter Input String : ";
    string s;cin>>s;
    TreeNode *root = makeTree(s);
    cout<<"Preorder : ";preOrder(root);
    cout<<"\nInorder : ";inOrder(root);
    cout<<"\nPostorder : ";postOrder(root);
    cout<<endl;
    return 0;
}
