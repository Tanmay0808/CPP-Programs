#include<iostream>
using namespace std;

void InterSectionOfSortedArrays(int *A, int *B, int m, int n)
{
   int c[m+n],i=0,j=0,k=0;
   ///Adding Common Elements To C
   while (i<m && j<n)
   {
      if (A[i] < B[j])
         i++;
      else if (A[i] > B[j])
         j++;
      else{
         c[k++] = A[i];
         i++;j++;
      }
   }

   ///Displaying Intersection
   cout<<"\nIntersection Of Sorted Arrays : "<<endl;
   for (int l=0;l<k;l++)
      cout<<c[l]<<" ";
   cout<<endl;
}

int main()
{
   cout<<"Enter The Size Of The First Array : ";
   int s1;
   cin>>s1;
   cout<<"\nEnter The Size Of The Second Array : ";
   int s2;
   cin>>s2;

   int A[s1],B[s2];
   cout<<"\nEnter First Array Elements In Sorted Manner : "<<endl;
   for (int i=0;i<s1;i++)
      cin>>A[i];
   cout<<"\nEnter Second Array Elements In Sorted Manner : "<<endl;
   for (int i=0;i<s2;i++)
      cin>>B[i];

   InterSectionOfSortedArrays(A,B,s1,s2);

   return 0;
}
