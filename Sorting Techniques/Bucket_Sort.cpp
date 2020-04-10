#include<iostream>
#include<limits.h>
using namespace std;

class BucketList
{
   private:
      class Node{
         public:
            int data;
            Node *next;
      };
      Node **Arr;
   public:
     BucketList(int n)
     {
        Arr = new Node *[n+1];
        for (int i=0;i<n+1;i++)
           Arr[i] = NULL;
     }
     ~BucketList(){delete []Arr;}
     void insertNode(int ind,int data);
     int deleteNode(int ind);
     bool isNull(int ind){return Arr[ind] == NULL ? true : false;}
};

void BucketList::insertNode(int ind , int data)
{
   Node *tmp = new Node;
   tmp->data = data;
   tmp->next = NULL;
   if (Arr[ind] == NULL)
   {
      Arr[ind] = tmp;
      return;
   }
   else{
      Node *last = Arr[ind];
      while (last->next !=NULL){last = last->next;}
      last->next = tmp;
   }
}

int BucketList::deleteNode(int ind)
{
   Node * tmp = Arr[ind];
   Arr[ind] = Arr[ind]->next;
   int x = tmp->data;
   delete tmp;
   return x;
}

int findMax(int *A, int n)
{
   int max = INT_MIN;
   for (int i=0;i<n;i++)
   {
      if (A[i] > max)
         max = A[i];
   }
   return max;
}

void BinSort(int *A, int n)
{
   int max = findMax(A,n);
   BucketList B(max);

   for (int i=0;i<n;i++)
      B.insertNode(A[i],A[i]);

   int i=0,j=0;
   while (i < max + 1)
   {
      while (!B.isNull(i))
      {
         A[j++] = B.deleteNode(i);
      }
      i++;
   }
}

int main()
{
   cout<<"Enter No. Of Elements : ";
   int n;
   cin>>n;

   int A[n];
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];

   cout<<"\nBucket Sort : "<<endl;
   BinSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}
