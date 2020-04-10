#include<iostream>
#include<limits.h>
using namespace std;

class BSTNode
{
   public:
      BSTNode *lchild;
      int data;
      BSTNode *rchild;
};

class StackTree
{
  private:
     class Node{
        public:
           BSTNode *data;
           Node *next;
     };
     Node *top;
   public:
      StackTree(){top=NULL;}
      ~StackTree()
      {
         while(top)
         {
            Node *tmp = top;
            top = top->next;
            delete tmp;
         }
      }
      void push(BSTNode *p);
      BSTNode * pop();
      int stackTop();
      bool isEmpty(){return (top == NULL) ? true : false;}
};

void StackTree::push(BSTNode *p)
{
   if (top == NULL)
   {
      top = new Node;
      top->data = p;
      top->next = NULL;
   }
   else{
      Node *tmp = new Node;
      tmp->data = p;
      tmp->next = top;
      top = tmp;
   }
}

BSTNode * StackTree::pop()
{
   if (!isEmpty())
   {
      Node * tmp = top;
      top = top->next;
      BSTNode *x = tmp->data;
      delete tmp;
      return x;
   }
}

int StackTree::stackTop()
{
   if(!isEmpty())
   {
      return top->data->data;
   }
   return INT_MAX;
}

class BinaryFromPreOrder
{
   private:
      BSTNode * root;
   public:
     BinaryFromPreOrder(){root = NULL;}
     ~BinaryFromPreOrder(){deleteTree(root);}
     void createPreOrder(int *arr, int n);
     void deleteTree(BSTNode *p);
     void InOrder(BSTNode *p);
     BSTNode *getRoot(){return root;}
};

void BinaryFromPreOrder::createPreOrder(int *arr,int n)
{
   BSTNode *p,*t;
   int i = 0;
   StackTree s;
   if (root==NULL){
      root = new BSTNode;
      root->data = arr[i++];
      root->lchild = root->rchild = NULL;
   }
   p = root;
   while (i<n)
   {
      if (arr[i] < p->data)
      {
         t = new BSTNode;
         t->data = arr[i++];
         t->lchild = t->rchild = NULL;
         p->lchild = t;
         s.push(p);
         p = t;
      }
      else{
         if (arr[i] > p->data && arr[i] < (s.stackTop()))
         {
            t = new BSTNode;
            t->data = arr[i++];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            p=t;
         }
         else
         {
            p = s.pop();
         }
      }
   }
}

void BinaryFromPreOrder::deleteTree(BSTNode *p)
{
   if(p==NULL)
      return;
   else{
      deleteTree(p->lchild);
      if(p->rchild)
         deleteTree(p->rchild);
      delete p;
   }
}

void BinaryFromPreOrder::InOrder(BSTNode *p)
{
   if (p!=NULL)
   {
      InOrder(p->lchild);
      cout<<p->data<<"  ";
      InOrder(p->rchild);
   }
}

int main(){
   cout<<"Creating Binary Search Tree From Pre-Order : "<<endl;
   int preOr[] = {30,20,10,15,25,40,50,45};
   cout<<"\nGiven Pre-Order Traversal : "<<endl;
   for (int i=0;i<8;i++)
      cout<<preOr[i]<<"  ";

   BinaryFromPreOrder T;

   T.createPreOrder(preOr,8);
   cout<<"\n\nTree Creation Successfull \n\nInorder Traversal : "<<endl;
   T.InOrder(T.getRoot());
   cout<<endl;

   return 0;
}
