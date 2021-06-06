#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* prev;
};

class Stack{                // A class "Stack" which implements a stack using a linked list.
    node* topele=NULL;      // topele => TopElement (which is intialised to "0".
    
 public:
    void push(int x){       // We are creating a "Push" function, Pushing an integer "x" into the stack.
        node* temp=new node;
        temp->val=x;
        temp->prev=topele;
        topele=temp;
    }
    
    int pop(){              // We are creating a "PoP" function.
        if(topele){
            int temp=topele->val;   // Pop the last element inserted in the stack and we are "returning it".
            topele=topele->prev;
            return temp;
        }
        return -1;          // If the stack is empty "return -1".
    }
    int top(){              // We are creating a "Top" function.
        if(topele) return topele->val;  // Return the last element inserted in the stack, "without poping it".
        return -1;          // If the stack is empty return -1.
    }
    int empty(){            // We are creating an "Empty" function.
        if(topele) return 0;    // If the stack is empty, "Return 1". Else, "Return 0".
        return 1;
    }
};

class Graph{                // A class "Graph" which stores an "undirected simple graph G(V, E) with |V|= n vertice".
    int n;                  // n as "vertices".
    int adj[101][101];      // Adjacency Matrix.
    
public:                     // Constructor.
    Graph(int m){           // Takes "n=m" as parameter and initializes the adjacency matrix with all entries as "0".
        n=m;
        for(int ii=0;ii<n;ii++){
            for(int jj=0;jj<n;jj++){
                adj[ii][jj]=0;
            }
        }
    }
    
    void operator += (pair<int,int> p){ // Here we are adding an edge (u, v) to the same graph object G.
        adj[p.first][p.second]=1;       //  If the edge (u, v) is already present, do nothing [0 <= u,v <= n-1].
        adj[p.second][p.first]=1;
    }
    
    void operator -= (pair<int,int> p){ // Here we are deleting an edge (u, v) from the same graph object G.
        adj[p.first][p.second]=0;       // If the edge (u, v) is not present, do nothing [0 <= u,v <= n-1].
        adj[p.second][p.first]=0;
    }
    
    int helper(int a, int visited[], int b){      // Here we created an "Helper Function".
        visited[a]=1;
        for(int i=0;i<n;i++){
            if(adj[a][i]==1 && visited[i]==0){
                if(helper(i, visited, a)) return 1;
            }
            else if(adj[a][i]==1 && i!=b)
                return 1;
        }
        return 0;
    }
    
    int components(){       // With the help of DFS, we calculate the number of connected components in the graph.
        int visited[n];
        for(int i=0;i<n;i++) {visited[i]=0;}
        int result=0;
        for(int i=0;(i<n);i++){
            if(visited[i]==1) continue;
                result++;
                Stack dfs;
                dfs.push(i);
                visited[i]=1;
                while(!dfs.empty()){
                    int x=dfs.pop();
                    for(int j=0; j<n;j++){
                        if((adj[x][j]==1) && (visited[j]==0)){
                        visited[j]=1;
                        dfs.push(j);
                        }
                    }
                }
        }
        return result;
    }
    
    int reach(pair<int,int> p){     // If there is a path from u to v using DFS, then "Return 1" else return "0".
        int visited[n];
        for(int i=0;i<n;i++) { visited[i]=0;}
                Stack dfs;
                for(int i=0;i<n;i++){
                    if(adj[i][p.first]) {if(i==p.second) return 1;
                                         visited[i]=1; dfs.push(i);}
                }
                while(!dfs.empty()){
                    int x=dfs.pop();
                    if(x==p.second) return 1;
                    for(int j=0; j<n;j++){
                        if((adj[x][j]==1) && (visited[j]==0)){
                        visited[j]=1;
                        dfs.push(j);
                        }
                    }
                }
        return 0;
    }
    
    int cycle(){        // Using DFS, if the graph has any cycle, "Return 1". else "0".
        int *visited= new int[n];
        for(int i=0;i<n;i++) { visited[i]=0;}
        for(int i=0;i<n; i++){
            if( visited[i]==0)
            {
                if(helper(i,visited,-1)){
                return 1;
                }
            }
        }
        return 0;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    Stack s;            // "q" The number of operations to be performed on the stack.
    string op;          // "op => Operation"
    cin>>q;
    for(int ii=0;ii<q;ii++){
       cin>>op;
        if(op=="push"){
            int x;
            cin>>x;
            s.push(x);
        }
        if(op=="pop"){
            cout<<s.pop()<<endl;
        }
        if(op=="top"){
            cout<<s.top()<<endl;
        }
        if(op=="empty"){
            cout<<s.empty()<<endl;
        }
    }

    int n;
    cin>>n;
    Graph g(n);         // The input contains an integer "n" denoting the number of vertices in the graph.
    int m;              // An integer "m" denotes the number of graph operations to be performed.
    cin>>m;
    for(int ii=0;ii<m;ii++){
        cin>>op;
        if(op=="add"){
            pair<int,int> p;
            cin>>p.first>>p.second;
            g+=p;
        }
        if(op=="del"){
            pair<int,int> p;
            cin>>p.first>>p.second;
            g-=p;
        }
        if(op=="cycle"){
            cout<<g.cycle()<<endl;
        }
        if(op=="components"){
            cout<<g.components()<<endl;
        }
        if(op=="reach"){
            pair<int,int> p;
            cin>>p.first>>p.second;
            cout<<g.reach(p)<<endl;
        }
    }
    return 0;
}

