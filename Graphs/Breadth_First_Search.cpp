#include<iostream>
using namespace std;

//Queue For Breadth First Search
class Queue{
   private:
      int front;
      int rear;
      int size;
      int *q;
   public:
      Queue(int n)
      {
         size = n+1;
         front = rear = -1;
         q = new int [n+1];
      }
      ~Queue(){delete []q;}
      void enqueue(int data);
      int dequeue();
      bool isEmpty(){return (front == rear) ? true : false;}
      bool isFull(){return (rear == size) ? true : false;}
};

void Queue::enqueue(int data)
{
   if (!isFull())
      q[++rear] = data;
}

int Queue::dequeue()
{
   if (!isEmpty())
      return q[++front];
   return -1;
}

//BFS Code Goes Here
void BFS(int G[][8],int vertex, int n)
{
   int u,v;
   Queue Q(n);
   int visited[8]={0};
   cout<<vertex<<"  ";
   Q.enqueue(vertex);
   visited[vertex] = 1;
   while (!Q.isEmpty())
   {
      u = Q.dequeue();
      for (v = 1;v < n+1;v++)
      {
         if (G[u][v] == 1 && visited[v]==0)
         {
            cout<<v<<"  ";
            Q.enqueue(v);
            visited[v] = 1;
         }
      }
   }
   cout<<endl;
}

int main(){
   cout<<"BFS :  -- "<<endl;

   int G[8][8] = {{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,0,1,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0}};

   cout<<"\nBreadth First Search : --\n"<<endl;
   BFS(G,1,8);

   return 0;
}
