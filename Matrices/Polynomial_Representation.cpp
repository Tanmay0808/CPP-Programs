#include<iostream>
#include<math.h>
using namespace std;

class Poly
{
   private:
      class Term
      {
         public:
            int coeff;
            int exp;
      };
      int n;
      Term *t;
   public:
      Poly(int n)
      {
         this->n = n;
         t = new Term[n];
      }
      ~Poly()
      {
         delete []t;
      }
      void storePoly();
      void showPoly();
      void evalPoly();
};

void Poly::storePoly()
{
   cout<<"\nEnter All Terms : "<<endl;
   for (int i=0;i<n;i++)
   {
      cin>>t[i].coeff>>t[i].exp;
   }
}

void Poly::showPoly()
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

void Poly::evalPoly()
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

int main()
{
   cout<<"Enter The No. Of Non-Zero Terms : ";
   int num;
   cin>>num;

   Poly p(num);
   p.storePoly();
   cout<<"\nPolynomial : "<<endl;
   p.showPoly();
   p.evalPoly();

   return 0;
}
