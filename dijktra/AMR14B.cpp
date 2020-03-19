
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
typedef tuple<lld,lld,lld> tl;
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool comp(tl &s1,tl &s2)
{
	return get<2>(s1)<get<2>(s2);
}

lld dijktra(lld s,lld n,vector<pl> adjr[])
{
	vector<lld> dist(n+1,inf);
	vector<lld>lastadded(n+1,inf);
	dist[s]=0;
	lastadded[s]=0;
	priority_queue<tl,vector<tl>,greater<tl>>pq;
	pq.push({0,0,s});
	while(!pq.empty())
	{
		tl a=pq.top();
		 lld u=get<2>(a);
		pq.pop();
		for(auto i:adjr[u])
		{
			lld v=i.first;
			lld w=i.second;
			if(dist[v]>dist[u]+w||(dist[v]==(dist[u]+w) && w<lastadded[v]))			{
				dist[v]=dist[u]+w;
				lastadded[v]=w;
				pq.push({dist[v],w,v});
				//vis[v]=1;
			}

		}
	}

	lld ans=0;
	 for(lld i=0;i<n;i++)
	 {
	 	if(lastadded[i]==inf)
	 		return -1;
	 	ans+=lastadded[i];
	 }
	 return ans;
}

lld find(lld u,lld p[])
{
	if(u==p[u])
		return u;
	else
	{
		return p[u]=find(p[u],p);
	}
}
void merge(lld u,lld v,lld size[],lld p[])
{
	if(size[u]<size[v])
		swap(u,v);
	p[v]=u;
	size[u]+=size[v];
	size[v]=0;
}

int main() 
{ 
	  fastio;
	 int  t;
	 cin>>t;
	 while(t--)
	 {
	 lld n,m;
	 cin>>n>>m;
	 vector<pl> adj[n+1];
	 lld u,v,w;
	 vector<tl>edges;
	 for(lld i=0;i<m;i++)
	 {
	 	cin>>u>>v>>w;
	 	adj[u].emplace_back(v,w);
	 	adj[v].emplace_back(u,w);
	 	edges.emplace_back(u,v,w);
	 }

	 lld ans1=dijktra(0,n,adj);
	 sort(edges.begin(),edges.end(),comp);
	 lld p[n],size[n];
	    for(lld i=0;i<n;i++)
	    	p[i]=i,size[i]=0;

       lld ans2=0;
	  for(auto i:edges)
	  {
	  	u=get<0>(i);
	  	v=get<1>(i);
	  	w=get<2>(i);
	  	lld p_u=find(u,p);
	  	lld p_v=find(v,p);
	  	if(p_u!=p_v)
	  	{
           ans2+=w;
           merge(p_u,p_v,size,p);   
	  	}

	  }
	  if(ans1==ans2)
	  	cout<<"YES\n";
	  else
	  	cout<<"NO\n";
	    for(lld i=0;i<n;i++)
	    	adj[i].clear();
	    edges.clear();

      }
 	return 0;
}
