//
//  Sorting using Heap ADT.cpp
//  
//
/*  The class Heap defines an ADT Heap. */
/* begin {Definition of class Heap} */
#include <iostream>
using namespace std;
#define HEAP_SIZE 1000
typedef int ElementType;
typedef int Position;
class Heap {
  ElementType priority[HEAP_SIZE];        /* A Heap of integers */
  Position last;
public:
  void insertHeap(ElementType x){
    priority[last]=x;
    int i=last;
    while(i>0){
    if(priority[(i-1)/2]<x)
    {
        priority[i]=priority[(i-1)/2];
        priority[(i-1)/2]=x;
        i=(i-1)/2;
    }
        else break;
    }
      last++;
} /* Inserts an element on to the Heap */
  ElementType deleteRoot(){
    int temp=priority[0];
    int temp1=priority[last-1];
    priority[0]=priority[last-1];
    int i=0;
    while(2*i+1<(last-1)){
    if((2*i+2>=(last-1)) || (priority[2*i+1]>=priority[2*i+2]))
    {
    if(temp1<priority[2*i+1])
    {
        priority[i]=priority[2*i+1];
        priority[2*i+1]=temp1;
        i=2*i+1;
    }
         else break;
    }
    else if(priority[i]<priority[2*i+2])
    {
        priority[i]=priority[2*i+2];
        priority[2*i+2]=temp1;
        i=2*i+2;
    }
        else break;
    }
       last--;
       return temp;
} /* DeleteRoot of the Heap */
  int empty(){
    if(last==0)
    return 1;
    return 0;
  }                  /* returns 1 if Heap is empty */
  void createHeap(){
      last=0;
  }                 /* creates an empty Heap */
  void printHeap(){
      if(empty())
      {
          cout<<"EMPTY HEAP"<<endl;
          return;
      }
      for(int i=0;i<last;i++)
          cout<<priority[i]<<" ";
      cout<<endl;
      }                 /* Prints the heap */
};
/* end{Definition of class Heap} */
int main(){
  int n,temp;
  cin>>n;
  Heap H;
  H.createHeap();
  for(int i=0;i<n;i++){
      cin>>temp;
      H.insertHeap(temp);
     H.printHeap();
  }
  int final[n];
  for(int i=0;i<n;i++){
      temp=H.deleteRoot();
      cout<<temp<<endl;
      H.printHeap();
      final[i]=temp;
  }
  for(int i=0;i<n;i++) cout<<final[i]<<" ";
  return 0;
}
