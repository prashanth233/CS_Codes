#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int n;
    int a[50][50]={0};  // two graphs initiliased to a ..
    int b[50][50]={0};  // .. a graph with zero edges
    void add() {
        int count=0;    // counter which stores no. of edges in new graph initialised to zero
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (a[i][j] || b[i][j])
                    count++;    // updating counter based on if edges follow the condition for existence in the new graph
            }
        }
        cout<<count/2<<endl;
    }
    
    void sub() {
        int count=0;    // counter which stores no. of edges in new graph initialised to zero
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (a[i][j] && (!b[i][j]))   // updating counter based on if edges follow the condition for ->
                    count++;                 // -> existence in the new graph
            }
        }
        cout<<count/2<<endl;
    }
    
    void div() {
        int count=0;    // counter which stores no. of edges in new graph initialised to zero
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (a[i][j] || ((i!=j) && (!(b[i][j]))))    // updating counter based on if edges follow the ->
                    count++;                                // -> condition for existence in the new graph
            }
        }
        cout<<count/2<<endl;
    }
    
    void tensor() {
        int count=0;    // counter which stores no. of edges in new graph initialised to zero
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<n;k++) {
                    for (int l=0;l<n;l++) {
                        if (a[i][j] && b[k][l]) // updating counter based on if edges follow the condition for ->
                            count++;            // -> existence in the new graph
                    }
                }
            }
        }
        cout<<count/2<<endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Graph g;
    cin>>g.n;   // number of vertices
    int d,u,v;
    cin>>d;
    while (d--) {
        cin>>u>>v;
        g.a[u][v]=1;    // updating edges of first graph
        g.a[v][u]=1;
    }
    cin>>d;
    while (d--) {
        cin>>u>>v;
        g.b[u][v]=1;    // updating edges of second graph
        g.b[v][u]=1;
    }
    g.add();    // calling all 4 functions
    g.sub();
    g.div();
    g.tensor();
    return 0;
}

