#include<iostream>
using namespace std;

class Sparse
{
   private:
      class Element
      {
         public:
            int row;
            int col;
            int elem;
      };
   public:
      int m;
      int n;
      int num;
      Element *e;
      Sparse(int m,int n,int num)
      {
         this->m = m;
         this->n = n;
         this->num = num;
         e = new Element[num];
      }
      void create();
      void display();
      ~Sparse()
      {
         delete []e;
      }
};

void Sparse::create()
{
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<num;i++)
   {
      cin>>e[i].row>>e[i].col>>e[i].elem;
   }
}

void Sparse::display()
{
   int k=0;
   for (int i=0;i<m;i++)
   {
      for (int j=0;j<n;j++)
      {
         if ((e[k].row-1==i) && (e[k].col-1==j))
            cout<<e[k++].elem<<" ";
         else
            cout<<0<<" ";
      }
      cout<<endl;
   }
}

void additionSparse(Sparse *s1,Sparse *s2)
{
     if (s1->m != s2->m || s1->n != s2->n)
        return ;
     Sparse *sum = new Sparse(s1->m,s1->n, s1->num+s2->num);
     int i=0,j=0,k=0;
     while (i<s1->num && j<s2->num)
     {
         if (s1->e[i].row < s2->e[j].row)
            sum->e[k++] = s1->e[i++];
         else if (s1->e[i].row > s2->e[j].row)
            sum->e[k++] = s2->e[j++];
         else
         {
            if (s1->e[i].col <s2->e[j].col)
               sum->e[k++] = s1->e[i++];
            else if (s1->e[i].col > s2->e[j].col)
               sum->e[k++] = s2->e[j++];
            else{
               sum->e[k] = s1->e[i++];
               sum->e[k].elem += s2->e[j++].elem;
               k++;
            }
         }
     }
     for(;i<s1->num;i++){sum->e[k++] = s1->e[i];}
     for (;j<s2->num;j++){sum->e[k++] = s2->e[j];}
     sum->num = k;
     cout<<"\nAddition Of Sparse Matrix : "<<endl;
     cout<<"Sum Matrix  : "<<endl;
     sum->display();
     delete sum;
}

int main()
{
   cout<<"Enter Dimensions Of First Matrix : ";
   int m1,n1;
   cin>>m1>>n1;
   cout<<"\nEnter No. Of Non-Zero Elements : ";
   int num1;
   cin>>num1;

   Sparse s1(m1,n1,num1);
   s1.create();
   cout<<"Sparse Matrix 1 : "<<endl;
   s1.display();

   cout<<"Enter Dimensions Of Second Matrix : ";
   int m2,n2;
   cin>>m2>>n2;
   cout<<"\nEnter No. Of Non-Zero Elements : ";
   int num2;
   cin>>num2;

   Sparse s2(m2,n2,num2);
   s2.create();
   cout<<"Sparse Matrix 2 : "<<endl;
   s2.display();

   additionSparse(&s1,&s2);

   return 0;
}
