#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node *genTree()
{
    queue<Node *> q;
    Node *root = NULL;
    
    int data;
    cout<<"Enter root : ";
    cin>>data;
    
    if (data == -1)
        return root;
    root = new Node(data);
    q.push(root);
    
    while(!q.empty())
    {
        Node *curr = q.front();q.pop();
        int lchild, rchild;
        
        cout<<"Left child of "<<curr->data<<" : ";
        cin>>lchild;
        if (lchild != -1)
        {
            curr->left = new Node(lchild);
            q.push(curr->left);
        }
        
        cout<<"Right child of "<<curr->data<<" : ";
        cin>>rchild;
        if (rchild != -1)
        {
            curr->right = new Node(rchild);
            q.push(curr->right);
        }
    }
    return root;    
}

bool isMirror(Node *root1, Node *root2)
{
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return root1->data == root2->data && isMirror(root1->left, root2->right) 
                                      && isMirror(root1->right, root2->left);
}

bool isSymmetric(Node* root)
{
	return isMirror(root, root);
}

int main()
{
  Node *root = genTree();
  if (isSymmetric(root)
  {
      cout<<"Yes"<<endl;
  }else{
      cout<<"No"<<endl;
  } 
  return 0;
}
