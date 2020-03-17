
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 10000000000000000
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
void dijktra(lld s,lld d,vector<lld>&dis,vector<pl> adj[])
{
	priority_queue<pl,vector<pl>,greater<pl>>pq;
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty())
	{
		lld u=pq.top().second;
		pq.pop();
		for(auto i:adj[u])
		{
			lld v=i.first;
			lld w=i.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
 
		}
	}
}
 
int main() 
{ 
	  fastio;
     lld t;
     cin>>t;
     while(t--)
     {
     	lld n,m,k,s,t;
     	cin>>n>>m>>k>>s>>t;
     	lld u,v,w;
     	vector<pl>adj[n+1];
     	vector<pl>adjr[n+1];
     	for(lld i=0;i<m;i++)
     	{
           cin>>u>>v>>w;
           adj[u].push_back({v,w});
           adjr[v].push_back({u,w});
     	}
     	vector<lld> diss(n+1,inf);
        dijktra(s,t,diss,adj);
     	vector<lld>dist(n+1,inf);
     	dijktra(t,s,dist,adjr);
 
     	lld mm=inf;
        for(lld i=0;i<k;i++)
        {
        	cin>>u>>v>>w;
           mm=min(mm,min(diss[u]+w+dist[v],diss[v]+w+dist[u]));
        }
        mm=min(mm,min(diss[t],dist[s]));
        if(mm==inf)
         mm=-1;
        cout<<mm<<"\n";
           dist.clear();
           diss.clear();
          for(lld i=0;i<=n;i++)
          	{adj[i].clear();
          	adjr[i].clear();}
 
     }
 	return 0;
}
 