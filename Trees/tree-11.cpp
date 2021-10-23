//convert binary tree to doubly linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left,*right;
    Node(int k){
        key = k;
        left=right=NULL;
    }
};

void traverseDLL(Node *head){
    if(head==NULL) return;
    cout<<head->key<<" ";
    traverseDLL(head->right);
}

Node* convertToDLL(Node *root){
    if(root==NULL)return root;
    static Node* prev = NULL;
    Node *head=convertToDLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    convertToDLL(root->right);
    return head;
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    
    Node *head = convertToDLL(root);
    traverseDLL(head);
}