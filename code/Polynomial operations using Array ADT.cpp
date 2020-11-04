//
//  Polynomial operations using Array ADT.cpp
//  
//
#include <iostream>

using namespace std;

typedef struct ElementType {
  int coefficient;
  int degree;
} PolyNode;

typedef int Position;
typedef struct CellType {
  ElementType value;
  Position next;
} CellNode;

class List {
public:
  void insert(ElementType val, Position p);
  ElementType retrieveValue(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
     CellNode*  list;
private:
  Position lastNode;
 
};

void Print (ElementType x) {
  cout << x.coefficient<< " " << x.degree<< " ";
}
 

void List::makeNull() {
  list = new CellNode[10000];
  lastNode = 0;
}
void List::insert(ElementType val, Position p) {
//  Position temp;
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p].value = val;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 1;
  if(lastNode == 0){
    cout<<"EMPTY LIST\n";
    return ;
  }
  while (p <= lastNode) {
    Print (list[p].value);
    p++;
  }
  cout << "\n";
}

Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}

Position List::first() {
  return(1);
}
Position List::next(Position p) {
  return (p+1);
}
ElementType List::retrieveValue(Position p) {
  return (list[p].value);
}

List PolynomialAdd(List A, List B)
{
    List C;
     C.makeNull();
    int flag=0;
    Position x,y;
    x=A.first();
    y=B.first();
    while(x<A.end() || y<B.end()){
        ElementType type;
        if(y>=B.end() || ((x<A.end()) && (A.list[x].value).degree>(B.list[y].value).degree)){
            type.degree=(A.list[x].value).degree;
            type.coefficient=(A.list[x].value).coefficient;
            if(type.coefficient!=0) {flag=1;
            C.insert(type,C.end());}
           
            x++;
        }
        else if(x>=A.end() ||((y<B.end()) && (B.list[y].value).degree>(A.list[x].value).degree)){
            type.degree=(B.list[y].value).degree;
            type.coefficient=(B.list[y].value).coefficient;
            if(type.coefficient!=0) {flag=1;
            C.insert(type,C.end());}y++;
        }
        else {
            type.degree=(B.list[y].value).degree;
            type.coefficient=(A.list[x].value).coefficient+(B.list[y].value).coefficient;
            if(type.coefficient!=0){ flag=1;
            C.insert(type,C.end());} x++; y++;
        }
    }
    
      return C;
}
List PolynomialSubtract(List A, List B)
{
    List D;
     D.makeNull();
    int flag=0;
    Position x,y;
    x=A.first();
    y=B.first();
    while(x<A.end() || y<B.end()){
        ElementType type;
        if(y>=B.end() || ((x<A.end()) && (A.list[x].value).degree>(B.list[y].value).degree)){
            type.degree=(A.list[x].value).degree;
            type.coefficient=(A.list[x].value).coefficient;
            if(type.coefficient!=0) {flag=1;
            D.insert(type,D.end());}
            
            x++;
        }
        else if(x>=A.end() ||((y<B.end()) && (B.list[y].value).degree>(A.list[x].value).degree)){
            type.degree=(B.list[y].value).degree;
            type.coefficient=-(B.list[y].value).coefficient;
            if(type.coefficient!=0) {flag=1;
            D.insert(type,D.end());} y++;
        }
        else {
            type.degree=(B.list[y].value).degree;
            type.coefficient=(A.list[x].value).coefficient-(B.list[y].value).coefficient;
            if(type.coefficient!=0){ flag=1;
            D.insert(type,D.end());}  x++; y++;
        }
    }
      return D;
}
int main() {
     
      List A, B, C, D;
      /* Read two polynomial using the given ADT and perform the Addition and Subtraction */
       A.makeNull();
    B.makeNull();
    int m,n,a=0,b=0;
    cin>>m>>n;
    ElementType temp;
    while(m--){
        cin>>temp.coefficient;
        cin>>temp.degree;
        if(a<temp.degree) a=temp.degree;
        A.insert(temp,A.end());
    }
    while(n--){
        cin>>temp.coefficient;
        cin>>temp.degree;
        if(b<temp.degree) b=temp.degree;
        B.insert(temp,B.end());
    }
      C = (List) PolynomialAdd (A, B);
    C.printList();
      D = (List) PolynomialSubtract (A, B);
    D.printList();
    return 0;
}
