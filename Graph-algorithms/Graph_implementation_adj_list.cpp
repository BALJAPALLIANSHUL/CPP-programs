/*     This is just one of the implementation of graphs with class     You can explor emore ways     */



#include<bits/stdc++.h>
using namespace std;
void print_array(vector<string>& arr)
{
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
class graph{
    unordered_map<int,list<int>> adj_list;
public:
    void add_edge(int u, int v, bool direction){
        //0 undirected 1 directed
        adj_list[u].push_back(v);
        if(!direction){
            adj_list[v].push_back(u);
        }
    }
    void print_adj_list(){
        for(const auto& i:adj_list){
            for(const auto& j:i.second){
                cout<<i.first<<"->"<<j<<" ";
            }
        }
    }
};
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif
    graph g;
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>u>>v;
        g.add_edge(u,v,0);
    }
    g.print_adj_list();
    return 0;
}

/*test case
        6
        0 1
        1 4
        1 3
        3 4
        2 3
        0 2
*\