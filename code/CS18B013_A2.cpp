#include<bits/stdc++.h>
using namespace std;
typedef int ll;

class Matrix{ // This is the base class
 public:
    ll n; // Here n is a number of rows
    ll m; // Here m is a number of coloumns
    ll *a[100005];
    ll binarySearch(ll X, ll k){
       int start = 0;
    int end = n - 1;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[k][mid] == X)
        {
            for(int w=mid;w<n;w++){ if(a[k][w]>X) return w-1;}
            return n-1;
        }
        else if (a[k][mid] < X)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end;
    }
    ll binarySearch1(ll X, ll k){
       int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[k][mid] == X)
        {
            for(int w=mid;w>=0;w--){ if(a[k][w]<X) return w+1;}
            return 0;
        }
        else if (a[k][mid] < X)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end;
    }
    void matrixSearch(ll x){
        for(ll jj=0;jj<m;jj++){
        ll temp=binarySearch1(x,jj);
        if(temp!=-1 && a[jj][temp]==x) {cout<<jj<<" "<<temp<<endl; return;}
        }
        cout<<-1<<" "<<-1<<endl;
    }
};

class MatrixMedian: public Matrix { // This is the derived class
    public:
    ll upperBound(ll x, ll k){
            ll temp=binarySearch(x,k);
            if(a[k][temp]==x) temp++;
            return temp;
        }
    ll findMedian(){
            int r=m;
            int c=n;
            int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<m; i++)
    {
        // Finding the minimum element
        if (a[i][0] < min)
            min = a[i][0];

        // Finding the maximum element
        if (a[i][n-1] > max)
            max = a[i][n-1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(a[i], a[i]+c, mid) - a[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll m,n;
    MatrixMedian p; // This (p) is object of the derived class
    cin>>m>>n;
    for(ll k=0;k<m;k++) p.a[k]=new int[n];
    p.m=m;
    p.n=n;
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++)
            cin>>p.a[i][j];
    }
    ll q; // Here q is number of queries
    cin>>q;
    for(ll i=0;i<q;i++){
        string temp;
        cin>>temp;
        if(temp=="BS") {
            ll ta,tb;
            cin>>ta>>tb;
            ll tc=p.binarySearch(ta, tb);
            cout<<tc<<endl;
        }
        if(temp=="MS") {
            ll ta;
            cin>>ta;
            p.matrixSearch(ta);
        }
        if(temp=="Median") {
            
            ll tc=p.findMedian();
            cout<<tc<<endl;
        }
    }
    return 0;
}
