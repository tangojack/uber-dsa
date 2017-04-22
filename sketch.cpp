#include <iostream>
#include <string>
#include <assert.h>


using namespace std;


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
    for(int i = 0; i < l; i++){
        // scan over every car to get the final answer
    }

    if(bestv == -1)
        cout << "NO" << endl;
    else
        cout << bestv << endl;
    return;
}


void QueryPrice(){
    //your code starts here
}

void Diameter(){
    //your code starts here
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
