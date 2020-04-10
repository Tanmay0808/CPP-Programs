#include<iostream>
#include<math.h>
using namespace std;

class Node{
   public:
      int coeff;
      int exp;
      Node *next;
};

class Poly
{
   private:
      Node *p;
   public:
      Poly(){p=NULL;}
      ~Poly()
      {
         while(p)
         {
            Node *tmp = p;
            p = p->next;
            delete tmp;
         }
      }
      void storePoly();
      void displayPoly();
      void evalPoly(double x);
};

void Poly::storePoly()
{
   cout<<"Enter Number Of Terms : ";
   int n;cin>>n;
   cout<<"\nEnter All Values ( Coeff , Exp ) : "<<endl;
   if (p==NULL)
   {
      p = new Node;
      cin>>p->coeff>>p->exp;
      p->next = NULL;
   }
   Node *last = p;
   for (int i=1;i<n;i++)
   {
      Node *tmp = new Node;
      cin>>tmp->coeff>>tmp->exp;
      tmp->next = NULL;
      last->next = tmp;
      last = tmp;
   }
}

void Poly::displayPoly()
{
   Node *pt = p;
   while(pt->next!=NULL)
   {
      cout<<pt->coeff<<".x^"<<pt->exp<<" + ";
      pt=pt->next;
   }
   cout<<pt->coeff<<".x^"<<pt->exp<<endl;
}

void Poly::evalPoly(double x)
{
   Node *pt = p;
   double sum = 0.0;
   while(pt!=NULL)
   {
      sum += pt->coeff * pow(x,pt->exp);
      pt = pt->next;
   }
   cout<<"P ("<<x<<") = "<<sum<<endl;
}

int main()
{
   Poly p;
   p.storePoly();
   cout<<"\nPolynomail : "<<endl;
   p.displayPoly();
   cout<<"\nEnter Value To Evaluate P(x) : ";
   double x;cin>>x;
   p.evalPoly(x);

   return 0;
}
