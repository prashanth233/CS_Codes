#include <bits/stdc++.h>
using namespace std;

class BloomBrain{
  public:
    int n;
    int a[100005]={0};
    int temp[100005]={0};
    int unocc[100005]={0};
    int last;
    int tot=0;
    
    long long int divconquer(int start,int end){
        if(start>=end) return 0;
        
        int mid=(start+end)/2;
        long long int t1=divconquer(start,mid);
        long long int t2=divconquer(mid+1,end);
        long long int count=t1+t2;
        int tempo[end-start+1];
        int ti=0;
        int i=start;
        int j=mid+1;;
        for(;i<=mid && j<=end;){
                if(temp[j]<temp[i]) {
                    count+=(mid+1-i);
                    tempo[ti++]=temp[j];
                    j++;
                }
                else {
                    tempo[ti++]=temp[i];
                    i++;
                }
            
        }
        
        if(i>mid){
            for(;j<=end;j++) tempo[ti++]=temp[j];
        }
        
        else {
            for(;i<=mid;i++) tempo[ti++]=temp[i];
        }
        
        for(int k=0;k<=end-start;k++) temp[k+start]=tempo[k];
        
       return count;
    }
    
    int divconq(int start, int end){
        if(start==end){
            if(a[start]<0) return 0;
            else return a[start];
        }
        int mid=(start+end)/2;
        int ans=divconq(start,mid);
        int ans1=divconq(mid+1,end);
        if(ans1>ans) ans=ans1;
        
        int curmax=0;
        int ans2=0;
        for(int i=mid+1;i<=end;i++){
            if(curmax>ans2) ans2=curmax;
            curmax+=a[i];
        }
        if(curmax>ans2) ans2=curmax;
        
        curmax=0;
        int ans3=0;
        for(int i=mid;i>=start;i--){
            if(curmax>ans3) ans3=curmax;
            curmax+=a[i];
        }
        if(curmax>ans3) ans3=curmax;
        
        if(ans2+ans3>ans) ans=ans2+ans3;
        
        return ans;
        
    }
    
    void update(int b[]){ /*It will take an array of size N as input which indicates the corresponding seraphic number of members*/
        tot=0;
        for(int i=0;i<n;i++) {a[i]=b[i];
                             if(unocc[i]==0) temp[tot++]=a[i];}
        cout<<divconquer(0,tot-1)<<endl;
    }
    
    void join(int x){   /*It will take one integer value as input which indicates the initial seraphic number of the new joining member*/                      /*This new member will be given the last (highest number) unoccupied room*/
        int i;
        for(i=0;i<n && unocc[i]==0;i++);
        if(i==n) return;
        a[last]=x; unocc[last]=0;
        for(i=last-1;i>=0;i--){
            if(unocc[i]==1) {last=i; return;}
        }
        last=n;
    }
    
    void leave(int x){  /*It will take one integer value as input, the member occupying that room number will leave the centre*/
        a[x]=0;
        unocc[x]=1;
        if(x>last || last>=n) last=x;
    }
    
    int occupied(){ /*This will output the number of existing members in the centre*/
        int count=0;
        for(int i=0;i<n;i++){
            if(unocc[i]==0) count++;
        }
        return count;
    }
    
    int play(){
        return divconq(0,n-1);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    BloomBrain b;
    b.n=n;
    b.last=n;
    int q;
    cin>>q;
    string temp;
    while(q--){
        cin>>temp;
        if(temp=="update"){ /*for this query in the next line there will be N values, each separated by a single space*/
            int a[n];
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            b.update(a);
        }
        else if(temp=="join"){  /*for this query there will be a value s in the same line*/
            int temp;
            cin>>temp;
            b.join(temp);
        }
        else if(temp=="leave"){ /*for this query there will be a value idx in the same line*/
            int temp;
            cin>>temp;
            b.leave(temp);
        }
        else if(temp=="occupied"){  /*print the number of quality talks possible between existing members*/
            cout<<b.occupied()<<endl;
        }
        else cout<<b.play()<<endl;  /*print the minimum seraphic number of the guru such that the guru will not lose even against the best                              possible group*/
    }
    return 0;
}
