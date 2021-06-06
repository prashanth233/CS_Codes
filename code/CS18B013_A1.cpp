#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class mtrx
{
    public:
    int n;
    int a[50][50]={0};
    
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i;
    string e;
    cin>>i;
    int j;
    cin>>j;
    mtrx c,d;
    c.n=j;
    d.n=j;
    for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++)
            cin>>c.a[ii][ij];
    }
    for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++)
            cin>>d.a[ii][ij];
    }
    for(int ii=0;ii<i;ii++){
        cin>>e;
        if(e=="SPSUM"){
            mtrx tem;
            tem.n=c.n;
            for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++)
        {  if((ii+ij)%2) tem.a[ii][ij]=c.a[ij][ii];
                else tem.a[ii][ij]=c.a[ii][ij];}
    }
            for(int ii=0;ii<j;ii++){
                int count=0;
        for(int ij=0;ij<j;ij++)
        {
            count+=tem.a[ii][ij];
            
        }
                cout<<count;
                if(ii<j-1) cout<<",";
    }
            cout<<endl;
            
        }
        if(e=="MOD"){
            int count=1;
            for(int ii=0;ii<j;ii++){
                if(ii%3==0){
                    int max=INT_MIN;
        for(int ij=0;ij<j;ij++)
        {
            if(max<c.a[ii][ij]) max=c.a[ii][ij];
        }
                    count*=max;
    }
                if(ii%3==1){
        
             int min=INT_MAX;
        for(int ij=0;ij<j;ij++)
        {
            if(min>c.a[ii][ij]) min=c.a[ii][ij];
        }
                    count*=min;
        
    }
                if(ii%3==2){
         int sum=0;
        for(int ij=0;ij<j;ij++)
        {
            sum+=c.a[ii][ij];
        }
                    count*=(sum)/c.n;
    }
            
            }
            cout<<count<<endl;
        }
        if(e=="MRS"){
            int k;
            cin>>k;
            mtrx f;
             for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            f.a[ii][ij]=d.a[ii][ij]+c.a[ii][ij];
        }
        }
         mtrx g;
             for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            int ji=((ii*j+ij+k)/j)%j; int jj=(ii*j+ij+k)%j;
            g.a[ji][jj]=f.a[ii][ij];
        }
        }
            for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            cout<<g.a[ii][ij]<<" ";
        }
                 cout<<endl;
             }
        }
        if(e=="MADD"){
            int k;
            cin>>k;
            mtrx f;
            if(k==1){
                
                for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            f.a[ii][ij]=c.a[ij][ii]+d.a[ii][ij];
        }
                }
            }
            if(k==2){
               
                for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            f.a[ii][ij]=d.a[ij][ii]+c.a[ii][ij];
        }
                }
            }
             for(int ii=0;ii<j;ii++){
        for(int ij=0;ij<j;ij++){
            cout<<f.a[ii][ij]<<" ";
        }
                 cout<<endl;
             }
        }
    }
    return 0;
}
