#include <bits/stdc++.h>
using namespace std;

pair<int,int> temp;

class Graph{
    public:
    int v=0;
    list <pair<int,int>> adj[500];
    
    void addv(){
        v++;
    }
    
    void adde(int a,int b, int w){
        temp.first=w;
        temp.second=b;
        adj[a].push_back(temp);
        temp.second=a;
        adj[b].push_back(temp);
        }
    
    void dele(int a,int b){
        
        list <pair<int,int>> :: iterator it;
        for(it = adj[a].begin(); it != adj[a].end(); ++it){
            if((*it).second==b) {adj[a].remove(*it); break;}
        }
        for(it = adj[b].begin(); it != adj[b].end(); ++it){
            if((*it).second==a) {adj[b].remove(*it); break;}
        }
    }
    
    void bfs(int a){
        bool *visited=new bool[v];
        for(int i = 0; i < v; i++)
        visited[i] = false;
        
        list<int> queue;
        
        visited[a]=true;
        queue.push_back(a);
        
        list<pair<int,int>>::iterator i;
 
    while(!queue.empty())
    {
        int s = queue.front();
        cout << s << " ";
        queue.pop_front();
        adj[s].sort();
      for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            int tem=(*i).second;
            if (!visited[tem])
            {
                visited[tem] = true;
                queue.push_back(tem);
            }
        }
    }
        cout<<endl;
    }
    
    void ssp(int a){
        int d[v];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        list<pair<int,int>>::iterator i;
        int j=0;
        while(j<v) {
            d[j]=INT_MAX;
            j++;
        }
        d[a]=0;
        pair<int,int> tem;
        tem.first=0;
        tem.second=a;
        q.push(tem);
        
        while(!q.empty()){
            int t=q.top().second;
            q.pop();
            for (i = adj[t].begin(); i != adj[t].end(); ++i){
                int f=(*i).second;
                int w=(*i).first;
                if(d[f]>d[t]+w){
                    d[f]=d[t]+w;
                    pair<int,int> p;
                    p.first=d[f];
                    p.second=f;
                    q.push(p);
                }
            }
        }
        j=0;
        while(j<v){
            cout<<d[j]<<" ";
            j++;
        }
        cout<<endl;
        
        
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Graph g;
    cin>>g.v;
    int q;
    cin>>q;
    string str;
    while(q--){
        cin>>str;
        if(str=="ADDV"){
            g.addv();
        }
        else if(str=="ADDE"){
            int a,b,w;
            cin>>a>>b>>w;
            g.adde(a,b,w);
        }
        else if(str=="DELE"){
            int a,b;
            cin>>a>>b;
            g.dele(a,b);
        }
    }
    q=2;
    while(q--){
        cin>>str;
        if(str=="BFS"){
            int a;
            cin>>a;
            g.bfs(a);
        }
        else if(str=="SSP"){
            int a;
            cin>>a;
            g.ssp(a);
        }
    }
    return 0;
}

