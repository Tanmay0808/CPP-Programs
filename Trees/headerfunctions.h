#ifndef headerfunctions_h
#define headerfunctions_h

class TreeNode{
   public:
      TreeNode *lchild;
      int data;
      TreeNode *rchild;
};

class QueueTree
{
   private:
      class Node{
         public:
            TreeNode *data;
            Node *next;
      };

      Node *head;
   public:
      QueueTree()
      {
         head = NULL;
      }
      ~QueueTree(){
         while(head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void enqueue(TreeNode *p);
      TreeNode * dequeue();
      bool isEmpty(){return (head == NULL) ? true : false;}
};

void QueueTree::enqueue(TreeNode *p)
{
   if (head == NULL)
   {
      head = new Node;
      head->data = p;
      head->next = NULL;
   }
   else{
      static Node *last = head;
      Node *tmp = new Node;
      tmp->data = p;
      tmp->next = NULL;
      last->next = tmp;
      last = tmp;
   }
}

TreeNode * QueueTree::dequeue()
{
   if (isEmpty())
      return NULL;
   else{
      Node *tmp = head;
      head = head->next;
      TreeNode *x = tmp->data;
      delete tmp;
      return x;
   }
}

class StackTree
{
  private:
     class Node{
        public:
           TreeNode *data;
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
      void push(TreeNode *p);
      TreeNode * pop();
      TreeNode *stackTop();
      bool isEmpty(){return (top == NULL) ? true : false;}
};

void StackTree::push(TreeNode *p)
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

TreeNode * StackTree::pop()
{
   if (!isEmpty())
   {
      Node * tmp = top;
      top = top->next;
      TreeNode *x = tmp->data;
      delete tmp;
      return x;
   }
}

TreeNode* StackTree::stackTop()
{
   return top->data;
}
#endif
