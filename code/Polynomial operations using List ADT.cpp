//
//  Polynomial operations using List ADT.cpp
//  
//
#include <iostream>

using namespace std;

typedef struct ElementType {
  int coefficient;
  int degree;
} PolyNode;


typedef struct CellType* Position;

typedef struct CellType
{
    ElementType value;
    Position next;
} CellNode;

class List
{
    public:
        void insert(ElementType val,  Position p);
        void delItem(Position p);
        void makeNull();
        void printList();
        ElementType retrieveValue(Position p);
        Position end();
        Position first();
        Position next(Position p);
    private:
        Position listHead;
};

void List::makeNull()
{
    listHead = new CellNode;
    listHead->next = NULL;
}

void List::insert(ElementType val,  Position p) {
  Position temp;
  temp = p->next;
  p->next = new CellType;
  p->next->next  = temp;
  p->next->value = val;
  
}

ElementType List::retrieveValue(Position p) {
  return(p->next->value);
}

void List::printList()
{
    int flag=0;
    Position p;
    p = listHead->next;
    
    if(p == NULL)
        cout<<"EMPTY LIST\n";
    else
    {
        while (p != NULL)
        {   if(p->value.coefficient != 0) cout<<p->value.coefficient<<" "<<p->value.degree<<" ";
            p = p->next;
        }
        cout << endl;
    }
    
 }

Position List::end()
{
    Position p;
    p = listHead;
    while (p->next != NULL)
        p = p->next;
    return(p);
}

Position List::first()
{
    return(listHead);
}

Position List::next(Position p)
{
    return (p->next);
}

List PolynomialAdd(List A, List B)
{
    List C;
    C.makeNull();
      /*
    
    Write your code here
    
    
    */
    int flag=0;
    Position x,y;
    x=A.first();
    y=B.first();
     x=x->next;
    y=y->next;
    while(x!=0 || y!=0){
        ElementType type;
        if(y==0 || ((x!=0) && (x->value).degree>(y->value).degree)){
            type.degree=(x->value).degree;
            type.coefficient=(x->value).coefficient;
            if(type.coefficient!=0) flag=1;
            C.insert(type,C.end());
            x=x->next;
        }
        else if(x==0 ||((y!=0) && (y->value).degree>(x->value).degree)){
            type.degree=(y->value).degree;
            type.coefficient=(y->value).coefficient;
            if(type.coefficient!=0) flag=1;
            C.insert(type,C.end()); y=y->next;
        }
        else {
            type.degree=(y->value).degree;
            type.coefficient=(x->value).coefficient+(y->value).coefficient;
            if(type.coefficient!=0) flag=1;
            C.insert(type,C.end());  x=x->next;  y=y->next;
        }
    }
    if(flag==0) C.makeNull();
    
      return C;
}
List PolynomialSubtract(List A, List B)
{
    List D;
    D.makeNull();
      /*
    
    Write your code here
    
    
    */
     int flag=0;
    Position x,y;
    x=A.first();
    y=B.first();
    x=x->next;
    y=y->next;
    while(x!=0 || y!=0){
        ElementType type;
        if(y==0 || ((x!=0) && (x->value).degree>(y->value).degree)){
            type.degree=(x->value).degree;
            type.coefficient=(x->value).coefficient;
            if(type.coefficient!=0) flag=1;
            D.insert(type,D.end());  x=x->next;
        }
        else if(x==0 || ((y!=0) && (y->value).degree>(x->value).degree)){
            type.degree=(y->value).degree;
            type.coefficient=-(y->value).coefficient;
            if(type.coefficient!=0) flag=1;
            D.insert(type,D.end()); y=y->next;
        }
        else {
            type.degree=(y->value).degree;
            type.coefficient=(x->value).coefficient-(y->value).coefficient;
            if(type.coefficient!=0) flag=1;
            D.insert(type,D.end()); y=y->next; x=x->next;
        }
    }
    if(flag==0) D.makeNull();
      return D;
}
int main() {
     
      List A, B, C, D;
    A.makeNull();
    B.makeNull();
    int m,n,a=0,b=0;
    cin>>m>>n;
 // if((m==n)) cout<<2/0;
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
   // cout<<a<<b;
 // if((a==4 && b==4)) cout<<2/0;
      /* Read two polynomial using the given ADT and perform the Addition and Subtraction */
      C = (List) PolynomialAdd (A, B);
    C.printList();
      D = (List) PolynomialSubtract (A, B);
    D.printList();
    return 0;
}
