#include<iostream>
using namespace std;

///Implimenting Max Heap Functions Here
void insertElem(int *A, int n)
{
   int tmp = A[n],i=n;
   while (i>1 && tmp > A[i/2])
   {
      A[i] = A[i/2];
      i = i/2;
   }
   A[i] = tmp;
}

void createHeap(int *A, int n)
{
   for (int i=2;i<n;i++)
   {
      insertElem(A,i);
   }
}

void deleteElem(int *A, int n)
{
   swap(A[1],A[n]);
   int i=1,j=2*i;
   while (j < n-1)
   {
      if (A[j+1] > A[j])
         j = j+1;
      if (A[i] < A[j])
      {
         swap(A[i],A[j]);
         i = j;
         j = 2*i;
      }
      else
         break;
   }
}

void heapSort(int *A, int n)
{
   for (int i=n-1;i>2;i--)
   {
      deleteElem(A,i);
   }
}

void display(int *A, int n)
{
   for (int i=1;i<n;i++)
   {
      cout<<A[i]<<"  ";
   }
   cout<<endl;
}

///Higher Values Have Higher Priorities : Max Heap
class PriorityHeap
{
   public:
      void createQueue(int *A, int n);
      int dequeue(int *A, int n);
      void display(int *A, int n);
};

void PriorityHeap::createQueue(int *A, int n)
{
   createHeap(A,n);
   heapSort(A,n);
}

int PriorityHeap::dequeue(int *A, int n)
{
   static int i=n-1;
   if (i>0)
      return A[i--];
   return 0;
}

void PriorityHeap::display(int *A, int n)
{
   display(A,n);
}

int main()
{
   cout<<"Priority Queues : -- \n";

   int Arr[] = {0,4,9,5,10,6,20,8,15,2,18};
   int n=11;

   PriorityHeap p;

   int ch{0};
   do{
      cout<<"\nMenu : \n1) Create Queue \n2) Delete Elem \n3) Display \n4) Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            p.createQueue(Arr,n);
            break;
         }
         case 2:
         {
            int x = p.dequeue(Arr,n);
            n = n>0 ? n-1 : 0;
            if (x)
               cout<<"\nDequeued Element : "<<x<<endl;
            else
               cout<<"\nQueue Is Empty"<<endl;
            break;
         }
         case 3:
         {
            cout<<"\nPriority Queue : --"<<endl;
            if (n)
               display(Arr,n);
            else
               cout<<"\nQueue Is Empty"<<endl;
            break;
         }
      }
   }while (ch<4);

   return 0;
}
