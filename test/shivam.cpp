#include <iostream>
#include <string>
#include <assert.h>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <iterator>
#include <limits>

using namespace std;

typedef pair <int, int> pair1;

class Graph
{
    private:
        int vertices;
        list <pair <int, int> > * adj;
    public:
        //vector<int> distancefinal;
        Graph (int n)
        {
            vertices = n;
            adj = new list <pair1> [vertices];
            //distancefinal = new vector <int> (vertices, -1);
        }
        void addEdge (int a, int b, int w)
        {
            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
        }
        void shortestPath (int x, vector <int> &distance)
        {
            //vector <int> distance(vertices, -1);
            priority_queue <pair1, vector<pair1>, greater<pair1> > pq;
            pq.push(make_pair(0, x));

            distance[x]=0;
            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();

                list <pair <int, int> >::iterator itr;
                for (itr=adj[u].begin(); itr!=adj[u].end(); ++itr)
                {
                    int v = (*itr).first;
                    int w = (*itr).second;
                    if (distance[v]==-1 || distance[v]>distance[u] + w)
                    {
                        distance[v] = distance[u] + w;
                        pq.push(make_pair(distance[v],v));
                    }
                   /* if (distance[v]>distance[u] + w)
                    {
                        distance[v] = distance[u] + w;
                        pq.push(make_pair(distance[v],v));
                    }*/
                }
            }
           // distancefinal=distance;
             /*int l;
    cin >> l;
        int updateto=-1;
            for(int i = 0; i < l; i++){
        // scan over every car to get the final answer
        int locay;
        cin>>locay;
        cout<<endl;
        cout<<distance[locay]<<"...distance..."<<locay<<endl;
        if (bestv==-1 && (distance[locay]!=0 && distance[locay]!=-1))
        {
            bestv=distance[locay];
            updateto=locay;
        }
        else if (bestv>distance[locay] && distance[locay]!=-1 && distance[locay]!=0)
        {
            bestv=distance[locay];
            updateto=locay;
        }
    }
    bestv=updateto;*/
        }
};

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

    int bestv = -1;
    vector <int> distance(n, -1);
    // implement your own shortest path
    g.shortestPath(u, distance);

  /*  int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        // scan over every car to get the final answer
        int locay;
        cin>>locay;
        if (bestv==-1 && distance[locay].first!=0)
            bestv=distance[locay].first;
        else if (bestv>distance[locay].first)
        {
            bestv=distance[locay].first;
        }
    }*/
    int l;
    cin >> l;
    int updateto=-1;
    for(int i = 0; i < l; i++)
    {
        // scan over every car to get the final answer
        int locay;
        cin>>locay;
        //if (bestv==-1 && (distance[locay]!=0 && distance[locay]!=-1))
        //{
          //  bestv=distance[locay];
         //   updateto=locay;
        //}
        //else if
        if(bestv>distance[locay] || bestv == -1)//&& distance[locay]!=-1 && distance[locay]!=0)
        {
            bestv=distance[locay];
            updateto=locay;
        }
    }

    bestv=updateto;
    if(bestv == -1)
        cout << "NO" << endl;
    else
        cout << bestv << endl;
    return;
}


void QueryPrice(){
    //your code starts here
       int n, m;

    cin >> n >> m;

    Graph g(n); // implement Graph class by yourself

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }


    // implement your own shortest path
    int k;
    cin>>k;
    vector <int> bestv(k,-1);
    for (int i=0; i<k; i++)
    {
        vector <int> distance(n, -1);
        int u;
        cin>>u;
        int locay;
        cin>>locay;
        g.shortestPath(u, distance);

        if (bestv[i]==-1)
        {
            bestv[i]=distance[locay];
        }
        distance.clear();

    }

    for (int i=0; i<k; i++)
    {
        if(bestv[i] == -1)
            cout << "NO" << endl;
        else
            cout << bestv[i] << endl;
    }
    return;

}

void Diameter(){
 /*   //your code starts here
    int n, m;
    cin>>n>>m;

    Graph g(n);

    int initial;

    for (int i=0; i<m; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        g.addEdge(a, b, w);
        intial = a;
    }

*/
}

void DiameterApproximation(){
    //your code starts here
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