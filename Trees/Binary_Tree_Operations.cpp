#include<iostream>
#include "headerfunctions.h"
using namespace std;

class BinaryTree
{
   private:
      TreeNode *root;
      QueueTree q;
      StackTree s;
   public:
      BinaryTree()
      {
         root = NULL;
      }
      ~BinaryTree(){
         deleteTree(root);
      }
      TreeNode * getRoot(){return root;}
      void createTree();
      void deleteTree(TreeNode *p);
      void preOrder(TreeNode *p);
      void inOrder(TreeNode *p);
      void postOrder(TreeNode *p);
      void iterPreorder(TreeNode *p);
      void iterInorder(TreeNode *p);
      void iterPostorder(TreeNode *p);
      void levelOrder(TreeNode *p);
      int countNodes(TreeNode *p);
      int heightOfTree(TreeNode *p);
      int sumOfNodes(TreeNode *p);
      int leafNodes(TreeNode *p);
};

void BinaryTree::createTree()
{
   int data;
   if (root == NULL)
   {
      cout<<"\nEnter Data For Root Node : ";
      cin>>data;
      root = new TreeNode;
      root->lchild = root->rchild = NULL;
      root->data = data;
      q.enqueue(root);
   }

   TreeNode *p,*t;
   while(!q.isEmpty())
   {
      p = q.dequeue();
      cout<<"\nEnter Data For Left Child Of  "<<p->data<<" : ";
      cin>>data;
      if (data != -1)
      {
         t = new TreeNode;
         t->data = data;
         t->lchild = t->rchild = NULL;
         p->lchild = t;
         q.enqueue(t);
      }
      cout<<"\nEnter Data For Right Child Of  "<<p->data<<" : ";
      cin>>data;
      if (data != -1)
      {
         t = new TreeNode;
         t->data = data;
         t->lchild = t->rchild = NULL;
         p->rchild = t;
         q.enqueue(t);
      }
   }
   cout<<"\nTree Creation Successful"<<endl;
}

void BinaryTree::deleteTree(TreeNode *p)
{
   if (p == NULL)
       return;
   else{
      deleteTree(p->lchild);
      if (p->rchild != NULL)
         deleteTree(p->rchild);
      delete p;
   }
}

void BinaryTree::preOrder(TreeNode *p)
{
   if (p!=NULL)
   {
      cout<<p->data<<"  ";
      preOrder(p->lchild);
      preOrder(p->rchild);
   }
}

void BinaryTree::inOrder(TreeNode *p)
{
   if (p!=NULL)
   {
      inOrder(p->lchild);
      cout<<p->data<<"  ";
      inOrder(p->rchild);
   }
}

void BinaryTree::postOrder(TreeNode *p)
{
   if (p!=NULL)
   {
      postOrder(p->lchild);
      postOrder(p->rchild);
      cout<<p->data<<"  ";
   }
}

void BinaryTree::iterPreorder(TreeNode *p)
{
   while (p!=NULL || !s.isEmpty())
   {
      if (p!=NULL)
      {
         cout<<p->data<<"  ";
         s.push(p);
         p = p->lchild;
      }
      else
      {
         p = s.pop();
         p = p->rchild;
      }
   }
   cout<<endl;
}

void BinaryTree::iterInorder(TreeNode *p)
{
   while (p!=NULL || !s.isEmpty())
   {
      if (p!=NULL)
      {
         s.push(p);
         p = p->lchild;
      }
      else
      {
         p = s.pop();
         cout<<p->data<<"  ";
         p = p->rchild;
      }
   }
   cout<<endl;
}

void BinaryTree::iterPostorder(TreeNode *p)
{
   while (p!=NULL || !s.isEmpty())
   {
      if (p!=NULL)
      {
         s.push(p);
         s.push(p);
         p = p->lchild;
      }
      else
      {
         if (s.isEmpty()){break;}
            p = s.pop();
         if (!s.isEmpty() && p == s.stackTop()){
            p=p->rchild;
         }
         else
         {
            cout<<p->data<<"  ";
            p = NULL;
         }
      }
   }
   cout<<endl;
}

void BinaryTree::levelOrder(TreeNode *p)
{
   QueueTree q;
   cout<<p->data<<"  ";
   q.enqueue(p);
   while (!q.isEmpty())
   {
      p = q.dequeue();
      if (p->lchild)
      {
         cout<<p->lchild->data<<"  ";
         q.enqueue(p->lchild);
      }
      if (p->rchild)
      {
         cout<<p->rchild->data<<"  ";
         q.enqueue(p->rchild);
      }
   }
   cout<<endl;
}

int BinaryTree::countNodes(TreeNode *p)
{
   int x=0,y=0;
   if (p!=NULL)
   {
      x = countNodes(p->lchild);
      y = countNodes(p->rchild);
      return x + y + 1;
   }
   return 0;
}

int BinaryTree::heightOfTree(TreeNode *p)
{
   int x=0,y=0;
   if (p!=NULL)
   {
      x = heightOfTree(p->lchild);
      y= heightOfTree(p->rchild);
      return (x > y) ? x+1 : y+1;
   }
   return -1;
}

int BinaryTree::sumOfNodes(TreeNode *p)
{
   int x=0,y=0;
   if (p!=NULL)
   {
      x = sumOfNodes(p->lchild);
      y = sumOfNodes(p->rchild);
      return x + y + p->data;
   }
   return 0;
}

int BinaryTree::leafNodes(TreeNode *p)
{
   if (p!=NULL)
   {
      return (!p->lchild && !p->rchild) ? leafNodes(p->lchild) + leafNodes(p->rchild) + 1 : leafNodes(p->lchild) + leafNodes(p->rchild);
   }
   return 0;
}

int main()
{
   cout<<"Creating A Binary Tree : "<<endl;
   BinaryTree T;
   T.createTree();

   cout<<"\nRecursive Pre-Order Traversal : "<<endl;
   T.preOrder(T.getRoot());

   cout<<"\n\nRecursive In-Order Traversal : "<<endl;
   T.inOrder(T.getRoot());

   cout<<"\n\nRecursive Post-Order Traversal : "<<endl;
   T.postOrder(T.getRoot());

   cout<<"\n\nIterative Pre-Order Traversal : "<<endl;
   T.iterPreorder(T.getRoot());

   cout<<"\nIterative In-Order Traversal : "<<endl;
   T.iterInorder(T.getRoot());

   cout<<"\n\nIterative Post-Order Traversal : "<<endl;
   T.iterPostorder(T.getRoot());

   cout<<"\nLevel Order Traversal : "<<endl;
   T.levelOrder(T.getRoot());

   cout<<"\nNo. Of Nodes : "<<T.countNodes(T.getRoot())<<endl;

   cout<<"\nHeight Of Binary Tree : "<<T.heightOfTree(T.getRoot())<<endl;

   cout<<"\nSum Of Nodes : "<<T.sumOfNodes(T.getRoot())<<endl;

   cout<<"\nNo. Of Leaf Nodes : "<<T.leafNodes(T.getRoot())<<endl;

   return 0;
}
