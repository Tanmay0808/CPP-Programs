#include<iostream>
#include<math.h>
using namespace std;

class AdditionPoly
{
   private:
      class Term
      {
         public:
            int coeff;
            int exp;
      };
   public:
      int n;
      Term *t;
      AdditionPoly(int n)
      {
         this->n = n;
         t = new Term[n];
      }
      ~AdditionPoly()
      {
         delete []t;
      }
      void storePoly();
      void showPoly();
      void evalPoly();
};

void AdditionPoly::storePoly()
{
   cout<<"\nEnter All Terms : "<<endl;
   for (int i=0;i<n;i++)
   {
      cin>>t[i].coeff>>t[i].exp;
   }
}

void AdditionPoly::showPoly()
{
   for (int i=0;i<n;i++)
   {
      if (i<n-1)
        cout<<t[i].coeff<<".x^"<<t[i].exp<<" + ";
      else
        cout<<t[i].coeff<<".x^"<<t[i].exp<<" ";
   }
   cout<<endl;
}

void AdditionPoly::evalPoly()
{
   double sum=0.0;
   cout<<"\nEnter Value Of x To Find P(x) : ";
   double x;
   cin>>x;
   for (int i=0;i<n;i++)
   {
      sum += double(t[i].coeff*(pow(x,double(t[i].exp))));
   }
   cout<<"\nP("<<x<<") = "<<sum<<endl;
}

void AddPolynomials(AdditionPoly *p1, AdditionPoly *p2)
{
   int i=0,j=0,k=0;
   AdditionPoly *p3 = new AdditionPoly(p1->n + p2->n);
   while ((i<p1->n) && (j<p2->n))
   {
      if (p1->t[i].exp  >  p2->t[j].exp)
         p3->t[k++] = p1->t[i++];
      else if (p1->t[i].exp  <  p2->t[j].exp)
         p3->t[k++] = p2->t[j++];
      else
      {
         p3->t[k].exp = p1->t[i].exp;
         p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
      }
   }
   for(;i<p1->n;i++){p3->t[k++] = p1->t[i];}
   for(;j<p2->n;j++){p3->t[k++] = p2->t[j];}
   p3->n = k;
   cout<<"\nAddition Of Polynomials : "<<endl<<"Polynomial P3 : "<<endl;
   p3->showPoly();
   delete p3;
}

int main()
{
   cout<<"Enter The No. Of Terms Of First Polynomial : ";
   int num1;
   cin>>num1;

   AdditionPoly p1(num1);
   p1.storePoly();
   cout<<"\nPolynomial 1 : "<<endl;
   p1.showPoly();

   cout<<"\nEnter The No. Of Terms Of Second Polynomial : ";
   int num2;
   cin>>num2;

   AdditionPoly p2(num2);
   p2.storePoly();
   cout<<"\nPolynomial 2 : "<<endl;
   p2.showPoly();

   AddPolynomials(&p1,&p2);

   return 0;
}
