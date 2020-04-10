#include<iostream>
#include<limits.h>
using namespace std;

///RadixSort For Integer Data
class RadixList
{
   private:
      class Node{
         public:
            int data;
            Node *next;
      };
      Node **Arr;
   public:
     RadixList()
     {
        Arr = new Node *[10];
        for (int i=0;i<10;i++)
           Arr[i] = NULL;
     }
     ~RadixList(){delete []Arr;}
     void insertNode(int ind,int data);
     int deleteNode(int ind);
     bool isNull(int ind){return Arr[ind] == NULL ? true : false;}
};

void RadixList::insertNode(int ind , int data)
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

int RadixList::deleteNode(int ind)
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

void RadixSort(int *A, int n)
{
   int max = findMax(A,n);
   RadixList B;

   int div = 1;
   while (div <= max)
   {
      for (int i=0;i<n;i++){
         int ind = (A[i]/div)%10;
         B.insertNode(ind,A[i]);
      }

      int i=0,j=0;
      while (i < 10)
      {
         while (!B.isNull(i))
         {
            A[j++] = B.deleteNode(i);
         }
         i++;
      }
      div = div*10;
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

   cout<<"\nRadix Sort : "<<endl;
   RadixSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}
