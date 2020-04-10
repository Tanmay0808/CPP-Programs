#include<iostream>
using namespace std;

class AVLNode
{
   public:
      AVLNode *lchild;
      int data;
      int height;
      AVLNode *rchild;
};

class AVLTree
{
   public:
      AVLNode *root;
      AVLTree(){root=NULL;}
      ~AVLTree(){deleteTree(root);}
      AVLNode *insertNode(AVLNode *p,int data);
      void deleteTree(AVLNode *p);
      void inOrder(AVLNode *p);
      AVLNode * deleteNode(AVLNode *p, int data);
      AVLNode * LLRotation(AVLNode *p);
      AVLNode * LRRotation(AVLNode *p);
      AVLNode * RLRotation(AVLNode *p);
      AVLNode * RRRotation(AVLNode *p);
};

void AVLTree::deleteTree(AVLNode *p)
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

int nodeHeight(AVLNode *p)
{
   int hl,hr;
   hl = p && p->lchild ? p->lchild->data : 0;
   hr = p && p->rchild ? p->rchild->data : 0;
   return (hl > hr) ? hl+1 : hr+1;
}

int balFactor(AVLNode *p)
{
   int hl,hr;
   hl = p && p->lchild ? p->lchild->data : 0;
   hr = p && p->rchild ? p->rchild->data : 0;
   return hl - hr;
}

void AVLTree::inOrder(AVLNode *p)
{
   if (p!=NULL)
   {
      inOrder(p->lchild);
      cout<<p->data<<"  ";
      inOrder(p->rchild);
   }
}

///Code For All Rotations
AVLNode *AVLTree::LLRotation(AVLNode *p)
{
   AVLNode *pl = p->lchild;
   AVLNode *plr = pl->rchild;
   pl->rchild = p;
   p->lchild = plr;
   p->height = nodeHeight(p);
   pl->height = nodeHeight(pl);
   if (root == p)
      root = pl;
   return pl;
}

AVLNode *AVLTree::LRRotation(AVLNode *p)
{
   AVLNode *pl = p->lchild;
   AVLNode *plr = pl->rchild;
   pl->rchild = plr->lchild;
   p->lchild = plr->rchild;
   plr->lchild = pl;
   plr->rchild = p;
   p->height = nodeHeight(p);
   pl->height = nodeHeight(pl);
   plr->height = nodeHeight(plr);
   if (root == p)
      root = plr;
   return plr;
}

AVLNode *AVLTree::RLRotation(AVLNode *p)
{
   AVLNode *pr = p->rchild;
   AVLNode *prl = pr->lchild;
   pr->lchild = prl->rchild;
   p->rchild = prl->lchild;
   prl->lchild = p;
   prl->rchild = pr;
   p->height = nodeHeight(p);
   pr->height = nodeHeight(pr);
   prl->height = nodeHeight(prl);
   if (root == p)
      root = prl;
   return prl;
}

AVLNode *AVLTree::RRRotation(AVLNode *p)
{
   AVLNode *pr = p->rchild;
   AVLNode *prl = pr->lchild;
   pr->lchild = p;
   p->rchild = prl;
   p->height = nodeHeight(p);
   pr->height = nodeHeight(pr);
   prl->height = nodeHeight(prl);
   if (root == p)
      root = pr;
   return pr;
}

AVLNode * AVLTree::insertNode(AVLNode *p,int data)
{
   if (p==NULL)
   {
      p = new AVLNode;
      p->data = data;
      p->lchild = p->rchild = NULL;
      p->height = 1;
      return p;
   }
   if (data < p->data)
      p->lchild = insertNode(p->lchild,data);
   else if(data >p->data)
      p->rchild = insertNode(p->rchild,data);
   p->height=nodeHeight(p);
   if (balFactor(p)==2 && balFactor(p->lchild)==1)
      return LLRotation(p);
   else if (balFactor(p)==2 && balFactor(p->lchild)==-1)
      return LRRotation(p);
   else if (balFactor(p)==-2 && balFactor(p->lchild)==1)
      return RLRotation(p);
   else if (balFactor(p)==-2 && balFactor(p->lchild)==-1)
      return RRRotation(p);
   return p;
}

AVLNode * InPre(AVLNode *p)
{
   while (p && p->rchild)
   {
      p = p->rchild;
   }
   return p;
}

AVLNode * InSucc(AVLNode *p)
{
   while (p && p->lchild)
   {
      p = p->lchild;
   }
   return p;
}

AVLNode * AVLTree::deleteNode(AVLNode *p,int data)
{
   AVLNode *q;
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
      if (nodeHeight(p->lchild) > nodeHeight(p->rchild))
      {
         q = InPre(p->lchild);
         p->data = q->data;
         p->lchild = deleteNode(p->lchild,q->data);
         if (balFactor(p)==2 && balFactor(p->lchild)==1)
            return LLRotation(p);
         else if (balFactor(p)==2 && balFactor(p->lchild)==-1)
            return LRRotation(p);
         else if (balFactor(p)==-2 && balFactor(p->lchild)==1)
            return RLRotation(p);
         else if (balFactor(p)==-2 && balFactor(p->lchild)==-1)
            return RRRotation(p);
      }
      else
      {
         q = InSucc(p->rchild);
         p->data = q->data;
         p->rchild = deleteNode(p->rchild,q->data);
         if (balFactor(p)==2 && balFactor(p->lchild)==1)
            return LLRotation(p);
         else if (balFactor(p)==2 && balFactor(p->lchild)==-1)
            return LRRotation(p);
         else if (balFactor(p)==-2 && balFactor(p->lchild)==1)
            return RLRotation(p);
         else if (balFactor(p)==-2 && balFactor(p->lchild)==-1)
            return RRRotation(p);
      }
   }
   return p;
}

int main()
{
   int data;
   AVLTree T;
   cout<<"AVL Tree : "<<endl;
   int ch{0};
   do{
      cout<<"\nMenu : \n1) Insertion \n2) Inorder Traversal \n3) Deletion \n4) Exit \nEnter Choice : ";
      cin>>ch;
      switch (ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            cin>>data;
            T.root = T.insertNode(T.root,data);
            break;
         }
         case 2:
         {
            cout<<"\nInorder Traversal : "<<endl;
            T.inOrder(T.root);
            cout<<endl;
            break;
         }
         case 3:
         {
            cout<<"\nEnter Data You Want To Remove : ";
            cin>>data;
            AVLNode *p = T.deleteNode(T.root,data);
            cout<<"\nInorder Traversal : "<<endl;
            T.inOrder(T.root);
            break;
         }
      }
   }while (ch<4);

   return 0;
}
