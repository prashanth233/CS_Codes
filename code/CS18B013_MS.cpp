#include <bits/stdc++.h>
using namespace std;

class Batsman{      /* Here we have created a batsman class */
    public:
     int id;
     int runs;
     int matches;
     int balls;
     int no;
     int visited;
     float performance;

     bool operator < (Batsman b){
        if(performance < b.performance)
            return true;
        else
            return false;
    }
};

int b[1000];

void sort(int n, Batsman a[]){      /* Sort function for comparing two objects */
    for(int i=0;i<n;i++){
        int minindex;
        int flag=0;
        
    for(int j=0;j<n;j++){
        if((flag==0) || (a[j] < a[minindex])) {
            if((a[j].visited)==0){
                minindex=j;
                flag=1;
            }
        }
    }
        cout<<a[minindex].id<<" "<<a[minindex].matches<<" "<<a[minindex].runs<<" "<<a[minindex].no<<" "<<a[minindex].balls<<endl;
        a[minindex].visited=1;
        b[i]=minindex;
    }
}

void farthest(int n,Batsman a[],int k){     /* Here we are creating farthest function */
    int start=0;
    int end=n-1;
    int l=k;
    int e[k];
    float temp=a[b[n/2]].performance;
    
    while(k--){
        float c=a[b[start]].performance;
        float d=a[b[end]].performance;
        if((temp-c) > (d-temp)){
            e[k]=a[b[start]].id;
            start++;
        }
        else{
            e[k]=a[b[end]].id;
            end--;
        }
    }
    for(int t=0;t<l;t++){
        int mini=1005;
        int minind=-1;
    for(int r=0;r<l;r++){
        if(e[r]<mini) {
            mini=e[r];
            minind=r;
        }
    }
        cout<<mini<<" ";
        e[minind]=1005;
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;      /* Number "n" that will represent number of records */
    cin>>n;
    Batsman a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i].id>>a[i].matches>>a[i].runs>>a[i].no>>a[i].balls;
        a[i].visited=0;
        a[i].performance=float(a[i].runs)/float(a[i].balls);
    }
    int t;      /* Represents the number of operations "t" */
    cin>>t;
    string temp;
    
    for(int i=0;i<t;i++){
        cin>>temp;
        if(temp=="Sort"){       /* Sort the records on the basis of Performance metric */
            sort(n,a);
        for(int q=0;q<n;q++)
            a[q].visited=0;
        }
        if(temp=="X"){      /* Print k farthest players’ records */
            int k;
            cin>>k;
            farthest(n,a,k);
        }
    }
    return 0;
}
