#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
 
int topolol(vvi& G,vi& dg,vi& topo){
    priority_queue<int, vector<int>, greater<int> > vs;
    for(int i=0;i<dg.size();++i)
       { if(dg[i]==0) 
          vs.push(i);
       }
        
    int IX = 0;
    while(not vs.empty() ){
        int v = vs.top();
        vs.pop();
        topo[IX++] = v;
        for(int i=0;i<G[v].size();++i){
            int adj = G[v][i];
            --dg[adj];
            if(dg[adj]==0)
                vs.push(adj);
        }
    }
    return IX;
    
}
 
int main(){
    int n,m;
    cin >> n >> m;
        vvi G(n+1);
        vi in_dg(n+1,0);
        while(m--){
            int u,v;
            cin >> u >> v;
            //u,v;
            G[u].push_back(v);
            ++in_dg[v];
        }
        vi topo(n+1);
        if(topolol(G,in_dg,topo)!=n+1)
        {
            cout<<"Sandro fails.\n";
            return 0;
        }
        else
        {
        for(int i=1; i<topo.size(); ++i)
            cout << ' ' << topo[i];
        cout << endl;
        }
    
} 