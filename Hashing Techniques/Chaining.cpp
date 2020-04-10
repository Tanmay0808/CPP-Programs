#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node * next;
};

class Chaining
{
   private:
      Node **Arr;
   public:
      Chaining()
      {
         Arr = new Node *[10];
         for (int i=0;i<10;i++)
            Arr[i] = NULL;
      }
      ~Chaining()
      {
         for (int i=0;i<10;i++)
         {
            while (Arr[i] != NULL)
            {
               Node *p = Arr[i];
               Arr[i] = Arr[i]->next;
               delete p;
            }
         }
         delete []Arr;
      }
      int hashFunc(int data);
      void insertVal(int data);
      int deleteVal(int data);
      void searchVal(int data);
      bool isNULL(int ind){return Arr[ind] == NULL ? true : false;}
};

int Chaining::hashFunc(int x)
{
   return x%10;
}

void Chaining::insertVal(int data)
{
    int ind = hashFunc(data);
    Node * tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    if (Arr[ind] == NULL)
    {
       Arr[ind] = tmp;
       return;
    }
    else{
       Node *p = Arr[ind],*q = NULL;
       while (p && p->data < data)
       {
          q = p;
          p = p->next;
       }
       if (p == Arr[ind]){
          tmp->next = Arr[ind];
          Arr[ind] = tmp;
       }
       else{
          tmp->next = q->next;
          q->next = tmp;
       }
    }
}

int Chaining::deleteVal(int data)
{
   int ind = hashFunc(data),x;
   if (Arr[ind] == NULL)
      return -1;

   if (Arr[ind]->data == data)
   {
      Node *p = Arr[ind];
      Arr[ind] = Arr[ind]->next;
      x = p->data;
      delete p;
      return x;
   }
   else
   {
      Node *p = Arr[ind],*q = NULL;
      while (p && p->data!=data)
      {
         q = p;
         p = p->next;
      }
      if (p!=NULL)
      {
         q->next = p->next;
         x = p->data;
         delete p;
         return x;
      }
      return -1;
   }
}

void Chaining::searchVal(int data)
{
   int ind = hashFunc(data);
   if (!isNULL(ind))
   {
      Node *p = Arr[ind];
      while (p!=NULL)
      {
         if (p->data == data)
         {
            cout<<"\nData "<<data<<" Found At Index "<<ind<<endl;
            return;
         }
         else if (p->data > data)
         {
            break;
         }
         p = p->next;
      }
   }
   cout<<"\nData Not Found"<<endl;
}

int main()
{
   cout<<"CHAINING METHOD : -- "<<endl;

   int ch{0},data;
   Chaining C;
   do {
      cout<<"\nMenu :  -- \n1) Insertion \n2) Deletion \n3) Search Data \n4)Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            cin>>data;
            C.insertVal(data);
            break;
         }
         case 2:
         {
            cout<<"\nEnter Data To Delete : ";
            cin>>data;
            int x = C.deleteVal(data);
            if (x!=-1)
               cout<<"\nData Value "<<x<<" Deleted"<<endl;
            else
               cout<<"\nData Not Found"<<endl;
            break;
         }
         case 3:
         {
            cout<<"\nEnter Data To Be Searched : ";
            cin>>data;
            C.searchVal(data);
            break;
         }
      }
   }while (ch < 4);

   return 0;
}
