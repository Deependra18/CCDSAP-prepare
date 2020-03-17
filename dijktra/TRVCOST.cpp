/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<pl> adj[10001];
 vector<lld>dist(10001,inf);
 
void dijiktra(lld s,lld n)
{
  
   priority_queue<pl,vector<pl>,greater<pl>>pq;
   pq.push({0,s});
   dist[s]=0;
   while(!pq.empty())
   {
   lld u=pq.top().second;
   pq.pop();
   for(auto it:adj[u])
   {
   	  lld v=it.first;
   	  lld w=it.second;
   	  if(dist[v]>dist[u]+w)
   	  {
   	  	dist[v]=dist[u]+w;
   	  	pq.push({dist[v],v});
   	  }
   }
}
 
 
 
}
 
int main() 
{ 
	  fastio;
    lld n,m;
    cin>>n;
    lld u,v,w;
    for(lld i=0;i<n;i++)
    {
     cin>>u>>v>>w;
     adj[u].push_back({v,w});
     adj[v].push_back({u,w});
 
    }
    lld x,q;
    cin>>x;
    dijiktra(x,n);
    cin>>q;
    while(q--)
    {
      lld dp;
      cin>>dp;
      dp=dist[dp];
    if(dp==inf)
    	cout<<"NO PATH\n";
    else
    	cout<<dp<<"\n";
   }
 	return 0;
}