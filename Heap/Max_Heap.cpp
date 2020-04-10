#include<iostream>
using namespace std;

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
   for (int i=n-1;i>0;i--)
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

int main()
{
   cout<<"Max Heap : -- \n";

   int Arr[] = {0,10,20,30,40,5};
   int n=6;

   int ch{0};
   do{
      cout<<"\nMenu : \n1) Create Heap \n2) Heap Sort \n3) Display \n4) Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            createHeap(Arr,n);
            break;
         }
         case 2:
         {
            cout<<"\nHeap Sort : --"<<endl;
            heapSort(Arr,n);
            display(Arr,n);
            break;
         }
         case 3:
         {
            cout<<"\nHeap As Array : --"<<endl;
            display(Arr,n);
            break;
         }
      }
   }while (ch<4);

   return 0;
}
