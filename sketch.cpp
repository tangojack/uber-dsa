#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <list>
#include <utility>
#include <queue>

using namespace std;

class Graph{
    public:
        vector<vector<pair <int, int> > > adjacency_list;
        vector<int> distance;
    
        Graph(int n){
            vector<pair <int, int> > v;
            for (int i = 0; i < n; i++){
                adjacency_list.push_back(v);
            }
        }
        void addEdge(int u, int v, int weight);
        void shortestPath(int u);
};

void Graph::shortestPath(int u){
    vector<int> visited;
    priority_queue<pair<int, int> > pq; 
    for (int i = 0; i < (int)adjacency_list.size(); i++){
        if (i == u){
            distance.push_back(0);
        }
        else{
            distance.push_back(-1);
        }   
    }

    pq.push(make_pair(distance[u], u));
    int v;
    int flag;

    while(visited.size() < adjacency_list.size()){
        u = pq.top().second;
        pq.pop();

        visited.push_back(u);
        for (int j = 0; j < (int)adjacency_list[u].size(); j++){
            v = adjacency_list[u][j].first;
            flag = 0;
            for (int i = 0; i < (int)visited.size(); i++){
                if (v == visited[i])
                    flag = 1;
            }

            if (flag == 0){
                if (distance[v] > distance[u] + adjacency_list[u][j].second || distance[v] == -1){
                    distance[v] = distance[u] + adjacency_list[u][j].second;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
    }
}

void Graph::addEdge(int u, int v, int weight){
    adjacency_list[u].push_back(make_pair(v, weight));
    adjacency_list[v].push_back(make_pair(u, weight));
}

void NearestDriver(){
    int n, m;

    cin >> n >> m;
    
    Graph g(n); // implement Graph class by yourself
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }

    int u;
    cin >> u;
    // implement your own shortest path
    g.shortestPath(u);

    int bestv = -1;
    int l;
    cin >> l;

    int car_loc;
    int least;
    int flag;
    for(int i = 0; i < l; i++){
        // scan over every car to get the final answer
        flag = 0;
        cin >> car_loc;
        if (g.distance[car_loc] == -1)
            flag = 1;
        
        if (flag == 0 && least > g.distance[car_loc]){
            least = g.distance[car_loc];
            bestv = car_loc;
        }
    }

    if(bestv == -1)
        cout << "NO" << endl;
    else
        cout << bestv << endl;
    return;
}

void QueryPrice(){
    int n, m;

    cin >> n >> m;
    
    Graph g(n); // implement Graph class by yourself
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }

    int queries;
    cin >> queries;
    vector<int> u, v;
    int a, b;
    // implement your own shortest path
    for (int i = 0; i < queries; i++){
        cin >> a >> b;
        u.push_back(a);
        v.push_back(b);
    }
    for (int i = 0; i < queries; i++){
        g.distance.clear();
        g.shortestPath(u[i]);
        if (g.distance[v[i]] == -1){
            cout << "NO" << endl;
        }
        else {
            cout << g.distance[v[i]] << endl;
        }
    }
    return;
}

void Diameter(){
    int n, m;

    cin >> n >> m;
    
    Graph g(n); // implement Graph class by yourself
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }

    int max = 0;
    vector<pair<int, int> > pairs;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            pairs.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < (int)pairs.size(); i++){
        g.distance.clear();
        g.shortestPath(pairs[i].first);

        if (g.distance[pairs[i].second] == -1){
            cout << "INF" << endl;
            break;
        }
        else if (g.distance[pairs[i].second] > max){
            max = g.distance[pairs[i].second];
        }
    }
    cout << max << endl;
    return;
}

void DiameterApproximation(){
    int n, m;

    cin >> n >> m;
    
    Graph g(n); // implement Graph class by yourself
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }

    int diameter = 0;
    int max = 0;
    int flag = 0;
    int index = 0;
    for (int i = 0; i < 2; i++){
        g.distance.clear();
        g.shortestPath(index);
        for (int j = 0; j < n; j++){
            if (g.distance[j] == -1){
                cout << "INF" << endl;
                flag = 1;
                break;
            }
            else if (max < g.distance[j]){
                max = g.distance[j];
                index = j;
            }
        }
        if (diameter < max){
            diameter = max;
        }
        if (flag == 1){
            break;
        }
    }
    if (flag == 0)
        cout << diameter << endl;
    return;
}

int main(){
    string section;
    cin >> section;

    if(section == "NearestDriver")    
        NearestDriver();
    else if(section == "QueryPrice")    
        QueryPrice();
    else if(section == "Diameter")    
        Diameter();
    else if(section == "DiameterApproximation")    
        DiameterApproximation();
    else{
        cout << "wrong input file!" << endl;
        assert(0);
    }

    return 0;   
}
