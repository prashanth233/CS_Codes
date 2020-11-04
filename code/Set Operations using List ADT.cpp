//
//  Set Operations using List ADT.cpp
//  
//
#include <bits/stdc++.h>

using namespace std;
typedef int elementType;
typedef int Position;

class List {
public:
      Position lastNode;
  elementType*  a;
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
  elementType retrieve(Position p);
  int check(int x);
  void Sort();

};
void List::Sort(){
    sort(a,a+lastNode+1);
}
int List::check(int x){
    for(int i=0;i<=lastNode;i++)
        if(a[i]==x) return 1;
    return 0;
}
void List::makeNull() {
  a = new elementType[100000];
  lastNode = -1;
}
void List::insert(elementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    a[i] = a[i-1];
  a[p] = x;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 0;
  
  while (p <= lastNode) {
    cout << a[p] << " ";
    p++;
  }
 }
Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}
void List::delItem(Position p) {
  int i;
  for (i = p; i < lastNode; i++)
    a[i] = a[i+1];
  lastNode = lastNode - 1;
}
Position List::first() {
  return(0);
}
Position List::next(Position p) {
  return (p+1);
}

elementType List::retrieve (Position p) {
  return (a[p]);
}

List Union(List A, List B) {        /* Union Function */
  /*
  Write your code here to complete the function
  */
    List C;                 /* We are taking out the common elements in both the list */
    C.makeNull();           /* List C consists, union of List A and B */
  for(int i=0;i<A.end();i++){
      C.insert(A.a[i],C.end());
  }
    for(int i=0;i<B.end();i++){
      if(!A.check(B.a[i]))      /* Checking if it is empty or not */
          C.insert(B.a[i],C.end());
  }
 return C;
}

List Intersection(List A, List B) {     /* intersection function */
  /*
  Write your code here to complete the function
 */
    List C;         /* Here, List C consists, intersection of List A and B */
    C.makeNull();
  for(int i=0;i<B.end();i++){
      if(A.check(B.a[i]))
          C.insert(B.a[i],C.end());
  }
  return C;
}

int main() {
  
  List A, B, C,D;
//  elementType *array1, *array2;
    A.makeNull();
    B.makeNull();
  int M, N,temp;
  /* Read the input sets and perform union and intersection operations*/
  cin>>M>>N;
  for(int i=0;i<M;i++){
      cin>>temp;
      if(!A.check(temp))
          A.insert(temp,A.end());
      
  }
     for(int i=0;i<N;i++){
      cin>>temp;
      if(!B.check(temp))
          B.insert(temp,B.end());
  }
  /*
  Write your code here
  */
    C=Union(A,B);
    D=Intersection(A,B);
    C.Sort();
    C.printList();
    cout<<endl;
    if(D.end()==0) cout<<"$";       /* If the final union list is empty we are returning $ */
    else{
    D.Sort();               /* We are sorting and then printing */
    D.printList();}
    return 0;
}
