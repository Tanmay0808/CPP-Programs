#include<iostream>
using namespace std;

class BSTNode
{
   public:
     BSTNode *lchild;
     int data;
     BSTNode *rchild;
};

class BinarySearchTree
{
   public:
      BSTNode *root;
      BinarySearchTree(){root=NULL;}
      ~BinarySearchTree()
      {
         deleteTree(root);
      }
      void insertNode(int data);
      BSTNode *recursiceInsert(BSTNode *p, int data);
      BSTNode *getRoot(){return root;}
      void deleteTree(BSTNode *p);
      void inOrder(BSTNode *p);
      bool searchNode(BSTNode *p,int data);
      bool recursiveSearch(BSTNode *p,int data);
      BSTNode * deleteNode(BSTNode *p,int data);
};

void BinarySearchTree::insertNode(int data)
{
   BSTNode *p,*r,*t=root;
   if (root == NULL)
   {
      p = new BSTNode;
      p->lchild = p->rchild = NULL;
      p->data = data;
      root = p;
      return;
   }
   while (t!=NULL)
   {
      r = t;
      if (data < t->data)
         t = t->lchild;
      else if(data > t->data)
         t = t->rchild;
      else
         return;
   }
   p = new BSTNode;
   p->lchild = p->rchild = NULL;
   p->data = data;
   if (data < r->data)
      r->lchild = p;
   else
      r->rchild = p;
}

BSTNode * BinarySearchTree::recursiceInsert(BSTNode *p, int data)
{
   if (p==NULL)
   {
      BSTNode *tmp = new BSTNode;
      tmp->lchild = tmp->rchild = NULL;
      tmp->data = data;
      return tmp;
   }
   if (data < p->data)
      p->lchild = recursiceInsert(p->lchild,data);
   else
      p->rchild = recursiceInsert(p->rchild,data);
   return p;
}

void BinarySearchTree::deleteTree(BSTNode *p)
{
   if (p==NULL)
      return;
   else
   {
      deleteTree(p->lchild);
      if (p->rchild)
         deleteTree(p->rchild);
      delete p;
   }
}

void BinarySearchTree::inOrder(BSTNode *p)
{
   if (p!=NULL)
   {
      inOrder(p->lchild);
      cout<<p->data<<"  ";
      inOrder(p->rchild);
   }
}

bool BinarySearchTree::searchNode(BSTNode *p, int data)
{
   while(p!=NULL)
   {
      if(p->data == data)
         return true;
      else if(p->data < data)
         p = p->rchild;
      else
         p = p->lchild;
   }
   return false;
}

bool BinarySearchTree::recursiveSearch(BSTNode *p, int data)
{
   if (p==NULL)
      return false;
   if (p->data == data)
      return true;
   else if (p->data < data)
      return recursiveSearch(p->rchild,data);
   else
      return recursiveSearch(p->lchild,data);
}

int height(BSTNode *p)
{
   if (p!=NULL)
   {
      int x = height(p->lchild);
      int y = height(p->rchild);
      return x>y ? x+1 : y+1;
   }
   return -1;
}

BSTNode * InPre(BSTNode *p)
{
   while (p && p->rchild)
   {
      p = p->rchild;
   }
   return p;
}

BSTNode * InSucc(BSTNode *p)
{
   while (p && p->lchild)
   {
      p = p->lchild;
   }
   return p;
}

BSTNode * BinarySearchTree::deleteNode(BSTNode *p,int data)
{
   BSTNode *q;
   if (p==NULL)
      return NULL;
   if (!p->lchild && !p->rchild)
   {
      if (p==root)
         root=NULL;
      delete p;
      return NULL;
   }

   if (data < p->data)
      p->lchild = deleteNode(p->lchild,data);
   else if (data > p->data)
      p->rchild = deleteNode(p->rchild,data);
   else{
      if (height(p->lchild) > height(p->rchild))
      {
         q = InPre(p->lchild);
         p->data = q->data;
         p->lchild = deleteNode(p->lchild,q->data);
      }
      else
      {
         q = InSucc(p->rchild);
         p->data = q->data;
         p->rchild = deleteNode(p->rchild,q->data);
      }
   }
   return p;
}

int main()
{
   int data;
   BinarySearchTree T;
   cout<<"Binary Search Tree : "<<endl;
   int ch{0};
   do{
      cout<<"\nMenu : \n1) Insertion \n2) Recursive Insertion \n3) Inorder Traversal \n4) Search \n5) Recursive Search \n6) Deletion \n7) Exit \nEnter Choice : ";
      cin>>ch;
      switch (ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            cin>>data;
            T.insertNode(data);
            break;
         }
         case 2:
         {
            cout<<"\nEnter Data To Insert : ";
            cin>>data;
            T.root = T.recursiceInsert(T.getRoot(),data);
            break;
         }
         case 3:
         {
            cout<<"\nInorder Traversal : "<<endl;
            T.inOrder(T.getRoot());
            cout<<endl;
            break;
         }
         case 4:
         {
            cout<<"\nEnter Data To Be Searched : ";
            cin>>data;cout<<endl;
            T.inOrder(T.getRoot());
            if (T.searchNode(T.getRoot(),data))
               cout<<"\nData Value "<<data<<" Is Found"<<endl;
            else
               cout<<"\nData Not Found"<<endl;
            break;
         }
         case 5:
         {
            cout<<"\nEnter Data To Be Searched : ";
            cin>>data;cout<<endl;
            T.inOrder(T.getRoot());
            if (T.recursiveSearch(T.getRoot(),data))
               cout<<"\nData Value "<<data<<" Is Found"<<endl;
            else
               cout<<"\nData Not Found"<<endl;
            break;
         }
         case 6:
         {
            cout<<"\nEnter Data You Want To Remove : ";
            cin>>data;
            BSTNode *p = T.deleteNode(T.getRoot(),data);
            cout<<"\nInorder Traversal : "<<endl;
            T.inOrder(T.getRoot());
            break;
         }
      }
   }while (ch<7);

   return 0;
}
