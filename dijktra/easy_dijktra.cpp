
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
#define pai pair<lld,lld>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lld dijiktra(vector<pair<lld,lld>>adj[],lld source,lld dest,lld n)
{
	
	priority_queue<pai, vector<pai>,greater<pai>> pq;
	vector<lld> dist(n+1,inf);
	pq.push({0ll,source});
	dist[source]=0;
	while(!pq.empty())
	{
		pair<lld,lld> p=pq.top();
		lld u=p.second;
		pq.pop();
		for(auto it:adj[u])
		{
             if(dist[it.first]>(dist[u]+it.second))
             {
             	dist[it.first]=dist[u]+it.second;
             	pq.push({dist[it.first],it.first});
             } 
		}

	}
	return dist[dest];
	
}

int main() 
{ 
	  fastio;
	 int t;
	 cin>>t;
	 while(t--)
	 {
	 	lld n,m;
	 	cin>>n>>m;
	 	vector<pair<lld,lld>>adj[n+1];
	 	lld u,v,w;
	 	 for(lld i=0;i<m;i++)
	 	 {
	 	 	cin>>u>>v>>w;
	 	 	adj[u].push_back({v,w});
	 	 }
	 	 lld A,B;
	 	 cin>>A>>B;
	 	 lld d=dijiktra(adj,A,B,n+1);
	 	    if(d==inf)
	 	 	cout<<"NO\n";
	 	 else
	 	 	cout<<d<<"\n";
	 	 
	 }

    



 	return 0;
}
