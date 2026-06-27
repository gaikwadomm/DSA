#include<bits/stdc++.h>
using namespace std;



int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    // Undirected Unweighted Graph
    vector<int> AdjListUnweighted[vertex];

    int u,v ;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        AdjListUnweighted[u].push_back(v);
        AdjListUnweighted[v].push_back(u);
    }

    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<AdjListUnweighted[i].size();j++){
            cout<<AdjListUnweighted[i][j]<<"->";
        }
        cout<<endl;
    }

    // Undirected Weighted Graph
    vector<pair<int,int>> AdjListWeighted[vertex];

    int u2,v2,weight ;
    for(int i=0;i<edges;i++){
        cin>>u2>>v2>>weight;
        AdjListWeighted[u2].push_back({v2,weight});
        AdjListWeighted[v2].push_back({u2,weight});
    }

    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<AdjListWeighted[i].size();j++){
            cout<<"("<<AdjListWeighted[i][j].first<<","<<AdjListWeighted[i][j].second<<")->";
        }
        cout<<endl;
    }

    // Directed Weighted Graph

    vector<pair<int,int>> AdjListDirWt[vertex];

    int u3, v3, wt;
    for(int i=0;i<edges;i++){
        cin>>u3>>v3>>wt;
        AdjListDirWt[u3].push_back({v3, wt});
    }
}