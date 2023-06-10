/*     This is just one of the implementation of graphs with class     You can explor emore ways     */



#include<bits/stdc++.h>
using namespace std;
class Weighted_graph{
public:
        vector<vector<int>> adj_matrix;
        Weighted_graph(vector<vector<int>>& v){
            this->adj_matrix =v;
        }
    void add_edge(int u,int v,bool direction,int weight = 1){
        adj_matrix[u][v] = weight;
        if(!direction){
            adj_matrix[v][u] = weight;
        }
    }
    void print_matrix(){
        for(const auto& i:adj_matrix){
            for(const auto& j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

};
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif
        
    int n,u,v,e;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));
    Weighted_graph* g = new Weighted_graph(a);
    for(int i = 0;  i<n;  i++)
    {
        cin>>u>>v>>e;
        g->add_edge(u,v,0,e);
    }
    g->print_matrix();
    delete g;
    return 0;
}
 /*     SAMPLE TEST CASE
        
        6
        0 1 2
        1 4 3
        1 3 4
        3 4 6
        2 3 2
        0 2 1
 */