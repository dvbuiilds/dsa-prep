#include<bits/stdc++.h>

using namespace std;

struct graphnode{
    int val;
    bool status;

    graphnode();
};

graphnode::graphnode(){
    status = false;
    cout<<"Status set to False"<<endl;
}

void addedgenew(vector<graphnode> * & graph, int u, int v){
    graphnode node;
    node.val = v;
    graph[u].push_back(node);
}

void addtwoedgenew(vector<graphnode> * & graph, int u, int v){
    graphnode node1;
    node1.val = v;
    graph[u].push_back(node1);
    graphnode node2;
    node2.val = u;
    graph[v].push_back(node2);
}

void printingnew(vector<graphnode> *graph, int v){
    for(int i =0; i<v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<<graph[i][j].val<<": ";
        }
        cout<<endl;
    }
}

void bfs(vector<graphnode> * graph, int V){     //time complexity: O()
    vector<bool> status(V, false);
    queue<int> bfsq;
    bfsq.push(0);

    while(!bfsq.empty()){
        int node = bfsq.front();
        status[node] = true;
        for(int i =0; i<graph[node].size(); i++){
            //cout<<graph[node][i].val<<endl;
            if(status[graph[node][i].val] == false ) {
                //cout<<"Pushed"<<endl;
                bfsq.push(graph[node][i].val);
                status[graph[node][i].val] = true;
            }
        }
        cout<<node<<" is visited"<<endl;
        bfsq.pop();
    }
}

void dfs(vector<graphnode> * graph, int x, vector<bool> & status, int V){
    if(status[x]) return;

    cout<<x<<endl;
    status[x] = true;

    for(int i =0; i<graph[x].size(); i++){
        int elem = graph[x][i].val;
        if(status[elem] == false) {
            dfs(graph, elem, status, V);
        }
    }

}

stack<int> topological;

void topologicalsort(vector<graphnode> * & graph, int V, vector<bool> & status, int x){
    
    status[x] = true;
    for(int i = 0; i<graph[x].size(); i++){
        int elem = graph[x][i].val;
        if(status[elem] == false){
            topologicalsort(graph, V, status, elem);
        }
    }
    cout<<x<<endl;
}
//<-----------------------Simple List Functions ------------------------------>

void addtwoedge(vector<int> * graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void addedge(vector<int> *graph, int u, int v){
    graph[u].push_back(v);
}

void printinggraph(vector<int> *graph, int v){
    for(int i =0; i <v; i++){
        cout<< i <<" -> ";
        for(int j = 0; j<graph[i].size(); j++){
            cout<< graph[i][j] <<", ";
        }
        cout<<endl;
    }
}