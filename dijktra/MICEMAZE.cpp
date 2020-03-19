
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
lld dijktra(lld s,lld n,vector<pl> adjr[],lld t)
{
	vector<lld> dist(n+1,inf);
	dist[s]=0;
	priority_queue<pl,vector<pl>,greater<pl>>pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		lld u=pq.top().second;
		pq.pop();
		for(auto i:adjr[u])
		{
			lld v=i.first;
			lld w=i.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
 
		}
	}
	lld c=0;
	  for(lld i=1;i<=n;i++)
	  {
	  	if(dist[i]<=t)
	  		c++;
 
	  }
	  return c;
 
  
}
 
int main() 
{ 
	  fastio;
	 lld n;
	 cin>>n;
	 lld e;
	 cin>>e;
	 lld t;
	 cin>>t;
	 lld m;
	 cin>>m;
	 vector<pl> adjr[n+1];
	 lld u,v,w;
	 for(lld i=0;i<m;i++)
	 {
	 	cin>>u>>v>>w;
	 	adjr[v].push_back({u,w});
	 }
	 cout<<dijktra(e,n,adjr,t)<<"\n";
 
      
 	return 0;
}