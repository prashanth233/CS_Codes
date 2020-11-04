//
//  Dijkstra's shortest path algorithm.cpp
//  
//
#include<bits/stdc++.h>
using namespace std;
#define INT_MA 10000

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int dist[1005];
int mapheap[1005];

class minh {
    public:
     int len=0;
     int arr[1005];
     void insert(int x);
     void delete1();
     void update(int x);
     
     
};

void minh :: insert (int x){
    
    arr[len]=x;
    int temp1;
    temp1=len;
    len++;
    while(temp1>0){
        if(dist[arr[temp1/2]]>dist[arr[temp1]]){
            mapheap[arr[temp1]]=temp1/2;
            mapheap[arr[temp1/2]]=temp1;
            int temp2=arr[temp1];
            arr[temp1]=arr[temp1/2];
            arr[temp1/2]=temp2;
            temp1=temp1/2;
        }
        else return ;
    }
    return;
}

void minh :: delete1()
{   if(len==0) return;
    int temp1;
    arr[0]=arr[len-1];
    len--;
    temp1=0;
    while(temp1<len/2){
       
        if(dist[temp1*2+2]<dist[temp1*2+1]){
            if(dist[temp1*2+2]<dist[temp1]){
             mapheap[arr[temp1*2+2]]=temp1;
            mapheap[arr[temp1]]=temp1*2+2;
            int temp2=arr[temp1];
            arr[temp1]=arr[temp1*2+2];
            arr[temp1*2+2]=temp2;
            temp1=temp1*2+2;}
            else return;
        }
        else {
            if(dist[temp1*2+1]<dist[temp1]){
            mapheap[arr[temp1*2+1]]=temp1;
            mapheap[arr[temp1]]=temp1*2+1;
            int temp2=arr[temp1];
            arr[temp1]=arr[temp1*2+1];
            arr[temp1*2+1]=temp2;
            temp1=temp1*2+1;}
            else return;
        }
    }
}

void minh :: update (int x){
    int temp1=x;
     while(temp1>0){
        if(dist[arr[temp1/2]]>dist[arr[temp1]]){
            mapheap[arr[temp1]]=temp1/2;
            mapheap[arr[temp1/2]]=temp1;
            int temp2=arr[temp1];
            arr[temp1]=arr[temp1/2];
            arr[temp1/2]=temp2;
            temp1=temp1/2;
        }
        else return ;
    }
    return;
    
}

class graph{
    public:
     int n=0;
     int g[1005][1005];
    
    
    int flag[1005]={0};
     void dijkstra();
};

void graph :: dijkstra(){
    
    dist[0]=0;
    for(int j=1;j<n;j++) dist[j]=g[0][j];
    for(int j=n;j<1005;j++) dist[j]=INT_MA;
    int temp=n;
    minh h;
   
    for(int ll=1;ll<n;ll++) {h.insert(ll);}
    
   
    while(--temp) {
        int mint=INT_MA;
       int min_index=h.arr[0];
       for(int ii=1;ii<n;ii++) {
            if(dist[ii]<mint && flag[ii]==0) {
               min_index=ii;
               mint=dist[ii];
          }
        }
        
        
        flag[min_index]=1;
       // for(int qq=0;qq<h.len;qq++) cout<<h.arr[qq]<<endl;
        h.delete1();
        
        for(int jj=1;jj<n;jj++){
            if(flag[jj]==0) {
                dist[jj]=min(dist[jj],dist[min_index]+g[min_index][jj]);
                h.update(mapheap[jj]);
            }
        }
      
    }
    for(int kk=0;kk<n;kk++) cout<<kk<<" "<<dist[kk]<<endl;
}

int main(){
    
    
    graph f;
    cin>>f.n;
    int e;
    cin>>e;
    int x,y,z;
    for(int i=0;i<f.n;i++) {
        for(int j=0;j<f.n;j++) f.g[i][j]=INT_MA;
    }
    for(int i=0;i<e;i++){
        cin>>x>>y>>z;
        f.g[x][y]=z;
        f.g[y][x]=z;
    }
    f.dijkstra();
    return 0;
    
    

}
