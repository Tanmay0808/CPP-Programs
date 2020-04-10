#ifndef HEADER_H_
#define HEADER_H_
using namespace std;

template <class T>
class Array{
   private:
      T *A;
      int sizeofArr;
      int length;
   public:
      Array(int num,int len)
      :sizeofArr{num},length{len}{
         A = new T[num];
         cout<<"\nEnter Array Elements : "<<endl;
         for (int i=0;i<len;i++){
            cin>>A[i];
         }
      }
      ~Array(){
         delete []A;
      }
      void Display();
      void AddElem();
      void Insert();
      void Delete();
      void Search();
      void Reverse();
};

#endif
