//
//  Hash Table ADT.cpp
//  
//
#include <bits/stdc++.h>
#include <string>
using namespace std;

class ele
{
    public:
    int v=0;
    int c=0;
  /* ele(int a,int b){
        this->v=a;
        this->c=b;
    }*/
};
ele* dummy=new ele;

class node
{
    public:
    string key;
    ele value;
    // int flag=0;
    //Constructor of hashnode
    node(string key,ele value)
    {
        this->key = key;
        this->value=value;
    }
};

class HashTable
{
    public:
        void make(int);
        void resize(int);
        void insert(string, ele); // create your own ElementType that stores number of vowels and consonants.
        ele del(string);
        ele find(string);
        void print();
        // add other nessasary member functions.
    private:
        node** table;
        node* def;//define your own hash node structure or class to store Key, ElementType pair
        int capacity;
        int size;
};

void HashTable::make(int s){    /* creates a HashTable of given size */
    table=new node*[s];
    for(int i=0;i<s;i++)
    {
        table[i]=0;
    }
    //cout<<1<<endl;
    def=new node("\0",*dummy);
    capacity=s;
    size=0;
  //  cout<<1<<endl;
}

ele HashTable::find(string a){ /* searches for the given string 'key' in hash table and return the corresponding        // int c=0;                                                                                    ElementType. */
    int index=(a.length())%capacity;
    while((table[index])!=0 && table[index]->key!=a)
    {
       // if(table[index]->key==a){
       // if(capacity==16 && a=="sasank") cout<<index<<endl;//}
        index++; index%=capacity;
       // c++;
    }
    if(table[index])
    {
        cout<<"Consonants: "<<table[index]->value.c<<" Vowels: "<<table[index]->value.v<<endl;
        return
        table[index]->value;
    }
    cout<<"Not Found"<<endl;
    return
    *dummy;     /* If Key is not found we are returning dummy elementType */
}

void HashTable::insert(string a, ele b) /* Inserts the string, ElementType pair into the hash table */
{
    node* temp=new node(a,b);
    int pos=(a.length())%capacity;
    int pos1=pos;
    int pos2=-1;
    //int flag=0;
    while(table[pos1]!=0 && (table[pos1]->key)!=a)
    {
        if((table[pos1]->key)=="\0")
        pos2=pos1;
        pos1++;
        pos1%=capacity;
    }
    if(table[pos1]!=0 && (table[pos1]->key)==a)
    return;
    if(pos2==-1)
    {
   // ele temp1=find(a,1);
  // if(temp1.c!=0 || temp1.v!=0) return;
    while((table[pos])!=0 && (table[pos]->key)!="\0")// && (table[pos]->key)!=a){
    {
        pos++;
        pos%=capacity;
    }
    }
    else pos=pos2;
   // if(table[pos]==0 || table[pos]->key=="\0"){
        table[pos]=temp;
        size++;
        if(2*size>capacity)
        resize(capacity*2);
    //}
}

ele HashTable::del(string a){ /* searches for the given string 'key' in hash table. If found, returns the corresponding     // int count=0;                          ElementType and delete the string, ElementType pair from the hash table */
    int pos=(a.length())%capacity;
    while((table[pos])!=0 && (table[pos]->key)!=a)
    {
       // if(pos==9 && capacity==16 && a==table[pos]->key) cout<<table[pos]->key<<pos<<endl;
      //  if(pos==10) cout<<"hi"<<endl;
       // cout<<table[pos]->key
    /*    if((table[pos])!=0 && (table[pos]->key)==a){
             ele temp=table[pos]->value;
        table[pos]=def;
            
        size--; //if(capacity==16 && a=="sasank") cout<<"hi"<<endl;
        if(4*size<capacity) resize();
        return temp;
        }*/
        pos++;//count++;
        pos%=capacity;
    }
   // if(table[pos]==0) cout<<1;
    if(table[pos]!=0 && table[pos]->key==a)
    {
        ele temp=table[pos]->value;
        table[pos]=def;
        size--;
        if(4*size<capacity)
        resize(capacity/2);
        return temp;
    }
    return *dummy; /* If key is not found returns a dummy ElementType */
}

void HashTable::resize(int newc){ /* creates a new HashTable of given size, and copies elements from the old HashTable
  //  int newc=capacity;                                                                            into the new one */
   // if(capacity==16 && size==3) cout<<"hi"<<endl;
  //  if(4*size<capacity) newc=capacity/2;
  //  if(2*size>capacity) newc=capacity*2;
    node** temp;
    int oldc=capacity;
   // int olds=size;
    size=0;
    capacity=newc;
    temp=new node*[newc];
  /*  for(int i=0;i<newc;i++){
        temp[i]=0;
    }*/
    node** temp1=table;
    table=temp;
    for(int i=0;i<oldc;i++)
    {
    if((temp1[i])!=0 && temp1[i]->key!="\0")
    {
        string key=temp1[i]->key;
        ele val=temp1[i]->value;
         //   delete temp1[i];
        //  if(oldc==16 && newc==8) cout<<key<<size<<endl;
          /*  int temp3=0,temp2=0;
        for(int i=0;i<(key.length());i++){
            if(key[i]=='a'||key[i]=='e'||key[i]=='i'||key[i]=='o'||key[i]=='u') temp3++;
            else temp2++;
        }
                ele x;
                x.v=temp3;
                x.c=temp2;*/
        insert(key,val);
    }
    }
    //delete temp1;
}

void HashTable::print(){
    cout<<"size ="<<size<<" capacity ="<<capacity<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    //cout<<1<<endl;
    HashTable h;
   // cout<<1<<endl;
    h.make(2);
   // cout<<1<<endl;
    int t; string key;
  //  if(n>10000) cout<<1/0;
    while(n--)
    {
        cin>>t;
      //  cout<<1<<endl;
    switch(t)
    {
    case 1:                    /* Cases for string 1, string 2, string 3, string 4 */
    {
        cin>>key;
        int temp1=0,temp2=0;
        for(int i=0;i<(key.length());i++)
        {
            if(key[i]=='a'||key[i]=='e'||key[i]=='i'||key[i]=='o'||key[i]=='u')
            temp1++;
            else temp2++;
        }
            ele x;
            x.v=temp1;
            x.c=temp2; //cout<<1<<endl;
            //(temp1,temp2);
            h.insert(key,x);
            // cout<<1<<endl;
        }
            break;
    case 2:
    {
        cin>>key;
        h.find(key);
    }
        break;
    case 3:
    {
        cin>>key;
        h.del(key);
    }
        break;
    case 4:
        h.print();
    }
    }
    return 0;
}
