#include<bits/stdc++.h>
using namespace std;

int vis[105][105];  // matrix to store visited edges during runtime
int comp(int set) {
    int c = set & -set;
    int r = set + c;
    set = (((r^set)>>2)/c)|r;
    return set;
}

bool check_cover(int V,int k,int E,int arr[105][105]) {
    int set = pow(2,k)-1;
    int limit = pow(2,V);
    for (;limit > set;) {
        int count=0;
        for (int i=0;i<105;i++) {
            for (int j=0;j<105;j++)
                vis[i][j]=0;
        }
        int j=1,v=1;
        while (limit > j) {
            if (!(set & j)) {}
            else {
                int k=1;
                while (V >= k) {
                    if ((!(arr[v][k])) || vis[v][k]) {}
                    else {
                        vis[v][k]=1;
                        vis[k][v]=1;
                        count++;
                    }
                    ++k;
                }
            }
            ++v; j*=2;
        }
        int rem = count-E;
        if (!rem)
            return 1;
        set = comp(set);
    }
    return 0;
}

int find_cover(int n, int m, int arr[105][105]) {
    int left=1, right=n;    // we use similar logic as finding the minimum vertex cover, with binary search
    for (;right > left;) {
        int mid = (left + right)/2;
        if (check_cover(n, mid, m, arr) == 1)
            right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int arr[105][105];  // graph is stored here
    for (int i=0;i<105;i++) {
        for (int j=0;j<105;j++) // graph initialised to a graph with zero edges
            arr[i][j]=0;
    }
    int V,E,t1,t2;
    cin>>V>>E;
    if(E==0) {
        cout<<V;
        return 0;
    }
    for (int i=0;i<E;i++) {
        cin>>t1>>t2;
        arr[t1+1][t2+1]=1;  // updating edges in graph
        arr[t2+1][t1+1]=1;
    }
    cout<<V - find_cover(V, E, arr) <<endl;
    return 0;
}
